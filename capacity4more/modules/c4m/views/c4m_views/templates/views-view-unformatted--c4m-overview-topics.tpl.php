<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<?php if (!empty($title)): ?>
  <h3 class="col-sm-12 align-center"><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
    <?php if ($classes_array[$id]): ?>
      <div class="<?php print $classes_array[$id]; ?>">
    <?php else: ?>
      <div>
    <?php endif; ?>
        <?php print $row; ?>
      </div>
<?php endforeach; ?>
