<?php

/**
 * @file
 * Search API data alteration callback
 */

class SearchApiAttachmentsAlterSettings extends SearchApiAbstractAlterCallback {

  // Cache table name.
  const CACHE_TABLE = 'cache_search_api_attachments';

  public function alterItems(array &$items) {

    // Extension restriction.
    $exclude = array();
    foreach (explode(' ', $this->options['excluded_extensions']) as $ext) {
      $exclude[$ext] = file_get_mimetype('dummy.' . $ext);
    }

    // File size restriction.
    $max_file_size = parse_size($this->options['max_file_size']);
    if ($this->index->getEntityType() == 'file') {
      foreach ($items as $id => &$item) {
        $file = array();
        foreach ($item as $key => $value) {
          $file[$key] = $value;
        }
        // Private file restriction.
        if (!$this->is_temporary($file) && !($this->options['excluded_private'] && $this->is_private($file))) {
          // Extension restriction.
          if (!in_array($file['filemime'], $exclude)) {
            // File size restriction.
            $file_size_errors = file_validate_size((object) $file, $max_file_size);
            if (empty($file_size_errors)) {
              $item->attachments_content = $this->getFileContent($file);
            }
          }
        }
      }
    }
    else {
      $fields = $this->getFileFields();
      foreach ($items as $id => &$item) {
        foreach ($fields as $name => $field) {
          if (isset($item->$name)) {
            foreach ($item->$name as $value) {
              // Limit to the max number of value per field.
              if (isset($this->options['number_indexed']) && $this->options['number_indexed'] != '0' && count($value) > $this->options['number_indexed']) {
                $value = array_slice($value, 0, $this->options['number_indexed']);
              }
              foreach ($value as $file) {
                // Private file restriction.
                if (!$this->is_temporary($file) && !($this->options['excluded_private'] && $this->is_private($file))) {
                  // Extension restriction.
                  if (!in_array($file['filemime'], $exclude)) {
                    // File size restriction.
                    $file_size_errors = file_validate_size((object) $file, $max_file_size);
                    if (empty($file_size_errors)) {
                      $attachments = 'attachments_' . $name;
                      if (isset($item->{$attachments})) {
                        $item->{$attachments} .= ' ' . $this->getFileContent($file);
                      }
                      else {
                        $item->{$attachments} = $this->getFileContent($file);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  public function configurationForm() {
    $default = implode(' ', search_api_attachments_default_excluded());
    $form['excluded_extensions'] = array(
      '#type' => 'textfield',
      '#title' => t('Excluded file extensions'),
      '#default_value' => isset($this->options['excluded_extensions']) ? $this->options['excluded_extensions'] : $default,
      '#size' => 80,
      '#maxlength' => 255,
      '#description' => t('File extensions that are excluded from indexing. Separate extensions with a space and do not include the leading dot. Extensions are internally mapped to a MIME type, so it is not necessary to put variations that map to the same type (e.g. tif is sufficient for tif and tiff)'),
    );
    $form['number_indexed'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of file indexed per file field'),
      '#default_value' => isset($this->options['number_indexed']) ? $this->options['number_indexed'] : '0',
      '#size' => 5,
      '#description' => t('The number of files to index per file field. The order of indexation is the weight in the widget. 0 for no restriction.'),
    );
    $form['max_file_size'] = array(
      '#type' => 'textfield',
      '#title' => t('Maximum file size'),
      '#default_value' => isset($this->options['max_file_size']) ? $this->options['max_file_size'] : '0',
      '#description' => t('Enter a value like "512" (bytes), "80 KB" (kilobytes) or "50 MB" (megabytes) in order to restrict the max file size of files that should be indexed.'),
      '#size' => 80,
      '#maxlength' => 255,
      '#element_validate' => array('_file_generic_settings_max_filesize'),
    );
    $form['excluded_private'] = array(
      '#type' => 'checkbox',
      '#title' => t('Exclude private files'),
      '#default_value' => isset($this->options['excluded_private']) ? $this->options['excluded_private'] : TRUE,
      '#description' => t('Check this box if you want to exclude private files to be indexed.'),
    );
    return $form;
  }

  public function propertyInfo() {
    $ret = array();
    if ($this->index->getEntityType() == 'file') {
      $ret['attachments_content'] = array(
        'label' => 'File content',
        'description' => 'File content',
        'type' => 'text',
      );
    }
    else {
      $fields = $this->getFileFields();
      foreach ($fields as $name => $field) {
        $ret['attachments_' . $name] = array(
          'label' => 'Attachment content: ' . $name,
          'description' => $name,
          'type' => 'text',
        );
      }
    }
    return $ret;
  }

  protected function getFileFields() {
    $ret = array();
    foreach (field_info_fields() as $name => $field) {
      if ($field['type'] == 'file' && array_key_exists($this->index->getEntityType(), $field['bundles'])) {
        $ret[$name] = $field;
      }
    }
    return $ret;
  }

  protected function getFileContent($file) {
    $extraction = FALSE;
    // Let's make the variable consistent.
    $file = (array) $file;

    // Before running the (performance-intensive) extraction process, check
    // if we already have a cached copy of the extracted data.
    if (isset($file['fid'])) {
      // Load cached extraction based off file ID.
      $cid = 'cached_extraction_:' . $file['fid'];
      $cached_extraction = cache_get($cid, self::CACHE_TABLE);

      // If we have a cache hit, there really is no need to continue.
      if (!empty($cached_extraction->data)) {
        return $cached_extraction->data;
      }
    }

    if (file_exists($file['uri'])) {
      if ($file['filemime'] == 'text/plain' || $file['filemime'] == 'text/x-diff') {
        $extraction = $this->extract_simple($file);
      }
      elseif (in_array($file['filemime'], array('image/jpeg', 'image/jpg', 'image/tiff'))) {
        $extraction = $this->extract_exif($file);
      }
      else {
        $extraction_method = variable_get('search_api_attachments_extract_using', 'tika');
        // Send the extraction request to the right place depending on the
        // current setting.
        if ($extraction_method == 'tika') {
          $extraction = $this->extract_tika($file);
        }
        else {
          $extraction = $this->extract_solr($file);
        }
      }
    }
    else {
      // Log the missing file information.
      watchdog('search_api_attachments', "Couldn't index %filename content because this file was missing.", array('%filename' => $file['filename']));
    }

    // If we have actual extracted data, write it to the cache.
    if ($extraction !== FALSE && isset($cid)) {
      cache_set($cid, $extraction, self::CACHE_TABLE);
    }

    return $extraction;
  }

  protected function extract_simple($file) {
    $text = file_get_contents($this->get_realpath($file));
    $text = iconv("UTF-8", "UTF-8//IGNORE", $text);
    $text = filter_xss(str_replace(array('<', '>'), array(' <', '> '), $text), array());
    $text = htmlspecialchars(html_entity_decode($text, ENT_NOQUOTES, 'UTF-8'), ENT_NOQUOTES, 'UTF-8');
    $text = trim($text);
    return $text;
  }

  protected function extract_exif($file) {
    $ret = '';
    $size = getimagesize($this->get_realpath($file), $info);
    if (isset($info['APP13'])) {
      $iptc = iptcparse($info['APP13']);
      if (is_array($iptc)) {
        foreach ($iptc as $key => $value) {
          foreach ($value as $innerkey => $innervalue) {
            $ret .= $innervalue . ' ';
          }
        }
      }
    }
    return $ret;
  }

  protected function extract_tika($file) {
    $filepath = $this->get_realpath($file);
    $tika_path = realpath(variable_get('search_api_attachments_tika_path', ''));
    $tika = realpath($tika_path . '/' . variable_get('search_api_attachments_tika_jar', 'tika-app-1.4.jar'));
    if (!($tika) || !is_file($tika)) {
      throw new Exception(t('Invalid path or filename for tika application jar.'));
    }
    // UTF-8 multibyte characters will be stripped by escapeshellargs() for the
    // default C-locale.
    // So temporarily set the locale to UTF-8 so that the filepath remains valid.
    $backup_locale = setlocale(LC_CTYPE, '0');
    setlocale(LC_CTYPE, 'en_US.UTF-8');
    $param = '';
    if ($file['filemime'] != 'audio/mpeg') {
      $param = ' -Dfile.encoding=UTF8 -cp ' . escapeshellarg($tika_path);
    }

    // Force running the Tika jar headless.
    $param = ' -Djava.awt.headless=true ' . $param;

    $cmd = escapeshellcmd('java') . $param . ' -jar ' . escapeshellarg($tika) . ' -t ' . escapeshellarg($filepath);
    if (strpos(ini_get('extension_dir'), 'MAMP/')) {
      $cmd = 'export DYLD_LIBRARY_PATH=""; ' . $cmd;
    }
    // Restore the locale.
    setlocale(LC_CTYPE, $backup_locale);
    // Support UTF-8 commands: http://www.php.net/manual/en/function.shell-exec.php#85095
    shell_exec("LANG=en_US.utf-8");
    return shell_exec($cmd);
  }

  /**
   * Extract data using Solr (via the ExtractingRequestHandler) or using the
   * remote Tika servlet.
   * @see  http://wiki.apache.org/solr/ExtractingRequestHandler.
   * @see  http://wiki.apache.org/tika/TikaJAXRS.
   */
  protected function extract_solr($file) {
    $extraction = FALSE;

    $filepath = $this->get_realpath($file);
    try {
      $filename = basename($filepath);

      // Server name is stored in the index.
      $server_name = $this->index->server;

      $server = search_api_server_load($server_name, TRUE);

      // Make sure this is a solr server.
      $class_info = search_api_get_service_info($server->class);
      $classes = class_parents($class_info['class']);
      $classes[$class_info['class']] = $class_info['class'];
      if (!in_array('SearchApiSolrService', $classes)) {
        throw new SearchApiException(t('Server %server is not a Solr server, unable to extract file.', array(
          '%server' => $server_name,
        )));
      }

      // Open a connection to the server.
      $solr_connection = $server->getSolrConnection();

      // Path for our servlet request.
      $servlet_path = variable_get('search_api_attachments_extracting_servlet_path', 'update/extract');

      // Parameters for the extraction request.
      $params = array(
        'extractOnly' => 'true',
        'resource.name' => $filename,
        // Matches the -t command for the tika CLI app.
        'extractFormat' => 'text',
        'wt' => 'json',
        'hl' => 'on',
      );

      // Heavily inspired by apachesolr_file.
      // @see apachesolr_file_extract().
      // Construct a multi-part form-data POST body in $data.
      $boundary = '--' . md5(uniqid(REQUEST_TIME));
      $data = "--{$boundary}\r\n";
      // The 'filename' used here becomes the property name in the response.
      $data .= 'Content-Disposition: form-data; name="file"; filename="extracted"';
      $data .= "\r\nContent-Type: application/octet-stream\r\n\r\n";
      $data .= file_get_contents($filepath);
      $data .= "\r\n--{$boundary}--\r\n";
      $headers = array('Content-Type' => 'multipart/form-data; boundary=' . $boundary);
      $options = array(
        'method' => 'POST',
        'headers' => $headers,
        'data' => $data,
      );

      // Make a servlet request using the solr connection.
      $response = $solr_connection->makeServletRequest($servlet_path, $params, $options);

      // If we have an extracted response, all is well.
      if (isset($response->extracted)) {
        $extraction = $response->extracted;
      }
    }
    catch (Exception $e) {
      // Log the exception to watchdog. Exceptions from Solr may be transient,
      // or indicate a problem with a specific file.
      watchdog('search_api_attachments', 'Exception occurred sending %filepath to Solr.', array(
        '%filepath' => $file['uri'],
      ));
      watchdog_exception('search_api_attachments', $e);
    }

    return $extraction;
  }

  /**
   * Check if the file is private.
   *
   * @param array $file
   *   A file array.
   *
   * @return bool
   *   TRUE if the file is private. FALSE otherwise.
   */
  protected function is_private($file) {
    $result = FALSE;
    $wrapper = 'private://';
    $uri = $file['uri'];
    if (substr($uri, 0, 10) == $wrapper) {
      $result = TRUE;
    }
    return $result;
  }

  protected function is_temporary($file) {
    $result = FALSE;
    $wrapper = 'temporary://';
    $uri = $file['uri'];
    if (substr($uri, 0, 12) == $wrapper) {
      $result = TRUE;
    }
    return $result;
  }

  protected function get_realpath($file) {
    $wrapper = file_stream_wrapper_get_instance_by_uri($file['uri']);
    $scheme = file_uri_scheme($file['uri']);
    $local_wrappers = file_get_stream_wrappers(STREAM_WRAPPERS_LOCAL);
    if (in_array($scheme, array_keys($local_wrappers))) {
      return $wrapper->realpath();
    }
    else {
      return $wrapper->getExternalUrl();
    }
  }
}
