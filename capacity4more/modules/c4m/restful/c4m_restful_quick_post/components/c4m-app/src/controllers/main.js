'use strict';

angular.module('c4mApp')
  .controller('MainCtrl', function($scope, DrupalSettings, EntityResource, Request, $window, $document, $http, $interval, $timeout, $sce, FileUpload) {

    $scope.data = DrupalSettings.getData('entity');

    // Getting the resources information.
    $scope.resources = DrupalSettings.getResources();

    // Setting empty default resource.
    $scope.selectedResource = '';

    // Getting the fields information.
    $scope.fieldSchema = DrupalSettings.getFieldSchema();

    $scope.debug = DrupalSettings.getDebugStatus();

    // Getting the activity stream.
    $scope.activities = DrupalSettings.getActivities();

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
      refreshTimestamp: new Date().getTime() / 1000,
      data: {},
      status: 0
    };

    // refresh rate of the activity stream (60000 is one minute).
    $scope.refreshRate = 60000;

    /**
     * Refreshes the activity stream.
     * The refresh rate is scope.refreshRate.
     */
    $scope.refresh = function() {
      var streamData = {};
      streamData.group = $scope.data.group;
      streamData.created = $scope.stream.refreshTimestamp;
      EntityResource.updateStream(streamData)
      .success( function (data, status) {
        $scope.stream.refreshTimestamp = new Date().getTime() / 1000;

        if (data) {
          // Count the activities that were fetched.
          var position = 0;
          angular.forEach(data.data, function (activity) {
            this.splice(position, 0, {
              id: activity.id,
              created: activity.created,
              html: $sce.trustAsHtml(activity.html)
            });
            position++;
          }, $scope.newActivities);
        }
      })
      .error( function (data, status) {
        $scope.stream = {
          data: data,
          status: status,
          refreshTimestamp: new Date().getTime() / 1000
        };

      });
    };
    //Start the activity stream refresh.
    $scope.refreshing = $interval($scope.refresh, $scope.refreshRate);

    /**
     * Merge the new activity with the activity stream,
     * Reset the new activities.
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
      }, $scope.activities);
      $scope.newActivities = [];
    };

    /**
     * Prepares the referenced "data" to be objects and normal field to be empty.
     * Responsible for toggling the visibility of the taxonomy-terms checkboxes.
     * Set "popups" to 0, as to hide all of the pop-overs on load.
     */
    function prepareData() {
      $scope.popups = {};
      angular.forEach($scope.fieldSchema, function (data, field) {
        // Don't change the group field Or resource object.
        if (field == 'resources' || field == 'group') {
          return;
        }
        var allowedValues = data.form_element.allowed_values;
        if(angular.isObject(allowedValues) && Object.keys(allowedValues).length && field != "tags") {
          $scope.referenceValues[field] = allowedValues;
          $scope.popups[field] = 0;
          $scope.data[field] = {};
        }
      });
    }

    // Preparing the data for the form.
    prepareData();

    // Set "Start a Debate" as default discussion type.
    $scope.data.discussion_type = 'debate';
    // Set "Event" as default event type.
    $scope.data.event_type = 'event';

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
      var elem_width = angular.element(event.srcElement).outerWidth();
      // Toggle the visibility variable.
      $scope.popups[name] = $scope.popups[name] == 0 ? 1 : 0;
      // Move the popover to be at the end of the button.
      angular.element(".hidden-checkboxes").css('left', elem_width);
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

      // Stop the "Activity-stream" auto refresh.
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

          // Request the new activity.
          var streamData = {};
          streamData.group = submitData.group;
          streamData.created = $scope.stream.refreshTimestamp;
          EntityResource.updateStream(streamData)
          .success( function (data, status) {
            $scope.stream = {
              data: data,
              status: status,
              refreshTimestamp: new Date().getTime() / 1000
            };

            // Scroll to the top of the page.
            jQuery('body').scrollTop(300);

            // Push the new activity to the activities array.
            angular.forEach(data.data, function (activity) {
              this.splice(0, 0, {
                id: activity.id,
                created: activity.created,
                html: $sce.trustAsHtml(activity.html)
              });

              // Highlight the newly added activity.
              $timeout(function() {
                jQuery('#activity-' + activity.id).effect( "highlight", {}, 10000 );
              }, 10);
            }, $scope.activities);

            // Collapse the quick-post form.
            $scope.selectedResource = '';
          })
          .error( function (data, status) {
            $scope.stream = {
              data: data,
              status: status,
              refreshTimestamp: new Date().getTime() / 1000
            };
          });
        }
      })
      .error( function (data, status) {
        $scope.serverSide.data = data;
        $scope.serverSide.status = status;
      });

      // Reset the form.
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
     * Resets the quick-post form.
     */
    $scope.resetEntityForm = function() {
      // Form is valid.
      $scope.entityForm.$setPristine();
      // Reset all the reference fields.
      prepareData();

      //Reset the text fields.
      var textFields = ['label', 'body', 'tags'];
      angular.forEach(textFields, function(field) {
        $scope.data[field] = field == 'tags' ? [] : '';
      });
    }
  });
