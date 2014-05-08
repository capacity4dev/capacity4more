<?php
/**
 * @file
 * Class to create the Region vocabulary terms.
 */

/**
 * Class C4mDemoContentCreateRegionTerms
 */
class C4mDemoContentCreateRegionTerms extends C4mDemoContentCreateVocabularyTerms {
  public $bundle = 'c4m_vocab_geo';

  /**
   * Content creations need to be run before this one.
   *
   * @var array
   */
  public $dependencies = array(
    'C4mDemoContentCreateUsers',
  );
}
