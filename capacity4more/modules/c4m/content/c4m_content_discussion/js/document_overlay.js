(function ($) {

  $(document).bind('drupalOverlayLoad', function() {
  });

  $(document).bind('click', function(event) {
    console.log(parent.Drupal.overlay);
    console.log(event.target);
    $('#edit-c4m-related-document-und-0-target-id', parent.window.document).val('we are here');
    parent.Drupal.overlay.close();
  });

})(jQuery);
