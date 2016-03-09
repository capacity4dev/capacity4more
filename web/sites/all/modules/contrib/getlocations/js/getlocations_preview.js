
/**
 * @file
 * getlocations_preview.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations module for Drupal 7
 * Manages the preview map in admin/config/getlocations
 * this is for googlemaps API version 3
*/

(function ($) {

  Drupal.behaviors.getlocations_preview = {
    attach: function () {

      // bail out
      if (typeof Drupal.settings.getlocations === 'undefined') {
        return;
      }

      // first find the right map
      $.each(Drupal.settings.getlocations, function (key, settings) {
        // this is the one we want
        if (settings.extcontrol == 'preview_map') {

          // an event handler on map zoom
          google.maps.event.addListener(Drupal.getlocations_map[key], 'zoom_changed', function() {
            $("#edit-getlocations-default-zoom").val(Drupal.getlocations_map[key].getZoom());
          });

          // an event handler on center changed
          google.maps.event.addListener(Drupal.getlocations_map[key], 'center_changed', function() {
            var ll = Drupal.getlocations_map[key].getCenter();
            $("#edit-getlocations-default-latlong").val(ll.lat() + ',' + ll.lng());
          });

          // an event handler on maptypeid_changed
          google.maps.event.addListener(Drupal.getlocations_map[key], 'maptypeid_changed', function() {
            var maptype = Drupal.getlocations_map[key].getMapTypeId();
            if (maptype == google.maps.MapTypeId.ROADMAP)        { maptype = 'Map'; }
            else if (maptype == google.maps.MapTypeId.SATELLITE) { maptype = 'Satellite'; }
            else if (maptype == google.maps.MapTypeId.HYBRID)    { maptype = 'Hybrid'; }
            else if (maptype == google.maps.MapTypeId.TERRAIN)   { maptype = 'Physical'; }
            else if (maptype == "OSM")                           { maptype = 'OpenStreetMap'; }
            $("#edit-getlocations-default-maptype").val(maptype);
          });



        }
      });
    }
  };
}(jQuery));
