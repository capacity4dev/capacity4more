<?php

/**
 * @file
 * Template for presenting OG project pages footer.
 */
?>

<div class="row">
  <ul class="c4m-footer-bar clearfix">
    <li class="first">
      <a class="logo" href="<?php print $front_page; ?>"
         title="<?php print t('Home'); ?>">
        <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/>
      </a>
    </li>
    <li class="c4m-footer-bar-project">
      <div class="text-uppercase">
        Explore more projects on
        <a href="<?php print $project_page; ?>" class="text-orange">Capacity4dev ></a>
        <br/>
        <a href=" https://ec.europa.eu/europeaid/home_en" class="">International cooperation and development ></a>
      </div>
    </li>
  </ul>
</div>
