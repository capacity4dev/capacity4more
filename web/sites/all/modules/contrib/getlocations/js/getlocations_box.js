
/**
 * @file
 * getlocations_box.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations module in colorbox
 * jquery stuff
*/
(function ($) {

  Drupal.behaviors.getlocations_box = {
    attach: function() {
      // hide the returnlinks in a box
      $(".getlocations_returnlink").hide();
    }
  };

}(jQuery));
