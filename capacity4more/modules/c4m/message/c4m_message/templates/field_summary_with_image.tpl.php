<div class="row">
  <?php if($image != ''):?>

    <div class="col-sm-6">

      <?php print $image; ?>

    </div>

    <div class="col-sm-6">

  <?php else: ?>

    <div class="col-sm-12">

  <?php endif; ?>

    <?php print $description; ?>

  </div>

</div>
