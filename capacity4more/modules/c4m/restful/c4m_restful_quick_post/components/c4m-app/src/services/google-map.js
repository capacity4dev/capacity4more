'use strict';

/**
 * @ngdoc service
 * @name c4mApp.service:GoogleMap
 * @description
 * # Sends request for address to google maps API.
 */
angular.module('c4mApp')
  .service('GoogleMap', function($http) {

    this.getAddress = function (data, resource) {
     return $http.get('http://maps.google.com/maps/api/geocode/json?address='
      + data.location.street + ','
      + data.location.city + ','
      + data.location.country_name
      + '&sensor=false')
      .success(function (result) {
         return result;
       })
    };
  });
