/**
 * @file
 * Functionality for search.
 */

(function ($) {
  Drupal.behaviors.focus_search_form = {
    attach: function (context, settings) {
      $('#edit-search-page').change(function() {
        $('#edit-keys').focus();
      })
    }
  }
})(jQuery);
