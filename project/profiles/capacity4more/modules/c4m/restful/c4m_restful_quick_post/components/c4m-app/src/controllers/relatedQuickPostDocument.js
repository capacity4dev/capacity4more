/**
 * @file
 * Provides the Related Quick Post Documents controller.
 */

angular.module('c4mApp')
  .controller('DocumentQuickPostCtrl', function ($scope, DrupalSettings, EntityResource, Request) {

    $scope.data = DrupalSettings.getData('vocabularies');

    $scope.data.relatedDocuments = [];

    $scope.model = {};

    $scope.fieldName = 'c4m-related-document';
    $scope.formId = 'quick-post-form';

    /**
     * Create document node.
     *
     * @param event
     *  The submit event.
     * @param fileId
     *  Id of the attached file.
     * @param data
     *  The submitted data.
     * @param addToLibrary
     *  Open or not full form of adding document.
     */
    $scope.createDocument = function (event, fileId, data, addToLibrary) {
      // Preventing the form from redirecting to the "action" url.
      // We nee the url in the action because of the "overlay" module.
      event.preventDefault();
      DrupalSettings.getFieldSchema('documents')
        .then(function (data) {
          $scope.fieldSchema = data.c4m.field_schema;
          $scope.data.entity = data.c4m.data.entity;

          var resourceFields = $scope.fieldSchema.resources['documents'];
          var submitData = Request.cleanFields(data, resourceFields);

          angular.forEach(resourceFields, function (data, field) {
            // Don't change the group field Or resource object.
            if (field == 'resources' || field == 'group' || field == "tags") {
              return;
            }
            var allowedValues = field == "categories" ? data.form_element.allowed_values.categories : data.form_element.allowed_values;
            if (angular.isObject(allowedValues) && Object.keys(allowedValues).length) {
              submitData[field] = {};
            }

            var textFields = ['label', 'body', 'tags', 'organiser' , 'datetime'];
            angular.forEach(textFields, function (field) {
              if (!field) {
                submitData[field] = field == 'tags' ? [] : '';
              }
            });
          });
          submitData.document = fileId;
          submitData.group = DrupalSettings.getData('groupID');
          submitData.add_to_library = addToLibrary ? 1 : 0;

          EntityResource.createEntity(submitData, 'documents', resourceFields)
            .success(function (data, status) {
              var nid = data.data[0].id;
              var item = '(' + nid + ')';

              jQuery('#edit-' + $scope.fieldName + '-und', parent.window.document).val(item);
              jQuery('#input-' + $scope.fieldName, parent.window.document).val(nid).trigger('click');

              if (!addToLibrary) {
                // Save document and go to the parent page.
                parent.Drupal.overlay.close();
              }
              else {
                // Save document and go to its edit page to add more data.
                parent.Drupal.overlay.open(DrupalSettings.getData('purl') + '/overlay-node/' + nid + '/edit' + '?render=overlay');
              }
            });
        });
    };

    /**
     * Close the overlay.
     */
    $scope.closeOverlay = function () {
      parent.Drupal.overlay.close();
    };
  });
