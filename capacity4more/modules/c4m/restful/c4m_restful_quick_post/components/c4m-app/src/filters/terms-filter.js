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
    return function(items, searchText) {
      if (searchText) {
        var filtered = {};
        searchText = searchText.toLowerCase();
        angular.forEach(items, function(item, id) {
          if (item.label.toLowerCase().indexOf(searchText) >= 0) {
            filtered[id] = {
              id: id,
              label: item.label,
              children: item.children
            };
          }
          else {
            angular.forEach(item.children, function(child) {
              if (child.label.toLowerCase().indexOf(searchText) >= 0) {
                filtered[id] = {
                  id: id,
                  label: item.label,
                  children: []
                };
                filtered[id]['children'].push({
                  id: child.id,
                  label: child.label
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

    return function(bytes, precision) {
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
