<div ng-controller="DocumentCtrl">

  <form name="documentForm" action="overlay-file/<?php print $file_id; ?>?render=overlay" ng-submit="createDocument($event, '<?php print $file_id; ?>', data, false)">

    <?php
      print('Upload new document: <br/>');
      print($file);
    ?>

    <br/>
    <input id="label" class="form-control" name="label" type="text" placeholder="<?php print t('Add document title'); ?>" ng-minlength=3 ng-model="data.label" required>
    <br/>
    <p>Add this document also to the group Library?</p>
    <input type="button" id="save-edit" class="btn btn-primary" ng-click="createDocument($event, '<?php print $file_id; ?>', data, true)" tabindex="100" value="<?php print t('YES'); ?>">
    <button type="submit" id="save" class="btn btn-primary" tabindex="100"><?php print t('NO'); ?></button>
    <a href="javascript://" id="clear-button" ng-click="closeOverlay()"><?php print t('Cancel'); ?></a>
  </form>
</div>
