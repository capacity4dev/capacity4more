<?php

/**
 * @file
 * Contains the SearchApiAutocompleteSearch class.
 */


/**
 * Class describing the settings for a certain search for which autocompletion
 * is available.
 */
class SearchApiAutocompleteSearch extends Entity {

  // Entity properties, loaded from the database:

  /**
   * @var integer
   */
  public $id;

  /**
   * @var string
   */
  public $machine_name;

  /**
   * @var string
   */
  public $name;

  /**
   * @var integer
   */
  public $index_id;

  /**
   * @var string
   */
  public $type;

  /**
   * @var boolean
   */
  public $enabled;

  /**
   * An array of options for this search, containing any of the following:
   * - results: Boolean indicating whether to also list the estimated number of
   *   results for each suggestion (if possible).
   * - fields: Array containing the fulltext fields to use for autocompletion.
   * - custom: An array of type-specific settings.
   *
   * @var array
   */
  public $options = array();

  // Inferred properties, for caching:

  /**
   * @var SearchApiIndex
   */
  protected $index;

  /**
   * @var SearchApiServer
   */
  protected $server;

  /**
   * Constructor.
   *
   * @param array $values
   *   The entity properties.
   */
  public function __construct(array $values = array()) {
    parent::__construct($values, 'search_api_autocomplete_search');
  }

  /**
   * @return SearchApiIndex
   *   The index this search belongs to.
   */
  public function index() {
    if (!isset($this->index)) {
      $this->index = search_api_index_load($this->index_id);
      if (!$this->index) {
        $this->index = FALSE;
      }
    }
    return $this->index;
  }

  /**
   * Retrieves the server this search would at the moment be executed on.
   *
   * @return SearchApiServer
   *   The server this search would at the moment be executed on.
   *
   * @throws SearchApiException
   *   If a server is set for the index but it doesn't exist.
   */
  public function server() {
    if (!isset($this->server)) {
      if (!$this->index() || !$this->index()->server) {
        $this->server = FALSE;
      }
      else {
        $this->server = $this->index()->server();
        if (!$this->server) {
          $this->server = FALSE;
        }
      }
    }
    return $this->server;
  }

  /**
   * @return boolean
   *   TRUE if the server this search is currently associated with supports the
   *   autocompletion feature; FALSE otherwise.
   */
  public function supportsAutocompletion() {
    try {
      return $this->server() && $this->server()->supportsFeature('search_api_autocomplete');
    }
    catch (Exception $e) {
      return FALSE;
    }
  }

  /**
   * Helper method for altering a textfield form element to use autocompletion.
   */
  public function alterElement(array &$element, array $fields = array()) {
    if (search_api_autocomplete_access($this)) {

      $fields_string = $fields ? implode(' ', $fields) : '-';
      $module_path = drupal_get_path('module', 'search_api_autocomplete');
      $element['#attached']['css'][] = $module_path . '/search_api_autocomplete.css';
      $element['#attached']['js'][] = $module_path . '/search_api_autocomplete.js';
      if (isset($this->options['submit_button_selector'])) {
        $element['#attached']['js'][] = array(
          'type' => 'setting',
          'data' => array('search_api_autocomplete' => array('selector' => $this->options['submit_button_selector'])),
        );
      }
      $element['#autocomplete_path'] = 'search_api_autocomplete/' . $this->machine_name . '/' . $fields_string;
      $element += array('#attributes' => array());
      $element['#attributes'] += array('class'=> array());
      $element['#attributes']['class'][] = 'auto_submit';
      $options = $this->options + array('min_length' => 1);
      if ($options['min_length'] > 1) {
        $element['#attributes']['data-min-autocomplete-length'] = $options['min_length'];
      }
    }
  }

  /**
   * Split a string with search keywords into two parts.
   *
   * The first part consists of all words the user has typed completely, the
   * second one contains the beginning of the last, possibly incomplete word.
   *
   * @return array
   *   An array with $keys split into exactly two parts, both of which may be
   *   empty.
   */
  public function splitKeys($keys) {
    $keys = ltrim($keys);
    // If there is whitespace or a quote on the right, all words have been
    // completed.
    if (rtrim($keys, " \"") != $keys) {
      return array(rtrim($keys, ' '), '');
    }
    if (preg_match('/^(.*?)\s*"?([\S]*)$/', $keys, $m)) {
      return array($m[1], $m[2]);
    }
    return array('', $keys);
  }

  /**
   * Create the query that would be issued for this search for the complete keys.
   *
   * @param $complete
   *   A string containing the complete search keys.
   * @param $incomplete
   *   A string containing the incomplete last search key.
   *
   * @return SearchApiQueryInterface
   *   The query that would normally be executed when only $complete was entered
   *   as the search keys for this search.
   *
   * @throws SearchApiException
   *   If the query couldn't be created.
   */
  public function getQuery($complete, $incomplete) {
    $info = search_api_autocomplete_get_types($this->type);
    if (empty($info['create query'])) {
      return NULL;
    }
    $query = $info['create query']($this, $complete, $incomplete);
    if ($complete && !$query->getKeys()) {
      $query->keys($complete);
    }
    return $query;
  }

}
