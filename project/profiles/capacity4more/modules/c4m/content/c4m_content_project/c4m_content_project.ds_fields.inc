<?php

/**
 * @file
 * c4m_content_project.ds_fields.inc
 */

/**
 * Callback for Twitter widget.
 */
function _c4m_content_project_field_twitter_ds_widget($field) {
  $entity = $field['entity'];
  $entity = entity_metadata_wrapper('paragraphs_item', $entity);

  $settings = array(
    "service" => "smk",
    "type" => "search",
    "display_user" => TRUE,
    "display_user_pic" => TRUE,
    "auto_expand_photo" => FALSE,
    "result_type" => "mixed",
    "rts_display_original" => TRUE,
    "tweet_about_btn" => FALSE,
    "tweet_more_btn" => TRUE,
  );

  if ($entity->c4m_twitter_username->value()) {
    $settings['incl_profiles'] = $entity->c4m_twitter_username->value();
  }
  if ($entity->c4m_twitter_hashtag->value()) {
    $settings['incl_hashtags'] = $entity->c4m_twitter_hashtag->value();
  }
  if ($entity->c4m_twitter_keywords->value()) {
    $settings['query'] = $entity->c4m_twitter_keywords->value();
  }

  $content = array(
    'wrapper' => array(
      '#type' => 'container',
      'content' => array(
        '#markup' => '<script type="application/json">' . json_encode($settings) . '</script>',
      ),
      '#attributes' => array(
        'class' => array('twitter_widget'),
      ),
      '#attached' => array(
        'js' => array(
          '//europa.eu/webtools/load.js' => array(
            'type' => 'external',
          ),
        ),
      ),
    ),
  );

  return drupal_render($content);
}

/**
 * Callback for the system block renderer field.
 *
 * @param string $field
 *   The field which to render.
 *
 * @return array
 *   Rendered output.
 */
function _c4m_content_project_system_block_renderer($field) {
  if ($paragraph_id = $field['entity']->item_id) {
    if ($paragraphs_item = paragraphs_item_load_multiple(
      array($paragraph_id)
    )
    ) {
      $paragraphs_item = reset($paragraphs_item);
      $block_info = explode(
        ':',
        $paragraphs_item->c4m_block[LANGUAGE_NONE][0]['moddelta']
      );

      // If the referenced block is NOT a View.
      if ($block_info[0] != 'views') {
        // Simply render the block.
        $rendered_block = c4m_helper_block_render(
          $block_info[0],
          $block_info[1]
        );
        return render($rendered_block);
      }

      // If a View, take into account the number of items parameter.
      $number_of_items = isset($paragraphs_item->c4m_number_of_items) ? $paragraphs_item->c4m_number_of_items : 5;

      // Get info for the View.
      $views_info = explode('-', $block_info[1]);
      $view = views_get_view($views_info[0]);

      // Set number of items.
      $number_of_items = $number_of_items[LANGUAGE_NONE][0]['value'];
      $view->set_items_per_page($number_of_items);

      // Set correct show more link.
      $view->set_display('block');
      if ($view->display_handler->use_more()) {
        $group = c4m_og_current_group();
        // We store the show more path in the link_url in Views and prepend purl.
        $show_more_path = $view->display_handler->get_option('link_url');
        $view->display_handler->set_option('link_url', $group->purl . '/' . $show_more_path);
      }

      // Render the View.
      $output = $view->preview($views_info[1], array());
      $view->destroy();

      return $output;
    }
  }

  return '';
}
