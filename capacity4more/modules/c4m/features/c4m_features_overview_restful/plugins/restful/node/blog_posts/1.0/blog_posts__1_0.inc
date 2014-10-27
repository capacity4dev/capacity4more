<?php

$plugin = array(
  'label' => t('Blog post'),
  'resource' => 'blog_posts',
  'name' => 'blog_posts__1_0',
  'entity_type' => 'node',
  'bundle' => 'blog',
  'description' => t('Create "blog" content type.'),
  'class' => 'C4mRestfulBlogPostsResource',
  'authentication_types' => TRUE,
);
