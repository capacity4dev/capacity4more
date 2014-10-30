<div ng-app="c4mApp" ng-controller="MainCtrl">
  <div class="explanation">
    <em><?php print t('Quick Post') ?></em>
  </div>

  <form name="entityForm" ng-submit="submitForm(entityForm, data, bundle_name, 'submit')">

    <bundle-select items="bundles" on-change="updateBundle" bundle-name="bundle_name"></bundle-select>

    <div class="form-group text" ng-class="{ 'has-error' : entityForm.label.$invalid && !entityForm.label.$pristine }">
      <input id="label" class="form-control" name="label" type="text" ng-model="data.label" placeholder="<?php print t('Title'); ?>" required ng-minlength=3>
      <p ng-show="entityForm.label.$invalid && !entityForm.label.$pristine" class="help-block"><?php print t('Label is too short.'); ?></p>

      <div class="errors">
        <ul ng-show="serverSide.data.errors.label">
          <li ng-repeat="error in serverSide.data.errors.label">{{error}}</li>
        </ul>
      </div>
    </div>


    <div ng-show="bundles[bundle_name]" on-change="updateDiscussionType">

      <discussion-types ng-show="bundle_name == 'discussions'" field-schema="field_schema" discussion-type="data.discussion_type" on-change="updateDiscussionType"></discussion-types>

      <div class="form-group" ng-class="{ 'has-error' : entityForm.body.$invalid && !entityForm.body.$pristine }">
        <div id="body" text-angular ta-toolbar="[['h1','h2'],['bold','italics', 'underline','ul','ol'],['justifyLeft', 'justifyCenter', 'justifyRight'],['insertImage', 'insertLink', 'insertVideo']]" text-angular-name="body" ng-model="data.body" data-placeholder="<?php print t('Add a description'); ?>"></div>
        <div class="errors">
          <ul ng-show="serverSide.data.errors.body">
            <li ng-repeat="error in serverSide.data.errors.body">{{error}}</li>
          </ul>
        </div>
      </div>

      <div class="form-group btn-group">
        <div class="label-wrapper">
          <label>{{field_schema.topic.info.label}}</label>
          <span class="description">{{field_schema.topic.info.description}}</span>
        </div>
        <div class="checkboxes-wrapper">
          <div>
            <button type="button" ng-click="togglePopover('topic', $event)" class="btn btn-primary"><i class="fa fa-plus"></i> <?php print t('Select Topic'); ?></button>
          </div>

          <!-- Hidden topic checkboxes.-->
          <div class="popover right hidden-checkboxes" ng-show="popups.topic">
            <div class="arrow"></div>
            <div class="popover-content">
              <list-terms type="topic" model="data.topic" items="reference_values.topic"></list-terms>
            </div>
          </div>
        </div>
      </div>

      <div class="form-group btn-group">
        <div class="label-wrapper">
          <label>{{field_schema.c4m_vocab_date.info.label}}</label>
          <span class="description">{{field_schema.c4m_vocab_date.info.description}}</span>
        </div>
        <div class="checkboxes-wrapper">
          <div>
            <button type="button" ng-click="togglePopover('c4m_vocab_date', $event)" class="btn btn-primary"><i class="fa fa-plus"></i> <?php print t('Select Date'); ?></button>
          </div>

          <!-- Hidden topic checkboxes.-->
          <div class="popover right hidden-checkboxes" ng-show="popups.c4m_vocab_date">
            <div class="arrow"></div>
            <div class="popover-content">
              <list-terms type="date" model="data.c4m_vocab_date" items="reference_values.c4m_vocab_date"></list-terms>
            </div>
          </div>
        </div>
      </div>

      <div class="form-group btn-group">
        <div class="label-wrapper">
          <label>{{field_schema.c4m_vocab_language.info.label}}</label>
          <span class="description">{{field_schema.c4m_vocab_language.info.description}}</span>
        </div>
        <div class="checkboxes-wrapper">
          <div>
            <button type="button" ng-click="togglePopover('c4m_vocab_language', $event)" class="btn btn-primary"><i class="fa fa-plus"></i> <?php print t('Select Language'); ?></button>
          </div>

          <!-- Hidden topic checkboxes.-->
          <div class="popover right hidden-checkboxes" ng-show="popups.c4m_vocab_language">
            <div class="arrow"></div>
            <div class="popover-content">
              <list-terms type="language" model="data.c4m_vocab_language" items="reference_values.c4m_vocab_language"></list-terms>
            </div>
          </div>
        </div>
      </div>

      <div class="form-group btn-group">
        <div class="label-wrapper">
          <label>{{field_schema.c4m_vocab_geo.info.label}}</label>
          <span class="description">{{field_schema.c4m_vocab_geo.info.description}}</span>
        </div>
        <div class="checkboxes-wrapper">
          <div>
            <button type="button" ng-click="togglePopover('c4m_vocab_geo', $event)" class="btn btn-primary"><i class="fa fa-plus"></i> <?php print t('Select Region'); ?></button>
          </div>

          <!-- Hidden geo checkboxes.-->
          <div class="popover right hidden-checkboxes" ng-show="popups.c4m_vocab_geo">
            <div class="arrow"></div>
            <div class="popover-content">
              <list-terms type="geo" model="data.c4m_vocab_geo" items="reference_values.c4m_vocab_geo"></list-terms>
            </div>
          </div>
        </div>
      </div>

      <div class="input-wrapper tags">
        <label><?php print t('Tags') ?></label>
        <input multiple type="hidden" ui-select2="{query: tagsQuery, minimumInputLength: 2}" ng-model="data.tags" class="form-control"/>
      </div>

      <div class="actions">
        <button type="submit" class="btn btn-primary" tabindex="100"><?php print t('POST'); ?></button>
        <a href="javascript://" id="full-from-button" ng-click="submitForm(entityForm, data, bundle_name, 'full_form')"><?php print t('Create in full form'); ?></a>
        <a href="javascript://" id="clear-button" ng-click="this.form.reset()"><?php print t('Cancel'); ?></a>
      </div>
    </div>
  </form>

  <div ng-show="debug">
    <h2>Console (Server side)</h2>
    <div ng-show="serverSide.status == 200" class="create-success">
      <strong>
        New {{ bundle_name }} created: <a ng-href="{{ serverSide.data.self }}" target="_blank">{{ serverSide.data.label }}</a> (node ID {{ serverSide.data.data[0].id }})
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
        <?php print t('The {{ bundles[bundle_name] }} was saved successfully.') ?>
      </div>
    </div>
    <div ng-show="serverSide.status > 0 && serverSide.status != 200">
      <div class="alert alert-danger">
        <?php print t('Error saving {{ bundles[bundle_name] }}.') ?>
      </div>
    </div>
  </div>
</div>
