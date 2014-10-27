'use strict';

/**
 * @ngdoc directive
 * @name restfulApp.directive:bundleSelect
 * @description
 * # bundleSelect
 */
angular.module('restfulApp')
  .directive('bundleSelect', function ($window, DrupalSettings) {
    return {
      templateUrl: DrupalSettings.getBasePath() + 'profiles/drupal_angular/libraries/bower_components/restful-app/dist/directives/bundle-select/bundle-select.html',
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
