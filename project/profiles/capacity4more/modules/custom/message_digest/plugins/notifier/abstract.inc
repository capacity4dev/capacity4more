<?php

/**
 * Message Digest notifier.
 */
class MessageDigest extends MessageNotifierBase {

  /**
   * Create a message that needs to be sent out later.
   *
   * Do not actually deliver this message because it will be delivered
   * via cron in a digest, but return TRUE to prevent a logged error.
   * Instead, we "deliver" it to the message_digest DB table so that it
   * can be retrieved at a later time.
   *
   * @param array $output
   *   Array with strings that need to be glued together.
   *
   * @return bool|void
   *   TRUE is all goes well.
   */
  public function deliver(array $output = []) {
    $message = $this->message;
    $plugin = $this->plugin;

    $message_callbacks = c4m_message_digest_get_grouping_info();

    $message_digest = [
      'receiver' => $message->uid,
      'gid' => !empty($message_callbacks[$message->type]) ? $message->{$message_callbacks[$message->type]['title_callback_argument_field']}[LANGUAGE_NONE][0]['target_id'] : 0,
      'notifier' => $plugin['name'],
      'sent' => FALSE,
      'timestamp' => $message->timestamp,
    ];
    // This will only have a value if the message is not a message_subscribe
    // message.
    $mid = isset($message->mid) ? $message->mid : NULL;

    // Our $message is a cloned copy of the original $message with the mid field
    // removed to prevent overwriting (this happens in message_subscribe) so we
    // need to fetch the mid manually.
    if (empty($mid)) {
      $mid = db_select('message', 'm')
        ->fields('m', ['mid'])
        ->condition('timestamp', $message->timestamp)
        ->condition('type', $message->type)
        ->execute()
        ->fetchField();
    }

    if (!empty($mid)) {
      $message_digest['mid'] = $mid;
    }

    drupal_write_record('message_digest', $message_digest);

    return TRUE;
  }

  /**
   * This will be overridden in subclasses with custom intervals.
   */
  public function getInterval() {
    return '1 day';
  }

  /**
   * Retrieve all the messages for an interval that haven't been sent.
   *
   * Aggregate all of the messages for this interval and notifier that haven't
   * already been sent, and group them by user and then by group.
   */
  public function aggregate() {
    $interval = $this->getInterval();
    $start = strtotime('-' . $interval);
    $message_groups = [];

    $query = db_select('message_digest', 'md');
    $query->fields('md');
    $query->condition('timestamp', $start, '>');
    $query->condition('sent', FALSE);
    $query->condition('notifier', $this->plugin['name']);
    $result = $query->execute();

    foreach ($result as $row) {
      $account = user_load($row->receiver);
      $context = [
        'account' => $account,
        'data' => $row,
        'plugin' => $this->plugin,
      ];

      drupal_alter('message_digest_aggregate', $context);

      $message = message_load($context['data']->mid);

      if (!empty($context['data']->mid)) {
        $message_groups[$context['data']->receiver][$message->type][$row->gid][] = $context['data']->mid;
      }
    }
    return $message_groups;
  }

  /**
   * Create a formatted digest.
   *
   * Given an array of mids, build the full message content for them
   * and combine them into one blob of email content.
   */
  public function format($digest, $view_modes, $uid) {
    $output_array = [];
    $footer_text = '';
    $header_text = '';

    $message_callbacks = c4m_message_digest_get_grouping_info();

    foreach ($digest as $message_type => $group) {
      foreach ($group as $eid => $messages) {
        if (!empty($messages)) {
          // Call this with the gid argument.
          if (function_exists($message_callbacks[$message_type]['title_callback'])) {
            $output_array[] = call_user_func($message_callbacks[$message_type]['title_callback'], $eid);
            $output_array[] = '';
          }
        }

        foreach ($messages as $mid) {
          $message = message_load($mid);
          $message->uid = $uid;
          if (empty($message) || !is_object($message)) {
            continue;
          }
          $rows = [];
          foreach ($view_modes as $view_mode_name => $view_mode) {
            $content = $message->buildContent($view_mode_name);
            $rows[$view_mode_name] = render($content);
          }

          $output_array[] = theme('message_digest_row', [
            'rows' => $rows,
            'plugin' => $this->plugin,
            'message' => $message,
          ]);

          // Get header text.
          $langcode = NULL;
          $options = [
            'field name' => 'message_header',
          ];

          // Overwrite $header_text. We'll just keep the last one.
          $header_text = $message->getText($langcode, $options);

          // Get footer text.
          $langcode = NULL;
          $options = [
            'field name' => 'message_footer',
          ];
          // Overwrite $footer_text. We'll just keep the last one.
          $footer_text = $message->getText($langcode, $options);
        }

        $output_array[] = '';
        $output_array[] = '<hr/>';
      }
    }

    if (!empty($header_text)) {
      array_unshift($output_array, $header_text);
    }

    if (!empty($footer_text)) {
      $output_array[] = $footer_text;
    }

    return theme('message_digest', [
      'messages' => $output_array,
      'plugin' => $this->plugin,
    ]);
  }

  /**
   * Send the actual digest email.
   */
  public function deliverDigest($uid, $formatted_message) {
    $account = user_load($uid);
    $lang = !empty($account->language) && $account->language != LANGUAGE_NONE ? $languages[$account->language] : language_default();
    $params = [
      'body' => $formatted_message,
    ];
    drupal_mail('message_digest', 'digest', $account->mail, $lang, $params);
  }

  /**
   * Mark the sent digest messages as sent in the message_digest DB table.
   */
  public function markSent($uid, $plugin_name) {
    $num_rows = db_update('message_digest')
      ->fields(['sent' => TRUE])
      ->condition('receiver', $uid)
      ->condition('notifier', $plugin_name)
      ->execute();
  }

}
