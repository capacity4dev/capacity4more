/**
 * @file
 * Provides the controller to handle Drupal forms (DrupalFormCtrl).
 */

'use strict';

angular.module('c4mApp')
  .controller('DrupalFormCtrl', function ($scope, DrupalSettings, EntityResource, Request, $window, $document, $modal, QuickPostService, $filter, FileUpload) {

    $scope.data = DrupalSettings.getData('vocabularies');

    $scope.data.group = DrupalSettings.getData('group');

    // Get related to the discussion documents.
    $scope.data.relatedDocuments = DrupalSettings.getData('relatedDocuments');

    // Get the form Identifier, for the related documents widget.
    $scope.formId = DrupalSettings.getData('formId');

    $scope.fieldName = '';

    $scope.model = {};

    $scope.basePath = DrupalSettings.getBasePath();

    // Get the Vocabulary ID of the current group.
    $scope.tagsId = DrupalSettings.getData('tags_id');

    // Get the selected tags (Only on edit page).
    $scope.data.tags = DrupalSettings.getData('tags');

    // Get the selected values of the taxonomy-terms (Only on edit page).
    $scope.values = DrupalSettings.getData('values');

    // Assign all the vocabularies to $scope.model.
    angular.forEach($scope.data, function (values, vocab) {
      $scope.model[vocab] = {};
    });

    // When on an edit page, Add the values of the taxonomies to the $scope.model,
    // This will unable us to show the selected values when opening an edit page.
    angular.forEach($scope.values, function (values, vocab) {
      angular.forEach(values, function (value, id) {
        $scope.model[vocab][id] = value;
      });
    });

    // Creating the pop-ups according to the vocabulary that was sent to the controller.
    $scope.popups = {};
    angular.forEach($scope.data, function (value, key) {
      $scope.popups[key] = 0;
    });

    angular.forEach($scope.data.categories, function (item, value) {
      item.selected = false;
    });

    // Copy the vocabularies to another variable,
    // It can be filtered without effecting the data that was sent to the controller.
    $scope.filteredTerms = angular.copy($scope.data);

    // Check if there's categories in the current group,
    // to display an empty categories message.
    $scope.categoriesLength = angular.isDefined($scope.filteredTerms.categories) && Object.keys($scope.filteredTerms.categories).length ? true : false;

    // Update the shown taxonomies upon searching.
    $scope.updateSearch = function (vocab) {
      $scope.filteredTerms[vocab] = $filter('termsFilter')($scope.data[vocab], $scope.searchTerms[vocab]);
    };

    // Toggle the visibility of the popovers.
    $scope.togglePopover = function (name, event) {
      QuickPostService.togglePopover(name, event, $scope.popups);
    };

    // Getting matching tags.
    $scope.tagsQuery = function (query) {
      QuickPostService.tagsQuery(query, $scope);
    };

    // Watch the "Tags" variable for changes,
    // Add the selected tags to the hidden tags input,
    // This way it can be saved in the Drupal Form.
    $scope.$watch('data.tags', function () {
      var tags = [];
      angular.forEach($scope.data.tags, function (tag) {
        if (!tag.isNew) {
          tags.push(tag.text + ' (' + tag.id + ')');
        }
        else {
          tags.push(tag.text);
        }
      });
      if (!angular.isObject($scope.tagsId)) {
        angular.element('#edit-og-vocabulary-und-0-' + $scope.tagsId).val(tags.join(', '));
      }
    });

    /**
     * Update the checkboxes in the Drupal form.
     *
     * We have to fill the fields according to the name of the field because
     * It's more accurate and we have conflicting values,
     * But in the case of "og_vocab", The structure of the field name is different
     * and we update it according to the value instead.
     *
     * @param key
     *   The ID of the term that was changed.
     * @param vocab
     *   The name of the vocab.
     */
    $scope.updateSelectedTerms = function (key, vocab) {
      if ($scope.model[vocab][key]) {
        // Checkbox has been checked.
        if (vocab == 'categories') {
          angular.element('input[type=checkbox][value="' + key + '"]').prop("checked", true);
        }
        else {
          // Check up to 3 topics selected.
          if (vocab == 'c4m_vocab_topic' || vocab == 'c4m_vocab_topic_expertise' || vocab == 'c4m_vocab_geo') {
            var topicCount = 0;
            angular.forEach($scope.model[vocab], function (element, topicKey) {
              if (element === true && $scope.data[vocab][topicKey]) {
                // Term is selected and it's term of the first level.
                topicCount++;
              }
            });
            // Don't check if selected more than 3 topics.
            if (topicCount > 3) {
              $scope.model[vocab][key] = false;
              angular.element('input[type=checkbox][name="' + vocab + '[und][' + key + ']"]').prop("checked", false);
              return;
            }
          }
          angular.element('input[type=checkbox][name="' + vocab + '[und][' + key + ']"]').prop("checked", true);
        }
      }
      else {
        // Checkbox has been unchecked.
        if (vocab == 'categories') {
          angular.element('input[type=checkbox][value="' + key + '"]').prop("checked", false);
        }
        else {
          angular.element('input[type=checkbox][name="' + vocab + '[und][' + key + ']"]').prop("checked", false);
        }
        if (key in $scope.data[vocab]) {
          // This is the 1st level term - should uncheck all 2 an 3 levels terms.
          angular.forEach($scope.data[vocab][key].children, function (child, itemKey) {
            var childID = child.id;

            // Uncheck 2 level terms.
            if (childID in $scope.model[vocab] && $scope.model[vocab][childID] === true) {
              $scope.model[vocab][childID] = false;
              if (vocab == 'categories') {
                angular.element('input[type=checkbox][value="' + childID + '"]').prop("checked", false);
              }
              else {
                angular.element('input[type=checkbox][name="' + vocab + '[und][' + childID + ']"]').prop("checked", false);
              }
              // Uncheck 3 level terms.
              angular.forEach($scope.data[vocab][key].children[itemKey].children, function (childChild, childChildKey) {
                var childChildID = childChild.id;
                if (childChildID in $scope.model[vocab] && $scope.model[vocab][childChildID] === true) {
                  $scope.model[vocab][childChildID] = false;
                  if (vocab == 'categories') {
                    angular.element('input[type=checkbox][value="' + childChildID + '"]').prop("checked", false);
                  }
                  else {
                    angular.element('input[type=checkbox][name="' + vocab + '[und][' + childChildID + ']"]').prop("checked", false);
                  }
                }
              });
            }
          });
        }
        else {
          // This was the 2 or 3 level term.
          angular.forEach($scope.data[vocab], function (term, termKey) {
            angular.forEach($scope.data[vocab][termKey].children, function (child, childKey) {
              if (key == child.id) {
                // This is the current 2 level term - should uncheck its children.
                angular.forEach($scope.data[vocab][termKey].children[childKey].children, function (childChild, childChildKey) {
                  var childID = childChild.id;
                  if (childID in $scope.model[vocab] && $scope.model[vocab][childID] === true) {
                    $scope.model[vocab][childID] = false;
                    if (vocab == 'categories') {
                      angular.element('input[type=checkbox][value="' + childID + '"]').prop("checked", false);
                    }
                    else {
                      angular.element('input[type=checkbox][name="' + vocab + '[und][' + childID + ']"]').prop("checked", false);
                    }
                  }
                });
              }
            });
          });
        }
      }
    };

    /**
     * Show or hide list of subcategories for the current category.
     *
     * Is called by click.
     *
     * @param item
     *  Current category item.
     */
    $scope.updateSelected = function (item) {
      item.selected = !item.selected;
    };

    /**
     * Check if current term has at least one selected child.
     *
     * @param vocab
     *  Vocabulary name.
     * @param key
     *  1-st level term id.
     * @param childKey
     *  2-nd level term id.
     *
     * @returns {boolean}
     */
    $scope.termHasChildrenSelected = function (vocab, key, childKey) {
      if (childKey != 'null') {
        // This is 2-level term.
        if (!$scope.data[vocab][key].children[childKey]) {
          // This term has been removed.
          return false;
        }
        if (!$scope.data[vocab][key].children[childKey].children) {
          // This term doesn't have children at all.
          return false;
        }
        for (var i = 0; i < $scope.data[vocab][key].children[childKey].children.length; i++) {
          var id = $scope.data[vocab][key].children[childKey].children[i].id;
          if ($scope.model[vocab][id] === true) {
            return true;
          }
        }
      }
      else {
        // This is 1-level term.
        if (!$scope.data[vocab][key]) {
          // This term has been removed.
          return false;
        }
        if (!$scope.data[vocab][key].children) {
          // This term doesn't have children at all.
          return false;
        }
        for (var i = 0; i < $scope.data[vocab][key].children.length; i++) {
          var id = $scope.data[vocab][key].children[i].id;
          if ($scope.model[vocab][id] === true) {
            return true;
          }
        }
      }
      return false;
    };

    /**
     * When clicking on the "X" next to the taxonomy-term name (full form page).
     *
     * @param key
     *  The ID of the taxonomy.
     * @param vocab
     *  The name of the vocabulary.
     */
    $scope.removeTaxonomyValue = function (key, vocab) {
      $scope.model[vocab][key] = false;
      $scope.updateSelectedTerms(key, vocab);
    };

    // Close all popovers on "ESC" key press.
    $document.on('keyup', function (event) {
      // 27 is the "ESC" button.
      if (event.which == 27) {
        $scope.closePopups();
      }
    });

    // Close all popovers on click outside popup box.
    $document.on('mousedown', function (event) {
      // Check if we are not clicking on the popup.
      var parents = angular.element(event.target).parents();
      var close = true;
      angular.forEach(parents, function (parent, id) {
        if (parent.className.indexOf('popover') != -1) {
          close = false;
        }
      });
      // This is not button, that should open popup.
      if (event.target.type != 'button' && close) {
        $scope.closePopups();
      }
    });

    /**
     * Make all popups closed.
     */
    $scope.closePopups = function () {
      $scope.$apply(function (scope) {
        angular.forEach($scope.popups, function (value, key) {
          this[key] = 0;
        }, $scope.popups);
      });
    };

    /**
     * Uploading document file.
     *
     * @param $files
     *  The file.
     * @param fieldName
     *  Name of the current field.
     */
    $scope.onFileSelect = function ($files, fieldName) {
      $scope.setFieldName(fieldName);
      // $files: an array of files selected, each file has name, size, and type.
      for (var i = 0; i < $files.length; i++) {
        var file = $files[i];
        FileUpload.upload(file).then(function (data) {
          var fileId = data.data.data[0].id;
          $scope.data.fileName = data.data.data[0].label;
          $scope.serverSide.file = data;
          var openPath = DrupalSettings.getData('purl') == $scope.basePath ? $scope.basePath : DrupalSettings.getData('purl') + '/';
          Drupal.overlay.open(openPath + 'overlay-file/' + fileId + '?render=overlay');
        });
      }
    };

    /**
     * Opens the system's file browser.
     */
    $scope.browseFiles = function (fieldName) {
      angular.element('#' + fieldName).click();
    };

    /**
     * Set the name of the current field.
     *
     * @param fieldName
     */
    $scope.setFieldName = function (fieldName) {
      $scope.fieldName = fieldName;
    };
  });
