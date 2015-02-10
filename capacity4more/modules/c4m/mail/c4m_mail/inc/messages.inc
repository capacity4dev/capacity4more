<?php
/**
 * Code to set/update the mail content based on the test in messages folder.
 * @file
 */


/**
 * Class to manage the email messages.
 */
class c4m_mail_messages {
  /**
   * Base path where all messages are stored.
   *
   * @var string
   */
  protected $path;

  /**
   * Listing of all the messages.
   *
   * @var array
   */
  protected $list;


  /**
   * Constructor.
   */
  public function __construct() {
    $this->path = drupal_get_path('module', 'c4m_mail')
      . DIRECTORY_SEPARATOR
      . 'messages';

    module_load_include('inc', 'c4m_mail', 'messages/list');
    /* @var $messages array */
    $this->list = $messages;
  }

  /**
   * Update all messages based on the message list.
   *
   * @return array
   *   List of message titles processed.
   */
  public function update() {
    $result = $this->process($this->list);
    return $result;
  }

  /**
   * Process the message list.
   *
   * Replace all message variables with the data found in the files.
   *
   * @param array $list
   *   The list of messages and their parts to process.
   *
   * @return array
   *   List of message titles processed.
   */
  protected function process($list) {
    $processed = array();
    $parts = array('subject' => 'txt', 'body' => 'html');

    foreach ($list as $item) {
      foreach ($parts as $part => $type) {
        $variable = $item[$part];
        $text = $this->load_text($item['module'], $variable, $type);
        if (!$text) {
          continue;
        }

        variable_set($variable, $text);
        $processed[] = $variable;
      }
    }

    return $processed;
  }

  /**
   * Load a message file.
   *
   * @param string $module
   *   The name of the module this message part belongs to.
   * @param string $filename
   *   The filename to load from the messages folder.
   * @param string $filetype
   *   The filetype extension.
   *
   * @return string
   *   The contents of the loaded file.
   */
  protected function load_text($module, $filename, $filetype) {
    $file = $this->path . DIRECTORY_SEPARATOR . $filename . '.' . $filetype;
    if (!file_exists($file)) {
      return FALSE;
    }

    $text = file_get_contents($file);
    return $text;
  }
}
