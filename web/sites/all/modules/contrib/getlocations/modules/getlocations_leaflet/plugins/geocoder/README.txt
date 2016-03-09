Extending the geocoder functionality.
The geocoder for each map can be accessed in the javascript global variable
getlocations_leaflet_geocoder[key]
where 'key' is the key of the current map, eg 'key_1'

Here is an example of some javascript that could be run in a theme.
It replaces the default result actions with something else, in this case it
makes a polygon that describes the bounds of the search result.
Replace 'mytheme' with the name of your theme and add it to your theme's javascript

(function ($) {
  Drupal.behaviors.mytheme = {
    attach: function() {

      // edit this line to suit your use case
      if ($(".view-display-id-page_2").is('div') && $("#getlocations_leaflet_wrapper_key_1").is('div')) {
        var key = 'key_1';
        getlocations_leaflet_geocoder[key].markGeocode = function(result) {
          var bbox = result.bbox;
          this._map.fitBounds(bbox);
          if (this._lpolygon) {
            this._map.removeLayer(this._lpolygon);
          }
          this._lpolygon = L.polygon(
            [bbox.getSouthEast(), bbox.getNorthEast(), bbox.getNorthWest(), bbox.getSouthWest()],
            {
              'color': '#A0A0A0',
              'opacity': 0.8,
              'weight': 2,
              'fillColor': '#C0C0C0',
              'fillOpacity': 0.3,
              'clickable': true
            }
          );
          this._lpolygon.bindPopup(result.name).addTo(this._map);
        };
      }

    }
  };
})(jQuery);

