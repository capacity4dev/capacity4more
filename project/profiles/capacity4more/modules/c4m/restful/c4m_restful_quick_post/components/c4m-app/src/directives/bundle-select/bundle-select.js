/**
 * @file
 * Provides the bundleSelect directive.
 */

'use strict';

/**
 * Provides the bundleSelect directive.
 *
 * @ngdoc directive
 *
 * @name c4mApp.directive:bundleSelect
 *
 * @description bundleSelect.
 */
angular.module('c4mApp')
  .directive('bundleSelect', function ($window, DrupalSettings) {
    return {
      templateUrl: DrupalSettings.getBasePath() + 'profiles/capacity4more/libraries/bower_components/c4m-app/dist/directives/bundle-select/bundle-select.html',
      restrict: 'E',
      scope: {
        items: '=',
        selectedResource: '=',
        onChange: '=onChange'
      },
      link: function postLink(scope) {
        scope.purl = DrupalSettings.getPurlPath();
        // On changing type => update the bundleName.
        scope.updateResource = function (resource, e) {
          return scope.onChange(resource, e);
        }
      }
    };
  });
