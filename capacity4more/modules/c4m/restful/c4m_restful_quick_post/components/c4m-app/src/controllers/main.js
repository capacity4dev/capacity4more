'use strict';

angular.module('c4mApp')
  .controller('MainCtrl', function($scope, DrupalSettings, EntityResource, $window, $document, $http, FileUpload, $filter) {
    $scope.data = DrupalSettings.getData('entity');
    // Getting the resources information.
    $scope.resources = DrupalSettings.getResources();

    // Setting empty default resource.
    $scope.current_resource = '';

    // Getting the fields information.
    $scope.field_schema = DrupalSettings.getFieldSchema();

    $scope.debug = DrupalSettings.getDebugStatus();

    $scope.reference_values = {};

    $scope.server_side = {
      status: 0,
      data: {}
    };

    $scope.tags_query_cache = [];

    /**
     * Prepares the referenced "data" to be objects and normal field to be empty.
     * Responsible for toggling the visibility of the taxonomy-terms checkboxes.
     * Set "popups" to 0, as to hide all of the pop-overs on load.
     */
    function prepareData() {
      $scope.popups = {};
      angular.forEach($scope.field_schema, function (data, field) {
        var allowed_values = data.form_element.allowed_values;
        if(angular.isObject(allowed_values) && Object.keys(allowed_values).length && field != "tags") {
          $scope.reference_values[field] = data.form_element.allowed_values;

          // Save the "group" ID.
          if (field == 'group') {
            var id = $scope.data[field];
            $scope.data[field] = {};
            $scope.data[field][id] = true;
          }
          else {
            $scope.popups[field] = 0;
            $scope.data[field] = {};
          }
        }
      });
    }

    // Preparing the data for the form.
    prepareData();

    // Set "Start a Debate" as default discussion type.
    $scope.data.discussion_type = 'debate';

    // Prepare the "Regions & Countries" to be a tree object.
    angular.forEach($scope.reference_values, function (data, field) {
      var parent = 0;
      $scope[field] = {};
      angular.forEach($scope.reference_values[field], function (label, id) {
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
              label: label.replace("-","")
            });
          }
        }
      });
    });

    /**
     * Display the fields upon clicking on the label field.
     */
    $scope.showFields = function () {
      if (!$scope.current_resource) {
        $scope.current_resource = 'discussions';
      }
    };

    /**
     * Get matching tags.
     *
     * @param query
     *   The query string.
     */
    $scope.tagsQuery = function (query) {
      var group = {id: Object.keys($scope.data.group)};
      var url = DrupalSettings.getBasePath() + 'api/tags';
      var terms = {results: []};

      var lowerCaseTerm = query.term.toLowerCase();
      if (angular.isDefined($scope.tags_query_cache[lowerCaseTerm])) {
        // Add caching.
        terms.results = $scope.tags_query_cache[lowerCaseTerm];
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
          $scope.tags_query_cache[lowerCaseTerm] = terms;
        }

        query.callback(terms);
      });
    };

    /**
     * Update the bundle of the entity to send to the right API.
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
      $scope.current_resource = resource;
    };

    /**
     * Update the type of the discussion.
     *
     * @param type
     *  The type of the discussion.
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
          $scope.popups[key] = 0;
        }
      });
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
          $scope.popups[key] = 0;
          // Re-Bind the JS with the HTML with "digest".
          $scope.$digest();
        });
      }
    };
    // Call the keyUpHandler function on key-up.
    $document.on('keyup', $scope.keyUpHandler);

    /**
     * Submit form.
     *
     * @param entityForm
     *  The form.
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
    $scope.submitForm = function(entityForm, data, resource, type) {
      // @TODO: Clean the form in a more generic way.
      // Clean request from un-needed fields.
      switch (resource) {
        case 'discussions':
          delete data['document'];
          delete data['document_type'];
          break;
        case 'documents':
          delete data['discussion_type'];
          break;
        case 'events':
          delete data['discussion_type'];
          delete data['document'];
          delete data['document_type'];
          delete data['date'];
          break;
        default:
          break;
      }

      // Check the type of the submit.
      // Make node unpublished if requested to create in full form.
      data.status = type == 'full_form' ? 0 : 1;

      // Check if angular thinks that the form is valid.
      if(entityForm.$valid) {

        // Get the IDs of the selected references.
        angular.forEach(data, function (values, field) {
          if(values && angular.isObject(values)  && Object.keys(values).length && field != 'tags') {
            data[field] = [];
            angular.forEach(values, function (value, index) {
              if(value === true) {
                data[field].push(index);
              }
            });
          }
        });

        // Copy data.
        var submitData = angular.copy(data);

        // Setup Date and time for events.
        if (resource == 'events') {
          // If the user didn't choose the time, Fill the current time.
          if (!$scope.data.start_time || !$scope.data.end_time) {
            $scope.data.start_time = new Date();
            $scope.data.end_time = new Date();
          }
          // Convert  to a timestamp for restful.
          submitData.datetime =  {
            value: $filter('date')($scope.data.start_date, 'yyyy-MM-dd') + ' ' + $filter('date')($scope.data.start_time, 'HH-mm-ss'),
            value2: $filter('date')($scope.data.end_date, 'yyyy-MM-dd') + ' ' + $filter('date')($scope.data.end_time, 'HH-mm-ss')
          };
          // Delete time because RESTful will try to check their values.
          delete submitData['start_date'];
          delete submitData['end_date'];
          delete submitData['start_time'];
          delete submitData['end_time'];
        }

        // Assign tags.
        var tags = [];
        angular.forEach(submitData.tags, function (term, index) {
          if (term.isNew) {
            // New term.
            tags[index] = {};
            tags[index].label = term.id;
          }
          else {
            // Existing term.
            tags[index] = term.id;
          }
        });

        submitData.tags = tags;

        // Deleting the "document" field when it's empty.
        if (submitData.document == null) {
          delete submitData['document'];
        }

        // Call the create entity function service.
        EntityResource.createEntity(submitData, resource)
        .success(function(data, status) {
          // If requested to create in full form, Redirect user to the edit page.
          if(type == 'full_form') {
            var node_id = data.data[0].id;
            $window.location = DrupalSettings.getBasePath() + "node/" + node_id + "/edit";
          }
          else {
            $scope.server_side.data = data;
            $scope.server_side.status = status;
            prepareData();
          }
        })
        .error(function(data, status) {
          $scope.server_side.data = data;
          $scope.server_side.status = status;
          prepareData();
        });
      }
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
          $scope.server_side.file = data;
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
