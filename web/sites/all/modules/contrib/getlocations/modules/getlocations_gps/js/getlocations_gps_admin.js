/**
 * @file
 * getlocations_admin.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations module admin
 * jquery stuff
 */
(function ($) {
  Drupal.behaviors.getlocations_admin_gps = {
    attach: function() {
      // gps button
      if ($("input[id$=gps-button]").is('input')) {
        if ($("input[id$=gps-button]").attr('checked')) {
          $("#wrap-getlocations-gps-button").show();
        }
        else {
          $("#wrap-getlocations-gps-button").hide();
        }
        $("input[id$=gps-button]").change(function() {
          if ($(this).attr('checked')) {
            $("#wrap-getlocations-gps-button").show();
          }
          else {
            $("#wrap-getlocations-gps-button").hide();
          }
        });
      }
    }
  };
}(jQuery));
