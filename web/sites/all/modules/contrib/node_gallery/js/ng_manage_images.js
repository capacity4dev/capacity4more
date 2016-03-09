/**
 * @file
 * jQuery additions to manage images page.
 */
(function($) {

/**
 * Image rotation preview.
 */
Drupal.theme.prototype.nodeGalleryRotateDialog = function (filepath) {
  var output = '';
  output += '<img src="' + filepath + '" class="node-gallery-api-rotate-90" />';
  output += '<img src="' + filepath + '" class="node-gallery-api-rotate-180" />';
  output += '<img src="' + filepath + '" class="node-gallery-api-rotate-270" />';
  return output;
};

Drupal.theme.prototype.nodeGalleryRotationChangedWarning = function () {
  return '<div id="node-gallery-rotation-changed-warning" class="tabledrag-changed-warning messages warning">* ' + Drupal.t("Changes made in this table will not be saved until the form is submitted.") + '</div>';
};

Drupal.behaviors.nodeGalleryRotateImagePreview = {};
Drupal.behaviors.nodeGalleryRotateImagePreview.attach = function (context) {
  var self = this;
  self.changed = false;
  this.link = undefined;

  var buttonOk = function () {
    var selected = $('#node-gallery-rotate-dialog .selected').attr('class');
    if (typeof selected != 'undefined') {
      var degrees = selected.match(/node-gallery-api-rotate-([0-9]+)/);
      self.link.parent().find(':input:radio[id$="'+degrees[1]+'"]').attr('checked', true).click();
      self.link.parent().find(':input:hidden').val(degrees[1]).click();
    }
    self.dialog.dialog("close");
  };

  var _buttons = {};
  _buttons[Drupal.t('Ok')] = buttonOk;
  _buttons[Drupal.t('Cancel')] = function () {self.dialog.dialog("close");};
  if ($('a.node-gallery-api-rotate-link', context).length > 0) {
    this.dialog = $('<div id="node-gallery-rotate-dialog"></div>')
      .dialog({
        autoOpen: false,
        modal: true,
        resizable: true,
        title: 'Rotate image',
        width: 500,
        height: 300,
        minWidth: 500,
        minHeight: 300,
        buttons: _buttons
      });
  }
  $('a.node-gallery-api-rotate-link', context).each(function () {
    $(this).click(function () {
      self.link = $(this);
      self.dialog.html(Drupal.theme('nodeGalleryRotateDialog', $(this).attr('rel'))).dialog('open');
      $('#node-gallery-rotate-dialog img').each( function () {
        $(this).click(function () {
          $(this).addClass('selected').siblings('.selected').removeClass('selected');
        })
      });
      return false;
    });
  });
  $(':input[name$="\[rotate\]"]', context).click(function() {
        $(this).parents('tr:first').find('.file img').removeClass().addClass('node-gallery-api-rotate-'+$(this).val());
        if (self.changed == false) {
          $(Drupal.theme('nodeGalleryRotationChangedWarning')).insertBefore($(this).parents('table')).hide().fadeIn('slow');
          self.changed = true;
        }
  });
  $(':input:radio[name^="images"][name$="\[rotate\]"]', context).each(function () {
    if ($(this).val() == "0") {
      $(this).attr('checked', 'checked');
    }
  });
};

})(jQuery);
