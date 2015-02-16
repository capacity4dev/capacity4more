<div class="row" ng-controller="CarouselCtrl">
  <div class="col-md-12" ng-if="carouselImages.length > 0">
    <ul rn-carousel rn-carousel-index="carouselIndex" rn-carousel-loop rn-carousel-controls class="carousel">
      <li ng-repeat="slide in carouselImages track by slide.id" ng-class="'id-' + slide.id">
        <div ng-style="{'background-image': 'url(' + slide.image + ')'}"  class="bgimage">
          <div class="intro-text">
            <span class="title">
            {{ slide.title }}
          </span>
          <span class="text">
            {{ slide.text }}
          </span>
          </div>
        </div>
      </li>
    </ul>
    <div rn-carousel-indicators ng-if="carouselImages.length > 1" slides="carouselImages" rn-carousel-index="carouselIndex"></div>
  </div>
</div>
