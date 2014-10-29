'use strict';

/**
 * @ngdoc directive
 * @name c4mApp.directive:discussionTypes
 * @description
 * # The types of the discussion.
 */
angular.module('c4mApp')
  .directive('discussionTypes', function ($window, DrupalSettings) {
    return {
      templateUrl: DrupalSettings.getBasePath() + 'profiles/capacity4more/libraries/bower_components/c4m-app/dist/directives/discussion-types/discussion-types.html',
      restrict: 'E',
      scope: {
        fieldSchema: '=',
        discussionType: '=',
        onChange: '=onChange'
      },
      link: function postLink(scope) {
        // Get allowed values.
        scope.allowed_values = scope.fieldSchema.discussion_type.form_element.allowed_values;
        // On changing type => update the discussion type.
        scope.updateDiscussionType = function(type, e) {
          return scope.onChange(type, e);
        }
      }
    };
  });
