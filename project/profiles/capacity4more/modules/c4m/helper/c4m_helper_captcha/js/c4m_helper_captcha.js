/**
 * @file
 * Add captcha validation.
 */

(function ($) {
  Drupal.behaviors.c4m_captcha = {
    attach: function(context) {
      var arrayLength = Drupal.settings.c4m_captcha_forms.length;
      for (var i = 0; i < arrayLength; i++) {
        var formId = '#' + Drupal.settings.c4m_captcha_forms[i].replace(/_/g, '-');
        $(formId, context).submit(function(event) {
          // @todo Make sure to allow multiple captcha forms in one page.
          if (!captcha.captchaObjects[0].validateCaptcha()) {
            event.preventDefault();
          }
        });
      }
    }
  };
})(jQuery);
