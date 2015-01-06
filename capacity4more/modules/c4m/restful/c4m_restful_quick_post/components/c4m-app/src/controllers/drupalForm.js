'use strict';

angular.module('c4mApp')
  .controller('DrupalFormCtrl', function($scope, DrupalSettings, EntityResource, Request, $window, $document, $modal, QuickPostService, $filter, FileUpload) {

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
    angular.forEach($scope.data, function(values, vocab) {
      $scope.model[vocab] = {};
    });

    // When on an edit page, Add the values of the taxonomies to the $scope.model,
    // This will unable us to show the selected values when opening an edit page.
    angular.forEach($scope.values, function(values, vocab) {
      angular.forEach(values, function(value, id) {
        $scope.model[vocab][id] = value;
      });
    });

    // Creating the pop-ups according to the vocabulary that was sent to the controller.
    $scope.popups = {};
    angular.forEach($scope.data, function(value, key) {
      $scope.popups[key] = 0;
    });

    // Copy the vocabularies to another variable,
    // It can be filtered without effecting the data that was sent to the controller.
    $scope.filteredTerms = angular.copy($scope.data);

    // Update the shown texonomies upon searching.
    $scope.updateSearch = function(vocab) {
      $scope.filteredTerms[vocab] = $filter('termsFilter')($scope.data[vocab], $scope.searchTerms[vocab]);
    };

    // Toggle the visibility of the popovers.
    $scope.togglePopover = function(name, event) {
      QuickPostService.togglePopover(name, event, $scope.popups);
    };

    // Getting matching tags.
    $scope.tagsQuery = function (query) {
      QuickPostService.tagsQuery(query, $scope);
    };

    // Watch the "Tags" variable for changes,
    // Add the selected tags to the hidden tags input,
    // This way it can be saved in the Drupal Form.
    $scope.$watch('data.tags', function() {
      var tags = [];
      angular.forEach ($scope.data.tags, function(tag) {
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
     * Update the checkboxes in the Drupal form,
     * We have to fill the fields according to the name of the field because
     * It's more accurate and we have conflicting values,
     * But in the case of "og_vocab", The structure of the field name is different
     * and we update it according to the value instead.
     *
     * @param key
     *  The ID of the term that was changed.
     *
     * @param vocab
     *  The name of the vocab.
     */
    $scope.updateSelectedTerms = function(key, vocab) {
      if($scope.model[vocab][key]) {
        if (vocab == 'categories') {
          angular.element('input[type=checkbox][value="' + key + '"]').prop("checked", true);
        }
        else {
          angular.element('input[type=checkbox][name="' + vocab + '[und][' + key + ']"]').prop("checked", true);
        }
      }
      else {
        if (vocab == 'categories') {
          angular.element('input[type=checkbox][value="' + key + '"]').prop("checked", false);
        }
        else {
          angular.element('input[type=checkbox][name="' + vocab + '[und][' + key + ']"]').prop("checked", false);
        }
        if (key in $scope.data[vocab]) {
          angular.forEach($scope.data[vocab][key].children, function(child, itemKey) {
            var childID = child.id;

            if (childID in $scope.model[vocab] && $scope.model[vocab][childID] === true) {
              $scope.model[vocab][childID] = false;
              if (vocab == 'categories') {
                angular.element('input[type=checkbox][value="' + key + '"]').prop("checked", false);
              }
              else {
                angular.element('input[type=checkbox][name="' + vocab + '[und][' + key + ']"]').prop("checked", false);
              }
            }
          });
        }
      }
    };

    /**
     * When clicking on the "X" next to the taxonomy-term name
     * On the full form page.
     *
     * @param key
     *  The ID of the taxonomy.
     * @param vocab
     *  The name of the vocabulary.
     */
    $scope.removeTaxonomyValue = function(key, vocab) {
      $scope.model[vocab][key] = false;
      $scope.updateSelectedTerms(key, vocab);
    };

    /**
     * Close all popovers on "ESC" key press.
     *
     * @param event.
     *  The press button event.
     */
    $document.on('keyup', function(event) {
      // 27 is the "ESC" button.
      if(event.which == 27) {
        angular.forEach($scope.popups, function (value, key) {
          if (name != key) {
            this[key] = 0;
          }
        }, $scope.popups);
       $scope.$digest();
      }
    });

    /**
     * Uploading document file.
     *
     * @param $files
     *  The file.
     * @param fieldName
     *  Name of the current field.
     */
    $scope.onFileSelect = function($files, fieldName) {
      console.log(fieldName);
      $scope.setFieldName(fieldName);
      //$files: an array of files selected, each file has name, size, and type.
      for (var i = 0; i < $files.length; i++) {
        var file = $files[i];
        FileUpload.upload(file).then(function(data) {
          var fileId = data.data.data[0].id;
          $scope.data.fileName = data.data.data[0].label;
          $scope.serverSide.file = data;
          Drupal.overlay.open(DrupalSettings.getData('purl') + '/overlay-file/' + fileId + '/' + fieldName + '?render=overlay');
        });
      }
    };


    /**
     * Opens the system's file browser.
     */
    $scope.browseFiles = function(fieldName) {
      angular.element('#' + fieldName).click();
    };

    /**
     * Set the name of the current field.
     *
     * @param fieldName
     */
    $scope.setFieldName = function(fieldName) {
      $scope.fieldName = fieldName;
    };
  });
