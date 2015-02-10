<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('What is C4D video'),
  'description' => t('Renders the "What is C4D video" link and video overlay'),
  'category' => t('C4M'),
  'defaults' => array(
    'video' => FALSE,
  ),
);

/**
 * Render callback.
 */
function c4m_features_og_group_dashboard_what_c4d_video_content_type_render($subtype, $conf, $args, $context) {
  if(!isset($conf['video']) && !$conf['video']) {
    return FALSE;
  }

  $block = new stdClass();
  $block->module = 'c4m_restful_quick_post';
  $block->title = '';
  $block->content = c4m_features_og_group_dashboard_c4d_video($conf['video']);
  return $block;
}

/**
 * Edit form.
 */
function c4m_features_og_group_dashboard_what_c4d_video_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

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
function c4m_features_og_group_dashboard_what_c4d_video_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['video'] = $form_state['values']['video'];
}
