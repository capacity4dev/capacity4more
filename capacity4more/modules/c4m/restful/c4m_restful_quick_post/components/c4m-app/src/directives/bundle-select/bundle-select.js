'use strict';

/**
 * @ngdoc directive
 * @name c4mApp.directive:bundleSelect
 * @description
 * # bundleSelect
 */
angular.module('c4mApp')
  .directive('bundleSelect', function ($window, DrupalSettings) {
    return {
      templateUrl: DrupalSettings.getBasePath() + 'profiles/capacity4more/libraries/bower_components/c4m-app/dist/directives/bundle-select/bundle-select.html',
      restrict: 'E',
      scope: {
        items: '=',
        bundleName: '=',
        onChange: '=onChange'
      },
      link: function postLink(scope) {
        // On changing type => update the bundleName.
        scope.updateBundle = function(bundle, e) {
          return scope.onChange(bundle, e);
        }
      }
    };
  });
