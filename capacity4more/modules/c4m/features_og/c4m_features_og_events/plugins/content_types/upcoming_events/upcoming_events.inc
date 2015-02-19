<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Upcoming events'),
  'description' => t('Renders Upcoming events form.'),
  'category' => t('C4M'),
);

/**
 * Render callback.
 */
function c4m_features_og_events_upcoming_events_content_type_render($subtype, $conf, $args, $context) {
  global $user;

  $block = new stdClass();
  $block->module = 'c4m_restful_quick_post';
  $block->title = 'Upcoming events';

  if ($user->uid) {
    $block->content = c4m_features_og_events_upcoming_events_loggedin();
  }
  else {
    $block->content = c4m_features_og_events_upcoming_events_anonymous();
  }

  return $block;
}

/**
 * Edit form.
 */
function c4m_features_og_events_upcoming_events_content_type_edit_form($form, &$form_state) {
  return $form;
}
