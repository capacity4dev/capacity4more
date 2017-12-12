<?php

/**
 * @file
 * Block specific functionality like block definitions & overrides.
 */

/**
 * Override the default Search Api Facet block titles.
 *
 * Is called by @see c4m_search_block_view_alter() when the block is provided
 * by the facetapi module.
 *
 * @param mixed $data
 *   The render array.
 * @param object $block
 *   The block information for who the block is being displayed.
 */
function _c4m_search_block_facetapi_view_alter(&$data, $block) {
  // Array of title overrides as "block-delta" => "title".
  $titles = array(
    // Global.
    'C1uZlhNqghipCSyxxgucWQMdVsq4ppY5' => t('Date'),
    '4Erg9yLvJMABad12YSuX81wXLf2eoV17' => t('Language'),
    'lcuW9WS3uMIsaaA0uZQgyEVGKcC2RDWB' => t('OG Vocab'),
    'q300p1xON0icJkyRehKpatIQn7Zfnugr' => t('Status'),
    'dGKhc10y2QJpsM5ad2fQ7SS0YaaUVZXg' => t('Group or Project'),

    // Geographical.
    'JQeEQzhfJJBhHcXpX4531H7GTXL1viNU' => t('Regions & Countries'),

    // Topics.
    'SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E' => t('Topics'),
    'fzBPY1BAj0MTas5AQbIbJMNKqcb06xVW' => t('Topics'),
    'LCbhPBaJpwKclgI7jHQ9adTa9YUbXAO1' => t('Topics'),
    'bg1wyxiiqobnrzn1exkukcw9arm3on07' => t('Topics of Interest'),
    'okbRObcVrcftlQAKnMx7ns16BYwkgQpC' => t('Topics of Expertise'),

    // Content type.
    'QjdXjCmQyf1I4MYpAXp20tgcG7rR8PKS' => t('Type'),
    'z0ZWdgkZbPLU1TJrbGrvIMR0OoqyvXRa' => t('Type'),

    // Group vocabularies.
    'ZOrDSi3aBn5Scpx14PeuQryeYEcBDDJ3' => t('Categories'),
    'w6asLvBjgGIFWmRHVJbMQJLQjE6uslPx' => t('Tags'),

    // Content type specific.
    // Group type.
    '0fu22cwdXHTX0SCpBBcEbOR77Jm1IfBp' => t('Type'),
    'yxOyG0dJbBLQDLZCpS9EuYjzha6J9TNN' => t('Type'),
    // Discussion type.
    'RA7qZWw02okb78IuBysWTadEIVCrCL1b' => t('Type'),
    // Document type.
    '2qrTnbxWr0rI2lmcQR6mBDryPwkuS1PH' => t('Type'),
    // Event type.
    'ajPbeoCHay77liOuYn2HrFBMw0VZUgCz' => t('Type'),
    // Project type.
    'S9qne31IKDd1jhPm8FHFcpVq9mtX65DM' => t('Type'),
    // Project stage.
    'OK4Vyc0ny8QpANDSYVhonW7ExFGaGeb5' => t('Stage'),
  );

  // Check if we have an override for the block delta.
  if (!isset($titles[$block->delta])) {
    return;
  }

  // Override the title.
  $data['subject'] = $titles[$block->delta];
}

/**
 * Override the default current_search block titles.
 *
 * @param mixed $data
 *   The render array.
 * @param object $block
 *   The block information for who the block is being displayed.
 */
function _c4m_search_block_current_search_view_alter(&$data, $block) {
  // Override the title.
  $data['subject'] = t('You searched for:');
}
