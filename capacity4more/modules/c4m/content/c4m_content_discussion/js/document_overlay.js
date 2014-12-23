(function ($) {

  $(document).bind('drupalOverlayLoad', function() {
  });

  $(document).on('click', function(event) {

    var $target = $(event.target);
    console.log($target);
    if ($target.is('a')) {
      var target = $target[0];
      var parents = $target.parents();
      console.log(parents);
      // array_reverse(parents)
      //find the first element with id like 'node-'+id
      // send id to the parent document.
      $('#edit-c4m-related-document-und-0-target-id', parent.window.document).val('we are here');
      parent.Drupal.overlay.close();
    }


  });

})(jQuery);
