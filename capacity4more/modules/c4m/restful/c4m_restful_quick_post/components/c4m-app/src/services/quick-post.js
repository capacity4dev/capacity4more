'use strict';

/**
 * @ngdoc service
 * @name c4mApp.service:QuickPostService
 * @description
 * # Imports the settings sent from drupal.
 */
angular.module('c4mApp')
  .service('QuickPostService', function($rootScope, $http) {
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

      scope.data.location = {};
      scope.data.location.street = '';
      scope.data.location.city = '';
      scope.data.location.postal_code = '';
      scope.data.location.country_name = '';

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
        var midParent = 0;

        scope[field] = {};
        angular.forEach(scope.referenceValues[field], function (label, id) {

          if (label.indexOf('-') == -1 && label.indexOf('--') == -1) {
            parent = id;
            scope[field][id] = {
              id: id,
              label: label,
              children: []
            };
          }
          else {
            if (label.indexOf('--') == -1) {
              if (parent > 0) {
                midParent = id;
                scope[field][parent]['children'].push({
                  id: id,
                  label: label.replace('-',''),
                  children: []
                });
              }
            }
            else {
              if (midParent > 0) {
                angular.forEach(scope[field][parent]['children'], function(value, key) {
                  if (value.id == midParent) {
                    scope[field][parent]['children'][key]['children'].push({
                      id: id,
                      label: label.replace('--','')
                    });
                  }
                });
              }
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
     * Find the taxonomy term name by its id.
     *
     * @param vocab
     *  Taxonomy vocabulary object.
     * @param termID
     *  Taxonomy term id.
     * @returns string
     *  Returns the name of the taxonomy term.
     */
    this.findLabel = function(vocab, termID) {
      if (vocab[termID]) {
        return vocab[termID].label;
      }
      else {
        var termName = '';
        angular.forEach(vocab, function(value, key) {
          if (value.hasOwnProperty('children')) {
            angular.forEach(value.children, function(child, key) {
              var id = termID.toString();
              if (child.id == id) {
                termName = child.label;
              }
              else if (child.hasOwnProperty('children')) {
                angular.forEach(child.children, function(childChild, childKey) {
                  if (childChild.id == id) {
                    termName = childChild.label;
                  }
                });
              }
            });
          }
        });
        return termName;
      }
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
      var elemWidth = angular.element(event.currentTarget).outerWidth();
      // Toggle the visibility variable.
      popups[name] = popups[name] == 0 ? 1 : 0;
      // Move the popover to be at the end of the button.
      angular.element(".hidden-checkboxes").css('left', elemWidth);
    };
  });
