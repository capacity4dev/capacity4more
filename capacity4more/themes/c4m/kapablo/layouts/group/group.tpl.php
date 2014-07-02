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

      <h2 class="green-title">group activity</h2>

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
          <a href="#">De Caninock Sophie</a>
        </div>
        <div class="info members-count">
          <label>Members:</label>
          <a href="#">1234</a>
        </div>
        <div class="info topics">
          <label>Topic(s):</label>
          <a href="#">agriculture & rural development</a>,
          <a href="#">energy</a>,
          <a href="#">environment & climate change</a>,
          <a href="#">water & sanitation</a>
        </div>
      </div>

      <div class="highlights">
        <h2 class="green-title">Highlights</h2>
        <!-- This is a highlight post -->
        <div class="post blog first">
          <div class="content-wrapper">
            <div class="post-action">
              <span class="icon"></span>
              <span class="author sans-font">Amitai Bursitne</span>
              <span class="action">Created a blog post</span>
              <span class="date">Today, 20:00</span>
            </div>
            <div class="post-content">
              <p class="user-text">Farmer-driven research to improve food and
                nutrition security.</p>

              <p class="comments">2 Comments</p>
            </div>
          </div>
        </div>
        <!-- End of post -->
        <!-- This is a highlight post -->
        <div class="post discussion">
          <div class="content-wrapper">
            <div class="post-action">
              <span class="icon"></span>
              <span class="author sans-font">Keren Soref</span>
              <span class="action">Added a discussion</span>
              <span class="date">18/06/2014, 10:00</span>
            </div>
            <div class="post-content">
              <p class="user-text">Last week capacity4dev launched the updated
                Food & Nutrition Security – ROSA group. Laura Gualdi, Programme
                Manager for Food Security</p>

              <p class="comments">1 Comment</p>
            </div>
          </div>
        </div>
        <!-- End of post -->
        <!-- This is a highlight post -->
        <div class="post comment">
          <div class="content-wrapper">
            <div class="post-action">
              <span class="icon"></span>
              <span class="author sans-font">Bob Dylan</span>
              <span class="action">Commented on discussion</span>
              <span class="date">18/06/2014, 10:00</span>
            </div>
            <div class="post-content">
              <p class="user-text">Last week capacity4dev launched the updated
                Food & Nutrition Security – ROSA group. Laura Gualdi, Programme
                Manager for Food Security</p>

              <p class="comments">1 Comment</p>
            </div>
          </div>
        </div>
        <!-- End of post -->
        <!-- This is a highlight post -->
        <div class="post document">
          <div class="content-wrapper">
            <div class="post-action">
              <span class="icon"></span>
              <span class="author sans-font">Justin Bieber</span>
              <span class="action">Uploaded a document</span>
              <span class="date">17/06/2014, 14:48</span>
            </div>
            <div class="post-content">
              <p class="user-text">Atui Rauti Para Report.ppt</p>
            </div>
          </div>
        </div>
        <!-- End of post -->
        <!-- This is a highlight post -->
        <div class="post event">
          <div class="content-wrapper">
            <div class="post-action">
              <span class="icon"></span>
              <span class="author sans-font">Asaf Soref</span>
              <span class="action">Created an event</span>
              <span class="date">16/06/2014, 14:48</span>
            </div>
            <div class="post-content">
              <p class="user-text">10th Forest Governance Forum - Cameroon -
                22-24 October 2014</p>
            </div>
          </div>
        </div>
        <!-- End of post -->
        <!-- This is a highlight post -->
        <div class="post new-member last">
          <div class="content-wrapper">
            <div class="post-action">
              <span class="icon"></span>
              <span class="author sans-font">Asaf Soref</span>
              <span class="action">New member</span>
              <span class="date">16/06/2014, 14:48</span>
            </div>
          </div>
        </div>
        <!-- End of post -->
      </div>
    </div>
  </div>
</section>
