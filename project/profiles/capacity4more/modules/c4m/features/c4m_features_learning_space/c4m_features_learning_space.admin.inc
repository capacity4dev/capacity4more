<?php
/**
 * @file
 * Admin forms.
 */

function c4m_features_learning_space_admin_settings($form) {
  $form['learning_image'] = array(
    '#type' => 'managed_file',
    '#name' => 'c4m_learning_space_image',
    '#title' => t('Upload Learning Space banner'),
    '#default_value' => variable_get('learning_image', ''),
    '#description' => t('Upload the banner image for the learning space page.'),
    '#required' => TRUE,
    '#theme' => 'c4m_features_learning_space_admin_image',
    '#upload_location' => 'public://learning_space/',
    '#upload_validators' => array(
      'file_validate_extensions' => array('gif png jpg jpeg'),
      'file_validate_image_resolution' => array(0, '960x300'),
    ),
  );

  $defaults = array(
    'value' => '',
    'format' => filter_default_format(),
  );
  $intro_text = variable_get('learning_intro', $defaults);

  $form['learning_intro'] = array(
    '#type' => 'text_format',
    '#title' => t('Introduction text'),
    '#default_value' => $intro_text['value'],
    '#format' => $intro_text['format'],
  );

  return system_settings_form($form);
}