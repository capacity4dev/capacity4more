<?php
/**
 * @file
 * Wiki helpers & plugins.
 */

/**
 * Menu callback for path wiki.
 *
 * Renders the Wiki menu.
 *
 * @return mixed
 *   The rendered wiki menu.
 */
function c4m_features_og_wiki_wiki() {
  // If we are not in group context, deny access.
  if (!$group = c4m_og_current_group()) {
    drupal_access_denied();
  }
  elseif (!$group->book['has_children']) {
    // If the group has no first wiki page (meaning a level 1 page.
    return theme('c4m_features_og_wiki_wiki', array('content' => NULL));
  }
  else {
    $book  = book_get_flat_menu($group->book);
    // Remove level 0 link.
    array_shift($book);
    $menu_link = array_shift($book);
    if (empty($menu_link['link_path'])) {
      return theme('c4m_content_wiki_page_wiki', array('content' => NULL));
    }
    drupal_goto($menu_link['link_path']);
  }
}
