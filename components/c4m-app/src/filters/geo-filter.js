'use strict';

/**
 * @ngdoc filter
 * @name c4mApp.filter:geoFilter
 * @description
 * # Filter "Regions & Countries" according to the search input by the user and return filtered items.
 */

angular.module('c4mApp')
  .filter('geoFilter',[ function () {
  return function(items, searchText) {
    if(searchText) {
      var filtered = [];
      searchText = searchText.toLowerCase();
      angular.forEach(items, function(item) {
        if( item.label.toLowerCase().indexOf(searchText) >= 0 ) filtered.push(item);
      });
      return filtered;
    }
  }
}]);
