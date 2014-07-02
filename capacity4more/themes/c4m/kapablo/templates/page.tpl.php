<div class="container">
  <header>
    <div class="row">
      <div class="col-sm-3 col-xs-12">
        <div class="welcome"><?php print $welcome; ?></div>
        <div id="user-menu">
          <?php print render($user_menu); ?>
        </div>
        <div class="eu-logo sans-font">
          <p><?php print t('Development and cooperation europeAid'); ?></p>
        </div>
      </div>
      <div class="col-sm-3 col-xs-12">
        <div class="c4d-logo sans-font">
          <p>C<i>4</i>D.EU</p>
        </div>
      </div>
      <div class="col-sm-6 col-xs-12">
        <div id="main-nav">
          <?php print render($navigation_menu); ?>
        </div>

        <?php if (isset($search_form)): ?>
          <?php print $search_form; ?>
        <?php endif; ?>
      </div>
    </div>


    <div class="row breadcrumb">
      <?php if (isset($breadcrumbs)): ?>
        <?php print $breadcrumbs; ?>
      <?php endif; ?>
    </div>
  </header>

  <div id="messages">
    <?php print $messages; ?>
  </div>

  <?php print render($page['content']); ?>
</div>
