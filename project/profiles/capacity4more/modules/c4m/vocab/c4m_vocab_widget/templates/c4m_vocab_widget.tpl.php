<?php
/**
 * @file
 * Template to render the Vocabulary widget.
 */
?>
<div
  ng-show="data.field_info.<?php print $vocabulary_machine_name ?>.description">
  {{data.field_info.<?php print $vocabulary_machine_name ?>.description}}
</div>
<div class="form-group <?php print $vocabulary_machine_name; ?>">
  <div class="checkboxes-wrapper">
    <div>
      <button name="<?php print $vocabulary_machine_name ?>" type="button"
              ng-click="togglePopover('<?php print $vocabulary_machine_name; ?>', $event)"
              class="btn btn-primary fa fa-plus">&nbsp;<?php print t(
          'Select @name',
          array('@name' => $vocabulary_label)
        ); ?></button>
      <?php if ($required): ?>
        <label class="control-label">
          <span class="form-required"
                title="<?php print t('This field is required.'); ?>">*</span>
        </label>
      <?php endif; ?>
    </div>
    <div class="selected-values"
         ng-show="data.<?php print $vocabulary_machine_name; ?>">
      <div class="value taxonomy-term-selected"
           ng-show="value === true && data.<?php print $vocabulary_machine_name; ?>[key]"
           ng-repeat="(key, value) in model.<?php print $vocabulary_machine_name; ?>">
        <div class="level-1">
          <i
            ng-click="removeTaxonomyValue(key, '<?php print $vocabulary_machine_name; ?>')"
            class="fa fa-times remove-taxonomy"></i> {{
          findLabel(data.<?php print $vocabulary_machine_name; ?>, key) }}
        </div>
        <div
          ng-show="data.<?php print $vocabulary_machine_name; ?>[key].children.length > 0"
          class="level-2">
          <div
            ng-repeat="(childkey, child) in data.<?php print $vocabulary_machine_name; ?>[key].children">
            <div>
              <span
                ng-show="model.<?php print $vocabulary_machine_name; ?>[child.id] === true">
                <i
                  ng-click="removeTaxonomyValue(child.id, '<?php print $vocabulary_machine_name; ?>')"
                  class="fa fa-times remove-taxonomy"></i>
                {{ findLabel(data.<?php print $vocabulary_machine_name; ?>, child.id) }}
                <i class="fa fa-chevron-right"
                   ng-show="termHasChildrenSelected('<?php print $vocabulary_machine_name; ?>', key, childkey)"></i>
              </span>
            </div>
            <div class="level-3">
              <div
                ng-show="model.<?php print $vocabulary_machine_name; ?>[childChild.id] === true"
                ng-repeat="(childChildkey, childChild) in data.<?php print $vocabulary_machine_name; ?>[key].children[childkey].children">
                <i
                  ng-click="removeTaxonomyValue(childChild.id, '<?php print $vocabulary_machine_name; ?>')"
                  class="fa fa-times remove-taxonomy"></i>
                {{ findLabel(data.<?php print $vocabulary_machine_name; ?>,
                childChild.id) }}

              </div>
            </div>
          </div>
        </div>
      </div>

    </div>
    <!-- Hidden checkboxes.-->
    <div class="popover right hidden-checkboxes"
         ng-hide="popups.<?php print $vocabulary_machine_name; ?> != 1">
      <div class="arrow"></div>
      <div class="popover-content">
        <form action="#" class="search">
          <input ng-model="searchTerms.<?php print $vocabulary_machine_name; ?>"
                 ng-change="updateSearch('<?php print $vocabulary_machine_name; ?>')"
                 class="form-control" type="text" placeholder="Search"/>
        </form>
        <ul>
          <li class="checkbox"
              ng-repeat="item in filteredTerms.<?php print $vocabulary_machine_name; ?>">
            <label>
              <input type="checkbox" data-target="{{item.id}}" ng-name="type"
                     title="{{item.label}}"
                     ng-model="model.<?php print $vocabulary_machine_name; ?>[item.id]"
                     ng-change="updateSelectedTerms(item.id, '<?php print $vocabulary_machine_name; ?>')">
              {{item.label}}
            </label>
            <ul
              ng-show="item.children && model.<?php print $vocabulary_machine_name; ?>[item.id] == true"
              class="indent">
              <li ng-repeat="child in item.children">
                <label>
                  <input type="checkbox" data-target="{{item.id}}"
                         ng-name="type"
                         ng-model="model.<?php print $vocabulary_machine_name; ?>[child.id]"
                         ng-change="updateSelectedTerms(child.id, '<?php print $vocabulary_machine_name; ?>')">
                  {{child.label}}
                </label>
                <ul
                  ng-show="child.children && model.<?php print $vocabulary_machine_name; ?>[child.id] == true"
                  class="indent">
                  <li ng-repeat="childChild in child.children">
                    <label>
                      <input type="checkbox" ng-name="type"
                             ng-model="model.<?php print $vocabulary_machine_name; ?>[childChild.id]"
                             ng-change="updateSelectedTerms(childChild.id, '<?php print $vocabulary_machine_name; ?>')">
                      {{childChild.label}}
                    </label>
                  </li>
                </ul>
              </li>
            </ul>
          </li>
        </ul>
      </div>
    </div>
  </div>
</div>
