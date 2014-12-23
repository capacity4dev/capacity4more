<div class="activity-stream">
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
  <div ng-repeat="activity in existingActivities" ng-bind-html="activity.html" class="activities" id="activity-{{activity.id}}"></div>

  <div class="show-more-wrapper">
    <p class="show-more">
      <a href="javascript://" ng-if="showMoreButton" ng-click="showMoreActivities()"><?php print t('show more') ?></a>
      <span ng-if="!showMoreButton"><?php print t('End of activities') ?></span>
    </p>
  </div>
</div>
