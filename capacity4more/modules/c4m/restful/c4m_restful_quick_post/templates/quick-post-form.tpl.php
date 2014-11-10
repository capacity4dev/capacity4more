<div ng-app="c4mApp" ng-controller="MainCtrl">
  <div class="explanation">
    <em><?php print t('Quick Post') ?></em>
  </div>

  <form name="entityForm" ng-submit="submitForm(entityForm, data, selectedResource, 'quick_post')">

    <bundle-select items="resources" on-change="updateResource" current-resource="selectedResource"></bundle-select>

    <div class="form-group input-wrapper file-wrapper" ng-show="selectedResource == 'documents'" ng-class="{ 'has-error' : errors.document }">
      <div ng-show="dropSupported" class="form-control drop-box" ng-file-drop="onFileSelect($files);" ng-file-drop-available="dropSupported=true" ng-file-drag-over-class="file-upload-drag">

        <div ng-hide="serverSide.file">
          <?php print t('Drop file here to upload or'); ?>
          <a href="javascript://" ng-click="browseFiles()"><?php print t('Browse') ?></a>
          <input type="file" ng-hide="true" name="document-file" id="document_file" ng-file-select="onFileSelect($files)">
        </div>

        <div ng-show="serverSide.file.status == 200">
          <div class="alert alert-success">
            <?php print t('The document "{{ serverSide.file.data.data[0].label }}" was saved successfully.') ?>
          </div>
        </div>
      </div>

      <div class="errors">
        <ul ng-show="serverSide.data.errors.image">
          <li ng-repeat="error in serverSide.data.errors.image">{{error}}</li>
        </ul>
      </div>
      <p ng-show="errors.document" class="help-block"><?php print t('Document file is required.'); ?></p>
    </div>

    <div class="form-group text" ng-class="{ 'has-error' : entityForm.label.$invalid && !entityForm.label.$pristine }">
      <input id="label" class="form-control" ng-click="showFields()" name="label" type="text" ng-model="data.label" placeholder="<?php print t('Title'); ?>" ng-minlength=3 required>
      <p ng-show="entityForm.label.$invalid && !entityForm.label.$pristine" class="help-block"><?php print t('Title is too short.'); ?></p>
      <div class="errors">
        <ul ng-show="serverSide.data.errors.label">
          <li ng-repeat="error in serverSide.data.errors.label">{{error}}</li>
        </ul>
      </div>
    </div>

    <div ng-show="resources[selectedResource]">

      <div ng-show="selectedResource == 'discussions'" ng-class="{ 'has-error' : errors.discussion_type }">
        <label>{{fieldSchema.discussion_type.info.label}}</label>
        <types field="'discussion_type'" field-schema="fieldSchema" type="data.discussion_type" on-change="updateType"></types>
        <p ng-show="errors.discussion_type" class="help-block"><?php print t('Discussion type is required.'); ?></p>
      </div>

      <div ng-show="selectedResource == 'events'" ng-class="{ 'has-error' : errors.event_type }">
        <label>{{fieldSchema.event_type.info.label}}</label>
        <types field="'event_type'" field-schema="fieldSchema" type="data.event_type" on-change="updateType"></types>
        <p ng-show="errors.event_type" class="help-block"><?php print t('Event type is required.'); ?></p>
      </div>

      <div class="form-group" ng-class="{ 'has-error' : errors.body }">
        <div id="body" name="data-body" text-angular ta-toolbar="[['h1','h2'],['bold','italics', 'underline','ul','ol'],['justifyLeft', 'justifyCenter', 'justifyRight'],['insertImage', 'insertLink', 'insertVideo']]" text-angular-name="body" ng-model="data.body" data-placeholder="<?php print t('Add a description'); ?>"></div>
        <p ng-show="errors.body" class="help-block"><?php print t('Body is required.'); ?></p>
        <div class="errors">
          <ul ng-show="serverSide.data.errors.body">
            <li ng-repeat="error in serverSide.data.errors.body">{{error}}</li>
          </ul>
        </div>
      </div>

      <div class="form-group text" ng-show="selectedResource == 'events'" ng-class="{ 'has-error' : errors.organiser }">
        <label>{{fieldSchema.organiser.info.label}}</label>
        <input id="organiser" class="form-control" name="organiser" type="text" ng-model="data.organiser">
        <div class="errors">
          <ul ng-show="serverSide.data.errors.organiser">
            <li ng-repeat="error in serverSide.data.errors.organiser">{{error}}</li>
          </ul>
        </div>
      </div>

      <div class="form-group date" ng-show="selectedResource == 'events'" ng-class="{ 'has-error' : errors.datetime}">
        <label><?php print t('When') ?></label>
        <div class="row">
          <calendar></calendar>
        </div>
        <p class="errors" ng-show="errors.datetime"><?php print t('Date / time is not valid'); ?></p>
      </div>

      <div class="form-group btn-group" ng-show="selectedResource == 'documents'" ng-class="{ 'has-error' : errors.document_type }">
        <div class="label-wrapper">
          <label>{{fieldSchema.document_type.info.label}}</label>
          <span id="document_type_description" class="description">{{fieldSchema.document_type.info.description}}</span>
        </div>
        <div class="checkboxes-wrapper">
          <div>
            <button type="button" ng-click="togglePopover('document_type', $event)" class="btn btn-primary fa fa-plus">&nbsp;<?php print t('Select Type'); ?></button>
            <p ng-show="errors.document_type" class="help-block"><?php print t('Document type is required.'); ?></p>
          </div>
          <!-- Hidden document_type checkboxes.-->
          <div class="popover right hidden-checkboxes" ng-show="popups.document_type">
            <div class="arrow"></div>
            <div class="popover-content">
              <list-terms type="document_type" model="data.document_type" items="document_type"></list-terms>
            </div>
          </div>
        </div>
      </div>

      <div class="form-group btn-group" ng-class="{ 'has-error' : errors.topic }">
        <div class="label-wrapper">
          <label>{{fieldSchema.topic.info.label}}</label>
          <span id="topic_description" class="description">{{fieldSchema.topic.info.description}}</span>
        </div>
        <div class="checkboxes-wrapper">
          <div>
            <button type="button" ng-click="togglePopover('topic', $event)" class="btn btn-primary fa fa-plus">&nbsp;<?php print t('Select Topic'); ?></button>
            <p ng-show="errors.topic" class="help-block"><?php print t('Topic is required.'); ?></p>
          </div>
          <!-- Hidden topic checkboxes.-->
          <div class="popover right hidden-checkboxes" ng-show="popups.topic">
            <div class="arrow"></div>
            <div class="popover-content">
              <list-terms type="topic" model="data.topic" items="topic"></list-terms>
            </div>
          </div>
        </div>
      </div>

      <div class="form-group btn-group" ng-show="selectedResource != 'events'" ng-class="{ 'has-error' : errors.date }">
        <div class="label-wrapper">
          <label>{{fieldSchema.date.info.label}}</label>
          <span id="date_description" class="description">{{fieldSchema.date.info.description}}</span>
        </div>
        <div class="checkboxes-wrapper">
          <div>
            <button type="button" ng-click="togglePopover('date', $event)" class="btn btn-primary fa fa-plus">&nbsp;<?php print t('Select Date'); ?></button>
            <p ng-show="errors.date" class="help-block"><?php print t('Date is required.'); ?></p>
          </div>
          <!-- Hidden date checkboxes.-->
          <div class="popover right hidden-checkboxes" ng-show="popups.date">
            <div class="arrow"></div>
            <div class="popover-content">
              <list-terms type="date" model="data.date" items="date"></list-terms>
            </div>
          </div>
        </div>
      </div>

      <div class="form-group btn-group" ng-class="{ 'has-error' : errors.language }">
        <div class="label-wrapper">
          <label>{{fieldSchema.language.info.label}}</label>
          <span id="language_description" class="description">{{fieldSchema.language.info.description}}</span>
        </div>
        <div class="checkboxes-wrapper">
          <div>
            <button type="button" ng-click="togglePopover('language', $event)" class="btn btn-primary fa fa-plus">&nbsp;<?php print t('Select Language'); ?></button>
            <p ng-show="errors.language" class="help-block"><?php print t('Language is required.'); ?></p>
          </div>
          <!-- Hidden language checkboxes.-->
          <div class="popover right hidden-checkboxes" ng-show="popups.language">
            <div class="arrow"></div>
            <div class="popover-content">
              <list-terms type="language" model="data.language" items="language"></list-terms>
            </div>
          </div>
        </div>
      </div>

      <div class="form-group btn-group" ng-class="{ 'has-error' : errors.geo }">
        <div class="label-wrapper">
          <label>{{fieldSchema.geo.info.label}}</label>
          <span id="geo_description" class="description">{{fieldSchema.geo.info.description}}</span>
        </div>
        <div class="checkboxes-wrapper">
          <div>
            <button type="button" ng-click="togglePopover('geo', $event)" class="btn btn-primary fa fa-plus">&nbsp;<?php print t('Select Region'); ?></button>
            <p ng-show="errors.geo" class="help-block"><?php print t('Regions & Countries are required.'); ?></p>
          </div>
          <!-- Hidden geo checkboxes.-->
          <div class="popover right hidden-checkboxes" ng-show="popups.geo" >
            <div class="arrow"></div>
            <div class="popover-content">
              <list-terms type="geo" model="data.geo" items="geo"></list-terms>
            </div>
          </div>
        </div>
      </div>

      <div class="input-wrapper tags" ng-class="{ 'has-error' : errors.tags }">
        <label><?php print t('Tags') ?></label>
        <input multiple type="hidden" ui-select2="{query: tagsQuery, minimumInputLength: 2}" ng-model="data.tags" class="form-control"/>
        <p ng-show="errors.tags" class="help-block"><?php print t('Tags are required.'); ?></p>
      </div>

      <div class="actions">
        <button type="submit" id="quick-submit" class="btn btn-primary" tabindex="100"><?php print t('POST'); ?></button>
        <a href="javascript://" id="full-from-button" ng-click="submitForm(entityForm, data, selectedResource, 'full_form')"><?php print t('Create in full form'); ?></a>
        <a href="javascript://" id="clear-button" ng-click="this.form.reset()"><?php print t('Cancel'); ?></a>
      </div>
    </div>
  </form>

  <div ng-show="debug">
    <h2>Console (Server side)</h2>
    <div ng-show="serverSide.status == 200" class="create-success">
      <strong>
        New {{ resources[selectedResource].bundle }} created: <a ng-href="{{ serverSide.data.self }}" target="_blank">{{ serverSide.data.label }}</a> (node ID {{ serverSide.data.data[0].id }})
      </strong>
    </div>
    <div ng-show="serverSide.status">
      <div>
        Status: {{ serverSide.status }}
      </div>
      <div>
        Data: <pre pretty-json="serverSide.data" />
      </div>
    </div>
  </div>
  <br/>
  <div class="messages" ng-show="debug == 0">
    <div ng-show="serverSide.status == 200">
      <div class="alert alert-success">
        <?php print t('The {{ resources[selectedResource].bundle }} was saved successfully.') ?>
      </div>
    </div>
    <div ng-show="serverSide.status > 0 && serverSide.status != 200">
      <div class="alert alert-danger">
        <?php print t('Error saving {{ resources[selectedResource].bundle }}.') ?>
      </div>
    </div>
  </div>
</div>
