'use strict';

angular.module('c4mApp', [
    'ngPrettyJson',
    'ui.select2',
    'ui.bootstrap',
  ], function($httpProvider) {

    // Use x-www-form-urlencoded Content-Type
    $httpProvider.defaults.headers.post['Content-Type'] = 'application/x-www-form-urlencoded;charset=utf-8';

});
