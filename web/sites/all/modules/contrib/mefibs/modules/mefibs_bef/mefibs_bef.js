/**
 * @file
 * Handles AJAX fetching of views, including filter submission and response.
 */
(function ($) {

// This makes sure, that the selected class is properly set on the links when
// using the options select-as-links.
Drupal.behaviors.MefibsBEFForm = {
  attach: function(context, settings) {
    $(context).each(function(index, el) {
      $('.bef-select-as-links', el).each(function() {
        if (!$(this).find('select').length) {
          return;
        }
        var selected = $(this).find('select').val().toLowerCase().replace(/_/g, '-').replace(/ /g, '-');
        if (typeof selected == 'undefined') {
          return;
        }
        var select_id = $(this).find('select').attr('id').toLowerCase().replace(/_/g, '-').replace(/ /g, '-');
        $(this).find('.form-item').removeClass('selected');
        $(this).find('#' + select_id + '-' + selected).addClass('selected');
      });
    });

    // Support for sliders in mefibs blocks.
    if (settings.mefibs) {
      if (typeof Drupal.settings.better_exposed_filters.slider_options != 'undefined') {
        var new_sliders = [];        
        $.each(settings.mefibs.forms, function(block_id, mefibs) {
          $.each(settings.better_exposed_filters.slider_options, function(element_id, slider) {

            var expected_id = ("views-exposed-form-" + mefibs.view_name + "-" + mefibs.view_display_id).replace(/_/g, '-');
            var element_wrapper = ('edit-' + element_id + '-wrapper').replace(/_/g, '-');
            var original_element = ('#' + element_wrapper + ' > .views-widget > div');
            var original_slider = ('#' + element_wrapper + ' .bef-slider').replace(/_/g, '-');

            if ($.inArray(element_id, mefibs.elements) == -1) {
              // Remove the old slider from the form.
              if ($(original_slider, original_element).length) {
                $(original_slider, original_element).slider('destroy');
                $(element_wrapper, original_element).remove();
              }
              return;
            }

            if (expected_id != slider.viewId) {
              return;
            }

            var new_slider = $.extend({}, slider);

            if (block_id != 'default') {
              new_slider.id = mefibs.form_prefix + '-' + new_slider.id;
              new_slider.viewId = ("views-exposed-form-" + mefibs.view_name + "-" + mefibs.view_display_id + "-" + mefibs.form_prefix).replace(/_/g, '-');
            }

            new_sliders.push(new_slider);

            // Remove the old slider from the form.
            if (block_id != 'default' && $(original_slider, context).length) {
              $(original_slider, context).slider('destroy');
              $(element_wrapper, context).remove();
            }
            delete Drupal.settings.better_exposed_filters.slider_options[element_id];
          });
        });
        $.each(new_sliders, function(i, slider) {
          Drupal.settings.better_exposed_filters.slider_options[slider.id] = slider;
        });
        Drupal.behaviors.better_exposed_filters_slider.attach(context, Drupal.settings);
      }
    }
  }
};

})(jQuery);
