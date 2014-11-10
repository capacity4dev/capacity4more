'use strict';

angular.module('c4mApp')
  .service('Request', function() {

    /**
     * Prepare the request.
     *
     * @param data
     *   The data object to POST.

     * @param resource
     *   The bundle of the entity.
     *
     * @param resource_fields
     *  The fields information.
     *
     * @returns {*}
     *   The request object ready for RESTful.
     */
    this.prepare = function(data, resource, resource_fields) {

      // Copy data, because we shouldn't change the variables in the scope.
      var submitData = angular.copy(data);

      // Setup Date and time for events.
      if (resource == 'events') {
        // If the user didn't choose the time, Fill the current time.
        if (!submitData.startTime || !submitData.endTime) {
          submitData.startTime = new Date();
          submitData.endTime = new Date();
        }
        // Convert to a timestamp for restful.
        submitData.datetime = {
          value: $filter('date')(submitData.startDate, 'yyyy-MM-dd') + ' ' + $filter('date')(submitData.startTime, 'HH:mm:ss'),
          value2: $filter('date')(submitData.endDate, 'yyyy-MM-dd') + ' ' + $filter('date')(submitData.endTime, 'HH:mm:ss')
        };
      }

      angular.forEach(submitData, function (values, field) {
        // Get the IDs of the selected references.
        // Prepare data to send to RESTful.
        var fieldType = resource_fields[field].data.type;
        if (values && (fieldType == "entityreference" || fieldType == "taxonomy_term_reference") && field != 'tags') {
          submitData[field] = [];
          angular.forEach(values, function (value, index) {
            if (value === true) {
              this[field].push(index);
            }
          }, submitData);
          // The group field should have one value.
          if (field == 'group') {
            submitData[field] = values;
          }
        }
      });

      // Assign tags.
      var tags = [];
      angular.forEach(submitData.tags, function (term, index) {
        if (term.isNew) {
          // New term.
          tags[index] = {};
          tags[index].label = term.id;
        }
        else {
          // Existing term.
          tags[index] = term.id;
        }
      });

      submitData.tags = tags;

      return jQuery.param(submitData);
    };

    /**
     * Check for required fields.
     *
     * @param data
     *  The request data.
     *
     * @param resource
     *  The entity resource.
     *
     *  @param resource_fields
     *   The fields information.
     *
     * @returns {*}
     *  The errors object.
     */
    this.checkRequired = function (data, resource, resource_fields) {
      var errors = {};

      angular.forEach(data, function (values, field) {

        if (resource == 'events') {
          // If the user didn't choose the date, Display an error.
          if (!data.startDate || !data.endDate) {
            errors.datetime = 1;
          }
        }

        // Check required fields for validations
        var field_required = resource_fields[field].data.required;
        if (field_required && (!values || !values.length )) {
          errors[field] = 1;
        }
      });

      return errors;
    };


    /**
     * Cleaning the submitted data from other resources fields,
     * because the RESTful will return an error if there's undefined fields.
     *
     * @param data
     *  The request data.
     *
     * @param resource_fields
     *  The fields information.
     *
     * @returns {*}
     *  Object of the cleaned data.
     */
    this.cleanFields = function (data, resource_fields) {
      angular.forEach(data, function (values, field) {
        if (!resource_fields[field]) {
          delete data[field];
        }
      });

      return data;
    };
  });
