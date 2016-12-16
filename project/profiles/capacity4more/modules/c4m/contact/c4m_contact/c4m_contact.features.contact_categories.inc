<?php
/**
 * @file
 * c4m_contact2.features.contact_categories.inc
 */

/**
 * Implements hook_contact_categories_defaults().
 */
function c4m_contact_contact_categories_defaults() {
  return array(
    'Issues with the content of the site' => array(
      'category' => 'Issues with the content of the site',
      'recipients' => 'info@example.com',
      'reply' => '',
      'weight' => 0,
      'selected' => 0,
    ),
    'Suggestions' => array(
      'category' => 'Suggestions',
      'recipients' => 'info@example.com',
      'reply' => '',
      'weight' => 0,
      'selected' => 1,
    ),
    'Technical issue with the site' => array(
      'category' => 'Technical issue with the site',
      'recipients' => 'info@example.com',
      'reply' => '',
      'weight' => 0,
      'selected' => 0,
    ),
  );
}
