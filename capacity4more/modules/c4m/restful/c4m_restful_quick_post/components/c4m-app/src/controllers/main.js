'use strict';

angular.module('c4mApp')
  .controller('MainCtrl', function($scope, DrupalSettings, GoogleMap, EntityResource, Request, $window, $document, $modal, QuickPostService, $interval, $sce, FileUpload) {

    $scope.data = DrupalSettings.getData('entity');

    // Checking if this is full form or not.
    $scope.fullForm = DrupalSettings.getData('full_form');

    // Getting all existing documents.
    $scope.documents = DrupalSettings.getDocuments();

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

    // Getting the activity stream.
    $scope.existingActivities = DrupalSettings.getActivities();

    // Range of the initial loaded activity stream.
    $scope.range = 20;

    // Display the "show more" button only if the activity stream is equal to the the range.
    $scope.showMoreButton = $scope.existingActivities.length >= $scope.range;

    $scope.basePath = DrupalSettings.getBasePath();

    // Empty new activities.
    $scope.newActivities = [];

    // Activity stream status, refresh time.
    $scope.stream = {
      // The first one is the last loaded activity, (if no activities, insert 0).
      lastLoadedID: $scope.existingActivities.length > 0 ? $scope.existingActivities[0].id : 0,
      firstLoadedID: $scope.existingActivities.length > 0 ? $scope.existingActivities[$scope.existingActivities.length - 1].id : 0,
      status: 0
    };

    // refresh rate of the activity stream (60000 is one minute).
    // @TODO: Import the refresh rate from the drupal settings.
    $scope.refreshRate = 60000;

    /**
     * Refreshes the activity stream.
     * The refresh rate is scope.refreshRate.
     */
    $scope.refresh = function() {
      $scope.addNewActivities('newActivities');
    };
    // Start the activity stream refresh.
    $scope.refreshing = $interval($scope.refresh, $scope.refreshRate);

    /**
     * Adds newly fetched activities to either to the activity-stream or the load button,
     * Depending on if the current user added an activity or it's fetched from the server.
     *
     * @param type
     *  Determines to which variable the new activity should be added,
     *  existingActivities: The new activity will be added straight to the activity stream. (Highlighted as well)
     *  newActivities: The "new posts" notification button will appear in the user's activity stream.
     */
    $scope.addNewActivities = function(type) {
      if (type == 'existingActivities') {
        // Merge all the loaded activities before adding the created one.
        $scope.showNewActivities(0);
      }

      var activityStreamInfo = {
        group: $scope.data.group,
        lastId: $scope.stream.lastLoadedID
      };

      // Don't send a request when data is missing.
      if(!activityStreamInfo.lastId || !activityStreamInfo.group) {
        // If last ID is 0, this is a new group and there's no activities.
        if(activityStreamInfo.lastId != 0) {
          $scope.stream.status = 500;
          return false;
        }
      }

      // Call the update stream method.
      EntityResource.updateStream(activityStreamInfo)
        .success( function (data, status) {
          // Update the stream status.
          $scope.stream.status = status;

          // Update if there's new activities.
          if (data.data) {
            // Count the activities that were fetched.
            var position = 0;
            angular.forEach(data.data, function (activity) {
              this.splice(position, 0, {
                id: activity.id,
                html: $sce.trustAsHtml(activity.html)
              });
              position++;
            }, $scope[type]);

            // Update the last loaded ID.
            // Only if there's new activities from the server.
            $scope.stream.lastLoadedID = $scope[type][0].id ? $scope[type][0].id : $scope.stream.lastLoadedID;
          }
        })
        .error( function (data, status) {
          // Update the stream status if we get an error, This will display the error message.
          $scope.stream.status = status;
        });
    };

    /**
     * Merge the "new activity" with the existing activity stream.
     * When a user has clicked on the "new posts", we grab the activities in the "new activity" group and push them to the top of the "existing activity", and clear the "new activity" group.
     *
     * @param position.
     *  The position in which to add the new activities.
     */
    $scope.showNewActivities = function(position) {
      angular.forEach ($scope.newActivities, function (activity) {
        this.splice(position, 0, {
          id: activity.id,
          html: activity.html
        });
        position++;
      }, $scope.existingActivities);
      $scope.newActivities = [];
    };

    /**
     * When clicking on the "show more" button,
     * Request the next set of activities from RESTful,
     * Adds the newly loaded activity stream to the bottom of the "existingActivities" array.
     */
    $scope.showMoreActivities = function() {
      // Determine the position of the loaded activities depending on the number of the loaded page.
      var position = $scope.existingActivities.length;
      // For loading the next page, Every time the "show more" button is clicked, We add 1 to the "activityPage" variable.
      $scope.activityPage++;

      EntityResource.loadMoreStream($scope.data.group, $scope.stream.firstLoadedID)
        .success( function (data, status) {
          if (data.data) {
            angular.forEach(data.data, function (activity) {
              this.splice(position, 0, {
                id: activity.id,
                html: $sce.trustAsHtml(activity.html)
              });
              position++;
            }, $scope.existingActivities);

            // Update the ID of the last activity in the activity stream.
            $scope.stream.firstLoadedID = data.data[data.data.length - 1].id;

            // Keep the "show more" button, only if the remaining activities to load is more than the range.
            // The "Count" variable will go down as we are filtering with the lowest activity ID.
            $scope.showMoreButton = data.count >= $scope.range;
          }
        });
    };

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

      // Stop the "Activity-stream" auto refresh When submitting a new activity,
      // because we don't want the auto refresh to display the activity as an old one.
      $interval.cancel($scope.refreshing);

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

            // Scroll to the top of the page 50px down.
            angular.element('html, body').animate({scrollTop:50}, '500', 'swing');

            // Add the newly created activity to the stream.
            $scope.addNewActivities('existingActivities');

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
      $scope.refreshing = $interval($scope.refresh, $scope.refreshRate);
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
