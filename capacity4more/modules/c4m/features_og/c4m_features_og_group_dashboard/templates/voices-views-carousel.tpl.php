<div class="row" ng-controller="CarouselCtrl">
  <div class="col-md-12">
    <ul rn-carousel class="image">
      <li ng-repeat="carousel in carouselImages">
        <div class="layer">{{ carousel.image }}</div>
      </li>
    </ul>
    <div rn-carousel-indicators ng-if="carouselImages.length > 1" slides="carouselImages"></div>
  </div>
</div>
