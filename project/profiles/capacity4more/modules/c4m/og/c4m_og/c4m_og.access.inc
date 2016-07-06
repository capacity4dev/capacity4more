<?php

/**
 * @file
 * Functionality regarding OG access (public/restricted/private).
 */

/**
 * Utility function; Return the organizations info from organizations.
 */
function c4m_og_organisations_info() {
  $default_info = array();

  $type = 'organisation';
  $nodes = node_load_multiple(array(), array('type' => $type, 'status' => NODE_PUBLISHED));
  foreach ($nodes as $organisation) {
    $wrapper = entity_metadata_wrapper('node', $organisation);
    $domains = $wrapper->c4m_domain->getIterator();
    $domains_list = array();
    foreach ($domains as $domain) {
      $domains_list[] = $domain->domain->value();
    }

    $default_info[$organisation->nid] = array(
      'title' => $organisation->title,
      'nid' => $wrapper->nid,
      'description' => $wrapper->c4m_body->value(),
      'icon' => c4m_content_organisation_get_icon($organisation),
      'domains' => $domains_list,
    );
  }

  return $default_info;
}

/**
 * Get a list of all possible access types and their information.
 *
 * @todo: Convert this into a hook.
 *
 * @return array
 *   Group access info for all group access types.
 */
function c4m_og_access_types() {
  $group_types = &drupal_static(__FUNCTION__);

  if (!isset($group_types)) {
    $group_types = array(
      'public' => array(
        'type' => 'public',
        'title' => t('Public group'),
        'helptext' => t('All capacity4dev users can access this group, only group members can post content.'),
        'description' => t('All users may view public content from this Group. Users must request to join this Group.'),
      ),
      'restricted' => array(
        'type' => 'restricted',
        'title' => t('Restricted group'),
        'helptext' => t('Access restricted to <em>Group_members</em>'),
        'description' => t('Define by organisation and/or email domain what users can view this Group. Only members can post content to the Group.'),
      ),
      'private' => array(
        'type' => 'private',
        'title' => t('Private group'),
        'helptext' => t('Only group members can access this group and post content.'),
        'description' => t('Only Group members will be able to access this Group.'),
      ),
    );
  }

  return $group_types;
}

/**
 * Get the group info (public/restricted/private) by the group.
 *
 * @param object $group
 *   The group entity.
 *
 * @return array
 *   Group access info.
 */
function c4m_og_get_access_type($group) {
  $group_types = c4m_og_access_types();

  // Check if the group_access field exists.
  if (!isset($group->group_access)) {
    return $group_types['public'];
  }

  $wrapper = entity_metadata_wrapper('node', $group);
  $group_access = $wrapper->group_access->value();

  $group_type = 'public';

  if ($group_access && $wrapper->pluggable_node_access->value()) {
    $group_type = 'restricted';
  }
  elseif ($group_access) {
    $group_type = 'private';
  }

  return $group_types[$group_type];
}

/**
 * Get the restricted information (organisations & domains).
 *
 * Do not use this function directly, use wrapper functions:
 * - c4m_og_get_organisations($group)
 * - c4m_og_get_email_domains($group)
 *
 * @param object $group
 *   The group we want to get the info from.
 *
 * @return array
 *   Array with arrays:
 *   organisations : an array of the organisations linked to the restricted
 *                   group.
 *   domains       : individual email domains linked to the restricted group.
 */
function c4m_og_get_restricted_info($group) {
  $infos = &drupal_static(__FUNCTION__, array());
  $info = array(
    'organisations' => array(),
    'domains' => array(),
  );

  // Prevent notices when called from node/add form.
  if (empty($group->nid)) {
    return $info;
  }

  if (!array_key_exists($group->nid, $infos)) {
    $wrapper = entity_metadata_wrapper('node', $group);
    $pluggable_node_accesses = $wrapper->pluggable_node_access->value();
    if (!$pluggable_node_accesses) {
      return $info;
    }
    $pluggable_node_accesses = is_array($pluggable_node_accesses) ? $pluggable_node_accesses : array($pluggable_node_accesses);
    foreach ($pluggable_node_accesses as $pluggable_node_access) {
      $data = $pluggable_node_access->data;
      if (!is_array($data) || empty($data)) {
        continue;
      }
      switch ($pluggable_node_access->type) {
        case 'email_domain':
          $info['domains'] = $data;
          break;

        case 'organisation':
          $info['organisations'] = $data;
          break;
      }
    }

    $infos[$group->nid] = $info;
  }
  return $infos[$group->nid];
}

/**
 * Reset the static restricted info cache.
 */
function c4m_og_reset_restricted_info() {
  drupal_static_reset('c4m_og_get_restricted_info');
}

/**
 * Get the organisations for the given group.
 *
 * @param object $group
 *   The group we want to get the organisations.
 *
 * @return array
 *   All the organisations (and their info) for the given group.
 */
function c4m_og_get_organisations($group) {
  $info = c4m_og_get_restricted_info($group);
  return $info['organisations'];
}

/**
 * Get the email domains that have access to the given group.
 *
 * @param object $group
 *   The group we want to get the email domains.
 *
 * @return array
 *   The email domains that are not linked to organisations also linked to the
 *   group.
 */
function c4m_og_get_email_domains($group) {
  $info = c4m_og_get_restricted_info($group);
  return $info['domains'];
}

/**
 * Implements hook_FORM_ID_form_alter().
 *
 * Adds the fields about the Group Access types & Pluggable Access.
 */
function c4m_og_form_group_node_form_alter(&$form, &$form_state) {
  // Default values.
  $default_domains = array();
  $default_organisations = array();
  $default_access_type = 'public';

  // Form changes on creation.
  if (!$form['nid']['#value']) {
    // Change title.
    drupal_set_title('Request group');

    // Change submit button on creation.
    $form['actions']['submit']['#value'] = t('Request');
  }

  // Organisation options.
  $organisation_field_options = array();
  $organisations_info = c4m_og_organisations_info();
  foreach ($organisations_info as $name => $organisation) {
    // Set arrays for later use.
    $organisation['icon']['#item']['attributes'] = array(
      'class' => 'organisation-icon',
    );

    $organisation_field_options[$name] = drupal_render($organisation['icon'])
      . filter_xss($organisation['title'])
      . '<div>'
      . filter_xss($organisation['description']['value']) . '</br>'
      . t('Accessible to users with email domains: @domains', array('@domains' => implode(', ', $organisation['domains'])))
      . '</div>';
  }

  if (!empty($form_state['node'])) {
    // Group organisations.
    $default_organisations = c4m_og_get_organisations($form_state['node']);
    if ($default_organisations) {
      $organisations = $default_organisations;
      $default_organisations = array_combine($organisations, $organisations);
    }

    // Group domains.
    $default_domains = c4m_og_get_email_domains($form_state['node']);

    // Default access type.
    $group_type = c4m_og_get_access_type($form_state['node']);
    $default_access_type = $group_type['type'];
  }

  // Access options.
  $options = array(
    'public' => t('Public'),
    'restricted' => t('Restricted'),
    'private' => t('Private'),
  );

  $form['pluggable_group_access'] = array(
    '#type' => 'radios',
    '#title' => t('Group access'),
    '#required' => TRUE,
    '#options' => $options,
    '#default_value' => $default_access_type,
    '#prefix' => '<div id="edit-permissions">',
    '#suffix' => '</div>',
  );
  $form['pluggable_group_access']['public'] = array(
    '#type' => 'radio',
    '#title' => t('Public'),
    '#weight' => 10,
    '#description' => t('All users may view public content from this Group. Users must request to join this Group.'),
  );
  $form['pluggable_group_access']['restricted'] = array(
    '#type' => 'radio',
    '#title' => t('Restricted'),
    '#weight' => 20,
    '#description' => t('Define by organisation and/or email domain what users can view this Group. Only members can post content to the Group.'),
  );
  $form['pluggable_group_access']['restricted_organisations'] = array(
    '#weight' => 25,
    '#title' => t('Allow users to access this Group by their organisation'),
    '#description' => t('Users belonging to these organisations will have access to this Group. Users must request to join this Group.'),
    '#type' => 'checkboxes',
    '#options' => $organisation_field_options,
    '#states' => array(
      // Show the checkboxes only when "restricted" is selected.
      'visible' => array(
        ':input[name="pluggable_group_access"]' => array('value' => 'restricted'),
      ),
    ),
    '#default_value' => $default_organisations,
  );
  $form['pluggable_group_access']['restricted_by_domain'] = array(
    '#weight' => 26,
    '#title' => t('Allow users to access this Group by their email domain'),
    '#description' => t('Users registered to the platform with an email domain in this list will have access to this Group. Users must request to join this Group. Add one or more email domains. The email domain is the part of the email address after the @. Example: add gmail.com to allow users with an email address like jane.doo@gmail.com.'),
    '#type' => 'textfield',
    '#states' => array(
      // Show the checkboxes only when "restricted" is selected.
      'visible' => array(
        ':input[name="pluggable_group_access"]' => array('value' => 'restricted'),
      ),
    ),
    '#default_value' => implode(' ', $default_domains),
  );

  $form['pluggable_group_access']['private'] = array(
    '#type' => 'radio',
    '#title' => t('Private'),
    '#weight' => 30,
    '#description' => t('Only Group members will be able to access this Group.'),
  );

  // Show field_membership_open_request only when pluggable_group_access is not
  // private.
  $form['field_membership_open_request']['#states'] = array(
    // Show the checkboxes only when "restricted" is selected.
    'invisible' => array(
      ':input[name="pluggable_group_access"]' => array('value' => 'private'),
    ),
  );

  // Adds submit handler.
  $form['#submit'][] = 'c4m_og_group_form_submit';

  // Hide original pluggable_node_access field.
  $form['pluggable_node_access']['#access'] = FALSE;

  // Hide group visibility field.
  $form['group_access']['#access'] = FALSE;

  // Group visibility field is required even when hidden, so we change it in
  // order to avoid validation errors.
  $form['group_access']['und']['#required'] = FALSE;

  // Add select2 widget for related groups.
  $form['c4m_related_projects'][LANGUAGE_NONE]['#attached'] = array(
    'css' => array(
      libraries_get_path('select2') . '/dist/css/select2.min.css',
      drupal_get_path('module', 'c4m_og') . '/css/select2-widget.css',
    ),
    'js' => array(
      libraries_get_path('select2') . '/dist/js/select2.min.js',
      drupal_get_path('module', 'c4m_og') . '/js/select2-widget.js',
    ),
  );
  $form['c4m_related_projects'][LANGUAGE_NONE]['#after_build'] = array('c4m_og_select2_widget_after_build');
  $form['c4m_related_group'][LANGUAGE_NONE]['#attached'] = array(
    'css' => array(
      libraries_get_path('select2') . '/dist/css/select2.min.css',
      drupal_get_path('module', 'c4m_og') . '/css/select2-widget.css',
    ),
    'js' => array(
      libraries_get_path('select2') . '/dist/js/select2.min.js',
      drupal_get_path('module', 'c4m_og') . '/js/select2-widget.js',
    ),
  );
  $form['c4m_related_group'][LANGUAGE_NONE]['#after_build'] = array('c4m_og_select2_widget_after_build');
}

/**
 * After build callback; Add required JS settings to Select2 fields.
 */
function c4m_og_select2_widget_after_build($element, &$form_state) {
  // There may be more than one Select2 field and each of them gets to this
  // function separately and should be added to the existing array of elements
  // saved in a drupal JS setting.
  // The problem is we cannot modify an existing drupal JS setting, we can only
  // override it. The solution is saving the array of elements as static, and
  // then overriding the JS setting according to it.
  $setting = drupal_static(__FUNCTION__, array());

  $setting[] = array(
    'selector' => '#' . $element['#id'],
    'cardinality' => 3,
  );

  drupal_add_js(array('select2_widget' => $setting), 'setting');
  return $element;
}

/**
 * Submit handler; Handle group access type.
 */
function c4m_og_group_form_submit($form, &$form_state) {
  // Check whether we already have referenced entity in pluggable_node_access.
  $node = $form_state['node'];
  $wrapper = entity_metadata_wrapper('node', $node);

  // Get the new domain values.
  $group_access = $form_state['values']['pluggable_group_access'];
  switch ($group_access) {
    case 'restricted':
      // Set group_access to "private".
      $form_state['values']['group_access'][LANGUAGE_NONE][0]['value'] = 1;

      // Extract the organisations from the form.
      $organisations = array_keys(
        array_filter($form_state['values']['restricted_organisations'])
      );

      // Extract the domains from the form.
      $domains = array_map(
        'trim',
        explode(' ', $form_state['values']['restricted_by_domain'])
      );

      // Save the pluggable_node_access.
      $pluggable_node_accesses = c4m_og_save_pluggable_node_access_restricted($node, $organisations, $domains);

      $form_state['values']['pluggable_node_access'][LANGUAGE_NONE] = NULL;
      foreach ($pluggable_node_accesses as $pluggable_node_access) {
        $form_state['values']['pluggable_node_access'][LANGUAGE_NONE][] = array('target_id' => $pluggable_node_access->id);
      }
      break;

    case 'public':
      // Set group_access to "public".
      $form_state['values']['group_access'][LANGUAGE_NONE][0]['value'] = 0;

      // Delete pluggable_node_access entity if exist.
      c4m_og_remove_pluggable_node_access($wrapper, $form_state);
      break;

    case 'private':
      // Set group_access to "private".
      $form_state['values']['group_access'][LANGUAGE_NONE][0]['value'] = 1;

      // Delete pluggable_node_access entity if exist.
      c4m_og_remove_pluggable_node_access($wrapper, $form_state);
      break;
  }

  // Clear the info cache!
  c4m_og_reset_restricted_info();
}

/**
 * API to save the pluggable_node_access record for a restricted group.
 *
 * @param object $group
 *   The group the pluggable access needs to be saved for.
 * @param array $organisations
 *   The organisations that needs to be linked to the node_access.
 * @param array $domains
 *   Optional domains to link to the group node_access.
 *
 * @return object
 *   The pluggable_node_access entity.
 */
function c4m_og_save_pluggable_node_access_restricted($group, $organisations = array(), $domains = array()) {
  $domains = array_combine($domains, $domains);

  $wrapper = entity_metadata_wrapper('node', $group);
  $pluggable_node_accesses = $wrapper->pluggable_node_access->value();
  $entities = array();

  if (empty($pluggable_node_accesses)) {
    // Create new pluggable_node_access entity.
    $values = array(
      'type' => 'email_domain',
      'data' => $domains,
    );
    $pluggable_node_access = entity_create('pluggable_node_access', $values);
    $pluggable_node_access->save();
    $entities[] = $pluggable_node_access;

    $values = array(
      'type' => 'organisation',
      'data' => $organisations,
    );
    $pluggable_node_access = entity_create('pluggable_node_access', $values);
    $pluggable_node_access->save();
    $entities[] = $pluggable_node_access;
  }
  else {
    $domains_saved = FALSE;
    $organisations_saved = FALSE;
    $pluggable_node_accesses = is_array($pluggable_node_accesses) ? $pluggable_node_accesses : array($pluggable_node_accesses);
    foreach ($pluggable_node_accesses as $pluggable_node_access) {
      switch ($pluggable_node_access->type) {
        case 'email_domain':
          $pluggable_node_access->data = $domains;
          $domains_saved = TRUE;
          break;

        case 'organisation':
          $pluggable_node_access->data = $organisations;
          $organisations_saved = TRUE;
          break;
      }
      $pluggable_node_access->save();
      $entities[] = $pluggable_node_access;
    }

    if (!$domains_saved) {
      $values = array(
        'type' => 'email_domain',
        'data' => $domains,
      );
      $pluggable_node_access = entity_create('pluggable_node_access', $values);
      $pluggable_node_access->save();
      $entities[] = $pluggable_node_access;
    }

    if (!$organisations_saved) {
      $values = array(
        'type' => 'organisation',
        'data' => $organisations,
      );
      $pluggable_node_access = entity_create('pluggable_node_access', $values);
      $pluggable_node_access->save();
      $entities[] = $pluggable_node_access;
    }
  }

  return $entities;
}

/**
 * Utility function; Removes referenced entity and form value.
 *
 * @param EntityMetadataWrapper $wrapper
 *   Wrapped node entity.
 * @param array $form_state
 *   Form state array.
 */
function c4m_og_remove_pluggable_node_access(
  EntityMetadataWrapper $wrapper,
  array &$form_state
) {
  // Delete referenced entity.
  if ($pluggable_node_accesses = $wrapper->pluggable_node_access->value()) {
    foreach ($pluggable_node_accesses as $pluggable_node_access) {
      $pluggable_node_access->delete();
    }
  }

  // Clean form value.
  $form_state['values']['pluggable_node_access'][LANGUAGE_NONE] = NULL;
}

/**
 * Implements hook_og_user_access_alter().
 *
 * Allow subscribing based on field_membership_open_request value.
 */
function c4m_og_og_user_access_alter(&$perm, $context) {
  if ($context['string'] != 'subscribe without approval') {
    return;
  }

  if ($context['group_type'] != 'node') {
    return;
  }
  $group = $context['group'];
  if ($group->type != 'group') {
    return;
  }
  $wrapper = entity_metadata_wrapper('node', $group);

  $perm['subscribe without approval'] = $wrapper->field_membership_open_request->value();
}
