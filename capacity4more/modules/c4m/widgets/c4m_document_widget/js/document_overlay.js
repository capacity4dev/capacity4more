/**
 * @file
 * Document overlay widget behaviour.
 */

(function ($) {

  $(document).on('click', function(event) {

    // Need to get current field name.
    var element = $('.active-library-link', parent.window.document);

    var fieldName = element.attr('id');
    fieldName = fieldName.replace('link-', '');

    // Get the element that was clicked.
    var $target = $(event.target);

    if ($target.is('button') && $target.val() == 'Delete') {
      // We are on the node/edit page in the overlay. On click on the "Delete"
      // button should remove the node id from inputs on the parent page.
      var value = $('#edit-' + fieldName + '-und', parent.window.document).val();
      var ids = $('#input-' + fieldName, parent.window.document).val();

      value = value.split(',').slice(0, -1).join();

      ids = ids.split(',').slice(0, -1).join();

      $('#edit-' + fieldName + '-und', parent.window.document).val(value);
      $('#input-' + fieldName, parent.window.document).val(ids).trigger('click');

      parent.Drupal.overlay.close();
    }

    // Click on the node in the library overlay page.
    var parents = $target.parents();
    var nids = [];
    // Find the parent element with node id in the element's id.
    $.each(parents, function(index, value) {
      var id = value.id;

      if (id.indexOf('node-') != -1 && id.match(/[0-9]/g)) {
        nids.push(value.id.replace(/\D/g, ''));
      }
    });

    // Node id was not found.
    if (!nids[0]) {
      return;
    }
    // More then one were found. Take the main one.
    nids.reverse();
    var nid = nids[0];

    // Prepare the values for the widget input.
    var item = '(' + nid + ')';

    // Put values in the hidden inputs in the parent page.
    var value = $('#edit-' + fieldName + '-und', parent.window.document).val();
    var ids = $('#input-' + fieldName, parent.window.document).val();
    if (value.indexOf(item) == -1) {
      value = value ? value + ', ' + item : item;
      ids = ids ? ids + ',' + nid : nid;
    }
    $('#edit-' + fieldName + '-und', parent.window.document).val(value);
    $('#input-' + fieldName, parent.window.document).val(ids).trigger('click');
    // Close verlay.
    parent.Drupal.overlay.close();
  });

  // Catch url changing. If close_overlay appeared - close the overlay.
  $(parent.window).bind('hashchange', function() {
    if (parent) {
      if (parent.window.location.hash.indexOf('close_overlay') != -1) {
        parent.Drupal.overlay.close();
      }
    }
  });

})(jQuery);
