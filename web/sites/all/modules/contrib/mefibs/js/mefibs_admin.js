/**
 * @file
 * Handles AJAX fetching of views, including filter submission and response.
 */
(function ($) {

Drupal.MefibsAdmin = {};

Drupal.behaviors.MefibsAdmin = {};
Drupal.behaviors.MefibsAdmin.attach = function(context, settings) {
  
  // Only act on the mefibs edit display form.
  if ($('#mefibs-display-extender-blocks-wrapper', context).length == 0) {
    return;
  }
  
  var wrapper = $('#mefibs-display-extender-blocks-wrapper', context);
  Drupal.MefibsAdmin.buttons = $('input[type=submit]', wrapper).once('mefibs-buttons');
  if (Drupal.MefibsAdmin.buttons.length) {
    new Drupal.MefibsAdmin.replaceButtons(Drupal.MefibsAdmin.buttons);
  }
};

Drupal.MefibsAdmin.replaceButtons = function(buttons) {
  
  // Find each button, hide it and insert a link next to it.
  var length = buttons.length;
  for (i = 0; i < length; i++) {
    var $button = $(buttons[i]);
    $button.hide();
    var buttonId = $button.attr('id');
    $('<a href="#" class="mefibs-button-link">' + $button.val() + '</a>')
      .insertBefore($button)
      // When the link is clicked, dynamically click the corresponding form
      // button.
      .once('mefibs-option-form-button')
      .bind('click.mefibs-option-form-button', {buttonId: buttonId}, $.proxy(this, 'clickButton'));
  }
  
};

Drupal.MefibsAdmin.replaceButtons.prototype.clickButton = function (event) {
  // Due to conflicts between Drupal core's AJAX system and the Views AJAX
  // system, the only way to get this to work seems to be to trigger both the
  // .mousedown() and .submit() events.
  // @see views/js/views-admin.js
  // Drupal.viewsUi.rearrangeFilterHandler.prototype.clickAddGroupButton
  $('input#' + event.data.buttonId).mousedown();
  $('input#' + event.data.buttonId).submit();
  return false;
};

})(jQuery);
