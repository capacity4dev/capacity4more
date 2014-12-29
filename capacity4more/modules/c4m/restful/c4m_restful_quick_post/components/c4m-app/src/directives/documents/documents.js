'use strict';

/**
 * @ngdoc directive
 * @name c4mApp.directive:relatedDocuments
 * @description
 * # A list of related to the discussion documents.
 */
angular.module('c4mApp')
  .directive('relatedDocuments', function (DrupalSettings, $window, $log, EntityResource) {
    return {
      templateUrl: DrupalSettings.getBasePath() + 'profiles/capacity4more/libraries/bower_components/c4m-app/dist/directives/documents/documents.html',
      restrict: 'E',
      scope: {
        relatedDocuments: '=',
//        documents: '='
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

          var documents = {};
          angular.forEach(relatedDocuments, function(value, key) {

            EntityResource.getEntityData('documents', value).success( function (data, status) {
              documents[key] = data.data[0];
              // Format file size.
              documents[key].document.filesize = $window.filesize(documents[key].document.filesize);
            });
          });
          return documents;
        };

        element.parents('#discussion-node-form').find('#related-documents').on('click', function (event) {
          var val = jQuery(this).val();
          scope.$apply(function(scope) {
            var ids = val.split(",");
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
          var value = jQuery('#edit-c4m-related-document-und').val();
          value = value.replace('(' + id + '), ', '');
          value = value.replace('(' + id + ')', '');

          var ids =jQuery('#related-documents').val();
          ids = ids.replace(id + ', ', '');
          ids = ids.replace(id, '');

          jQuery('#edit-c4m-related-document-und').val(value);
          jQuery('#related-documents').val(ids);
        };
      }
    };
  });
