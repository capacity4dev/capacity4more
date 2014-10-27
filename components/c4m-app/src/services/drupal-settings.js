'use strict';

angular.module('restfulApp')
  .service('DrupalSettings', function($window) {
    var self = this;

    /**
     * Wraps inside AngularJs Drupal settings global object.
     *
     * @type {Drupal.settings}
     */
    this.settings = $window.Drupal.settings;


    /**
     * Get the base path of the Drupal installation.
     */
    this.getBasePath = function() {
      return (angular.isDefined(self.settings.drupalAngular.basePath)) ? self.settings.drupalAngular.basePath : undefined;
    };

    /**
     * Get the base path of the Drupal installation.
     */
    this.getCsrfToken = function() {
      return (angular.isDefined(self.settings.drupalAngular.csrfToken)) ? self.settings.drupalAngular.csrfToken : undefined;
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
      return (angular.isDefined(self.settings.drupalAngular.data[id])) ? self.settings.drupalAngular.data[id] : {};
    }
  });
