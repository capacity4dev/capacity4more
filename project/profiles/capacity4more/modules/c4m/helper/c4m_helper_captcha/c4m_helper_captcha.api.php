<?php

/**
 * @file
 * Hooks provided by the c4m_helper_captcha module.
 */

/**
 * Defines forms with captcha.
 */
function hook_c4m_captcha_form_info() {
  return array(
    'user_register_form',
  );
}
