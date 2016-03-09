(function($) {

  Drupal.behaviors.nodeGalleryPlupload = {
    attach: function (context, settings) {
      $(".plupload-element", context).once('ng_plupload-init', function () {
        $(this).pluploadQueue().bind('BeforeUpload', function(up, file) {
          // Remove any previous filename query strings and append the next one.
          up.settings.url = up.settings.url.replace(/([?&])filename=[^&]+/, '');
          up.settings.url += (up.settings.url.match(/[?]/) ? '&filename=' : '?filename=') + file.name;
      });
    });
  }
};

})(jQuery);