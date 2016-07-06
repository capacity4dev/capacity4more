/**
 * @file
 * Provides the different discussion types.
 */

'use strict';

/**
 * Provides the different discussion types.
 *
 * @ngdoc directive
 *
 * @name c4mApp.directive:discussionTypes
 *
 * @description The types of the discussion.
 */
angular.module('c4mApp')
  .directive('types', function ($window, DrupalSettings) {
    return {
      templateUrl: DrupalSettings.getBasePath() + 'profiles/capacity4more/libraries/bower_components/c4m-app/dist/directives/types/types.html',
      restrict: 'E',
      scope: {
        fieldSchema: '=',
        type: '=',
        field: '=',
        onChange: '=onChange',
        cols: '='
      },
      link: function postLink(scope) {
        // Get allowed values.
        scope.allowedValues = scope.fieldSchema[scope.field];
        // On changing type => update the discussion type.
        scope.updateType = function (type, field, e) {
          return scope.onChange(type, field, e);
        }
      }
    };
  });
