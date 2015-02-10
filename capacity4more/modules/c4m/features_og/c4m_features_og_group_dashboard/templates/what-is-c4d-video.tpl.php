<div class="button-wrapper">
  <button type="button" class="btn btn-primary btn-lg" data-toggle="modal" data-target="#c4dVideoModal">
    <?php print t('Watch what is capacity4dev') ?>
  </button>
</div>
<div class="modal fade" id="c4dVideoModal" tabindex="-1" role="dialog" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="<?php print t('Close') ?>"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title" id="c4dVideoLabel"><?php print t('Watch what is capacity4dev') ?></h4>
      </div>
      <div class="modal-body">
        <?php print $video_embed ?>
      </div>
    </div>
  </div>
</div>
