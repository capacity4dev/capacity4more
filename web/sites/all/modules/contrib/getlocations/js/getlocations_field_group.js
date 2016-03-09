
/**
 * @file
 * getlocations_field_group.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations module for Drupal 7
 */

(function ($) {
  Drupal.behaviors.getlocations_field_group = {
    attach: function () {

      // bail out
      if (typeof Drupal.settings.getlocations === 'undefined') {
        return;
      }

      $.each(Drupal.settings.getlocations, function (key, settings) {

        // Drupal field_group module support
        if (settings.field_group_enable) {
          // field group multipage support
          if ($(".multipage-link-next,.multipage-link-previous").is('input')) {
            $(".multipage-link-next,.multipage-link-previous").one('click', function(event) {
              Drupal.getlocations.redoMap(key);
              if (Drupal.getlocations_data[key].datanum == 1) {
                var ll = Drupal.getlocations_data[key].latlons;
                var ll2 = ll[0];
                Drupal.getlocations_map[key].setCenter({lat: parseFloat(ll2[0]), lng: parseFloat(ll2[1])});
              }
            });
          }
          // field group vert and horiz tabs
          if ($(".vertical-tabs-list,.horizontal-tabs-list").is('ul')) {
            $("li.vertical-tab-button a, li.horizontal-tab-button a").bind('click', function(event) {
              Drupal.getlocations.redoMap(key);
              if (Drupal.getlocations_data[key].datanum == 1) {
                var ll = Drupal.getlocations_data[key].latlons;
                var ll2 = ll[0];
                Drupal.getlocations_map[key].setCenter({lat: parseFloat(ll2[0]), lng: parseFloat(ll2[1])});
              }
            });
          }
          // field group accordion
          if ($(".field-group-accordion, .field-group-accordion-wrapper").is('div')) {
            $(".accordion-item").bind('click', function(event) {
              Drupal.getlocations.redoMap(key);
              if (Drupal.getlocations_data[key].datanum == 1) {
                var ll = Drupal.getlocations_data[key].latlons;
                var ll2 = ll[0];
                Drupal.getlocations_map[key].setCenter({lat: parseFloat(ll2[0]), lng: parseFloat(ll2[1])});
              }
            });
          }
        }

      }); // end each

    } // end attach
  }; // end behaviors

})(jQuery);
