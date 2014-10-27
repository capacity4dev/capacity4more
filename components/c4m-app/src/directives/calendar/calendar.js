'use strict';

/**
 * @ngdoc directive
 * @name restfulApp.directive:calendar
 * @description
 * # calendar
 */
angular.module('restfulApp')
  .directive('calendar', function ($window, DrupalSettings) {
    return {
      templateUrl: DrupalSettings.getBasePath() + 'profiles/drupal_angular/libraries/bower_components/restful-app/dist/directives/calendar/calendar.html',
      restrict: 'E',
      scope: {
        'data': '='
      }
    };
  });
