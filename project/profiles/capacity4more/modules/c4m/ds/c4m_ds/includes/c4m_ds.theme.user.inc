<?php
/**
 * @file
 * Custom Display Suite function fields.
 */

/**
 * DS function field.
 *
 * Render "Submitted by" User first and last name on timestamp.
 * (extends default ds field with first + last name).
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_article_notable_contribution(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $entity = $field['entity'];

  $view = views_embed_view('notable_contributions', 'block', $entity->uid);

  return $view;
}
