<?php
/**
 * @file
 * All preprocess functionality.
 */

/**
 * Implements theme_preprocess_message().
 *
 *  Activity stream messages preprocess.
 */
function kapablo_preprocess_message(&$variables) {
  if ($variables['view_mode'] != 'activity_group' && $variables['view_mode'] != 'activity_global') {
    return;
  }

  $message = $variables['message'];
  $variables['theme_hook_suggestions'][] = 'message__activity_stream';
  $variables['theme_hook_suggestions'][] = "message__{$message->type}__activity_stream";

  $variables['content'] = $message->getText();

  // Getting the name of the icon image file from the message type.
  $icon_type = explode('__', $message->type);

  $icon_entity_type = $icon_type[1];

  $icon_name = 'missing';

  if ($icon_entity_type == 'comment') {
    $icon_name = 'comment';
  }

  if ($icon_entity_type == 'node') {
    // Icon image file name is content type of the node.
    $icon_name = $icon_type[2];

    if ($icon_name == 'discussion') {
      $message_wrapper = entity_metadata_wrapper('message', $message);
      // Icon image file name is the discussion type of the discussion node.
      $icon_name = 'discussion-' . $message_wrapper->field_node->c4m_discussion_type->value(
        );
    }
  }

  $variables['icon'] = $icon_name;
}

/**
 * Implements theme_preprocess_block().
 */
function kapablo_preprocess_block(&$variables) {
  $block_id = $variables['block']->module . '-' . $variables['block']->delta;
  $classes = &$variables['classes_array'];

  // Add classes based on the block delta.
  switch ($block_id) {
    case 'c4m_user_profile-user_welcome':
    case 'c4m_user_profile-user_notifications':
      $classes[] = 'col-sm-12 col-md-6';
      break;
  }
}

/**
 * Implements theme_preprocess_page().
 *
 * @see page.tpl.php
 */
function kapablo_preprocess_page(&$variables) {
  // Add information about the number of sidebars.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class_kapablo'] = ' class="col-sm-4"';
  }
  elseif (!empty($variables['page']['sidebar_first']) || !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class_kapablo'] = ' class="col-sm-8"';
  }
  else {
    $variables['content_column_class_kapablo'] = ' class="col-sm-12"';
  }

  $variables['front_page'] = url('<front>', array('purl' => array('disabled' => TRUE)));

  // Add search form.
  $variables['search_form'] = drupal_get_form('c4m_search_form');

  // Take care of the breadcrumb for OG content.
  _set_og_breadcrumbs();

  // Off-canvas trigger labels.
  $offcanvas_trigger_label_left = t('More info');
  $offcanvas_trigger_label_right = t('More info');

  drupal_alter('c4m_offcanvas_trigger_label_left', $offcanvas_trigger_label_left);
  drupal_alter('c4m_offcanvas_trigger_label_right', $offcanvas_trigger_label_right);

  $variables['offcanvas_trigger_label_left'] = $offcanvas_trigger_label_left;
  $variables['offcanvas_trigger_label_right'] = $offcanvas_trigger_label_right;
}

/**
 * Helper function to set the breadcrumb for OG content.
 */
function _set_og_breadcrumbs() {
  // We use the raw path (purl pages do not have system paths).
  $path_elements = explode('/', request_path());

  // If the current path contains 2 or less parts and
  // the first part is a Persistent URL.
  if (count($path_elements) <= 2 && $purl = purl_load(array(
    'provider' => 'og_purl|node',
    'value' => $path_elements[0],
  ))) {
    $breadcrumb = array();

    // We need to load the group to get the
    // group title to use in the breadcrumb.
    $group = node_load($purl['id']);

    // Just have the group title displayed on group pages.
    if (count($path_elements) == 1) {
      $breadcrumb[] = $group->title;
    }
    // This deals with the direct menu items in the group menu.
    else {
      // We use the menu trail to get the titles for the breadcrumb.
      $trail = menu_get_active_trail();
      if (isset($trail[1]['menu_name']) && $trail[1]['menu_name'] == 'c4m-og-menu') {
        // Breadcrumb element linking to the group page.
        $breadcrumb[] = l($group->title, $path_elements[0]);
        $breadcrumb[] = $trail[1]['link_title'];
      }
    }

    drupal_set_breadcrumb($breadcrumb);
  }
}

/**
 * Implements template_preprocess_field().
 */
function kapablo_preprocess_field(&$variables, $hook) {
  $element = $variables['element'];

  switch ($element['#field_name']) {
    case 'c4m_ds_group_access_info':
      $group = $element['#object'];

      // Retrieve group access info.
      $group_access = c4m_og_get_access_type($group);

      if (!empty($group_access['type'])) {
        $variables['classes_array'][] = 'group-' .
          drupal_html_class($group_access['type']);
      }
      break;

    // Create an attribute to the link field.
    // This field will contain the initials of the title.
    // Using this initials in the css to create a ::before element
    // The ::before element is used to create
    // a circle with the user's initials in it.
    case 'c4m_link_multiple':
      foreach ($element['#items'] as $key => $item) {
        // Get initials of the user name.
        $title_array = preg_split("/\s+/", $item['title']);
        $initials = "";
        foreach ($title_array as $w) {
          $initials .= $w[0];
        }

        // Set initials in an attribute to the 'a' tag to use in css.
        $variables['items'][$key]['#element']['attributes']['data-initials'] = $initials;

        // Add html if there's no link.
        if (!$variables['items'][$key]['#element']['url']) {
          $title = $item['title'];
          $variables['items'][$key]['#element']['title'] = "<span data-initials='$initials'>$title</span>";
          $variables['items'][$key]['#element']['html'] = TRUE;
        }
      }
      break;

    // Group status field,
    // Do NOT display when the status is "Published".
    case 'c4m_og_status':
      if (reset($variables['items'])['#markup'] == 'Published') {
        unset($variables['items'][0]);
        // Remove the class.
        unset($variables['ds-config']['fis-cl']);
      }
      break;

    case 'c4m_ds_group_members_count':
      foreach ($element['#items'] as $key => $item) {
        $variables['items'][$key]['#markup'] = '<span class="group-statistic"><i class="fa fa-user"></i> ' . $variables['items'][$key]['#markup'] . '</span>';
      }
      break;

    case 'c4m_ds_group_posts_count':
      foreach ($element['#items'] as $key => $item) {
        $variables['items'][$key]['#markup'] = '<span class="group-statistic"><i class="fa fa-comments-o"></i> ' . $variables['items'][$key]['#markup'] . '</span>';
      }
      break;

    case 'c4m_discussion_type':
      switch ($element['#view_mode']) {
        case 'full':
          foreach ($element['#items'] as $key => $item) {
            $markup = c4m_content_discussion_simple_label(
              $variables['items'][$key]['#markup']
            );

            $variables['items'][$key]['#markup'] = '<i class="fa ' . $markup['class'] . '"></i> ' . $markup['label'];
          }
          break;
      }
      break;

    case 'og_vocabulary':
      foreach ($variables['items'] as $key => $item) {
        if (is_array($variables['items'][$key])) {
          foreach ($variables['items'][$key] as $subkey => $list) {
            $list['#title'] = str_replace(
              'Categories',
              'Group Categories',
              $list['#title']
            );

            $variables['items'][$key][$subkey] = $list;
          }
        }
      }
      break;

    case 'title':
      if ($element['#object']->type == 'photo') {
        $node = $element['#object'];
        $galleries = node_gallery_api_get_relationships(NULL, $node->nid);

        if (!empty($galleries)) {
          $gallery = array_pop($galleries);
          $album = node_load($gallery->ngid);
        }

        foreach ($element['#items'] as $key => $item) {
          $variables['items'][$key]['#markup'] = '<h1 class="text--inline">' . $album->title . '</h1><h2 class="text--inline">&nbsp;&gt; ' . $node->title . '</h2>';
        }
      }

      break;
  }
}

/**
 * Implements hook_preprocess_facetapi_link_inactive().
 */
function kapablo_preprocess_facetapi_link_inactive(&$variables) {
  $replace = _kapablo_help_facetapi_link_replace($variables['text']);
  if (empty($replace['class'])) {
    return;
  }

  foreach ($replace['class'] as $class) {
    $variables['options']['attributes']['class'][] = $class;
  }
}

/**
 * Implements hook_preprocess_facetapi_link_active().
 */
function kapablo_preprocess_facetapi_link_active(&$variables) {
  $replace = _kapablo_help_facetapi_link_replace($variables['text']);
  if (empty($replace['class'])) {
    return;
  }

  foreach ($replace['class'] as $class) {
    $variables['options']['attributes']['class'][] = $class;
  }
}

/**
 * Create replacement array for the faceted items label strings for discussions.
 *
 * @param string $text_orig
 *   The original text.
 *
 * @return array
 *   The replace info.
 */
function _kapablo_help_facetapi_link_replace($text_orig) {
  $replace = array();
  $text = $text_orig;
  $class = '';

  switch ($text_orig) {
    case t('Ask a Question'):
      $text = t('Question');
      $class = 'fl-question';
      break;

    case t('Share an Idea'):
      $text = t('Idea');
      $class = 'fl-idea';
      break;

    case t('Share Information'):
      $text = t('Information');
      $class = 'fl-info';
      break;

    case t('Start a Debate'):
      $text = t('Debate');
      $class = 'fl-debate';
      break;

    case t('Public'):
      $text = t('Public');
      $class = 'fl-public';
      break;

    case t('Private'):
      $text = t('Private');
      $class = 'fl-private';
      break;

    case t('Restricted'):
      $text = t('Restricted');
      $class = 'fl-restricted';
      break;
  }

  if ($text_orig !== $text) {
    $replace['text'] = $text;
  }
  if (!empty($class)) {
    $replace['class'] = array($class, 'fl-icon');
  }

  return $replace;
}

/**
 * Implements hook_preprocess_views_view().
 *
 * Set  parameters for the custom template of the
 * c4m_overview_inthe_picture_blocks view.
 *
 * @see views-view--c4m-overview-inthe-picture-blocks--block.tpl.php
 */
function kapablo_preprocess_views_view(&$vars) {
  switch ($vars['name']) {
    case 'c4m_overview_inthe_picture_blocks':
      $items = $vars['view']->result;
      $carousels = array();
      foreach ($items as $node) {
        $wrapper = entity_metadata_wrapper('node', $node->nid);
        $banner = $wrapper->c4m_media->value();
        $link = $wrapper->c4m_link->value();
        $body = $wrapper->c4m_body->value();
        $carousels[] = array(
          'id' => $wrapper->getIdentifier(),
          'title' => $wrapper->c4m_heading->value(),
          'text' => $body['value'],
          'image' => file_create_url($banner['uri']),
          'alias' => $link['url'],
        );
      }

      // Pass info via Drupal.settings.
      $settings['c4m'] = array(
        'carousels' => $carousels,
      );
      drupal_add_js($settings, 'setting');

      break;
  }
}

/**
 * Overrides template_preprocess_views_view_fields().
 */
function kapablo_preprocess_views_view_fields(&$vars) {
  $view = $vars['view'];

  switch ($view->name) {
    case 'c4m_er_groups':
      $node = node_load($vars['row']->nid);
      $access = c4m_og_get_access_type($node);

      $object = new stdClass();
      $object->content = '<span class="er--field-access privacy-level--' . $access['type'] . '">[' . $access['type'] . ']</span>';
      $object->wrapper_prefix = '';
      $object->wrapper_suffix = '';
      $object->label_html = '';

      $vars['fields']['access'] = $object;

      break;
  }
}

/**
 * Overrides theme_breadcrumb() and bootstrap_breadcrumb().
 *
 * Print breadcrumbs as an ordered list.
 * We need to set the icon class on every item except the first one.
 * That is why we cannot use theme_item_list.
 *
 * @see bootstrap_breadcrumb()
 * @see theme_breadcrumb()
 */
function kapablo_breadcrumb($variables) {
  $output = '';
  $breadcrumb = $variables['breadcrumb'];

  // Determine if we are to display the breadcrumb.
  $bootstrap_breadcrumb = theme_get_setting('bootstrap_breadcrumb');
  if (($bootstrap_breadcrumb == 1 || ($bootstrap_breadcrumb == 2 && arg(
          0
        ) == 'admin')) && !empty($breadcrumb)
  ) {

    $output = "<ol" . drupal_attributes(
        array('class' => array('breadcrumb'))
      ) . '>';

    array_unshift(
      $breadcrumb,
      l(t('EUROPA'), 'http://ec.europa.eu'),
      l(t('capacity4dev'), '<front>', array('purl' => array('disabled' => TRUE)))
    );

    $num_items = count($breadcrumb);

    foreach ($breadcrumb as $i => $item) {
      $attributes = array();
      $i++;
      $data = '';

      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }

      if ($i == 1) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_items) {
        $attributes['class'][] = 'last';
      }
      else {
        $data .= '<i class="fa fa-chevron-right"></i>';
      }

      $output .= '<li' . drupal_attributes(
          $attributes
        ) . '>' . $data . "</li>\n";
    }

    $output .= '</ol>';
  }
  return $output;
}

/**
 * Implements theme_item_list().
 *
 * Get back first and last classes (Bootstrap theme removes them).
 */
function kapablo_item_list($variables) {
  $items = $variables['items'];
  $title = $variables['title'];
  $type = $variables['type'];
  $attributes = $variables['attributes'];

  // Only output the list container and title, if there are any list items.
  // Check to see whether the block title exists before adding a header.
  // Empty headers are not semantic and present accessibility challenges.
  $output = isset($variables['hide_wrapper']) ? '' : '<div class="item-list">';
  if (isset($title) && $title !== '') {
    $output .= '<h3>' . $title . '</h3>';
  }

  if (!empty($items)) {
    $output .= "<$type" . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    $i = 0;
    foreach ($items as $item) {
      $attributes = array();
      $children = array();
      $data = '';
      $i++;
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        // Render nested list.
        $data .= theme_item_list(
          array(
            'items' => $children,
            'title' => NULL,
            'type' => $type,
            'attributes' => $attributes,
          )
        );
      }
      if ($i == 1) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_items) {
        $attributes['class'][] = 'last';
      }
      $output .= '<li' . drupal_attributes(
          $attributes
        ) . '>' . $data . "</li>\n";
    }
    $output .= "</$type>";
  }
  $output .= isset($variables['hide_wrapper']) ? '' : '</div>';
  return $output;
}

/**
 * Overrides theme_menu_tree().
 */
function kapablo_menu_tree__small(&$variables) {
  return '<ul class="text-small">' . $variables['tree'] . '</ul>';
}

/**
 * Pre-processes variables for the "image" theme hook.
 *
 * See theme function for list of available variables.
 *
 * @see theme_image()
 *
 * @ingroup theme_preprocess
 */
function kapablo_preprocess_image(&$variables) {
  // Remove .img-responsive class for icon_small styled images.
  if (!empty($variables['style_name']) && $variables['style_name'] == 'icon_small') {
    if (($key = array_search('img-responsive', $variables['attributes']['class'])) !== FALSE) {
      unset($variables['attributes']['class'][$key]);
    }
  }
}

/**
 * Overrides template_process_html().
 */
function kapablo_preprocess_html(&$variables) {
  // Render off_canvas into top level variables.
  $variables['off_canvas'] = drupal_render($variables['page']['off_canvas']);
}
