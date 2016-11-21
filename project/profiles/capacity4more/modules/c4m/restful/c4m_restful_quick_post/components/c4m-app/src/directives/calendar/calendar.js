/**
 * @file
 * Provides the calendar.
 */

'use strict';

/**
 * Provides the calendar.
 *
 * @ngdoc directive
 *
 * @name c4mApp.directive:calendar
 *
 * @description calendar.
 */
angular.module('c4mApp')
  .directive('calendar', function ($window, DrupalSettings) {
    return {
      templateUrl: DrupalSettings.getBasePath() + 'profiles/capacity4more/modules/c4m/restful/c4m_restful_quick_post/components/c4m-app/dist/directives/calendar/calendar.html',
      restrict: 'E',
      scope: true
    };
  });
