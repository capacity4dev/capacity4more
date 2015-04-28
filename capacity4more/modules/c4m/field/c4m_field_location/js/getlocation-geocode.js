(
  function ($) {
    Drupal.behaviors.getLocationsGeocode = {
      attach: function (context, settings) {
        // Work over all class 'getlocations_map_canvas'
        $(".getlocations_map_canvas", context).once('getlocations-fields-map-processed-fix', function (index, element) {
          var elemID = $(element).attr('id');
          var key = elemID.replace(/^getlocations_map_canvas_/, '');

          var streetfield = 'getlocations_street_';
          var additionalfield = 'getlocations_additional_';
          var cityfield = 'getlocations_city_';
          var provincefield = 'getlocations_province_';

          // Is there really a map?
          if ($("#getlocations_map_canvas_" + key).is('div') && settings.getlocations_fields[key] !== undefined) {

            var geocode = $("#" + 'getlocations_geocodebutton_' + key);

            geocode.addClass('btn').addClass('btn-warning')
              .parent()
              .next('p')
              .html(Drupal.t('Convert your address to a geographical location. Don\'t forget to do this for every change in your address.'));

            $(".form-submit#edit-submit").on('click', function (evt) {
              // Only geocode if anything significant is entered.
              if ($("#" + streetfield + key).val() != '' ||
                $("#" + additionalfield + key).val() != '' ||
                  // Geocoding based on postal code alone delivers wrong results.
                  //$("#" + postal_codefield + key).val() != '' ||
                $("#" + cityfield + key).val() != '' ||
                $("#" + provincefield + key).val() != '') {
                  // Pressing the GEOCODE button is not that clear, fallback functionality to trigger these steps via js before submitting the form.
                  // Prevent immediate form submission.
                  evt.preventDefault();
                  geocode.trigger('click');

                  setTimeout(function() { document.getElementById('event-node-form').submit()}, 1000);
              }
            });
          }
        });
      }
    };
  }
)(jQuery);