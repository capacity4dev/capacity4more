<?php
/**
 * @file
 * Panels plugin to add a video in an overlay.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('YouTube video overlay'),
  'description' => t('Renders a button that opens an embedded YouTube video overlay.'),
  'category' => t('C4M'),
  'defaults' => array(
    'title' => FALSE,
    'video' => FALSE,
  ),
);

/**
 * Render callback.
 */
function c4m_features_homepage_intro_video_overlay_content_type_render($subtype, $conf, $args, $context) {
  if (!$conf['video']) {
    return FALSE;
  }

  $variables = array(
    'video_title' => $conf['title'],
    'video_url' => $conf['video'],
  );

  $block = new stdClass();
  $block->module = 'c4m_restful_quick_post';
  $block->title = '';
  $block->content = theme('c4m_features_homepage_intro_video', $variables);
  return $block;
}

/**
 * Edit form.
 */
function c4m_features_homepage_intro_video_overlay_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['title'] = array(
    '#title' => t('Video title'),
    '#type' => 'textfield',
    '#default_value' => $conf['title'],
    '#description' => t('Title of the video (If empty, it will default to "Watch what is capacity4dev").'),
  );

  $form['video'] = array(
    '#title' => t('Video URL'),
    '#type' => 'textfield',
    '#default_value' => $conf['video'],
    '#description' => t('Provide the "Share" url of the video you want to embed.'),
  );
  return $form;
}

/**
 * Edit form submit callback.
 */
function c4m_features_homepage_intro_video_overlay_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['title'] = $form_state['values']['title'];
  $form_state['conf']['video'] = $form_state['values']['video'];
}
