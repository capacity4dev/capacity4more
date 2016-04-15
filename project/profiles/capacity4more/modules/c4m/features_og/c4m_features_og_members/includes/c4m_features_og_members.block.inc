<?php
/**
 * @file
 * Block definitions for the c4m_features_og_members module.
 */

/**
 * Override blocks.
 *
 * @param mixed $data
 *   The render array.
 * @param object $block
 *   The block information for who the block is being displayed.
 */
function _c4m_features_og_members_block_view_alter(&$data, $block) {
  $info = array(
    'Facet API: Search service: Search Users : OG membership type' => 'Group membership type',
    'Facet API: Search service: Search Users : Organisation type' => 'Organisation type',
    'Facet API: Search service: Search Users : Organisation' => 'Organisation',
    'Facet API: Search service: Search Users : Topics of Expertise' => 'Specialist in one of these topics',
    'Facet API: Search service: Search Users : Based in' => 'Country of residence',
  );

  if (!empty($block->info) &&
      array_key_exists($block->info, $info)) {
    $data['subject'] = t('@title', array('@title' => $info[$block->info]));
  }
}
