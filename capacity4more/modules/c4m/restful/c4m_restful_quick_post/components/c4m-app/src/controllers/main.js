'use strict';

angular.module('c4mApp')
  .controller('MainCtrl', function($rootScope, $scope, DrupalSettings, GoogleMap, EntityResource, Request, $window, $document, $modal, QuickPostService, $interval, $sce, FileUpload) {

    $scope.data = DrupalSettings.getData('entity');

    // Checking if this is full form or not.
    $scope.fullForm = DrupalSettings.getData('full_form');

    //Getting node id if we are editing node.
    $scope.id = $scope.data.entityId;

    // Getting the resources information.
    $scope.resources = DrupalSettings.getResources();

    if ($scope.resources) {
      if (Object.keys($scope.resources).length > 1) {
        // Setting empty default resource.
        $scope.selectedResource = '';
      }
      else {
        $scope.selectedResource = Object.keys($scope.resources)[0];
      }
    }

    // Getting the fields information.
    $scope.fieldSchema = DrupalSettings.getFieldSchema();

    $scope.debug = DrupalSettings.getDebugStatus();

    $scope = QuickPostService.setDefaults($scope);

    $scope.basePath = DrupalSettings.getBasePath();

    /**
     * Prepares the referenced "data" to be objects and normal field to be empty.
     * Responsible for toggling the visibility of the taxonomy-terms checkboxes.
     * Set "popups" to 0, as to hide all of the pop-overs on load.
     */
    function initFormValues() {
      $scope.popups = {};

      angular.forEach($scope.resources, function (info, resource_name) {
        angular.forEach($scope.fieldSchema.resources[resource_name], function (data, field) {
          // Don't change the group field Or resource object.
          if (field == 'resources' || field == 'group' || field == "tags") {
            return;
          }
          var allowedValues = field == "categories" ? data.form_element.allowed_values.categories : data.form_element.allowed_values;
          if(angular.isObject(allowedValues) && Object.keys(allowedValues).length) {
            $scope.referenceValues[field] = allowedValues;
            $scope.popups[field] = 0;
            if (!$scope.data[field] || !$scope.fullForm) {
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
      });


      if (angular.isDefined($scope.data.discussion_type)) {
        // Set "Start a Debate" as default discussion type.
        $scope.data.discussion_type = angular.isObject($scope.data.discussion_type) || !$scope.fullForm ? 'debate' : $scope.data.discussion_type;
      }

      if (angular.isDefined($scope.data.event_type)) {
        // Set "Event" as default event type.
        $scope.data.event_type = angular.isObject($scope.data.event_type) || !$scope.fullForm ? 'event' : $scope.data.event_type;
      }

      // Reset all the text fields.
      var textFields = ['label', 'body', 'tags', 'organiser' , 'datetime'];
      angular.forEach(textFields, function (field) {
        if (!field || !$scope.fullForm){
          $scope.data[field] = field == 'tags' ? [] : '';
        }
      });
    }

    // Preparing the data for the form.
    initFormValues();

    $scope = QuickPostService.formatTermFieldsAsTree($scope);

    // Displaying the fields upon clicking on the label field.
    $scope.showFields = function() {
      $scope.selectedResource = QuickPostService.showFields($scope.selectedResource);
    };

    // Getting matching tags.
    $scope.tagsQuery = function (query) {
      QuickPostService.tagsQuery(query, $scope);
    };

    /**
     * Called by the directive "bundle-select",
     * Updates the bundle of the entity to send to the correct API url.
     *
     * @param resource
     *  The resource name.
     */
    $scope.updateResource = function(resource) {
      // Update Bundle.
      $scope.selectedResource = $scope.selectedResource == resource ? '' : resource;
    };

    /**
     * Remove taxonomy term from the data.
     * Called by click on added term.
     *
     * @param key
     *  taxonomy term id
     * @param field
     *  name of the taxonomy terms field.
     */
    $scope.removeTaxonomyValue = function(key, field) {
      $scope.data[field][key] = false;
      // If this is parent term - find all children and turn them to false
      if (key in $scope[field]) {
        angular.forEach($scope[field][key].children, function(child, key) {
          var childID = child.id;
          if (childID in $scope.data[field] && $scope.data[field][childID] === true) {
            $scope.data[field][childID] = false;
          }
        });
      }
    };

    // Find taxonomy term name.
    $scope.findLabel = function(vocab, termID) {
      return QuickPostService.findLabel(vocab, termID);
    };

    /**
     * Called by the directive "types",
     * Updates the type of the selected resource.
     *
     * @param type
     *  The type.
     * @param field
     *  The name of the field.
     */
    $scope.updateType = function(type, field) {
      // Update type field.
      $scope.data[field] = $scope.data[field] == type ? '' : type;
    };

    // Toggle the visibility of the popovers.
    $scope.togglePopover = function(name, event) {
      QuickPostService.togglePopover(name, event, $scope.popups);
    };

    // Close all popovers on "ESC" key press.
    //$document.on('keyup', function(event) {
    //  QuickPostService.keyUpHandler(event, $scope);
    //});

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

      // Stop the "Activity-stream" auto refresh When submitting a new activity,
      // because we don't want the auto refresh to display the activity as an old one.
      $rootScope.$broadcast('c4m.activity.refresh', 'stop');

      // Reset all errors.
      $scope.errors = {};

      // Get the fields of this resource.
      var resourceFields = $scope.fieldSchema.resources[resource];

      // Clean the submitted data, Drupal will return an error on undefined fields.
      var submitData = Request.cleanFields(data, resourceFields);

      if (resource == 'events') {

        // Get the lan/lng of the address from google map.
        GoogleMap.getAddress(submitData, resource).then(function (result) {
          if (result.data.results.length > 0) {
            var location = result.data.results[0].geometry.location;
            submitData.location.lat = location.lat;
            submitData.location.lng = location.lng;
            angular.forEach(result.data.results[0].address_components, function(value, key) {
              // Find country short name.
              if (value.types[0] == 'country') {
                submitData.location.country = value.short_name;
              }
            });
          }
          else {
            // Use default latitude and longitude of Brussels, Belgium.
            submitData.location.lat = 50.850339600000000000;
            submitData.location.lng = 4.351710300000036000;
            submitData.location.country = 'BE';
          }
          // Continue submitting form.
          checkForm(submitData, resource, resourceFields, type);
        });
      }
      else {
        // This is not an Event - just continue submitting.
        checkForm(submitData, resource, resourceFields, type);
      }
    };

    var checkForm  = function(submitData, resource, resourceFields, type) {
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
            $window.location = DrupalSettings.getBasePath() + "node/" + entityID + "/edit";
          }
          else {
            $scope.serverSide.data = data;
            $scope.serverSide.status = status;

            // Scroll to the top of the activity stream (Reference is the label input).
            var labelInput = angular.element('#label').offset();
            angular.element('html, body').animate({scrollTop:labelInput.top}, '500', 'swing');

            // Add the newly created activity to the stream.
            // By broadcasting the update to the "activity" controller.
            $rootScope.$broadcast('c4m.activity.update');

            // Collapse the quick-post form.
            if(!$scope.fullForm) {
              $scope.selectedResource = '';
            }
            else {
              // Go to the entity page after saving in the full form.
              var entityID = data.data[0].id;
              $window.location = DrupalSettings.getBasePath() + "node/" + entityID;
            }
          }
        })
        .error( function (data, status) {
          $scope.serverSide.data = data;
          $scope.serverSide.status = status;
        });

      // Reset the form, by removing existing values and allowing the user to write a new content.
      $scope.resetEntityForm();

      // Resume the "Activity-stream" auto refresh.
      $rootScope.$broadcast('c4m.activity.refresh', 'continue');
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
                $scope.documentName = document.label;
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

    /**
     * Resets the quick-post form validations.
     * Clears all the fields for a new entry.
     */
    $scope.resetEntityForm = function() {
      // Clear any form validation errors.
      $scope.entityForm.$setPristine();
      // Reset all the fields.
      initFormValues();
    }
  });
