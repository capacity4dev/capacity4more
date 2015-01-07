<div ng-controller="DocumentCtrl" id="documentFile">

  <form name="documentForm" action="overlay-file/<?php print $file_id; ?>?render=overlay" ng-submit="createDocument($event, '<?php print $file_id; ?>', data, addToLibrary, '<?php print $file_name; ?>')">

    <?php
      print t('Upload new document: ') . $file_name;
    ?>
    <br/>
    <?php
      print($file);
    ?>

    <br/>
    <p>Add this document also to the group Library?</p>
    <button type="submit" id="save-edit" ng-click="addToLibrary = true" class="btn btn-primary" tabindex="100"><?php print t('YES'); ?></button>
    <button type="submit" id="save" ng-click="addToLibrary = false" class="btn btn-primary" tabindex="100"><?php print t('NO'); ?></button>
    <a href="javascript://" id="clear-button" ng-click="closeOverlay()"><?php print t('Cancel'); ?></a>
  </form>
</div>
