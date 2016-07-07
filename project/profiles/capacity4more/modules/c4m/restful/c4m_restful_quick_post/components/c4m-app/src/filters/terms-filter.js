/**
 * @file
 * Provides the termsFilter & FileSize filters.
 */

'use strict';

/**
 * Provides the termsFilter.
 *
 * @ngdoc filter
 *
 * @name c4mApp.filter:termsFilter
 *
 * @description Filter taxonomy-terms according to the search input by the user and return filtered items.
 */
angular.module('c4mApp')
  .filter('termsFilter',[ function () {
    return function (items, searchText) {
      if (searchText) {
        var filtered = {};
        searchText = searchText.toLowerCase();
        angular.forEach(items, function (item, id) {
          // Check first level terms.
          if (item.label.toLowerCase().indexOf(searchText) >= 0) {
            // Label match - add to list and go to the next one.
            filtered[id] = {
              id: id,
              label: item.label,
              children: item.children
            };
          }
          else {
            var parentTerm = false;
            angular.forEach(item.children, function (child, childId) {
              // Label doesn't match - check second level terms.
              if (child.label.toLowerCase().indexOf(searchText) >= 0) {
                // Label match - add to list and go to the next one.
                if (!parentTerm) {
                  filtered[id] = {
                    id: id,
                    label: item.label,
                    children: []
                  };
                  parentTerm = true;
                }
                filtered[id].children.push({
                  id: child.id,
                  label: child.label,
                  children: child.children
                });
              }
              else {
                var childTerm = false;
                angular.forEach(child.children, function (childChild) {
                  if (childChild.label.toLowerCase().indexOf(searchText) >= 0) {
                    if (!parentTerm) {
                      filtered[id] = {
                        id: id,
                        label: item.label,
                        children: []
                      };
                      parentTerm = true;
                    }
                    if (!childTerm) {
                      filtered[id].children.push({
                        id: child.id,
                        label: child.label,
                        children: []
                      });
                      childTerm = true;
                    }
                    filtered[id].children[filtered[id].children.length - 1].children.push({
                      id: childChild.id,
                      label: childChild.label
                    });
                  }
                });
              }
            });
          }
        });
        return filtered;
      }
      else {
        return items;
      }
    }
  }]);

/**
 * Provides the human readable filesize.
 *
 * @ngdoc filter
 *
 * @name c4mApp.filter:termsFilter
 *
 * @description Format the bytes into a human readable string.
 */
angular.module('c4mApp')
  .filter('filesize', function () {
    var units = [
      'bytes',
      'KB',
      'MB',
      'GB',
      'TB',
      'PB'
    ];

    return function (bytes, precision) {
      if (isNaN(parseFloat(bytes)) || ! isFinite(bytes)) {
        return '?';
      }

      var unit = 0;

      while (bytes >= 1024) {
        bytes /= 1024;
        unit ++;
      }

      return bytes.toFixed(+ precision) + ' ' + units[ unit ];
    };
  });
