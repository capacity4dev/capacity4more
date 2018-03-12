<?php

/**
 * @file
 * Handler to add the Manage Highlights link.
 */

/**
 * Views area handler to add the Manage Highlights link.
 *
 * @ingroup views_area_handlers
 */
// @codingStandardsIgnoreLine
class c4M_features_og_highlights_handler_area_manage_link extends views_handler_area {

  /**
   * {@inheritdoc}
   */
  public function render($empty = FALSE) {
    if (c4m_features_og_members_is_power_user()) {
      $output = l(t('manage highlights'), 'manage/highlights', ['purl' => ['disabled' => FALSE]]);
      return $output;
    }
  }

}
