<?php
// @codingStandardsIgnoreFile

/**
 * @file
 * Group PURL views field handler.
 */

class c4m_admin_groups_views_handler_field_group_purl extends c4m_admin_groups_views_handler_field {

  /**
   * @inheritdoc
   */
  function render($values) {
    if ($group = $this->get_og_group_from_context($values)) {
      if (!is_numeric($group->nid)) {
        return '';
      }

      $purl = array(
        'provider' => "og_purl|node",
        'id' => $group->nid,
      );
      $options = array('purl' => $purl, 'absolute' => TRUE);

      $purl_modifier = purl_load($purl);

      if (!$purl_modifier) {
        return t('No URL found');
      }

      return url($purl_modifier['value'], $options);
    }
  }

}
