<?php

/**
 * @file
 * Template for presenting OG project pages footer.
 */
?>

<div>
  <ul class="c4m-footer-bar">
    <li class="first">
      <a class="logo" href="<?php print $front_page; ?>"
         title="<?php print t('Home'); ?>">
        <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/>
      </a>
    </li>
    <li class="c4m-footer-bar-project">
      <div class="text-uppercase">
        <?php print t('Explore more projects on') ?>
        <a href="<?php print $project_page; ?>" class="text-orange">
          <?php print t('Capacity4dev &gt') ?>
        </a>
        <br/>
        <a href="https://ec.europa.eu/europeaid/home_en">
          <?php print t('International cooperation and development &gt') ?>
        </a>
      </div>
    </li>
  </ul>
</div>
