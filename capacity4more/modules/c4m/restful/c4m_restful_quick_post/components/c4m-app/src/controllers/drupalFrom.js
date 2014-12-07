'use strict';

angular.module('c4mApp')
  .controller('DrupalFromCtrl', function($scope, DrupalSettings, $document, QuickPostService) {

    $scope.data = DrupalSettings.getData('vocabularies');

    angular.forEach($scope.data, function(value, key) {
      $scope.popups[value] = 0;
    });

    // Toggle the visibility of the popovers.
    $scope.togglePopover = function(name, event) {
      QuickPostService.togglePopover(name, event, $scope.popups);
    };

    // Close all popovers on "ESC" key press.
    $scope.keyUpHandler = function(keyEvent) {
      QuickPostService.keyUpHandler(keyEvent, $scope);
    };

    // Call the keyUpHandler function on key-up.
    $document.on('keyup', $scope.keyUpHandler);
  });
