<?php
/**
 * @file
 * Panels plugin to add the pane for the Activity Stream.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Activity stream'),
  'description' => t('Renders AngularJs based activity stream.'),
  'category' => t('C4M'),
  'hook theme' => 'c4m_message_activity_stream_content_type_theme',
);

/**
 * Render callback.
 */
function c4m_message_activity_stream_content_type_render($subtype, $conf, $args, $context) {

  $block = new stdClass();
  $block->module = 'c4m_message';
  $block->title = '';
  $block->content = theme('c4m_message_activity_stream');
  return $block;
}

/**
 * Edit form.
 */
function c4m_message_activity_stream_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Delegated hook_theme().
 */
function c4m_message_activity_stream_content_type_theme(&$theme, $plugin) {
  $theme['c4m_message_activity_stream'] = array(
    'variables' => array(),
    'path' => $plugin['path'],
    'template' => 'activity-stream',
  );
}
