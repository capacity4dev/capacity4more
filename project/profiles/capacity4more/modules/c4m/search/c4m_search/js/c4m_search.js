/**
 * @file
 * Functionality for search.
 */

(function ($) {
  /**
   * Trick Drupal into rebinding the autocomplete behavior.
   */
  Drupal.behaviors.focus_search_form = {
    attach: function (context, settings) {
      $('#edit-search-page').change(function() {
        $('#edit-keys-autocomplete')
          .removeClass('autocomplete-processed')
          .val('/search_api_autocomplete/' + $('#edit-search-page').val() + '/-');
        $('#edit-keys')
          .unbind()
          .focus();
        Drupal.behaviors.autocomplete.attach(document);
      })
    }
  }
})(jQuery);
