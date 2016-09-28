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
 * by association to the `Help & Guidance` book. This function returns the main
 * book's ID.
 */
class c4m_content_book_plugin_argument_default extends views_plugin_argument_default {

  /**
   * Return the node ID of the main help pages book.
   *
   * @return bool|int
   *   Return the node ID of the main help pages book.
   */
  public function get_argument() {
    if (!$node = c4m_content_book_get_main_help_and_guidance()) {
      $link = l(t('Please setup one'), 'admin/config/c4m/help_and_guidance', array('purl' => array('disabled' => TRUE)));
      drupal_set_message(t('Unable to retrieve the main help and guidance book. !link.', array('!link' => $link,)), 'error');

      return '';
    }

    return $node->nid;
  }
}
