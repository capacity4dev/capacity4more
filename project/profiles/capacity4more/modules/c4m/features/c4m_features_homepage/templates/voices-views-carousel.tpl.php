<?php
/**
 * @file
 * Prints out the Voices & Views carousel.
 */
?>

<div class="row carousel">
  <span class="block-title"><?php print l(t('VOICES & VIEWS'), 'articles'); ?></span>
  <div class="col-md-12">
    <div class="owl-carousel">
      <?php foreach ($carousels as $carousel): ?>
        <div class="item">
          <img class="" src="<?print $carousel['image']; ?>">
          <h2><?php print $carousel['title']; ?></h2>
          <p><?php print $carousel['text']; ?></p>
          <p><?php print $carousel['link']; ?></p>
        </div>
      <?php endforeach; ?>
    </div>
  </div>
</div>
