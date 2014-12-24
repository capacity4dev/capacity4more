<form name="documentForm" ng-submit="createDocument('<?php print($file_id); ?>', label)">

  <?php
    print('Upload new document: <br/>');
    print($file);
  ?>

  <br/>
  <input id="label" class="form-control" name="label" type="text" placeholder="<?php print t('Add document title'); ?>" ng-minlength=3 ng-model="label">

  <p>Add this document also to the group Library?</p>
  <button type="submit" id="save-edit" class="btn btn-primary" tabindex="100"><?php print t('YES'); ?></button>
<!--  <button type="submit" id="save" class="btn btn-primary" tabindex="100">--><?php //print t('NO'); ?><!--</button>-->
  <a href="javascript://" id="clear-button" ng-click="cancel()"><?php print t('Cancel'); ?></a>
</form>
