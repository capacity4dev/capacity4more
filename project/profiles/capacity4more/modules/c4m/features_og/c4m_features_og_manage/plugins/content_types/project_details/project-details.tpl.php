<?php

/**
 * @file
 * Template for the project management dashboard.
 */
?>

<div class="row project-management-dashboard">
  <div class="col-md-12 project-management-wrapper">
    <div class="project-administration">
      <div class="title">
        <h2><?php print t('Project administration') ?></h2>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Owner') ?> (<a
            href="<?php print $details['owner_edit']; ?>"><?php print t(
              'Edit'
            ) ?></a>)
        </div>
        <div class="col-md-9"><?php print $details['owner']; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Administrators') ?> (<a
            href="<?php print $details['admins_edit']; ?>"><?php print t(
              'Edit'
            ) ?></a>)
        </div>
        <div class="col-md-9"><?php print $details['admins']; ?></div>
      </div>
    </div>
    <div class="project-details">
      <div class="title">
        <h2><?php print t('Project details') ?></h2>
        <a href="<?php print $details['edit_link'] ?>#edit-details"><?php print t('Edit'); ?></a>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Project name') ?></div>
        <div class="col-md-9"><?php print (isset($details['title'])) ? $details['title'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Project path') ?></div>
        <div class="col-md-9"><?php print (isset($details['purl'])) ? $details['purl'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Project tag line') ?></div>
        <div class="col-md-9"><?php print isset($details['tagline']) ? $details['tagline'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Project stage') ?></div>
        <div class="col-md-9"><?php print isset($details['stage']) ? $details['stage'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Project description') ?></div>
        <div class="col-md-9"><?php print isset($details['description']['value']) ? $details['description']['value'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Duration') ?></div>
        <div class="col-md-9"><?php print (isset($details['duration'])) ? $details['duration'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('External URL') ?></div>
        <div class="col-md-9"><?php print (isset($details['url'])) ? $details['url'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Total budget') ?></div>
        <div class="col-md-9"><?php print (isset($details['total_budget'])) ? $details['total_budget'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Project stakeholders') ?></div>
        <div class="col-md-9"><?php print isset($details['stakeholders']) ? $details['stakeholders'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Source of funding') ?></div>
        <div class="col-md-9"><?php print (isset($details['source_funding'])) ? $details['source_funding'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Partners') ?></div>
        <div class="col-md-9"><?php print (isset($details['partners'])) ? $details['partners'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('CRIS Decision number') ?></div>
        <div class="col-md-9"><?php print (isset($details['cris_decision_number'])) ? $details['cris_decision_number'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('CRIS Contract number') ?></div>
        <div class="col-md-9"><?php print (isset($details['cris_contract_number'])) ? $details['cris_contract_number'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Project topics') ?></div>
        <div class="col-md-9"><div class="c4m-taxonomy-tree"><?php print (isset($details['topics'])) ? $details['topics'] : ''; ?></div></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Project regions & countries') ?></div>
        <div class="col-md-9"><div class="c4m-taxonomy-tree"><?php print (isset($details['locations'])) ? $details['locations'] : ''; ?></div></div>
      </div>
    </div>
    <div class="project-related-content">
      <div class="title">
        <h2><?php print t('Related content') ?></h2>
        <a
          href="<?php print $details['edit_link'] ?>#edit-related-content"><?php print t(
            'Edit'
          ) ?> </a>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Related Groups') ?></div>
        <div class="col-md-9"><?php print (isset($details['related_groups'])) ? $details['related_groups'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Related Projects') ?></div>
        <div class="col-md-9"><?php print (isset($details['related_projects'])) ? $details['related_projects'] : ''; ?></div>
      </div>
    </div>
    <div class="project-related-content">
      <div class="title">
        <h2><?php print t('Categories') ?></h2>
        <?php print $details['taxonomy_manage_link'] ?>
      </div>
      <div class="row">
        <div class="col-md-12"><?php print t(
            'This project has <strong>@cat_count Categories</strong> and <strong>@term_count Terms</strong>',
            array(
              '@cat_count' => $details['categories_count'],
              '@term_count' => $details['terms_count'],
            )
          ) ?></div>
      </div>
    </div>
    <div class="project-features">
      <div class="title">
        <h2><?php print t('Features') ?></h2>
        <?php print $details['features_manage_link'] ?>
      </div>
      <?php foreach ($details['features_available'] as $feature) : ?>
        <div class="row">
          <div class="col-md-3"><?php print $feature['name']; ?></div>
          <div
            class="col-md-9"><?php print empty($details['features_enabled'][$feature['machine_name']]) ? t(
              'Disabled'
            ) : '<strong>' . t('Enabled') . '</strong>'; ?></div>
        </div>
      <?php endforeach; ?>
    </div>
    <div class="project-navigation">
      <div class="title">
        <h2><?php print t('Project Navigation') ?></h2>
        <a href="<?php print $details['menu_link']; ?>"><?php print t(
            'Edit'
          ) ?></a>
      </div>
    </div>
  </div>
</div>
