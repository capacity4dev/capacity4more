<?php

/**
 * @file
 * Current Search plugin to provide Reset filters link.
 */

/**
 * Implementation for clear all filters link.
 *
 * @see FacetapiBonusCurrentSearchResetFiltersLink
 */
class C4MSearchCurrentSearchClearAllFiltersLink extends CurrentSearchItemText {

  /**
   * Implements CurrentSearchItem::execute().
   */
  public function execute(FacetapiAdapter $adapter) {
    $data = array('facetapi_adapter' => $adapter);

    // Determines plurality of string.
    if ($this->settings['plural']) {
      $condition = '[' . $this->settings['plural_condition'] . ']';
      $count = (int) token_replace($condition, $data);
      $raw_text = ($count != 1) ? $this->settings['text_plural'] : $this->settings['text'];
    }
    else {
      $raw_text = $this->settings['text'];
    }

    // Translates text, returns themed output.
    $translated_text = $this->translate('text', $raw_text);

    // Makes sure facet builds are initialized.
    $adapter->processFacets();

    $path = current_path();
    $icon_title = t('Clear all');

    $variables = [
      'text' => l('<i class="fa fa-trash-o" title="' . $icon_title . '"></i> ' . token_replace($translated_text, $data), $path, ['html' => TRUE]),
      'wrapper' => $this->settings['wrapper'],
      'element' => $this->settings['element'],
      'css' => $this->settings['css'],
      'class' => current_search_get_classes($this->settings['classes'], $data),
      'options' => ['html' => TRUE],
    ];
    return ['#markup' => theme('current_search_text', $variables)];
  }

}
