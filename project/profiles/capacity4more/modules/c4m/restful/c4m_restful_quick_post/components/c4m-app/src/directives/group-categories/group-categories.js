/**
 * @file
 * Provides a list of filterable taxonomy terms.
 */

'use strict';

/**
 * Provides a list of filterable taxonomy terms.
 *
 * @ngdoc directive
 *
 * @name c4mApp.directive:listTerms
 *
 * @description A list of filterable taxonomy terms.
 */
angular.module('c4mApp')
  .directive('groupCategories', function ($window, DrupalSettings, $timeout, $filter) {
    return {
      templateUrl: DrupalSettings.getBasePath() + 'profiles/capacity4more/libraries/bower_components/c4m-app/dist/directives/group-categories/group-categories.html',
      restrict: 'E',
      scope: {
        items: '=items',
        model: '=model',
        type: '@type',
        popup: '=',
        updatePopoverPosition: '='
      },
      link: function postLink(scope) {
        angular.forEach(scope.items, function(item, id) {
          item.selected = false;
        });
        // Set the filtered items to include all items at load.
        scope.$watch('items', function(items) {
          scope.filteredTerms = items;
          // Check if there's categories in the current group,
          // to display an empty categories message.
          scope.itemsLength = angular.isDefined(items) && Object.keys(items).length ? true : false;
        });
        // Filtering the items according to the value of the searchTerm input.
        scope.updateSearch = function() {
          scope.filteredTerms = $filter('termsFilter')(scope.items, scope.searchTerm);
        };

        /**
         * Show or hide list of subcategories for the current category.
         * Is called by click.
         *
         * @param item
         *  Current category item.
         */
        scope.updateSelected = function(item) {
          item.selected = !item.selected;
        };

        // Updating the popover position && No more than 3 regions can be
        // selected.
        // TODO: Stop user from selecting more values.
        scope.updateSelectedTerms = function() {
          // Update the position of the popover.
          if (scope.updatePopoverPosition) {
            scope.updatePopoverPosition(scope.type);
          }

          var selectedCount = 0;
          angular.forEach(scope.items, function(item, id) {
            if (id in scope.model && scope.model[id] === true) {
              selectedCount++;
            }
            else if (id in scope.model && scope.model[id] === false) {
              // Find all children and turn them to false.
              angular.forEach(scope.items[id].children, function(child, key) {
                var childID = child.id;
                if (childID in scope.model && scope.model[childID] === true) {
                  scope.model[childID] = false;
                }
              });
            }
          });

          if (selectedCount > 3) {
            angular.element("#" + scope.type + "_description").addClass('error-too-many-selected');
            if (scope.popup) {
              scope.popup = 0;
            }
          }
          else {
            angular.element("#" + scope.type + "_description").removeClass('error-too-many-selected');
          }
        };
      }
    };
  });
