'use strict';

angular.module('c4mApp')
  .controller('MainCtrl', function($scope, DrupalSettings, EntityResource, $window, $document, $http, $filter) {
    $scope.data = DrupalSettings.getData('entity');
    // Setting default content type to "Discussion".
    $scope.bundle_name = 'discussions';
    $scope.bundles = {
      'discussions': 'Add a Discussion',
      'documents': 'Upload a Document',
      'events': 'Add an Event'
    };

    // Getting all the fields information.
    $scope.field_schema = DrupalSettings.getFieldSchema();

    $scope.debug = DrupalSettings.getDebugStatus();

    $scope.reference_values = {};

    $scope.serverSide = {
      status: 0,
      data: {}
    };

    $scope.c4m_vocab_geo = {};

    $scope.tagsQueryCache = [];

    // Responsible for toggling the visibility of the taxonomy-terms.
    // Set "popups" to 0, as to hide all of the pop-overs on load.
    // Also prepare the referenced "data" to be objects.
    $scope.popups = {};
    angular.forEach($scope.field_schema, function (data, field) {
      var allowed_values = data.form_element.allowed_values;
      if(angular.isObject(allowed_values) && Object.keys(allowed_values).length) {
        $scope.reference_values[field] = data.form_element.allowed_values;

        $scope.popups[field] = 0;
        if($scope.data[field]) {
          angular.forEach($scope.data[field], function (term) {
            $scope.data[field] = {};
            $scope.data[field][term] = true;
          });
        }
        else {
          $scope.data[field] = {};
        }
      }
    });

    // Setting default discussion type to "Start a debate".
    $scope.data.discussion_type = 'debate';

    // Prepare the "Regions & Countries" to be a tree object.
    var parent = 0;
    angular.forEach($scope.reference_values.c4m_vocab_geo, function (label, id) {
      if(label.indexOf('-')) {
        parent = id;
        $scope.c4m_vocab_geo[id] = {
          id: id,
          label: label,
          children: []
        };
      }
      else {
        if (parent > 0) {
          $scope.c4m_vocab_geo[parent]['children'].push({
            id: id,
            label: label.replace("-","")
          });
        }
      }
    });

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
      if (angular.isDefined($scope.tagsQueryCache[lowerCaseTerm])) {
        // Add caching.
        terms.results = $scope.tagsQueryCache[lowerCaseTerm];
        query.callback(terms);
        return;
      }

      $http.get(url, {
        params: {
          string: query.term,
          group: group.id
        }
      }).success(function(data) {

        if (data.data.length == 0) {
          terms.results.push({
            text: query.term,
            id: query.term,
            isNew: true
          });
        }
        else {
          angular.forEach(data.data, function (tag) {
            terms.results.push({
              text: tag.label,
              id: tag.id,
              isNew: false
            });
          });
          $scope.tagsQueryCache[lowerCaseTerm] = terms;
        }

        query.callback(terms);
      });
    };

    /**
     * Update the bundle of the entity to send to the right API.
     */
    $scope.updateBundle = function(bundle, e) {
      // Get element clicked in the event.
      var elem = angular.element(e.srcElement);
      // Remove class "active" from all elements.
      angular.element( ".bundle-select" ).removeClass( "active" );
      // Add class "active" to clicked element.
      elem.addClass( "active" );
      // Update Bundle.
      $scope.bundle_name = bundle;
    };

    /**
     * Update the type of the discussion.
     */
    $scope.updateDiscussionType = function(type, e) {
      // Get element clicked in the event.
      var elem = angular.element(e.srcElement);
      // Remove class "active" from all elements.
      angular.element( ".discussion-types" ).removeClass( "active" );
      // Add class "active" to clicked element.
      elem.addClass( "active" );
      // Update Bundle.
      $scope.data.discussion_type = type;
    };

    /**
     * Toggle the visibility of the popovers.
     */
    $scope.togglePopover = function(type, e) {
      // Hide all the other pop-overs first.
      angular.forEach($scope.popups, function (value, key) {
        if ($scope.popups[type] != $scope.popups[key]) {
          $scope.popups[key] = 0;
        }
      });
      // Get element width clicked in the event.
      var elem_width = angular.element(e.srcElement).outerWidth();
      // Toggle the visibility variable.
      $scope.popups[type] = $scope.popups[type] == 0 ? 1 : 0;
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
    $document.on('keyup', $scope.keyUpHandler);

    /**
     * Submit form (even if not validated via client).
     */
    $scope.submitForm = function(entityForm, data, bundle, type) {
      // Check the type of the submit.
      // Make node unpublished if requested to create in full form.
      data.status = type == 'full_form' ? 0 : 1;

      // Check if angular thinks that the form is valid.
      if(entityForm.$valid) {


        // Get the IDs of the selected references.
        angular.forEach(data, function (values, field) {
          if(values && typeof(values) === 'object') {
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

        // Call the create entity function service.
        EntityResource.createEntity(submitData, bundle)
          .success(function(data, status) {
            // If requested to create in full form, Redirect user to the edit page.
            if(type == 'full_form') {
              var node_id = data.data[0].id;
              $window.location = DrupalSettings.getBasePath() + "node/" + node_id + "/edit";
            }
            else {
              $scope.serverSide.data = data;
              $scope.serverSide.status = status;
            }
          })
          .error(function(data, status) {
            $scope.serverSide.data = data;
            $scope.serverSide.status = status;
          });
      }
    };
  });
