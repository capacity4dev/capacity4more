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
      console.log(oldScope.fieldSchema);

      scope.debug = angular.copy(oldScope.debug, scope.debug);
      scope.basePath = angular.copy(oldScope.basePath, scope.basePath);
      return scope;
    }

  });
