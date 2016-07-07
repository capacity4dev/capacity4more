/**
 * @file
 * Provides the GoogleMap Service.
 */

'use strict';

/**
 * Provides the GoogleMap Service.
 *
 * @ngdoc service
 *
 * @name c4mApp.service:GoogleMap
 *
 * @description Sends request for address to google maps API.
 */
angular.module('c4mApp')
  .service('GoogleMap', function ($http) {

    this.getAddress = function (data, resource) {
      var url = 'http://maps.google.com/maps/api/geocode/json?address=';
      url += data.location.street ? data.location.street + ',' : '';
      url += data.location.city ? data.location.city : '';
      url += data.location.postal_code ? ' ' + data.location.postal_code : '';
      url += data.location.city || data.location.postal_code ? ',' : '';
      url += data.location.country_name ? ' ' + data.location.country_name : '';
      url += '&sensor=false';
      return $http.get(url);
    };
  });
