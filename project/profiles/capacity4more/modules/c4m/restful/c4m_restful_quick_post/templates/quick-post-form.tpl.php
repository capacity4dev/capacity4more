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

<div ng-if="selectedResource == 'discussions'" ng-class="{ 'has-error' : errors.discussion_type }">
  <types field="'discussion_type'" field-schema="referenceValues" type="data.discussion_type" on-change="updateType"
         cols="3"></types>
  <p ng-show="errors.discussion_type" class="help-block"><?php print t('Discussion type is required.'); ?></p>
</div>

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

<div class="form-group btn-group clearfix btn-group-selectors" ng-class="{ 'has-error' : errors.date }">
  <div class="label-wrapper">
    <label><?php print t('Group categories') ?></label>
    <span id="date_description" class="description">{{fieldSchema.resources[selectedResource].categories.info.description}}</span>
  </div>
  <div class="checkboxes-wrapper">
    <div class="popup-button">
      <button type="button" ng-click="togglePopover('categories', $event)"
              class="btn"><?php print t('Select Category'); ?></button>
      <p ng-show="errors.categories" class="help-block"><?php print t('Categories are required.'); ?></p>
    </div>

    <div class="selected-values" ng-show="data.categories">
      <div class="value row" ng-repeat="(key, value) in categories">
        <div class="parent col-sm-6">
          <span ng-show="termHasChildrenSelected('categories', key, 'null')">
            {{ findLabel(categories, key) }}
            <i class="fa fa-chevron-right " ng-show="termHasChildrenSelected('categories', key, 'null')"></i>
          </span>
        </div>
        <div class="child col-sm-6" ng-repeat="(childkey, child) in categories[key].children">
          <span ng-if="data.categories[child.id] === true" >
            <i ng-click="removeTaxonomyValue(child.id, 'categories')" class="fa fa-times"></i>
            {{ findLabel(categories, child.id) }}
          </span>
        </div>
      </div>
    </div>

    <!-- Hidden date checkboxes.-->
    <div class="popover right hidden-checkboxes" ng-show="popups.categories">
      <div class="arrow"></div>
      <div class="popover-content">
        <group-categories type="categories" model="data.categories" items="categories"></group-categories>
      </div>
    </div>
  </div>
</div>

<div class="form-group btn-group clearfix btn-group-selectors" ng-class="{ 'has-error' : errors.date }">
  <div class="label-wrapper">
    <label>{{fieldSchema.resources[selectedResource].date.info.label}}</label>
    <span id="date_description"
          class="description">{{fieldSchema.resources[selectedResource].date.info.description}}</span>
  </div>
  <div class="checkboxes-wrapper">
    <div class="checkboxes-wrapper">
      <div class="popup-button">
        <button type="button" id="date" ng-click="togglePopover('date', $event)"
                class="btn"><?php print t('Select Date'); ?></button>
        <p ng-show="errors.date" class="help-block"><?php print t('Date is required.'); ?></p>
      </div>
      <div class="selected-values" ng-show="data.date">
            <span ng-if="value === true" ng-repeat="(key, value) in data.date">
              {{ findLabel(date, key) }} <i ng-click="removeTaxonomyValue(key, 'date')" class="fa fa-times"></i>
            </span>
      </div>
      <!-- Hidden date checkboxes.-->
      <div class="popover right hidden-checkboxes" ng-show="popups.date">
        <div class="arrow"></div>
        <div class="popover-content">
          <list-terms update-popover-position="updatePopoverPosition" type="date" model="data.date"
                      items="date"></list-terms>
        </div>
      </div>
    </div>
  </div>
</div>

<div class="form-group btn-group clearfix btn-group-selectors" ng-class="{ 'has-error' : errors.language }">
  <div class="label-wrapper">
    <label>{{fieldSchema.resources[selectedResource].language.info.label}}</label>
    <span id="language_description" class="description">{{fieldSchema.resources[selectedResource].language.info.description}}</span>
  </div>
  <div class="checkboxes-wrapper">
    <div class="popup-button">
      <button type="button" ng-click="togglePopover('language', $event)"
              class="btn"><?php print t('Select Language'); ?></button>
      <p ng-show="errors.language" class="help-block"><?php print t('Language is required.'); ?></p>
    </div>
    <div class="selected-values" ng-show="data.language">
            <span ng-if="value === true" ng-repeat="(key, value) in data.language">
              {{ findLabel(language, key) }} <i ng-click="removeTaxonomyValue(key, 'language')" class="fa fa-times"></i>
            </span>
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

<div class="form-group btn-group clearfix btn-group-selectors" ng-class="{ 'has-error' : errors.geo }">
  <div class="label-wrapper">
    <label>{{fieldSchema.resources[selectedResource].geo.info.label}}</label>
    <span id="geo_description"
          class="description">{{fieldSchema.resources[selectedResource].geo.info.description}}</span>
  </div>
  <div class="checkboxes-wrapper">
    <div class="checkboxes-wrapper">
      <div class="popup-button">
        <button type="button" ng-click="togglePopover('geo', $event)"
                class="btn"><?php print t('Select Region'); ?></button>
        <p ng-show="errors.geo" class="help-block"><?php print t('Regions & Countries are required.'); ?></p>
      </div>
      <div class="selected-values geo-values" ng-show="data.geo">
        <div class="value row" ng-if="value === true && geo[key]" ng-repeat="(key, value) in data.geo">
          <div class="parent col-sm-4">
            <span>
              <i ng-click="removeTaxonomyValue(key, 'geo')" class="fa fa-times"></i> {{ findLabel(geo, key) }}
              <i class="fa fa-chevron-right " ng-show="termHasChildrenSelected('geo', key, 'null')"></i>
            </span>
          </div>
          <div class="col-sm-8">
            <div class="children row" ng-repeat="(childkey, child) in geo[key].children">
              <div class="col-sm-6" >
                <span ng-if="data.geo[child.id] === true" >
                  <i ng-click="removeTaxonomyValue(child.id, 'geo')" class="fa fa-times"></i> {{ findLabel(geo, child.id) }}
                  <i class="fa fa-chevron-right " ng-show="termHasChildrenSelected('geo', key, childkey)"></i>
                </span>
              </div>
              <div class="childChild col-sm-6">
                <span ng-if="data.geo[childChild.id] === true" ng-repeat="(childChildkey, childChild) in geo[key].children[childkey].children">
                  <i ng-click="removeTaxonomyValue(childChild.id, 'geo')" class="fa fa-times"></i> {{ findLabel(geo, childChild.id) }}
                </span>
              </div>
            </div>
          </div>
        </div>
      </div>
      <!-- Hidden geo checkboxes.-->
      <div class="popover right hidden-checkboxes" ng-show="popups.geo">
        <div class="arrow"></div>
        <div class="popover-content">
          <list-terms type="geo" popup="popups.geo" model="data.geo" items="geo"></list-terms>
        </div>
      </div>
    </div>
  </div>
</div>

<div class="input-wrapper tags" ng-class="{ 'has-error' : errors.tags }">
  <label><?php print t('Tags') ?></label>
  <input multiple type="hidden" ui-select2="{query: tagsQuery, minimumInputLength: 2}" ng-model="data.tags"
         class="form-control"/>

  <p ng-show="errors.tags" class="help-block"><?php print t('Tags are required.'); ?></p>
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
