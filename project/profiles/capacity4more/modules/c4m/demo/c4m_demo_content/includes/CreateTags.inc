<?php

/**
 * @file
 * Class to create the Tags vocabulary terms.
 */

/**
 * Class C4mDemoContentCreateTags.
 */
class C4mDemoContentCreateTags extends C4mDemoContentCreateVocabularyTerms {
  public $bundle = 'c4m_vocab_tag';

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
