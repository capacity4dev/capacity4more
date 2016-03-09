<?php

/**
 * Expose organic groups as context reactions.
 */
class context_og_reaction_set_group_context extends context_reaction {
  /**
   * Choose a group whose OG context will be set for this reaction.
   */
  function options_form($context) {
    $result = og_get_all_group();
    $options = array();

    foreach ($result as $gid) {
      $group = node_load($gid);
      $type = node_type_get_name($group->type);

      $options[$gid] = $type . ': ' . $group->title;
    }

    $values = $this->fetch_from_context($context);

    $form = array(
      'group' => array(
        '#title' => t('Group'),
        '#description' => t('Set the group context to the selected group.'),
        '#type' => 'select',
        '#multiple' => FALSE,
        '#options' => $options,
        '#default_value' => isset($values['group']) ? $values['group'] : '',
      ),
    );
    return $form;
  }

  function execute() {
    $contexts = context_active_contexts();
    //dpm($contexts);

    foreach ($contexts as $k => $v) {
      if (!empty($v->reactions[$this->plugin]['group'])) {
        $group = node_load($v->reactions[$this->plugin]['group']);
        og_context($group);
      }
    }
  }
}
