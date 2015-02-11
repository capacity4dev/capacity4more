<div class="dropdown">
  <button class="btn btn-default dropdown-toggle" type="button"
          id="adminster-user-<?php print $user_id; ?>" data-toggle="dropdown"
          aria-expanded="true">
    <span class="glyphicon glyphicon-cog"></span>
  </button>
  <ul class="dropdown-menu" role="menu"
      aria-labelledby="adminster-user-<?php print $user_id; ?>">
    <?php print implode('', $links); ?>
  </ul>
</div>