<?php

/**
 * @file
 * Template for the book export.
 */
?>
<div class="book-print--item"><?php print render($content); ?></div>
<?php if (!empty($children)) :?>
    <div class="book-print--children"><?php print render($children); ?></div>
<?php endif; ?>

