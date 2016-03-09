
/**
 * @file
 * getlocations_mapquest_preview.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations_mapquest module for Drupal 7
 * Manages the preview map in admin/config/getlocations/mapquest
 * this is for googlemaps API version 3
 */

(function ($) {

  Drupal.behaviors.getlocations_mapquest_preview = {
    attach: function () {

      // bail out
      if (typeof Drupal.settings.getlocations_mapquest === 'undefined' || typeof(MQA) === 'undefined' ) {
        return;
      }

      // first find the right map
      $.each(Drupal.settings.getlocations_mapquest, function (key, settings) {

        // this is the one we want
        if (settings.extcontrol == 'preview_map') {
/*
          // an event handler on zoomend and getZoom()
          //Drupal.getlocations_mapquest_map[key].on('zoomend', function() {
          Drupal.getlocations_mapquest.map[key].on('zoomend', function() {
            var z = Drupal.getlocations_mapquest.map[key].getZoomLevel()
            $("#edit-getlocations-mapquest-defaults-zoom").val(z);
          });
//R: 255, G: 255, B: 255 | #FFFFFF | ΔX: 9, ΔY: 180 | select.form-select#edit-getlocations-mapquest-defaults-zoom
          // an event handler on dragend and getCenter()
          //Drupal.getlocations_mapquest_map[key].on('dragend', function() {
          Drupal.getlocations_mapquest.map[key].on('dragend', function() {
            //var ll = Drupal.getlocations_mapquest_map[key].getCenter();
            var ll = Drupal.getlocations_mapquest.map[key].getCenter();
            $("#edit-getlocations-mapquest-defaults-latlong").val(ll.lat + ',' + ll.lng);
          });
*/

        }
      });

    }
  };
}(jQuery));
