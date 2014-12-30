<div class="input-wrapper tags" ng-class="{ 'has-error' : errors.tags }">
  <label><?php print t('Tags') ?></label>
  <input multiple type="hidden" ui-select2="{query: tagsQuery, minimumInputLength: 2}" ng-model="data.tags" class="form-control"/>

  <p ng-show="errors.tags" class="help-block"><?php print t('Tags are required.'); ?></p>
</div>
