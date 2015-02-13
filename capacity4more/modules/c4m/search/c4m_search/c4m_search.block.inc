<?php
/**
 * @file
 * Block specific functionality like block definitations & overrides.
 */

/**
 * Override the default Search Api Facet block titles.
 *
 * Is called by @see c4m_search_block_view_alter() when the block is provided
 * by the facetapi module.
 *
 * @param array $data
 *   The render array.
 * @param stdClass $block
 *   The block information for who the block is being displayed.
 */
function _c4m_search_block_facetapi_view_alter(&$data, $block) {
  // Array of title overrides as "block-delta" => "title".
  $titles = array(
    // Global.
    'C1uZlhNqghipCSyxxgucWQMdVsq4ppY5' => t('Date'),
    '4Erg9yLvJMABad12YSuX81wXLf2eoV17' => t('Language'),
    'lcuW9WS3uMIsaaA0uZQgyEVGKcC2RDWB' => t('OG Vocab'),
    'JQeEQzhfJJBhHcXpX4531H7GTXL1viNU' => t('Regions & Countries'),
    'fzBPY1BAj0MTas5AQbIbJMNKqcb06xVW' => t('Topics'),
    'QgJEmEcjJBhqSVzHPi5bPE2bqBu7Y67h' => t('Topics of Interest'),
    'QjdXjCmQyf1I4MYpAXp20tgcG7rR8PKS' => t('Type'), // Content type.

    // Group vocabularies.
    'ZOrDSi3aBn5Scpx14PeuQryeYEcBDDJ3' => t('Categories'),
    'w6asLvBjgGIFWmRHVJbMQJLQjE6uslPx' => t('Tags'),

    // Content type specific.
    'RA7qZWw02okb78IuBysWTadEIVCrCL1b' => t('Type'), // Discussion type.
    '2qrTnbxWr0rI2lmcQR6mBDryPwkuS1PH' => t('Type'), // Document type.
    'ajPbeoCHay77liOuYn2HrFBMw0VZUgCz' => t('Type'), // Event type.
  );

  // Check if we have an override for the block delta.
  if (!isset($titles[$block->delta])) {
    return;
  }

  // Override the title.
  $data['subject'] = $titles[$block->delta];
}