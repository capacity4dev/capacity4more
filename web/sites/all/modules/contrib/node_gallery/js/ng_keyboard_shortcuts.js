/**
 * @file
 * jQuery-based keyboard shortcuts.
 */
(function($) {

  Drupal.behaviors.initKeyboardShortcuts = {
    attach: function (context, settings) {
      $(document).keydown(function(event) {
        if (event.which == '37') {
          // left arrow
          if ($('td.item-navigator-prev a').length > 0) {
            window.location.href = $('td.item-navigator-prev a').attr('href');
          }
        }
        if (event.which == '39') {
          // right arrow
          if ($('td.item-navigator-next a').length > 0) {
            window.location.href = $('td.item-navigator-next a').attr('href');
          }
        }
      });
    }
  };


})(jQuery);