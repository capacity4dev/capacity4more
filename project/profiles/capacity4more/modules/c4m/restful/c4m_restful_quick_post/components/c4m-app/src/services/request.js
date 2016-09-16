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
  .service('Request', function ($filter) {
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
    this.prepare = function (data) {

      // Copy data, We shouldn't change the variables in the scope.
      var submitData = angular.copy(data);

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
