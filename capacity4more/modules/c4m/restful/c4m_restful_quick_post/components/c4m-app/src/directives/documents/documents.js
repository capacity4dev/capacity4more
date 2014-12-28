'use strict';

/**
 * @ngdoc directive
 * @name c4mApp.directive:relatedDocuments
 * @description
 * # A list of related to the discussion documents.
 */
angular.module('c4mApp')
  .directive('relatedDocuments', function (DrupalSettings, $window, $log) {
    return {
      templateUrl: DrupalSettings.getBasePath() + 'profiles/capacity4more/libraries/bower_components/c4m-app/dist/directives/documents/documents.html',
      restrict: 'E',
      scope: {
        relatedDocuments: '=',
        documents: '='
      },
      link: function postLink(scope, element) {
        scope.title = 'foo';

        /**
         * Create array of related document objects.
         *
         * @param relatedDocuments
         *  List of related documents ids
         *
         * @returns {{}}
         *  Returns array of related document information objects
         */
        scope.updateDocumentsData = function(relatedDocuments) {

          var data = {};
          angular.forEach(relatedDocuments, function(value, key) {
            $log.log(value, key);
            // Find document object by document id in all objects.
            var result =  scope.documents.filter(function( obj ) {
              return obj.id == value;
            });
            data[key] = angular.copy(result[0], data[key]);
            // Format file size.
            data[key].document.filesize = $window.filesize(data[key].document.filesize);
          });
          return data;
        };

        $log.log(element);

        element.parents('#discussion-node-form').find('#related-documents').on('click', function (event) {
          var val = jQuery(this).val();
          scope.$apply(function(scope) {
            var ids = val.split(",");
            $log.log(scope);
            scope.relatedDocuments = ids;
            scope.data = scope.updateDocumentsData(scope.relatedDocuments);
          });
        });

        scope.data = scope.updateDocumentsData(scope.relatedDocuments);

        // Updating data when added or removed item from the related documents.
        scope.$watch('relatedDocuments', function(newValue, oldValue) {
          if (newValue !== oldValue) {
            scope.data = scope.updateDocumentsData(newValue);
          }
        }, true);

        // Removing document from related documents.
        scope.removeDocument = function(id) {
          var index = scope.relatedDocuments.indexOf(id.toString());
          if (index != -1) {
            scope.relatedDocuments.splice(index, 1);
          }
        };
      }
    };
  });
