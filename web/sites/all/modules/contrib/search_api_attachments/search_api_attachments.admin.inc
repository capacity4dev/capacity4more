<?php


/**
 * @file
 * Admin settings
 */

/**
 * Page callback to show the settings for the attachments.
 */
function search_api_attachments_settings_form($form, &$form_state) {
  $form['search_api_attachments_extract_using'] = array(
    '#type' => 'radios',
    '#title' => t('Extraction method'),
    '#options' => array(
      'tika' => t('Tika (local java application)'),
      'solr' => t('Solr (remote server)'),
    ),
    '#description' => t('Choose extraction method, remote or local (extraction will be faster if run locally using tika).'),
    '#default_value' => variable_get('search_api_attachments_extract_using', 'tika'),
  );
  $form['search_api_attachments_tika_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Tika extraction settings'),
    '#description' => t('Required if using the "Tika" extraction method (above).'),
    '#collapsible' => TRUE,
  );
  $form['search_api_attachments_tika_settings']['search_api_attachments_tika_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Tika directory path:'),
    '#default_value' => variable_get('search_api_attachments_tika_path', ''),
    '#description' => t('The full path to tika directory. All library jars must be in the same directory. E.g. /var/apache-tika-4.0/'),
  );
  $form['search_api_attachments_tika_settings']['search_api_attachments_tika_jar'] = array(
    '#type' => 'textfield',
    '#title' => t('Tika jar file:'),
    '#default_value' => variable_get('search_api_attachments_tika_jar', 'tika-app-1.4.jar'),
    '#description' => t('The name of the tika CLI application jar file, e.g. tika-app-1.4.jar.'),
  );
  $form['search_api_attachments_solr_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Solr extraction settings'),
    '#description' => t('Required if using the "Solr" extraction method (above).'),
    '#collapsible' => TRUE,
  );
  $form['search_api_attachments_solr_settings']['search_api_attachments_extracting_servlet_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Solr extracting servlet path:'),
    '#default_value' => variable_get('search_api_attachments_extracting_servlet_path', 'update/extract'),
    '#description' => t('The path to the extracting servlet. E.g. update/extract or extract/tika'),
  );
  $form['search_api_attachments_cache_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Caching settings'),
    '#collapsible' => TRUE,
  );
  $form['search_api_attachments_cache_settings']['search_api_attachments_preserve_cache'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('search_api_attachments_preserve_cache', FALSE),
    '#title' => t('Preserve cached extractions across cache clears.'),
    '#description' => t('When checked, clearing the sidewide cache will not clear the cache of extracted files.'),
  );
  return system_settings_form($form);
}

/**
 * Validation handler for the settings form.
 */
function search_api_attachments_settings_form_validate($form, &$form_state) {
  // We only need to validate the tika path if we're using local extraction.
  if ($form_state['values']['search_api_attachments_extract_using'] == 'tika') {
    // Tika extraction without tika jar error.
    if (empty($form_state['values']['search_api_attachments_tika_jar'])) {
      form_set_error('search_api_attachments_tika_jar', t('Tika jar is mandatory.'));
    }

    // Check that the file exists.
    $path = realpath($form_state['values']['search_api_attachments_tika_path']);
    $tika = $path . '/' . $form_state['values']['search_api_attachments_tika_jar'];
    if (!file_exists($tika)) {
      form_set_error('search_api_attachments_tika_path', t('Tika jar file not found at this path.'));
    }
    // Check that the file is an executable jar.
    else {
      $cmd = escapeshellcmd('java') . ' -jar ' . escapeshellarg($tika) . ' -V';
      exec($cmd, $output, $return_code);
      // $return_code = 1 if it fails. 0 instead.
      if ($return_code) {
        form_set_error('search_api_attachments_tika_path', '');
        form_set_error('search_api_attachments_tika_jar', t('Tika jar file is not an executable jar. Please check if you have not downloaded a corrupted jar file.'));
      }
    }
  }
}
