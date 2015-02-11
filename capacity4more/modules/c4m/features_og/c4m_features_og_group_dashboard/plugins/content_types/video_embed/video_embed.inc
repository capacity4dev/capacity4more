<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('YouTube video embed'),
  'description' => t('Renders a button that opens an embedded YouTube video overlay.'),
  'category' => t('C4M'),
  'defaults' => array(
    'title' => FALSE,
    'video' => FALSE,
  ),
  'hook theme' => 'c4m_features_og_group_dashboard_video_embed_content_type_theme',
);

/**
 * Render callback.
 */
function c4m_features_og_group_dashboard_video_embed_content_type_render($subtype, $conf, $args, $context) {
  if (!$conf['video']) {
    return FALSE;
  }

  $button_title = $conf['title'] ? $conf['video'] : t('Watch what is capacity4dev');

  // Prepare the embed iframe, Take video ID from URL, or share URL.
  $video_id = str_replace('http://youtu.be/', '', $conf['video']);
  if (preg_match('/https:/i', $conf['video'])) {
    $video_id = str_replace('https://www.youtube.com/watch?v=', '', $conf['video']);
  }
  $video_embed = '<iframe width="100%" height="477" src="https://www.youtube.com/embed/' . $video_id . '?rel=0&amp;controls=0&amp;showinfo=0&amp;autoplay=0" frameborder="0" allowfullscreen></iframe>';

  $variables = array(
    'video_title' => $button_title,
    'video_embed' => $video_embed,
  );

  $block = new stdClass();
  $block->module = 'c4m_restful_quick_post';
  $block->title = '';
  $block->content = theme('video_embed' , $variables);
  return $block;
}

/**
 * Edit form.
 */
function c4m_features_og_group_dashboard_video_embed_content_type_edit_form($form, &$form_state) {
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
function c4m_features_og_group_dashboard_video_embed_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['title'] = $form_state['values']['title'];
  $form_state['conf']['video'] = $form_state['values']['video'];
}

/**
 * Delegated hook_theme().
 */
function c4m_features_og_group_dashboard_video_embed_content_type_theme(&$theme, $plugin) {
  $theme['video_embed'] = array(
    'variables' => array(
      'video_title' => NULL,
      'video_embed' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'video-embed',
  );
}
