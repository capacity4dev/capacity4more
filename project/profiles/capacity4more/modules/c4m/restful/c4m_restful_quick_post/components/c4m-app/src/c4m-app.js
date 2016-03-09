/**
 * @file
 * The c4m AngulerJS app.
 */

'use strict';

angular.module('c4mApp', [
  'ui.select2',
  'ui.bootstrap',
  'angularFileUpload',
  'ngAnimate',
  'angular-carousel',
  'ngTouch'
], function ($httpProvider) {

  // Use x-www-form-urlencoded Content-Type.
  $httpProvider.defaults.headers.post['Content-Type'] =
    'application/x-www-form-urlencoded;charset=utf-8';
});
