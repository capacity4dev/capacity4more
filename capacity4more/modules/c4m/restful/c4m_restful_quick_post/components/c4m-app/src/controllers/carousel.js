'use strict';

angular.module('c4mApp')
  .controller('CarouselCtrl', function($scope, DrupalSettings) {
    $scope.carouselImages = DrupalSettings.getCarousels();
  });
