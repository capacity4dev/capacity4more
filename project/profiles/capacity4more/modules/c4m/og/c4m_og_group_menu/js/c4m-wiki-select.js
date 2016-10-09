/**
 * @file
 * React on wiki page select.
 */

(function ($) {
  // When option from wiki select element is selected, set
  // it's value as a path link.
  Drupal.behaviors.wikiSelect = {
    attach: function (context) {
      $("#edit-wiki-select").on("change", function() {
        var $val = $("#edit-wiki-select").val();
        $("#edit-link-path").val($val);
      })
    }
  };

})(jQuery);
