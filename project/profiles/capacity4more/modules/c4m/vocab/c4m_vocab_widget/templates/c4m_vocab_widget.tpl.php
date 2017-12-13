<?php

/**
 * @file
 * Template to render the Vocabulary widget.
 */
?>
<div class="c4m-vocab-description"
  ng-show="data.field_info.<?php print $vocabulary_machine_name ?>.description">
  {{data.field_info.<?php print $vocabulary_machine_name ?>.description}}
</div>
<div class="form-group <?php print $vocabulary_machine_name; ?>">
  <div class="checkboxes-wrapper">
    <div>
      <button name="<?php print $vocabulary_machine_name ?>" type="button"
              ng-click="togglePopover('<?php print $vocabulary_machine_name; ?>', $event)"
              class="btn btn-primary fa fa-plus"
              title="<?php print t('Select @name', array('@name' => $vocabulary_label)); ?>">&nbsp;<?php print t(
          'Select @name',
          array('@name' => $vocabulary_label)
        ); ?></button>
      <?php if ($required): ?>
        <span class="form-required"
              title="<?php print t('This field is required.'); ?>">*</span>
      <?php endif; ?>
    </div>
    <div class="selected-values"
         ng-show="data.<?php print $vocabulary_machine_name; ?>">
      <div class="value taxonomy-term-selected ng-hide"
           ng-show="value === true && data.<?php print $vocabulary_machine_name; ?>[key]"
           ng-repeat="(key, value) in model.<?php print $vocabulary_machine_name; ?>">
        <div class="level-1" >
          <span title="{{ findLabel(data.<?php print $vocabulary_machine_name; ?>, key) }}">
            <i
              ng-click="removeTaxonomyValue(key, '<?php print $vocabulary_machine_name; ?>')"
              class="fa fa-times remove-taxonomy" title="Remove"></i>
              {{ findLabel(data.<?php print $vocabulary_machine_name; ?>, key) }}
            </span>
        </div>
        <div
          ng-show="data.<?php print $vocabulary_machine_name; ?>[key].children.length > 0"
          class="level-2">
          <div
            ng-repeat="(childkey, child) in data.<?php print $vocabulary_machine_name; ?>[key].children">
            <div>
              <span
                ng-show="model.<?php print $vocabulary_machine_name; ?>[child.id] === true"
                title="{{ findLabel(data.<?php print $vocabulary_machine_name; ?>, child.id) }}">
                <i
                  ng-click="removeTaxonomyValue(child.id, '<?php print $vocabulary_machine_name; ?>')"
                  class="fa fa-times remove-taxonomy" title="Remove"></i>
                {{ findLabel(data.<?php print $vocabulary_machine_name; ?>, child.id) }}
                <i class="fa fa-chevron-right"
                   ng-show="termHasChildrenSelected('<?php print $vocabulary_machine_name; ?>', key, childkey)"></i>
              </span>
            </div>
            <div class="level-3">
              <div
                ng-show="model.<?php print $vocabulary_machine_name; ?>[childChild.id] === true"
                ng-repeat="(childChildkey, childChild) in data.<?php print $vocabulary_machine_name; ?>[key].children[childkey].children">
                <span title="{{ findLabel(data.<?php print $vocabulary_machine_name; ?>,childChild.id) }}">
                  <i
                    ng-click="removeTaxonomyValue(childChild.id, '<?php print $vocabulary_machine_name; ?>')"
                    class="fa fa-times remove-taxonomy" title="Remove"></i>
                    {{ findLabel(data.<?php print $vocabulary_machine_name; ?>, childChild.id) }}
                </span>
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
                 class="form-control" type="text" placeholder="Search" title="Search"/>
        </form>
        <ul>
          <li class="checkbox"
              ng-repeat="item in filteredTerms.<?php print $vocabulary_machine_name; ?> | orderObjectBy:'weight'">
            <label title="{{item.label}}">
              <input type="checkbox" data-target="{{item.id}}" ng-name="type" title="Check {{item.label}}"
                     ng-model="model.<?php print $vocabulary_machine_name; ?>[item.id]"
                     ng-change="updateSelectedTerms(item.id, '<?php print $vocabulary_machine_name; ?>')">
              {{item.label}}
            </label>
            <ul
              ng-show="item.children && model.<?php print $vocabulary_machine_name; ?>[item.id] == true"
              class="indent">
              <li ng-repeat="child in item.children | orderObjectBy:'weight'">
                <label title="{{child.label}}">
                  <input type="checkbox" data-target="{{item.id}}"  title="Check {{child.label}}"
                         ng-name="type"
                         ng-model="model.<?php print $vocabulary_machine_name; ?>[child.id]"
                         ng-change="updateSelectedTerms(child.id, '<?php print $vocabulary_machine_name; ?>')">
                  {{child.label}}
                </label>
                <ul
                  ng-show="child.children && model.<?php print $vocabulary_machine_name; ?>[child.id] == true"
                  class="indent">
                  <li ng-repeat="childChild in child.children | orderObjectBy:'weight'">
                    <label title="{{childChild.label}}">
                      <input type="checkbox" ng-name="type" title="Check {{childChild.label}}"
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
