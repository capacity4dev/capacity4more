<?php

/**
 * @file
 * XML response when successful.
 */
?>
<user>
  <valid><?php echo $data['valid']; ?></valid>
  <title><?php echo $data['title']; ?></title>
  <userid><?php echo $data['userid']; ?></userid>
  <fname><?php echo $data['firstname']; ?></fname>
  <lname><?php echo $data['lastname']; ?></lname>
  <email><?php echo $data['email']; ?></email>
  <dg><?php echo $data['department']; ?></dg>
  <country iso="<?php echo $data['country_iso']; ?>"><?php echo $data['country_name']; ?></country>
  <region><?php echo $data['region']; ?></region>
</user>
