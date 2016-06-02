/**
 * @file
 * Activate carousel.
 */

(function ($) {

  Drupal.behaviors.nodeFieldsetSummaries = {
    attach: function (context) {
      $(".owl-carousel").owlCarousel({
        // Show next and prev buttons.
        navigation : true,
        slideSpeed : 300,
        paginationSpeed : 400,
        singleItem:true,
        navigationText: [
          '<svg width="35" height="35" viewBox="0 0 512 512" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" fill="#ffffff"><path d="M 416.00,416.00l-96.00,96.00L 64.00,256.00L 320.00,0.00l 96.00,96.00L 256.00,256.00L 416.00,416.00z" ></path></svg>',
          '<svg width="35" height="35" viewBox="0 0 512 512" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" fill="#ffffff"><path d="M 64.00,416.00l 96.00,96.00l 256.00-256.00L 160.00,0.00L 64.00,96.00l 160.00,160.00L 64.00,416.00z" ></path></svg>'
        ],
      });
    }
  };

})(jQuery);
