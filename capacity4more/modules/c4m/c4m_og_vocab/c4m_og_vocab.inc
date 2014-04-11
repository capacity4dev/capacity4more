<?php
/**
 * @file
 *
 * All code needed to create all vocabularies when a new group is created.
 */

/**
 * Function to trigger the creation of all group categories and to link al
 * content types to it.
 */
function c4m_og_vocab_trigger_create_group_categories($group) {
  // Get all the defined group vocabularies.
  $groups = c4m_og_vocab_info(C4M_OG_VOCAB_INFO_GROUPS);
  if (!isset($groups[$group->type])) {
    return;
  }
  $group_categories = array_combine($groups[$group->type], $groups[$group->type]);

  // Get all the available vocabularies.
  $vocabularies = c4m_og_vocab_info(C4M_OG_VOCAB_INFO_VOCABULARIES);
  $vocabularies = array_intersect_key($vocabularies, $group_categories);
  if (empty($vocabularies)) {
    return;
  }

  // Create the group vocabularies.
  $vocabs = c4m_og_vocab_create_group_vocabularies($group, $vocabularies);

  // Enable the group vocabulary for all group content types that need it.
  foreach ($vocabs AS $vocab_name => $vocab) {
    $types = c4m_og_vocab_get_info_content_types_by_vocabulary_name($vocab_name);
    if (empty($types)) {
      continue;
    }

    $settings = (isset($vocabularies[$vocab_name]['settings']))
      ? $vocabularies[$vocab_name]['settings']
      : array();

    c4m_og_vocab_enable_group_vocabulary_on_group_content_types(
      $types,
      $vocab,
      $settings
    );
  }
}

/**
 * Create all group vocabularies based on the given configuration.
 *
 * @param stdClass $group
 *   The group node.
 * @param array $vocabularies
 *   The vocabularies we need to create.
 *
 * @return array
 *   The vocabulary objects.
 */
function c4m_og_vocab_create_group_vocabularies($group, $vocabularies) {
  $vocabs = array();

  foreach ($vocabularies AS $vocabulary_name => $vocabulary) {
    $vocabs[$vocabulary_name] = c4m_og_vocab_create_group_vocabulary(
      $group,
      $vocabulary['machine_name'],
      $vocabulary['name'],
      $vocabulary['description']
    );
  }

  return $vocabs;
}


/**
 * Create a group vocabulary.
 *
 * @param stdClass $group
 *   The group node
 * @param string $machine_name
 * @param string $name
 * @param string $description
 *
 * @return stdClass
 *   The created vocabulary.
 */
function c4m_og_vocab_create_group_vocabulary(
  $group, $machine_name, $name, $description
) {
  // Make sure that the machine name is unique.
  // We do this by adding the nid to the machine name.
  if (!preg_match('/\[node:nid\]/', $machine_name)) {
    $machine_name += '_[node:nid]';
  }

  $machine_name = c4m_og_vocab_fill_string($group, $machine_name);
  $description = c4m_og_vocab_fill_string($group, $description);

  // Create the new vocabulary.
  $vocab = new StdClass();
  $vocab->name = $name;
  $vocab->description = $description;
  $vocab->machine_name = $machine_name;
  $vocab->hierarchy = 1;
  taxonomy_vocabulary_save($vocab);

  // Set up the relationship between the vocabulary and the group.
  og_vocab_relation_save($vocab->vid, 'node', $group->nid);

  return $vocab;
}


/**
 * Create the link between all configured content types and the given group
 * vocabulary.
 *
 * @param array $types
 *   An array of settings per content type.
 * @param stdClass $vocab
 *   The vocabulary object
 * @param array settings
 *   Settings to use when creating the term reference widget.
 *
 * @return void
 */
function c4m_og_vocab_enable_group_vocabulary_on_group_content_types(
  $types, $vocab, $settings
) {
  foreach ($types AS $info) {
    // We do not support group taxonomies of non group content types.
    if (!og_is_group_content_type(
      $info['entity_type'],
      $info['bundle']
    )) {
      continue;
    }

    // Link the vocabulary to the content type.
    $og_vocab = og_vocab_create_og_vocab(
      $vocab->vid,
      $info['entity_type'],
      $info['bundle'],
      OG_VOCAB_FIELD,
      $settings
    );
    $og_vocab->save();
  }
}


/**
 * Get all content types on witch the given category name should be enabled.
 *
 * @param string $name
 *
 * @return array
 */
function c4m_og_vocab_get_info_content_types_by_vocabulary_name($name) {
  $types = array();

  $all = c4m_og_vocab_info(C4M_OG_VOCAB_INFO_CONTENT);
  foreach ($all AS $type => $info) {
    if (!in_array($name, $info['vocabularies'])) {
      continue;
    }

    $types[$type] = $info;
  }

  return $types;
}


/**
 * Helper to fill in the node variables into a string.
 *
 * The supported placeholders are:
 * - [node:nid] : The node id
 * - [node:type] : The node type
 *
 * @param stdClass $node
 * @param string $string
 *
 * @return array
 */
function c4m_og_vocab_fill_string($node, $string) {
  $values = array(
    '/\[node:nid\]/'  => $node->nid,
    '/\[node:type\]/' => $node->type,
  );

  $search = array_keys($values);
  $replace = array_values($values);

  return preg_replace($search, $replace, $string);
}