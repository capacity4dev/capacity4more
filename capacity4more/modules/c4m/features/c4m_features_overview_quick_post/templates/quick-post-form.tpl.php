<div ng-app="c4mApp" ng-controller="MainCtrl">
  <div class="explanation">
    <em><?php t('Quick Post') ?></em>
  </div>

  <form name="entityForm" ng-submit="submitForm(entityForm, data, bundleName)">

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

    <bundle-select items="bundles" on-change="updateBundle" bundle-name="bundleName"></bundle-select>

    <div ng-show="bundles[bundleName]">
      <div class="form-group textarea" ng-class="{ 'has-error' : entityForm.body.$invalid && !entityForm.body.$pristine }">
        <label><?php print t('Description'); ?></label>
        <textarea id="body" class="form-control" name="body" type="textarea" ng-model="data.body" placeholder="<?php print t('Description'); ?>" cols="60" rows="3" ng-minlength=10 required></textarea>
        <p ng-show="entityForm.body.$invalid && !entityForm.body.$pristine" class="help-block"><?php print t('Description is too short.'); ?></p>
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
</div>
