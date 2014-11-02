'use strict';

/**
 * @ngdoc directive
 * @name c4mApp.directive:listGeo
 * @description
 * # A list of Regions & Countries.
 */
angular.module('c4mApp')
  .directive('listGeo', function ($window, DrupalSettings) {
    return {
      templateUrl: DrupalSettings.getBasePath() + 'profiles/capacity4more/libraries/bower_components/c4m-app/dist/directives/list-geo/list-geo.html',
      restrict: 'E',
      scope: {
        items: '=items',
        model: '=model',
        type: '@type'
      }
    };
  });
