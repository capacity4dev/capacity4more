'use strict';

/**
 * @ngdoc service
 * @name c4mApp.service:ModalService
 * @description
 * # Imports the settings sent from drupal.
 */
angular.module('c4mApp')
  .service('ModalService', function() {
    var self = this;

    this.getModalObject = function(scope, oldScope) {
      scope.data = angular.copy(oldScope.data, scope.data);
      scope.groupPurl = angular.copy(oldScope.groupPurl, scope.groupPurl);
      scope.fieldSchema = angular.copy(oldScope.fieldSchema, scope.fieldSchema);
      scope.debug = angular.copy(oldScope.debug, scope.debug);
      scope.basePath = angular.copy(oldScope.basePath, scope.basePath);
      return scope;
    };
    
    this.setDefaults = function(scope) {
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

    this.formatData = function(scope) {
      // Set "Start a Debate" as default discussion type.
      scope.data.discussion_type = angular.isObject(scope.data.discussion_type) ? 'debate' : scope.data.discussion_type;

      // Set "Event" as default event type.
      scope.data.event_type = 'event';

      // Prepare all the taxonomy-terms to be a tree object.
      angular.forEach(scope.referenceValues, function (data, field) {
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
    this.showFields = function (scope) {
      if (!scope.selectedResource) {
        scope.selectedResource = 'discussions';
      }
    };

    /**
     * Get matching tags.
     *
     * @param query
     *   The query string.
     */
    this.tagsQuery = function (query, scope) {
      var group = {id: scope.data.group};
      var url = scope.basePath + 'api/tags';
      var terms = {results: []};

      var lowerCaseTerm = query.term.toLowerCase();
      if (angular.isDefined(scope.tagsQueryCache[lowerCaseTerm])) {
        // Add caching.
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
     * Called by the directive "bundle-select",
     * Updates the bundle of the entity to send to the correct API url.
     *
     * @param resource
     *  The resource name.
     *
     *  @param event
     *    The click event.
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
     * Called by the directive "types",
     * Updates the type of the selected resource.
     *
     * @param type
     *  The type.

     * @param field
     *  The name of the field.
     *
     *  @param event
     *    The click event.
     */
    this.updateType = function(type, field, event, scope) {
      // Get element clicked in the event.
      var element = angular.element(event.srcElement);
      // Remove class "active" from all elements.
      angular.element( "." + field ).removeClass( "active" );
      // Add class "active" to clicked element.
      element.addClass( "active" );
      // Update Bundle.
      scope.data[field] = type;
    };

    /**
     * Toggle the visibility of the popovers.
     *
     * @param name
     *  The name of the pop-over.
     *
     *  @param event
     *    The click event.
     */
    this.togglePopover = function(name, event, scope) {
      // Hide all the other pop-overs, Except the one the user clicked on.
      angular.forEach(scope.popups, function (value, key) {
        if (name != key) {
          this[key] = 0;
        }
      }, scope.popups);
      // Get the width of the element clicked in the event.
      var elem_width = angular.element(event.srcElement).outerWidth();
      // Toggle the visibility variable.
      scope.popups[name] = scope.popups[name] == 0 ? 1 : 0;
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
