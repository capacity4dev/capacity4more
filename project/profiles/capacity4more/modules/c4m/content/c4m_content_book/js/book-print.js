/**
 * @file
 * Print functionality.
 */

var Drupal = Drupal || {};
var jQuery = jQuery || {};

(function ($) {
  "use strict";

  /**
   * Print page after document loads.
   *
   * @type {{attach: Drupal.behaviors.eventFormClasses.attach}}
   */
  Drupal.behaviors.bookStructurePrint = {
    attach: function () {
      $(window).bind("load", function () {
        window.print();
        window.onafterprint = function () {
          window.top.close();
        };
      });
    }
  };

})
(jQuery);
