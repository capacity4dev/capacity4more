
/**
 * @file
 * getlocations_leaflet_field_group.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations_leaflet module for Drupal 7
 * this is for leaflet maps http://leafletjs.com/
 */

(function ($) {
  Drupal.behaviors.getlocations_leaflet_field_group = {
    attach: function () {

      // bail out
      if (typeof Drupal.settings.getlocations_leaflet === 'undefined') {
        return;
      }

      $.each(Drupal.settings.getlocations_leaflet, function (key, settings) {

        // Drupal field_group module support
        if (settings.map_settings.field_group_enable) {
          // field group multipage support
          if ($(".multipage-link-next,.multipage-link-previous").is('input')) {
            $(".multipage-link-next,.multipage-link-previous").one('click', function(event) {
              Drupal.getlocations_leaflet.redoMap(key);
            });
          }
          // field group vert tabs
          if ($(".vertical-tabs-list").is('ul')) {
            $("li.vertical-tab-button a").bind('click', function(event) {
              Drupal.getlocations_leaflet.redoMap(key);
              if (Drupal.getlocations_leaflet_data[key].datanum == 1) {
                var ll2 = Drupal.getlocations_leaflet_data[key].latlons[0];
                Drupal.getlocations_leaflet_map[key].invalidateSize().panTo([parseFloat(ll2[0]),parseFloat(ll2[1])]);
              }
            });
          }

          // field group horiz tabs
          if ($(".horizontal-tabs-list").is('ul')) {
            $("li.horizontal-tab-button a").bind('click', function(event) {
              Drupal.getlocations_leaflet.redoMap(key);
            });
          }

          // field group accordion
          if ($(".field-group-accordion,.field-group-accordion-wrapper").is('div')) {
            $(".accordion-item").bind('click', function(event) {
              Drupal.getlocations_leaflet.redoMap(key);
            });
          }
        }

      }); // end each

    } // end attach
  }; // end behaviors

})(jQuery);
