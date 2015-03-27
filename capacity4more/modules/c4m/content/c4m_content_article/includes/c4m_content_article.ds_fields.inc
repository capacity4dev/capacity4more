<?php
/**
 * @file
 *
 * Custom Display Suite function fields.
 */

/**
 * DS function field.
 *
 * Render an <em> tag with the content disclaimer.
 *
 * @param $field
 *
 * @return string
 */
function c4m_content_article_disclaimer($field) {
  $disclaimer = variable_get('c4m_ds_content_disclaimer', 'DISCLAIMER: This information is provided in the interests of knowledge sharing and capacity development and should not be interpreted as the official view of the European Commission, or any other organisation.');

  $tag['element'] = array(
    '#tag'   => 'em',
    '#value' => $disclaimer,
  );

  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render a list of internal and external contributors.
 *
 * @param $field
 *
 * @return string
 */
function c4m_content_article_contributors($field) {
  if (empty($field['entity'])) {
    return;
  }
return;
  $entity = $field['entity'];
  $entity_wrapper = entity_metadata_wrapper('node', $entity);

  $internal = array();
  foreach ($entity_wrapper->c4m_related_user->value() as $contributor) {
    $user = entity_load('user', $contributor->uid);
    $internal[] = entity_view('user', $user, 'c4m_user_teaser_list');
  }
dsm($internal);
  $external = array();
  foreach ($entity_wrapper->c4m_link_multiple->value() as $contributor) {
  }

//  $ok = theme_item_list(array('title' => t('Contributors'), 'items' => $internal));
  $tag['element'] = array(
    '#tag'   => 'em',
    '#value' => $ok,
  );

  return theme_html_tag($tag);
}
