/**
 * @file
 * Provides the Activity Controller (ActivityCtrl).
 */

'use strict';

angular.module('c4mApp')
  .controller('AddTermCtrl', function($scope, $window, Request, EntityResource) {
    $scope.parent = 0;
    $scope.group = 0;
    $scope.label = '';

    // Prevent default behavior when keyPress event triggered
    // on the label input.
    var labelInput = angular.element('.label-input');
    labelInput.on('keypress', function(e) {
      if (e.keyCode == 13) {
        e.preventDefault();
        e.stopPropagation();
      }
    });

    /**
     * Create a new taxonomy-term.
     *
     * Create a new term under a specific category,
     * which is under a group (Restful knows which vocabulary from the group-id).
     * Shows/hides error text in case there was an error in the request.
     */
    $scope.addCategoryTerm = function() {
      // Error hidden element (Hide in case it was displayed in previous request).
      var errorLabelElement = angular.element('#label-error-' + $scope.parent);
      errorLabelElement.hide();
      // Prepare the request.
      var request = {
        parent: [$scope.parent],
        label: $scope.label,
        group: $scope.group
      };
      // Send the request to RESTful.
      EntityResource.createTerm(request, 'categories')
        .success(function () {
          // Reload current page in case the taxonomy was added successfully.
          $window.location.reload();
        })
        .error(function (data) {
          // Show error element.
          errorLabelElement.text(data.title);
          errorLabelElement.show();
          return false;
        });
    };
  });
