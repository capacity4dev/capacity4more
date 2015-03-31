<div class="row group-management-dashboard">
  <div class="col-md-12 group-management-wrapper">
    <div class="group-details">
      <div class="title">
        <h2><?php print t('Group details') ?></h2>
        <?php print $details['edit_link'] ?>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Group name') ?></div>
        <div class="col-md-9"><?php print $details['title'] ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Group path') ?></div>
        <div class="col-md-9"><?php print $details['purl'] ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Group description') ?></div>
        <div class="col-md-9"><?php print $details['description']['safe_value'] ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Group topics') ?></div>
        <div class="col-md-9"><?php print $details['topics'] ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Group regions & countires') ?></div>
        <div class="col-md-9"><?php print $details['locations'] ?></div>
      </div>
    </div>
    <div class="group-permissions">
      <div class="title">
        <h2><?php print t('Group permissions') ?></h2>
        <?php print $details['edit_link'] ?>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Group access') ?></div>
        <div class="col-md-9">
          <div class="access-title <?php print $details['group_access']['type'] ?>">
            <?php print $details['group_access']['title'] ?>
          </div>
          <div class="access-description">
            <?php print $details['group_access']['description'] ?>
          </div>
        </div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Membership requests') ?></div>
        <div class="col-md-9"><?php print $details['membership_open_request'] ?></div>
      </div>
    </div>
    <div class="group-related-content">
      <div class="title">
        <h2><?php print t('Related content') ?></h2>
        <?php print $details['edit_link'] ?>
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
    <div class="group-related-content">
      <div class="title">
        <h2><?php print t('Categories') ?></h2>
        <?php print $details['taxonomy_manage_link'] ?>
      </div>
      <div class="row">
        <div class="col-md-12"><?php print t('This group has <strong>@cat_count Categories</strong> and <strong>@term_count Terms</strong>', array('@cat_count' => $details['categories_count'], '@term_count' => $details['tags_count'])) ?></div>
      </div>
    </div>
  </div>
</div>
