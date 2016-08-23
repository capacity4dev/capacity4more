<?php

/**
 * @file
 * Template to render the Quick post forms.
 */
?>
<form name="entityForm"
      ng-submit="submitForm(data, selectedResource, 'quick_post')"
      xmlns="http://www.w3.org/1999/html">

<div class="form-group text" ng-class="{ 'has-error' : errors.label }">
  <input id="label" class="form-control" name="label" ng-click="updateResource('<?php print key($show_resources) ?>', $event)" type="text" ng-model="data.label"
         placeholder="<?php print t('Title'); ?>" required>

  <p ng-show="errors.label"
     class="help-block"><?php print t('Title is too short.'); ?></p>

  <div class="errors">
    <ul ng-show="serverSide.data.errors.label">
      <li ng-repeat="error in serverSide.data.errors.label">{{error}}</li>
    </ul>
  </div>
</div>

<?php if (count($show_resources) > 1): ?>
  <bundle-select items="resources" on-change="updateResource" selected-resource="selectedResource"></bundle-select>
  <div id="form-spinner" ng-if="resourceSpinner">
    <i class="fa fa-refresh fa-spin fa-2x"></i>
  </div>
<?php endif; ?>

<div ng-show="resources[selectedResource]" id="quick-post-fields">

<!-- Body editor-->
<div class="form-group" id="body-wrapper" ng-class="{ 'has-error' : errors.body }">
  <textarea ckeditor="editorOptions" name="body" id="body" ng-model="data.body"></textarea>

  <p ng-show="errors.body" class="errors"><?php print t('Body is required.'); ?></p>

  <div class="errors">
    <ul ng-show="serverSide.data.errors.body">
      <li ng-repeat="error in serverSide.data.errors.body">{{error}}</li>
    </ul>
  </div>
</div>


<div ng-if="selectedResource == 'discussions'" ng-class="{ 'has-error' : errors.discussion_type }">
  <types field="'discussion_type'" field-schema="referenceValues" type="data.discussion_type" on-change="updateType"
         cols="3"></types>
  <p ng-show="errors.discussion_type" class="help-block"><?php print t('Discussion type is required.'); ?></p>
</div>

<div class="form-group btn-group clearfix btn-group-selectors" ng-class="{ 'has-error' : errors.topic }">
  <div class="label-wrapper">
    <label>{{fieldSchema.resources[selectedResource].topic.info.label}}</label>
  <span id="topic_description"
        class="description">{{fieldSchema.resources[selectedResource].topic.info.description}}</span>
  </div>
  <div class="checkboxes-wrapper">
    <div class="checkboxes-wrapper">
      <div class="popup-button">
        <button type="button" ng-click="togglePopover('topic', $event)" class="btn">
          &nbsp;<?php print t('Select Topic'); ?></button>
        <p ng-show="errors.topic" class="help-block"><?php print t('Topic is required.'); ?></p>
      </div>
      <div class="selected-values" ng-show="data.topic">
      <span ng-if="value === true" ng-repeat="(key, value) in data.topic">
        {{ findLabel(topic, key) }} <i ng-click="removeTaxonomyValue(key, 'topic')" class="fa fa-times"></i>
      </span>
      </div>
      <!-- Hidden topic checkboxes.-->
      <div class="popover right hidden-checkboxes" ng-show="popups.topic">
        <div class="arrow"></div>
        <div class="popover-content">
          <list-terms type="topic" popup="popups.topic" model="data.topic" items="topic"></list-terms>
        </div>
      </div>
    </div>
  </div>
</div>

<div class="actions row">
  <div class="col-xs-12">
    <div class="qp-post-button">
      <button type="submit" id="quick-submit" class="btn btn-primary" tabindex="100"><?php print t('POST'); ?></button>
    </div>
    <div class="qp-post-fullform">
      <a href="javascript://" id="full-from-button"
         ng-click="submitForm(data, selectedResource, 'full_form')"><?php print t('Create in full form'); ?></a>
    </div>
    <div class="qp-post-cancel">
      <a href="javascript://" id="clear-button" ng-click="resetEntityForm()"><?php print t('Cancel'); ?></a>
    </div>
  </div>
</div>
</div>
</form>

<!-- Display an error if we can't save an entity-->
<div ng-show="serverSide.status > 0 && serverSide.status != 200 && serverSide.status != 201" class="messages">
  <div class="alert alert-danger">
    <?php print t('Error saving {{ resources[createdResource].bundle }}.') ?>
  </div>
</div>
