<?php

/**
 * @file
 * Admin forms.
 */

/**
 * Homepage intro video configuration form.
 *
 * @return array
 *   Form array.
 */
function c4m_features_homepage_intro_video_configure($form) {
  $form['video'] = array(
    '#type' => 'fieldset',
    '#title' => t('Video settings'),
  );

  $form['video']['c4m_features_homepage_intro_video_url'] = array(
    '#type' => 'textfield',
    '#title' => t('YouTube video URL'),
    '#default_value' => variable_get('c4m_features_homepage_intro_video_url', NULL),
    '#description' => t("URL of the YouTube video that should be played in the popup. Only video's hosted on YouTube are supported."),
  );

  $form['video']['c4m_features_homepage_intro_video_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title of the video'),
    '#default_value' => variable_get('c4m_features_homepage_intro_video_title', NULL),
    '#description' => t('Will be used also for the button label, defaults to "Watch what is capacity4dev" if left empty.'),
  );

  return system_settings_form($form);
}

/**
 * Form validation for homepage intro video configuration form.
 */
function c4m_features_homepage_intro_video_configure_validate($form, &$form_state) {
  $video_url = $form_state['values']['c4m_features_homepage_intro_video_url'];
  if (!empty($video_url)) {
    if (!c4m_features_homepage_intro_extract_youtube_video_id($video_url)) {
      form_set_error('c4m_features_homepage_intro_video_url', t('The YouTube video URL is not valid!'));
    }
  }
}
