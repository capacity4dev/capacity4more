/**
 * @file
 * Add captcha validation.
 */

var Drupal = Drupal || {};
var jQuery = jQuery || {};

(function ($) {
    "use strict";

    Drupal.behaviors.c4m_captcha = {
        attach: function (context) {
            var arrayLength = Drupal.settings.c4m_captcha_forms.length;
            var i = 0;
            var formId;

            while (i < arrayLength) {
                formId = "#" + Drupal.settings.c4m_captcha_forms[i].replace(/_/g, "-");
                $(formId, context).submit((function (event) {
                    var $captcha_error = $(".captcha_error", this);

                    // @todo Make sure to allow multiple captcha forms in one page.
                    if (!captcha.captchaObjects[0].validateCaptcha()) {
                        $captcha_error.removeClass("hidden").prev().addClass("has-error");
                        event.preventDefault();
                    }
                    else {
                        $captcha_error.addClass("hidden").prev().removeClass("has-error");
                    }
                }));

                i++;
            }
        }
    };
})(jQuery);
