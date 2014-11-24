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

        // Create array of related document objects.
        scope.updateData = function(relatedDocuments, allDocuments) {
          var data = {};
          angular.forEach(relatedDocuments, function(value, key) {
            var result =  allDocuments.filter(function( obj ) {
              return obj.id == value;
            });
            data[key] = angular.copy(result[0], data[key]);
            data[key].document.filesize = $window.filesize(data[key].document.filesize);
          });
          return data;
        };

        scope.data = scope.updateData(scope.relatedDocuments, scope.documents);

        scope.$watch('relatedDocuments', function(newValue, oldValue) {
          if (newValue !== oldValue) {
            scope.data = scope.updateData(newValue, scope.documents);
          }
        }, true);

        // Remove document from related documents.
        scope.removeDoc = function(id) {
          var index = scope.relatedDocuments.indexOf(id);
          if (index != -1) {
            scope.relatedDocuments.splice(index, 1);
          }
        };
      }
    };
  });
