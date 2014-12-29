angular.module('c4mApp')
  .controller('DocumentCtrl', function($scope, DrupalSettings, EntityResource, Request) {

    $scope.data = DrupalSettings.getData('vocabularies');

    $scope.data.relatedDocuments = [];

    $scope.relatedIds = '';

    $scope.baseUrl = DrupalSettings.getBasePath();

    $scope.model = {};

    // Getting all existing documents.
    $scope.documents = DrupalSettings.getDocuments();

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
    $scope.createDocument = function(event, fileId, data, addToLibrary) {
      // Preventing the form from redirecting to the "action" url.
      // We nee the url in the action because of the "overlay" module.
      event.preventDefault();
      $scope.fieldSchema = DrupalSettings.getFieldSchema();
      var resourceFields = $scope.fieldSchema.resources['documents'];
      var submitData = Request.cleanFields(data, resourceFields);

      angular.forEach(resourceFields, function (data, field) {
        // Don't change the group field Or resource object.
        if (field == 'resources' || field == 'group' || field == "tags") {
          return;
        }
        var allowedValues = field == "categories" ? data.form_element.allowed_values.categories : data.form_element.allowed_values;
        if(angular.isObject(allowedValues) && Object.keys(allowedValues).length) {
          submitData[field] = {};
        }

        var textFields = ['label', 'body', 'tags', 'organiser' , 'datetime'];
        angular.forEach(textFields, function (field) {
          if (!field){
            submitData[field] = field == 'tags' ? [] : '';
          }
        });
      });
      submitData.document = fileId;
      submitData.group = DrupalSettings.getData('groupID');

      EntityResource.createEntity(submitData, 'documents', resourceFields)
        .success( function (data, status) {
          var nid = data.data[0].id;



          $scope.$emit('addDocument', data.data[0]);



          if (!addToLibrary) {
            var item = '(' + nid + ')';

            // Multiple values.
            var value = jQuery('#edit-c4m-related-document-und', parent.window.document).val();
            var nids = jQuery('#related-documents', parent.window.document).val();
            if (value.indexOf(item) == -1) {
              value = value ? value + ', ' + item : item;
              nids = nids ? nids + ',' + nid : nid;
            }

            jQuery('#edit-c4m-related-document-und', parent.window.document).val(value);
            jQuery('#related-documents', parent.window.document).val(nids).trigger('click');


            parent.Drupal.overlay.close();
          }
          else {
            parent.Drupal.overlay.redirect(DrupalSettings.getData('purl') + '/node/' + nid + '/edit' + '?render=overlay');
          }

        });
    };

    $scope.closeOverlay = function() {
      parent.Drupal.overlay.close();
    };
  });
