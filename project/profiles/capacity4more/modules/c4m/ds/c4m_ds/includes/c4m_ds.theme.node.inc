<?php
/**
 * @file
 * Custom Display Suite function fields.
 */

/**
 * DS function field.
 *
 * Render "Submitted by" User first and last name on timestamp.
 * (extends default ds field with first + last name).
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_submitted_by_and_on(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $entity = $field['entity'];
  $user = user_load($entity->uid);
  $name = c4m_user_name($user);
  $options = array(
    'attributes' => array('class' => array('user-name')),
    'purl' => array('disabled' => TRUE),
  );

  // If user is not anonymous, set link on user name.
  if ($entity->uid > 0) {
    $name = l($name, 'user/' . $user->uid, $options);
  }
  else {
    $plain_user_name['element'] = array(
      '#tag' => 'span',
      '#attributes' => array(
        'class' => array('user-name'),
      ),
      '#value' => $name,
    );
    $name = theme_html_tag($plain_user_name);
  }

  $tag['element'] = array(
    '#tag' => 'span',
    '#attributes' => array(
      'class' => array('creation-date'),
      'data-toggle' => 'tooltip',
      'data-placement' => 'bottom',
      'title' => format_date($entity->created, 'custom', 'd M Y H:i'),
    ),
    '#value' => c4m_helper_date_time_ago($entity->created, $field['formatter']),
  );

  return $name . theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render "Submitted by" User first and last name and updated on timestamp.
 * (extends default ds field with first + last name).
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_submitted_by_and_updated_on(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $entity = $field['entity'];
  $user = user_load($entity->uid);
  $name = c4m_user_name($user);
  $options = array(
    'attributes' => array('class' => array('user-name')),
    'purl' => array('disabled' => TRUE),
  );

  // If user is not anonymous, set link on user name.
  if ($entity->uid > 0) {
    $name = l($name, 'user/' . $user->uid, $options);
  }
  else {
    $plain_user_name['element'] = array(
      '#tag' => 'span',
      '#attributes' => array(
        'class' => array('user-name'),
      ),
      '#value' => $name,
    );
    $name = theme_html_tag($plain_user_name);
  }

  $tag['element'] = array(
    '#tag' => 'span',
    '#attributes' => array(
      'class' => array('creation-date'),
      'data-toggle' => 'tooltip',
      'data-placement' => 'bottom',
      'title' => format_date($entity->changed, 'custom', 'd M Y H:i'),
    ),
    '#value' => c4m_helper_date_time_ago($entity->changed, $field['formatter']),
  );

  return $name . theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render node creation date according to time ago.
 *
 * If timestamp is within 24h of now: Indicate the time ago:
 *  - x seconds ago
 *  - x minutes ago
 *  - x hours ago
 * If timestamp is more then 1 day go: Show as a date (with or without time):
 * - 5 January 2015 (, 16:47)
 * - 28 August 2014 (, 9:05)
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_creation_date(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $tag['element'] = array(
    '#tag' => 'span',
    '#attributes' => array(
      'class' => array('creation-date'),
      'data-toggle' => 'tooltip',
      'data-placement' => 'bottom',
      'title' => format_date(
        $field['entity']->created,
        'custom',
        'd F Y - H:i'
      ),
    ),
    '#value' => c4m_helper_date_time_ago(
      $field['entity']->created,
      $field['formatter']
    ),
  );

  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render node update date according to time ago.
 *
 * If timestamp is within 24h of now: Indicate the time ago:
 *  - x seconds ago
 *  - x minutes ago
 *  - x hours ago
 * If timestamp is more then 1 day go: Show as a date (with or without time):
 * - 5 January 2015 (, 16:47)
 * - 28 August 2014 (, 9:05)
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_update_date(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $tag['element'] = array(
    '#tag' => 'span',
    '#attributes' => array(
      'class' => array('update-date'),
      'data-toggle' => 'tooltip',
      'data-placement' => 'bottom',
      'title' => format_date(
        $field['entity']->changed,
        'custom',
        'd F Y - H:i'
      ),
    ),
    '#value' => c4m_helper_date_time_ago(
      $field['entity']->changed,
      $field['formatter']
    ),
  );

  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render a span with the relevant content type icon.
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_content_type_icon(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $object = $field['entity'];

  $info = c4m_helper_entity_label_info($object);

  $tag['element'] = array(
    '#tag' => 'i',
    '#attributes' => array(
      'class' => array('fa', $info['icon']),
    ),
    '#value' => '',
  );

  return theme_html_tag($tag);
}

/**
 * Returns HTML for content type label DS field.
 *
 * @param array $field
 *   Field array.
 *
 * @return string
 *   HTML output.
 */
function theme_c4m_ds_content_type_label(array $field) {
  if (empty($field['entity'])) {
    return '';
  }

  $entity = $field['entity'];
  $info = c4m_helper_entity_label_info($entity);

  $type = ucwords($info['singular']);
  $icon_html = '';

  if (!empty($info['icon'])) {
    $icon_html = '<i class="fa ' . $info['icon'] . '"></i> ';
  }

  $tag['element'] = array(
    '#tag' => 'span',
    '#value' => $icon_html . $type,
    '#attributes' => array(
      'class' => array(
        'label',
        'label-primary',
      ),
    ),
  );

  return theme_html_tag($tag);
}

/**
 * Returns HTML for entity type label DS field.
 *
 * @param array $field
 *   Field array.
 *
 * @return string
 *   HTML output.
 */
function theme_c4m_ds_entity_type_label(array $field) {
  if (empty($field['entity'])) {
    return '';
  }

  $entity = $field['entity'];
  $label = c4m_helper_entity_get_entity_type_label($entity, $entity->type);

  return $label;
}

/**
 * DS function field.
 *
 * Render <content type> posted by.
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_type_update_action(array $field) {
  return _theme_c4m_ds_type_action($field, 'update action');
}

/**
 * DS function field.
 *
 * Render <content type> posted by.
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_type_insert_action(array $field) {
  return _theme_c4m_ds_type_action($field, 'insert action');
}

/**
 * DS function field.
 *
 * Render <content type> posted by.
 *
 * @param array $field
 *   The field that needs to be rendered.
 * @param string $action
 *   The action that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function _theme_c4m_ds_type_action(array $field, $action) {
  $output = '';

  if (empty($field['entity'])) {
    return $output;
  }
  $entity = $field['entity'];

  $label_info = c4m_helper_entity_label_info($entity);

  drupal_alter('c4m_helper_entity_label_info', $label_info, $entity);

  if ($entity->type == 'share') {
    $node = entity_metadata_wrapper(
      'node',
      $entity
    );
    $group_wrapper = entity_metadata_wrapper(
      'node',
      $node->og_group_ref->value()
    );

    $group_type = $group_wrapper->getBundle();

    $url_options = array(
      'absolute' => TRUE,
      'purl' => array(
        'provider' => 'og_purl|node',

        'id' => $group_wrapper->nid->value(),
      ),
    );

    $group_url = l(
      $group_wrapper->title->value(),
      url('<front>', $url_options)
    );

    $tag['element'] = array(
      '#tag' => 'span',
      '#attributes' => array(
        'class' => array('posted-by'),
        '#html' => TRUE,
      ),
      '#value' => t(
        'shared @original_type to the @group_type !group_link',
        array(
          '@original_type' => $label_info['singular'],
          '@group_type' => $group_type,
          '!group_link' => $group_url,
        )
      ),
    );
  }
  else {
    $tag['element'] = array(
      '#tag' => 'span',
      '#attributes' => array(
        'class' => array('posted-by'),
      ),
      '#value' => $label_info[$action],
    );
  }

  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render Shared <content> FROM <source group>.
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_type_insert_action_share_from(array $field) {
  $output = '';

  if (empty($field['entity'])) {
    return $output;
  }

  $entity = $field['entity'];

  if ($entity->type !== 'share') {
    return $output;
  }

  $label_info = c4m_helper_entity_label_info($entity);

  drupal_alter('c4m_helper_entity_label_info', $label_info, $entity);


  $node = entity_metadata_wrapper(
    'node',
    $entity
  );

  // Retrieve original node.
  $source_node = $node->c4m_source_entity->value();
  $original_node = entity_metadata_wrapper('node', $source_node);

  $group_wrapper = entity_metadata_wrapper(
    'node',
    $original_node->og_group_ref->value()
  );

  $group_type = $group_wrapper->getBundle();

  $group_url = l(
    $group_wrapper->title->value(),
    url(
      'node/' . $group_wrapper->get('nid')->value(),
      array('purl' => array('disabled' => TRUE), 'absolute' => TRUE)
    )
  );

  $tag['element'] = array(
    '#tag' => 'span',
    '#attributes' => array(
      'class' => array('posted-by'),
      '#html' => TRUE,
    ),
    '#value' => t(
      'shared @article @original_type from the @group_type !group_link',
      array(
        '@article' => $label_info['article'],
        '@original_type' => $label_info['singular'],
        '@group_type' => $group_type,
        '!group_link' => $group_url,
      )
    ),
  );

  return theme_html_tag($tag);
}

/**
 * Get all entity stats in one field.
 *
 * This is just a simple function, not a theme hook implementation.
 *
 * @param array $field
 *   The field info.
 *
 * @return string
 *   The rendered field.
 */
function theme_c4m_ds_content_footer_stats(array $field) {
  $entity = $field['entity'];

  $recommends = c4m_helper_entity_entity_get_properties(
    $entity,
    array(),
    '',
    'node',
    array('flag_name' => 'c4m_og_content_recommend')
  );

  $items['recommends'] = theme(
    'c4m_ds_entity_recommends_count',
    array(
      'count' => (!empty($recommends) ? c4m_content_ec_number_format(
        $recommends
      ) : 0),
    )
  );

  // Only show comments if comments counter is relevant to be shown.
  //
  // Only show if:
  //  - comments are not hidden
  //  AND
  //  - comments are not closed and the amount of comments is bigger than 0
  if (
    $entity->comment == COMMENT_NODE_OPEN ||
    ($entity->comment == COMMENT_NODE_CLOSED && $entity->comment_count > 0)
  ) {
    $items['comments'] = theme(
      'c4m_ds_entity_comments_count',
      array('count' => c4m_content_ec_number_format($entity->comment_count))
    );
  }

  $statistic = statistics_get($entity->nid);
  if (empty($statistic['totalcount'])) {
    $statistic['totalcount'] = 0;
  }

  $items['views'] = theme(
    'c4m_ds_entity_views_count',
    array('count' => c4m_content_ec_number_format($statistic['totalcount']))
  );

  if ($field['formatter'] === 'downloads') {
    $entity_wrapper = entity_metadata_wrapper('node', $entity);
    $document = $entity_wrapper->c4m_document->value();

    if (!empty($document)) {
      $file_object = file_load($document['fid']);
      $items['downloads'] = theme(
        'c4m_ds_entity_downloads_count',
        array(
          'count' => (!empty($file_object->download_count) ? c4m_content_ec_number_format(
            $file_object->download_count
          ) : 0),
        )
      );
    }
  }

  return implode($items);
}

/**
 * Get number of content items per topic.
 *
 * @param array $field
 *   The field info.
 *
 * @return NULL|string
 *   The rendered field.
 */
function theme_c4m_ds_topic_content_stats(array $field) {
  if (!isset($field['entity'])) {
    return NULL;
  }
  $entity = $field['entity'];

  if (!module_exists('c4m_content_topic')) {
    return NULL;
  }

  $stats_summary = array(
    '#theme' => 'c4m_website_statistics_summary',
    '#data' => c4m_content_get_topic_statistics(),
  );

  return render($stats_summary);
}

/**
 * Get a label with the publication status of a node.
 *
 * @param array $field
 *   The field info.
 *
 * @return string
 *   The rendered field.
 */
function theme_c4m_ds_content_status(array $field) {
  if (!isset($field['entity'])) {
    return NULL;
  }
  $entity = $field['entity'];

  if (intval($entity->status) !== NODE_NOT_PUBLISHED) {
    return NULL;
  }

  $tag['element'] = array(
    '#tag' => 'span',
    '#value' => t('Draft'),
  );

  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render group type info.
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_group_access_info(array $field) {
  if (!isset($field['entity'])) {
    return NULL;
  }

  $group_access = c4m_og_get_access_type($field['entity']);

  $tag['element'] = array(
    '#tag' => 'span',
    '#value' => $group_access['title'],
  );

  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render group members count.
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_group_members_count(array $field) {
  if (!isset($field['entity'])) {
    return NULL;
  }

  $members = c4m_og_get_members_count($field['entity']);

  $tag['element'] = array(
    '#tag' => 'span',
    '#value' => format_plural(
      $members,
      '1 member',
      '@count members',
      array('@count' => $members)
    ),
  );

  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render group posts count.
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_group_posts_count(array $field) {
  if (!isset($field['entity'])) {
    return NULL;
  }

  $posts = c4m_og_get_posts_count($field['entity']);

  $tag['element'] = array(
    '#tag' => 'span',
    '#value' => format_plural(
      $posts,
      '1 post',
      '@count posts',
      array('@count' => $posts)
    ),
  );

  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render group recommendation count.
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_group_recommendation_count_full(array $field) {
  if (!isset($field['entity'])) {
    return NULL;
  }

  $entity = $field['entity'];

  $recommends = c4m_helper_entity_entity_get_properties(
    $entity,
    array(),
    '',
    'node',
    array('flag_name' => 'c4m_og_content_recommend')
  );

  $output = theme(
    'c4m_ds_entity_recommends_count_full',
    array(
      'text' => format_plural(
        !empty($recommends) ? $recommends : 0,
        '1 recommendation',
        '@count recommendations',
        array('@count' => !empty($recommends) ? c4m_content_ec_number_format(
          $recommends
        ) : 0
        )
      ),
    )
  );

  return $output;
}

/**
 * DS function field.
 *
 * Render group access type.
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_group_type(array $field) {
  if (!isset($field['entity'])) {
    return NULL;
  }

  $group_type = c4m_og_get_access_type($field['entity']);

  $tag['element'] = array(
    '#tag' => 'span',
    '#value' => $group_type['title'],
  );

  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render group access type icon.
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_group_type_icon(array $field) {
  if (!isset($field['entity'])) {
    return NULL;
  }

  $group_type = c4m_og_get_access_type($field['entity']);

  $tag['element'] = array(
    '#tag' => 'span',
    '#attributes' => array(
      'class' => array(
        'group-icon',
        'group-' . $group_type['type'],
        'node-icon',
        'as-group-' . $group_type['type'],
      ),
    ),
    '#value' => '',
  );

  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render group membership type.
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_group_membership_type(array $field) {
  if (!isset($field['entity'])) {
    return NULL;
  }

  // Get membership type.
  global $user;
  $group = node_load($field['entity']->nid);
  $group_membership_type = c4m_user_og_get_role_in_group_human($user, $group);

  if (!$group_membership_type) {
    return;
  }

  $tag['element'] = array(
    '#tag' => 'span',
    '#value' => $group_membership_type,
    '#attributes' => array(
      'class' => array(
        'membership-indicator',
        'label',
        'label-primary',
      ),
    ),
  );

  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render the highlight node link.
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_node_highlight(array $field) {
  if (!isset($field['entity'])) {
    return NULL;
  }

  $node = $field['entity'];

  // Make sure the node is a group content.
  if (!$group = c4m_og_get_group_of_content($node)) {
    // The node is not a group content, might be the group itself, hence we
    // manipulate the parameter so the access callback will handle it.
    $group = $node;
  }

  if (!c4m_content_toggle_highlight_access($group, $node, $node->promote)) {
    return NULL;
  }

  // We should allow block-list view mode to display the highlight button only
  // withing og context().
  $block_list_view_mode = !empty($field['view_mode']) && $field['view_mode'] == 'highlight_list';
  if ($block_list_view_mode || !empty($field['formatter_settings']['ft']['lb-cl']) && $field['formatter_settings']['ft']['lb-cl'] == 'block-list') {
    if (!og_context()) {
      return NULL;
    }
  }

  // Add Drupal's ajax system to the current page.
  drupal_add_library('system', 'drupal.ajax');

  $link = c4m_content_create_highlight_link(
    $group->nid,
    $node->nid,
    $node->promote
  );

  $tag['element'] = array(
    '#tag' => 'div',
    '#value' => $link,
    '#attributes' => array(
      'class' => array(
        'c4m-node-highlight',
        "c4m-{$node->type}-node-highlight",
      ),
    ),
  );

  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render the promote node link.
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_node_promote(array $field) {
  if (!isset($field['entity'])) {
    return NULL;
  }

  $node = $field['entity'];

  if (!in_array($node->type, c4m_content_promotable_node_types())) {
    return NULL;
  }

  // Make sure the node has a group.
  if (!$group = c4m_og_get_group_of_content($node)) {
    return NULL;
  }

  if ($group->type == 'project') {
    return;
  }

  // Only power users can promote a node.
  if (!c4m_features_og_members_is_power_user($group)) {
    return NULL;
  }

  return flag_create_link('c4m_og_content_highlight', $node->nid);
}

/**
 * DS function field.
 *
 * Render members of a group with particular role.
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_group_role_members(array $field) {
  $output = '';

  if (empty($field['entity'])) {
    return $output;
  }
  $entity = $field['entity'];

  $members = c4m_og_get_users_by_roles(
    $entity->nid,
    array($field['formatter'])
  );

  foreach ($members as $member) {
    // Don't list the group owner twice.
    if ($entity->uid !== $member->uid) {
      $user = user_load($member->uid);
      $output .= ', ' . l(c4m_user_name($user), 'user/' . $member->uid);
    }
  }

  return ltrim($output, ', ');
}

/**
 * DS function field.
 *
 * Render start date of an event inside a calendar icon.
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_event_start_icon(array $field) {
  $output = '';

  if (empty($field['entity'])) {
    return $output;
  }
  $entity_wrapper = entity_metadata_wrapper('node', $field['entity']);
  $date_wrapper = $entity_wrapper->c4m_datetime_end->value();
  $start_date = new DateTime(
    $date_wrapper['value'],
    new DateTimeZone($date_wrapper['timezone_db'])
  );
  // Date at DB is stored at UTC, so need to adjust according to timezone.
  date_timezone_set($start_date, timezone_open($date_wrapper['timezone']));

  $tag['element'] = array(
    '#tag' => 'div',
    '#value' => '<i class="fa fa-calendar-o fa-stack-2x"></i>
  <span class="fa-stack-1x calendar-text">' . $start_date->format(
        'd'
      ) . '</span>',
    '#attributes' => array(
      'class' => array(
        'fa-stack',
        'fa-2x',
      ),
    ),
  );

  $icon_day = theme_html_tag($tag);

  $tag['element'] = array(
    '#tag' => 'div',
    '#value' => $start_date->format('M'),
    '#attributes' => array(
      'class' => array(
        'fa-2x',
        'calendar-text-month',
      ),
    ),
  );

  $month = theme_html_tag($tag);

  return $icon_day . $month;
}

/**
 * DS function field.
 *
 * Render Cover image if set, otherwise first picture of album.
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_photoalbum_cover_image(array $field) {
  $output = '';

  if (empty($field['entity'])) {
    return $output;
  }
  $relationships = node_gallery_api_get_relationships($field['entity']->nid);

  foreach ($relationships as $relationship) {
    $cover_nid = node_gallery_api_get_cover_nid($relationship->ngid);
  }

  if (empty($cover_nid)) {
    $first = array_shift($relationships);

    if ($first) {
      $cover_nid = $first->nid;
    }
  }

  if (!empty($cover_nid)) {
    // Load cover node.
    $cover_image_node = entity_metadata_wrapper('node', $cover_nid);
    $file = $cover_image_node->c4m_media->value();

    $style = $field['formatter'];
  }

  if (empty($file)) {
    $output = '';
  }
  else {
    $file['style_name'] = empty($style) ? 'media_thumbnail' : $style;
    $file['path'] = $file['uri'];
    $file['attributes'] = array('class' => 'user-image');
    $output = theme_image_style($file);
  }

  return $output;
}

/**
 * DS function field.
 *
 * Render administration link.
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_group_administer_link(array $field) {
  global $user;

  $entity = $field['entity'];

  if (og_user_access('node', $entity->nid, 'administer group', $user)) {
    return l(
      '<i class="fa fa-cog"></i> ' . t(
        'Manage this @group_type',
        array('@group_type' => $entity->type)
      ),
      'manage',
      array('html' => TRUE)
    );
  }
}

/**
 * DS function field.
 *
 * Render download link of a photo.
 *
 * @param array $field
 *   The field definition.
 */
function theme_c4m_ds_photo_download(array $field) {
  if (isset($field['entity'])) {
    $entity = entity_metadata_wrapper('node', $field['entity']);
    $file = $entity->c4m_media->file->value();
    $link = l(t('View original photo'), file_create_url($file->uri));
    return $link . ' (' . format_size($file->filesize) . ')';
  }
}

/**
 * DS function field.
 *
 * Render download link of a photo.
 *
 * @param array $field
 *   The field definition.
 *
 * @return string
 *   The rendered version.
 */
function theme_c4m_ds_content_shared_to(array $field) {
  if (empty($field['entity'])) {
    return '';
  }

  $entity = $field['entity'];

  return theme(
    'c4m_ds_embed_view',
    array(
      'view' => 'c4m_content_share_overview',
      'display' => 'block',
      'header' => 'h3',
      'args' => array($entity->nid),
    )
  );
}

/**
 * DS function field.
 *
 * Render project type icon.
 *
 * @param array $field
 *   The field that needs to be rendered.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_ds_project_type_icon(array $field) {
  if (!isset($field['entity'])) {
    return NULL;
  }

  $entity = entity_metadata_wrapper('node', $field['entity']);
  $project_type = $entity->c4m_project_type->value();

  $tag['element'] = array(
    '#tag' => 'i',
    '#attributes' => array(
      'class' => array(
        'fa',
        ($project_type == 'programme') ? 'fa-puzzle-piece' : 'fa-flag-checkered',
        'project-type-' . $project_type,
      ),
    ),
    '#value' => '',
  );

  return theme_html_tag($tag);
}
