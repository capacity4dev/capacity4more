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
        <div class="col-md-3"><?php print t('Owner') ?> (<a href="<?php print $details['owner_edit']; ?>"><?php print t('Edit') ?></a>)</div>
        <div class="col-md-9"><?php print $details['owner']; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Members') ?> (<a href="<?php print $details['admins_edit']; ?>"><?php print t('Edit') ?></a>)</div>
        <div class="col-md-9"><?php print $details['admins']; ?></div>
      </div>
    </div>
    <div class="project-details">
      <div class="title">
        <h2><?php print t('Project details') ?></h2>
        <a href="<?php print $details['edit_link'] ?>#edit-details"><?php print t('Edit') ?></a>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Project name') ?></div>
        <div class="col-md-9"><?php print $details['title'] ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Project path') ?></div>
        <div class="col-md-9"><?php print $details['purl'] ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Project description') ?></div>
        <div class="col-md-9"><?php print $details['description']['safe_value'] ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Duration') ?></div>
        <div class="col-md-9"><?php print $details['duration'] ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Total budget') ?></div>
        <div class="col-md-9"><?php print $details['total_budget'] ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Source of funding') ?></div>
        <div class="col-md-9"><?php print $details['source_funding'] ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Partners') ?></div>
        <div class="col-md-9"><?php print $details['partners'] ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Implemented by') ?></div>
        <div class="col-md-9"><?php print $details['implemented_by'] ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('CRIS Decision number') ?></div>
        <div class="col-md-9"><?php print $details['cris_decision_number'] ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('CRIS Contact number') ?></div>
        <div class="col-md-9"><?php print $details['cris_contract_number'] ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Project topics') ?></div>
        <div class="col-md-9"><?php print $details['topics'] ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Project regions & countries') ?></div>
        <div class="col-md-9"><?php print $details['locations'] ?></div>
      </div>
    </div>
    <div class="project-related-content">
      <div class="title">
        <h2><?php print t('Related content') ?></h2>
        <a href="<?php print $details['edit_link'] ?>#edit-related-content"><?php print t('Edit') ?> </a>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Related Groups') ?></div>
        <div class="col-md-9"><?php print $details['related_groups'] ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Related Projects') ?></div>
        <div class="col-md-9"><?php print $details['related_projects'] ?></div>
      </div>
    </div>
    <div class="project-related-content">
      <div class="title">
        <h2><?php print t('Categories') ?></h2>
        <?php print $details['taxonomy_manage_link'] ?>
      </div>
      <div class="row">
        <div class="col-md-12"><?php print t('This project has <strong>@cat_count Categories</strong> and <strong>@term_count Terms</strong>', array('@cat_count' => $details['categories_count'], '@term_count' => $details['terms_count'])) ?></div>
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
          <div class="col-md-9"><?php print empty($details['features_enabled'][$feature['machine_name']]) ? t('Disabled') : '<strong>' . t('Enabled') . '</strong>'; ?></div>
        </div>
      <?php endforeach; ?>
    </div>
  </div>
</div>
