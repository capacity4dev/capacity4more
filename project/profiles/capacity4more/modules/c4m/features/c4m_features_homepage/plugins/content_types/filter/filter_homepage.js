/**
 * @file
 * Filters the homepage content based on the filter.
 */

(function ($) {

  $(document).ready(function() {
    $('#edit-homepage-filter').change(function() {
      var radios = $('input[name="homepage-filter"]:checked');
      var filter = radios.val();
      window.location.search = '?filter=' + filter;
    });
  });

})(jQuery);
