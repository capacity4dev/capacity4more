/**
 * @file
 * Auto submit the "embedding" form in the media browser WYSIWYG popup.
 */

(function ($) {

  Drupal.behaviors.autoEmbed = {
    attach: function (context, settings) {
      // Automatically click the submit button to embed the file.
      $('.button.fake-ok').click();
    }
  };

})(jQuery);
