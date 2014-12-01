'use strict';

angular.module('c4mApp')
  .controller('MainCtrl', function($scope, DrupalSettings, EntityResource, Request, $window, $document, $http, $interval, $sce, FileUpload) {

    $scope.data = DrupalSettings.getData('entity');

    // Getting the resources information.
    $scope.resources = DrupalSettings.getResources();

    // Setting empty default resource.
    $scope.selectedResource = '';

    // Getting the fields information.
    $scope.fieldSchema = DrupalSettings.getFieldSchema();

    $scope.debug = DrupalSettings.getDebugStatus();

    // Getting the activity stream.
    $scope.existingActivities = DrupalSettings.getActivities();

    // Empty new activities.
    $scope.newActivities = [];

    $scope.referenceValues = {};

    $scope.errors = {};

    $scope.serverSide = {
      status: 0,
      data: {}
    };

    $scope.tagsQueryCache = [];

    // Date Calendar options.
    $scope.minDate = new Date();

    $scope.startOpened = false;

    $scope.endOpened = false;


    $scope.dateOptions = {
      formatYear: 'yyyy',
      startingDay: 1
    };

    $scope.format = 'dd/MM/yyyy';

    // Time picker options.
    // Hour step.
    $scope.hstep = 1;
    // Minute step.
    $scope.mstep = 1;


    // Activity stream status, refresh time.
    $scope.stream = {
      // The first one is the last loaded activity, (if no activities, insert 0).
      lastLoadedID: $scope.existingActivities.length > 0 ? $scope.existingActivities[0].id : 0,
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
        $scope.showNewActivities();
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
     */
    $scope.showNewActivities = function() {
      var position = 0;
      angular.forEach ($scope.newActivities, function (activity) {
        this.splice(position, 0, {
          id: activity.id,
          created: activity.created,
          html: activity.html
        });
        position++;
      }, $scope.existingActivities);
      $scope.newActivities = [];
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
            $scope.data[field] = {};
          }
        });
      });

      // Reset all the text fields.
      var textFields = ['label', 'body', 'tags', 'organiser' , 'datetime'];
      angular.forEach(textFields, function (field) {
        $scope.data[field] = field == 'tags' ? [] : '';
      });
    }

    // Preparing the data for the form.
    initFormValues();

    // Prepare all the taxonomy-terms to be a tree object.
    angular.forEach($scope.referenceValues, function (data, field) {
      var parent = 0;
      $scope[field] = {};
      angular.forEach($scope.referenceValues[field], function (label, id) {
        if(label.indexOf('-')) {
          parent = id;
          $scope[field][id] = {
            id: id,
            label: label,
            children: []
          };
        }
        else {
          if (parent > 0) {
            $scope[field][parent]['children'].push({
              id: id,
              label: label.replace('-','')
            });
          }
        }
      });
    });

    /**
     * Display the fields upon clicking on the label field.
     */
    $scope.showFields = function () {
      if (!$scope.selectedResource) {
        $scope.selectedResource = 'discussions';
      }
    };

    /**
     * Get matching tags.
     *
     * @param query
     *   The query string.
     */
    $scope.tagsQuery = function (query) {
      var group = {id: $scope.data.group};
      var url = DrupalSettings.getBasePath() + 'api/tags';
      var terms = {results: []};

      var lowerCaseTerm = query.term.toLowerCase();
      if (angular.isDefined($scope.tagsQueryCache[lowerCaseTerm])) {
        // Add caching.
        terms.results = $scope.tagsQueryCache[lowerCaseTerm];
        query.callback(terms);
        return;
      }

      $http.get(url + '?autocomplete[string]=' + query.term + '&group=' + group.id)
        .success(function(data) {
          if (data.data.length == 0) {
            terms.results.push({
              text: query.term,
              id: query.term,
              isNew: true
            });
          }
          else {
            angular.forEach(data.data, function (label, id) {
              terms.results.push({
                text: label,
                id: id,
                isNew: false
              });
            });
            $scope.tagsQueryCache[lowerCaseTerm] = terms;
          }

          query.callback(terms);
        });
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

    /**
     * Toggle the visibility of the popovers.
     *
     * @param name
     *  The name of the pop-over.
     *
     *  @param event
     *    The click event.
     */
    $scope.togglePopover = function(name, event) {
      // Hide all the other pop-overs, Except the one the user clicked on.
      angular.forEach($scope.popups, function (value, key) {
        if (name != key) {
          this[key] = 0;
        }
      }, $scope.popups);
      // Get the width of the element clicked in the event.
      var elemWidth = angular.element(event.target).outerWidth();
      var elemPosition = angular.element(event.target).offset();
      var elemParentPosition = angular.element(event.target).parent().offset();
      // Toggle the visibility variable.
      $scope.popups[name] = $scope.popups[name] == 0 ? 1 : 0;
      // Move the popover to be at the end of the button.
      angular.element(".hidden-checkboxes").css('left', (elemPosition.left - elemParentPosition.left) + elemWidth);
    };

    /**
     * Close all popovers on "ESC" key press.
     */
    $scope.keyUpHandler = function(keyEvent) {
      if(keyEvent.which == 27) {
        angular.forEach($scope.popups, function (value, key) {
          this[key] = 0;
          // Re-Bind the JS with the HTML with "digest".
          $scope.$digest();
        }, $scope.popups);
      }
    };
    // Call the keyUpHandler function on key-up.
    $document.on('keyup', $scope.keyUpHandler);

    /**
     * Submit form.
     *
     *  @param data
     *    The submitted data.
     *
     *  @param resource
     *    The bundle of the node submitted.
     *
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
      EntityResource.createEntity(submitData, resource, resourceFields)
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
          $scope.serverSide.file = data;
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
