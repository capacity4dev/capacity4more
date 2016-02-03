/**
 * @file
 * Provides a wrapper around the DrupalSettings object.
 */

'use strict';

/**
 * Provides a wrapper around the DrupalSettings object.
 *
 * @ngdoc service
 *
 * @name c4mApp.service:DrupalSettings
 *
 * @description Imports the settings sent from drupal.
 */
angular.module('c4mApp')
  .service('DrupalSettings', function($window, $http, $sce) {
    var self = this;

    // Wraps inside AngularJs Drupal settings global object.
    // @type {Drupal.settings}.
    this.settings = $window.Drupal.settings;

    /**
     * Get the base path of the Drupal installation.
     */
    this.getBasePath = function() {
      return (angular.isDefined(self.settings.c4m.basePath)) ? self.settings.c4m.basePath : undefined;
    };

    /**
     * Get the base path of the Group.
     */
    this.getPurlPath = function() {
      return (angular.isDefined(self.settings.c4m.purlPath)) ? self.settings.c4m.purlPath : undefined;
    };

    /**
     * Get the resources of the quick post.
     */
    this.getResources = function() {
      return (angular.isDefined(self.settings.c4m.resources)) ? self.settings.c4m.resources : undefined;
    };

    /**
     * Get the activity stream of the current group.
     */
    this.getActivities = function() {
      var activities = [];
      var rawActivities = (angular.isDefined(self.settings.c4m.activities)) ? self.settings.c4m.activities : undefined;

      // Activities HTML should be marked as trusted.
      angular.forEach(rawActivities, function (activity) {
        this.push({
          id: activity.id,
          timestamp: activity.timestamp,
          html: $sce.trustAsHtml(activity.html)
        });
      }, activities);

      return activities;
    };

    /**
     * Get the base path of the Drupal installation.
     */
    this.getCsrfToken = function() {
      return (angular.isDefined(self.settings.c4m.csrfToken)) ? self.settings.c4m.csrfToken : undefined;
    };

    /**
     * Get the debug status of the Drupal installation.
     */
    this.getCarousels = function() {
      return (angular.isDefined(self.settings.c4m.carousels)) ? self.settings.c4m.carousels : undefined;
    };

    /**
     * Get the debug status of the Drupal installation.
     */
    this.getFieldSchema = function(resourceName) {
      var url = this.getPurlPath() + '/quick-post/' + resourceName + '/field-schema';

      return $http({
        method: 'GET',
        url: url,
        withCredentials: true
      });
    };

    /**
     * Return the form schema.
     *
     * @param int id
     *   The form ID.
     *
     * @returns {*}
     *   The form schema if exists, or an empty object.
     */
    this.getData = function(id) {
      if (!angular.isDefined(self.settings.c4m.data)) {
        return {};
      }
      return (angular.isDefined(self.settings.c4m.data[id])) ? self.settings.c4m.data[id] : {};
    }
  });
