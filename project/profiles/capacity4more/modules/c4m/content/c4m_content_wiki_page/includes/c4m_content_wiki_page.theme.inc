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
    return;
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
  $element['collapse_button'] = array(
    '#type' => 'button',
    '#value' => '<i class="fa fa-chevron-circle-left"></i> Hide sidebar',
    '#attributes' => array(
      'class' => array(
        'btn btn-default',
      ),
      'id' => 'collapse-sidebar',
    ),
  );

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
  $group = og_context();

  // See if user should access these links.
  if (!$group ||
      !og_user_access($group['group_type'], $group['gid'], 'create wiki_page content')) {
    return;
  }

  $book = $field['entity']->book;
  $current_page = $book['mlid'];
  $parent_page = $book['plid'];
  $depth = $book['depth'];

  $purl = url('', array('absolute' => TRUE));

  $options = array(
    'attributes' => array(
      'class' => 'add-more',
    ),
  );

  // Links to add new book pages.
  $links = array(
    l(t('Add page on same level'), $purl . '/node/add/wiki-page?parent=' . $parent_page, $options),
    $depth <= 5 ? l(t('Add child page'), $purl . '/node/add/wiki-page?parent=' . $current_page, $options) : '',
  );

  $markup = theme('item_list', array('items' => $links, 'attributes' => array('class' => 'add-links')));

  return $markup;
}
