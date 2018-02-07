/**
 * @file
 * Auto submit the "embedding" form in the media browser WYSIWYG popup.
 */

(function ($) {

  Drupal.behaviors.autoEmbed = {
    attach: function (context, settings) {
      // Delay the click action as in Safari, when you upload an image it
      // doesn't get rendered as its request is cancelled by the browser.
      setTimeout(function () {
        // Automatically click the submit button to embed the file.
        $('.button.fake-ok').click();
      }, 50);
    }
  };

})(jQuery);
