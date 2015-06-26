<?php
/**
 * @file
 * Voices & Views carousel panels plugin.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Voices & views carousel'),
  'description' => t('Renders Voices & views carousel.'),
  'category' => t('C4M'),
);

/**
 * Render callback.
 */
function c4m_features_homepage_voices_views_carousel_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->module = 'c4m_restful_quick_post';
  $block->title = '';
  $block->content = c4m_features_homepage_voices_views_carousel();
  return $block;
}

/**
 * Edit form.
 */
function c4m_features_homepage_voices_views_carousel_content_type_edit_form($form, &$form_state) {
  return $form;
}
