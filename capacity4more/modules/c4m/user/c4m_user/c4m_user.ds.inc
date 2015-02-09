<?php
/**
 * @file
 * c4m_user.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_user_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|c4m_user_teaser_list';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'c4m_user_teaser_list';
  $ds_fieldsetting->settings = array(
    'c4m_media' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['user|user|c4m_user_teaser_list'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_user_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|c4m_user_teaser_list';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'c4m_user_teaser_list';
  $ds_layout->layout = 'c4m_ds_2col_icon_left';
  $ds_layout->settings = array(
    'regions' => array(
      'right' => array(
        0 => 'c4m_first_name',
        1 => 'c4m_last_name',
        2 => 'og_user_node',
        3 => 'c4m_organisation',
        5 => 'c4m_country',
      ),
      'left' => array(
        4 => 'c4m_media',
      ),
    ),
    'fields' => array(
      'c4m_first_name' => 'right',
      'c4m_last_name' => 'right',
      'og_user_node' => 'right',
      'c4m_organisation' => 'right',
      'c4m_media' => 'left',
      'c4m_country' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['user|user|c4m_user_teaser_list'] = $ds_layout;

  return $export;
}
