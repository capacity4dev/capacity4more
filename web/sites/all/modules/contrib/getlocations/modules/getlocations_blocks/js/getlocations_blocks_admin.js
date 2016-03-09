
/**
 * @file
 * getlocations_blocks_admin.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations_blocks module admin
*/
(function ($) {

  Drupal.behaviors.getlocations_blocks_admin = {
    attach: function() {
      // city
      var f = $("#edit-getlocations-blocks-city-filter").val();
      do_change(f, 'city');
      $("#edit-getlocations-blocks-city-filter").change( function() {
        f = $(this).val();
        do_change(f, 'city');
      });
      // province
      f = $("#edit-getlocations-blocks-province-filter").val();
      do_change(f, 'province');
      $("#edit-getlocations-blocks-province-filter").change( function() {
        f = $(this).val();
        do_change(f, 'province');
      });
      // postalcode
      f = $("#edit-getlocations-blocks-postalcode-filter").val();
      do_change(f, 'postalcode');
      $("#edit-getlocations-blocks-postalcode-filter").change( function() {
        f = $(this).val();
        do_change(f, 'postalcode');
      });
      // country
      if ($("#edit-getlocations-blocks-country-full").attr('checked')) {
        $(".form-item-getlocations-blocks-country-filter").hide();
        $(".form-item-getlocations-blocks-country-filter-fieldname").hide();
        $(".form-item-getlocations-blocks-country-filter-bundle").hide();
      }
      else {
         country_change();
      }
      $("#edit-getlocations-blocks-country-full").change( function() {
        if ($(this).attr('checked')) {
          $(".form-item-getlocations-blocks-country-filter").hide();
          $(".form-item-getlocations-blocks-country-filter-fieldname").hide();
          $(".form-item-getlocations-blocks-country-filter-bundle").hide();
        }
        else {
          country_change();
        }
      });

      function country_change() {
        $(".form-item-getlocations-blocks-country-filter").show();
        f = $("#edit-getlocations-blocks-country-filter").val();
        do_change(f, 'country');
        $("#edit-getlocations-blocks-country-filter").change( function() {
          f = $(this).val();
          do_change(f, 'country');
        });
      }

      function do_change(filter, field) {
        if (filter == 'field_name') {
          $(".form-item-getlocations-blocks-" + field + "-filter-fieldname").show();
          $(".form-item-getlocations-blocks-" + field + "-filter-bundle").hide();
        }
        else if (filter == 'bundle') {
          $(".form-item-getlocations-blocks-" + field + "-filter-fieldname").hide();
          $(".form-item-getlocations-blocks-" + field + "-filter-bundle").show();
        }
        else {
          $(".form-item-getlocations-blocks-" + field + "-filter-fieldname").hide();
          $(".form-item-getlocations-blocks-" + field + "-filter-bundle").hide();
        }
      }

    }
  };
}(jQuery));
