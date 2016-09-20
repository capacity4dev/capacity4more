<?php

/**
 * @file
 * C4M Views module helper functions.
 */

/**
 * Returns the title of the current views page.
 *
 * This only works if the current page is a "views view page".
 *
 * @return string|bool
 *   Title of current views page.
 */
function _c4m_views_get_current_views_page_title() {
  // Get the current Views page view.
  if ($view = views_get_page_view()) {
    // Get the title of the view.
    if ($title = $view->get_title()) {
      // Return the title of the view.
      return $title;
    }
  }

  return FALSE;
}

/**
 * Function to return whether or not the block "Views Page Title" is rendered.
 *
 * @return bool
 *   Returns TRUE or FALSE depending on the fact if the block "Views Page Title"
 *   is rendered on the page or not.
 */
function _c4m_views_block_views_page_title_is_rendered() {
  // Set an empty page title, because Views will already have set it to be
  // the title of the view.
  $reaction = context_get_plugin('reaction', 'block');

  // Get a list of all the regions for this theme.
  foreach (system_region_list($GLOBALS['theme']) as $region_key => $region_name) {
    $blocks = $reaction->block_get_blocks_by_region($region_key);

    if (in_array('c4m_views_views_page_title', $blocks)) {
      return TRUE;
    }
  }

  return FALSE;
}
