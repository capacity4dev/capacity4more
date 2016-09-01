<?php

/**
 * @file
 * Platform administrator pages.
 */

/**
 * Form definition for admins to manage the disclaimer text.
 */
function c4m_admin_manage_disclaimer_form($form, $form_state) {
  $form['c4m_content_article_disclaimer'] = array(
    '#title' => t('Disclaimer text'),
    '#type' => 'textarea',
    '#default_value' => variable_get('c4m_content_article_disclaimer', 'DISCLAIMER: This information is provided in the interests of knowledge sharing and capacity development and should not be interpreted as the official view of the European Commission, or any other organisation.'),
  );

  return system_settings_form($form);
}
