'use strict';

/**
 * @ngdoc filter
 * @name c4mApp.filter:listFilter
 * @description
 * # Filter the items according to the search input by the user and return filtered items.
 */

angular.module('c4mApp')
  .filter('listFilter',[ function () {
  return function(items, searchText) {
    if(searchText) {
      var filtered = {};
      searchText = searchText.toLowerCase();
      angular.forEach(items, function(label, id) {
        if( label.toLowerCase().indexOf(searchText) >= 0 ) filtered[id] = label;
      });
      return filtered;
    }
    else {
      return items;
    }
  }
}]);
