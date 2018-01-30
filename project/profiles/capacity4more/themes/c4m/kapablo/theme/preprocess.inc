<?php

/**
 * @file
 * All preprocess functionality.
 */

/**
 * Implements theme_preprocess_message().
 *
 * Activity stream messages preprocess.
 */
function kapablo_preprocess_message(&$variables) {
  if ($variables['view_mode'] != 'activity_group' && $variables['view_mode'] != 'activity_global') {
    return;
  }

  $message = $variables['message'];

  $variables['theme_hook_suggestions'][] = 'message__activity_stream';
  $variables['theme_hook_suggestions'][] = "message__{$message->type}__activity_stream";

  $variables['content'] = $message->getText();

  // Compute the destination. Either request_path() if the message is not
  // loaded through REST services or the group front page or the site front
  // page.
  $destination = request_path();
  if ($destination === 'api/activity_stream') {
    $query_params = drupal_get_query_parameters();
    if (!empty($query_params['group'])) {
      $destination = url('node/' . $query_params['group']);
    }
    else {
      $destination = url('<front>');
    }
  }

  if (c4m_message_delete_message_access($message)) {
    $link_options = [
      'attributes' => ['class' => ['action-delete']],
      'html' => TRUE,
      'query' => ['destination' => $destination],
    ];
    $title = t('Delete activity');
    $variables['content'] .= l('<i class="fa fa-window-close" title="' . $title . '"></i>', 'activity/' . $message->mid . '/delete', $link_options);
  }

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
      $icon_name = 'discussion-' . $message_wrapper->field_node->c4m_discussion_type->value();
    }
  }

  $variables['icon'] = $icon_name;
}

/**
 * Implements theme_preprocess_block().
 */
function kapablo_preprocess_block(&$variables) {
  if (isset($variables['elements']['#block']->bid) && $variables['elements']['#block']->bid == 'og_menu-og_single_menu_block') {
    // This block is the OG Menu. Add the tpl to the suggested filename list:
    $variables['theme_hook_suggestions'][] = 'block__menu__c4m_og_menu';
  }

  $block_id = $variables['block']->module . '-' . $variables['block']->delta;
  $classes = &$variables['classes_array'];

  // Add classes based on the block delta.
  switch ($block_id) {
    case 'c4m_user_profile-user_welcome':
    case 'c4m_user_profile-user_notifications':
      $classes[] = 'col-sm-12 col-md-6';
      break;

    case 'menu-c4m-og-menu':
      // Add search form.
      // Find current group ID.
      $gid = c4m_og_current_group_id();

      // Assemble search URL using current group.
      $redirect_url = url(
        'searchgroup',
        array(
          'absolute' => TRUE,
          'purl' => array(
            'provider' => 'og_purl|node',
            'id' => $gid,
          ),
        )
      );

      $form = drupal_get_form(
        'c4m_search_redirect_form',
        $redirect_url,
        NULL,
        t(
          'Search in @group_type...',
          array('@group_type' => c4m_og_get_group_type(array('gid' => $gid)))
        )
      );

      $variables['search_form'] = $form;

      break;

    // Sidebar block handling: adding classes, theme suggestion hook.
    case 'views-c4m_learning_content-block':
    case 'views-c4m_learning_content-block_1':
      $variables['classes_array'][] = 'sidebarblock';
      $variables['title_attributes_array']['class'][] = 'sidebarblock__title';
      array_unshift($variables['theme_hook_suggestions'], 'block__sidebarblock');

      break;
  }
}

/**
 * Implements theme_preprocess_views_view().
 */
function kapablo_preprocess_views_view(&$vars) {
  if (!empty($vars['more'])) {
    $vars['classes_array'][] = 'pane--more';
  }
}

/**
 * Implements theme_preprocess_page().
 *
 * @see page.tpl.php
 * @see page--og--project.tpl.php
 */
function kapablo_preprocess_page(&$variables) {

  drupal_add_js(
    '//ec.europa.eu/wel/cookie-consent/consent.js',
    [
      'type' => 'external',
      'scope' => 'header',
      'group' => JS_THEME,
      'weight' => 1000,
    ]
  );
  // Determine if the current context is a project.
  $context = og_context();
  if ($context) {
    if (($group_type = c4m_og_get_group_type($context)) && $group_type == 'project') {
      // Instruct to use a page template designated for project OG type.
      $variables['theme_hook_suggestions'][] = 'page__og__project';
    }
  }

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

  $variables['image_banner'] = kapablo_group_image_banner();
  $variables['image_banner_background'] = kapablo_group_image_banner_background();

  // Take care of the breadcrumb for OG content.
  _set_og_breadcrumbs();

  // Off-canvas trigger labels.
  $offcanvas_trigger_label_left = array(
    'icon' => 'fa fa-info',
    'label' => t('More info'),
  );
  $offcanvas_trigger_label_right = array(
    'icon' => 'fa fa-info',
    'label' => t('More info'),
  );

  // Add js to control the body no-js class.
  drupal_add_js("jQuery('body').removeClass('no-js');", array(
    'type' => 'inline',
    'scope' => 'footer',
    'weight' => 5,
  ));

  drupal_alter('c4m_offcanvas_trigger_label_left', $offcanvas_trigger_label_left);
  drupal_alter('c4m_offcanvas_trigger_label_right', $offcanvas_trigger_label_right);

  $variables['offcanvas_trigger_label_left'] = $offcanvas_trigger_label_left;
  $variables['offcanvas_trigger_label_right'] = $offcanvas_trigger_label_right;

  // Remove any og content on a conflict.
  if (c4m_og_purl_context_conflict_page()) {
    unset($variables['page']['content_top']['c4m_content_group_header_name_banner_group']);
    unset($variables['page']['content_top']['og_menu_og_single_menu_block']);
  }
}

/**
 * Helper function to set the breadcrumb for OG content.
 */
function _set_og_breadcrumbs() {
  // We use the raw path (purl pages do not have system paths).
  $path_elements = explode('/', request_path());

  // If the current path contains 2 or less parts and
  // the first part is a Persistent URL.
  if (count($path_elements) <= 2 && $purl = purl_load(
    array(
      'provider' => 'og_purl|node',
      'value' => $path_elements[0],
    )
  )) {
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
            $icon_class = c4m_content_discussion_icon_class(
              $variables['items'][$key]['#markup']
            );

            $variables['items'][$key]['#markup'] = '<i class="fa ' . $icon_class . '"></i> ' . $variables['items'][$key]['#markup'];
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

        $album_title = '';
        $album_separator = '';
        if (!empty($galleries)) {
          $gallery = array_pop($galleries);
          $album = node_load($gallery->ngid);
          $album_title = $album->title;
          $album_separator = '&nbsp;&gt;&nbsp;';
        }

        $link_to_photo = (!node_is_page($node)) ? l($node->title, 'node/' . $node->nid) : $node->title;
        foreach ($element['#items'] as $key => $item) {
          $variables['items'][$key]['#markup'] = '<h2 class="text--inline">' . $album_title . '</h2><h3 class="text--inline">' . $album_separator . $link_to_photo . '</h3><div class="clearfix"> </div>';
        }
      }

      break;
  }
}

/**
 * Implements hook_preprocess_facetapi_link_inactive().
 */
function kapablo_preprocess_facetapi_link_inactive(&$variables) {
  $variables['text'] = _kapablo_help_facetapi_link_add_icon($variables['text']);
  $variables['options']['html'] = TRUE;
}

/**
 * Implements hook_preprocess_facetapi_link_active().
 */
function kapablo_preprocess_facetapi_link_active(&$variables) {
  $variables['text'] = _kapablo_help_facetapi_link_add_icon($variables['text']);
  $variables['options']['html'] = TRUE;
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
function _kapablo_help_facetapi_link_add_icon($text_orig) {
  if ($class = c4m_content_discussion_icon_class($text_orig)) {
    return '<i class="fa ' . $class . '"></i>' . $text_orig;
  }

  return $text_orig;
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

      // og_menu sometimes doesn't provide the rendered item.
      if (!empty($data['#theme'])) {
        $data = render($data);
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
  // Adding a `no-js` class to the body element which is set to be removed by
  // JavaScript. Useful for detecting if JS is enabled in the browser.
  $variables['classes_array'][] = 'no-js';
}

/**
 * Pre-processes variables for the "bootstrap_panel" theme hook.
 *
 * In case of a bootstrap panel the title is not being rendered under the
 * kapablo_form_element_label() and at this point the title is already
 * rendered, hence we're adding the tooltip element explicitly.
 *
 * @see bootstrap_preprocess_bootstrap_panel()
 */
function kapablo_preprocess_bootstrap_panel(&$variables) {
  $element = &$variables['element'];

  if (isset($element['#description']) && !isset($element['#what_is_this'])) {
    // Adding the tooltip element.
    $element['#title'] .= kapablo_render_what_is_this($element['#description']);
    // Removing the description anyway to prevent duplications.
    $element['#description'] = NULL;
  }

  bootstrap_preprocess_bootstrap_panel($variables);
}

/**
 * Implements hook_preprocess_views_exposed_form().
 *
 * Add tooltip for the label (Search) of the full text search input.
 */
function kapablo_preprocess_views_exposed_form(&$vars) {
  if (!isset($vars['form']['#info']['filter-search_api_views_fulltext'])) {
    return;
  }

  $vars['widgets']['search']->label .= theme('kapablo_search_advanced_help');
}

/**
 * Create the image banner for groups.
 *
 * @param bool $background_image
 *   Determine if the current render is for the background image or not.
 *
 * @return string
 *   The image markup.
 */
function kapablo_group_image_banner($background_image = FALSE) {
  // No OG context.
  if (!$group = c4m_og_current_group()) {
    return FALSE;
  }

  // First establish the current group.
  $wrapper = entity_metadata_wrapper('node', $group);

  $menu_item = menu_get_item();
  $markup = '';
  if (drupal_is_front_page() || ($menu_item['path'] == 'manage' && og_user_access('node', $group->nid, 'administer group'))) {
    // Add group image.
    $file = $wrapper->c4m_banner->value();
    if (!empty($file)) {
      $file['style_name'] = 'banner';
      $file['path'] = $file['uri'];
      $file['attributes'] = array('class' => 'group-banner');

      // If current page is the 'Group Management' page, and the current
      // rendering is not for the background image of the banner then add an
      // edit link to the banner.
      if (!$background_image && $menu_item['path'] == 'manage') {
        $edit_link['element'] = array(
          '#tag' => 'span',
          '#attributes' => array(
            'class' => array('edit-link'),
          ),
          '#value' => t('Edit'),
        );
        $options = array(
          'html' => TRUE,
          'attributes' => array(
            'class' => array(
              'edit-banner',
            ),
          ),
        );
        $markup .= l(theme_html_tag($edit_link) . theme_image_style($file), url('node/' . $group->nid . '/edit', array(
          'absolute' => TRUE,
          'fragment' => 'edit-image-banner',
        )), $options);
      }
      else {
        $markup .= theme('image_style', $file);
      }
    }
  }

  return $markup;
}

/**
 * Returns the markup for the background image of the banner.
 *
 * @see kapablo_group_image_banner()
 */
function kapablo_group_image_banner_background() {
  return kapablo_group_image_banner(TRUE);
}

/**
 * Render region callback.
 *
 * @ingroup themeable
 */
function kapablo_panels_bootstrap_layouts_style_region_render($vars) {
  $display = $vars['display'];
  $panes = $vars['panes'];
  $settings = $vars['settings'];

  $layouts = array(
    'bootstrap_twocol_stacked',
    'bootstrap_threecol_stacked',
  );

  if (in_array($display->layout, $layouts) && $panes) {
    $class = array('group-' . $vars['region_id'], 'dashboard');

    if ($settings['column_size']) {
      if (empty($settings['column_type'])) {
        $settings['column_type'] = 'col-lg';
      }

      $class[] = $settings['column_type'] . '-' . $settings['column_size'];
    }

    if ($settings['offset_type'] && $settings['offset_size']) {
      $class[] = $settings['offset_type'] . '-' . $settings['offset_size'];
    }

    $class = implode(' ', $class);
    $html = implode('', $panes);

    return "<div class='$class'>$html</div>";
  }
}

/**
 * Implements hook_preprocess_panels_pane().
 *
 * @ingroup themeable
 */
function kapablo_preprocess_panels_pane(&$vars) {
  $uuid = $vars['pane']->uuid;

  $clear_sidebarblock_panel_pane = FALSE;

  $sidebarblock = FALSE;
  $sidebarblock_small = FALSE;
  $sidebarblock_multiple = FALSE;

  // Defining clear panel panes by UUID.
  $clear_sidebarblock_panel_pane_uuids = array(
    // My Groups.
    '3e93b788-7d5d-472b-93b7-c120c0b9f8a8',
    // Upcoming Events.
    '43f1ee7a-dabf-47f6-89a3-07a0e96573f2',
    // Upcoming Events.
    '5abcf7ba-8a73-4ba1-8599-8e144b4326b1',
    // Suggested Groups.
    '5be4e32c-b632-48f9-81af-3ecb57a2eaf7',
    // Suggested Projects.
    '0bcb25cb-e83a-4e43-ab3f-180c49eabffc',
    // Video embed.
    '6291300a-bfa2-4b41-b466-2acf76adce64',
  );

  // Defining sidebar blocks by UUID.
  $sidebarblocks_panel_pane_uuids = array(
    // Content Group.
    '1e41655c-1367-4fe9-ba4f-be3c36b3fc25',
    // Social Share links.
    '519bddb7-4a12-41fb-be03-a16ec9ddab93',
    // Social Share links.
    '58845eeb-9f44-44de-8439-b1027a7a67da',
    // Homepage Newsletter.
    '5d2ad3c6-4569-4046-86b0-0c4c57236914',
    // OG Highlights overview.
    '61364c4a-b99a-48c5-a681-818853195c85',
    // CTA block.
    '6d116082-1580-4306-87af-4418aa273b2a',
    // Search group form.
    'afa1da25-d147-4e2b-81c1-9b6ccd17fab6',
    // OG Members overview.
    'd54f83ca-540d-4bd0-9d56-d99e5afd46d8',
    // Content Project right.
    // 'd74f4471-e94f-4bec-bdbf-e9b2a23418c1',
    // OG Group Dashboard - CTA Block.
    'e8afdde0-18e0-4a56-982f-cc756de36f88',
    // Homepage newsletter.
    'f61cbf35-3227-4724-bc91-c08f74fd7d45',
    // OG Group Dashboard - CTA Block.
    'f7eb2728-5593-4a0f-979a-b40f29adf246',
  );

  $sidebarblocks_panel_pane_uuids_small = array();

  $sidebarblocks_panel_pane_uuids_multiple = array(
    // Featured Projects.
    '21833ed8-d9c8-4bd3-a4fd-b3127b5351a1',
    // Featured Groups.
    '6c330b80-7e65-4003-bf30-4f31188d01b9',
    // Featured Projects.
    '6efd1847-4a18-474e-9197-741d9c7be07e',
    // Featured Groups.
    '6fa5e4f2-1bfd-49a1-904c-c52cb184d024',
    // OG Related Projects.
    '77dbe08c-372e-438b-b9c6-525010b38791',
    // OG Related Groups overview.
    'bd4d5369-1eea-4c6a-b887-42ccc2b59b95',
    // Featured Groups.
    'e00433dd-e5e5-4c05-8231-b4642b65f37f',
  );

  $sidebarblocks_panel_pane_uuids_multiple_small = array();

  // Defining characteristics of sidebar blocks.
  if (in_array($uuid, $clear_sidebarblock_panel_pane_uuids)) {
    $clear_sidebarblock_panel_pane = TRUE;
  }
  elseif (in_array($uuid, $sidebarblocks_panel_pane_uuids)) {
    $sidebarblock = TRUE;
  }
  elseif (in_array($uuid, $sidebarblocks_panel_pane_uuids_small)) {
    $sidebarblock = TRUE;
    $sidebarblock_small = TRUE;
  }
  elseif (in_array($uuid, $sidebarblocks_panel_pane_uuids_multiple)) {
    $sidebarblock = TRUE;
    $sidebarblock_multiple = TRUE;
  }
  elseif (in_array($uuid, $sidebarblocks_panel_pane_uuids_multiple_small)) {
    $sidebarblock = TRUE;
    $sidebarblock_small = TRUE;
    $sidebarblock_multiple = TRUE;
  }

  // Applying classes and theme hook suggestions based on characteristics.
  if ($clear_sidebarblock_panel_pane) {
    $ths = &$vars['theme_hook_suggestions'];
    array_unshift($ths, 'panels_pane__clear_sideblock');
  }
  elseif ($sidebarblock) {
    $ths = &$vars['theme_hook_suggestions'];

    // Pane class.
    if ($sidebarblock_small) {
      array_unshift($vars['classes_array'], 'sidebarblock--small');
    }
    else {
      array_unshift($vars['classes_array'], 'sidebarblock');
    }

    // Pane title class.
    unset($vars['title_attributes_array']['class']);
    $vars['title_attributes_array']['class'][] = 'sidebarblock__title';
    $vars['title_attributes_array']['class'][] = 'closely';

    if ($sidebarblock_multiple) {
      array_unshift($ths, 'panels_pane__sidebarblock_multiple');
    }
    else {
      array_unshift($ths, 'panels_pane__sidebarblock');
    }

    if ($vars['more']) {
      $vars['classes_array'][] = 'pane--more';
    }
  }
}
