<?php

/**
 * @file
 * Upcoming events panels plugin.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Upcoming events'),
  'description' => t('Renders Upcoming events form.'),
  'category' => t('C4M'),
  'hook theme' => 'c4m_features_og_events_upcoming_events_content_type_theme',
);

/**
 * Render callback.
 */
function c4m_features_og_events_upcoming_events_content_type_render($subtype, $conf, $args, $context) {
  global $user;

  $block = new stdClass();
  $block->module = 'c4m_restful_quick_post';
  $block->title = '';

  if ($user->uid) {
    list($events, $display_see_more) = c4m_features_og_events_upcoming_events_loggedin();
  }
  else {
    list($events, $display_see_more) = c4m_features_og_events_upcoming_events_anonymous();
  }

  if ($events) {
    $block->content = theme('c4m_features_og_events_upcoming_events', array(
      'events' => $events,
      'display_see_more' => $display_see_more,
    ));
  }

  return $block;
}

/**
 * Edit form.
 */
function c4m_features_og_events_upcoming_events_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Delegated hook_theme().
 */
function c4m_features_og_events_upcoming_events_content_type_theme(&$theme, $plugin) {
  $theme['c4m_features_og_events_upcoming_events'] = array(
    'variables' => array(
      'events' => NULL,
      'display_see_more' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'upcoming_events',
  );
}
