/**
 * @file
 * Activate carousel.
 */

(function ($) {

  Drupal.behaviors.nodeFieldsetSummaries = {
    attach: function (context) {
      $(".owl-carousel").owlCarousel({
        // Show next and prev buttons
        navigation : true,
        slideSpeed : 300,
        paginationSpeed : 400,
        singleItem:true,
        navigationText: [
          "<i class='fa fa-3x fa-arrow-circle-left' aria-hidden='true'></i>",
          "<i class='fa fa-3x fa-arrow-circle-right' aria-hidden='true'></i>"
        ],
      });
    }
  };

})(jQuery);

