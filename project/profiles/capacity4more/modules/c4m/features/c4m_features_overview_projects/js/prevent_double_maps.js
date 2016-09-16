/**
 * @file
 * Prevent double Leaflet maps in the backend (not compatible).
 */

(function ($) {

  Drupal.behaviors.preventDoubleMaps = {
    attach: function (context) {
      // Check whether a map is present on page load.
      checkForMap();

      // When left or right "add map" buttons are clicked, check for present map.
      $("button[name='c4m_left_column_add_more_add_more_bundle_c4m_paragraph_map']").mousedown( function() {
        checkForMap();
      });
      $("button[name='c4m_right_column_add_more_add_more_bundle_c4m_paragraph_map']").mousedown( function() {
        checkForMap();
      });
    }
  };

  function checkForMap() {
    // If a map is present, hide the "add map" buttons.
    if ($('.paragraphs-item-c4m-paragraph-map, .field-type-geofield-geojson').length) {
      $("button[name='c4m_left_column_add_more_add_more_bundle_c4m_paragraph_map']").hide();
      $("button[name='c4m_right_column_add_more_add_more_bundle_c4m_paragraph_map']").hide();
    }
    // Show the "add map" buttons.
    else {
      $("button[name='c4m_left_column_add_more_add_more_bundle_c4m_paragraph_map']").show();
      $("button[name='c4m_right_column_add_more_add_more_bundle_c4m_paragraph_map']").show();
    }
  }

})(jQuery);
