'use strict';

angular.module('c4mApp')
  .controller('MainCtrl', function($rootScope, $scope, DrupalSettings, GoogleMap, EntityResource, Request, $window, $document, QuickPostService, FileUpload) {

    $scope.data = DrupalSettings.getData('entity');

    // Getting the resources information.
    $scope.resources = DrupalSettings.getResources();

    if ($scope.resources) {
        // Setting empty default resource.
        $scope.selectedResource = '';
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

          if (angular.isObject(allowedValues)) {
            $scope.referenceValues[field] = allowedValues;
            $scope.popups[field] = 0;
            $scope.data[field] = {};
          }
        });
      });

      // Set "Start a Debate" as default discussion type.
      $scope.data.discussion_type = 'debate';

      // Set "Event" as default event type.
      $scope.data.event_type = 'event';

      // Reset all the text fields.
      var textFields = ['label', 'body', 'tags', 'organiser' , 'datetime'];
      angular.forEach(textFields, function (field) {
        $scope.data[field] = field == 'tags' ? [] : '';
      });

      $scope.data['add_to_library'] = 1;

      $scope.data.location = {};
      $scope.data.location.street = '';
      $scope.data.location.city = '';
      $scope.data.location.postal_code = '';
      $scope.data.location.country_name = '';
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

      angular.forEach($scope[field], function(term, id) {
        // Go through all 1 level terms.
        angular.forEach($scope[field][id].children, function(child, childKey) {
          var childID = child.id;
          // If removed current 1 level term - all 2 and 3 level terms will be removed.
          // If removed current 2 level term - all 3 level terms will be removed.
          if (id == key || childID == key) {
            if (childID in $scope.data[field] && $scope.data[field][childID] === true) {
              $scope.data[field][childID] = false;
            }
            angular.forEach($scope[field][id].children[childKey].children, function(childChild, childChildKey) {
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

    /**
     * Check if current category has at least one selected child.
     *
     * @param key
     *  Category term id.
     *
     * @returns {boolean}
     */
    $scope.categoryHasChildrenSelected = function(key) {
      for (var i = 0; i < $scope.categories[key].children.length; i++) {
        var id = $scope.categories[key].children[i].id;
        if ($scope.data.categories[id] === true) {
          return true;
        }
      }
      return false;
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
        $scope.closePopups();
      }
    });

    /**
     * Close all popovers on click outside popup box.
     *
     * @param event.
     *  The click event.
     */
    $document.on('mousedown', function(event) {
      // Check if we are not clicking on the popup.
      var parents = angular.element(event.target).parents();
      var close = true;
      angular.forEach(parents, function(parent, id) {
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
    $scope.closePopups = function() {
      $scope.$apply(function(scope) {
        angular.forEach($scope.popups, function (value, key) {
          this[key] = 0;
        }, $scope.popups);
      });
    };

    /**
     * Submit form.
     *  Stops auto-refresh, Cleans fields (delete fields that doesn't belong to the entity being created),
     *  Adds location details (lat, lng) to the "event" entity,
     *  Sends the cleaned-up data to the checkForm function for entity creation.
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

    /**
     * Continue submitting form.
     *  Creates a node of the resource type. If Type of submission is
     *  a full form - redirects to the created node's editing page.
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
        .success( function (data, status) {
          // If requested to create in full form, Redirect user to the edit page.
          if (type == 'full_form') {
            var entityID = data.data[0].id;
            $window.location = DrupalSettings.getBasePath() + "node/" + entityID + "/edit";
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
        });
      }
    };

    /**
     * Remove uploaded file.
     */
    $scope.removeFile = function() {
      angular.element('#document_file').val('');
      $scope.data.document = null;
      delete $scope.data.fileName;
      delete $scope.serverSide.file;

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
