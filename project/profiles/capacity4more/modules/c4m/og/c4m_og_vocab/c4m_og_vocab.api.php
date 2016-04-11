<?php
/**
 * @file
 * Hooks provided by the capacity4more Group Vocabulary module.
 */

/**
 * Define the vocabularies available as group vocabulary.
 *
 * You need to implement the hook_c4m_og_vocab_info_groups() hook to define
 * what vocabularies per group node type should be automatically created.
 *
 * The information returned contains also the widget settings to setup the
 * vocabulary reference for enabled group content types.
 * You can configure for what content types the vocabulary fields ned to be
 * activated trough the hook_c4m_og_vocab_info_content() hook.
 *
 * The description & machine_name strings can be filled with variables.
 * There are 2 variables (tokens) available:
 * - [node:nid] : The Node ID of the group content for who the vocabulary will
 *                be created.
 * - [node:type]: The Node Type of the group content for who the vocabulary will
 *                be created.
 *
 * WARNING: You should always use the node id in the machine name as it needs
 *          to be unique for each vocabulary instance.
 *
 * @return array
 *   An array of vocabularies and their settings. The keys are used to identify
 *   the available vocabulary types when creating the group vocabularies and
 *   when the reference fields are added to the group content type.
 *   Each vocabulary has the following data:
 *   - name : The name of the vocabulary. Will be used to create the vocabulary
 *     in the taxonomy_vocab table.
 *   - description : The description of the vocabulary. You can use variables
 *     to identify the different vocabularies.
 *   - machine_name : The machine name of the vocabulary.
 *     You need to use the [node:nid] variable in it as each machine name needs
 *     to be unique!
 *   - settings : an array of widget settings. Is used to create the reference
 *     fields on the group content types.
 *     - required : Is this a required field.
 *     - widget_type : The widget type to use. Following types are supported:
 *       - options_buttons : radio buttons or checkboxes, depends on
 *                           cardinality.
 *       - options_select : select list.
 *       - entityreference_autocomplete : autocomplete field.
 *       - entityreference_autocomplete_tags : autocomplete + free tagging.
 *     - cardinality : How much items can be added.
 *       Use FIELD_CARDINALITY_UNLIMITED constant to indicate unlimited items.
 */
function hook_c4m_og_vocab_info_vocabularies() {
  return array(
    'c4m_vocab_category' => array(
      'name' => t('Categories'),
      'description' => t('Categories for [node:type] (nid:[node:nid]).'),
      'machine_name' => 'c4m_vocab_category_[node:nid]',
      'settings' => array(
        'required' => 0,
        'widget_type' => 'options_buttons',
        'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      ),
    ),
    'c4m_vocab_tag' => array(
      'name' => t('Tags'),
      'description' => t('Tags for [node:type] (nid:[node:nid]).'),
      'machine_name' => 'c4m_vocab_tag_[node:nid]',
      'settings' => array(
        'required' => 0,
        'widget_type' => 'entityreference_autocomplete_tags',
        'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      ),
    ),
  );
}

/**
 * Define group vocabularies per node type.
 *
 * Indicate what vocabularies should be created (per group type) when a new
 * group node is added (insert) on the platform.
 * Every time a new group node is created, the c4m_og_vocab module will use
 * this information to define what group vocabularies should be created.
 *
 * The vocabulary names refer to the config in the
 * hook_c4m_og_vocab_info_vocabularies() info hooks.
 *
 * @return array
 *   The array contains per group node type an array of vocabulary names.
 */
function hook_c4m_og_vocab_info_groups() {
  return array(
    'group' => array(
      'c4m_vocab_category',
      'c4m_vocab_tag',
    ),
    'project' => array(
      'c4m_vocab_category',
    ),
  );
}

/**
 * Define per content type what group vocabularies it can refer to.
 *
 * Use this to indicate per group content types (the content nodes not the
 * group nodes) what vocabulary reference fields that should be added.
 *
 * It will only enable vocabularies if the content type is a group content
 * post type and if the vocabulary is in use for the created group.
 *
 * @return array
 *   An array describing for each group content type what vocabularies
 *   should be refered to.
 *   It contains an array of configuration per content type
 *   (use the content type name as keys):
 *   - entity_type : The entity type of the group content entity type.
 *   - bundle : The bundle name of the group content entity type.
 *   - vocabularies : An array of vocabulary names as defined in the
 *     hook_c4m_og_vocab_info_vocabularies() hooks.
 */
function hook_c4m_og_vocab_info_content() {
  return array(
    'discussion' => array(
      'entity_type' => 'node',
      'bundle' => 'discussion',
      'vocabularies' => array(
        'c4m_vocab_category',
        'c4m_vocab_tag',
      ),
    ),
    'event' => array(
      'entity_type' => 'node',
      'bundle' => 'event',
      'vocabularies' => array(
        'c4m_vocab_category',
      ),
    ),
  );
}
