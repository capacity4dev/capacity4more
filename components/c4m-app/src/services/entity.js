'use strict';

angular.module('restfulApp')
  .service('EntityResource', function(DrupalSettings, $http) {

    /**
     * Create a new entity.
     *
     * @param data
     *   The data object to POST.

     * @param bundle
     *   The bundle of the entity.
     *
     * @returns {*}
     *   JSON of the newly created entity.
     */
    this.createEntity = function(data, bundle) {
      return $http({
        method: 'POST',
        url: DrupalSettings.getBasePath() + 'api/v1/' + bundle,
        data: jQuery.param(data),
        headers: {
          'Content-Type': 'application/x-www-form-urlencoded',
          "X-CSRF-Token": DrupalSettings.getCsrfToken(),
          // Call the correct resource version (v1.5) that has the "body" and
          // "image" fields exposed.
          "X-Restful-Minor-Version": 5
        },
        withCredentials: true
      });
    }
  });
