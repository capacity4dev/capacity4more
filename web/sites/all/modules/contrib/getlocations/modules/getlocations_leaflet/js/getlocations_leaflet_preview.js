
/**
 * @file
 * getlocations_preview.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations_leaflet module for Drupal 7
 * Manages the preview map in admin/config/getlocations/leaflet
 * this is for googlemaps API version 3
 */

(function ($) {

  Drupal.behaviors.getlocations_leaflet_preview = {
    attach: function () {

      // bail out
      if (typeof Drupal.settings.getlocations_leaflet === 'undefined') {
        return;
      }

      // first find the right map
      $.each(Drupal.settings.getlocations_leaflet, function (key, settings) {

        // this is the one we want
        if (settings.extcontrol == 'preview_map') {

          // an event handler on zoomend and getZoom()
          Drupal.getlocations_leaflet_map[key].on('zoomend', function() {
            $("#edit-getlocations-leaflet-defaults-zoom").val(Drupal.getlocations_leaflet_map[key].getZoom());
          });

          // an event handler on dragend and getCenter()
          Drupal.getlocations_leaflet_map[key].on('dragend', function() {
            var ll = Drupal.getlocations_leaflet_map[key].getCenter();
            $("#edit-getlocations-leaflet-defaults-latlong").val(ll.lat + ',' + ll.lng);
          });

        }
      });

    }
  };
}(jQuery));
