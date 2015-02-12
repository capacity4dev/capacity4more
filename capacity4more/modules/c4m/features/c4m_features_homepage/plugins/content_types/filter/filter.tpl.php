<div class="content-filter row">
  <form class="col-sm-12">
  <?php print t('Filter by'); ?>
  <?php if ($is_member): ?>
  <input type="radio" name="filter" value="groups"> <?php print t('My groups'); ?>
  <?php endif; ?>
  <input type="radio" name="filter" value="interests"> <?php print t('My interests'); ?>
  <input type="radio" name="filter" value="all" checked> <?php print t('Show all'); ?>
    </form>
</div>
