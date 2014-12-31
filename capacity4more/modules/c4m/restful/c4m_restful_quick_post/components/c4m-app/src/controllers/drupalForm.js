'use strict';

angular.module('c4mApp')
  .controller('DrupalFormCtrl', function($scope, DrupalSettings, EntityResource, Request, $window, $document, $modal, QuickPostService, $filter, FileUpload) {

    $scope.data = DrupalSettings.getData('vocabularies');

    $scope.data.group = DrupalSettings.getData('group');

    // Get related to the discussion documents.
    var val = jQuery('#edit-c4m-related-document-und').val();
    var ids = [];
    if (val && val.length > 0) {
      ids = val.match(/\d+(?=\))/g);
      jQuery('#related-documents').val(ids.join());
    }

    $scope.data.relatedDocuments = ids;

    $scope.model = {};

    $scope.basePath = DrupalSettings.getBasePath();

    $scope.tagIds = 14;

    $scope.values = DrupalSettings.getData('values');

    angular.forEach($scope.data, function(values, vocab) {
      $scope.model[vocab] = {};
    });

    angular.forEach($scope.values, function(values, vocab) {
      angular.forEach(values, function(value, id) {
        $scope.model[vocab][id] = value;
      });
    });

    $scope.popups = [];
    angular.forEach($scope.data, function(value, key) {
      $scope.popups[key] = 0;
    });

    $scope.filteredTerms = angular.copy($scope.data);

    $scope.updateSearch = function(vocab) {
      $scope.filteredTerms[vocab] = $filter('termsFilter')($scope.data[vocab], $scope.searchTerm);
    };

    // Toggle the visibility of the popovers.
    $scope.togglePopover = function(name, event) {
      QuickPostService.togglePopover(name, event, $scope.popups);
    };

    // Close all popovers on "ESC" key press.
    $scope.keyUpHandler = function(keyEvent) {
      QuickPostService.keyUpHandler(keyEvent, $scope);
    };

    // Getting matching tags.
    $scope.tagsQuery = function (query) {
      QuickPostService.tagsQuery(query, $scope);
    };

    $scope.$watch('data.tags', function() {

      var tags = [];
      angular.forEach ($scope.data.tags, function(tag) {
        if (!tag.isNew) {
          tags.push(tag.text + ' (' + tag.id + ')');
        }
      });
      angular.element('#edit-og-vocabulary-und-0-22').val(tags.join(', '));
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
    function updateTerms(key, vocab) {
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
    }

    $scope.updateSelectedTerms = function(key, vocab) {
      updateTerms(key, vocab);
    };

    $scope.removeTaxonomyValue = function(key, vocab) {
      $scope.model[vocab][key] = false;
      updateTerms(key, vocab);
    };
      // Call the keyUpHandler function on key-up.
    $document.on('keyup', $scope.keyUpHandler);

    /**
     * Uploading document file.
     *
     * @param $files
     *  The file.
     */
    $scope.onFileSelect = function($files) {
      //$files: an array of files selected, each file has name, size, and type.
      for (var i = 0; i < $files.length; i++) {
        var file = $files[i];
        FileUpload.upload(file).then(function(data) {
          var fileId = data.data.data[0].id;
          $scope.data.fileName = data.data.data[0].label;
          $scope.serverSide.file = data;
          Drupal.overlay.open(DrupalSettings.getData('purl') + '/overlay-file/' + fileId + '?render=overlay');
        });
      }
    };


    /**
     * Opens the system's file browser.
     */
    $scope.browseFiles = function() {
      angular.element('#document_file').click();
    };

  });
