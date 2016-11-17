Feature: Global access
  Test global access

  @api
  Scenario Outline: Verify global pages cannot be seeing with context.
    Given I am logged in as user "mariecurie"
    When I go to "<url>"
    Then I should not have access to the page

    Examples:
    | url                      |
    | nobelprize/groups        |
    | nobelprize/people        |
    | nobelprize/learning      |
    | nobelprize/about         |
    | nobelprize/help-guidance |
    | nobelprize/legal-notices |

  @api
  Scenario Outline: Verify global pages can be seeing without the context.
    Given I am an anonymous user
    When I go to "<url>"
    Then I should have access to the page

    Examples:
    | url           |
    | groups        |
    | people        |
    | learning      |
    | about         |
    | help-guidance |
    | legal-notices |
