'use strict';

angular.module('c4mApp')
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
      return (angular.isDefined(self.settings.c4m.basePath)) ? self.settings.c4m.basePath : undefined;
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
    this.getDebugStatus = function() {
      return (angular.isDefined(self.settings.c4m.debug)) ? self.settings.c4m.debug : undefined;
    };

    /**
     * Get the debug status of the Drupal installation.
     */
    this.getFieldSchema = function() {
      return (angular.isDefined(self.settings.c4m.field_schema)) ? self.settings.c4m.field_schema : undefined;
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
      return (angular.isDefined(self.settings.c4m.data[id])) ? self.settings.c4m.data[id] : {};
    }
  });
