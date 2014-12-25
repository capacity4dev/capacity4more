(function ($) {

  $(document).bind('drupalOverlayLoad', function() {
  });

  $(document).on('click', function(event) {
    var $target = $(event.target);
    if ($target.is('a') && $target.parent().is('h2')) {
      var target = $target[0];
      var parents = $target.parents();
      var elements = [];
      $.each(parents, function(index, value) {
        var id = value.id;

        if (id.indexOf('node-') != -1 && id.match(/[0-9]/g)) {
          elements.push(value);
        }
      });

      elements.reverse();

      var nid = elements[0] ? elements[0].id.replace(/\D/g, '') : 0;

      var title = $('#' + elements[0].id, window.document).find('[property="dc:title"]')[0];

      var $title = $(title);
      var label = $title.attr('content') ? $title.attr('content') : 'Property title is not found';

      var item = label + ' (' + nid + ')';

//      for multiple values.
      var value = $('#edit-c4m-related-document-und', parent.window.document).val();
      if (value.indexOf(item) == -1) {
        value = value ? value + ', ' + item : item;
      }

      $('#edit-c4m-related-document-und', parent.window.document).val(value);
      parent.Drupal.overlay.close();
    }


  });

})(jQuery);
