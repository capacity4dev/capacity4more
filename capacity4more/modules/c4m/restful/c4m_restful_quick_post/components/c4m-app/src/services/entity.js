'use strict';

/**
 * @ngdoc service
 * @name c4mApp.service:EntityResource
 * @description
 * # Sends the request to RESTful.
 */
angular.module('c4mApp')
  .service('EntityResource', function(DrupalSettings, Request, $http) {

    /**
     * Create a new entity.
     *
     * @param data
     *   The data object to POST.

     * @param resource
     *   The bundle of the entity.
     *
     * @param resourceFields
     *   The fields information.
     *
     * @param entityId
     *   The editing node id or NULL.
     *
     * @returns {*}
     *   JSON of the newly created entity.
     */
    this.createEntity = function(data, resource, resourceFields, entityId) {

      Request.resourceFields = resourceFields;
      Request.resource = resource;

      var url = DrupalSettings.getBasePath() + 'api/' + resource;

      if (entityId) {
        url += '/' + entityId;
      }

      return $http({
        method: entityId ? 'PATCH' : 'POST',
        url: url,
        data: data,
        transformRequest: Request.prepare,
        headers: {
          'Content-Type': 'application/x-www-form-urlencoded',
          "X-CSRF-Token": DrupalSettings.getCsrfToken()
        },
        withCredentials: true
      });
    }
  });
