'use strict';

angular.module('c4mApp')
  .service('EntityResource', function(DrupalSettings, $http) {

    /**
     * Create a new entity.
     *
     * @param data
     *   The data object to POST.

     * @param resource
     *   The bundle of the entity.
     *
     * @returns {*}
     *   JSON of the newly created entity.
     */
    this.createEntity = function(data, resource) {
      return $http({
        method: 'POST',
        url: DrupalSettings.getBasePath() + 'api/' + resource,
        data: jQuery.param(data),
        headers: {
          'Content-Type': 'application/x-www-form-urlencoded',
          "X-CSRF-Token": DrupalSettings.getCsrfToken()
        },
        withCredentials: true
      });
    }
  });
