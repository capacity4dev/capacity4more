/**
 * @file
 * Group export behaviors.
 */

var Drupal = Drupal || {};
var jQuery = jQuery || {};

(function ($) {
  "use strict";

  /**
   * Adjust interval dates according to the predefined options.
   *
   * @type {{attach: Drupal.behaviors.disableSubmitButtons.attach}}
   */
  Drupal.behaviors.setPredefinedInterval = {
    attach: function (context) {
      $('#predefined-intervals a', context).on('click', function () {
        $("#edit-start-date input").val($(this).attr("start"));
        $("#edit-end-date input").val($(this).attr("end"));
      });
    }
  };

})
(jQuery);
