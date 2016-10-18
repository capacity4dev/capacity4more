<?php

/**
 * @file
 * Template to render the Quick post forms.
 */
?>
<form name="entityForm" id="quick-post-form"
      ng-submit="submitForm(data, selectedResource, 'quick_post')"
      xmlns="http://www.w3.org/1999/html">

<div class="form-group text" ng-class="{ 'has-error' : errors.label }">
  <input id="label" class="form-control" name="label" type="text"
         ng-model="data.label"
         ng-attr-placeholder="{{ titlePlaceholder ? titlePlaceholderText : '' }}"
         ng-focus="focusQuickPostTitle('<?php print key($show_resources) ?>', $event)"
         ng-blur="titlePlaceholder = true"
         required>

  <p ng-show="errors.label"
     class="help-block"><?php print t('Title is too short.'); ?></p>

  <div class="errors">
    <ul ng-show="serverSide.data.errors.label">
      <li ng-repeat="error in serverSide.data.errors.label">{{error}}</li>
    </ul>
  </div>
</div>

<div ng-show="resources[selectedResource]" id="quick-post-fields">

<div ng-if="selectedResource == 'discussions'" ng-class="{ 'has-error' : errors.discussion_type }">
    <types field="'discussion_type'" field-schema="referenceValues" type="data.discussion_type" on-change="updateType"
            cols="3"></types>
    <p ng-show="errors.discussion_type" class="help-block"><?php print t('Discussion type is required.'); ?></p>
</div>

  <div class="field-type-entityreference field-name-c4m-related-document field-widget-c4m-add-document form-wrapper form-group" id="edit-c4m-related-document">
    <div class="ng-hide"><div class="form-item form-item-c4m-related-document-und form-type-textfield form-autocomplete form-group">
        <label class="control-label" for="edit-c4m-related-document-und">Documents </label>
        <div class="input-group">
          <input class="form-control form-text" type="text" id="edit-c4m-related-document-und" name="c4m_related_document[und]" value="" size="60" maxlength="1024" autocomplete="OFF" aria-autocomplete="list"/>
          <span class="input-group-addon">
            <span class="icon glyphicon glyphicon-refresh" aria-hidden="true"></span>
          </span>
        </div>
        <input type="hidden" id="edit-c4m-related-document-und-autocomplete" value="http://capacity4more.local/index.php?q=entityreference/autocomplete/tags/c4m_related_document/node/discussion/NULL" disabled="disabled" class="autocomplete" />
      </div>
    </div>
  </div>

<!-- Body editor-->
<div class="form-group" id="body-wrapper" ng-class="{ 'has-error' : errors.body }">

  <div>
    <input type="file" name="document-file" id="c4m-related-document" class="document_file" ng-file-select="onQuickPostFileSelect($files, 'c4m-related-document')">
    <a href="javascript://" ng-click="browseFiles('c4m-related-document')"></a>
    <span class="body-attachment-link"><label for="c4m-related-document"><i class="fa fa-paperclip"></i></label></span>
  </div>

  <textarea ckeditor="editorOptions" name="body" class="form-control" id="body" ng-model="data.body" placeholder="Share information or an idea, start debate or ask a question here..."></textarea>
  <p ng-show="errors.body" class="help-block"><?php print t('Body is required.'); ?></p>
  <related-quick-post-documents related-documents="data.relatedDocuments" form-id="formId" field-name="'c4m-related-document'"></related-quick-post-documents>
  <input type="text" id="input-c4m-related-document" class="hidden" value>

  <div class="cfm-file-upload-wrapper form-group input-wrapper file-wrapper" ng-class="{ 'has-error' : errors.document }">

    <div class="has-error" ng-show="serverSide.data.imageError">
      <ul class="help-block">
        <li><?php print t('An error occurred while trying to upload the attachment.') ?></li>
      </ul>
    </div>
  </div>

  <div class="errors">
    <ul ng-show="serverSide.data.errors.body">
      <li ng-repeat="error in serverSide.data.errors.body">{{error}}</li>
    </ul>
  </div>
</div>

<span>Create a post with additional details by using
  <a href="javascript://" id="full-from-button" ng-click="submitForm(data, selectedResource, 'full_form')"><?php print t('the advanced form'); ?></a>
instead.</span>

<div class="form-group btn-group clearfix btn-group-selectors topics-section" ng-class="{ 'has-error' : errors.topic }">
  <div class="label-wrapper">
    <span id="topic_description" class="description">
      {{fieldSchema.resources[selectedResource].topic.info.description}}
    </span>
  </div>
  <div class="checkboxes-wrapper">
    <div class="popup-button">
      <button type="button" ng-click="togglePopover('topic', $event)" class="btn quickpost-btn popup-btn">
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

  <div class="actions-row">
    <div class="actions-row-group">
      <input type="checkbox" id="notification" ng-model="data.notification">
      <label for="notification">Notify members of the group about this post</label>
    </div>
    <div class="actions-row-group">
      <div class="qp-post-button">
        <button type="submit" id="quick-submit" class="btn btn-primary quickpost-btn quickpost-submit-btn" tabindex="100"><?php print t('Post'); ?></button>
      </div>
      <div class="qp-post-cancel">
        <a href="javascript://" id="clear-button" ng-click="closeQuickPost()"><?php print t('Cancel'); ?></a>
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
