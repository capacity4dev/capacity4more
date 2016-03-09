
/**
 * @file
 * getlocations_leaflet_polygons.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations polygons support
 * jquery stuff
*/
(function ($) {
  Drupal.behaviors.getlocations_leaflet_polygons = {
    attach: function() {

      // bail out
      if (typeof Drupal.settings.getlocations_leaflet_polygons === 'undefined') {
        return;
      }

      var default_polygon_settings = {
        strokeColor: '#FF0000',
        strokeOpacity: 0.8,
        strokeWeight: 3,
        fillColor: '#FF0000',
        fillOpacity: 0.35
      };

      $.each(Drupal.settings.getlocations_leaflet_polygons, function (key, settings) {

        var strokeColor = (settings.strokeColor ? settings.strokeColor : default_polygon_settings.strokeColor);
        if (! strokeColor.match(/^#/)) {
          strokeColor = '#' + strokeColor;
        }
        var strokeOpacity = (settings.strokeOpacity ? settings.strokeOpacity : default_polygon_settings.strokeOpacity);
        var strokeWeight = (settings.strokeWeight ? settings.strokeWeight : default_polygon_settings.strokeWeight);
        var fillColor = (settings.fillColor ? settings.fillColor : default_polygon_settings.fillColor);
        if (! fillColor.match(/^#/)) {
          fillColor = '#' + fillColor;
        }
        var fillOpacity = (settings.fillOpacity ? settings.fillOpacity : default_polygon_settings.fillOpacity);
        var clickable = (settings.clickable ? settings.clickable : default_polygon_settings.clickable);
        var message = (settings.message ? settings.message : default_polygon_settings.message);

        var polygons = settings.polygons;
        var p_strokeColor = strokeColor;
        var p_strokeOpacity = strokeOpacity;
        var p_strokeWeight = strokeWeight;
        var p_fillColor = fillColor;
        var p_fillOpacity = fillOpacity;
        var p_clickable = clickable;
        var p_message = message;
        var pg = [];
        var PolyG = new L.LayerGroup();
        for (var i = 0; i < polygons.length; i++) {
          pg = polygons[i];
          if (pg.coords) {
            if (pg.strokeColor) {
              if (! pg.strokeColor.match(/^#/)) {
                pg.strokeColor = '#' + pg.strokeColor;
              }
              p_strokeColor = pg.strokeColor;
            }
            if (pg.strokeOpacity) {
              p_strokeOpacity = pg.strokeOpacity;
            }
            if (pg.strokeWeight) {
              p_strokeWeight = pg.strokeWeight;
            }
            if (pg.fillColor) {
              if (! pg.fillColor.match(/^#/)) {
                pg.fillColor = '#' + pg.fillColor;
              }
              p_fillColor = pg.fillColor;
            }
            if (pg.fillOpacity) {
              p_fillOpacity = pg.fillOpacity;
            }
            if (pg.clickable) {
              p_clickable = pg.clickable;
            }
            if (pg.message) {
              p_message = pg.message;
            }
            p_clickable = (p_clickable ? true : false);
            var mcoords = [];
            var poly = [];
            scoords = pg.coords.split("|");
            for (var s = 0; s < scoords.length; s++) {
              var ll = scoords[s];
              var lla = ll.split(",");
              mcoords[s] = new L.LatLng(parseFloat(lla[0]), parseFloat(lla[1]));
            }
            if (mcoords.length > 2) {
              var polyOpts = {};
              polyOpts.color = p_strokeColor;
              polyOpts.opacity = p_strokeOpacity;
              polyOpts.weight = p_strokeWeight;
              polyOpts.fillColor = p_fillColor;
              polyOpts.fillOpacity = p_fillOpacity;
              polyOpts.clickable = p_clickable;
              poly[i] = new L.Polygon(mcoords, polyOpts);
              PolyG.addLayer(poly[i]);

              if (p_clickable && p_message) {
                poly[i].bindPopup(p_message);
              }
            }
          }
        }

        if (polygons.length) {
          PolyG.addTo(Drupal.getlocations_leaflet_map[key]);
          if (Drupal.getlocations_leaflet_settings[key].map_settings.layercontrol_polyg_ov) {
            Drupal.getlocations_leaflet_layerscontrol[key].addOverlay(PolyG, Drupal.getlocations_leaflet_settings[key].map_settings.layercontrol_polyg_ov_label);
          }
        }

      });
    }
  };
}(jQuery));
