
/**
 * @file
 * getlocations_leaflet_polylines.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations polylines support
 * jquery stuff
*/
(function ($) {
  Drupal.behaviors.getlocations_leaflet_polylines = {
    attach: function() {

      // bail out
      if (typeof Drupal.settings.getlocations_leaflet_polylines === 'undefined') {
        return;
      }

      var default_polyline_settings = {
        strokeColor: '#FF0000',
        strokeOpacity: 0.8,
        strokeWeight: 3,
      };

      $.each(Drupal.settings.getlocations_leaflet_polylines, function (key, settings) {

        var strokeColor = (settings.strokeColor ? settings.strokeColor : default_polyline_settings.strokeColor);
        if (! strokeColor.match(/^#/)) {
          strokeColor = '#' + strokeColor;
        }
        var strokeOpacity = (settings.strokeOpacity ? settings.strokeOpacity : default_polyline_settings.strokeOpacity);
        var strokeWeight = (settings.strokeWeight ? settings.strokeWeight : default_polyline_settings.strokeWeight);
        var clickable = (settings.clickable ? settings.clickable : default_polyline_settings.clickable);
        var message = (settings.message ? settings.message : default_polyline_settings.message);

        var polylines = settings.polylines;
        var p_strokeColor = strokeColor;
        var p_strokeOpacity = strokeOpacity;
        var p_strokeWeight = strokeWeight;
        var p_clickable = clickable;
        var p_message = message;
        var pl = [];
        var Lines = new L.LayerGroup();
        for (var i = 0; i < polylines.length; i++) {
          pl = polylines[i];
          if (pl.coords) {
            if (pl.strokeColor) {
              if (! pl.strokeColor.match(/^#/)) {
                pl.strokeColor = '#' + pl.strokeColor;
              }
              p_strokeColor = pl.strokeColor;
            }
            if (pl.strokeOpacity) {
              p_strokeOpacity = pl.strokeOpacity;
            }
            if (pl.strokeWeight) {
              p_strokeWeight = pl.strokeWeight;
            }
            if (pl.clickable) {
              p_clickable = pl.clickable;
            }
            if (pl.message) {
              p_message = pl.message;
            }
            p_clickable = (p_clickable ? true : false);
            var mcoords = [];
            var poly = [];
            scoords = pl.coords.split("|");
            for (var s = 0; s < scoords.length; s++) {
              var ll = scoords[s];
              var lla = ll.split(",");
              mcoords[s] = new L.LatLng(parseFloat(lla[0]), parseFloat(lla[1]));
            }
            if (mcoords.length > 1) {
              var polyOpts = {};
              polyOpts.color = p_strokeColor;
              polyOpts.opacity = p_strokeOpacity;
              polyOpts.weight = p_strokeWeight;
              polyOpts.clickable = p_clickable;
              poly[i] = new L.Polyline(mcoords ,polyOpts);
              Lines.addLayer(poly[i]);

              if (p_clickable && p_message) {
                poly[i].bindPopup(p_message);
              }
            }
          }
        }

        if (polylines.length) {
          Lines.addTo(Drupal.getlocations_leaflet_map[key]);
          if (Drupal.getlocations_leaflet_settings[key].map_settings.layercontrol_polyl_ov) {
            Drupal.getlocations_leaflet_layerscontrol[key].addOverlay(Lines, Drupal.getlocations_leaflet_settings[key].map_settings.layercontrol_polyl_ov_label);
          }
        }

      });

    }
  };
}(jQuery));
