<div class="row" ng-controller="CarouselCtrl">
  <div class="col-md-12">
    <ul rn-carousel class="image">
      <li ng-repeat="carousel in carouselImages">
        <div class="layer">{{ carousel.image }}</div>
      </li>
    </ul>
  </div>
</div>
