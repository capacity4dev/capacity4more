
/**
 * @file
 * getlocations_marker_box.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations module marker colorbox
 * jquery stuff
*/
(function ($) {

  Drupal.getlocations_marker_box = {};
  // colorbox with markers. This function is triggered when an icon in the colorbox is clicked on.
  // It collects the machine_name and applies it to the dropdown linktype in the parent page.
  Drupal.getlocations_marker_box.getlocations_marker_get = function(machine_name, linktype) {
    var topdoc = false;
    var linkid = false;
    if (linktype) {
      linkid = '#' + linktype;
    }
    if (linkid) {
      topdoc = $(window.parent.document).find(linkid);
      if (topdoc) {
        $(topdoc).val(machine_name).attr('selected');
      }
      else {
      }
    }
    return false;
  };
}(jQuery));
