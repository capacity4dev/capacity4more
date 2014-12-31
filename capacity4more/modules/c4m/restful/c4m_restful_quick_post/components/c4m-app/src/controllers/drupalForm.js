'use strict';

angular.module('c4mApp')
  .controller('DrupalFormCtrl', function($scope, DrupalSettings, EntityResource, Request, $window, $document, $modal, QuickPostService, $filter) {

    $scope.data = DrupalSettings.getData('vocabularies');

    $scope.data.group = DrupalSettings.getData('group');

    $scope.model = {};

    $scope.basePath = DrupalSettings.getBasePath();

    $scope.tagIds = 14;

    $scope.values = DrupalSettings.getData('values');

    angular.forEach($scope.data, function(values, vocab) {
      $scope.model[vocab] = {};
    });

    angular.forEach($scope.values, function(values, vocab) {
      angular.forEach(values, function(value, id) {
        $scope.model[vocab][id] = value;
      });
    });

    $scope.popups = [];
    angular.forEach($scope.data, function(value, key) {
      $scope.popups[key] = 0;
    });

    $scope.filteredTerms = angular.copy($scope.data);

    $scope.updateSearch = function(vocab) {
      $scope.filteredTerms[vocab] = $filter('termsFilter')($scope.data[vocab], $scope.searchTerm);
    };

    // Toggle the visibility of the popovers.
    $scope.togglePopover = function(name, event) {
      QuickPostService.togglePopover(name, event, $scope.popups);
    };

    // Close all popovers on "ESC" key press.
    $scope.keyUpHandler = function(keyEvent) {
      QuickPostService.keyUpHandler(keyEvent, $scope);
    };

    // Getting matching tags.
    $scope.tagsQuery = function (query) {
      QuickPostService.tagsQuery(query, $scope);
    };

    $scope.$watch('data.tags', function() {
      //var formElement = angular.element('.node-form');
      //var input = angular.element('<input type="hidden" name="og_vocabulary[und][0][' + $scope.tagIds + ']" value="' + $scope.data.tags[0].text + ' (' + $scope.data.tags[0].id + ')"/>');
      //formElement.append(input);
    });

    function updateTerms(key, vocab) {
      // Check/uncheck the checkbox in the drupal form.
      if($scope.model[vocab][key]) {
        angular.element('input[type=checkbox][name="' + vocab + '[und][' + key + ']"]').prop("checked", true);
      }
      else {
        angular.element('input[type=checkbox][name="' + vocab + '[und][' + key + ']"]').prop("checked", false);
        if (key in $scope.data[vocab]) {
          angular.forEach($scope.data[vocab][key].children, function(child, itemKey) {
            var childID = child.id;

            if (childID in $scope.model[vocab] && $scope.model[vocab][childID] === true) {
              $scope.model[vocab][childID] = false;
              angular.element('input[type=checkbox][name="' + vocab + '[und][' + key + ']"]').prop("checked", false);
            }
          });
        }
      }
    }

    $scope.updateSelectedTerms = function(key, vocab) {
      updateTerms(key, vocab);
    };

    $scope.removeTaxonomyValue = function(key, vocab) {
      $scope.model[vocab][key] = false;
      updateTerms(key, vocab);
    };
      // Call the keyUpHandler function on key-up.
    $document.on('keyup', $scope.keyUpHandler);
  });
