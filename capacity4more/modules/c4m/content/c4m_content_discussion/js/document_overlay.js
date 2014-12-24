(function ($) {

  $(document).bind('drupalOverlayLoad', function() {
  });

  $(document).on('click', function(event) {

    var $target = $(event.target);
    console.log($target);
    if ($target.is('a')) {
      var target = $target[0];
      var parents = $target.parents();
      var nids = [];
      $.each( parents, function( index, value ){
        var id = value.id;
        if (id.indexOf('node-') != -1 && id.match(/[0-9]/g)) {
          var nid = id.replace(/\D/g, '');
          nids.push(nid);
        }
      });
      nids.reverse();

      console.log(nids[0]);
      $('#edit-c4m-related-document-und-0-target-id', parent.window.document).val('(' + nids[0] + ')');
      parent.Drupal.overlay.close();
    }


  });

})(jQuery);
