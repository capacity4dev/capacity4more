<?php

/**
 * @file
 * Template for presenting OG project pages footer.
 */
?>

<div class="c4m-footer-bar-wrapper">
  <ul class="c4m-footer-bar">
    <li class="first">
      <?php print $logo_link ?>
    </li>
    <li class="c4m-footer-bar-project">
      <div class="text-uppercase">
        <?php print t('Explore more projects on') ?>
        <?php print $project_link ?>
        <br/>
        <?php print $europaid_link ?>
      </div>
    </li>
  </ul>
</div>
