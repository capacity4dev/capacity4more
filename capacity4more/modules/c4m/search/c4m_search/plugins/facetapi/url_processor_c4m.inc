<?php

/**
 * @file
 * A custom URL processor for c4m.
 */

/**
 * Extension of FacetapiUrlProcessor.
 */
class FacetapiUrlProcessorC4m extends FacetapiUrlProcessorStandard {

  /**
   * Implements FacetapiUrlProcessorC4m::setBreadcrumb().
   */
  public function setBreadcrumb() {
    // Reset the breadcrumb.
    drupal_set_breadcrumb(array());
  }

}
