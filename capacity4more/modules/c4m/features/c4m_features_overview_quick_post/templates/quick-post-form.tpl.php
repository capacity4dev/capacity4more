<div ng-app="c4mApp" ng-controller="MainCtrl">
  <div class="explanation">
    <em><?php print t('Quick Post') ?></em>
  </div>

  <form name="entityForm" ng-submit="submitForm(entityForm, data, bundle_name)">

    <bundle-select items="bundles" on-change="updateBundle" bundle-name="bundle_name"></bundle-select>

    <div class="form-group text" ng-class="{ 'has-error' : entityForm.label.$invalid && !entityForm.label.$pristine }">
      <label><?php print t('Title'); ?></label>
      <input id="label" class="form-control" name="label" type="text" ng-model="data.label" placeholder="<?php print t('Title'); ?>" required ng-minlength=3>
      <p ng-show="entityForm.label.$invalid && !entityForm.label.$pristine" class="help-block"><?php print t('Label is too short.'); ?></p>

      <div class="errors">
        <ul ng-show="serverSide.data.errors.label">
          <li ng-repeat="error in serverSide.data.errors.label">{{error}}</li>
        </ul>
      </div>
    </div>


    <div ng-show="bundles[bundle_name]" on-change="updateDiscussionType">

      <discussion-types field-schema="field_schema" discussion-type="data.discussion_type" on-change="updateDiscussionType"></discussion-types>

      <div class="form-group" ng-class="{ 'has-error' : entityForm.body.$invalid && !entityForm.body.$pristine }">
        <label><?php print t('Description'); ?></label>
        <div id="body" text-angular ta-toolbar="[['h1','h2'],['bold','italics', 'underline','ul','ol'],['justifyLeft', 'justifyCenter', 'justifyRight'],['insertImage', 'insertLink', 'insertVideo']]" text-angular-name="body" ng-model="data.body"></div>
        <div class="errors">
          <ul ng-show="serverSide.data.errors.body">
            <li ng-repeat="error in serverSide.data.errors.body">{{error}}</li>
          </ul>
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
