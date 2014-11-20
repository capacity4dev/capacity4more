angular.module('c4mApp')
  .controller('ModalInstanceCtrl', function ($scope, $modalInstance, getFile) {
    $scope.file = getFile;
    $scope.selected = {
      item: getFile
    };

    $scope.ok = function () {
      $modalInstance.close($scope.selected.item);
    };

    $scope.cancel = function () {
      $modalInstance.dismiss('cancel');
    };
  });
