'use strict';

angular.module('c4mApp')
  .controller('MainCtrl', function($scope, DrupalSettings, EntityResource, $window) {
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

    // Setting default discussion type to "Start a debate".
    $scope.data.discussion_type = 'debate';

    $scope.debug = DrupalSettings.getDebugStatus();

    $scope.reference_values = DrupalSettings.getReferneceValues();

    $scope.serverSide = {
      status: 0,
      data: {}
    };

    // Add popups for each entity-reference in order to hide them.
    $scope.popups = {};
    angular.forEach($scope.reference_values, function (value, key) {
      $scope.popups[key] = 0;
    });

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
    $scope.togglePopover = function(type) {
      $scope.popups[type] = $scope.popups[type] == 0 ? 1 : 0;
    };

    /**
     * Submit form (even if not validated via client).
     */
    $scope.submitForm = function(entityForm, data, bundle) {
      // Check if angular thinks that the form is valid.
      if(entityForm.$valid) {

        // Get the IDs of the references.
        angular.forEach(data, function (value, field) {
          if(typeof(value) == 'object') {
            data[field] = Object.keys(value);
          }
        });

        // Copy data.
        var submitData = angular.copy(data);

        // Call the create entity function service.
        EntityResource.createEntity(submitData, bundle)
          .success(function(data, status) {
            $scope.serverSide.data = data;
            $scope.serverSide.status = status;
          })
          .error(function(data, status) {
            $scope.serverSide.data = data;
            $scope.serverSide.status = status;
          });
      }
    };
  });
