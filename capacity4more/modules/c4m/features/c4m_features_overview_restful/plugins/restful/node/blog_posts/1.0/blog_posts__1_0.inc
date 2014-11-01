<?php

$plugin = array(
  'label' => t('Blog post'),
  'resource' => 'blog_posts',
  'name' => 'blog_posts__1_0',
  'entity_type' => 'node',
  'bundle' => 'blog',
  'description' => t('Expose the "Discussion" resource.'),
  'class' => 'C4mRestfulBlogPostsResource',
  'authentication_types' => TRUE,
);
