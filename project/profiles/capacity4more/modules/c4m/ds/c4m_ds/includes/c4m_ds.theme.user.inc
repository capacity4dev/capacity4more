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

  return theme(
    'c4m_ds_embed_view',
    array(
      'view' => 'notable_contributions',
      'display' => 'block',
      'header' => 'h3',
      'args' => array($entity->uid),
    )
  );
}

/**
 * Get all user stats in one field.
 *
 * @param array $field
 *   The field info.
 *
 * @return string
 *   The rendered field.
 */
function theme_c4m_ds_user_footer_stats(array $field) {
  $entity = $field['entity'];

  $recommends = c4m_helper_entity_entity_get_properties(
    $entity,
    array(),
    '',
    'node',
    array('flag_name' => 'c4m_og_content_recommend')
  );

  $items['posts'] = theme(
    'c4m_ds_user_posts_count',
    array('count' => theme_c4m_user_activity_posts($field))
  );

  $items['comments'] = theme(
    'c4m_ds_entity_comments_count',
    array('count' => theme_c4m_user_activity_comments($field))
  );

  return implode($items);
}
