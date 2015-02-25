<?php
/**
 * @file
 * Information about custom DS layouts.
 */

/**
 * Implements hook_ds_layout_info().
 */
function c4m_ds_ds_layout_info() {
  $path = drupal_get_path('module', 'c4m_ds');
  $path .= '/layouts';

  $layouts = array();

  // Details of the layouts.
  $layouts['c4m_ds_3_9_fluid'] = array(
    'label'   => t('Fluid 3-9 unstacked.'),
    'path'    => $path . '/c4m_ds_3_9_fluid',
    'regions' => array(
      'left'  => t('Left'),
      'right' => t('Right'),
    ),
    'form'    => TRUE,
    'image'   => FALSE,
  );

  $layouts['c4m_ds_4_8_fluid'] = array(
    'label'   => t('Fluid 4-8 unstacked.'),
    'path'    => $path . '/c4m_ds_4_8_fluid',
    'regions' => array(
      'left'  => t('Left'),
      'right' => t('Right'),
    ),
    'form'    => TRUE,
    'image'   => TRUE,
  );

  $layouts['c4m_ds_8_4_fluid'] = array(
    'label'   => t('Fluid 8-4 unstacked.'),
    'path'    => $path . '/c4m_ds_8_4_fluid',
    'regions' => array(
      'left'  => t('Left'),
      'right' => t('Right'),
    ),
    'form'    => TRUE,
    'image'   => TRUE,
  );

  $layouts['c4m_ds_2col_icon_left'] = array(
    'label'   => t('Two columns with the content icon left.'),
    'path'    => $path . '/c4m_ds_2col_icon_left',
    'regions' => array(
      'left'  => t('Icon'),
      'right' => t('Content'),
    ),
    'form'    => TRUE,
    'image'   => TRUE,
  );

  $layouts['c4m_ds_3col_icon_left'] = array(
    'label'   => t('Three columns with the content icon left.'),
    'path'    => $path . '/c4m_ds_3col_icon_left',
    'regions' => array(
      'left'  => t('Icon'),
      'middle' => t('Content middle'),
      'right' => t('Content right'),
    ),
    'form'    => TRUE,
    'image'   => TRUE,
  );

  $layouts['c4m_ds_4col_table_vbo'] = array(
    'label'   => t('Fluid 4 columns with space on the left for a bulk operation checkbox.'),
    'path'    => $path . '/c4m_ds_4col_table_vbo',
    'regions' => array(
      'first' => t('First'),
      'second' => t('Second'),
      'third' => t('Third'),
      'fourth' => t('Fourth'),
    ),
    'form'    => TRUE,
    'image'   => TRUE,
  );

  return $layouts;
}
