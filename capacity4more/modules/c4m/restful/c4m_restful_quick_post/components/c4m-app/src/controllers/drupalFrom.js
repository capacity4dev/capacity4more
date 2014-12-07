'use strict';

angular.module('c4mApp')
  .controller('DrupalFromCtrl', function($scope, DrupalSettings, EntityResource, Request, $window, $document, $modal, QuickPostService, $interval, $sce, FileUpload) {

    $scope.data = DrupalSettings.getData('vocabularies');

    $scope.popups = [];
    angular.forEach($scope.data, function(value, key) {
      $scope.popups.language = 0;
    });

    // Toggle the visibility of the popovers.
    $scope.togglePopover = function() {
      $scope.popups.language = $scope.popups.language == 1 ? 0 : 1;
    };

    // Close all popovers on "ESC" key press.
    $scope.keyUpHandler = function(keyEvent) {
      QuickPostService.keyUpHandler(keyEvent, $scope);
    };

    $scope.updateSelectedTerms = function(key) {
        jQuery('input[type=checkbox][value="' + key + '"]').attr("checked", "true");
    };
    // Call the keyUpHandler function on key-up.
    $document.on('keyup', $scope.keyUpHandler);
  });
