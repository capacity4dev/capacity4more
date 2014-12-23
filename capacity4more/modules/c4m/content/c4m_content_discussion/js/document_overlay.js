(function ($) {

  $(document).bind('drupalOverlayLoad', function() {
    // Populate the entity reference field with the selected node ID.
    $('.page-title', parent.window.document).hide();
  });

  Drupal.overlay.eventhandlerDocumentChosen = function (event) {
    if (event.type == 'click') {
      $('#edit-c4m-related-document-und-0-target-id').val('we are here');
      $.bbq.removeState('overlay');
      return;
    }
  }
})(jQuery);
