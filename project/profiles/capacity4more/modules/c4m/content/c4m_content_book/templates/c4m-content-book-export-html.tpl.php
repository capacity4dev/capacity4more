<?php

/**
 * @file
 * Template for the book export.
 */

drupal_add_js(drupal_get_path('module', 'c4m_content_book') . '/js/book-print.js');
?>
<div class="book-print">
    <?php print $contents; ?>
    <?php if (!empty($comments)): ?>
        <h2><?php print t("Comments"); ?></h2>
        <div class="book-print--comments">
            <?php print render($comments); ?>
        </div>
    <?php endif; ?>
</div>