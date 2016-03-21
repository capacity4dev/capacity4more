<?php
/**
 * @file
 * Template for the Vocabulary widget.
 */
?>
<div class="input-wrapper tags" ng-class="{ 'has-error' : errors.tags }">
  <label class="control-label"><?php print t('Tags') ?></label>
  <?php if ($required): ?>
    <span class="form-required" title="<?php print t('This field is required.'); ?>">*</span>
  <?php endif; ?>
  <input multiple type="hidden" ui-select2="{query: tagsQuery, minimumInputLength: 2}" ng-model="data.tags" class="form-control"/>

  <p ng-if="selectedTags">{{selectedTags}}</p>
  <p ng-if="errors.tags" class="help-block"><?php print t('Tags are required.'); ?></p>
</div>
