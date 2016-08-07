<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 * - $page['page_top']: Items for the page top region.
 * - $page['page_bottom']: Items for the page bottom region.
 *
 * @see kapablo_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 *
 * @link html.tpl.php
 *
 * @ingroup themeable
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

  <!--  TOP MENU -->
  <?php if (!empty($page['top_menu'])): ?>
    <section id="top-menu">
      <div class="container">
        <div class="row">
          <div class="col-sm-12 col-md-12 text-right">
            <?php print render($page['top_menu']); ?>
          </div>
        </div>
      </div>
    </section>
  <?php endif; ?>

  <div id="header-ec-wrapper">
    <div class="container">
      <div class="row">
        <div class="col-xs-9 col-sm-8 col-md-9 header-logo">
          <?php if ($logo): ?>
            <a class="logo pull-left" href="<?php print $front_page; ?>"
               title="<?php print t('Home'); ?>">
              <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/>
            </a>
          <?php endif; ?>
        </div>

        <div class="col-xs-3 col-sm-4 col-md-3">

          <div class="header-actions">

            <span class="header-actions--wrapper">
              <span class="header-actions--search fa fa-search" data-toggle="collapse" data-target="#search"></span>
            </span>
            <span class="header-actions--wrapper">
              <div class="header-actions--navigation js-navigationButton" data-effect="animation--push">
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
              </div>
            </span>
          </div>

        </div>


        <div id="search" class="col-xs-4 col-sm-4 col-md-3 header-search collapse">
          <!-- SEARCH-->
          <?php print render($search_form); ?>
        </div>
      </div>

      <div class="row">
        <div class="col-sm-12 col-md-12 header-breadcrumb">
          <?php if (!empty($breadcrumb)): print $breadcrumb;
          endif; ?>
        </div>
      </div>
    </div>
  </div><!-- /banner-ec -->

  <?php if ($page['header']): ?>
    <div id="header-content-wrapper">
      <div class="container">
        <div class="row">
          <div class="col-sm-12 col-md-12 header-content">
            <?php print render($page['header']); ?>
          </div>
        </div>
      </div>
    </div><!-- /header-content-wrapper -->
  <?php endif; ?>

  <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
    <div class="navigation--primary">
      <nav class="container navbar" role="navigation">
        <!-- Brand and toggle get grouped for better mobile display -->
        <div class="navbar-header">
          <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
          <button type="button" class="navbar-toggle" data-toggle="collapse"
                  data-target=".navbar-collapse">
            <span class="sr-only">Toggle navigation</span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
        </div>

        <div class="navbar-collapse collapse">
          <?php if (!empty($primary_nav)): ?>
            <?php print render($primary_nav); ?>
          <?php endif; ?>
          <?php if (!empty($page['navigation'])): ?>
            <?php print render($page['navigation']); ?>
          <?php endif; ?>
        </div>
      </nav>
    </div>
  <?php endif; ?>
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
          <span class="trigger-text">Group info</span>
          <i class="pull-right fa fa-chevron-right"></i>
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

<?php if (!empty($page['content_bottom'])): ?>
  <div class="row content-bottom">
    <div class="col-sm-12">
      <?php print render($page['content_bottom']); ?>
    </div>
  </div>
<?php endif; ?>


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
