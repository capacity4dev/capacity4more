(function ($) {

  $(document).on('click', function(event) {
    var $target = $(event.target);
    // Click on the title of the node in the overlay page.
    if ($target.is('a') && $target.parent().is('h2')) {
      var parents = $target.parents();
      var nids = [];
      $.each(parents, function(index, value) {
        var id = value.id;

        if (id.indexOf('node-') != -1 && id.match(/[0-9]/g)) {
          nids.push(value.id.replace(/\D/g, ''));
        }
      });

      nids.reverse();

      // Get the node id.
      var nid = nids[0] || 0;

      var item = '(' + nid + ')';

      // Put values in the hidden inputs in the parent page.
      var value = $('#edit-c4m-related-document-und', parent.window.document).val();
      var ids = $('#related-documents', parent.window.document).val();
      if (value.indexOf(item) == -1) {
        value = value ? value + ', ' + item : item;
        ids = ids ? ids + ',' + nid : nid;
      }
      $('#edit-c4m-related-document-und', parent.window.document).val(value);
      $('#related-documents', parent.window.document).val(ids).trigger('click');

      // Close verlay.
      parent.Drupal.overlay.close();
    }
    else if ($target.is('button') && $target.val() == 'Delete') {
      // We are on the node/edit page in the overlay. On click on the "Delete"
      // button should remove the node id from inputs on the parent page.

      var value = $('#edit-c4m-related-document-und', parent.window.document).val();
      var ids = $('#related-documents', parent.window.document).val();

      value = value.split(',').slice(0, -1).join();

      ids = ids.split(',').slice(0, -1).join();

      $('#edit-c4m-related-document-und', parent.window.document).val(value);
      $('#related-documents', parent.window.document).val(ids).trigger('click');

      parent.Drupal.overlay.close();

    }

  });

  // Catch url changing. If needed - close the overlay.
  $(parent.window).bind('hashchange', function() {
    if (parent) {
      if (parent.window.location.hash.indexOf('close_overlay') != -1) {
        parent.Drupal.overlay.close();
      }
    }
  });

})(jQuery);


