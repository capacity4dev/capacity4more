'use strict';

angular.module('c4mApp')
  .controller('MainCtrl', function($scope, DrupalSettings, EntityResource, Request, $window, $document, $http, FileUpload, $modal, QuickPostService) {

    $scope.data = DrupalSettings.getData('entity');

    // Checking if this is full form or not.
    $scope.fullForm = DrupalSettings.getData('full_form');

    // Getting all existing documents.
    $scope.documents = DrupalSettings.getDocuments();

    //Getting node id if we are editing node.
    $scope.id = $scope.data.entityId;

    // Getting the resources information.
    $scope.resources = DrupalSettings.getResources();

    if (Object.keys($scope.resources).length > 1) {
      // Setting empty default resource.
      $scope.selectedResource = '';
    }
    else {
      $scope.selectedResource = Object.keys($scope.resources)[0];
    }

    // Getting the fields information.
    $scope.fieldSchema = DrupalSettings.getFieldSchema();

    $scope.debug = DrupalSettings.getDebugStatus();

    $scope = QuickPostService.setDefaults($scope);

    /**
     * Prepares the referenced "data" to be objects and normal field to be empty.
     * Responsible for toggling the visibility of the taxonomy-terms checkboxes.
     * Set "popups" to 0, as to hide all of the pop-overs on load.
     */
    function prepareData() {
      $scope.popups = {};

      angular.forEach($scope.fieldSchema, function (data, field) {
        // Don't change the group field or the resource object.
        if (field == 'resources' || field == 'group') {
          return;
        }
        var allowedValues = data.form_element.allowed_values;
        if(angular.isObject(allowedValues) && Object.keys(allowedValues).length && field != "tags") {
          $scope.referenceValues[field] = allowedValues;
          $scope.popups[field] = 0;
          if (!$scope.data[field]) {
            // Field is empty.
            $scope.data[field] = {};
          }
          else {
            // Field has value and this is not a discussion or event type field,
            // which is actually not an object.
            if (field != 'discussion_type' && field != 'event_type') {
              var obj = {};
              angular.forEach($scope.data[field], function (value, key) {
                obj[value] = true;
              });
              $scope.data[field] = obj;
            }
          }
        }
      });

      if (angular.isDefined($scope.data.discussion_type)) {
        // Set "Start a Debate" as default discussion type.
        $scope.data.discussion_type = angular.isObject($scope.data.discussion_type) ? 'debate' : $scope.data.discussion_type;
      }

      if (angular.isDefined($scope.data.event_type)) {
        // Set "Event" as default event type.
        $scope.data.event_type = angular.isObject($scope.data.event_type) ? 'event' : $scope.data.event_type;
      }
    }

    // Preparing the data for the form.
    prepareData();

    $scope = QuickPostService.formatTermFieldsAsTree($scope);

    // Displaying the fields upon clicking on the label field.
    $scope.showFields = function() {
      $scope.selectedResource = QuickPostService.showFields($scope.selectedResource);
    }

    // Getting matching tags.
    $scope.tagsQuery = function (query) {
      QuickPostService.tagsQuery(query, $scope);
    };



    // Updates the bundle of the entity to send to the correct API url.
    $scope.updateResource = function(resource, event) {
      $scope.selectedResource = QuickPostService.updateResource(resource, event);
    };

    // Updates the type of the selected resource.
    $scope.updateType = function(type, field, event) {
      $scope.data[field] = QuickPostService.updateType(type, field, event);
    };

    // Toggle the visibility of the popovers.
    $scope.togglePopover = function(name, event) {
      QuickPostService.togglePopover(name, event, $scope.popups);
    };

    // Close all popovers on "ESC" key press.
    $scope.keyUpHandler = function(keyEvent) {
      QuickPostService.keyUpHandler(keyEvent, $scope);
    };

    // Call the keyUpHandler function on key-up.
    $document.on('keyup', $scope.keyUpHandler);

    /**
     * Submit form.
     *
     *  @param data
     *    The submitted data.
     *  @param resource
     *    The bundle of the node submitted.
     *  @param type
     *    The type of the submission.
     */
    $scope.submitForm = function(data, resource, type) {
      // Reset all errors.
      $scope.errors = {};

      // Get the fields of this resource.
      var resourceFields = $scope.fieldSchema.resources[resource];

      // Clean the submitted data, Drupal will return an error on undefined fields.
      var submitData = Request.cleanFields(data, resourceFields);

      // Check for required fields.
      var errors = Request.checkRequired(submitData, resource, resourceFields);

      // Check the type of the submit.
      // Make node unpublished if requested to create in full form.
      submitData.status = type == 'full_form' ? 0 : 1;

      // Cancel submit and display errors if we have errors.
      if (Object.keys(errors).length && type == 'quick_post') {
        angular.forEach( errors, function(value, field) {
          this[field] = value;
        }, $scope.errors);
        return false;
      }

      // Call the create entity function service.
      EntityResource.createEntity(submitData, resource, resourceFields, $scope.id)
      .success( function (data, status) {
        // If requested to create in full form, Redirect user to the edit page.
        if(type == 'full_form') {
          var entityID = data.data[0].id;
          $window.location = DrupalSettings.getBasePath() + "node/" + entityID + "/js-edit";
        }
        else {
          $scope.serverSide.data = data;
          $scope.serverSide.status = status;
          prepareData();
        }
      })
      .error( function (data, status) {
        $scope.serverSide.data = data;
        $scope.serverSide.status = status;
        prepareData();
      });
    };

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
          $scope.data.document = data.data.data[0].id;
          $scope.data.fileName = data.data.data[0].label;
          $scope.serverSide.file = data;

          if ($scope.fullForm && $scope.selectedResource == 'discussions') {
            // If we are creating or editing discussion in the full form -
            // after loading file send file id to the modal, where we'll create
            // a document with this file.

            $scope.open = function (size) {

              var modalInstance = $modal.open({
                templateUrl: 'myModalContent.html',
                controller: 'ModalInstanceCtrl',
                size: size,
                resolve: {
                  getScope: function () {
                    return $scope;
                  }
                }
              });

              modalInstance.result.then(function (document) {
                $scope.data.related_document.push(document.id);
                document.id = parseInt(document.id);
                // Add new document to list of all documents.
                $scope.documents.push(document);
              });
            };

            $scope.open();
          }
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
