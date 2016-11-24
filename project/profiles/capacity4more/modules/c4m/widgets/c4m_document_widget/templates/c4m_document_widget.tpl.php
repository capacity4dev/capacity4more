<?php

/**
 * @file
 * Template to render the document widget.
 */
?>
<div class="form-group input-wrapper file-wrapper"">
  <label for="<?php print $field_name; ?>" class="control-label" title="<?php print $title; ?>"><?php print $title; ?></label>
  <?php if ($required): ?>
    <span class="form-required" title="<?php print t('This field is required.'); ?>">*</span>
  <?php endif; ?>
    <div class="cfm-file-upload-wrapper">
      <div class="cfm-file-upload" ng-file-drop="onFileSelect($files, '<?php print $field_name; ?>');"
           ng-file-drag-over-class="file-upload-drag">
        <input type="file" name="document-file" id="<?php print $field_name; ?>" class="document_file" ng-file-select="onFileSelect($files, '<?php print $field_name; ?>')" title="Upload file">
        <i class="fa fa-hand-pointer-o cfm-file-upload__hand"></i>
        <p class="cfm-file-upload__title" title="<?php print t('Drop file here to upload documents'); ?>"><?php print t('Drop file here to upload documents'); ?></p>
        <a href="javascript://" ng-click="browseFiles('<?php print $field_name; ?>')" title="Browse"> <?php print t('or browse'); ?> </a>
      </div>
      <script>
        /**
         * Opens the file attachment form in overlay after choosing a file in
         * the media browser modal.
         *
         * @param media
         *   Data object of the file chosen in the media browser.
         */
        var c4m_attachment_overlay = function (media) {
          window.location = '#overlay=<?php print c4m_og_current_group_purl(); ?>/overlay-file/' + media[0].fid;
        };

        // Options to define which tabs to display in the media browser modal.
        var media_browser_options = {'enabledPlugins[media_default--media_browser_my_files]': 'media_default--media_browser_my_files'};
      </script>
      <a href="JavaScript://" onclick="Drupal.media.popups.mediaBrowser(c4m_attachment_overlay,media_browser_options)"
         ng-click="setFieldName('<?php print $field_name; ?>')" id="link-<?php print $field_name; ?>"
         ng-class="{'active-library-link':fieldName === '<?php print $field_name; ?>'}"
         title="<?php print t('Select a document from the library') ?>">
        <?php print t('or select a document from the library') ?>
      </a>
    </div>
  <related-documents related-documents="data.relatedDocuments['<?php print $field_name; ?>']" form-id="formId" field-name="'<?php print $field_name; ?>'"></related-documents>

  <input type="hidden" id="input-<?php print $field_name; ?>" class="hidden-input" value="<?php print $default_value; ?>">
</div>
