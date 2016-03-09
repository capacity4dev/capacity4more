<?php

/**
 * @file
 * Template file for a droppable area of 'dragndrop_upload_widget' widget.
 */
?>
<div class="droppable" id="<?php print $element['#dnd_id']; ?>">
  <div class="droppable-preview">
    <div class="droppable-preview-file">
      <div class="preview-remove">x</div>
      <div>
        <span class="preview-filename"></span>
        <span class="preview-filesize"></span>
      </div>
    </div>
  </div>
  <div class="droppable-message">
    <span><?php print render($element['#text']); ?></span>

    <?php if ($element['#standard_upload']): ?>
    <div class="droppable-standard-upload">
      <span><?php print t('or'); ?></span>
      <a href="#" class="droppable-browse-button button">
        <?php print t('Browse'); ?>
      </a>
    </div>
    <?php endif ?>
  </div>
</div>
<div class="droppable-controls">
  <?php print render($element['remove_button']); ?>
  <?php print render($element['upload_button']); ?>
</div>
