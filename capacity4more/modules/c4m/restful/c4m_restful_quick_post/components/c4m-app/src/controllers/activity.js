'use strict';

angular.module('c4mApp')
  .controller('ActivityCtrl', function($scope, DrupalSettings, EntityResource, $timeout, $interval, $sce) {

    // Get the current group ID.
    $scope.group = DrupalSettings.getData('entity').group;

    // Getting the activity stream.
    $scope.existingActivities = DrupalSettings.getActivities();

    // Empty new activities.
    $scope.newActivities = [];

    // Activity stream status, refresh time.
    $scope.stream = {
      // The first one is the last loaded activity, (if no activities, insert 0).
      lastLoadedID: $scope.existingActivities.length > 0 ? $scope.existingActivities[0].id : 0,
      status: 0
    };

    // refresh rate of the activity stream (60000 is one minute).
    // @TODO: Import the refresh rate from the drupal settings.
    $scope.refreshRate = 60000;

    /**
     * Refreshes the activity stream.
     * The refresh rate is scope.refreshRate.
     */
    $scope.refresh = function() {
      $scope.addNewActivities('newActivities');
    };
    // Start the activity stream refresh.
    $scope.refreshing = $interval($scope.refresh, $scope.refreshRate);

    /**
     * Adds newly fetched activities to either to the activity-stream or the load button,
     * Depending on if the current user added an activity or it's fetched from the server.
     *
     * @param type
     *  Determines to which variable the new activity should be added,
     *  existingActivities: The new activity will be added straight to the activity stream. (Highlighted as well)
     *  newActivities: The "new posts" notification button will appear in the user's activity stream.
     */
    $scope.addNewActivities = function(type) {
      if (type == 'existingActivities') {
        // Merge all the loaded activities before adding the created one.
        $scope.showNewActivities();
      }

      var activityStreamInfo = {
        group: $scope.group,
        lastId: $scope.stream.lastLoadedID
      };

      // Don't send a request when data is missing.
      if(!activityStreamInfo.lastId || !activityStreamInfo.group) {
        // If last ID is 0, this is a new group and there's no activities.
        if(activityStreamInfo.lastId != 0) {
          $scope.stream.status = 500;
          return false;
        }
      }

      // Call the update stream method.
      EntityResource.updateStream(activityStreamInfo)
        .success( function (data, status) {
          // Update the stream status.
          $scope.stream.status = status;

          // Update if there's new activities.
          if (data.data) {
            // Count the activities that were fetched.
            var position = 0;
            angular.forEach(data.data, function (activity) {
              this.splice(position, 0, {
                id: activity.id,
                html: $sce.trustAsHtml(activity.html)
              });
              position++;
            }, $scope[type]);

            // Update the last loaded ID.
            // Only if there's new activities from the server.
            $scope.stream.lastLoadedID = $scope[type][0].id ? $scope[type][0].id : $scope.stream.lastLoadedID;
          }
        })
        .error( function (data, status) {
          // Update the stream status if we get an error, This will display the error message.
          $scope.stream.status = status;
        });
    };

    /**
     * Merge the "new activity" with the existing activity stream.
     * When a user has clicked on the "new posts", we grab the activities in the "new activity" group and push them to the top of the "existing activity", and clear the "new activity" group.
     */
    $scope.showNewActivities = function() {
      var position = 0;
      angular.forEach ($scope.newActivities, function (activity) {
        this.splice(position, 0, {
          id: activity.id,
          created: activity.created,
          html: activity.html
        });
        position++;
      }, $scope.existingActivities);
      $scope.newActivities = [];
    };

    // Listening to broadcast for changes in the activity.
    // e.g. Adding a new activity from the "main" controller.
    $scope.$on('c4m.activity.update', function() {
      // Load new activity.
      $scope.addNewActivities('existingActivities');
    });

    // Listening to broadcast for changes in the refresh.
    // This will stop or resume the refresh of the activity stream.
    // In case of resuming the activity stream,
    // Wait for 10 seconds to avoid any conflicts between the normal refresh and the "create new activity" pull.
    $scope.$on('c4m.activity.refresh', function(broadcast, action) {
      if(action == 'stop') {
        $interval.cancel($scope.refreshing);
      }
      else {
        $timeout(function() {
          $scope.refreshing = $interval($scope.refresh, $scope.refreshRate);
        }, 10000);
      }
    });
  });
