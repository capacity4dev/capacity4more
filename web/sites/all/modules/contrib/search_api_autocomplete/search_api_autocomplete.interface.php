<?php

/**
 * @file
 * Contains the SearchApiAutocompleteInterface.
 */


/**
 * Interface describing the method a service class has to add to support autocompletion.
 *
 * Please note that this interface is purely documentational. You shouldn't, and
 * can't, implement it explicitly.
 */
interface SearchApiAutocompleteInterface extends SearchApiServiceInterface {

  /**
   * Get autocompletion suggestions for some user input.
   *
   * For example, when given the user input "teach us", with "us" being
   * considered incomplete, the following might be returned:
   * @code
   *   array(
   *     array(
   *       'prefix' => t('Did you mean:'),
   *       'user_input' => 'reach us',
   *     ),
   *     array(
   *       'user_input' => 'teach us',
   *       'suggestion_suffix' => 'ers',
   *     ),
   *     array(
   *       'user_input' => 'teach us',
   *       'suggestion_suffix' => ' swimming',
   *     ),
   *     'teach users swimming',
   *   );
   * @endcode
   *
   * @param SearchApiQueryInterface $query
   *   A query representing the completed user input so far.
   * @param SearchApiAutocompleteSearch $search
   *   An object containing details about the search the user is on, and
   *   settings for the autocompletion. See the class documentation for details.
   *   Especially $search->options should be checked for settings, like whether
   *   to try and estimate result counts for returned suggestions.
   * @param string $incomplete_key
   *   The start of another fulltext keyword for the search, which should be
   *   completed. Might be empty, in which case all user input up to now was
   *   considered completed. Then, additional keywords for the search could be
   *   suggested.
   * @param string $user_input
   *   The complete user input for the fulltext search keywords so far.
   *
   * @return array
   *   An array of suggestion. Each suggestion is either a simple string
   *   containing the whole suggested keywords, or an array containing the
   *   following keys:
   *   - prefix: For special suggestions, some kind of prefix describing them.
   *   - suggestion_prefix: A suggested prefix for the entered input.
   *   - user_input: The input entered by the user. Defaults to $user_input.
   *   - suggestion_suffix: A suggested suffix for the entered input.
   *   - results: If available, the estimated number of results for these keys.
   *   One of "suggestion_prefix" and "suggestion_suffix" has to be present, all
   *   other keys are optional. The search keys inserted for the suggestion will
   *   be a direct concatenation (no spaces in between) of "suggestion_prefix",
   *   "user_input" and "suggestion_suffix".
   */
  public function getAutocompleteSuggestions(SearchApiQueryInterface $query, SearchApiAutocompleteSearch $search, $incomplete_key, $user_input);

}
