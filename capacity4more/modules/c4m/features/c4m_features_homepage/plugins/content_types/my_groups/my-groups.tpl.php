<div class="row">
  <div class="col-md-12">
    <div class="my-groups">
      <div class="title"><?php print t('My Groups') ?></div>
      <?php print $first_groups ?>
      <div class="collapse" id="allGroups">
        <?php print $extra_groups ?>
      </div>
      <button class="btn btn-primary" type="button" data-toggle="collapse" data-target="#allGroups" aria-expanded="false" aria-controls="allGroups">
        <?php print t('Show all') ?>
      </button>
    </div>
  </div>
</div>
