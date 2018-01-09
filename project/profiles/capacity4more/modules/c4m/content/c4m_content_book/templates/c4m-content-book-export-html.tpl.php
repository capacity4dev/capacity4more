<?php

/**
 * @file
 * Template for the book export.
 */

drupal_add_js(drupal_get_path('module', 'c4m_content_book') . '/js/book-print.js', array('scope' => 'footer'));
?>
<div class="book-print">
    <?php if (!empty($status)): ?>
        <div class="group-indications">
            <div class="group-indications--access">
                <i class="top-buffer group-icon group-public node-icon as-group-public"></i>
                <span class="top-buffer indication label label-access public group-access">
                    <?php print $status; ?>
                </span>
            </div>
        </div>
    <?php endif; ?>
    <?php if (!empty($contents)): ?>
        <?php print $contents; ?>
    <?php endif; ?>
    <?php if (!empty($comments)): ?>
        <h2><?php print t("Comments"); ?></h2>
        <div class="book-print--comments">
            <?php print render($comments); ?>
        </div>
    <?php endif; ?>
</div>
