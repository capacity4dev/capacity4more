<?php

/**
 * @file
 * Definition of c4m_og_features_argument_default_enabled.
 */

/**
 * The default argument for enabled content types in a group.
 */
class c4m_og_features_argument_default_enabled extends views_plugin_argument_default {

  /**
   * Return a list of enabled content types in a group.
   */
  function get_argument() {
    $content_types = c4m_og_feature_enabled_content_types();
    return implode('+', $content_types);
  }

}
