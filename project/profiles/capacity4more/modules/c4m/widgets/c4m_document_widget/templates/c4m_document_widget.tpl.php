<?php
/**
 * @file
 * Template to render the document widget.
 */
?>
<div class="form-group input-wrapper file-wrapper" id="add-document-form">
  <label class="control-label"><?php print $title; ?></label>
  <?php if ($required): ?>
    <span class="form-required" title="<?php print t('This field is required.'); ?>">*</span>
  <?php endif; ?>
  <div class="form-control drop-box" ng-file-drop="onFileSelect($files, '<?php print $field_name; ?>');"
       ng-file-drag-over-class="file-upload-drag">

    <div name="discussion-document-upload" class="drop-text">
      <?php print t('Drop file here to upload or'); ?>
      <a href="javascript://" ng-click="browseFiles('<?php print $field_name; ?>')"> <?php print t('Browse'); ?> </a>
      <input type="file" name="document-file" id="<?php print $field_name; ?>" class="document_file" ng-file-select="onFileSelect($files, '<?php print $field_name; ?>')">
      <?php print t('or'); ?>
      <a href="<?php print url('overlay/documents', array('absolute' => TRUE, 'purl' => array('disabled' => FALSE))); ?>" ng-click="setFieldName('<?php print $field_name; ?>')" id="link-<?php print $field_name; ?>" ng-class="{'active-library-link':fieldName === '<?php print $field_name; ?>'}">
        <?php print t('Select a Document from the library') ?>
      </a>
    </div>
  </div>
  <related-documents related-documents="data.relatedDocuments['<?php print $field_name; ?>']" form-id="formId" field-name="'<?php print $field_name; ?>'"></related-documents>

  <input type="text" id="input-<?php print $field_name; ?>" class="hidden-input" value="<?php print $default_value; ?>">
</div>
