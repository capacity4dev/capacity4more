angular.module('c4mApp')
  .controller('ModalInstanceCtrl', function ($scope, $modalInstance, Request, EntityResource, getScope, ModalService, QuickPostService) {

    $scope = ModalService.getModalObject($scope, getScope);

    //Checking if this is full form or not.
    $scope.fullForm = true;

    $scope.fileName = $scope.data.fileName;

    // Getting the resources information.
    $scope.resources = {'documents' : {bundle: "Document", description: "Add a Document"}};

    $scope.selectedResource = Object.keys($scope.resources)[0];

    $scope = QuickPostService.setDefaults($scope);

    /**
     * Prepares the referenced "data" to be objects and normal field to be empty.
     * Responsible for toggling the visibility of the taxonomy-terms checkboxes.
     * Set "popups" to 0, as to hide all of the pop-overs on load.
     */
    function prepareData() {
      $scope.popups = {};

      angular.forEach($scope.fieldSchema, function (data, field) {
        // Don't change the group field Or resource object.
        if (field == 'resources' || field == 'group' ) {
          return;
        }
        var allowedValues = data.form_element.allowed_values;
        if(angular.isObject(allowedValues) && Object.keys(allowedValues).length && field != "tags") {
          $scope.referenceValues[field] = allowedValues;
          $scope.popups[field] = 0;
        }
      });
    }

    // Preparing the data for the form.
    prepareData();

    $scope = QuickPostService.formatData($scope);

    $scope = QuickPostService.formatData($scope);

    // Displaying the fields upon clicking on the label field.
    $scope.showFields = function() {
      QuickPostService.showFields($scope);
    }

    // Getting matching tags.
    $scope.tagsQuery = function () {
      QuickPostService.tagsQuery(query, scope);
    };



    // Updates the bundle of the entity to send to the correct API url.
    $scope.updateResource = function(resource, event) {
      $scope.selectedResource = QuickPostService.updateResource(resource, event);
    };

    // Updates the type of the selected resource.
    $scope.updateType = function(type, field, event) {
      QuickPostService.updateType(type, field, event, $scope);
    };

    // Toggle the visibility of the popovers.
    $scope.togglePopover = function(name, event) {
      QuickPostService.togglePopover(name, event, $scope);
    };

    // Close all popovers on "ESC" key press.
    $scope.keyUpHandler = function(keyEvent) {
      QuickPostService.keyUpHandler(keyEvent, $scope);
    };

    /**
     * Submit form.
     *
     *  @param data
     *    The submitted data.
     *  @param resource
     *    The bundle of the node submitted.
     *  @param type
     *    The type of the submission.
     */
    $scope.submitForm = function(data, resource, type) {
      // Reset all errors.
      $scope.errors = {};

      // Get the fields of this resource.
      var resourceFields = $scope.fieldSchema.resources[resource];

      // Clean the submitted data, Drupal will return an error on undefined fields.
      var submitData = Request.cleanFields(data, resourceFields);

      // Check for required fields.
      var errors = Request.checkRequired(submitData, resource, resourceFields);

      // Check the type of the submit.
      // Make node unpublished if requested to create in full form.
      submitData.status = type == 'full_form' ? 0 : 1;

      // Cancel submit and display errors if we have errors.
      if (Object.keys(errors).length && type == 'quick_post') {
        angular.forEach( errors, function(value, field) {
          this[field] = value;
        }, $scope.errors);
        return false;
      }

      // Call the create entity function service.
      EntityResource.createEntity(submitData, resource, resourceFields)
        .success( function (data, status) {
          $modalInstance.close(data.data[0]);
        })
        .error( function (data, status) {
          $scope.serverSide.data = data;
          $scope.serverSide.status = status;
          prepareData();
        });
    };

    $scope.cancel = function () {
      $modalInstance.dismiss('cancel');
    };
  });
