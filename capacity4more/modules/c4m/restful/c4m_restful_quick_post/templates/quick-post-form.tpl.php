<form name="entityForm" ng-submit="submitForm(data, selectedResource, 'quick_post')">

<div class="form-group text" ng-class="{ 'has-error' : entityForm.label.$invalid && !entityForm.label.$pristine }">
  <input id="label" class="form-control" name="label" ng-click="showFields()" type="text" ng-model="data.label"
         placeholder="<?php print t('Title'); ?>" ng-minlength=3 required>

  <p ng-show="entityForm.label.$invalid && !entityForm.label.$pristine"
     class="help-block"><?php print t('Title is too short.'); ?></p>

  <div class="errors">
    <ul ng-show="serverSide.data.errors.label">
      <li ng-repeat="error in serverSide.data.errors.label">{{error}}</li>
    </ul>
  </div>
</div>

<?php if (count($show_resources) > 1): ?>
  <bundle-select items="resources" on-change="updateResource" selected-resource="selectedResource"></bundle-select>
<?php endif; ?>

<div class="form-group input-wrapper file-wrapper" ng-if="selectedResource == 'documents'"
     ng-class="{ 'has-error' : errors.document }">
  <div class="form-control drop-box" ng-file-drop="onFileSelect($files);"
       ng-file-drag-over-class="file-upload-drag">

    <div ng-hide="serverSide.file" class="drop-text">
      <span class="uppercase"><?php print t('Drop file here to upload'); ?></span><br/>
      <?php print t('or');?> <a href="javascript://" ng-click="browseFiles()"><?php print t('Browse') ?></a>
      <input type="file" name="document-file" id="document_file" class="hidden-input" ng-file-select="onFileSelect($files)">
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

<div ng-show="resources[selectedResource]" id="quick-post-fields">

<div ng-if="selectedResource == 'discussions'" ng-class="{ 'has-error' : errors.discussion_type }">
  <types field="'discussion_type'" field-schema="referenceValues" type="data.discussion_type" on-change="updateType"
         cols="3"></types>
  <p ng-show="errors.discussion_type" class="help-block"><?php print t('Discussion type is required.'); ?></p>
</div>

<div ng-if="selectedResource == 'events'" ng-class="{ 'has-error' : errors.event_type }">
  <types field="'event_type'" field-schema="referenceValues" type="data.event_type" on-change="updateType"
         cols="4"></types>
  <p ng-show="errors.event_type" class="help-block"><?php print t('Event type is required.'); ?></p>
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

<div class="form-group text btn-group-selectors" ng-if="selectedResource == 'events'" ng-class="{ 'has-error' : errors.organiser }">
  <label>{{fieldSchema.resources[selectedResource].organiser.info.label}}</label>
  <input id="organiser" class="form-control" name="organiser" type="text" ng-model="data.organiser">

  <div class="errors">
    <ul ng-show="serverSide.data.errors.organiser">
      <li ng-repeat="error in serverSide.data.errors.organiser">{{error}}</li>
    </ul>
  </div>
</div>

<div class="form-group date btn-group-selectors" ng-if="selectedResource == 'events'" ng-class="{ 'has-error' : errors.datetime}">
  <label><?php print t('When') ?></label>

  <div class="row">
    <calendar></calendar>
  </div>
  <p class="errors" ng-show="errors.datetime"><?php print t('Date / time is not valid'); ?></p>
</div>

<div class="form-group btn-group btn-group-selectors" ng-if="selectedResource == 'documents'"
     ng-class="{ 'has-error' : errors.document_type }">
  <div class="label-wrapper">
    <label>{{fieldSchema.resources[selectedResource].document_type.info.label}}</label>
    <span id="document_type_description" class="description">{{fieldSchema.resources[selectedResource].document_type.info.description}}</span>
  </div>
  <div class="checkboxes-wrapper">
    <div class="popup-button">
      <button type="button" ng-click="togglePopover('document_type', $event)" class="btn">
        &nbsp;<?php print t('Select Type'); ?></button>
      <p ng-show="errors.document_type" class="help-block"><?php print t('Document type is required.'); ?></p>
    </div>
    <div class="selected-values" ng-show="data.document_type">
          <span ng-show="value === true" ng-repeat="(key, value) in data.document_type">
            {{ findLabel(document_type, key) }} <i ng-click="removeTaxonomyValue(key, 'document_type')"
                                                   class="fa fa-times"></i>
          </span>
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

<div class="form-group btn-group btn-group-selectors" ng-class="{ 'has-error' : errors.topic }">
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
            <span ng-show="value === true" ng-repeat="(key, value) in data.topic">
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

<div class="form-group place btn-group-selectors" ng-show="selectedResource == 'events'" ng-class="{ 'has-error' : errors.location}">
  <label><?php print t('Where') ?></label>

  <div class="row">
    <location data="data"></location>
  </div>
  <p class="errors" ng-show="errors.location"><?php print t('Location is not valid'); ?></p>
</div>

<div class="form-group btn-group btn-group-selectors" ng-class="{ 'has-error' : errors.date }">
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
            <span ng-show="value === true" ng-repeat="(key, value) in data.categories">
              {{ findLabel(categories, key) }} <i ng-click="removeTaxonomyValue(key, 'categories')"
                                                  class="fa fa-times"></i>
            </span>
    </div>
    <!-- Hidden date checkboxes.-->
    <div class="popover right hidden-checkboxes" ng-show="popups.categories">
      <div class="arrow"></div>
      <div class="popover-content">
        <list-terms type="categories" model="data.categories" items="categories"></list-terms>
      </div>
    </div>
  </div>
</div>

<div class="form-group btn-group btn-group-selectors" ng-if="selectedResource != 'events'"
     ng-class="{ 'has-error' : errors.date }">
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
            <span ng-show="value === true" ng-repeat="(key, value) in data.date">
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

<div class="form-group btn-group btn-group-selectors" ng-class="{ 'has-error' : errors.language }">
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
            <span ng-show="value === true" ng-repeat="(key, value) in data.language">
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

<div class="form-group btn-group btn-group-selectors" ng-class="{ 'has-error' : errors.geo }">
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
      <div class="selected-values" ng-show="data.geo">
        <div class="value" ng-show="value === true && geo[key]" ng-repeat="(key, value) in data.geo">
          <div class="parent col-sm-6">
                <span>
                  <i ng-click="removeTaxonomyValue(key, 'geo')" class="fa fa-times"></i> {{ findLabel(geo, key) }}
                  <i ng-show="geo[key]" class="fa fa-chevron-right "></i>
                </span>
          </div>
          <div class="child col-sm-6">
                <span ng-show="data.geo[child.id] === true" ng-repeat="(childkey, child) in geo[key].children">
                  <i ng-click="removeTaxonomyValue(child.id, 'geo')" class="fa fa-times"></i> {{ findLabel(geo, child.id) }}
                </span>
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

<!-- Debug -->
<div ng-show="debug">
  <h2>Console (Server side)</h2>

  <div ng-show="serverSide.status == 200 || serverSide.status == 201" class="create-success">
    <strong>
      New {{ resources[selectedResource].bundle }} created: <a ng-href="{{ serverSide.data.self }}" target="_blank">{{
        serverSide.data.label }}</a> (node ID {{ serverSide.data.data[0].id }})
    </strong>
  </div>
  <div ng-show="serverSide.status">
    <div>
      Status: {{ serverSide.status }}
    </div>
    <div>
      Data:
      <pre pretty-json="serverSide.data"/>
    </div>
  </div>
</div>
<!-- End debug -->
