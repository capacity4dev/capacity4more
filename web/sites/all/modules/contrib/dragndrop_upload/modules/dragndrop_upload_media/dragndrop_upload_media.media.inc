<?php

/**
 * @file
 * Media module integration for the Drag & Drop Upload module.
 * 
 * Adds "Multiple upload" plugin to the Media browser.
 * Alters "Upload" plugin to make it work with Drag & Drop Upload.
 */

/**
 * Implements hook_media_browser_plugin_info().
 */
function dragndrop_upload_media_media_browser_plugin_info() {
  $plugins = array();

  // Add multiupload plugin if "Multiupload Filefield Widget" exists.
  if (module_exists('dragndrop_upload_multi')) {
    if (user_access('administer media') || user_access('edit media')) {
      $plugins['mfw_multiupload'] = array(
        '#weight' => -10,
      );
    }
  }
  return $plugins;
}

/**
 * Implements hook_media_browser_plugin_view().
 */
function dragndrop_upload_media_media_browser_plugin_view($plugin_name, $params) {
  switch ($plugin_name) {
    case 'mfw_multiupload':
      $upload_form = drupal_get_form(
        'dragndrop_upload_media_add_mfw_multiupload',
        $params
      );
      return array(
        '#title' => t('Multiple upload'),
        'form' => array($upload_form),
      );
      break;
  }

  return array();
}

/**
 * Form callback for adding media via an upload form.
 */
function dragndrop_upload_media_add_mfw_multiupload($form, &$form_state, $params = array()) {
  module_load_include('pages.inc', 'media', 'includes/media');
  $form += media_add_upload($form, $form_state, $params);

  // Determine what URI scheme this file should use.
  $scheme = !empty($params['uri_scheme']) && file_stream_wrapper_valid_scheme(
    $params['uri_scheme']
  ) ? $params['uri_scheme'] : file_default_scheme();
  $scheme .= '://';

  // Prepare the file's subdirectory path.
  $directory = '';
  if (!empty($params['file_directory'])) {
    $directory = token_replace($params['file_directory']) . '/';

    // If the directory isn't writable, or doesn't exist and can't be created,
    // the upload will fail.
    $prepare_directory = file_stream_wrapper_uri_normalize(
      $scheme . $directory
    );
    if (!file_prepare_directory($prepare_directory, FILE_CREATE_DIRECTORY)) {
      drupal_set_message(
        t(
          'The file directory @dir does not exist or is not writable. Please contact an administrator.',
          array('@dir' => $prepare_directory)
        ),
        'error'
      );
      return array();
    }
  }

  // Compose the file's permanent destination.
  $destination = file_stream_wrapper_uri_normalize(
    $scheme . $directory
  );

  $upload_element = $form['upload'];
  $form['upload'] = array(
    '#tree' => TRUE,
    '#title' => t('Upload a new file'),
    '#process' => array('mfw_field_widget_process_multiple'),
    '#file_upload_delta' => 0
  );
  $form['upload'][0] = array(
      '#type' => 'mfw_managed_file',
      '#pre_render' => array('dragndrop_upload_media_multiupload_pre_render'),
      '#upload_location' => $destination,
    ) + $upload_element;
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

/**
 * Submit callback for media upload form.
 * 
 * Return uploaded files' fids to the Media browser.
 * 
 * @see dragndrop_upload_media_add_multiupload()
 */
function dragndrop_upload_media_add_mfw_multiupload_submit($form, &$form_state) { 
  $form_state['redirect'] = array(
    'media/browser',
    array(
      'query' => array(
        'render' => 'media-popup',
        'fid' => $form_state['values']['upload']
      )
    )
  );
}

/**
 * Pre-render callback for mfw_managed_file element.
 * 
 * Removes Upload and Remove buttons as they are not needed in Media browser.
 */
function dragndrop_upload_media_multiupload_pre_render($element) {
  $element['upload_button']['#access'] = FALSE;
  $element['remove_button']['#access'] = FALSE;
  return $element;
}

/**
 * Implements hook_form_FORM_ID_alter().
 * 
 * Alter "media_add_upload" form to change default submit callback
 * to a custom one.
 */
function dragndrop_upload_media_form_media_add_upload_alter(&$form, &$form_state) {
  if (!empty($form_state['build_info']['args'][0]['dragndropUpload'])) {
    $key = array_search('media_add_upload_submit', $form['#submit']);
    $form['#submit'][$key] = 'dragndrop_upload_media_add_upload_submit';
  }
}

/**
 * Form submit callback for a "media_add_upload" form.
 * 
 * Just a copy of media_add_upload_submit() excluding 
 * _media_save_file_permanently() function calling.
 * 
 * @see media_add_upload_submit()
 */
function dragndrop_upload_media_add_upload_submit($form, &$form_state) {
  $params = isset($form_state['build_info']['args'][0]) ? $form_state['build_info']['args'][0] : array();
  $file = $form_state['values']['upload'];

  // The media browser widget does not use the 'display' field.
  $file->display = TRUE;

  // Determine what URI scheme this file should use.
  $scheme = !empty($params['uri_scheme']) && file_stream_wrapper_valid_scheme(
    $params['uri_scheme']
  ) ? $params['uri_scheme'] : file_default_scheme();
  $scheme .= '://';

  // Prepare the file's subdirectory path.
  $directory = '';
  if (!empty($params['file_directory'])) {
    $directory = token_replace($params['file_directory']) . '/';

    // If the directory isn't writable, or doesn't exist and can't be created,
    // the upload will fail.
    $prepare_directory = file_stream_wrapper_uri_normalize(
      $scheme . $directory
    );
    if (!file_prepare_directory($prepare_directory, FILE_CREATE_DIRECTORY)) {
      drupal_set_message(
        t(
          'The file directory @dir does not exist or is not writable. Please contact an administrator.',
          array('@dir' => $prepare_directory)
        ),
        'error'
      );
      return;
    }
  }

  // Compose the file's permanent destination.
  $destination = file_stream_wrapper_uri_normalize(
    $scheme . $directory . $file->filename
  );

  // Save the uploaded file to the permanent location.
  $file = file_move($file, $destination, FILE_EXISTS_RENAME);

  if ($file) {
    drupal_set_message(
      t('The file @name was uploaded', array('@name' => $file->filename))
    );
  }
  else {
    drupal_set_message(
      t('An error occurred and no file was uploaded.'),
      'error'
    );
    return;
  }

  $form_state['redirect'] = array(
    'media/browser',
    array('query' => array('render' => 'media-popup', 'fid' => $file->fid))
  );
}

/**
 * Implements hook_media_browser_params_alter().
 * 
 * Disable "Multiple upload" plugin if Media browser is opened not
 * by Drag & Drop Upload module. 
 */
function dragndrop_upload_media_media_browser_params_alter(&$params) {
  if (empty($params['dragndropUpload'])) {
    $params['disabledPlugins'][] = 'mfw_multiupload';
  }
}
