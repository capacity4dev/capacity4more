/**
 * @file
 * Provides the Activity Controller (ActivityCtrl).
 */

'use strict';

angular.module('c4mApp')
  .controller('ActivityCtrl', function ($scope, DrupalSettings, EntityResource, $timeout, $interval, $sce) {

    /*
     * Re-init the Bootstrap tooltips after updating the activity stream.
     */
    $scope.bindBoostrapTooltips = function () {
      $timeout(function () {
        var tooltips = angular.element('[data-toggle="tooltip"]');
        tooltips.tooltip();
      }, 100);
    };

    // Get the current group ID.
    $scope.group = DrupalSettings.getData('entity').group;

    $scope.topics = DrupalSettings.getData('request').topics;

    $scope.homepage = DrupalSettings.getData('request').homepage;

    $scope.homepage = $scope.homepage === undefined ? 0 : $scope.homepage;

    $scope.hideArticles = DrupalSettings.getData('request').hide_articles;

    $scope.hideArticles = $scope.hideArticles === undefined ? 0 : $scope.hideArticles;

    // Getting the activity stream.
    $scope.existingActivities = DrupalSettings.getActivities();

    // Init the bootstrap tooltips.
    $scope.bindBoostrapTooltips();

    // Empty new activities.
    $scope.newActivities = [];

    // Activity stream status, refresh time.
    $scope.stream = {
      // The first one is the last loaded activity, (if no activities, insert 0).
      lastLoadedTimestamp: $scope.existingActivities.length > 0 ? $scope.existingActivities[0].timestamp : 0,
      // The Timestamp of the last activity in the activity stream (bottom) which has the lowest Timestamp (if no activities, insert 0).
      firstLoadedTimestamp: $scope.existingActivities.length > 0 ? $scope.existingActivities[$scope.existingActivities.length - 1].timestamp : 0,
      status: 0
    };

    // Range of the initial loaded activity stream.
    $scope.range = 10;

    // Display the "show more" button only if the activity stream is equal to the the range.
    $scope.showMoreButton = $scope.existingActivities.length >= $scope.range;

    // Refresh rate of the activity stream (60000 is one minute).
    // @TODO: Import the refresh rate from the drupal settings.
    $scope.refreshRate = 60000;

    /**
     * Refreshes the activity stream.
     *
     * The refresh rate is scope.refreshRate.
     */
    $scope.refresh = function () {
      $scope.addNewActivities('newActivities');
    };
    // Start the activity stream refresh.
    $scope.refreshing = $interval($scope.refresh, $scope.refreshRate);

    /**
     * Adds newly fetched activities.
     *
     * To either to the activity-stream or the load button.
     * Depending on if the current user added an activity or it's fetched from
     * the server.
     *
     * @param type
     *  Determines to which variable the new activity should be added,
     *  existingActivities: The new activity will be added straight to the
     *                      activity stream. (Highlighted as well)
     *  newActivities: The "new posts" notification button will appear in the
     *                 user's activity stream.
     */
    $scope.addNewActivities = function (type) {
      if (type == 'existingActivities') {
        // Merge all the loaded activities before adding the created one.
        $scope.showNewActivities(0);
      }

      var activityStreamInfo = {
        group: $scope.group,
        lastTimestamp: $scope.stream.lastLoadedTimestamp,
        homepage: $scope.homepage,
        hideArticles: $scope.hideArticles,
        topics: $scope.topics
      };

      // Don't send a request when data is missing.
      if (!activityStreamInfo.lastTimestamp || !activityStreamInfo.group) {
        // If last Timestamp is 0, this is a new group and there are no activities.
        if (activityStreamInfo.lastTimestamp != 0) {
          $scope.stream.status = 500;
          return false;
        }
      }

      // Call the update stream method.
      EntityResource.updateStream(activityStreamInfo, 'update')
        .success(function (data, status) {
          // Update the stream status.
          $scope.stream.status = status;

          // Update if there's new activities.
          if (data.data) {
            if (data.data.length == 0) {
              return;
            }
            // Count the activities that were fetched.
            var position = 0;
            angular.forEach(data.data, function (activity) {
              this.splice(position, 0, {
                id: activity.id,
                timestamp: activity.timestamp,
                html: $sce.trustAsHtml(activity.html)
              });
              position++;
            }, $scope[type]);

            // Update the last loaded Timestamp.
            // Only if there's new activities from the server.
            $scope.stream.lastLoadedTimestamp = $scope[type][0].timestamp ? $scope[type][0].timestamp : $scope.stream.lastLoadedTimestamp;
          }
        })
        .error(function (data, status) {
          // Update the stream status if we get an error, This will display the error message.
          $scope.stream.status = status;
        });
    };

    /**
     * Merge the "new activity" with the existing activity stream.
     *
     * When a user has clicked on the "new posts", we grab the activities in
     * the "new activity" group and push them to the top of the
     * "existing activity", and clear the "new activity" group.
     *
     * @param position.
     *  The position in which to add the new activities.
     */
    $scope.showNewActivities = function (position) {
      angular.forEach($scope.newActivities, function (activity) {
        this.splice(position, 0, {
          id: activity.id,
          timestamp: activity.timestamp,
          html: activity.html
        });
        position++;
      }, $scope.existingActivities);
      $scope.newActivities = [];
    };

    /**
     * When clicking on the "show more" button.
     *
     * Request the next set of activities from RESTful,
     * Adds the newly loaded activity stream to the bottom of the "existingActivities" array.
     */
    $scope.showMoreActivities = function () {
      // Determine the position of the loaded activities depending on the number of the loaded page.
      var position = $scope.existingActivities.length;

      var activityStreamInfo = {
        group: $scope.group,
        firstLoadedTimestamp: $scope.stream.firstLoadedTimestamp,
        homepage: $scope.homepage,
        hideArticles: $scope.hideArticles,
        topics: $scope.topics
      };

      EntityResource.updateStream(activityStreamInfo, 'load')
        .success(function (data, status) {
          if (data.data) {
            angular.forEach(data.data, function (activity) {
              this.splice(position, 0, {
                id: activity.id,
                timestamp: activity.timestamp,
                html: $sce.trustAsHtml(activity.html)
              });
              position++;
            }, $scope.existingActivities);

            if (data.data.length > 0) {
              // Update the Timestamp of the last activity in the activity stream.
              $scope.stream.firstLoadedTimestamp = data.data[data.data.length - 1].timestamp;
            }

            // Keep the "show more" button, only if the remaining activities to load is more than the range.
            // The "Count" variable will go down as we are filtering with the lowest activity Timestamp.
            $scope.showMoreButton = data.data.length >= $scope.range;

            // Re-init the bootstrap tooltips for the added items.
            $scope.bindBoostrapTooltips();
          }
        });
    };

    // Listening to broadcast for changes in the activity.
    // e.g. Adding a new activity from the "main" controller.
    $scope.$on('c4m.activity.update', function () {
      // Load new activity.
      $scope.addNewActivities('existingActivities');
    });

    // Listening to broadcast for changes in the refresh.
    // This will stop or resume the refresh of the activity stream.
    // In case of resuming the activity stream,
    // Wait for 10 seconds to avoid any conflicts between the normal refresh and the "create new activity" pull.
    $scope.$on('c4m.activity.refresh', function (broadcast, action) {
      if (action == 'stop') {
        $interval.cancel($scope.refreshing);
      }
      else {
        $timeout(function () {
          $scope.refreshing = $interval($scope.refresh, $scope.refreshRate);
        }, 10000);
      }
    });
  });
