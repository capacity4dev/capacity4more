angular.module('c4mApp')
  .controller('ModalDocumentsCtrl', function ($scope, $modalInstance, Request, EntityResource, getScope, ModalService, QuickPostService) {

    $scope = ModalService.getModalObject($scope, getScope);

    $scope.ok = function (id) {
      $modalInstance.close(id);
    };

    $scope.cancel = function () {
      $modalInstance.dismiss('cancel');
    };
  });
