
/**
 * @file
 * getlocations_blocks.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations_blocks module
*/
(function ($) {
  Drupal.behaviors.getlocations_blocks = {
    attach: function() {

      $("#edit-getlocations-blocks-city-form-submit").click( function() {
        p = $("#edit-getlocations-blocks-city").val();
        if (p) {
          window.location = Drupal.settings.basePath + Drupal.settings.getlocations_blocks.city_path + '/' + p;
        }
        return false;
      });

      $("#edit-getlocations-blocks-province-form-submit").click( function() {
        p = $("#edit-getlocations-blocks-province").val();
        if (p) {
          window.location = Drupal.settings.basePath + Drupal.settings.getlocations_blocks.province_path + '/' + p;
        }
        return false;
      });

      $("#edit-getlocations-blocks-postalcode-form-submit").click( function() {
        p = $("#edit-getlocations-blocks-postalcode").val();
        if (p) {
          window.location = Drupal.settings.basePath + Drupal.settings.getlocations_blocks.postalcode_path + '/' + p;
        }
        return false;
      });

      $("#edit-getlocations-blocks-country-form-submit").click( function() {
        p = $("#edit-getlocations-blocks-country").val();
        if (p) {
          window.location = Drupal.settings.basePath + Drupal.settings.getlocations_blocks.country_path + '/' + p;
        }
        return false;
      });

    }
  };
}(jQuery));
