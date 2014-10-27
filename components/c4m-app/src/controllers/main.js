'use strict';

angular.module('restfulApp')
  .controller('MainCtrl', function($scope, DrupalSettings, EntityResource, $filter, $log) {
    $scope.data = DrupalSettings.getData('entity');
    $scope.bundleName = '';
    $scope.bundles = {
      'discussions': 'Discussion',
      'documents': 'Document',
      'events': 'Event'
    };
    $scope.selections = {};
    $scope.serverSide = {
      data: {}
    };

    /**
     * Update the bundle of the entity to send to the right API.
     */
    $scope.updateBundle = function(bundle, e) {
      // Get element clicked in the event.
      var elem = angular.element(e.srcElement);
      // Remove class "active" from all elements.
      angular.element( ".active" ).removeClass( "active" );
      // Add class "active" to clicked element.
      elem.addClass( "active" );
      // Update Bundle.
      $scope.bundleName = bundle;
    }

    /**
     * Submit form (even if not validated via client).
     */
    $scope.submitForm = function(entityForm, data, bundle) {
      // Check if angular thinks that the form is valid.
      if(entityForm.$valid) {
        // Cope data.
        var submitData = angular.copy(data);
        // Setup Date and time for events.
        if (bundle == 'events') {
          // Convert  to a timestamp for restful.
          submitData.date =  {
            value: new Date($filter('date')(data.startDate, 'shortDate') + ' ' + $filter('date')(data.startTime, 'shortTime')).getTime() / 1000,
            value2: new Date($filter('date')(data.endDate, 'shortDate') + ' ' + $filter('date')(data.endTime, 'shortTime')).getTime() / 1000
          };
          // Delete time because RESTful will try to check their values.
          delete submitData['startDate'];
          delete submitData['endDate'];
          delete submitData['startTime'];
          delete submitData['endTime'];
        }

        // Add selected categories to data.
        var categories = [];
        var id = 0;
        angular.forEach($scope.selections, function (value, termId) {
          categories[id] = termId;
          id++;
        });

        submitData.categories = categories;

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
