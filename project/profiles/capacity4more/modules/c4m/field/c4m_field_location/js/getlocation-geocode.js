/**
 * @file
 * Manipulate the default getlocations code to work as we want it.
 */

(
  function ($) {
    Drupal.behaviors.getLocationsGeocode = {
      attach: function (context, settings) {
        // Work over all class 'getlocations_map_canvas'.
        $(".getlocations_map_canvas", context).once('getlocations-fields-map-processed-fix', function (index, element) {
          var elemID = $(element).attr('id');
          var key = elemID.replace(/^getlocations_map_canvas_/, '');

          // Is there really a map?
          if ($("#getlocations_map_canvas_" + key).is('div') &&
            settings.getlocations_fields[key] !== undefined) {

            var geocode = $("#" + 'getlocations_geocodebutton_' + key);

            geocode.addClass('btn').addClass('btn-warning')
              .parent()
              .next('p')
              .html(Drupal.t('Convert your address to a geographical location. Don\'t forget to do this for every change in your address.'));
          }
        });
      }
    };
  }
)(jQuery);
