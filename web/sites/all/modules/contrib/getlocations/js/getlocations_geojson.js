
/**
 * @file
 * getlocations_geojson.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations GeoJSON support
 * See https://github.com/JasonSanford/GeoJSON-to-Google-Maps
 * and http://www.geojson.org
*/

// this gets called from getlocations.js
Drupal.getlocations_geojson = function(key) {

  // collect data and options
  var geojson_data = Drupal.settings.getlocations[key].geojson_data;
  if (! geojson_data) {
    return;
  }
  var geojson_data_parsed = JSON.parse(geojson_data);
  var geojson_options = Drupal.settings.getlocations[key].geojson_options;
  var geojson_options_parsed = null;
  if (geojson_options) {
    geojson_options_parsed = JSON.parse(geojson_options);
  }
  // get the object
  var geojson_object = new GeoJSON(geojson_data_parsed, geojson_options_parsed);
  if (geojson_object.type && geojson_object.type == "Error") {
    alert(geojson_object.message);
    return;
  }
  //step over the object
  if (geojson_object.length) {
    for (var i = 0; i < geojson_object.length; i++) {
      if (geojson_object[i].length) {
        for (var j = 0; j < geojson_object[i].length; j++) {
          geojson_object[i][j].setMap(Drupal.getlocations_map[key]);
          if (geojson_object[i][j].geojsonProperties) {
            getlocations_do_geojson_bubble(geojson_object[i][j], key);
          }
        }
      }
      else {
        geojson_object[i].setMap(Drupal.getlocations_map[key]);
      }
      if (geojson_object[i].geojsonProperties) {
        getlocations_do_geojson_bubble(geojson_object[i], key);
      }
    }
  }
  else {
    geojson_object.setMap(Drupal.getlocations_map[key]);
    if (geojson_object.geojsonProperties) {
      getlocations_do_geojson_bubble(geojson_object, key);
    }
  }

};

function getlocations_do_geojson_bubble(data_item, key) {
  // munge for bonehead browsers
  var ver = Drupal.getlocations.msiedetect();
  var pushit = false;
  if ((ver == '') || (ver && ver > 8)) {
    pushit = true;
  }

  var main = '';
  for (var j in data_item.geojsonProperties) {
    main += data_item.geojsonProperties[j] + "<br />";
  }
  if (main == '') {
    return;
  }
  var geojson_content = "";
  geojson_content += '<div class="location vcard">';
  geojson_content += '<div class="container-inline">';
  geojson_content += main;
  geojson_content += '</div>';
  geojson_content += '</div>';

  google.maps.event.addListener(data_item, "click", function(event) {
    if (pushit) {
      for (var i in Drupal.getlocations_settings[key].infoBubbles) {
        Drupal.getlocations_settings[key].infoBubbles[i].close();
      }
    }
    if (Drupal.getlocations_settings[key].markeraction == 2) {
      if (typeof(infoBubbleOptions) == 'object') {
        var infoBubbleOpts = infoBubbleOptions;
      }
      else {
        var infoBubbleOpts = {};
      }
      infoBubbleOpts.content = geojson_content;
      var geojson_iw = new InfoBubble(infoBubbleOpts);
    }
    else {
      if (typeof(infoWindowOptions) == 'object') {
        var infoWindowOpts = infoWindowOptions;
      }
      else {
        var infoWindowOpts = {};
      }
      infoWindowOpts.content = geojson_content;
      var geojson_iw = new google.maps.InfoWindow(infoWindowOpts);
    }
    geojson_iw.open(Drupal.getlocations_map[key], data_item);
    if (pushit) {
      Drupal.getlocations_settings[key].infoBubbles.push(geojson_iw);
    }
  });

}
