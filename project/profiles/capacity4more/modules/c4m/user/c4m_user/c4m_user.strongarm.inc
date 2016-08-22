<?php
/**
 * @file
 * c4m_user.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_user_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_user__user';
  $strongarm->value = array(
    'view_modes' => array(
      'c4m_user_teaser_list' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'c4m_user_teaser_table' => array(
        'custom_settings' => TRUE,
      ),
      'c4m_user_picture' => array(
        'custom_settings' => TRUE,
      ),
      'c4m_user_teaser_list_global' => array(
        'custom_settings' => TRUE,
      ),
      'c4m_user_teaser_table_global' => array(
        'custom_settings' => TRUE,
      ),
      'block_list' => array(
        'custom_settings' => TRUE,
      ),
      'user_picture' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'ckeditor' => array(
          'weight' => '8',
        ),
        'mimemail' => array(
          'weight' => '4',
        ),
        'redirect' => array(
          'weight' => '11',
        ),
        'account' => array(
          'weight' => '-100',
        ),
        'timezone' => array(
          'weight' => '7',
        ),
        'contact' => array(
          'weight' => '3',
        ),
      ),
      'display' => array(
        'summary' => array(
          'default' => array(
            'weight' => '11',
            'visible' => FALSE,
          ),
          'c4m_user_teaser_list' => array(
            'weight' => '19',
            'visible' => FALSE,
          ),
          'c4m_user_picture' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'c4m_user_teaser_table' => array(
            'weight' => '21',
            'visible' => FALSE,
          ),
          'c4m_user_teaser_list_global' => array(
            'weight' => '17',
            'visible' => FALSE,
          ),
          'c4m_user_teaser_table_global' => array(
            'weight' => '23',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '26',
            'visible' => FALSE,
          ),
          'block_list' => array(
            'weight' => '38',
            'visible' => FALSE,
          ),
          'user_picture' => array(
            'weight' => '11',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '38',
            'visible' => FALSE,
          ),
        ),
        'mimemail' => array(
          'c4m_user_teaser_table' => array(
            'weight' => '14',
            'visible' => FALSE,
          ),
          'c4m_user_teaser_list' => array(
            'weight' => '13',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'c4m_user_teaser_list_global' => array(
            'weight' => '18',
            'visible' => FALSE,
          ),
          'c4m_user_teaser_table_global' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '20',
            'visible' => FALSE,
          ),
          'block_list' => array(
            'weight' => '34',
            'visible' => FALSE,
          ),
          'user_picture' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '34',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_user__user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_403';
  $strongarm->value = 'access-denied';
  $export['site_403'] = $strongarm;

  return $export;
}
