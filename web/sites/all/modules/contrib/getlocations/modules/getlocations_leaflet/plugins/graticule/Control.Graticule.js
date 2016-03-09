(function ($) {
  Drupal.behaviors.graticule = {
    attach: function() {

      L.Control.Graticule = L.Control.extend({

        _Graticule: false,

        options: {
          position: 'topleft',
          title: 'Toggle Graticule',
          forceSeparateButton: false
        },

        initialize: function (Graticule, options) {
          this._Graticule = Graticule;
          // Override default options
          for (var i in options) if (options.hasOwnProperty(i) && this.options.hasOwnProperty(i)) this.options[i] = options[i];
        },

        onAdd: function (map) {
          var className = 'leaflet-control-graticule', container;

          if (map.zoomControl && !this.options.forceSeparateButton) {
            container = map.zoomControl._container;
          } else {
            container = L.DomUtil.create('div', 'leaflet-bar');
          }

          this._createButton(this.options.title, className, container, this._clicked, map, this._Graticule);
          return container;
        },

        _createButton: function (title, className, container, method, map, Graticule) {
          var link = L.DomUtil.create('a', className, container);
          link.href = '#';
          link.title = title;

          L.DomEvent
          .addListener(link, 'click', L.DomEvent.stopPropagation)
          .addListener(link, 'click', L.DomEvent.preventDefault)
          .addListener(link, 'click', function() {method(map, Graticule);}, map);

          return link;
        },

        _clicked: function (map, Graticule) {
          if (!Graticule) {
            return;
          }

          if (map.hasLayer(Graticule)) {
            map.removeLayer(Graticule);
          } else {
            Graticule.addTo(map);
          }
        }
      });

      L.control.graticule = function (Graticule, options) {
        return new L.Control.Graticule(Graticule, options);
      };

    }
  };
})(jQuery);
