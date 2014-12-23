(function ($) {

  console.log('outside');

  Drupal.overlay.eventhandlerDocumentChosen = function (event) {
    alert('hello');
    if (event.type == 'click') {
      $('#edit-c4m-related-document-und-0-target-id').val('we are here');
      $.bbq.removeState('overlay');
      return;
    }
  }
})(jQuery);
