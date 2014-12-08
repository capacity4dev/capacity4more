angular.module('c4mApp')
  .controller('DrupalFormCtrl', function($scope, DrupalSettings, EntityResource, Request, $window, $document, $modal, QuickPostService) {

    $scope.data = DrupalSettings.getData('vocabularies');

    $scope.model = {};

    $scope.popups = [];
    angular.forEach($scope.data, function(value, key) {
      $scope.popups[key] = 0;
    });

    // Toggle the visibility of the popovers.
    $scope.togglePopover = function(name, event) {
      QuickPostService.togglePopover(name, event, $scope.popups);
    };

    // Close all popovers on "ESC" key press.
    $scope.keyUpHandler = function(keyEvent) {
      QuickPostService.keyUpHandler(keyEvent, $scope);
    };

    $scope.updateSelectedTerms = function(key) {
      // Check/uncheck the checkbox in the drupal form.
      if($scope.model[key]) {
        jQuery('input[type=checkbox][value="' + key + '"]').attr("checked", true);
//        jQuery('input[type=radio][value="' + key + '"]').attr("checked", true);
      }
      else {
        jQuery('input[type=checkbox][value="' + key + '"]').attr("checked", false);
//        jQuery('input[type=radio][value="' + key + '"]').attr("checked", false);
      }
    };

    // Call the keyUpHandler function on key-up.
    $document.on('keyup', $scope.keyUpHandler);
  });
