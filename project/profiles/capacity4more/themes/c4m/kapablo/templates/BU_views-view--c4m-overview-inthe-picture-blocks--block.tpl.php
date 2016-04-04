<?php

/**
 * @file
 * Display "In the picture" carousel on overview pages.
 *
 * When there's only one picture,
 * We display the picture without the carousel to avoid motion.
 */
?>

<div class="row carousel" ng-controller="CarouselCtrl">
  <div class="col-md-12" ng-if="carouselImages.length > 1">
    <ul rn-carousel rn-carousel-index="carouselIndex" rn-carousel-loop rn-carousel-controls class="carousel">
      <li ng-repeat="slide in carouselImages track by slide.id" ng-class="'id-' + slide.id">
        <a ng-href="{{ slide.alias }}">
          <div ng-style="{'background-image': 'url(' + slide.image + ')'}"  class="bgimage">
            <div class="intro-text" ng-if="slide.title || slide.text">
              <span class="title">
                {{ slide.title }}
              </span>
              <span class="text">
                {{ slide.text }}
              </span>
            </div>
          </div>
        </a>
      </li>
    </ul>
    <div rn-carousel-indicators ng-if="carouselImages.length > 1" slides="carouselImages" rn-carousel-index="carouselIndex"></div>
  </div>
  <div class="col-md-12" ng-if="carouselImages.length == 1">
    <ul class="no-carousel carousel">
      <li ng-repeat="slide in carouselImages track by slide.id" ng-class="'id-' + slide.id" class="one-slide">
        <a ng-href="{{ slide.alias }}">
          <div ng-style="{'background-image': 'url(' + slide.image + ')'}"  class="bgimage">
            <div class="intro-text" ng-if="slide.title || slide.text">
              <span class="title">
                {{ slide.title }}
              </span>
              <span class="text">
                {{ slide.text }}
              </span>
            </div>
          </div>
        </a>
      </li>
    </ul>
  </div>
</div>
