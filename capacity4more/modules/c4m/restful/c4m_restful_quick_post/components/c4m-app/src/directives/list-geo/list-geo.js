'use strict';

/**
 * @ngdoc directive
 * @name c4mApp.directive:listGeo
 * @description
 * # A list of Regions & Countries.
 */
angular.module('c4mApp')
  .directive('listGeo', function ($window, DrupalSettings, $filter) {
    return {
      templateUrl: DrupalSettings.getBasePath() + 'profiles/capacity4more/libraries/bower_components/c4m-app/dist/directives/list-geo/list-geo.html',
      restrict: 'E',
      scope: {
        items: '=items',
        model: '=model',
        type: '@type'
      },
      link: function postLink(scope) {
        // Set the filtered items to include all items at load.
        scope.filteredGeo = scope.items;
        // Filtering the items according to the value of the searchTerm input.
        scope.updateSearch = function() {
          scope.filteredGeo = $filter('geoFilter')(scope.items, scope.searchTerm);
        };
        // No more than 3 regions can be selected.
        // TODO: Stop user from selecting more values.
        scope.updateSelectedGeo = function() {
          var selected = 0;
          angular.forEach(scope.items, function(item, id) {
            if (id in scope.model && scope.model[id] === true) {
              selected++;
            }
          });
          if (selected > 3) {
            angular.element("#geo_description").css(
              'color', 'red'
            );
          }
          else {
            angular.element("#geo_description").css(
              'color', 'black'
            );
          }
        };
      }
    };
  });
