<?php
/**
 * @file
 * Activity stream wrapper.
 */
?>
<div class="activity-stream" ng-controller="ActivityCtrl">
  <!-- Display an error if we can't update the activity stream-->
  <div ng-show="stream.status > 0 && stream.status != 200" class="messages">
    <div class="alert alert-danger">
      <?php print t('Error loading activity stream.') ?>
    </div>
  </div>
  <div ng-show="newActivities.length > 0" class="messages" role="alert">
    <div class="alert alert-info" id="new-activities-button" ng-click="showNewActivities(0)">
      <?php print t('{{newActivities.length}} new post(s)') ?>
    </div>
  </div>
  <!-- The activity stream-->
  <div ng-repeat="activity in existingActivities" ng-class="{'first': $first, 'last': $last}" ng-bind-html="activity.html" class="activities" id="activity-{{activity.id}}"></div>

  <div class="show-more-wrapper" ng-if="showMoreButton">
    <p class="show-more text-center">
      <a href="javascript://" id="load-more-button" ng-click="showMoreActivities()" class="btn btn-primary"><?php print t('show more') ?></a>
    </p>
  </div>
</div>
