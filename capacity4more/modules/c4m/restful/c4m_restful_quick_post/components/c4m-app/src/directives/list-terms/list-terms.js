'use strict';

/**
 * @ngdoc directive
 * @name c4mApp.directive:listTerms
 * @description
 * # A list of filterable taxonomy terms.
 */
angular.module('c4mApp')
  .directive('listTerms', function ($window, DrupalSettings, $timeout, $filter) {
    return {
      templateUrl: DrupalSettings.getBasePath() + 'profiles/capacity4more/libraries/bower_components/c4m-app/dist/directives/list-terms/list-terms.html',
      restrict: 'E',
      scope: {
        items: '=items',
        model: '=model',
        type: '@type',
        popup: '=',
        updatePopoverPosition: '='
      },
      link: function postLink(scope) {
        // Set the filtered items to include all items at load.
        scope.filteredTerms = scope.items;
        // Filtering the items according to the value of the searchTerm input.
        scope.updateSearch = function() {
          scope.filteredTerms = $filter('termsFilter')(scope.items, scope.searchTerm);
        };
        // updating the popover position && No more than 3 regions can be selected.
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

              angular.forEach(scope.items[id].children, function(child, key) {
                var childID = child.id;
                if (childID in scope.model && scope.model[childID] === false) {
                  // Term of 2 level has been unchecked - uncheck its children.
                  angular.forEach(scope.items[id].children[key].children, function(childChild, childkey) {
                    var childChildID = childChild.id;
                    if (childChildID in scope.model && scope.model[childChildID] === true) {
                      scope.model[childChildID] = false;
                    }
                  });
                }
              });
            }
            else if (id in scope.model && scope.model[id] === false) {
              // Find all children and turn them to false
              angular.forEach(scope.items[id].children, function(child, key) {
                var childID = child.id;
                if (childID in scope.model && scope.model[childID] === true) {
                  scope.model[childID] = false;
                  // Find all child's children and turn them to false.
                  angular.forEach(scope.items[id].children[key].children, function(childChild, childkey) {
                    var childChildID = childChild.id;
                    if (childChildID in scope.model && scope.model[childChildID] === true) {
                      scope.model[childChildID] = false;
                    }
                  });
                }
              });
            }
          });

          if (selectedCount > 3) {
            angular.element("#" + scope.type + "_description").css(
              'color', 'red'
            );
            if (scope.popup) {
              scope.popup = 0;
            }
          }
          else {
            angular.element("#" + scope.type + "_description").css(
              'color', '#999999'
            );
          }
        };
      }
    };
  });
