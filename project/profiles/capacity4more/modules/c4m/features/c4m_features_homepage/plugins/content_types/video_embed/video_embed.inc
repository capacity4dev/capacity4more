<?php
/**
 * @file
 * Plugin to embed videos in panels.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('YouTube video embed'),
  'description' => t('Renders a button that opens an embedded YouTube video overlay.'),
  'category' => t('C4M'),
  'defaults' => array(
    'title' => FALSE,
    'description' => FALSE,
    'video' => FALSE,
  ),
  'hook theme' => 'c4m_features_homepage_video_embed_content_type_theme',
);

/**
 * Render callback.
 */
function c4m_features_homepage_video_embed_content_type_render($subtype, $conf, $args, $context) {
  if (!$conf['video']) {
    return FALSE;
  }

  $user_groups = og_get_groups_by_user();

  if (!empty($user_groups['node'])) {
    return;
  }

  $video_title = $conf['title'];
  $video_description = $conf['description'];

  // Prepare the embed iframe, Take video ID from URL, or share URL.
  $video_id = str_replace('http://youtu.be/', '', $conf['video']);
  if (preg_match('/https:/i', $conf['video'])) {
    $video_id = str_replace('https://www.youtube.com/watch?v=', '', $conf['video']);
  }
  
  $video_embed = '<iframe id="c4mVideo" allowfullscreen="true" width="100%" height="477" src="https://www.youtube.com/embed/' . $video_id . '?rel=0&amp;showinfo=0&amp;autoplay=0&amp;enablejsapi=1" frameborder="0"></iframe>';

  $video_thumb = array(
    'path' => 'http://img.youtube.com/vi/' . $video_id . '/maxresdefault.jpg',
    'width' => '',
    'height' => '',
    'alt' => $video_title,
    'title' => '',
  );

  // This js will enable communication with YouTube's API.
  $path = drupal_get_path('module', 'c4m_features_homepage_intro');
  drupal_add_js($path . '/js/video_overlay.js');

  $variables = array(
    'video_thumbnail' => theme('image', $video_thumb),
    'video_title' => $video_title,
    'video_description' => $video_description,
    'video_embed' => $video_embed,
  );

  $block = new stdClass();
  $block->module = 'c4m_features_homepage';
  $block->title = '';
  $block->content = theme('video_embed', $variables);
  return $block;
}

/**
 * Edit form.
 */
function c4m_features_homepage_video_embed_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['title'] = array(
    '#title' => t('Video block title'),
    '#type' => 'textfield',
    '#default_value' => $conf['title'],
    '#required' => 1,
    '#description' => t('Title of the video.'),
  );

  $form['description'] = array(
    '#title' => t('Video block description'),
    '#type' => 'textfield',
    '#default_value' => $conf['description'],
    '#required' => 1,
    '#description' => t('Description of the video.'),
  );

  $form['video'] = array(
    '#title' => t('Video URL'),
    '#type' => 'textfield',
    '#default_value' => $conf['video'],
    '#required' => 1,
    '#description' => t('Provide the "Share" url of the video you want to embed.'),
  );
  return $form;
}

/**
 * Edit form submit callback.
 */
function c4m_features_homepage_video_embed_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['title'] = $form_state['values']['title'];
  $form_state['conf']['description'] = $form_state['values']['description'];
  $form_state['conf']['video'] = $form_state['values']['video'];
}

/**
 * Delegated hook_theme().
 */
function c4m_features_homepage_video_embed_content_type_theme(&$theme, $plugin) {
  $theme['video_embed'] = array(
    'variables' => array(
      'video_thumbnail' => NULL,
      'video_title' => NULL,
      'video_description' => NULL,
      'video_embed' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'video-embed',
  );
}
