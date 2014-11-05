'use strict';

angular.module('c4mApp', [
    'ngPrettyJson',
    'textAngular',
    'ui.select2',
    'angularFileUpload'
  ], function($httpProvider) {

    // Use x-www-form-urlencoded Content-Type
    $httpProvider.defaults.headers.post['Content-Type'] = 'application/x-www-form-urlencoded;charset=utf-8';

});
