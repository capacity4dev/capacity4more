/**
 * @file
 * Provides the Main Controller (MainCtrl) for the c4mApp.
 */

'use strict';

angular.module('c4mApp')
  .controller('MainCtrl', function ($rootScope, $scope, DrupalSettings, GoogleMap, EntityResource, Request, $window, $document, QuickPostService, FileUpload) {
    $scope.editorOptions = {
      resize_minHeight : 300,
      height: 200
    };
    $scope.data = DrupalSettings.getData('entity');

    // Getting the resources information.
    $scope.resources = DrupalSettings.getResources();
    $scope.resourceSpinner = false;

    if ($scope.resources) {
        // Setting empty default resource.
        $scope.selectedResource = '';
    }

    // Getting the fields information.
    $scope.fieldSchema = {};

    // Hide quickpost title field placeholder on focus.
    $scope.titlePlaceholder = true;
    $scope.titlePlaceholderText = 'Start a discussion, share an idea...';

    $scope = QuickPostService.setDefaults($scope);

    /**
     * Prepares the referenced "data" to be objects and normal field to be empty.
     *
     * Responsible for toggling the visibility of the taxonomy-terms checkboxes.
     * Set "popups" to 0, as to hide all of the pop-overs on load.
     *
     * @param resource_name
     *   The name of the resource.
     */
    function initFormValues(resource_name) {
      $scope.popups = {};

      angular.forEach($scope.fieldSchema.resources[resource_name], function (data, field) {
        // Don't change the group field Or resource object.
        if (field == 'resources' || field == 'group' || field == "tags") {
          return;
        }
        var allowedValues = field == "categories" ? $scope.fieldSchema.categories : data.form_element.allowed_values;

        if (angular.isObject(allowedValues)) {
          $scope.referenceValues[field] = allowedValues;
          $scope.popups[field] = 0;
          $scope.data[field] = {};
        }
      });

      $scope = QuickPostService.formatTermFieldsAsTree($scope);

      // Set "Start a Debate" as default discussion type.
      $scope.data.discussion_type = 'info';

      // Set "Event" as default event type.
      $scope.data.event_type = 'event';

      // Reset all the text fields.
      var textFields = ['label', 'body', 'tags', 'organiser' , 'datetime'];
      angular.forEach(textFields, function (field) {
        $scope.data[field] = field == 'tags' ? [] : '';
      });

      $scope.data['add_to_library'] = 1;

      // Default location is empty.
      $scope.data.location = {};
      $scope.data.location.street = '';
      $scope.data.location.city = '';
      $scope.data.location.postal_code = '';
      $scope.data.location.country_name = '';
      $scope.data.location.location_name = '';
    }

    /**
     * Getting matching tags.
     *
     * @param query
     *  The query input by the user.
     */
    $scope.tagsQuery = function (query) {
      QuickPostService.tagsQuery(query, $scope);
    };

    /**
     * Called by the directive "bundle-select".
     *
     * Updates the bundle of the entity to send to the correct API url.
     *
     * @param resource
     *  The resource name.
     *  @param event
     *    The event where the function was called.
     */
    $scope.updateResource = function (resource, event) {
      // When clicking on the "label" input
      // and the resource is already selected, Do nothing.
      if (angular.isDefined(event) && $scope.selectedResource) {
        return false;
      }
      // Empty fields info.
      $scope.fieldSchema = {};
      $scope.referenceValues = {};
      // If resource is selected, Close form.
      if ($scope.selectedResource == resource) {
        $scope.selectedResource = '';
        return false;
      }
      $scope.resourceSpinner = true;
      // Update Bundle,
      // Update the fields information for this resource.
      DrupalSettings.getFieldSchema(resource)
        .success(function (data) {
          $scope.fieldSchema = data.c4m.field_schema;
          $scope.data.entity = data.c4m.data.entity;
          initFormValues(resource);
          $scope.selectedResource = resource;
          $scope.resourceSpinner = false;
        });
    };

    /**
     * Helper function to manage the flow of focusing the quick post title.
     *
     * When focusing the quick post title we should hide the placeholder from
     * it and try to update the resource.
     *
     * @see $scope.updateResource()
     */
    $scope.focusQuickPostTitle = function (resource, event) {
      $scope.titlePlaceholder = false;
      $scope.updateResource(resource, event);
    };

    /**
     * Remove taxonomy term from the data.
     *
     * Called by click on added term.
     *
     * @param key
     *  taxonomy term id
     * @param field
     *  name of the taxonomy terms field.
     */
    $scope.removeTaxonomyValue = function (key, field) {
      $scope.data[field][key] = false;

      angular.forEach($scope[field], function (term, id) {
        // Go through all 1 level terms.
        angular.forEach($scope[field][id].children, function (child, childKey) {
          var childID = child.id;
          // If removed current 1 level term - all 2 and 3 level terms will be removed.
          // If removed current 2 level term - all 3 level terms will be removed.
          if (id == key || childID == key) {
            if (childID in $scope.data[field] && $scope.data[field][childID] === true) {
              $scope.data[field][childID] = false;
            }
            angular.forEach($scope[field][id].children[childKey].children, function (childChild, childChildKey) {
              var childChildID = childChild.id;
              if (childChildID in $scope.data[field] && $scope.data[field][childChildID] === true) {
                $scope.data[field][childChildID] = false;
              }
            });
          }
        });
      });
    };

    // Find taxonomy term name.
    $scope.findLabel = function (vocab, termID) {
      return QuickPostService.findLabel(vocab, termID);
    };

    /**
     * Called by the directive "types".
     *
     * Updates the type of the selected resource.
     *
     * @param type
     *  The type.
     * @param field
     *  The name of the field.
     */
    $scope.updateType = function (type, field) {
      // Update type field.
      $scope.data[field] = $scope.data[field] == type ? '' : type;
    };

    // Toggle the visibility of the popovers.
    $scope.togglePopover = function (name, event) {
      QuickPostService.togglePopover(name, event, $scope.popups);
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
        if (!$scope[vocab][key].children[childKey]) {
          // This term has been removed.
          return false;
        }
        if (!$scope[vocab][key].children[childKey].children) {
          // This term doesn't have children at all.
          return false;
        }
        for (var i = 0; i < $scope[vocab][key].children[childKey].children.length; i++) {
          var id = $scope[vocab][key].children[childKey].children[i].id;
          if ($scope.data[vocab][id] === true) {
            return true;
          }
        }
      }
      else {
        // This is 1-level term.
        if (!$scope[vocab][key]) {
          // This term has been removed.
          return false;
        }
        if (!$scope[vocab][key].children) {
          // This term doesn't have children at all.
          return false;
        }
        for (var i = 0; i < $scope[vocab][key].children.length; i++) {
          var id = $scope[vocab][key].children[i].id;
          if ($scope.data[vocab][id] === true) {
            return true;
          }
        }
      }
      return false;
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
     * Submit form.
     *
     * Stops auto-refresh, Cleans fields (delete fields that doesn't belong to
     * the entity being created).
     * Adds location details (lat, lng) to the "event" entity.
     * Sends the cleaned-up data to the checkForm function for entity
     * creation.
     *
     *  @param data
     *    The submitted data.
     *  @param resource
     *    The bundle of the node submitted.
     *  @param type
     *    The type of the submission.
     */
    $scope.submitForm = function (data, resource, type) {

      // Stop the "Activity-stream" auto refresh When submitting a new activity,
      // because we don't want the auto refresh to display the activity as an old one.
      $rootScope.$broadcast('c4m.activity.refresh', 'stop');

      // Reset all errors.
      $scope.errors = {};

      // Get the fields of this resource.
      var resourceFields = $scope.fieldSchema.resources[resource];

      // Clean the submitted data, Drupal will return an error on undefined fields.
      var submitData = Request.cleanFields(data, resourceFields);

      checkForm(submitData, resource, resourceFields, type);
    };

    /**
     * Continue submitting form.
     *
     * Creates a node of the resource type. If Type of submission is
     * a full form - redirects to the created node's editing page.
     *
     * @param submitData
     *  The submitting data.
     * @param resource
     *  The bundle of the node submitted.
     * @param resourceFields
     *  The fields of the current resource.
     * @param type
     *  The type of the submission.
     */
    var checkForm  = function (submitData, resource, resourceFields, type) {
      // Check for required fields.
      var errors = Request.checkRequired(submitData, resource, resourceFields);

      // Check the type of the submit.
      // Make node unpublished if requested to create in full form.
      submitData.status = type == 'full_form' ? 0 : 1;

      // Cancel submit and display errors if we have errors.
      if (Object.keys(errors).length) {
        angular.forEach(errors, function (value, field) {
          this[field] = value;
        }, $scope.errors);
        // Scroll up upon discovering an error.
        // The last error is the point of reference to scroll.
        var errorName = Object.keys(errors)[Object.keys(errors).length - 1];
        // In the body input we point to the parent div because of textAngular.
        var errorInput = errorName == 'body' ? angular.element('#' + errorName + '-wrapper').offset() : angular.element('#' + errorName).offset();
        angular.element('html, body').animate({scrollTop:errorInput.top}, '500', 'swing');
        return false;
      }

      // Call the create entity function service.
      EntityResource.createEntity(submitData, resource, resourceFields)
        .success(function (data, status) {
          // If requested to create in full form, Redirect user to the edit page.
          if (type == 'full_form') {
            var entityID = data.data[0].id;
            $window.location = DrupalSettings.getPurlPath() + "/node/" + entityID + "/edit";
          }
          else {
            $scope.serverSide.data = data;
            $scope.serverSide.status = status;

            // Scroll up upon creating a new activity.
            // Reference the point to scroll to the top of the form (Title input is at the top of the form).
            var labelInput = angular.element('#label').offset();
            angular.element('html, body').animate({scrollTop:labelInput.top}, '500', 'swing');

            // Add the newly created activity to the stream.
            // By broadcasting the update to the "activity" controller.
            $rootScope.$broadcast('c4m.activity.update');

            // Collapse the quick-post form.
            $scope.selectedResource = '';
          }
        })
        .error(function (data, status) {
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
    $scope.onFileSelect = function ($files) {
      // $files: an array of files selected, each file has name, size, and type.
      for (var i = 0; i < $files.length; i++) {
        var file = $files[i];
        FileUpload.upload(file).then(function (data) {
          $scope.data.document = data.data.data[0].id;
          $scope.data.fileName = data.data.data[0].label;
          $scope.serverSide.file = data;
        });
      }
    };

    /**
     * Remove uploaded file.
     */
    $scope.removeUploadedFile = function () {
      angular.element('#document_file').val('');
      $scope.data.document = null;
      delete $scope.data.fileName;
      delete $scope.serverSide.file;
    };

    /**
     * Opens the system's file browser.
     */
    $scope.browseFiles = function () {
      angular.element('#document_file').click();
    };

    /**
     * Resets the quick-post form validations.
     *
     * Clears all the fields for a new entry.
     */
    $scope.resetEntityForm = function () {
      // Clear any form validation errors.
      $scope.entityForm.$setPristine();
      // Reset all errors.
      $scope.errors = {};
      // Reset all the fields.
      initFormValues();
      // Empty fields info.
      $scope.fieldSchema = {};
      $scope.referenceValues = {};
      // Remove file.
      $scope.removeUploadedFile();
    };

    /**
    * Closes quick-post form.
    */
    $scope.closeQuickPost = function () {
      // Clear all form fields.
      $scope.resetEntityForm();
      // Closes quick-post form.
      $scope.selectedResource = '';
    }
  });
