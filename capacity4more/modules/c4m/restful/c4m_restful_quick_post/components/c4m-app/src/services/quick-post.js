'use strict';

/**
 * @ngdoc service
 * @name c4mApp.service:QuickPostService
 * @description
 * # Imports the settings sent from drupal.
 */
angular.module('c4mApp')
  .service('QuickPostService', function() {
    var self = this;

    /**
     * Set the default values to the scope.
     *
     * @param scope
     *  the scope object.
     *
     * @returns {*}
     *  Returns the scope object with the default values.
     */
    this.setDefaults = function(scope) {
      scope.documentName = '';

      scope.referenceValues = {};

      scope.errors = {};

      scope.serverSide = {
        status: 0,
        data: {}
      };

      scope.tagsQueryCache = [];

      // Date Calendar options.
      scope.minDate = new Date();

      scope.startOpened = false;

      scope.endOpened = false;

      scope.dateOptions = {
        formatYear: 'yyyy',
        startingDay: 1
      };

      scope.format = 'dd/MM/yyyy';

      // Time picker options.
      // Hour step.
      scope.hstep = 1;
      // Minute step.
      scope.mstep = 1;

      return scope;
    };

    /**
     * Prepare all the taxonomy-terms to be a tree object.
     *
     * @param scope
     *  The scope object.
     *
     * @returns {*}
     *  Returns the scope object with the prepared taxonomy-terms fields.
     */
    this.formatTermFieldsAsTree = function(scope) {
      angular.forEach(scope.referenceValues, function (data, field) {
        // Parent id.
        var parent = 0;
        scope[field] = {};
        angular.forEach(scope.referenceValues[field], function (label, id) {
          if(label.indexOf('-')) {
            parent = id;
            scope[field][id] = {
              id: id,
              label: label,
              children: []
            };
          }
          else {
            if (parent > 0) {
              scope[field][parent]['children'].push({
                id: id,
                label: label.replace('-','')
              });
            }
          }
        });
      });

      return scope;
    };

    /**
     * Display the fields upon clicking on the label field.
     */
    this.showFields = function (selectedResource) {
      if (!selectedResource) {
        return 'discussions';
      }
      return selectedResource;
    };

    /**
     * Get matching tags.
     *
     * @param query
     *   The query string.
     * @param scope
     *   The scope object.
     */
    this.tagsQuery = function (query, scope) {
      var group = {id: scope.data.group};
      var url = scope.basePath + 'api/tags';
      var terms = {results: []};

      var lowerCaseTerm = query.term.toLowerCase();
      if (angular.isDefined(scope.tagsQueryCache[lowerCaseTerm])) {
        // Cache the tags result we got from the server,
        // to prevent re-query for the same ones.
        terms.results = scope.tagsQueryCache[lowerCaseTerm];
        query.callback(terms);
        return;
      }

      $http.get(url+'?autocomplete[string]=' + query.term + '&group=' + group.id)
        .success(function(data) {
          if (data.data.length == 0) {
            terms.results.push({
              text: query.term,
              id: query.term,
              isNew: true
            });
          }
          else {
            angular.forEach(data.data, function (label, id) {
              terms.results.push({
                text: label,
                id: id,
                isNew: false
              });
            });
            scope.tagsQueryCache[lowerCaseTerm] = terms;
          }

          query.callback(terms);
        });
    };

    /**
     * Called by the directive "bundle-select".
     *
     * Updates the bundle of the entity to send to the correct API url.
     *
     * @param resource
     *  The resource name.
     *  @param event
     *    The click event.
     *
     *  @returns string
     *    Returns a selected resource name.
     */
    this.updateResource = function(resource, event) {
      // Get element clicked in the event.
      var element = angular.element(event.srcElement);
      // Remove class "active" from all elements.
      angular.element( ".bundle-select" ).removeClass( "active" );
      // Add class "active" to clicked element.
      element.addClass( "active" );
      // Update Bundle.
      return resource;
    };

    /**
     * Called by the directive "types".
     *
     * Updates the type of the selected resource.
     *
     * @param type
     *  The type.
     * @param field
     *  The name of the field.
     *  @param event
     *  The click event.
     */
    this.updateType = function(type, field, event) {
      // Get element clicked in the event.
      var element = angular.element(event.srcElement);
      // Remove class "active" from all elements.
      angular.element( "." + field ).removeClass( "active" );
      // Add class "active" to clicked element.
      element.addClass( "active" );
      // Update Bundle.
      return type;
    };

    /**
     * Toggle the visibility of the popovers.
     *
     * @param name
     *  The name of the pop-over.
     *  @param event
     *    The click event.
     *  @param popups
     *    The scope object.
     */
    this.togglePopover = function(name, event, popups) {
      // Hide all the other pop-overs, Except the one the user clicked on.
      angular.forEach(popups, function (value, key) {
        if (name != key) {
          this[key] = 0;
        }
      }, popups);
      // Get the width of the element clicked in the event.
      var elem_width = angular.element(event.srcElement).outerWidth();
      var elemPosition = angular.element(event.target).offset();
      var elemParentPosition = angular.element(event.target).parent().offset();
      // Toggle the visibility variable.
      popups[name] = popups[name] == 0 ? 1 : 0;
      // Move the popover to be at the end of the button.
      angular.element(".hidden-checkboxes").css('left', elem_width);
    };

    /**
     * Close all popovers on "ESC" key press.
     */
    this.keyUpHandler = function(keyEvent, scope) {
      if(keyEvent.which == 27) {
        angular.forEach(scope.popups, function (value, key) {
          this[key] = 0;
          // Re-Bind the JS with the HTML with "digest".
          scope.$digest();
        }, scope.popups);
      }
    };


  });
