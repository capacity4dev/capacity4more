<?php

/**
 * @file
 * c4m_content_project.ds_fields.inc
 */

/**
 * Callback for Twitter widget.
 */
function _c4m_ds_field_twitter_widget($field) {
  $entity = $field['entity'];
  $entity = entity_metadata_wrapper('paragraphs_item', $entity);

  $settings = array(
    "service" => "smk",
    "type" => "search",
    "display_user" => TRUE,
    "display_user_pic" => TRUE,
    "auto_expand_photo" => FALSE,
    "from" => "EU_Commission",
    "result_type" => "mixed",
    "rts_display_original" => TRUE,
    "tweet_about_btn" => TRUE,
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
