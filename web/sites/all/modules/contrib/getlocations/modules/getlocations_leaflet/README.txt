getlocations_leaflet module for Drupal 7.x

If you have any questions or suggestions please contact me at
http://drupal.org/user/52366 or use the Getlocations issue queue.

Leaflet Library from
http://leaflet-cdn.s3.amazonaws.com/build/leaflet-0.7.3.zip
Extract it to your drupal root /sites/all/libraries/leaflet.
The file 'leaflet.js' must be found at /sites/all/libraries/leaflet/leaflet.js.
All other files and folder(s) that come with the library are also needed there.
You can install it using drush:
drush getlocations-leaflet

Alternately you can use CDN, see http://leafletjs.com/ or https://cdnjs.com/libraries/leaflet for details.
You can add the css and js URLs on the Leaflet configuration page.


markercluster comes from
https://github.com/Leaflet/Leaflet.markercluster
It is already installed but if you want to configure it in detail you might want to look at the examples.
See markercluster/markerclusteroptions.inc.txt for how to add options.

The list of available maps is based on code from
https://github.com/leaflet-extras/leaflet-providers

You can add maps from http://cloudmade.com/ on the form at admin/config/services/getlocations_leaflet
You can also add maps using a bespoke module, it should contain a function similar to this:

/**
 * Implements hook_TYPE_alter().
 *
 */
function mymodule_getlocations_leaflet_map_info_alter(&$map_info) {

  $cloudmade_apikey = 'YOUR_CLOUDMADE_API_KEY';
  $styleID_1 = '111479';
  $name_1 = "Cloudmade " . $styleID_1;
  $urlTemplate_1 = 'http://{s}.tile.cloudmade.com/' . $cloudmade_apikey . '/' . $styleID_1 . '/256/{z}/{x}/{y}.png';
  $attribution_1 = '© <a target="_blank" href="http://cloudmade.com">CloudMade</a> ' . $styleID_1;

  $styleID_2 = '69038';
  $name_2 = "Cloudmade " . $styleID_2;
  $urlTemplate_2 = 'http://{s}.tile.cloudmade.com/' . $cloudmade_apikey . '/' . $styleID_2 . '/256/{z}/{x}/{y}.png';
  $attribution_2 = '© <a target="_blank" href="http://cloudmade.com">CloudMade</a> ' . $styleID_2;

  $add = array(
    "$name_1" => array(
      'urlTemplate' => $urlTemplate_1,
      'options' => array(
        'attribution' => $attribution_1
      ),
      'description' => t('mymodule style 1'),
    ),
    "$name_2" => array(
      'urlTemplate' => $urlTemplate_2,
      'options' => array(
        'attribution' => $attribution_2
      ),
      'description' => t('mymodule style 2'),
    ),
  );
  $map_info['Getlocations OSM']['map_layers'] += $add;
}

Replace "mymodule" with the name of your module. This will also work in your theme's template.php.

GeoJSON support
Getlocations can support GeoJSON objects, see http://www.geojson.org/ for information about this format.
You can download the library from https://github.com/JasonSanford/GeoJSON-to-Google-Maps.
It should be installed in your libraries folder so you have a path something like this:
sites/all/libraries/GeoJSON/GeoJSON.js
You can install it using drush:
drush getlocations-geojson

Here is an example of geojson data:
{
  "type": "FeatureCollection",
  "features": [{
    "type": "Feature",
    "geometry": {
      "type": "Point",
      "coordinates": [102.0, 0.5]
    },
    "properties": {
      "popup": "this is a marker"
    }
  },
  {
    "type": "Feature",
    "geometry": {
      "type": "LineString",
      "coordinates": [[102.0, 0.0], [103.0, 1.0], [104.0, 0.0], [105.0, 1.0]]
    },
    "properties": {
      "popup": "hello world",
      "style": {"color": "#00C0C0", "opacity": "0.85", "weight": "2"}
    }
  }
]
}

The coordinates must be supplied as Longitude,Latitude.
"popup" contains the content of a popup balloon.
"style" can contain any valid Leaflet styling.

Other plugin sources:
https://github.com/turban/Leaflet.Graticule
https://github.com/lvoogdt/Leaflet.awesome-markers
http://fortawesome.github.io/Font-Awesome/
http://kartena.github.com/Leaflet.Pancontrol/
http://kartena.github.com/Leaflet.zoomslider/
http://brunob.github.com/leaflet.fullscreen
https://github.com/turban/Leaflet.Sync
https://github.com/Norkart/Leaflet-MiniMap
https://github.com/ardhi/Leaflet.MousePosition

Leaflet DivIcons

Leaflet's DivIcon function can be used by doing the following:
Enable Awesome markers.
Select awesome markers as the marker type
Select "Icon only" and add your html and/or class to the provided textfields
an example html:<div class="divicon-test1">&nbsp;</div>
ensure that your bespoke css class is in your theme's css and it should work.

