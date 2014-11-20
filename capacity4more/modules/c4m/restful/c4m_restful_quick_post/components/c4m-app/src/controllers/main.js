'use strict';

angular.module('c4mApp')
  .controller('MainCtrl', function($scope, DrupalSettings, EntityResource, Request, $window, $document, $http, FileUpload) {

    $scope.data = DrupalSettings.getData('entity');

    // Getting the resources information.
    $scope.resources = DrupalSettings.getResources();

    // Setting empty default resource.
    $scope.selectedResource = '';

    // Getting the fields information.
    $scope.fieldSchema = DrupalSettings.getFieldSchema();

    $scope.debug = DrupalSettings.getDebugStatus();

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

      $http.get(url+'?autocomplete[string]=' + query.term + '&group=' + group.id)
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
     *
     *  @param event
     *    The click event.
     */
    $scope.updateResource = function(resource, event) {
      // Get element clicked in the event.
      var element = angular.element(event.srcElement);
      // Remove class "active" from all elements.
      angular.element( ".bundle-select" ).removeClass( "active" );
      // Add class "active" to clicked element.
      element.addClass( "active" );
      // Update Bundle.
      $scope.selectedResource = resource;
    };

    /**
     * Called by the directive "types",
     * Updates the type of the selected resource.
     *
     * @param type
     *  The type.

     * @param field
     *  The name of the field.
     *
     *  @param event
     *    The click event.
     */
    $scope.updateType = function(type, field, event) {
      // Get element clicked in the event.
      var element = angular.element(event.srcElement);
      // Remove class "active" from all elements.
      angular.element( "." + field ).removeClass( "active" );
      // Add class "active" to clicked element.
      element.addClass( "active" );
      // Update Bundle.
      $scope.data[field] = type;
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
          $scope.selectedResource = '';
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
  });
