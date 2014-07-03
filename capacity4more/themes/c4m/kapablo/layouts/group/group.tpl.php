<section class="group">
  <div class="row">
    <div class="col-md-12">
      <h1 class="main-title"><?php print $content['title']; ?></h1>

      <div class="banner img-responsive-wrapper">
        <?php print $content['image']; ?>
      </div>
    </div>
  </div>
  <div class="row">
    <div class="col-md-7 col-xs-12">

      <h2 class="green-title"><?php print t('Group Activity'); ?></h2>

      <div class="add-activity">
        <form action="#" class="inline-form">
          <input type="text"
                 placeholder="Add a discussion, ask a question or tell us your idea here..."/>
          <input type="button"/>
        </form>
      </div>

      <div class="filter">
        <ul>
          <li class="discussion"><a href="#"></a></li>
          <li class="question"><a href="#"></a></li>
          <li class="idea"><a href="#"></a></li>
        </ul>
      </div>

      <?php print $content['activity_stream']; ?>
    </div>

    <div class="col-md-5 col-xs-12">
      <div class="group-info">
        <h2 class="green-title public">Public</h2>

        <p class="creation"><?php echo $content['created']; ?></p>

        <div class="description">
          <?php print $content['description']; ?>
        </div>

        <div class="info owner">
          <label><?php print t('Group owner'); ?>:</label>
          <?php print $content['group_owner']; ?>
        </div>
        <div class="info members-count">
          <label><?php print t('Members'); ?>:</label>
          <?php print $content['members_count']; ?>
        </div>
        <div class="info topics">
          <label><?php print t('Topics'); ?>:</label>
          <?php print $content['topics']; ?>
        </div>
      </div>

      <div class="highlights">
        <h2 class="green-title"><?php print t('Highlights'); ?></h2>
        <?php print $content['highlights']; ?>
      </div>
    </div>
  </div>
</section>
