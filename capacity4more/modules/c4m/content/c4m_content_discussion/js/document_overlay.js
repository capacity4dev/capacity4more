(function ($) {

  $(document).bind('drupalOverlayLoad', function() {
    // Populate the entity reference field with the selected node ID.
//    $('.page-title', parent.window.document).hide();

    console.log(Drupal.overlay);

  });

  $(document).bind('click', function(event) {
    console.log(parent.Drupal.overlay);
    console.log(event.target);
    $('#edit-field-test-field-und-0-target-id',parent.window.document).val('we are here');
    parent.Drupal.overlay.close();
  });

})(jQuery);
