'use strict';

/**
 * @ngdoc directive
 * @name c4mApp.directive:relatedDocuments
 * @description
 * # A list of related to the discussion documents.
 */
angular.module('c4mApp')
  .directive('relatedDocuments', function (DrupalSettings) {
    return {
      templateUrl: DrupalSettings.getBasePath() + 'profiles/capacity4more/libraries/bower_components/c4m-app/dist/directives/documents/documents.html',
      restrict: 'E',
      scope: {
        documents: '='
      },
      link: function postLink(scope) {
        console.log(scope.documents);

        scope.removeDoc = function(document) {
          var index = scope.documents.indexOf(document);
          if (index != -1) {
            scope.documents.splice(index, 1);
          }
        };
      }
    };
  });
