<?php
/**
 * @file
 *
 * Admin pages for the purl module.
 */

/**
 * Page callback for the purl administration page.
 */
function purl_admin() {
  global $pager_page_array, $pager_total, $pager_total_items;
  $page = isset($_GET['page']) ? $_GET['page'] : 0;
  $element = 0;
  $limit = 20;
  $providers = purl_providers();

  // Convert $page to an array, used by other functions.
  $pager_page_array = array($page);

  $methods = _purl_options();

  $merged = array();
  foreach (array_keys($methods) as $method) {
    foreach (purl_modifiers($method) as $value => $info) {
      $info['value'] = $value;
      $merged[] = $info;
    }
  }

  $rows = array();
  for ($i = $page * $limit; $i < ($page + 1) * $limit && $i < count($merged); $i++) {
    $rows[] = array(
      $providers[$merged[$i]['provider']]['name'],
      $merged[$i]['value'],
      $merged[$i]['id'],
      $methods[variable_get('purl_method_' . $merged[$i]['provider'], 'path')],
    );
  }

  // We calculate the total of pages as ceil(items / limit).
  $pager_total_items[$element] = count($merged);
  $pager_total[$element] = ceil($pager_total_items[$element] / $limit);
  $pager_page_array[$element] = max(0, min((int) $pager_page_array[$element], ((int) $pager_total[$element]) - 1));

  if ($rows) {
    $output = theme('table', array('header' => array(t('Provider'), t('Modifier'), t('ID'), t('Method')), 'rows' => $rows));
    $output .= theme('pager');
  }
  else {
    $output = "<p>" . t('No persistent urls have been registered.') . "</p>";
  }
  return $output;
}

/**
 * Settings form for choosing the operating mode of purl
 */
function purl_settings_form($form, &$form_state) {
  $form = array();
  $options = _purl_options();

  foreach (purl_providers() as $id => $provider) {
    // Check to see whether provider has limited the available valueing methods
    if (isset($provider['methods']) && count($provider['methods'])) {
      $provider_options = array();
      foreach ($provider['methods'] as $method) {
        $provider_options[$method] = $options[$method];
      }
    }
    else {
      $provider_options = $options;
    }

    $form[$id] = array(
      '#fieldset' => true,
      '#provider' => true,
      '#title' => $provider['name'],
      '#description' => $provider['description'],
    );
    $form[$id]['purl_method_' . $id] = array(
      '#title' => t('Method'),
      '#type' => 'select',
      '#options' => $provider_options,
      '#default_value' => variable_get('purl_method_' . $id, 'path'),
    );

    // Allow processors to alter the form.
    foreach ($provider_options as $k => $v) {
      purl_get_processor($k)->admin_form($form, $id);
    }
  }

  $form = system_settings_form($form);
  $form['#theme'] = 'purl_settings_form';
  return $form;
}

/**
 * Validate a key element and move its value to the correct key if validated.
 */
function purl_admin_form_key_validate(&$element, &$form_state) {
  // Check for string identifier sanity
  if (!empty($element['#value'])) {
    if (!preg_match('!^[A-Za-z0-9_-]+$!', $element['#value'])) {
      form_set_error($element['#name'], t('The key may only consist of letters, numbers, dashes and underscores.'));
    }
    else {
      $form_state['values']["purl_method_{$element['#provider_id']}_key"] = $element['#value'];
    }
  }
  unset($form_state['values'][$element['#name']]);
}

/**
 * Validate that an element has been set with a fully qualified domain name.
 */
function purl_validate_fqdn(&$element, &$form_state) {
  if (!empty($element['#value']) && !valid_url($element['#value'], TRUE)) {
    form_set_error($element['#name'], t('The domain must be a fully qualified domain name of the form `http://www.example.com`.'));
  }
}

/**
 * Theme function for purl_settings_form()
 */
function theme_purl_settings_form($variables) {
  $form = $variables['form'];
  $output = '';
  $rows = array();
  foreach (element_children($form) as $id) {
    $row = array();
    if (isset($form[$id]['#provider'])) {
      $name = $form[$id]['#title'];
      $description = $form[$id]['#description'];
      unset($form[$id]['#title']);
      unset($form[$id]['#description']);
      $row[] = "<strong>$name</strong><div class='description'>$description</div>";

      $cell = $extra = '';
      foreach (element_children($form[$id]) as $item) {
        unset($form[$id][$item]['#title']);
        if ($item == 'extra') {
          $extra = drupal_render($form[$id][$item]);
        }
        $cell .= drupal_render($form[$id][$item]);
      }
      $row[] = $cell;
      $row[] = $extra;
    }
    $rows[] = $row;
  }
  $output .= theme('table', array('header' => array(t('Provider'), t('Modifier type'), t('Settings')), 'rows' => $rows));
  $output .= drupal_render_children($form);
  drupal_add_js(drupal_get_path("module", "purl") . "/purl.admin.js");
  return $output;
}

/**
 * Allow administrators to enable purl methods.
 */
function purl_types_form($form, &$form_state) {
  $form = array();
  $form['purl_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Types'),
    '#options' => _purl_options(false),
    '#default_value' => variable_get('purl_types', array()),
    '#description' => t('Enabled URL modification types.'),
  );
  return system_settings_form($form);
}

/**
 * Private implementation of hook_form_alter()
 */
function _purl_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'menu_edit_menu') {
    //should this be the default value??
    if (isset($form['menu_name']['#default_value'])) {
      $form['purl'] = array(
        '#tree' => true,
        '#type' => 'fieldset',
        '#title' => t('Persistent URL behavior'),
        '#description' => t('All links are normally rewritten to contain the active persistent url elements. You may set all items in this menu to maintain existing modifications (the default), or to discard them.'),
      );
      $form['purl']['rewrite'] = array(
        '#type' => 'select',
        '#options' => array('enabled' => t("Maintain"), 'disabled' => ("Discard")),
        '#title' => t('Behavior'),
        '#default_value' => variable_get('purl_menu_behavior_' . $form['menu_name']['#default_value'], 'enabled'),
      );
      $form['#submit'][] = 'purl_menu_edit_submit';
    }
  }
  elseif ($form_id == 'menu_edit_item') {
    // are these the options we wanted??
    $options = $form['options']['#value'];
    $menu_name = $form_state['build_info']['args'][2]['menu_name'];
    $menu_behavior = (variable_get('purl_menu_behavior_' . $menu_name, 'enabled') == 'disabled') ? 1 : 0;
    $form['purl'] = array(
      '#tree' => true,
      '#type' => 'fieldset',
      '#title' => t('Persistent URL'),
      '#weight' => -1,
    );
    $form['purl']['disabled'] = array(
      '#type' => 'select',
      '#options' => array(0 => t("Maintain"), 1 => ("Discard")),
      '#title' => t('Behavior'),
      '#description' => t('All links are normally rewritten to contain the active persistent url elements. You may set this item to maintain existing modifications (the default), or to discard them.'),
      '#default_value' => isset($options['purl']['disabled']) ? $options['purl']['disabled'] : $menu_behavior,
    );
    // Fetch all modifiers.
    $modifiers = array('' => t('<none>'));
    $methods = _purl_options();
    foreach (array_keys($methods) as $method) {
      foreach (purl_modifiers($method) as $value => $info) {
        $modifiers[$info['provider'] . ':' . $info['id']] = $value;
      }
    }
    asort($modifiers);
    $form['purl']['modifier'] = array(
      '#type' => 'select',
      '#options' => $modifiers,
      '#title' => t('Modifier'),
      '#description' => t('Enter a Persistent URL modifier to be used with this path.'),
      '#default_value' => (isset($options['purl']) && isset($options['purl']['provider']) && isset($options['purl']['id'])) ? $options['purl']['provider'] . ':' . $options['purl']['id'] : '',
    );
    $form['#validate'][] = 'purl_item_edit_validate';
    $form['#submit'][] = 'purl_item_edit_submit';
  }
  elseif ($form_id == 'redirect_edit_form') {
    // are these the options we wanted??
    $options = $form['redirect_options']['#value'];
    $form['purl'] = array(
      '#tree' => true,
      '#type' => 'fieldset',
      '#title' => t('Persistent URL'),
      '#weight' => -1,
    );
    // Fetch all modifiers.
    $modifiers = array('' => t('<none>'));
    $methods = _purl_options();
    foreach (array_keys($methods) as $method) {
      foreach (purl_modifiers($method) as $value => $info) {
        $modifiers[$info['provider'] . ':' . $info['id']] = $value;
      }
    }
    asort($modifiers);
    $form['purl']['modifier'] = array(
      '#type' => 'select',
      '#options' => $modifiers,
      '#title' => t('Modifier'),
      '#description' => t('Enter a Persistent URL modifier to be used with this path.'),
      '#default_value' => (isset($options['purl']['add'][0])) ? $options['purl']['add'][0]['provider'] . ':' . $options['purl']['add'][0]['id'] : '',
    );
    $form['#validate'][] = 'purl_redirect_edit_validate';
  }
}

/**
 * Submit handler for menu_edit_menu
 */
function purl_redirect_edit_validate($form, &$form_state) {
  if ($form_state['values']['purl']['disabled'] == 0 && $form_state['values']['purl']['modifier']) {
    $purl_settings = explode(':', $form_state['values']['purl']['modifier']);
    $form_state['values']['redirect_options'] = array(
      'purl' => array('add' => array(array('provider' => $purl_settings[0], 'id' => $purl_settings[1]))),
    );
  }
  else {
    $form_state['values']['redirect_options'] = array();
  }
}

/**
 * Submit handler for menu_edit_menu().
 */
function purl_menu_edit_submit($form, &$form_state) {
  $menu = $form_state['values'];

  // Add 'menu-' to the menu name to help avoid name-space conflicts.
  // @see menu_edit_menu_submit().
  if ($form['#insert']) {
    $menu['menu_name'] = 'menu-' . $menu['menu_name'];
  }

  // Save the PURL behavior for the menu tree in a variable.
  if ($menu['purl']['rewrite'] == 'disabled') {
    variable_set('purl_menu_behavior_' . $menu['menu_name'], 'disabled');
  }
  else {
    variable_del('purl_menu_behavior_' . $menu['menu_name']);
  }

  // Recurse through all items and update the PURL behavior for each.
  $tree = menu_tree_all_data($menu['menu_name']);
  _purl_menu_edit_submit_recurse($tree, $menu['purl']['rewrite']);

  menu_cache_clear($menu['menu_name']);
}

/**
 * Recurse through a menu tree and apply the given PURL behavior to each link.
 *
 * This saves each menu link that needs to have its PURL behavior updated.
 *
 *  @param array $tree
 *    A (portion) of a menu tree as generated by menu_tree_all_data().
 *  @param string $behavior
 *   The PURL behavior to check in the options array of the menu links. Either
 *   'enabled' or 'disabled'.
 */
function _purl_menu_edit_submit_recurse($tree, $behavior) {
  foreach ($tree as $id => $item) {
    // Check for items where PURL behavior doesn't match.
    if (!isset($item['options']['purl']) || ($item['options']['purl'] !== $behavior)) {
      // Save each link to set options.'
      // @see purl_menu_link_alter()
      menu_link_save($item['link']);
    }
    // Recurse through child menu items.
    if ($item['link']['has_children']) {
      _purl_menu_edit_submit_recurse($item['below'], $behavior);
    }
  }
}

/**
 * Validate handler for menu_edit_item
 *
 * Doesn't actually validate, but rather moves data to where
 * menu_edit_item_submit() expects it.
 */
function purl_item_edit_validate($form, &$form_state) {
  $form_state['values']['options']['purl'] = array();
  if (!empty($form_state['values']['purl']['modifier'])) {
    list($provider, $id) = explode(':', $form_state['values']['purl']['modifier']);
    $form_state['values']['options']['purl']['provider'] = $provider;
    $form_state['values']['options']['purl']['id'] = $id;
  }
  if (!empty($form_state['values']['purl']['disabled'])) {
    $form_state['values']['options']['purl']['disabled'] = 1;
  }
  if (empty($form_state['values']['options']['purl'])) {
    unset($form_state['values']['options']['purl']);
  }
}

// Submit handler for menu_edit_item
/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function purl_item_edit_submit($form, &$form_state) {
  menu_cache_clear($form_state['values']['menu_name']);
}