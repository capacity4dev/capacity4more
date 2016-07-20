/**
 * @file
 * Provides the EntityResource service.
 */

'use strict';

/**
 * Provides the EntityResource service.
 *
 * @ngdoc service
 *
 * @name c4mApp.service:EntityResource
 *
 * @description Sends the request to RESTful.
 */
angular.module('c4mApp')
  .service('EntityResource', function (DrupalSettings, Request, $http) {

    /**
     * Get the entity by id.
     *
     * @param resource
     *  The bundle of the entity
     * @param entityId
     *  The node id.
     *
     * @returns {*}
     *  JSON of the entity.
     */
    this.getEntityData = function (resource, entityId) {
      var url = DrupalSettings.getBasePath() + 'api/' + resource;

      if (entityId) {
        url += '/' + entityId + '?group=' + Drupal.settings.ogContext.gid;
      }

      return $http({
        method: 'GET',
        url: url,
        withCredentials: true
      });
    };

    /**
     * Create a new entity.
     *
     * @param data
     *   The data object to POST.
     * @param resource
     *   The bundle of the entity.
     * @param resourceFields
     *   The fields information.
     * @param entityId
     *   The editing node id or NULL.
     *
     * @returns {*}
     *   JSON of the newly created entity.
     */
    this.createEntity = function (data, resource, resourceFields, entityId) {

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
          "Content-Type": 'application/x-www-form-urlencoded',
          "X-CSRF-Token": DrupalSettings.getCsrfToken()
        },
        withCredentials: true
      });
    };

    /**
     * Update the activity stream, and Load more activities.
     *
     * Provides the 'Show more' button.
     *
     * @param data
     *   The stream data.
     * @param action
     *   The type of action requested (Update activity || Load more activity).
     *
     * @returns {*}
     *   JSON of the updated activity stream.
     */
    this.updateStream = function (data, action) {
      var config = {
        withCredentials: true,
        headers: {
          "X-CSRF-Token": DrupalSettings.getCsrfToken()
        }
      };

      var timestamp = action == 'update' ? data.lastTimestamp : data.firstLoadedTimestamp;
      var operator = action == 'update' ? '>' : '<';

      var homepage = '&homepage=' + data.homepage;
      var hideArticles = '&hide_articles=' + data.hideArticles;
      var topics = data.topics;

      var topicsFilter = '';
      if (angular.isObject(topics)) {
        angular.forEach(topics, function (topic, index) {
          topicsFilter += '&topics[' + index + ']=' + topic;
        });
      }

      // If we have more than one group then add "IN",
      // operator and breakdown the group IDs to separate filters.
      if (angular.isObject(data.group)) {
        var group_filter = '';
        angular.forEach(data.group, function (group, index) {
          group_filter += 'group[' + index + ']=' + group + '&';
        });

        return $http.get(
          DrupalSettings.getBasePath()
            + 'api/activity_stream?'
            + group_filter
            + '&sort=-timestamp&filter[timestamp][value]=' + timestamp
            + '&filter[timestamp][operator]="' + operator
            + '"&html=1'
            + homepage
            + hideArticles
            + topicsFilter
          , config
        );
      }

      return $http.get(DrupalSettings.getBasePath() + 'api/activity_stream?group='
      + data.group + '&sort=-timestamp&filter[timestamp][value]=' + timestamp
      + '&filter[timestamp][operator]="' + operator + '"&html=1' + homepage + hideArticles + topicsFilter, config);
    };
  });
