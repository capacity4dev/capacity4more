<?php

/**
 * @file
 * Prints out a list of all the groups the user is member of.
 */
?>

<div class="ecas--user-login">
    <p><img src="<?php echo $eu_flag_img; ?>" alt="European Union"
            class="no-border"/></p>
    <p><?php
      echo t('Or sign-in to Capacity4dev with your EU Login credentials');
      ?></p>
    <p><a class="btn btn-primary" href="<?php echo $ecas_login; ?>">Sign in via
            EU Login</a></p>
    <p>EU staff must authenticate via EU Login. <a
                href="<?php echo $ecas_about; ?>">Click here</a> to find out
        more.</p>
</div>
