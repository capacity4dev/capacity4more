/**
 * @file
 * Provides the location field.
 */

'use strict';

/**
 * Provides the location field.
 *
 * @ngdoc directive
 *
 * @name c4mApp.directive:location
 *
 * @description location fields.
 */
angular.module('c4mApp')
  .directive('location', function ($window, DrupalSettings) {
    return {
      templateUrl: DrupalSettings.getBasePath() + 'profiles/capacity4more/libraries/bower_components/c4m-app/dist/directives/location/location.html',
      restrict: 'E',
      scope: {
        data: '='
      }
    };
  });
