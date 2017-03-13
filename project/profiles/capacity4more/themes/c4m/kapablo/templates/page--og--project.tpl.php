<?php

/**
 * @file
 * Theme suggestion implementation to display a page for OG type = 'project'.
 */
?>

<header id="page-header" role="banner">

  <!--  USER BAR -->
  <?php if (!empty($page['user_bar'])): ?>
    <section id="user-bar">
      <div class="container">
        <div class="row">
          <div class="col-sm-12 col-md-12">
            <?php print render($page['user_bar']); ?>
          </div>
        </div>
      </div>
    </section>
  <?php endif; ?>

  <div id="header-ec-wrapper" class="c4m-project-page">
    <?php if ($image_banner_background): ?>
      <div class="background-banner">
        <?php print $image_banner_background; ?>
      </div>
    <?php endif; ?>

    <div class="container">
      <?php if ($image_banner): ?>
        <div class="row">
          <div class="col-sm-12 col-md-12">
            <?php print $image_banner; ?>
          </div>
        </div>
      <?php endif; ?>
    </div>
  </div><!-- /banner-ec -->

</header>

<?php if (!empty($page['content_top'])): ?>
  <div id="content-top-wrapper">
    <div class="container">
      <div class="row">
        <div class="col-sm-12 col-md-12 content-top">
          <?php print render($page['content_top']); ?>
        </div>
      </div>
    </div>
  </div>
<?php endif; ?>
<?php if (!empty($page['content_above'])): ?>
  <div id="content-above-wrapper">
    <div class="container">
      <div class="row">
        <div class="col-sm-12 col-md-12 content-above">
          <?php print render($page['content_above']); ?>
        </div>
      </div>
    </div>
  </div>
<?php endif; ?>

<div id="main-wrapper">
  <div class="container">
    <div class="row">
      <div class="col-sm-12 col-md-12">

        <div class="trigger trigger--groupInfo js-navigationButton" data-effect="animation--slideOn">
          <span class="trigger-label circle circle--green">
            <span class="fa fa-info" ></span>
          </span>
          <span class="trigger-text">Project/programme info</span>
          <i class="pull-right fa fa-chevron-right"></i>
        </div>
      </div>

      <header role="banner" id="page-header">
        <?php if (!empty($site_slogan)): ?>
          <p class="lead"><?php print $site_slogan; ?></p>
        <?php endif; ?>
      </header>
      <!-- /#page-header -->

      <?php if (!empty($page['sidebar_first']) || !empty($page['sidebar_first_top'])): ?>
        <aside class="col-sm-4 offCanvasNavigation--left" role="complementary">
          <?php print render($page['sidebar_first_top']); ?>
          <?php print render($page['sidebar_first']); ?>
        </aside>  <!-- /#sidebar-first -->
      <?php endif; ?>

      <section<?php print $content_column_class_kapablo; ?>>
        <?php if (!empty($page['highlighted'])): ?>
          <div class="highlighted well"><?php print render(
              $page['highlighted']
            ); ?></div>
        <?php endif; ?>
        <a id="main-content"></a>
        <?php print render($title_prefix); ?>
        <?php if (!empty($title)): ?>
          <h1 class="page-header"><?php print $title; ?></h1>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php print $messages; ?>
        <?php if (!empty($tabs)): ?>
          <?php print render($tabs); ?>
        <?php endif; ?>
        <?php if (!empty($page['help'])): ?>
          <?php print render($page['help']); ?>
        <?php endif; ?>
        <?php if (!empty($action_links)): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>

        <?php if (!empty($page['sidebar_first']) && !empty($offcanvas_trigger_label_left)): ?>
          <div class="trigger js-navigationButton clearfix" data-effect="animation--slideOn">
            <i class="pull-left fa fa-chevron-left"></i>
            <span class="trigger-text pull-right"><?php print $offcanvas_trigger_label_left['label']; ?></span>
            <?php if ($offcanvas_trigger_label_left['icon']): ?>
              <span class="trigger-label circle circle--white pull-right">
                <span class="fa fa-<?php print $offcanvas_trigger_label_left['icon']; ?>" ></span>
              </span>
            <?php endif; ?>
          </div>
        <?php endif; ?>

        <?php if (!empty($page['sidebar_second']) && !empty($offcanvas_trigger_label_right)): ?>
          <div class="trigger js-navigationButton clearfix" data-effect="animation--slideOn">
            <?php if ($offcanvas_trigger_label_left['icon']): ?>
              <span class="trigger-label pull-left circle circle--white">
                <span class="fa fa-<?php print $offcanvas_trigger_label_right['icon']; ?>" ></span>
              </span>
            <?php endif; ?>
            <span class="trigger-text pull-left"><?php print $offcanvas_trigger_label_right['label']; ?></span>
            <i class="pull-right fa fa-chevron-right"></i>
          </div>
        <?php endif; ?>

        <?php print render($page['content']); ?>
      </section>

      <?php if (!empty($page['sidebar_second'])): ?>
        <aside class="col-sm-4 offCanvasNavigation--right" role="complementary">
          <?php print render($page['sidebar_second']); ?>
        </aside>  <!-- /#sidebar-second -->
      <?php endif; ?>
    </div>
  </div>
</div>

<div id="footer-top-wrapper">
  <div class="container">
    <div class="row">
      <section class="col-md-12">
        <?php print render($page['footer_top']); ?>
      </section>
    </div>
  </div>
</div>


<div id="footer-bottom-wrapper">
  <div class="container">
    <div class="row">
      <section class="col-md-12">
        <?php print render($page['footer_bottom']); ?>
      </section>
    </div>
  </div>
</div>
