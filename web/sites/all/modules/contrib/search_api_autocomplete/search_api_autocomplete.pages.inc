<?php

/**
 * @file
 * Contains page callbacks and theme functions for the frontend UI.
 */

/**
 * Page callback for getting autocomplete suggestions.
 */
function search_api_autocomplete_autocomplete(SearchApiAutocompleteSearch $search, $fields, $keys = '') {
  $ret = array();
  try {
    if ($search->supportsAutocompletion()) {
      $server = $search->server();
      list($complete, $incomplete) = $search->splitKeys($keys);
      $query = $search->getQuery($complete, $incomplete);
      if ($query) {
        // @todo Maybe make range configurable?
        $query->range(0, 10);
        $query->setOption('search id', 'search_api_autocomplete:' . $search->machine_name);
        if (!empty($search->options['fields'])) {
          $query->fields($search->options['fields']);
        }
        elseif ($fields != '-') {
          $fields = explode(' ', $fields);
          $query->fields($fields);
        }
        $query->preExecute();
        $suggestions = $server->getAutocompleteSuggestions($query, $search, $incomplete, $keys);
        if ($suggestions) {
          foreach ($suggestions as $suggestion) {
            // Convert suggestion strings into an array.
            if (is_string($suggestion)) {
              $pos = strpos($suggestion, $keys);
              if ($pos === FALSE) {
                $suggestion = array(
                  'user_input' => '',
                  'suggestion_suffix' => $suggestion,
                );
              }
              else {
                $suggestion = array(
                  'suggestion_prefix' => substr($suggestion, 0, $pos),
                  'user_input' => $keys,
                  'suggestion_suffix' => substr($suggestion, $pos + strlen($keys)),
                );
              }
            }
            // Add defaults.
            $suggestion += array(
              'prefix' => NULL,
              'suggestion_prefix' => '',
              'user_input' => $keys,
              'suggestion_suffix' => '',
              'results' => NULL,
            );
            if (empty($search->options['results'])) {
              unset($suggestion['results']);
            }
            $key = $suggestion['suggestion_prefix'] . $suggestion['user_input'] . $suggestion['suggestion_suffix'];
            if (!isset($ret[$key])) {
              $ret[$key] = $suggestion;
            }
          }

          $alter_params = array(
            'query' => $query,
            'search' => $search,
            'incomplete_key' => $incomplete,
            'user_input' => $keys,
          );
          drupal_alter('search_api_autocomplete_suggestions', $ret, $alter_params);

          foreach ($ret as $key => $suggestion) {
            $escaped_variables = array('suggestion_prefix', 'user_input', 'suggestion_suffix');
            foreach ($escaped_variables as $variable) {
              if ($suggestion[$variable]) {
                $suggestion[$variable] = check_plain($suggestion[$variable]);
              }
            }
            $ret[$key] = theme('search_api_autocomplete_suggestion', $suggestion);
          }
        }
      }
    }
  }
  catch (SearchApiException $e) {
    watchdog_exception('search_api_autocomplete', $e, '%type while retrieving autocomplete suggestions: !message in %function (line %line of %file).');
  }

  drupal_json_output($ret);
}

/**
 *
 *
 * @param array $variables
 *   An associative array containing:
 *   - prefix: For special suggestions, some kind of HTML prefix describing
 *     them.
 *   - suggestion_prefix: A suggested prefix for the entered input.
 *   - user_input: The input entered by the user.
 *   - suggestion_suffix: A suggested suffix for the entered input.
 *   - results: If available, the estimated number of results for these keys.
 */
function theme_search_api_autocomplete_suggestion(array $variables) {
  extract($variables);
  $output = '';
  if ($prefix) {
    $output .= "<span class=\"autocomplete-suggestion-note\">$prefix</span> ";
  }
  if ($suggestion_prefix) {
    $output .= "<span class=\"autocomplete-suggestion-prefix\">$suggestion_prefix</span>";
  }
  if ($user_input) {
    $output .= "<span class=\"autocomplete-user-input\">$user_input</span>";
  }
  if ($suggestion_suffix) {
    $output .= "<span class=\"autocomplete-suggestion-suffix\">$suggestion_suffix</span>";
  }
  if ($results) {
    $output .= " <span class=\"autocomplete-suggestion-results\">$results</span>";
  }

  return "<div class=\"search-api-autocomplete-suggestion\">$output</div>";
}
