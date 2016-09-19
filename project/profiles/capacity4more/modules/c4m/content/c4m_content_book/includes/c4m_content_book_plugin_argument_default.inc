<?php

/**
 * @file
 * Views argument plugin.
 */

// @codingStandardsIgnoreFile

/**
 * The help pages argument default handler.
 *
 * To allow rearranging the help pages, we want to filter the displayed content
 * by association to the `Help & Guidance` book. This function returns the
 * book's node ID.
 */
class c4m_content_book_plugin_argument_default extends views_plugin_argument_default {

  /**
   * Return the node ID of the help pages book.
   *
   * @return bool|int
   *   Return the node ID of the help pages book.
   */
  public function get_argument() {
    // Get the node ID of the Help & Guidance book.
    $help_book_title = variable_get('c4m_help_book_title', 'Help & Guidance');
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'book')
      ->propertyCondition('title', $help_book_title)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->propertyOrderBy('nid')
      ->range(0, 1)
      ->execute();

    // If the 'Help & Guidance' book ID could not be determined, add a human
    // friendly error message and return early -which will cause Drupal to
    // display 'The requested page could not be found'.
    if (!isset($result['node'])) {
      drupal_set_message(t('Unable to retrieve the help pages. Please !contact-page.', array(
        '!contact-page' => l(t('contact the site administrator'), 'contact', array('purl' => array('disabled' => TRUE))),
      )), 'error');

      return;
    }

    $entity = array_keys($result['node']);

    return array_shift($entity);
  }

}
