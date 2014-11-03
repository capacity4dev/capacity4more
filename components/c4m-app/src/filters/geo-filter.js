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
      var filtered = {};
      searchText = searchText.toLowerCase();
      angular.forEach(items, function(item, id) {
        if( item.label.toLowerCase().indexOf(searchText) >= 0 ) {
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
