
/**
 * @file
 * getlocations.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations module for Drupal 7
 * this is for googlemaps API version 3
*/

(function ($) {

  Drupal.getlocations_inputmap = [];
  Drupal.getlocations_pano = [];
  Drupal.getlocations_data = [];
  Drupal.getlocations_markers = [];
  Drupal.getlocations_settings = [];
  Drupal.getlocations_map = [];

  // in icons.js
  Drupal.getlocations.iconSetup();

  Drupal.behaviors.getlocations = {
    attach: function(context, settings) {

      // work over all class 'getlocations_map_canvas'
      $(".getlocations_map_canvas", context).once('getlocations-map-processed', function(index, element) {
        var elemID = $(element).attr('id');
        var key = elemID.replace(/^getlocations_map_canvas_/, '');
        // is there really a map?
        if ( $("#getlocations_map_canvas_" + key).is('div') ) {

          // defaults
          var global_settings = {
            maxzoom: 16,
            minzoom: 7,
            nodezoom: 12,
            minzoom_map: -1,
            maxzoom_map: -1,
            mgr: '',
            cmgr: '',
            cmgr_gridSize: null,
            cmgr_maxZoom: null,
            cmgr_minClusterSize: null,
            cmgr_styles: '',
            cmgr_style: null,
            defaultIcon: '',
            useInfoBubble: false,
            useInfoWindow: false,
            useCustomContent: false,
            useLink: false,
            markeraction: 0,
            markeractiontype: 1,
            show_maplinks: false,
            show_bubble_on_one_marker: false,
            infoBubbles: [],
            datanum: 0,
            batchr: []
          };

          var setting = settings.getlocations[key];
          var lat = parseFloat(setting.lat);
          var lng = parseFloat(setting.lng);

          var selzoom = parseInt(setting.zoom);
          var controltype = setting.controltype;
          var pancontrol = setting.pancontrol;
          var scale = setting.scale;
          var overview = setting.overview;
          var overview_opened = setting.overview_opened;
          var sv_show = setting.sv_show;
          var scrollw = setting.scrollwheel;
          var maptype = (setting.maptype ? setting.maptype : '');
          var baselayers = (setting.baselayers ? setting.baselayers : '');
          var map_marker = setting.map_marker;
          var poi_show = setting.poi_show;
          var transit_show = setting.transit_show;
          var pansetting = setting.pansetting;
          var draggable = setting.draggable;
          var map_styles = setting.styles;
          var map_backgroundcolor = setting.map_backgroundcolor;
          var fullscreen = (setting.fullscreen ? true : false);
          if (setting.is_mobile && setting.fullscreen_disable) {
            fullscreen = false;
          }
          var js_path = setting.js_path;
          var useOpenStreetMap = false;
          var nokeyboard = (setting.nokeyboard ? true : false);
          var nodoubleclickzoom = (setting.nodoubleclickzoom ? true : false);
          var pancontrolposition = setting.pancontrolposition;
          var mapcontrolposition = setting.mapcontrolposition;
          var zoomcontrolposition = setting.zoomcontrolposition;
          var scalecontrolposition = setting.scalecontrolposition;
          var svcontrolposition = setting.svcontrolposition;
          var fullscreen_controlposition = setting.fullscreen_controlposition;

          global_settings.info_path = setting.info_path;
          global_settings.lidinfo_path = setting.lidinfo_path;
          global_settings.preload_data = setting.preload_data;
          if (setting.preload_data) {
            global_settings.getlocations_info = Drupal.settings.getlocations_info[key];
          }
          global_settings.getdirections_link = setting.getdirections_link;

          Drupal.getlocations_markers[key] = {};
          Drupal.getlocations_markers[key].coords = {};
          Drupal.getlocations_markers[key].lids = {};
          Drupal.getlocations_markers[key].cat = {};

          global_settings.locale_prefix = (setting.locale_prefix ? setting.locale_prefix + "/" : "");
          global_settings.show_bubble_on_one_marker = (setting.show_bubble_on_one_marker ? true : false);
          global_settings.minzoom = parseInt(setting.minzoom);
          global_settings.maxzoom = parseInt(setting.maxzoom);
          global_settings.nodezoom = parseInt(setting.nodezoom);

          // highlighting
          if (setting.highlight_enable) {
            global_settings.highlight_enable = setting.highlight_enable;
            global_settings.highlight_strokecolor = setting.highlight_strokecolor;
            global_settings.highlight_strokeopacity = setting.highlight_strokeopacity;
            global_settings.highlight_strokeweight = setting.highlight_strokeweight;
            global_settings.highlight_fillcolor = setting.highlight_fillcolor;
            global_settings.highlight_fillopacity = setting.highlight_fillopacity;
            global_settings.highlight_radius = setting.highlight_radius;
          }

          if (setting.minzoom_map == -1) {
            global_settings.minzoom_map = null;
          }
          else {
            global_settings.minzoom_map = parseInt(setting.minzoom_map);
          }
          if (setting.maxzoom_map == -1) {
            global_settings.maxzoom_map = null;
          }
          else {
            global_settings.maxzoom_map = parseInt(setting.maxzoom_map);
          }

          global_settings.datanum = Drupal.getlocations_data[key].datanum;

          global_settings.markermanagertype = setting.markermanagertype;
          global_settings.pansetting = setting.pansetting;
          // mobiles
          global_settings.is_mobile = setting.is_mobile;
          global_settings.show_maplinks = setting.show_maplinks;
          global_settings.show_search_distance = setting.show_search_distance;

          // streetview overlay settings
          global_settings.sv_showfirst              = (setting.sv_showfirst ? true : false);
          global_settings.sv_heading                = setting.sv_heading;
          global_settings.sv_zoom                   = setting.sv_zoom;
          global_settings.sv_pitch                  = setting.sv_pitch;
          global_settings.sv_addresscontrol         = (setting.sv_addresscontrol ? true : false);
          global_settings.sv_addresscontrolposition = setting.sv_addresscontrolposition;
          global_settings.sv_pancontrol             = (setting.sv_pancontrol ? true : false);
          global_settings.sv_pancontrolposition     = setting.sv_pancontrolposition;
          global_settings.sv_zoomcontrol            = setting.sv_zoomcontrol;
          global_settings.sv_zoomcontrolposition    = setting.sv_zoomcontrolposition;
          global_settings.sv_linkscontrol           = (setting.sv_linkscontrol ? true : false);
          global_settings.sv_imagedatecontrol       = (setting.sv_imagedatecontrol ? true : false);
          global_settings.sv_scrollwheel            = (setting.sv_scrollwheel ? true : false);
          global_settings.sv_clicktogo              = (setting.sv_clicktogo ? true : false);

          // prevent old msie from running markermanager
          var ver = Drupal.getlocations.msiedetect();
          var pushit = false;
          if ( (ver == '') || (ver && ver > 8)) {
            pushit = true;
          }

          if (pushit && setting.markermanagertype == 1 && setting.usemarkermanager) {
            global_settings.usemarkermanager = true;
            global_settings.useclustermanager = false;
          }
          else if (pushit && setting.markermanagertype == 2 && setting.useclustermanager == 1) {
            global_settings.cmgr_styles = Drupal.settings.getlocations_markerclusterer;
            global_settings.cmgr_style = (setting.markerclusterer_style == -1 ? null : setting.markerclusterer_style);
            global_settings.cmgr_gridSize = (setting.markerclusterer_size == -1 ? null : parseInt(setting.markerclusterer_size));
            global_settings.cmgr_maxZoom = (setting.markerclusterer_zoom == -1 ? null : parseInt(setting.markerclusterer_zoom));
            global_settings.cmgr_minClusterSize = (setting.markerclusterer_minsize == -1 ? null : parseInt(setting.markerclusterer_minsize));
            global_settings.cmgr_title = setting.markerclusterer_title;
            global_settings.cmgr_imgpath = setting.markerclusterer_imgpath;
            global_settings.useclustermanager = true;
            global_settings.usemarkermanager = false;
          }
          else {
            global_settings.usemarkermanager = false;
            global_settings.useclustermanager = false;
          }

          global_settings.markeraction = setting.markeraction;
          global_settings.markeractiontype = 'click';
          if (setting.markeractiontype == 2) {
            global_settings.markeractiontype = 'mouseover';
          }

          if (global_settings.markeraction == 1) {
            global_settings.useInfoWindow = true;
          }

          else if (global_settings.markeraction == 2) {
            global_settings.useInfoBubble = true;
          }
          else if (global_settings.markeraction == 3) {
            global_settings.useLink = true;
          }

          if((global_settings.useInfoWindow || global_settings.useInfoBubble) && setting.custom_content_enable == 1) {
            global_settings.useCustomContent = true;
          }
          global_settings.defaultIcon = Drupal.getlocations.getIcon(map_marker);

          // each map has its own data so when a map is replaced by ajax the new data is too.
          global_settings.latlons = (Drupal.getlocations_data[key].latlons ? Drupal.getlocations_data[key].latlons : '');

          // map type
          var maptypes = [];
          if (maptype) {
            if (maptype == 'Map' && baselayers.Map) { maptype = google.maps.MapTypeId.ROADMAP; }
            else if (maptype == 'Satellite' && baselayers.Satellite) { maptype = google.maps.MapTypeId.SATELLITE; }
            else if (maptype == 'Hybrid' && baselayers.Hybrid) { maptype = google.maps.MapTypeId.HYBRID; }
            else if (maptype == 'Physical' && baselayers.Physical) { maptype = google.maps.MapTypeId.TERRAIN; }

            if (baselayers.Map) { maptypes.push(google.maps.MapTypeId.ROADMAP); }
            if (baselayers.Satellite) { maptypes.push(google.maps.MapTypeId.SATELLITE); }
            if (baselayers.Hybrid) { maptypes.push(google.maps.MapTypeId.HYBRID); }
            if (baselayers.Physical) { maptypes.push(google.maps.MapTypeId.TERRAIN); }

            var copyrightNode = document.createElement('div');
            copyrightNode.id = 'copyright-control';
            copyrightNode.style.fontSize = '11px';
            copyrightNode.style.fontFamily = 'Arial, sans-serif';
            copyrightNode.style.margin = '0 2px 2px 0';
            copyrightNode.style.whiteSpace = 'nowrap';

            var baselayer_keys = new Array();
            for(var bl_key in baselayers) {
              baselayer_keys[baselayer_keys.length] = bl_key;
            }
            for (var c = 0; c < baselayer_keys.length; c++) {
              var bl_key = baselayer_keys[c];
              if ( bl_key != 'Map' && bl_key != 'Satellite' && bl_key != 'Hybrid' && bl_key != 'Physical') {
                // do stuff
                if (baselayers[bl_key]) {
                  maptypes.push(bl_key);
                  useOpenStreetMap = true;
                }
              }
            }
          }
          else {
            maptype = google.maps.MapTypeId.ROADMAP;
            maptypes.push(google.maps.MapTypeId.ROADMAP);
            maptypes.push(google.maps.MapTypeId.SATELLITE);
            maptypes.push(google.maps.MapTypeId.HYBRID);
            maptypes.push(google.maps.MapTypeId.TERRAIN);
          }
          // map styling
          var styles_array = [];
          if (map_styles) {
            try {
              styles_array = eval(map_styles);
            } catch (e) {
              if (e instanceof SyntaxError) {
                console.log(e.message);
                // Error on parsing string. Using default.
                styles_array = [];
              }
            }
          }

          // Merge styles with our settings.
          var styles = styles_array.concat([
            { featureType: "poi", elementType: "labels", stylers: [{ visibility: (poi_show ? 'on' : 'off') }] },
            { featureType: "transit", elementType: "labels", stylers: [{ visibility: (transit_show ? 'on' : 'off') }] }
          ]);

          var controlpositions = [];
          controlpositions['tl'] = google.maps.ControlPosition.TOP_LEFT;
          controlpositions['tc'] = google.maps.ControlPosition.TOP_CENTER;
          controlpositions['tr'] = google.maps.ControlPosition.TOP_RIGHT;
          controlpositions['rt'] = google.maps.ControlPosition.RIGHT_TOP;
          controlpositions['rc'] = google.maps.ControlPosition.RIGHT_CENTER;
          controlpositions['rb'] = google.maps.ControlPosition.RIGHT_BOTTOM;
          controlpositions['br'] = google.maps.ControlPosition.BOTTOM_RIGHT;
          controlpositions['bc'] = google.maps.ControlPosition.BOTTOM_CENTER;
          controlpositions['bl'] = google.maps.ControlPosition.BOTTOM_LEFT;
          controlpositions['lb'] = google.maps.ControlPosition.LEFT_BOTTOM;
          controlpositions['lc'] = google.maps.ControlPosition.LEFT_CENTER;
          controlpositions['lt'] = google.maps.ControlPosition.LEFT_TOP;
          global_settings.controlpositions = controlpositions;

          var mapOpts = {
            zoom: selzoom,
            minZoom: global_settings.minzoom_map,
            maxZoom: global_settings.maxzoom_map,
            center: new google.maps.LatLng(lat, lng),
            mapTypeId: maptype,
            scrollwheel: (scrollw ? true : false),
            draggable: (draggable ? true : false),
            styles: styles,
            overviewMapControl: (overview ? true : false),
            overviewMapControlOptions: {opened: (overview_opened ? true : false)},
            keyboardShortcuts: (nokeyboard ? false : true),
            disableDoubleClickZoom: nodoubleclickzoom
          };
          if (map_backgroundcolor) {
            mapOpts.backgroundColor = map_backgroundcolor;
          }
          // zoom control
          if (controltype == 'none') {
            mapOpts.zoomControl = false;
          }
          else {
            mapOpts.zoomControl = true;
            var zco = {};
            if (zoomcontrolposition) {
              zco.position = controlpositions[zoomcontrolposition];
            }
            if (controltype == 'small') {
              zco.style = google.maps.ZoomControlStyle.SMALL;
            }
            else if (controltype == 'large') {
              zco.style = google.maps.ZoomControlStyle.LARGE;
            }
            if (zco) {
              mapOpts.zoomControlOptions = zco;
            }
          }

          // pancontrol
          if (pancontrol) {
            mapOpts.panControl = true;
            if (pancontrolposition) {
              mapOpts.panControlOptions = {position: controlpositions[pancontrolposition]};
            }
          }
          else {
            mapOpts.panControl = false;
          }

          // map control
          if (setting.mtc == 'none') {
            mapOpts.mapTypeControl = false;
          }
          else {
            mapOpts.mapTypeControl = true;
            var mco = {};
            mco.mapTypeIds = maptypes;
            if (setting.mtc == 'standard') {
              mco.style = google.maps.MapTypeControlStyle.HORIZONTAL_BAR;
            }
            else if (setting.mtc == 'menu') {
              mco.style = google.maps.MapTypeControlStyle.DROPDOWN_MENU;
            }
            if (mapcontrolposition) {
              mco.position = controlpositions[mapcontrolposition];
            }
            mapOpts.mapTypeControlOptions = mco;
          }

          // scale control
          if (scale) {
            mapOpts.scaleControl = true;
            if (scalecontrolposition) {
              mapOpts.ScaleControlOptions = {position: controlpositions[scalecontrolposition]};
            }
          }
          else {
            mapOpts.scaleControl = false;
          }

          // pegman
          if (sv_show) {
            mapOpts.streetViewControl = true;
            if (svcontrolposition) {
              mapOpts.StreetViewControlOptions = {position: controlpositions[svcontrolposition]};
            }
          }
          else {
            mapOpts.streetViewControl = false;
          }

          // make the map
          Drupal.getlocations_map[key] = new google.maps.Map(document.getElementById("getlocations_map_canvas_" + key), mapOpts);
          // another way
          // Drupal.getlocations_map[key] = new google.maps.Map($(element).get(0), mapOpts);

          // other maps
          // OpenStreetMap
          if (useOpenStreetMap) {
            for (var c = 0; c < baselayer_keys.length; c++) {
              var bl_key = baselayer_keys[c];
              if ( bl_key != 'Map' && bl_key != 'Satellite' && bl_key != 'Hybrid' && bl_key != 'Physical') {
                if (baselayers[bl_key] ) {
                  setupNewMap(key, bl_key);
                }
              }
            }
            google.maps.event.addListener(Drupal.getlocations_map[key], 'maptypeid_changed', updateAttribs);
            Drupal.getlocations_map[key].controls[google.maps.ControlPosition.BOTTOM_RIGHT].push(copyrightNode);
          }

          // input map
          if (setting.inputmap) {
            Drupal.getlocations_inputmap[key] = Drupal.getlocations_map[key];
          }

          // set up markermanager
          if (global_settings.usemarkermanager) {
            global_settings.mgr = new MarkerManager(Drupal.getlocations_map[key], {
              borderPadding: 50,
              maxZoom: global_settings.maxzoom,
              trackMarkers: false
            });
          }
          else if (global_settings.useclustermanager) {
            var cmgr_settings = {
              gridSize: global_settings.cmgr_gridSize,
              maxZoom: global_settings.cmgr_maxZoom,
              styles: global_settings.cmgr_styles[global_settings.cmgr_style],
              minimumClusterSize: global_settings.cmgr_minClusterSize,
              title: global_settings.cmgr_title
            };
            if (global_settings.cmgr_imgpath) {
              cmgr_settings.imagePath = global_settings.cmgr_imgpath + '/m';
            }
            global_settings.cmgr = new MarkerClusterer(
              Drupal.getlocations_map[key],
              [],
              cmgr_settings
            );
          }

          // KML
          if (setting.kml_url) {
            var kmlLayer = {};
            var kmlLayertoggleState = [];
            kmlLayer[key] = new google.maps.KmlLayer({
              url: setting.kml_url,
              preserveViewport: (setting.kml_url_viewport ? true : false),
              clickable: (setting.kml_url_click ? true : false),
              suppressInfoWindows: (setting.kml_url_infowindow ? true : false)
            });
            if (setting.kml_url_button_state > 0) {
              kmlLayer[key].setMap(Drupal.getlocations_map[key]);
              kmlLayertoggleState[key] = true;
            }
            else {
              kmlLayer[key].setMap(null);
              kmlLayertoggleState[key] = false;
            }
            $("#getlocations_toggleKmlLayer_" + key).click( function() {
              var label = '';
              l = (setting.kml_url_button_label ? setting.kml_url_button_label : Drupal.t('Kml Layer'));
              if (kmlLayertoggleState[key]) {
                kmlLayer[key].setMap(null);
                kmlLayertoggleState[key] = false;
                label = l + ' ' + Drupal.t('On');
              }
              else {
                kmlLayer[key].setMap(Drupal.getlocations_map[key]);
                kmlLayertoggleState[key] = true;
                label = l + ' ' + Drupal.t('Off');
              }
              $(this).val(label);
            });
          }

          // Traffic Layer
          if (setting.trafficinfo) {
            var trafficInfo = {};
            var traffictoggleState = [];
            trafficInfo[key] = new google.maps.TrafficLayer();
            if (setting.trafficinfo_state > 0) {
              trafficInfo[key].setMap(Drupal.getlocations_map[key]);
              traffictoggleState[key] = true;
            }
            else {
              trafficInfo[key].setMap(null);
              traffictoggleState[key] = false;
            }
            $("#getlocations_toggleTraffic_" + key).click( function() {
              var label = '';
              if (traffictoggleState[key]) {
                trafficInfo[key].setMap(null);
                traffictoggleState[key] = false;
                label = Drupal.t('Traffic Info On');
              }
              else {
                trafficInfo[key].setMap(Drupal.getlocations_map[key]);
                traffictoggleState[key] = true;
                label = Drupal.t('Traffic Info Off');
              }
              $(this).val(label);
            });
          }

          // Bicycling Layer
          if (setting.bicycleinfo) {
            var bicycleInfo = {};
            var bicycletoggleState =  [];
            bicycleInfo[key] = new google.maps.BicyclingLayer();
            if (setting.bicycleinfo_state > 0) {
              bicycleInfo[key].setMap(Drupal.getlocations_map[key]);
              bicycletoggleState[key] = true;
            }
            else {
              bicycleInfo[key].setMap(null);
              bicycletoggleState[key] = false;
            }
            $("#getlocations_toggleBicycle_" + key).click( function() {
              var label = '';
              if (bicycletoggleState[key]) {
                bicycleInfo[key].setMap(null);
                bicycletoggleState[key] = false;
                label = Drupal.t('Bicycle Info On');
              }
              else {
                bicycleInfo[key].setMap(Drupal.getlocations_map[key]);
                bicycletoggleState[key] = true;
                label = Drupal.t('Bicycle Info Off');
              }
              $(this).val(label);
            });
          }

          // Transit Layer
          if (setting.transitinfo) {
            var transitInfo = {};
            var transittoggleState = [];
            transitInfo[key] = new google.maps.TransitLayer();
            if (setting.transitinfo_state > 0) {
              transitInfo[key].setMap(Drupal.getlocations_map[key]);
              transittoggleState[key] = true;
            }
            else {
              transitInfo[key].setMap(null);
              transittoggleState[key] = false;
            }
            $("#getlocations_toggleTransit_" + key).click( function() {
              var label = '';
              if (transittoggleState[key]) {
                transitInfo[key].setMap(null);
                transittoggleState[key] = false;
                label = Drupal.t('Transit Info On');
              }
              else {
                transitInfo[key].setMap(Drupal.getlocations_map[key]);
                transittoggleState[key] = true;
                label = Drupal.t('Transit Info Off');
              }
              $(this).val(label);
            });
          }

          // Panoramio Layer
          if (setting.panoramio_use && setting.panoramio_show) {
            var panoramioLayer = {};
            var panoramiotoggleState = [];
            panoramioLayer[key] = new google.maps.panoramio.PanoramioLayer();
            if (setting.panoramio_state > 0) {
              panoramioLayer[key].setMap(Drupal.getlocations_map[key]);
              panoramiotoggleState[key] = true;
            }
            else {
              panoramioLayer[key].setMap(null);
              panoramiotoggleState[key] = false;
            }
            $("#getlocations_togglePanoramio_" + key).click( function() {
              var label = '';
              if (panoramiotoggleState[key]) {
                panoramioLayer[key].setMap(null);
                panoramiotoggleState[key] = false;
                label = Drupal.t('Panoramio On');
              }
              else {
                panoramioLayer[key].setMap(Drupal.getlocations_map[key]);
                panoramiotoggleState[key] = true;
                label = Drupal.t('Panoramio Off');
              }
              $(this).val(label);
            });
          }

          // Weather Layer
          if (setting.weather_use) {
            if (setting.weather_show) {
              var weatherLayer = {};
              var weathertoggleState = {};
              tu = google.maps.weather.TemperatureUnit.CELSIUS;
              if (setting.weather_temp == 2) {
                tu = google.maps.weather.TemperatureUnit.FAHRENHEIT;
              }
              sp = google.maps.weather.WindSpeedUnit.KILOMETERS_PER_HOUR;
              if (setting.weather_speed == 2) {
                sp = google.maps.weather.WindSpeedUnit.METERS_PER_SECOND;
              }
              else if (setting.weather_speed == 3) {
                sp = google.maps.weather.WindSpeedUnit.MILES_PER_HOUR;
              }
              var weatherOpts =  {
                temperatureUnits: tu,
                windSpeedUnits: sp,
                clickable: (setting.weather_clickable ? true : false),
                suppressInfoWindows: (setting.weather_info ? false : true)
              };
              if (setting.weather_label > 0) {
                weatherOpts.labelColor = google.maps.weather.LabelColor.BLACK;
                if (setting.weather_label == 2) {
                  weatherOpts.labelColor = google.maps.weather.LabelColor.WHITE;
                }
              }
              weatherLayer[key] = new google.maps.weather.WeatherLayer(weatherOpts);
              if (setting.weather_state > 0) {
                weatherLayer[key].setMap(Drupal.getlocations_map[key]);
                weathertoggleState[key] = true;
              }
              else {
                weatherLayer[key].setMap(null);
                weathertoggleState[key] = false;
              }
              $("#getlocations_toggleWeather_" + key).click( function() {
                var label = '';
                if (weathertoggleState[key]) {
                  weatherLayer[key].setMap(null);
                  weathertoggleState[key] = false;
                  label = Drupal.t('Weather On');
                }
                else {
                  weatherLayer[key].setMap(Drupal.getlocations_map[key]);
                  weathertoggleState[key] = true;
                  label = Drupal.t('Weather Off');
                }
                $(this).val(label);
              });
            }
            if (setting.weather_cloud) {
              var cloudLayer = {};
              var cloudtoggleState = [];
              cloudLayer[key] = new google.maps.weather.CloudLayer();
              if (setting.weather_cloud_state > 0) {
                cloudLayer[key].setMap(Drupal.getlocations_map[key]);
                cloudtoggleState[key] = true;
              }
              else {
                cloudLayer[key].setMap(null);
                cloudtoggleState[key] = false;
              }
              $("#getlocations_toggleCloud_" + key).click( function() {
                var label = '';
                if (cloudtoggleState[key] == 1) {
                  cloudLayer[key].setMap(null);
                  cloudtoggleState[key] = false;
                  label = Drupal.t('Clouds On');
                }
                else {
                  cloudLayer[key].setMap(Drupal.getlocations_map[key]);
                  cloudtoggleState[key] = true;
                  label = Drupal.t('Clouds Off');
                }
                $(this).val(label);
              });
            }
          }

          // exporting global_settings to Drupal.getlocations_settings
          Drupal.getlocations_settings[key] = global_settings;

          // markers and bounding
          if (! setting.inputmap && ! setting.extcontrol) {
            //setTimeout(function() { doAllMarkers(Drupal.getlocations_map[key], global_settings, key) }, 300);
            doAllMarkers(Drupal.getlocations_map[key], global_settings, key);

            // Bounding
            Drupal.getlocations.redoMap(key);

          }

          // fullscreen
          if (fullscreen) {
            var fsdiv = '';
            $(document).keydown( function(kc) {
              var cd = (kc.keyCode ? kc.keyCode : kc.which);
              if(cd == 27){
                if($("body").hasClass("fullscreen-body-" + key)){
                  toggleFullScreen();
                }
              }
            });
            var fsdoc = document.createElement("DIV");
            var fs = new FullScreenControl(fsdoc);
            fsdoc.index = 0;
            var fs_p = controlpositions['tr'];
            if (fullscreen_controlposition) {
              var fs_p = controlpositions[fullscreen_controlposition];
            }
            Drupal.getlocations_map[key].controls[fs_p].setAt(0, fsdoc);
          }

          // search_places in getlocations_search_places.js
          if (setting.search_places && $.isFunction(Drupal.getlocations_search_places)) {
            Drupal.getlocations_search_places(key);
          }

          //geojson in getlocations_geojson.js
          if (setting.geojson_enable && setting.geojson_data && $.isFunction(Drupal.getlocations_geojson)) {
            Drupal.getlocations_geojson(key);
          }

        } // end is there really a map?

        // functions
        function FullScreenControl(fsd) {
          fsd.style.margin = "5px";
          fsd.style.boxShadow = "0 2px 4px rgba(0, 0, 0, 0.4)";
          fsdiv = document.createElement("DIV");
          fsdiv.style.height = "22px";
          fsdiv.style.backgroundColor = "white";
          fsdiv.style.borderColor = "#717B87";
          fsdiv.style.borderStyle = "solid";
          fsdiv.style.borderWidth = "1px";
          fsdiv.style.cursor = "pointer";
          fsdiv.style.textAlign = "center";
          fsdiv.title = Drupal.t('Full screen');
          fsdiv.innerHTML = '<img id="btnFullScreen" src="' + js_path + 'images/fs-map-full.png"/>';
          fsd.appendChild(fsdiv);
          google.maps.event.addDomListener(fsdiv, "click", function() {
            toggleFullScreen();
          });
        }

        function toggleFullScreen() {
          var cnt = Drupal.getlocations_map[key].getCenter();
          $("#getlocations_map_wrapper_" + key).toggleClass("fullscreen");
          $("html,body").toggleClass("fullscreen-body-" + key);
          $(document).scrollTop(0);
          google.maps.event.trigger(Drupal.getlocations_map[key], "resize");
          Drupal.getlocations_map[key].setCenter(cnt);
          setTimeout( function() {
            if($("#getlocations_map_wrapper_" + key).hasClass("fullscreen")) {
              $("#btnFullScreen").attr("src", js_path + 'images/fs-map-normal.png');
              fsdiv.title = Drupal.t('Normal screen');
            }
            else {
              $("#btnFullScreen").attr("src", js_path + 'images/fs-map-full.png');
              fsdiv.title = Drupal.t('Full screen');
            }
          },200);
        }

        function doAllMarkers(map, gs, mkey) {

          var arr = gs.latlons;
          for (var i = 0; i < arr.length; i++) {
            var arr2 = arr[i];
            if (arr2.length < 2) {
              return;
            }
            var lat = arr2[0];
            var lon = arr2[1];
            var lid = arr2[2];
            var name = arr2[3];
            var mark = arr2[4];
            var lidkey = arr2[5];
            var customContent = arr2[6];
            var cat = arr2[7];

            if (mark === '') {
              gs.markdone = gs.defaultIcon;
            }
            else {
              gs.markdone = Drupal.getlocations.getIcon(mark);
            }
            var m = Drupal.getlocations.makeMarker(map, gs, lat, lon, lid, name, lidkey, customContent, cat, mkey);
            // still experimental
            Drupal.getlocations_markers[mkey].lids[lid] = m;
            if (gs.usemarkermanager || gs.useclustermanager) {
              gs.batchr.push(m);
            }
          }
          // add batchr
          if (gs.usemarkermanager) {
           gs.mgr.addMarkers(gs.batchr, gs.minzoom, gs.maxzoom);
            gs.mgr.refresh();
          }
          else if (gs.useclustermanager) {
            gs.cmgr.addMarkers(gs.batchr, 0);
          }
        }

        function updateCopyrights(attrib) {
          if (attrib) {
            copyrightNode.innerHTML = attrib;
            if (setting.trafficinfo) {
              $("#getlocations_toggleTraffic_" + key).attr('disabled', true);
            }
            if (setting.bicycleinfo) {
              $("#getlocations_toggleBicycle_" + key).attr('disabled', true);
            }
            if (setting.transitinfo) {
              $("#getlocations_toggleTransit_" + key).attr('disabled', true);
            }
          }
          else {
            copyrightNode.innerHTML = "";
            if (setting.trafficinfo) {
              $("#getlocations_toggleTraffic_" + key).attr('disabled', false);
            }
            if (setting.bicycleinfo) {
              $("#getlocations_toggleBicycle_" + key).attr('disabled', false);
            }
            if (setting.transitinfo) {
              $("#getlocations_toggleTransit_" + key).attr('disabled', false);
            }
          }
        }

        function setupNewMap(k, blk) {
          if (setting.baselayer_settings != undefined) {
            if (setting.baselayer_settings[blk] != undefined) {
              var tle = setting.baselayer_settings[blk].title;
              if (setting.mtc == 'menu') {
                tle = setting.baselayer_settings[blk].short_title;
              }
              var tilesize = parseInt(setting.baselayer_settings[blk].tilesize);
              var url_template = setting.baselayer_settings[blk].url;
              Drupal.getlocations_map[k].mapTypes.set(blk, new google.maps.ImageMapType({
                getTileUrl: function(coord, zoom) {
                  var url = '';
                  if (url_template) {
                    url = url_template.replace(/__Z__/, zoom).replace(/__X__/, coord.x).replace(/__Y__/, coord.y);
                  }
                  return url;
                },
                tileSize: new google.maps.Size(tilesize, tilesize),
                name: tle,
                minZoom: parseInt(setting.baselayer_settings[blk].minzoom),
                maxZoom: parseInt(setting.baselayer_settings[blk].maxzoom)
              }));
            }
          }
        }

        function updateAttribs() {
          var blk = Drupal.getlocations_map[key].getMapTypeId();
          for (var c = 0; c < baselayer_keys.length; c++) {
            var bl_key = baselayer_keys[c];
            if ( bl_key != 'Map' && bl_key != 'Satellite' && bl_key != 'Hybrid' && bl_key != 'Physical') {
              if ( bl_key == blk ) {
                var attrib = setting.baselayer_settings[blk].attribution;
                if (attrib) {
                  updateCopyrights(attrib);
                }
              }
            }
            else {
              updateCopyrights('');
            }
          }
        }

        // end functions

      }); // end once
    } // end attach
  }; // end behaviors

  // external functions
  Drupal.getlocations.makeMarker = function(map, gs, lat, lon, lid, title, lidkey, customContent, cat, mkey) {

    //if (! gs.markdone) {
    //  return;
    //}

    // categories
    if (cat) {
      Drupal.getlocations_markers[mkey].cat[lid] = cat;
    }

    // check for duplicates
    var hash = new String(lat + lon);
    if (Drupal.getlocations_markers[mkey].coords[hash] == null) {
      Drupal.getlocations_markers[mkey].coords[hash] = 1;
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

    // relocate function
    var get_winlocation = function(gs, lid, lidkey) {
      if (gs.preload_data) {
        arr = gs.getlocations_info;
        for (var i = 0; i < arr.length; i++) {
          data = arr[i];
          if (lid == data.lid && lidkey == data.lidkey && data.content) {
            window.location = data.content;
          }
        }
      }
      else {
        // fetch link and relocate
        $.get(gs.lidinfo_path, {'lid': lid, 'key': lidkey}, function(data) {
          if (data.content) {
            window.location = data.content;
          }
        });
      }
    };

    var mouseoverTimeoutId = null;
    var mouseoverTimeout = (gs.markeractiontype == 'mouseover' ? 300 : 0);
    var p = new google.maps.LatLng(lat, lon);
    var m = new google.maps.Marker({
      icon: gs.markdone.image,
      shadow: gs.markdone.shadow,
      shape: gs.markdone.shape,
      map: map,
      position: p,
      title: title,
      clickable: (gs.markeraction > 0 ? true : false),
      optimized: false
    });

    if (gs.markeraction > 0) {
      google.maps.event.addListener(m, gs.markeractiontype, function() {
        mouseoverTimeoutId = setTimeout(function() {
          if (gs.useLink) {
            // relocate
            get_winlocation(gs, lid, lidkey);
          }
          else {
            if(gs.useCustomContent) {
              var cc = [];
              cc.content = customContent;
              Drupal.getlocations.showPopup(map, m, gs, cc, mkey);
            }
            else {
              // fetch bubble content
              if (gs.preload_data) {
                arr = gs.getlocations_info;
                for (var i = 0; i < arr.length; i++) {
                  data = arr[i];
                  if (lid == data.lid && lidkey == data.lidkey && data.content) {
                    Drupal.getlocations.showPopup(map, m, gs, data, mkey);
                  }
                }
              }
              else {
                var qs = {};
                qs.lid = lid;
                qs.key = lidkey;
                qs.gdlink = gs.getdirections_link;
                var slat = false;
                var slon = false;
                var sunit = false;
                if (gs.show_distance) {
                  // getlocations_search module
                  if ($("#getlocations_search_slat_" + mkey).is('div')) {
                    var slat = $("#getlocations_search_slat_" + mkey).html();
                    var slon = $("#getlocations_search_slon_" + mkey).html();
                    var sunit = $("#getlocations_search_sunit_" + mkey).html();
                  }
                }
                else if (gs.show_search_distance) {
                  // getlocations_fields distance views filter and field
                  if ($("#getlocations_fields_search_views_search_wrapper_" + mkey).is('div')) {
                    var slat = $("#getlocations_fields_search_views_search_latitude_" + mkey).html();
                    var slon = $("#getlocations_fields_search_views_search_longitude_" + mkey).html();
                    var sunit = $("#getlocations_fields_search_views_search_units_" + mkey).html();
                  }
                }
                if (slat && slon) {
                  qs.sdist = sunit + '|' + slat + '|' + slon;
                }

                $.get(gs.info_path, qs, function(data) {
                  Drupal.getlocations.showPopup(map, m, gs, data, mkey);
                });
              }
            }
          }
        }, mouseoverTimeout);
      });
      google.maps.event.addListener(m,'mouseout', function() {
        if(mouseoverTimeoutId) {
          clearTimeout(mouseoverTimeoutId);
          mouseoverTimeoutId = null;
        }
      });

    }

    // highlighting
    if (gs.markeractiontype != 'mouseover' && gs.highlight_enable) {
      var conv = [];
      var temp = 0.5;
      for (var c = 21; c > 0; c--) {
        temp += temp;
        conv[c] = temp;
      }
      var circOpts = {
        strokeColor: gs.highlight_strokecolor,
        strokeOpacity: gs.highlight_strokeopacity,
        strokeWeight: gs.highlight_strokeweight,
        fillColor: gs.highlight_fillcolor,
        fillOpacity: gs.highlight_fillopacity,
        radius: parseInt(gs.highlight_radius),
        center: p,
        map: map,
        visible: false,
        clickable: false
      };
      var circ =  new google.maps.Circle(circOpts);
      google.maps.event.addListener(m,'mouseover', function() {
        circ.setRadius(parseInt(gs.highlight_radius * conv[map.getZoom()] * 0.1));
        circ.setVisible(true);
      });
      google.maps.event.addListener(m,'mouseout', function() {
        circ.setVisible(false);
      });
    }

    // we only have one marker
    if (gs.datanum == 1) {
      if (gs.pansetting > 0) {
        map.setCenter(p);
        map.setZoom(gs.nodezoom);
      }
      // show_bubble_on_one_marker
      if (gs.show_bubble_on_one_marker && (gs.useInfoWindow || gs.useInfoBubble)) {
        google.maps.event.trigger(m, 'click');
      }
      // streetview first feature
      if (gs.sv_showfirst) {
        var popt = {
          position: p,
          pov: {
            heading: parseInt(gs.sv_heading),
            pitch: parseInt(gs.sv_pitch)
          },
          enableCloseButton: true,
          zoom: parseInt(gs.sv_zoom)
        };

        if (gs.sv_addresscontrol) {
          popt.addressControl = true;
          if (gs.sv_addresscontrolposition) {
            popt.addressControlOptions = {position: gs.controlpositions[gs.sv_addresscontrolposition]};
          }
        }
        else {
          popt.addressControl = false;
        }
        if (gs.sv_pancontrol) {
          popt.panControl = true;
          if (gs.sv_pancontrolposition) {
            popt.panControlOptions = {position: gs.controlpositions[gs.sv_pancontrolposition]};
          }
        }
        else {
          popt.panControl = false;
        }
        if (gs.sv_zoomcontrol == 'none') {
          popt.zoomControl = false;
        }
        else {
          popt.zoomControl = true;
          var zco = {};
          if (gs.sv_zoomcontrolposition) {
            zco.position = gs.controlpositions[gs.sv_zoomcontrolposition];
          }
          if (gs.sv_zoomcontrol == 'small') {
            zco.style = google.maps.ZoomControlStyle.SMALL;
          }
          else if (gs.sv_zoomcontrol == 'large') {
            zco.style = google.maps.ZoomControlStyle.LARGE;
          }
          if (zco) {
            popt.zoomControlOptions = zco;
          }
        }
        if (! gs.sv_linkscontrol) {
          popt.linksControl = false;
        }
        if (gs.sv_imagedatecontrol) {
          popt.imageDateControl = true;
        }
        else {
          popt.imageDateControl = false;
        }
        if (! gs.sv_scrollwheel) {
          popt.scrollwheel = false;
        }
        if (! gs.sv_clicktogo) {
          popt.clickToGo = false;
        }

        Drupal.getlocations_pano[mkey] = new google.maps.StreetViewPanorama(document.getElementById("getlocations_map_canvas_" + mkey), popt);
        Drupal.getlocations_pano[mkey].setVisible(true);
      }
    }

    // show_maplinks
    if (gs.show_maplinks && (gs.useInfoWindow || gs.useInfoBubble || gs.useLink)) {
      // add link
      $("div#getlocations_map_links_" + mkey + " ul").append('<li><a href="#maptop_' + mkey + '" class="lid-' + lid + '">' + title + '</a></li>');
      // Add listener
      $("div#getlocations_map_links_" + mkey + " a.lid-" + lid).click(function(){
        $("div#getlocations_map_links_" + mkey + " a").removeClass('active');
        $("div#getlocations_map_links_" + mkey + " a.lid-" + lid).addClass('active');
        if (gs.useLink) {
          // relocate
          get_winlocation(gs, lid, lidkey);
        }
        else {
          // emulate
          google.maps.event.trigger(m, 'click');
        }
      });
    }

    return m;

  };

  Drupal.getlocations.showPopup = function(map, m, gs, data, key) {
    var ver = Drupal.getlocations.msiedetect();
    var pushit = false;
    if ( (ver == '') || (ver && ver > 8)) {
      pushit = true;
    }

    if (pushit) {
      // close any previous instances
      for (var i in Drupal.getlocations_settings[key].infoBubbles) {
        Drupal.getlocations_settings[key].infoBubbles[i].close();
      }
    }

    if (gs.useInfoBubble) {
      if (typeof(infoBubbleOptions) == 'object') {
        var infoBubbleOpts = infoBubbleOptions;
      }
      else {
        var infoBubbleOpts = {};
      }
      infoBubbleOpts.content = data.content;
      var infoBubble = new InfoBubble(infoBubbleOpts);
      infoBubble.open(map, m);
      if (pushit) {
        // add to the array
        Drupal.getlocations_settings[key].infoBubbles.push(infoBubble);
      }
    }
    else {
      if (typeof(infoWindowOptions) == 'object') {
        var infoWindowOpts = infoWindowOptions;
      }
      else {
        var infoWindowOpts = {};
      }
      infoWindowOpts.content = data.content;
      var infowindow = new google.maps.InfoWindow(infoWindowOpts);
      infowindow.open(map, m);
      if (pushit) {
        // add to the array
        Drupal.getlocations_settings[key].infoBubbles.push(infowindow);
      }
    }
  };

  Drupal.getlocations.doBounds = function(map, minlat, minlon, maxlat, maxlon, dopan) {
    if (minlat !== '' && minlon !== '' && maxlat !== '' && maxlon !== '') {
      // Bounding
      var minpoint = new google.maps.LatLng(parseFloat(minlat), parseFloat(minlon));
      var maxpoint = new google.maps.LatLng(parseFloat(maxlat), parseFloat(maxlon));
      var bounds = new google.maps.LatLngBounds(minpoint, maxpoint);
      if (dopan) {
        map.panToBounds(bounds);
      }
      else {
        map.fitBounds(bounds);
      }
    }
  };

  Drupal.getlocations.redoMap = function(key) {
    var settings = Drupal.settings.getlocations[key];
    var minmaxes = (Drupal.getlocations_data[key].minmaxes ? Drupal.getlocations_data[key].minmaxes : '');
    var minlat = '';
    var minlon = '';
    var maxlat = '';
    var maxlon = '';
    var cenlat = '';
    var cenlon = '';
    if (minmaxes) {
      minlat = parseFloat(minmaxes.minlat);
      minlon = parseFloat(minmaxes.minlon);
      maxlat = parseFloat(minmaxes.maxlat);
      maxlon = parseFloat(minmaxes.maxlon);
      cenlat = ((minlat + maxlat) / 2);
      cenlon = ((minlon + maxlon) / 2);
    }
    google.maps.event.trigger(Drupal.getlocations_map[key], "resize");
    if (! settings.inputmap && ! settings.extcontrol) {
      if (settings.pansetting == 1) {
        Drupal.getlocations.doBounds(Drupal.Drupal.getlocations_map[key], minlat, minlon, maxlat, maxlon, true);
      }
      else if (settings.pansetting == 2) {
        Drupal.getlocations.doBounds(Drupal.getlocations_map[key], minlat, minlon, maxlat, maxlon, false);
      }
      else if (settings.pansetting == 3 && cenlat && cenlon) {
        var c = new google.maps.LatLng(parseFloat(cenlat), parseFloat(cenlon));
        Drupal.getlocations_map[key].setCenter(c);
      }
    }
  };

  Drupal.getlocations.msiedetect = function() {
    var ieversion = '';
    if (/MSIE (\d+\.\d+);/.test(navigator.userAgent)){ //test for MSIE x.x;
     ieversion = new Number(RegExp.$1) // capture x.x portion and store as a number
    }
    return ieversion;
  };

  Drupal.getlocations.getGeoErrCode = function(errcode) {
    var errstr;
    if (errcode == google.maps.GeocoderStatus.ERROR) {
      errstr = Drupal.t("There was a problem contacting the Google servers.");
    }
    else if (errcode == google.maps.GeocoderStatus.INVALID_REQUEST) {
      errstr = Drupal.t("This GeocoderRequest was invalid.");
    }
    else if (errcode == google.maps.GeocoderStatus.OVER_QUERY_LIMIT) {
      errstr = Drupal.t("The webpage has gone over the requests limit in too short a period of time.");
    }
    else if (errcode == google.maps.GeocoderStatus.REQUEST_DENIED) {
      errstr = Drupal.t("The webpage is not allowed to use the geocoder.");
    }
    else if (errcode == google.maps.GeocoderStatus.UNKNOWN_ERROR) {
      errstr = Drupal.t("A geocoding request could not be processed due to a server error. The request may succeed if you try again.");
    }
    else if (errcode == google.maps.GeocoderStatus.ZERO_RESULTS) {
      errstr = Drupal.t("No result was found for this GeocoderRequest.");
    }
    return errstr;
  };

  Drupal.getlocations.geolocationErrorMessages = function(error) {
    var ret = '';
    switch(error.code) {
      case error.PERMISSION_DENIED:
        ret = Drupal.t("because you didn't give me permission");
        break;
      case error.POSITION_UNAVAILABLE:
        ret = Drupal.t("because your browser couldn't determine your location");
        break;
      case error.TIMEOUT:
        ret = Drupal.t("because it was taking too long to determine your location");
        break;
      case error.UNKNOWN_ERROR:
        ret = Drupal.t("due to an unknown error");
        break;
    }
    return ret;
  };

}(jQuery));
