Feature: Articles
  Check articles overview and detail pages

  @api
  Scenario: Check article detail page as anonymous
    Given I am an anonymous user
    When I visit "Recovery of Oldest Human DNA" node of type "article"
    Then I should see the article detail page