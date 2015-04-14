<div class="row carousel" ng-controller="CarouselCtrl">
  <div class="col-md-12" ng-if="carouselImages.length > 0">
    <span class="block-title"><a href="<?php print url('articles') ?>"><?php print t('VOICES & VIEWS'); ?></a></span>
    <?php print $link; ?>
    <ul rn-carousel rn-carousel-index="carouselIndex" rn-carousel-loop rn-carousel-controls class="carousel">
      <li ng-repeat="slide in carouselImages track by slide.id" ng-class="'id-' + slide.id">
        <div ng-style="{'background-image': 'url(' + slide.image + ')'}"  class="bgimage">
          <a href="<?php print url('articles') ?>">
            <div class="intro-text">
              <span class="title">
                {{ slide.title }}
              </span>
              <span class="text">
                {{ slide.text }}
              </span>
            </div>
          </a>
        </div>
      </li>
    </ul>
    <div rn-carousel-indicators ng-if="carouselImages.length > 1" slides="carouselImages" rn-carousel-index="carouselIndex"></div>
  </div>
</div>
