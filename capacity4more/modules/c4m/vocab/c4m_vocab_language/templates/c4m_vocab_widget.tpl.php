<div class="form-group btn-group <?php print($vocabulary_name); ?>">
  <div class="checkboxes-wrapper">
    <div>
      <button type="button" ng-click="togglePopover('<?php print($vocabulary_name); ?>', $event)" class="btn btn-primary fa fa-plus">&nbsp;<?php print(t('Select @name', array('@name' => str_replace("c4m_vocab_", "", $vocabulary_name)))); ?></button>
    </div>
    <!-- Hidden language checkboxes.-->
    <div class="popover right hidden-checkboxes" ng-hide="popups.<?php print($vocabulary_name); ?> != 1">
      <div class="arrow"></div>
      <div class="popover-content">
        <form action="#" class="search">
          <input ng-model="searchTerm" ng-change="updateSearch()" class="form-control" type="text" placeholder="Search"/>
        </form>
        <div class="checkbox" ng-repeat="item in data.<?php print($vocabulary_name); ?>">
          <label>
            <input type="checkbox" ng-name="type" title="{{item.label}}" ng-model="model[item.id]" ng-change="updateSelectedTerms(item.id)"> {{item.label}}
          </label>
        </div>
      </div>
    </div>
  </div>
</div>
