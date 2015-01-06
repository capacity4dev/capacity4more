<div class="form-group input-wrapper file-wrapper" id="add-document-form">

  <div class="form-control drop-box" ng-file-drop="onFileSelect($files, '<?php print $field_name; ?>');"
       ng-file-drag-over-class="file-upload-drag">

    <div name="discussion-document-upload">
      <?php print t('Drop file here to upload or'); ?>
      <a href="javascript://" ng-click="browseFiles('<?php print $field_name; ?>')"> <?php print t('Browse'); ?> </a>
      <input type="file" name="document-file" id="<?php print $field_name; ?>" class="document_file" ng-file-select="onFileSelect($files, '<?php print $field_name; ?>')">
      <br/>
      <?php print t('or'); ?>
      <a href="<?php print url('overlay/documents', array('absolute' => TRUE, 'purl' => array('disabled' => FALSE))); ?>" ng-click="setFieldName('<?php print $field_name; ?>')" id="link-<?php print $field_name; ?>" ng-class="{'active-library-link':fieldName === '<?php print $field_name; ?>'}">
        <?php print t('Select a Document from the library') ?>
      </a>
    </div>
  </div>
  <related-documents related-documents="data.relatedDocuments['<?php print $field_name; ?>']" form-id="formId" field-name="'<?php print $field_name; ?>'"></related-documents>

  <input type="text" id="input-<?php print $field_name; ?>" ng-hide="true" value="<?php print $default_value; ?>">
</div>
