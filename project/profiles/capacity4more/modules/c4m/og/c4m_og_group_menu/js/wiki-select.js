/**
 * @file
 * React on wiki page select.
 */

(function ($) {

  Drupal.behaviors.wikiSelect = {
    attach: function (context) {
      $("#edit-wiki-select").on("change", function() {
        var $val = $("#edit-wiki-select").val();
        $("#edit-link-path").val($val);
      })
    }
  };

})(jQuery);
