'use strict';

angular.module('c4mApp')
  .controller('dateCtrl', function($scope) {
    // Date Calendar options.
    $scope.minDate = new Date();

    $scope.openStart = function($event) {
      $event.preventDefault();
      $event.stopPropagation();

      $scope.startOpened = true;
    };

    $scope.openEnd = function($event) {
      $event.preventDefault();
      $event.stopPropagation();

      $scope.endOpened = true;
    };

    $scope.dateOptions = {
      formatYear: 'yyyy',
      startingDay: 1
    };
    // /Date Calendar options.

    // Time picker options
    $scope.startTime = new Date();
    $scope.endTime = new Date();

    $scope.hstep = 1;
    $scope.mstep = 1;
    // /Time picker options.
  });
