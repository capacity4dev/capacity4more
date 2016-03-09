/**
 * @file
 * Handles AJAX fetching of views, including filter submission and response.
 */
(function ($) {

Drupal.behaviors.MefibsForm = {};
Drupal.behaviors.MefibsForm.views_settings = new Array();
Drupal.behaviors.MefibsForm.attach = function(context, settings) {

  if (!settings.mefibs) {
    return;
  }
  if (settings && settings.views && settings.views.ajaxViews) {
    $.each(settings.views.ajaxViews, function(i, ajax_settings) {
      $.each(settings.mefibs.forms, function(index, mefibs) {
        if (ajax_settings.view_name == mefibs.view_name && ajax_settings.view_display_id == mefibs.view_display_id) {
          Drupal.behaviors.MefibsForm.views_settings[mefibs.form_prefix] = ajax_settings;
          var settings_copy = jQuery.extend({}, ajax_settings);
          settings_copy.view_display_id = [mefibs.view_display_id, mefibs.form_prefix].join('-');
          instance = new Drupal.views.ajaxView(settings_copy);
          instance.$exposed_form.find('input,select,checkbox,radio').each(function() {
            var name = $(this).attr('name');
            if (name && name.indexOf(mefibs.form_prefix) == -1 && name != mefibs.form_prefix.replace('-', '_')) {
              $(this).attr('name', mefibs.form_prefix + '-' + name);
            }
          });
        }
      });
    });
  }
};

if (Drupal.ajax) {
  /**
   * Modify form values prior to form submission.
   */
  Drupal.ajax.prototype.beforeSubmit = function(form_values, element, options) {

    var view_name = view_display_id = view_args = '';
    var view_display_id_key = 0;
    $.each(form_values, function(key, item) {
      if (item.name == 'view_name') {
        view_name = item.value;
      }
      if (item.name == 'view_args') {
        view_args_key = key;
      }
      if (item.name == 'view_display_id') {
        view_display_id = item.value;
        view_display_id_key = key;
      }

      if (view_name != '' && view_display_id != '' && view_args != '') {
        return false;
      }
    });

    // clean the display id so that views will actually respond
    $.each(Drupal.settings.mefibs.forms, function(index, mefibs) {
      if (view_name == mefibs.view_name && (view_display_id == ([mefibs.view_display_id, mefibs.form_prefix].join('-')))) {
        form_values[view_display_id_key].value = mefibs.view_display_id;
        form_values[view_args_key].value = Drupal.behaviors.MefibsForm.views_settings[mefibs.form_prefix].view_args;
      }
    });
  };
}

})(jQuery);
