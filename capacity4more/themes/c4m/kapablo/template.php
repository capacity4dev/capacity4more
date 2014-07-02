<?php

function kapablo_preprocess_page(&$variables) {
  global $user;

  // Welcome message.
  $name = t('guest');
  if ($user->uid) {
    $wrapper = entity_metadata_wrapper('user', $user);
    $name = $wrapper->c4m_first_name->value();
  }
  $variables['welcome'] = t('Welcome %name', array('%name' => $name));

  // Prepare menus.
  $variables['user_menu'] = menu_tree('user-menu');
  $variables['navigation'] = menu_tree('navigation');

  // TODO: Replace dummy search form.
  $variables['search_form'] = '<form action="#" class="inline-form"><input type="text" placeholder="Search"><input type="button"></form>';
}
