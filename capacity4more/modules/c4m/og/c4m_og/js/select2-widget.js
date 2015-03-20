/**
 * @file
 * Add Select2 functionality to select fields.
 */

(function ($) {
  Drupal.behaviors.select2Widget = {
    // Add Select2 functionality to select fields.
    attach: function (context, settings) {

      // Get needed data about all select elements that should be using Select2.
      var elements = Drupal.settings.select2_widget;
      var element;

      // Run through elements and add Select2 functionality to each of them.
      for (var key in elements) {
        element = elements[key];

        var selector = element.selector;
        var cardinality = element.cardinality;

        $(selector).select2({
          maximumSelectionSize: cardinality
        });
      }

    }
  }
})(jQuery);
