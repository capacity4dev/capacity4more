<div ng-app="c4mApp" ng-controller="MainCtrl">
  <div class="explanation">
    <em><?php print t('Quick Post') ?></em>
  </div>

  <form name="entityForm" ng-submit="submitForm(entityForm, data, bundle_name)">

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
              <div class="checkbox" ng-repeat="topic in reference_values.topic">
                <label>
                  <input type="checkbox" name="topic" ng-model="data.topic[topic.id]"> {{topic.label}}
                </label>
              </div>
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
              <div class="checkbox" ng-repeat="date in reference_values.c4m_vocab_date">
                <label>
                  <input type="checkbox" name="date" ng-model="data.c4m_vocab_date[date.id]"> {{date.label}}
                </label>
              </div>
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
              <div class="checkbox" ng-repeat="language in reference_values.c4m_vocab_language">
                <label>
                  <input type="checkbox" name="language" ng-model="data.c4m_vocab_language[language.id]"> {{language.label}}
                </label>
              </div>
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
              <div class="checkbox" ng-repeat="geo in reference_values.c4m_vocab_geo">
                <label>
                  <input type="checkbox" name="geo" ng-model="data.c4m_vocab_geo[geo.id]"> {{geo.label}}
                </label>
              </div>
            </div>
          </div>
        </div>
      </div>

      <div class="actions">
        <button type="submit" class="btn btn-primary" tabindex="100"><?php print t('POST'); ?></button>
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
