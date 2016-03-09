<?php

/**
 * @file
 * Template file for a wrapper theme function of the file upload element.
 *
 * @see dragndrop_upload_widget_pre_render()
 */
?>
<div class="droppable-standard-upload-hidden">
  <?php print render($element['#children']); ?>
</div>
