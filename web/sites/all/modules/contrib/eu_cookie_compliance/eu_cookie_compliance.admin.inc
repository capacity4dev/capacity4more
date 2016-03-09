<?php
/**
 * @file
 * This file provides administration form for the module.
 */

/**
 * Provides form for cookie control popup.
 */
function eu_cookie_compliance_admin_form($form_state) {

  global $language;
  $ln = $language->language;
  $popup_settings = eu_cookie_compliance_get_settings();

  $form['eu_cookie_compliance_domain'] = array(
    '#type' => 'textfield',
    '#title' => t('Domain'),
    '#default_value' => variable_get('eu_cookie_compliance_domain', ''),
    '#description' => t('Sets the domain of the cookie to a specific url.  Used when you need consistency across domains.  This is language independent.'),
  );

  $form['eu_cookie_compliance_' . $ln] = array (
    '#type'  => 'item',
    '#tree'   => TRUE,
  );

  if (module_exists('locale')) {
    $form['eu_cookie_compliance_' . $ln]['#title'] = t('You are editing settings for the %language language.', array('%language' => $language->name));
  }

  $form['eu_cookie_compliance_' . $ln]['popup_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable popup'),
    '#default_value' => isset($popup_settings['popup_enabled']) ? $popup_settings['popup_enabled'] : 0,
  );

  $form['eu_cookie_compliance_' . $ln]['popup_clicking_confirmation'] = array(
    '#type' => 'checkbox',
    '#title' => t('Consent by clicking'),
    '#default_value' => isset($popup_settings['popup_clicking_confirmation']) ? $popup_settings['popup_clicking_confirmation'] : 1,
    '#description' => t('By default by clicking any link on the website the visitor accepts the cookie policy. Uncheck this box if you do not require this functionality. You may want to edit the pop-up message below accordingly.'),
  );

  if (module_exists('geoip') || module_exists('smart_ip')){
    $form['eu_cookie_compliance_' . $ln]['eu_only'] = array(
      '#type' => 'checkbox',
      '#title' => t('Only display popup in EU countries (using the <a href="http://drupal.org/project/geoip">geoip</a> module or the <a href="http://drupal.org/project/smart_ip">smart_ip</a> module)'),
      '#default_value' => isset($popup_settings['eu_only']) ? $popup_settings['eu_only'] : 0,
    );
  }

  $form['eu_cookie_compliance_' . $ln]['popup_position'] = array(
    '#type' => 'checkbox',
    '#title' => t('Place the pop-up at the top of the website'),
    '#default_value' => isset($popup_settings['popup_position']) ? $popup_settings['popup_position'] : 0,
    '#description' => t('By default the pop-up appears at the bottom of the website. Tick this box if you want it to appear at the top'),
  );

  $form['eu_cookie_compliance_' . $ln]['popup_agree_button_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Agree button message'),
    '#default_value' => isset($popup_settings['popup_agree_button_message']) ? $popup_settings['popup_agree_button_message'] : t('OK, I agree'),
    '#size' => 30,
    '#required' => TRUE,
  );

  $form['eu_cookie_compliance_' . $ln]['popup_disagree_button_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Disagree button message'),
    '#default_value' => isset($popup_settings['popup_disagree_button_message']) ? $popup_settings['popup_disagree_button_message'] : t('No, give me more info'),
    '#size' => 30,
    '#required' => TRUE,
  );

  $form['eu_cookie_compliance_' . $ln]['popup_info'] = array(
    '#type' => 'text_format',
    '#title' => t('Popup message - requests consent'),
    '#default_value' => isset($popup_settings['popup_info']['value']) ? $popup_settings['popup_info']['value'] : '',
    '#required' => TRUE,
    '#format' => isset($popup_settings['popup_info']['format']) ? $popup_settings['popup_info']['format'] : filter_default_format(),
  );

  $form['eu_cookie_compliance_' . $ln]['popup_agreed_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable thank you message'),
    '#default_value' => isset($popup_settings['popup_agreed_enabled']) ? $popup_settings['popup_agreed_enabled'] : 1,
  );

  $form['eu_cookie_compliance_' . $ln]['popup_hide_agreed'] = array(
    '#type' => 'checkbox',
    '#title' => t('Clicking hides thank you message'),
    '#default_value' => isset($popup_settings['popup_hide_agreed']) ? $popup_settings['popup_hide_agreed'] : 0,
    '#description' => t('Clicking a link hides the thank you message automatically.'),
  );

  $form['eu_cookie_compliance_' . $ln]['popup_find_more_button_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Find more button message'),
    '#default_value' => isset($popup_settings['popup_find_more_button_message']) ? $popup_settings['popup_find_more_button_message'] : t('More info'),
    '#size' => 30,
    '#required' => TRUE,
  );

  $form['eu_cookie_compliance_' . $ln]['popup_hide_button_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Hide button message'),
    '#default_value' => isset($popup_settings['popup_hide_button_message']) ? $popup_settings['popup_hide_button_message'] : t('Hide'),
    '#size' => 30,
    '#required' => TRUE,
  );

  $form['eu_cookie_compliance_' . $ln]['popup_agreed'] = array(
    '#type' => 'text_format',
    '#title' => t('Popup message - thanks for giving consent'),
    '#default_value' => isset($popup_settings['popup_agreed']['value']) ? $popup_settings['popup_agreed']['value'] : '',
    '#required' => TRUE,
    '#format' => isset($popup_settings['popup_agreed']['format']) ? $popup_settings['popup_agreed']['format'] : filter_default_format(),
  );

  $form['eu_cookie_compliance_' . $ln]['popup_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Privacy policy link'),
    '#default_value' => isset($popup_settings['popup_link']) ? $popup_settings['popup_link'] : '',
    '#size' => 60,
    '#maxlength' => 220,
    '#required' => TRUE,
    '#description' => t('Enter link to your privacy policy or other page that will explain cookies to your users. For external links prepend http://'),
  );

  $form['eu_cookie_compliance_' . $ln]['popup_link_new_window'] = array(
    '#type' => 'checkbox',
    '#title' => t('Open privacy policy link in a new window'),
    '#default_value' => isset($popup_settings['popup_link_new_window']) ? $popup_settings['popup_link_new_window'] : 1,
  );

  $form['eu_cookie_compliance_' . $ln]['popup_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Popup height in pixels'),
    '#default_value' => isset($popup_settings['popup_height']) ? $popup_settings['popup_height'] : '',
    '#size' => 5,
    '#maxlength' => 5,
    '#required' => FALSE,
    '#description' => t('Enter an integer value for a desired height in pixels or leave empty for automatically adjusted height. Do not set this value if you are using responsive theme.'),

  );

  $form['eu_cookie_compliance_' . $ln]['popup_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Popup width in pixels or a percentage value'),
    '#default_value' => isset($popup_settings['popup_width']) ? $popup_settings['popup_width'] : '100%',
    '#size' => 5,
    '#maxlength' => 5,
    '#required' => TRUE,
    '#description' => t('Set the width of the popup. This can be either an integer value or percentage of the screen width. For example: 200 or 50%'),
  );

  $form['eu_cookie_compliance_' . $ln]['popup_delay'] = array(
    '#type' => 'textfield',
    '#title' => t('Popup time delay in seconds'),
    '#default_value' => isset($popup_settings['popup_delay']) ? $popup_settings['popup_delay'] : 1,
    '#size' => 5,
    '#maxlength' => 5,
    '#required' => TRUE,
  );

  $form_color_picker_type = 'textfield';

  if (module_exists('jquery_colorpicker')) {
    $form_color_picker_type = 'jquery_colorpicker';
  }

  $form['eu_cookie_compliance_' . $ln]['popup_bg_hex'] = array(
    '#type' => $form_color_picker_type,
    '#title' => t('Background Color'),
    '#default_value' => isset($popup_settings['popup_bg_hex']) ? check_plain($popup_settings['popup_bg_hex']) : '0779BF', // Garland colors :)
    '#description' => t('Change the background color of the popup. Provide HEX value without the #'),
    '#element_validate' => array('eu_cookie_compliance_validate_hex'),
  );

  $form['eu_cookie_compliance_' . $ln]['popup_text_hex'] = array(
    '#type' => $form_color_picker_type,
    '#title' => t('Text Color'),
    '#default_value' => isset($popup_settings['popup_text_hex']) ? check_plain($popup_settings['popup_text_hex']) : 'ffffff',
    '#description' => t('Change the text color of the popup. Provide HEX value without the #'),
    '#element_validate' => array('eu_cookie_compliance_validate_hex'),
  );
  // Adding option to add/remove popup on specified domains
  $exclude_domains_option_active = array(
    0 => t('Add'),
    1 => t('Remove'),
  );
  $form['eu_cookie_compliance_' . $ln]['domains_option'] = array(
    '#type' => 'radios',
    '#title' => t('Add/Remove popup on specified domains'),
    '#default_value' => isset($popup_settings['domains_option']) ? $popup_settings['domains_option'] : 1,
    '#options' => $exclude_domains_option_active,
    '#description' => t("Specify if you want to add or remove popup on the listed below domains."),
  );
  $form['eu_cookie_compliance_' . $ln]['domains_list'] = array(
    '#type' => 'textarea',
    '#title' => t('Domains list'),
    '#default_value' => isset($popup_settings['domains_list']) ? $popup_settings['domains_list'] : '',
    '#description' => t("Specify domains with protocol (e.g. http or https). Enter one domain per line."),
  );

  $form['eu_cookie_compliance_' . $ln]['exclude_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Exclude paths'),
    '#default_value' => isset($popup_settings['exclude_paths']) ? $popup_settings['exclude_paths'] : '',
    '#description' => t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>')),
  );


  return system_settings_form($form);
}

/**
 * Validates form for cookie controll popup.
 */
function eu_cookie_compliance_admin_form_validate($form, &$form_state) {
  global $language;
  $ln = $language-> language;
  if (!preg_match('/^[1-9][0-9]{0,4}$/', $form_state['values']['eu_cookie_compliance_' . $ln]['popup_height']) && !empty($form_state['values']['eu_cookie_compliance_' . $ln]['popup_height'])) {
    form_set_error('eu_cookie_compliance_' . $ln . '][popup_height', t('Height must be an integer value .'));
  }
  if (!preg_match('/^[1-9][0-9]{0,4}$/', $form_state['values']['eu_cookie_compliance_' . $ln]['popup_delay'])) {
    form_set_error('eu_cookie_compliance_' . $ln . '][popup_delay', t('Delay must be an integer value.'));
  }
  if (!preg_match('/^[1-9][0-9]{0,4}\%?$/', $form_state['values']['eu_cookie_compliance_' . $ln]['popup_width'])) {
    form_set_error('eu_cookie_compliance_' . $ln . '][popup_width', t('Width must be an integer or a percentage value.'));
  }
  $popup_link = $form_state['values']['eu_cookie_compliance_' . $ln]['popup_link'];
  //if the link contains a fragment then check if it validates then rewrite link with full url
  if ((strpos($popup_link, '#') !== FALSE) && (strpos($popup_link, 'http') === FALSE)) {
    $fragment = explode('#', $popup_link);
    $popup_link = url($fragment[0], array('fragment' => $fragment[1], 'absolute' => TRUE));
    form_set_error('eu_cookie_compliance_' . $ln . '][popup_link', t('Looks like your privacy policy link contains fragment #, you should make this an absolute url eg @link', array('@link' => $popup_link)));
  }

  cache_clear_all('eu_cookie_compliance_client_settings_' . $language->language, 'cache');
}

/**
 * Validate field for a HEX value if a value is set
 */
function eu_cookie_compliance_validate_hex($element, &$form_state) {
  if (!empty($element['#value']) && !preg_match('/^[0-9a-fA-F]{3,6}$/', $element['#value'])) {
    form_error($element, t('%name must be a HEX value (without leading #) or empty.', array('%name' => $element['#title'])));
  }
}
