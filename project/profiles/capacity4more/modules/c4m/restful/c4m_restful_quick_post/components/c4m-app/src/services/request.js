/**
 * @file
 * Functionality to clean and prepare the RESTful request object.
 */

'use strict';

/**
 * Service to clean and prepare the RESTful request object.
 *
 * @ngdoc service
 *
 * @name c4mApp.service:Request
 *
 * @description
 * # Cleans and prepares the RESTful request object.
 */
angular.module('c4mApp')
  .service('Request', function($filter) {
    var Request = this;

    this.resourceFields = '';
    this.resource = '';

    /**
     * Prepare the request.
     *
     * @param data
     *   The data object to POST.
     *
     * @returns {*}
     *   The request object ready for RESTful.
     */
    this.prepare = function(data) {

      // Copy data, We shouldn't change the variables in the scope.
      var submitData = angular.copy(data);

      // Setup Date and time for events.
      if (Request.resource == 'events') {
        // Submitting full form without the datetime field.
        // Assign the current date to the form.
        // this will avoid displaying errors and will redirect the user the full form edit page
        // which has the current date filled by default anyway.
        if (submitData.status == 0 && !submitData.datetime) {
          submitData.datetime = {};
          submitData.datetime.startDate = new Date();
          submitData.datetime.endDate = new Date();
        }
        // If the user didn't choose the time, Fill the current time.
        if (!submitData.datetime.startTime || !submitData.datetime.endTime) {
          submitData.datetime.startTime = new Date();
          submitData.datetime.endTime = new Date();
        }
        // Convert to the "date" field format in the installation.
        submitData.datetime = {
          value: $filter('date')(submitData.datetime.startDate, 'yyyy-MM-dd') + ' ' + $filter('date')(submitData.datetime.startTime, 'HH:mm'),
          value2: $filter('date')(submitData.datetime.endDate, 'yyyy-MM-dd') + ' ' + $filter('date')(submitData.datetime.endTime, 'HH:mm')
        };
      }

      angular.forEach(submitData, function (values, field) {
        // Get the IDs of the selected references.
        // Prepare data to send to RESTful.
        if (Request.resourceFields[field] && field != 'tags') {
          var fieldType = Request.resourceFields[field].data.type;
          if (values && (fieldType == "entityreference" || fieldType == "taxonomy_term_reference")) {
            submitData[field] = [];
            angular.forEach(values, function (value, index) {
              if (value === true) {
                this[field].push(index);
              }
            }, submitData);
            // The group field should have one value.
            if (field == 'group' || field == 'related_document') {
              submitData[field] = values;
            }
          }
        }
      });

      // Assign tags.
      var tags = [];
      angular.forEach(submitData.tags, function (term, index) {
        if (term.isNew) {
          // New term.
          this[index] = {};
          this[index].label = term.id;
        }
        else {
          // Existing term.
          this[index] = term.id;
        }
      }, tags);

      var categories = submitData.categories;
      delete(submitData.categories);
      delete(submitData.tags);
      submitData.categories = categories.concat(tags);

      return jQuery.param(submitData);
    };

    /**
     * Check for required fields.
     *
     * @param data
     *   The request data.
     * @param resource
     *   The entity resource.
     * @param resourceFields
     *   The fields information.
     *
     * @returns {*}
     *   The errors object.
     */
    this.checkRequired = function (data, resource, resourceFields) {
      var errors = {};
      var errorData = angular.copy(data);

      if (resource == 'events') {
        // If the user didn't choose the date, Display an error.
        if (!errorData.datetime) {
          errors.datetime = 1
        }
        else {
          if (!errorData.datetime.startDate || !errorData.datetime.endDate) {
            errors.datetime = 1;
          }
        }
      }

      angular.forEach(errorData, function (values, field) {
        if (field == "tags") {
          return;
        }
        // Check that title has the right length.
        if (field == 'label' && values.length < 3) {
          this[field] = 1;
        }
        // Check required fields for validations, except for datetime field because we checked it earlier.
        var fieldRequired = resourceFields[field].data.required;
        if (fieldRequired && (!values) && field != "datetime") {
          this[field] = 1;
        }
      }, errors);

      return errors;
    };

    /**
     * Cleaning the submitted data from other resources fields.
     *
     * Because the RestFul will return an error if there's undefined fields.
     *
     * @param data
     *   The request data.
     * @param resourceFields
     *   The fields information.
     *
     * @returns {*}
     *  Object of the cleaned data.
     */
    this.cleanFields = function (data, resourceFields) {
      // Copy data, We shouldn't change the variables in the scope.
      var cleanData = angular.copy(data);
      angular.forEach(cleanData, function (values, field) {

        // Keep only the status field.
        if (!resourceFields[field] && field != "tags") {
          delete this[field];
        }
      }, cleanData);

      return cleanData;
    };
  });
