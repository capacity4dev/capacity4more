<div class="activity-stream">
  <!-- Display an error if we can't update the activity stream-->
  <div ng-show="stream.status > 0 && stream.status != 200" class="messages">
    <div class="alert alert-danger">
      <?php print t('Error loading activity stream.') ?>
    </div>
  </div>
  <!-- The activity stream-->
  <div ng-repeat="activity in activities">
    <div ng-bind-html="activity.html" id="activity-{{activity.id}}"></div>
  </div>
</div>
