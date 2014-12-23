<?php
/**
 * @file
 *
 * Custom Display Suite function fields and theming functions.
 */

/**
 * Theme function for wiki page.
 *
 * @param $variables
 * @return null|string
 */
function theme_c4m_features_og_wiki_wiki($variables) {
  if (empty($variables['content'])) {
    return t('No wiki pages (yet).');
  }
}

