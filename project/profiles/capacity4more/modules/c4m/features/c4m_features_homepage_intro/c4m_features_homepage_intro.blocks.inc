<?php
/**
 * @file
 * All blocks for the intro_video module.
 */

/**
 * Configure the video block.
 *
 * @return array
 *   Form array.
 */
function _c4m_features_homepage_intro_video_configure() {
  $form['video'] = array(
    '#type' => 'fieldset',
    '#title' => t('Video settings'),
  );
  $form['video']['c4m_features_homepage_intro_video_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL of the video that should be played in the popup.'),
    '#default_value' => variable_get('c4m_features_homepage_intro_video_url', NULL),
    '#description' => t("Only video's hosted on YouTube are supported."),
  );
  $form['video']['c4m_features_homepage_intro_video_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title of the video, will be used also for the button label.'),
    '#default_value' => variable_get('c4m_features_homepage_intro_video_title', NULL),
    '#description' => t('If empty, it will default to "Watch what is capacity4dev".'),
  );

  return $form;
}

/**
 * Save the video block configuration.
 *
 * @param array $edit
 *   The data as received from the block config form.
 */
function _c4m_features_homepage_intro_video_save(array $edit) {
  variable_set(
    'c4m_features_homepage_intro_video_url',
    $edit['c4m_features_homepage_intro_video_url']
  );
}

/**
 * Block to render the video button.
 *
 * @return mixed
 *   The block array.
 */
function _c4m_features_homepage_intro_video_view() {
  // No block if no video URL is set.
  $url = variable_get('c4m_features_homepage_intro_video_url', NULL);
  if (empty($url)) {
    return;
  }

  $content = theme('c4m_features_homepage_intro_video', array(
    'video_title' => variable_get('c4m_features_homepage_intro_video_title', NULL),
    'video_url' => variable_get('c4m_features_homepage_intro_video_url', NULL),
  ));

  // Return the block.
  $block = array(
    'subject' => NULL,
    'content' => $content,
  );

  return $block;
}

/**
 * Block to render the banner.
 *
 * @return mixed
 *   The block array.
 */
function _c4m_features_homepage_intro_banner_view() {
  $content = theme('c4m_features_homepage_intro_banner', array());

  // Return the block.
  $block = array(
    'subject' => NULL,
    'content' => $content,
  );

  return $block;
}
