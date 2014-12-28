angular.module('c4mApp')
  .controller('DrupalFormCtrl', function($scope, DrupalSettings, EntityResource, Request, $window, $document, $modal, QuickPostService, $filter, FileUpload) {

    $scope.data = DrupalSettings.getData('vocabularies');

    $scope.data.relatedDocuments = {};

    $scope.relatedIds = '';

    $scope.baseUrl = DrupalSettings.getBasePath();

    $scope.model = {};

    // Getting all existing documents.
    $scope.documents = DrupalSettings.getDocuments();

    $scope.values = DrupalSettings.getData('values');

    angular.forEach($scope.values, function(values, vocab) {
      angular.forEach(values, function(value, id) {
        $scope.model[id] = value;
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

    function updateTerms(key, vocab) {
      // Check/uncheck the checkbox in the drupal form.
      if($scope.model[key]) {
        jQuery('input[type=checkbox][value="' + key + '"]').attr("checked", true);
      }
      else {
        jQuery('input[type=checkbox][value="' + key + '"]').attr("checked", false);
        if (key in $scope.data[vocab]) {
          angular.forEach($scope.data[vocab][key].children, function(child, itemKey) {
            var childID = child.id;

            if (childID in $scope.model && $scope.model[childID] === true) {
              $scope.model[childID] = false;
              jQuery('input[type=checkbox][value="' + childID + '"]').attr("checked", false);
            }
          });
        }
      }
    }

    $scope.updateSelectedTerms = function(key, vocab) {
      updateTerms(key, vocab);
    };

    $scope.removeTaxonomyValue = function(key, vocab) {
      $scope.model[key] = false;
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
          Drupal.overlay.open(DrupalSettings.getData('purl') + '/add-file/' + fileId + '?render=overlay');
        });
      }
    };
    /**
     * Create document node.
     *
     * @param event
     *  The submit event.
     * @param fileId
     *  Id of the attached file.
     * @param data
     *  The submitted data.
     * @param addToLibrary
     *  Open or not full form of adding document.
     */
    $scope.createDocument = function(event, fileId, data, addToLibrary) {
      // Preventing the form from redirecting to the "action" url.
      // We nee the url in the action because of the "overlay" module.
      event.preventDefault();
      $scope.fieldSchema = DrupalSettings.getFieldSchema();
      var resourceFields = $scope.fieldSchema.resources['documents'];
      var submitData = Request.cleanFields(data, resourceFields);

      angular.forEach(resourceFields, function (data, field) {
        // Don't change the group field Or resource object.
        if (field == 'resources' || field == 'group' || field == "tags") {
          return;
        }
        var allowedValues = field == "categories" ? data.form_element.allowed_values.categories : data.form_element.allowed_values;
        if(angular.isObject(allowedValues) && Object.keys(allowedValues).length) {
          submitData[field] = {};
        }

        var textFields = ['label', 'body', 'tags', 'organiser' , 'datetime'];
        angular.forEach(textFields, function (field) {
          if (!field){
            submitData[field] = field == 'tags' ? [] : '';
          }
        });
      });
      submitData.document = fileId;
      submitData.group = DrupalSettings.getData('groupID');

      EntityResource.createEntity(submitData, 'documents', resourceFields)
        .success( function (data, status) {
          var nid = data.data[0].id;

          if (!addToLibrary) {
            var item = '(' + nid + ')';

            // Multiple values.
            var value = jQuery('#edit-c4m-related-document-und', parent.window.document).val();
            var nids = jQuery('#related-documents', parent.window.document).val();
            if (value.indexOf(item) == -1) {
              value = value ? value + ', ' + item : item;
              nids = nids ? nids + ',' + nid : nid;
            }

            jQuery('#edit-c4m-related-document-und', parent.window.document).val(value);
            jQuery('#related-documents', parent.window.document).val(nids).trigger('click');


            parent.Drupal.overlay.close();
          }
          else {
            parent.Drupal.overlay.redirect(DrupalSettings.getData('purl') + '/node/' + nid + '/edit' + '?render=overlay');
          }

        });
    };
  });
