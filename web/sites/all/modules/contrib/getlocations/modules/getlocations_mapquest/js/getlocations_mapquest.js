
/**
 * @file
 * getlocations_mapquest.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations_mapquest module for Drupal 7
 * this is for mapquest maps http://mapquest.com
 */

(function ($) {

  Drupal.getlocations_mapquest = {};
  Drupal.getlocations_mapquest.map = [];
  Drupal.getlocations_mapquest.markers = [];
  Drupal.getlocations_mapquest.settings = [];
  Drupal.getlocations_mapquest_data = [];

  Drupal.behaviors.getlocations_mapquest = {
    attach: function (context, settings) {

      // functions
      function getlocations_mapquest_do_link(m, l) {
        MQA.EventManager.addListener(m, 'click', function(evt){
          window.location = l;
        });
      }

      // show_maplinks
      function getlocations_mapquest_show_maplinks(key, glid, m, a, t) {
        $("div#getlocations_mapquest_map_links_" + key + " ul").append('<li><a href="#maptop_' + key + '" class="glid-' + glid + '">' + t + '</a></li>');
        $("div#getlocations_mapquest_map_links_" + key + " a.glid-" + glid).click(function() {
          $("div#getlocations_mapquest_map_links_" + key + " a").removeClass('active');
          $("div#getlocations_mapquest_map_links_" + key + " a.glid-" + glid).addClass('active');
          if (a.type == 'link') {
            // relocate
            window.location = a.data;
          }
          else if (a.type == 'popup') {
            m.toggleInfoWindow();
          }
        });
      }
      // end functions

      // work over all class 'getlocations_mapquest_canvas'
      $(".getlocations_mapquest_canvas", context).once('getlocations-mapquest-processed', function(index, element) {
        var elemID = $(element).attr('id');
        var key = elemID.replace(/^getlocations_mapquest_canvas_/, '');
        // is there really a map?
        if ( $("#getlocations_mapquest_canvas_" + key).is('div') && typeof(MQA) !== 'undefined' ) {

          var map_settings = settings.getlocations_mapquest[key].map_settings;
          var map_opts = settings.getlocations_mapquest[key].map_opts;

          var icons = Drupal.getlocations_mapquest_data[key].icons;
          var datanum = Drupal.getlocations_mapquest_data[key].datanum;
          var latlons = Drupal.getlocations_mapquest_data[key].latlons;
          var minmaxes = (Drupal.getlocations_mapquest_data[key].minmaxes ? Drupal.getlocations_mapquest_data[key].minmaxes : '');
          var minlat = '';
          var minlon = '';
          var maxlat = '';
          var maxlon = '';
          var cenlat = '';
          var cenlon = '';
          if (minmaxes) {
            var mmarr = minmaxes.split(',');
            minlat = parseFloat(mmarr[0]);
            minlon = parseFloat(mmarr[1]);
            maxlat = parseFloat(mmarr[2]);
            maxlon = parseFloat(mmarr[3]);
            cenlat = ((minlat + maxlat) / 2);
            cenlon = ((minlon + maxlon) / 2);
          }
          var latlong = map_opts['latlong'];
          var lla = latlong.split(',');
          var clat = parseFloat(lla[0]);
          var clon = parseFloat(lla[1]);
          var latlon = {lat:clat, lng:clon};
          if ( cenlat) {
            latlon = {lat:cenlat, lng:cenlon};
          }

          Drupal.getlocations_mapquest.markers[key] = {};
          Drupal.getlocations_mapquest.markers[key].coords = {};
          Drupal.getlocations_mapquest.markers[key].lids = {};
          Drupal.getlocations_mapquest.markers[key].cat = {};
          Drupal.getlocations_mapquest.settings[key] = settings.getlocations_mapquest[key];

          var mapopts = {
            elt: document.getElementById('getlocations_mapquest_canvas_' + key),
            latLng: latlon,
            zoom: parseInt(map_opts.zoom),
            mtype: map_opts.maps_default,
            bestFitMargin: parseInt(map_opts.bestfitmargin),
            zoomOnDoubleClick: (map_opts.doubleClickZoom ? true : false)
          };

          // get the map
          Drupal.getlocations_mapquest.map[key] = new MQA.TileMap(mapopts);

          if (map_settings.scrollWheelZoom) {
            MQA.withModule('mousewheel', function() {
              // enable zooming with your mouse
              Drupal.getlocations_mapquest.map[key].enableMouseWheelZoom();
            });
          }

          Drupal.getlocations_mapquest.map[key].setDraggable((map_settings.dragging ? true : false));

          // zoomControl none small large
          if (map_settings.zoomControl == 'small' || map_settings.zoomControl == 'large') {
            var zoomcontrolposition = MQA.MapCorner.TOP_LEFT;
            if (map_settings.zoomcontrolposition == 'topright') {
              zoomcontrolposition = MQA.MapCorner.TOP_RIGHT;
            }
            else if (map_settings.zoomcontrolposition == 'bottomright') {
              zoomcontrolposition = MQA.MapCorner.BOTTOM_RIGHT;
            }
            else if (map_settings.zoomcontrolposition == 'bottomleft') {
              zoomcontrolposition = MQA.MapCorner.BOTTOM_LEFT;
            }
            if (map_settings.zoomControl == 'small') {
              MQA.withModule('smallzoom', function() {
                // add the Small Zoom control map_settings.zoomcontrol_hset, map_settings.zoomcontrol_vset
                Drupal.getlocations_mapquest.map[key].addControl(
                  new MQA.SmallZoom(),
                  new MQA.MapCornerPlacement(zoomcontrolposition, new MQA.Size(map_settings.zoomcontrol_hset, map_settings.zoomcontrol_vset))
                );
              });
            }
            else if (map_settings.zoomControl == 'large') {
              //
              MQA.withModule('largezoom', function() {
                // add the Large Zoom control
                Drupal.getlocations_mapquest.map[key].addControl(
                  new MQA.LargeZoom(),
                  new MQA.MapCornerPlacement(zoomcontrolposition, new MQA.Size(map_settings.zoomcontrol_hset, map_settings.zoomcontrol_vset))
                );
              });
            }
          }

          // layerControl
          if (map_settings.layerControl) {
            var layercontrolposition = MQA.MapCorner.TOP_RIGHT;
            if (map_settings.layercontrolposition == 'topleft') {
              layercontrolposition = MQA.MapCorner.TOP_LEFT;
            }
            else if (map_settings.layercontrolposition == 'bottomright') {
              layercontrolposition = MQA.MapCorner.BOTTOM_RIGHT;
            }
            else if (map_settings.layercontrolposition == 'bottomleft') {
              layercontrolposition = MQA.MapCorner.BOTTOM_LEFT;
            }
            MQA.withModule('viewoptions', function() {
              Drupal.getlocations_mapquest.map[key].addControl(
                new MQA.ViewOptions(),
                new MQA.MapCornerPlacement(layercontrolposition, new MQA.Size(map_settings.layercontrol_hset, map_settings.layercontrol_vset))
              );
            });
          }

          // overview
          if (map_settings.overview) {
            var overviewcontrolposition = MQA.MapCorner.BOTTOM_RIGHT;
            if (map_settings.overviewcontrolposition == 'topright') {
              overviewcontrolposition = MQA.MapCorner.TOP_RIGHT;
            }
            else if (map_settings.overviewcontrolposition == 'topleft') {
              overviewcontrolposition = MQA.MapCorner.TOP_LEFT;
            }
            else if (map_settings.overviewcontrolposition == 'bottomleft') {
              overviewcontrolposition = MQA.MapCorner.BOTTOM_LEFT;
            }
            MQA.withModule('insetmapcontrol', function() {
              // Create the options object
              //  -set the size of the control; default is 150px in width and 125px in height
              //  -set the zoom differential; default is 3 zoom levels and can also be a negative value
              //  -set the mapType of the control; default is 'map'
              //  -set the starting view of the inset map; default is minimized
              var overview_options = {
                size: { width: map_settings.overview_hset, height: map_settings.overview_vset },
                zoom: parseInt(map_settings.overview_zoom),
                mapType: map_opts.maps_default,
                minimized: (map_settings.overview_opened ? true : false)
              };
              Drupal.getlocations_mapquest.map[key].addControl(
                new MQA.InsetMapControl(overview_options),
                new MQA.MapCornerPlacement(overviewcontrolposition)
              );
            });
          }

          // trafficControl
          if (map_settings.trafficControl) {
            var trafficcontrolposition = MQA.MapCorner.TOP_LEFT;
            if (map_settings.trafficcontrolposition == 'topright') {
              trafficcontrolposition = MQA.MapCorner.TOP_RIGHT;
            }
            else if (map_settings.trafficcontrolposition == 'bottomright') {
              trafficcontrolposition = MQA.MapCorner.BOTTOM_RIGHT;
            }
            else if (map_settings.trafficcontrolposition == 'bottomleft') {
              trafficcontrolposition = MQA.MapCorner.BOTTOM_LEFT;
            }
            MQA.withModule('traffictoggle', function() {
              Drupal.getlocations_mapquest.map[key].addControl(
                new MQA.TrafficToggle(),
                new MQA.MapCornerPlacement(trafficcontrolposition, new MQA.Size(map_settings.trafficcontrol_hset, map_settings.trafficcontrol_vset))
              );
            });
          }

          // drawingControl
          if (map_settings.drawingControl) {
            var drawingcontrolposition = MQA.MapCorner.TOP_RIGHT;
            if (map_settings.drawingcontrolposition == 'topleft') {
              drawingcontrolposition = MQA.MapCorner.TOP_LEFT;
            }
            else if (map_settings.drawingcontrolposition == 'bottomright') {
              drawingcontrolposition = MQA.MapCorner.BOTTOM_RIGHT;
            }
            else if (map_settings.drawingcontrolposition == 'bottomleft') {
              drawingcontrolposition = MQA.MapCorner.BOTTOM_LEFT;
            }
            MQA.withModule('shapedrawingcontrol', function() {
              Drupal.getlocations_mapquest.map[key].addControl(
                new MQA.ShapeDrawingControl({
                  color: '#000000',
                  colorAlpha: 0.5,
                  fillColor: '#000000',
                  fillColorAlpha: 0.5,
                  borderWidth: 2
                }),
                new MQA.MapCornerPlacement(drawingcontrolposition, new MQA.Size(map_settings.drawingcontrol_hset, map_settings.drawingcontrol_vset))
              )
            });
          }

          // geolocationControl
          if (map_settings.geolocationControl) {
            var geolocationcontrolposition = MQA.MapCorner.TOP_LEFT;
            if (map_settings.geolocationcontrolposition == 'topright') {
              geolocationcontrolposition = MQA.MapCorner.TOP_RIGHT;
            }
            else if (map_settings.geolocationcontrolposition == 'bottomright') {
              geolocationcontrolposition = MQA.MapCorner.BOTTOM_RIGHT;
            }
            else if (map_settings.geolocationcontrolposition == 'bottomleft') {
              geolocationcontrolposition = MQA.MapCorner.BOTTOM_LEFT;
            }
            MQA.withModule('geolocationcontrol', function() {
              Drupal.getlocations_mapquest.map[key].addControl(
                new MQA.GeolocationControl(),
                new MQA.MapCornerPlacement(geolocationcontrolposition, new MQA.Size(map_settings.geolocationcontrol_hset, map_settings.geolocationcontrol_vset))
              )
            });
          }

          // latlons data
          if (datanum > 0) {

            // categories
            var categories = {};
            if (map_settings.category_showhide_buttons) {
              categories = (map_settings.categories ? map_settings.categories : {});
            }

            var Marr = [];
            var Markers = {};

            // loop over latlons
            for (var i = 0; i < latlons.length; i++) {
              var latlon = latlons[i];
              var lat           = latlon[0];
              var lon           = latlon[1];
              var entity_key    = latlon[2];
              var entity_id     = latlon[3];
              var glid          = latlon[4];
              var title         = latlon[5];
              var markername    = latlon[6];
              var x             = latlon[7];
              var markeraction  = latlon[8];
              var cat           = latlon[9];
              var icon = '';
              if (markername) {
                icon = icons[markername];
              }

              // get the marker
              var Marker = Drupal.getlocations_mapquest.makeMarker(map_settings, lat, lon, entity_key, entity_id, glid, title, icon, markeraction, cat, key);

              // show_maplinks
              if (markeraction && markeraction.type && markeraction.data) {
                if (title && map_settings.show_maplinks) {
                  getlocations_mapquest_show_maplinks(key, glid, Marker, markeraction, title);
                }
              }

              // add marker to getlocations_leaflet_markers
              // still experimental
              Drupal.getlocations_mapquest.markers[key].lids[glid] = Marker;

              // push the marker
              Marr.push(Marker);

            }

            // add markers to a collection
            MQA.withModule('shapes', function() {
              Markers = new MQA.ShapeCollection();
              for (var c = 0; c < Marr.length; c++) {
                Markers.add(Marr[c]);
              }
              Drupal.getlocations_mapquest.map[key].addShapeCollection(Markers);
              Drupal.getlocations_mapquest.map[key].bestFit();
            });

          }
          else {
            Drupal.getlocations_mapquest.redoMap(key);
          }

          // field_group support
          if (map_settings.field_group_enable) {
            // field group multipage support
            if ($(".multipage-link-next,.multipage-link-previous").is('input')) {
              $(".multipage-link-next,.multipage-link-previous").one('click', function(event) {
                Drupal.getlocations_mapquest.redoMap(key);
              });
            }
            // field group vert and horiz tabs
            if ($(".vertical-tabs-list,.horizontal-tabs-list").is('ul')) {
              $("li.vertical-tab-button a, li.horizontal-tab-button a").bind('click', function(event) {
                Drupal.getlocations_mapquest.redoMap(key);
              });
            }
            // field group accordion
            if ($(".field-group-accordion").is('div')) {
              $(".accordion-item").bind('click', function(event) {
                Drupal.getlocations_mapquest.redoMap(key);
              });
            }
          }


        } // end is there really a map?
      }); // end once

    } // end attach
  }; // end behaviors


  // external functions
  Drupal.getlocations_mapquest.makeMarker = function(gs, lat, lon, entity_key, entity_id, glid, title, icon, markeraction, cat, mkey) {

    // categories
    if (cat) {
      Drupal.getlocations_mapquest.markers[mkey].cat[glid] = cat;
    }

    // check for duplicates
    var hash = new String(lat + lon);
    if (Drupal.getlocations_mapquest.markers[mkey].coords[hash] == null) {
      Drupal.getlocations_mapquest.markers[mkey].coords[hash] = 1;
    }
    else {
      // we have a duplicate
      // 10000 constrains the max, 0.0001 constrains the min distance
      m1 = (Math.random() /10000) + 0.0001;
      // randomise the operator
      m2 = Math.random();
      if (m2 > 0.5) {
        lat = parseFloat(lat) + m1;
      }
      else {
        lat = parseFloat(lat) - m1;
      }
      m1 = (Math.random() /10000) + 0.0001;
      m2 = Math.random();
      if (m2 > 0.5) {
        lon = parseFloat(lon) + m1;
      }
      else {
        lon = parseFloat(lon) - m1;
      }
    }

    var latLng = {lat: lat, lng: lon};
    var Marker = new MQA.Poi(latLng);
    Marker.setIcon( new MQA.Icon(icon.iconUrl, parseInt(icon.iconSize.x, 10), parseInt(icon.iconSize.y, 10)));
    if (icon.shadowUrl) {
      Marker.setShadow(new MQA.Icon(icon.shadowUrl, parseInt(icon.shadowSize.x, 10), parseInt(icon.shadowSize.y, 10)));
      if (icon.shadowAnchor) {
        Marker.setShadowOffset({ x: 0, y: parseInt('-' + icon.shadowAnchor.y)});
      }
    }
    else {
      Marker.setShadow('', 0, 0);
    }

    if (title) {
      Marker.setRolloverContent(title);
    }

    // markeraction
    if (markeraction && markeraction.type && markeraction.data) {
      if (markeraction.type == 'popup') {
        Marker.setInfoContentHTML(markeraction.data);
      }
      else if (markeraction.type == 'link') {
        MQA.EventManager.addListener(Marker, 'click', function(evt){
          window.location = markeraction.data;
        });
      }
    }

    return Marker;
  };

  // redo map
  Drupal.getlocations_mapquest.redoMap = function(key) {
    if (Drupal.getlocations_mapquest_data[key].datanum > 1) {
      var map_opts = Drupal.settings.getlocations_mapquest[key].map_opts;
      var minmaxes = (Drupal.getlocations_mapquest_data[key].minmaxes ? Drupal.getlocations_mapquest_data[key].minmaxes : '');
      var minlat = '';
      var minlon = '';
      var maxlat = '';
      var maxlon = '';
      var cenlat = '';
      var cenlon = '';
      var sw     = '';
      var ne     = '';
      if (minmaxes) {
        var mmarr = minmaxes.split(',');
        minlat = parseFloat(mmarr[0]);
        minlon = parseFloat(mmarr[1]);
        maxlat = parseFloat(mmarr[2]);
        maxlon = parseFloat(mmarr[3]);
        cenlat = ((minlat + maxlat) / 2);
        cenlon = ((minlon + maxlon) / 2);
        sw = new MQA.LatLng(parseFloat(mmarr[2]), parseFloat(mmarr[3]));
        ne = new MQA.LatLng(parseFloat(mmarr[0]), parseFloat(mmarr[1]))
      }
      var latlong = map_opts['latlong'];
      var lla = latlong.split(',');
      var clat = parseFloat(lla[0]);
      var clon = parseFloat(lla[1]);
      if ( cenlat) {
        var latlon = new MQA.LatLng(cenlat, cenlon);
      }
      else {
        var latlon = new MQA.LatLng(clat, clon);
      }
      if (sw) {
        var rect = new MQA.RectLL(ne, sw);
        Drupal.getlocations_mapquest.map[key].zoomToRect(rect, false, 1, 20);
      }
      else {
        var z = Drupal.settings.getlocations_mapquest[key].map_opts.zoom;
        Drupal.getlocations_mapquest.map[key].setCenter(latlon, z);
      }
    }

  };

})(jQuery);
