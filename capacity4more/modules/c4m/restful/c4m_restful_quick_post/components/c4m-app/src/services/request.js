'use strict';

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

      // Copy data, because we shouldn't change the variables in the scope.
      var submitData = angular.copy(data);

      // Setup Date and time for events.
      if (Request.resource == 'events') {
        // If the user didn't choose the time, Fill the current time.
        if (!submitData.startTime || !submitData.endTime) {
          submitData.datetime.startTime = new Date();
          submitData.datetime.endTime = new Date();
        }
        // Convert to a timestamp for restful.
        submitData.datetime = {
          value: $filter('date')(submitData.datetime.startDate, 'yyyy-MM-dd') + ' ' + $filter('date')(submitData.datetime.startTime, 'HH:mm:ss'),
          value2: $filter('date')(submitData.datetime.endDate, 'yyyy-MM-dd') + ' ' + $filter('date')(submitData.datetime.endTime, 'HH:mm:ss')
        };
      }

      angular.forEach(submitData, function (values, field) {
        // Get the IDs of the selected references.
        // Prepare data to send to RESTful.
        var fieldType = Request.resourceFields[field].data.type;
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
     *  @param resourceFields
     *   The fields information.
     *
     * @returns {*}
     *  The errors object.
     */
    this.checkRequired = function (data, resource, resourceFields) {
      var errors = {};

      angular.forEach(data, function (values, field) {

        if (resource == 'events') {
          // If the user didn't choose the date, Display an error.
          if (!data.datetime.startDate || !data.datetime.endDate) {
            errors.datetime = 1;
          }
        }

        // Check required fields for validations, except for datetime field because we checked it earlier.
        var field_required = resourceFields[field].data.required;
        if (field_required && (!values || !values.length ) && field != 'datetime') {
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
     * @param resourceFields
     *  The fields information.
     *
     * @returns {*}
     *  Object of the cleaned data.
     */
    this.cleanFields = function (data, resourceFields) {
      angular.forEach(data, function (values, field) {
        if (!resourceFields[field]) {
          delete data[field];
        }
      });

      return data;
    };
  });
