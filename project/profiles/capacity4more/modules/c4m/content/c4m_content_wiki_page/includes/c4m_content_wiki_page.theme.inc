<?php

/**
 * @file
 * Custom Display Suite function fields.
 */

/**
 * DS function field.
 *
 * Render WIKI Page navigation.
 *
 * @param array $field
 *   Field info.
 *
 * @return string
 *   The rendered version of the field.
 */
function theme_c4m_content_wiki_page_navigation(array $field) {
  if (empty($field['entity']->book['menu_name'])) {
    return NULL;
  }

  $book = $field['entity']->book;

  // We have to replicate some code because we cannot just
  // call theme('book_navigation', array('book_link' => ...)) because
  // we want to remove level 0 from the tree.
  $tree = menu_build_tree($book['menu_name']);

  if (empty($tree)) {
    return NULL;
  }

  // Remove level 0 first.
  $tree = $tree[key($tree)]['below'];
  $tree = menu_tree_output($tree);

  // Fix the theme hook suggestions.
  // Do this so we end up in OUR theme overrides.
  $file = DRUPAL_ROOT . '/' . drupal_get_path('theme', 'bootstrap') .
    '/templates/book/book-navigation.vars.php';
  if (file_exists($file)) {
    require_once $file;
    _bootstrap_book_fix_theme_hooks($book['nid'], $tree);
  }

  // Return the rendered output.
  $markup = drupal_render($tree);
  // We need to clear the menu build tree cache for this menu or the building
  // of book navigation will fail as it will have nids for node objects.
  drupal_static_reset('_menu_build_tree');

  return $markup;
}

/**
 * DS function field.
 *
 * Render WIKI Page sidebar collapse button.
 *
 * @param array $field
 *   Field info.
 *
 * @return string
 *   The rendered version of the field.
 */
function theme_c4m_content_wiki_page_collapse(array $field) {
  $element['collapse_button'] = [
    '#type' => 'button',
    '#value' => 'Hide sidebar',
    '#icon' => '<i class="fa fa-chevron-circle-left"></i>',
    '#attributes' => [
      'id' => 'collapse-sidebar',
    ],
  ];

  // Return the rendered output.
  $markup = drupal_render($element);

  return $markup;
}

/**
 * DS function field.
 *
 * Render WIKI Page Add pages links.
 *
 * @param array $field
 *   Field info.
 *
 * @return mixed
 *   The rendered version of the field if the access check is TRUE.
 */
function theme_c4m_content_wiki_page_add_links(array $field) {
  // Not under group context, or user not allowed to create wiki pages.
  if (!og_context() || !node_access('create', 'wiki_page')) {
    return;
  }

  $book = $field['entity']->book;
  $current_page = $book['mlid'];
  $parent_page = $book['plid'];
  $depth = $book['depth'];

  $options = array(
    'attributes' => array(
      'class' => 'add-more',
    ),
    'html' => TRUE,
  );

  // Links to add new book pages.
  $links = array(
    l(
      '<i class="fa fa-plus-square-o"></i> ' . t('Add page on same level'),
      'node/add/wiki-page',
      array_merge($options, array('query' => array('parent' => $parent_page)))
    ),
    $depth <= 5 ? l(
      '<i class="fa fa-plus-square-o"></i> ' . t('Add child page'),
      'node/add/wiki-page',
      array_merge($options, array('query' => array('parent' => $current_page)))
    ) : '',
  );

  $markup = theme(
    'item_list',
    array('items' => $links, 'attributes' => array('class' => 'add-links'))
  );

  return $markup;
}
