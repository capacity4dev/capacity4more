<div class="content-filter row">
  <form class="col-sm-12" name="filter_form">
    <?php print t('Filter by'); ?>

    <?php if ($is_member): ?>
      <input type="radio" name="filter" value="groups" onclick="form.submit();" > <?php print t('My groups'); ?>
    <?php endif; ?>

    <input type="radio" name="filter" value="interests" onclick="form.submit();" > <?php print t('My interests'); ?>
    <input type="radio" name="filter" value="all" onclick="form.submit();"> <?php print t('Show all'); ?>
  </form>
</div>
