<?php
/**
 * @file
 * Code to set/update the mail content based on the test in messages folder.
 */

/**
 * Class to manage the email messages.
 */
class C4mMailMessages {
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

    include $this->path . '/list.inc';
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
    $processed = array();

    foreach ($this->list as $item) {
      if ($this->updateMessage(
        $item['module'],
        $item['subject'],
        $item['body']
      )) {
        $processed[] = $item['title'];
      }
    }

    return $processed;
  }

  /**
   * Process all variables of a message.
   *
   * @param string $module
   *   The name of the module.
   * @param string $subject
   *   The subject variable name.
   * @param string $body
   *   The body variable name.
   *
   * @return bool
   *   Success.
   */
  protected function updateMessage($module, $subject, $body) {
    $parts = array(
      $subject => 'txt',
      $body => 'html',
    );

    foreach ($parts as $variable => $filetype) {
      $text = $this->loadText($module, $variable, $filetype);
      if (!$text) {
        return FALSE;
      }

      variable_set($variable, $text);
    }

    return TRUE;
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
  protected function loadText($module, $filename, $filetype) {
    $file = $this->path
      . DIRECTORY_SEPARATOR . $module
      . DIRECTORY_SEPARATOR . $filename . '.' . $filetype;
    if (!file_exists($file)) {
      return FALSE;
    }

    $text = file_get_contents($file);
    return $text;
  }

}
