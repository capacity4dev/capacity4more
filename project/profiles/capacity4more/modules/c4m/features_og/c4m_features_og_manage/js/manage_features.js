/**
 * @file
 * Improve UX to enable/disable features.
 */

(function ($) {

  Drupal.behaviors.c4mOgFeatureFilter = {
    attach: function (context) {
      $('.form-type-checkbox').each(function (i) {
        var $cell = $(this);
        var $checkbox = $(':checkbox', $cell);
        var $state = 'off';
        if ($checkbox.is(":checked")) {
          $state = 'on enabled';
        }
        $cell.prepend('<div class="toggle-enable ' + $state + '"><div>&nbsp;</div></div>', $cell);
        var $switch = $('.toggle-enable', $cell);
        $switch.click(function () {
          $checkbox.click();
        });
        $checkbox.click(function () {
          $switch.toggleClass('off');
        });
      });
    }
  };

})(jQuery);
