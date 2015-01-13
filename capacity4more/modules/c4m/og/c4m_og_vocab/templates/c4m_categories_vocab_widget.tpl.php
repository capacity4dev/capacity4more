<div class="form-group btn-group <?php print $vocabulary_machine_name; ?>">
  <div class="checkboxes-wrapper">
    <div>
      <button name="<?php print $vocabulary_machine_name ?>" type="button" ng-click="togglePopover('<?php print $vocabulary_machine_name; ?>', $event)" class="btn btn-primary fa fa-plus">&nbsp;<?php print t('Select @name', array('@name' => $vocabulary_label)); ?></button>
    </div>
    <div class="selected-values" ng-show="data.<?php print $vocabulary_machine_name; ?>">
      <div class="value row" ng-show="value === true " ng-repeat="(key, value) in model.<?php print $vocabulary_machine_name; ?>">
        <div class="parent col-sm-6">
          <span>
            <i ng-click="removeTaxonomyValue(key, '<?php print $vocabulary_machine_name; ?>')" class="fa fa-times"></i> {{ findLabel(data.<?php print $vocabulary_machine_name; ?>, key) }}
            <i ng-show="data.<?php print $vocabulary_machine_name; ?>[key]" class="fa fa-chevron-right "></i>
          </span>
        </div>
        <div class="child col-sm-6">
          <span ng-show="model.<?php print $vocabulary_machine_name; ?>[child.id] === true" ng-repeat="(childkey, child) in data.<?php print $vocabulary_machine_name; ?>[key].children">
            <i ng-click="removeTaxonomyValue(child.id, '<?php print $vocabulary_machine_name; ?>')" class="fa fa-times"></i> {{ findLabel(data.<?php print $vocabulary_machine_name; ?>, child.id) }}
          </span>
        </div>
      </div>
    </div>
    <!-- Hidden checkboxes.-->
    <div class="popover right hidden-checkboxes" ng-hide="popups.<?php print $vocabulary_machine_name; ?> != 1">
      <div class="arrow"></div>
      <div class="popover-content">
        <form action="#" class="search">
          <input ng-model="searchTerms.<?php print $vocabulary_machine_name; ?>" ng-change="updateSearch('<?php print $vocabulary_machine_name; ?>')" class="form-control" type="text" placeholder="Search"/>
        </form>
        <ul>
          <li class="checkbox" ng-repeat="item in filteredTerms.<?php print $vocabulary_machine_name; ?>">
            <label ng-click="updateSelected(item, '<?php print $vocabulary_machine_name; ?>');">
              {{item.label}}
            </label>
            <ul ng-show="item.selected == true" class="indent">
              <li ng-repeat="child in item.children">
                <label>
                  <input type="checkbox" data-target="{{item.id}}" ng-name="type" ng-model="model.<?php print $vocabulary_machine_name; ?>[child.id]" ng-change="updateSelectedTerms(child.id, '<?php print $vocabulary_machine_name; ?>')"> {{child.label}}
                </label>
              </li>
            </ul>
          </li>
        </ul>
      </div>
    </div>
  </div>
</div>
