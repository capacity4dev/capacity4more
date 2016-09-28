/**
 * @file
 * Provides the Quick Post Controller (ActivityCtrl).
 */

'use strict';

angular.module('c4mApp')
  .controller('QuickPostFormCtrl', function ($scope, DrupalSettings, EntityResource, Request, $window, $document, $modal, QuickPostService, $filter, FileUpload) {

    $scope.data = DrupalSettings.getData('vocabularies');

    $scope.data.group = DrupalSettings.getData('group');

    // Get related to the discussion documents.
    $scope.data.relatedDocuments = DrupalSettings.getData('relatedDocuments');

    // Get the form Identifier, for the related documents widget.
    $scope.formId = DrupalSettings.getData('formId');

    $scope.fieldName = '';

    $scope.model = {};

    $scope.basePath = DrupalSettings.getBasePath();

    /**
     * Uploading document file.
     *
     * @param $files
     *  The file.
     * @param fieldName
     *  Name of the current field.
     */
    $scope.onFileSelect = function ($files, fieldName) {

      $scope.setFieldName(fieldName);
      // $files: an array of files selected, each file has name, size, and type.
      for (var i = 0; i < $files.length; i++) {
        var file = $files[i];
        FileUpload.upload(file).then(function (data) {
          var fileId = data.data.data[0].id;
          $scope.data.fileName = data.data.data[0].label;
          $scope.serverSide.file = data;
          var openPath = DrupalSettings.getData('purl');
          Drupal.overlay.open(openPath  + '/overlay-file/' + fileId + '/quick' + '?render=overlay');
        });
      }
    };

    /**
     * Opens the system's file browser.
     */
    $scope.browseFiles = function (fieldName) {
      angular.element('#' + fieldName).click();
    };

    /**
     * Set the name of the current field.
     *
     * @param fieldName
     */
    $scope.setFieldName = function (fieldName) {
      $scope.fieldName = fieldName;
    };
  });

