/**
 * @file
 * Add captcha validation.
 */

(function ($) {
  Drupal.behaviors.c4m_captcha = {
    attach: function(context) {
      $('.captcha').bind('DOMSubtreeModified', function() {
        $('#security_code', this).addClass('form-control');
      });
      var arrayLength = Drupal.settings.c4m_captcha_forms.length;
      for (var i = 0; i < arrayLength; i++) {
        var formId = '#' + Drupal.settings.c4m_captcha_forms[i].replace(/_/g, '-');
        $(formId, context).submit(function(event) {
          var $captcha_error = $('.captcha_error', this);

          // @todo Make sure to allow multiple captcha forms in one page.
          if (!captcha.captchaObjects[0].validateCaptcha()) {
            $captcha_error.removeClass('hidden').prev().addClass('has-error');
            event.preventDefault();
          }
          else {
            $captcha_error.addClass('hidden').prev().removeClass('has-error');
          }
        });
      }
    }
  };
})(jQuery);
