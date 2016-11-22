<?php

/**
 * @file
 * Template for the Categories vocabulary widget.
 */
?>
<div class="form-group btn-group <?php print $vocabulary_machine_name; ?> c4m-categories-vocab-widget">
  <div class="checkboxes-wrapper">
    <div>
      <button name="<?php print $vocabulary_machine_name ?>" type="button"
              ng-click="togglePopover('<?php print $vocabulary_machine_name; ?>', $event)"
              class="btn btn-primary fa fa-plus"
              title="<?php print t('Select @name', array('@name' => $vocabulary_label)); ?>">&nbsp;<?php print t(
              'Select @name', array('@name' => $vocabulary_label)); ?></button>
      <?php if ($required): ?>
        <label class="control-label">
          <span class="form-required"
                title="<?php print t('This field is required.'); ?>">*</span>
        </label>
      <?php endif; ?>
    </div>
    <div class="selected-values"
         ng-show="model.<?php print $vocabulary_machine_name; ?>">
      <div class="value taxonomy-term-selected"
           ng-repeat="(key, value) in data.<?php print $vocabulary_machine_name; ?>">
        <div class="level-1"
             ng-show="termHasChildrenSelected('<?php print $vocabulary_machine_name; ?>',key,'null')">
          <span title="{{ findLabel(data.<?php print $vocabulary_machine_name; ?>, key) }}">
            {{ findLabel(data.<?php print $vocabulary_machine_name; ?>, key) }}
          </span>
        </div>
        <div class="level-2">
          <div
            ng-show="model.<?php print $vocabulary_machine_name; ?>[child.id] === true"
            ng-repeat="(childkey, child) in data.<?php print $vocabulary_machine_name; ?>[key].children">
            <span title="{{ findLabel(data.<?php print $vocabulary_machine_name; ?>, child.id) }}">
              <i
                ng-click="removeTaxonomyValue(child.id, '<?php print $vocabulary_machine_name; ?>')"
                class="fa fa-times remove-taxonomy" title="Remove"></i>
              {{ findLabel(data.<?php print $vocabulary_machine_name; ?>, child.id) }}
            </span>
          </div>
        </div>
      </div>
    </div>
    <!-- Hidden checkboxes.-->
    <div class="popover right hidden-checkboxes"
         ng-hide="popups.<?php print $vocabulary_machine_name; ?> != 1">
      <div class="arrow"></div>
      <div class="popover-content">
        <div ng-if="!categoriesLength">
          <span title="<?php print t('No categories have been defined yet.') ?>">
            <?php print t('No categories have been defined yet.') ?>
          </span>
        </div>
        <form action="#" class="search" ng-show="categoriesLength">
          <input ng-model="searchTerms.<?php print $vocabulary_machine_name; ?>"
                 ng-change="updateSearch('<?php print $vocabulary_machine_name; ?>')"
                 class="form-control" type="text" placeholder="Search" title="Search"/>
        </form>
        <ul ng-if="categoriesLength">
          <li class="checkbox table-display"
              ng-repeat="item in filteredTerms.<?php print $vocabulary_machine_name; ?>">
            <label ng-show="{{item.children.length}}"
                   ng-click="updateSelected(item);"
                   class="parent-select" title="{{item.label}}"
                   title="{{item.label}}">
              <i class="fa fa-angle-down" ng-show="item.selected"></i>
              <i class="fa fa-angle-right" ng-show="!item.selected"></i>
              {{item.label}}
            </label>
            <ul ng-show="item.selected == true" class="indent">
              <li ng-repeat="child in item.children">
                <label title="{{child.label}}">
                  <input type="checkbox" data-target="{{item.id}}"
                         ng-name="type"
                         ng-model="model.<?php print $vocabulary_machine_name; ?>[child.id]"
                         ng-change="updateSelectedTerms(child.id, '<?php print $vocabulary_machine_name; ?>')"
                         title="Check">
                  {{child.label}}
                </label>
              </li>
            </ul>
          </li>
        </ul>
      </div>
    </div>
  </div>
</div>
