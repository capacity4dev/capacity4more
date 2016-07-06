<?php

/**
 * @file
 * Class to create the Category vocabulary terms.
 */

/**
 * Class C4mDemoContentCreateCategories.
 */
class C4mDemoContentCreateCategories extends C4mDemoContentCreateVocabularyTerms {
  public $bundle = 'c4m_vocab_category';

  public $ogVocab = TRUE;

  /**
   * Content creations need to be run before this one.
   *
   * @var array
   */
  public $dependencies = array(
    'C4mDemoContentCreateGroups',
  );

}
