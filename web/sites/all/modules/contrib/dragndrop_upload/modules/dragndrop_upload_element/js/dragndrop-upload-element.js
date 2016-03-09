/**
 * @file
 * Contains a behavior to initialize dragndrop_upload element.
 */

(function ($) {
  Drupal.behaviors.dragndropUploadElement = {
    attach: function (context, settings) {
      if (!settings.dragndropUploadElement) {
        return;
      }
      $.each(settings.dragndropUploadElement, function (selector) {
        $(selector, context).once('dnd-upload-element', function () {
          new DnDUpload($(this));
        });
      });
    }
  };
})(jQuery);
