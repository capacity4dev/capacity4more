<?php

/**
 * @file
 * Definition of c4m_features_og_members_default_membership_types.
 */

/**
 * The default argument for enabled content types in a group.
 */
//@codingStandardsIgnoreLine
class c4m_features_og_members_default_membership_types extends views_plugin_argument_default {

  /**
   * Return a list of enabled content types in a group.
   */
  //@codingStandardsIgnoreLine
  function get_argument() {
    if ($group = c4m_og_current_group()) {
      $membership_types = [
        $group->nid . '_member',
        $group->nid . '_owner',
        $group->nid . '_administrator',
      ];
      if (c4m_features_og_members_is_power_user($group)) {
        $membership_types[] = $group->nid . '_pending';
      }
      return implode('+', $membership_types);
    }
    else {
      return NULL;
    }
  }

}
