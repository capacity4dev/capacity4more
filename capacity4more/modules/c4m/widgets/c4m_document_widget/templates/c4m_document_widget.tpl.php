<div class="form-group input-wrapper file-wrapper" id="add-document-form">

  <div class="form-control drop-box" ng-file-drop="onFileSelect($files);"
       ng-file-drag-over-class="file-upload-drag">

    <div name="discussion-document-upload">
      <?php print t('Drop file here to upload or'); ?>
      <a href="javascript://" ng-click="browseFiles()"> <?php print t('Browse'); ?> </a>
      <input type="file" name="document-file" id="document_file" ng-file-select="onFileSelect($files)">
      <br/>
      <?php print t('or'); ?>
      <a href="<?php print url('overlay/documents', array('absolute' => TRUE, 'purl' => array('disabled' => FALSE))); ?>">
        <?php print t('Select a Document from the library') ?>
      </a>
    </div>
  </div>
  <related-documents related-documents="data.relatedDocuments" form-id="formId"></related-documents>

  <input type="text" id="related-documents" ng-hide="true" value="<?php print $default_value; ?>">
</div>
