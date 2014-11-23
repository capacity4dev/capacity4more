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
     * @returns {*}
     *   JSON of the newly created entity.
     */
    this.createEntity = function(data, resource, resourceFields) {
      Request.resourceFields = resourceFields;
      Request.resource = resource;
      return $http({
        method: 'POST',
        url: DrupalSettings.getBasePath() + 'api/' + resource,
        data: data,
        transformRequest: Request.prepare,
        headers: {
          "Content-Type": 'application/x-www-form-urlencoded',
          "X-CSRF-Token": DrupalSettings.getCsrfToken()
        },
        withCredentials: true
      });
    };

    this.updateStream = function(data) {
      var config = {
        withCredentials: true,
        headers: {
          "X-CSRF-Token": DrupalSettings.getCsrfToken()
        }
      };

      return $http.get(DrupalSettings.getBasePath() + 'api/activity_stream?group=' + data.group + '&sort=-id&filter[created][value]=' + data.created + '&filter[created][operator]=">"&html=1', config);
    };
  });
