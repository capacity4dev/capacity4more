'use strict';

/**
 * @ngdoc directive
 * @name c4mApp.directive:relatedDocuments
 * @description
 * # A list of related to the discussion documents.
 */
angular.module('c4mApp')
  .directive('relatedDocuments', function (DrupalSettings, $window) {
    return {
      templateUrl: DrupalSettings.getBasePath() + 'profiles/capacity4more/libraries/bower_components/c4m-app/dist/directives/documents/documents.html',
      restrict: 'E',
      scope: {
        relatedDocuments: '=',
        documents: '='
      },
      link: function postLink(scope) {
        scope.data = {};

        angular.forEach(scope.relatedDocuments, function(value, key) {
          var result = scope.documents.filter(function( obj ) {
            return obj.id == value;
          });
          scope.data[key] = result[0];
          scope.data[key].document.filesize = $window.filesize(scope.data[key].document.filesize);
        });

        scope.removeDoc = function(id) {



          var index = scope.relatedDocuments.indexOf(id);
          if (index != -1) {
            scope.relatedDocuments.splice(index, 1);
          }
        };
      }
    };
  });
