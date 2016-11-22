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
      templateUrl: DrupalSettings.getBasePath() + 'profiles/capacity4more/modules/c4m/restful/c4m_restful_quick_post/components/c4m-app/dist/dist/directives/location/location.html',
      restrict: 'E',
      scope: {
        data: '='
      }
    };
  });
