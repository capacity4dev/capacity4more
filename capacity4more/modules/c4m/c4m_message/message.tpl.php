<div class="row post <?php print $message_type; ?> <?php print $node_type; ?>">
  <div class="col-md-3 user-info">
    <?php echo $user_picture; ?>
  </div>
  <div class="col-md-9 content-wrapper">
    <div class="post-action">
      <span class="icon"></span>
      <span class="author sans-font"><?php print $user_name; ?></span>
      <span class="action"><?php print render($content); ?></span>
      <span class="date"><?php print $created; ?></span>
    </div>
    <div class="post-content">
      <?php print $media; ?>
      <?php print $body; ?>
      <?php if ($comments_count): ?>
        <p class="comments"><?php print $comments_count; ?></p>
      <?php endif; ?>
    </div>
  </div>
</div>
