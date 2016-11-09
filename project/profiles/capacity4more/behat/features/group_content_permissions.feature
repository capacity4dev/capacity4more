Feature: Test creation of the content permissions.
  Test group members' permissions.

  @javascript
  Scenario: Check Discussion creating in the own group
    Given a group "Discussion Insert 2" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    Then  I should be allowed to create a "discussion" in group "Discussion Insert 2"

  @javascript
  Scenario: Check Event creating in the own group
    Given a group "Discussion Insert 4" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    Then  I should be allowed to create a "event" in group "Discussion Insert 4"

  @api
  Scenario Outline: As admin, access create content form, without purl prefix.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should not have access to the page

    Examples:
      | user        | path                 |
      | mariecurie  | /node/add/photoalbum |
      | mariecurie  | /node/add/photo |
      | mariecurie  | /node/add/event |
      | mariecurie  | /node/add/document |
      | mariecurie  | /node/add/discussion |

  @api
  Scenario: Set "Pending" group state to 'Public'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When  I change access of group "Pending group" to "Public"
    Then  I am an anonymous user
    And I go to "pending"
    And I should see "Please log in"

  @dev-new
  Scenario Outline: As site admin, access create content form, with purl prefix of pending public group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should have access to the page

    Examples:
      | user        | path                 |
      | mariecurie  | /pending/node/add/photoalbum |
      | mariecurie  | /pending/node/add/photo |
      | mariecurie  | /pending/node/add/event |
      | mariecurie  | /pending/node/add/document |
      | mariecurie  | /pending/node/add/discussion |

  @dev-new
  Scenario Outline: As non member, member, group admin and group owner, access create content form, with purl prefix of pending public group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /nobelprize/node/add/photoalbum |
      | isaacnewton | /nobelprize/node/add/photoalbum |
      | turing      | /nobelprize/node/add/photoalbum |
      | alfrednobel | /nobelprize/node/add/photoalbum |
      | badhairday  | /nobelprize/node/add/photo |
      | isaacnewton | /nobelprize/node/add/photo |
      | turing      | /nobelprize/node/add/photo |
      | alfrednobel | /nobelprize/node/add/photo |
      | badhairday  | /nobelprize/node/add/event |
      | isaacnewton | /nobelprize/node/add/event |
      | turing      | /nobelprize/node/add/event |
      | alfrednobel | /nobelprize/node/add/event |
      | badhairday  | /nobelprize/node/add/document |
      | isaacnewton | /nobelprize/node/add/document |
      | turing      | /nobelprize/node/add/document |
      | alfrednobel | /nobelprize/node/add/document |
      | badhairday  | /nobelprize/node/add/discussion |
      | isaacnewton | /nobelprize/node/add/discussion |
      | turing      | /nobelprize/node/add/discussion |
      | alfrednobel | /nobelprize/node/add/discussion |

  @dev
  Scenario: Set "Pending group" group state to 'Restricted'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When  I change access of group "Pending group" to "Restricted"
    Then  I am an anonymous user
    And I go to "nobelprize"
    And I should see "Please log in"

  @dev
  Scenario Outline: As site admin, access create content form, with purl prefix of pending restricted group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should have access to the page

    Examples:
      | user        | path                 |
      | mariecurie  | /nobelprize/node/add/photoalbum |
      | mariecurie  | /nobelprize/node/add/photo |
      | mariecurie  | /nobelprize/node/add/event |
      | mariecurie  | /nobelprize/node/add/document |
      | mariecurie  | /nobelprize/node/add/discussion |

  @dev
  Scenario Outline: As non member, member, group admin and group owner, access create content form, with purl prefix of pending restricted group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /nobelprize/node/add/photoalbum |
      | isaacnewton | /nobelprize/node/add/photoalbum |
      | turing      | /nobelprize/node/add/photoalbum |
      | alfrednobel | /nobelprize/node/add/photoalbum |
      | badhairday  | /nobelprize/node/add/photo |
      | isaacnewton | /nobelprize/node/add/photo |
      | turing      | /nobelprize/node/add/photo |
      | alfrednobel | /nobelprize/node/add/photo |
      | badhairday  | /nobelprize/node/add/event |
      | isaacnewton | /nobelprize/node/add/event |
      | turing      | /nobelprize/node/add/event |
      | alfrednobel | /nobelprize/node/add/event |
      | badhairday  | /nobelprize/node/add/document |
      | isaacnewton | /nobelprize/node/add/document |
      | turing      | /nobelprize/node/add/document |
      | alfrednobel | /nobelprize/node/add/document |
      | badhairday  | /nobelprize/node/add/discussion |
      | isaacnewton | /nobelprize/node/add/discussion |
      | turing      | /nobelprize/node/add/discussion |
      | alfrednobel | /nobelprize/node/add/discussion |

  @dev
  Scenario: Set "Nobel Prize" group state to 'Private'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When  I change access of group "Nobel Prize" to "Private"
    Then  I am an anonymous user
    And I go to "nobelprize"
    And I should see "Please log in"

  @dev
  Scenario Outline: As site admin, access create content form, with purl prefix of pending private group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should have access to the page

    Examples:
      | user        | path                 |
      | mariecurie  | /nobelprize/node/add/photoalbum |
      | mariecurie  | /nobelprize/node/add/photo |
      | mariecurie  | /nobelprize/node/add/event |
      | mariecurie  | /nobelprize/node/add/document |
      | mariecurie  | /nobelprize/node/add/discussion |

  @dev
  Scenario Outline: As non member, member, group admin and group owner, access create content form, with purl prefix of pending private group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /nobelprize/node/add/photoalbum |
      | isaacnewton | /nobelprize/node/add/photoalbum |
      | turing      | /nobelprize/node/add/photoalbum |
      | alfrednobel | /nobelprize/node/add/photoalbum |
      | badhairday  | /nobelprize/node/add/photo |
      | isaacnewton | /nobelprize/node/add/photo |
      | turing      | /nobelprize/node/add/photo |
      | alfrednobel | /nobelprize/node/add/photo |
      | badhairday  | /nobelprize/node/add/event |
      | isaacnewton | /nobelprize/node/add/event |
      | turing      | /nobelprize/node/add/event |
      | alfrednobel | /nobelprize/node/add/event |
      | badhairday  | /nobelprize/node/add/document |
      | isaacnewton | /nobelprize/node/add/document |
      | turing      | /nobelprize/node/add/document |
      | alfrednobel | /nobelprize/node/add/document |
      | badhairday  | /nobelprize/node/add/discussion |
      | isaacnewton | /nobelprize/node/add/discussion |
      | turing      | /nobelprize/node/add/discussion |
      | alfrednobel | /nobelprize/node/add/discussion |

  @dev
  Scenario: Change "Nobel Prize" group state to Draft.
    Given  I am logged in as user "mariecurie"
    When  The group "Nobel Prize" status is changed by admin to "Draft"
    Then  I should have access to the page

  @dev-wip
  Scenario: Set "Nobel Prize" group state to 'Public'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When  I change access of group "Nobel Prize" to "Public"
    Then  I am an anonymous user
    And I go to "nobelprize"
    And I should see "Please log in"

  @dev-wip
  Scenario Outline: As member, group admin, group owner and site admin, access create content form, with purl prefix of draft public group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should have access to the page

    Examples:
      | user        | path                 |
      | turing  | /nobelprize/node/add/photoalbum |
      | turing  | /nobelprize/node/add/photo |
      | turing  | /nobelprize/node/add/event |
      | turing  | /nobelprize/node/add/document |
      | turing  | /nobelprize/node/add/discussion |
      | galileo  | /nobelprize/node/add/photoalbum |
      | galileo  | /nobelprize/node/add/photo |
      | galileo  | /nobelprize/node/add/event |
      | galileo  | /nobelprize/node/add/document |
      | galileo  | /nobelprize/node/add/discussion |
      | galileo  | /nobelprize/node/add/photoalbum |
      | alfrednobel  | /nobelprize/node/add/photo |
      | alfrednobel  | /nobelprize/node/add/event |
      | alfrednobel  | /nobelprize/node/add/document |
      | alfrednobel  | /nobelprize/node/add/discussion |
      | mariecurie  | /nobelprize/node/add/photoalbum |
      | mariecurie  | /nobelprize/node/add/photo |
      | mariecurie  | /nobelprize/node/add/event |
      | mariecurie  | /nobelprize/node/add/document |
      | mariecurie  | /nobelprize/node/add/discussion |

  @dev-wip
  Scenario Outline: As non member, access create content form, with purl prefix of draft public group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /nobelprize/node/add/photoalbum |
      | badhairday  | /nobelprize/node/add/photo |
      | badhairday  | /nobelprize/node/add/event |
      | badhairday  | /nobelprize/node/add/document |
      | badhairday  | /nobelprize/node/add/discussion |

  @dev-wip
  Scenario: Set "Nobel Prize" group state to 'Restricted'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When  I change access of group "Nobel Prize" to "Restricted"
    Then  I am an anonymous user
    And I go to "nobelprize"
    And I should see "Please log in"

  @dev-wip
  Scenario Outline:  As member, group admin, group owner and site admin, access create content form, with purl prefix of draft restricted group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should have access to the page

    Examples:
      | user        | path                 |
      | turing  | /nobelprize/node/add/photoalbum |
      | turing  | /nobelprize/node/add/photo |
      | turing  | /nobelprize/node/add/event |
      | turing  | /nobelprize/node/add/document |
      | turing  | /nobelprize/node/add/discussion |
      | galileo  | /nobelprize/node/add/photoalbum |
      | galileo  | /nobelprize/node/add/photo |
      | galileo  | /nobelprize/node/add/event |
      | galileo  | /nobelprize/node/add/document |
      | galileo  | /nobelprize/node/add/discussion |
      | galileo  | /nobelprize/node/add/photoalbum |
      | alfrednobel  | /nobelprize/node/add/photo |
      | alfrednobel  | /nobelprize/node/add/event |
      | alfrednobel  | /nobelprize/node/add/document |
      | alfrednobel  | /nobelprize/node/add/discussion |
      | mariecurie  | /nobelprize/node/add/photoalbum |
      | mariecurie  | /nobelprize/node/add/photo |
      | mariecurie  | /nobelprize/node/add/event |
      | mariecurie  | /nobelprize/node/add/document |
      | mariecurie  | /nobelprize/node/add/discussion |

  @dev-wip
  Scenario Outline: As non member, access create content form, with purl prefix of draft restricted group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /nobelprize/node/add/photoalbum |
      | badhairday  | /nobelprize/node/add/photo |
      | badhairday  | /nobelprize/node/add/event |
      | badhairday  | /nobelprize/node/add/document |
      | badhairday  | /nobelprize/node/add/discussion |

  @dev-wip
  Scenario: Set "Nobel Prize" group state to 'Private'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When  I change access of group "Nobel Prize" to "Private"
    Then  I am an anonymous user
    And I go to "nobelprize"
    And I should see "Please log in"

  @dev-wip
  Scenario Outline: As member, group admin, group owner and site admin, access create content form, with purl prefix of draft private group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should have access to the page

    Examples:
      | user        | path                 |
      | turing  | /nobelprize/node/add/photoalbum |
      | turing  | /nobelprize/node/add/photo |
      | turing  | /nobelprize/node/add/event |
      | turing  | /nobelprize/node/add/document |
      | turing  | /nobelprize/node/add/discussion |
      | galileo  | /nobelprize/node/add/photoalbum |
      | galileo  | /nobelprize/node/add/photo |
      | galileo  | /nobelprize/node/add/event |
      | galileo  | /nobelprize/node/add/document |
      | galileo  | /nobelprize/node/add/discussion |
      | galileo  | /nobelprize/node/add/photoalbum |
      | alfrednobel  | /nobelprize/node/add/photo |
      | alfrednobel  | /nobelprize/node/add/event |
      | alfrednobel  | /nobelprize/node/add/document |
      | alfrednobel  | /nobelprize/node/add/discussion |
      | mariecurie  | /nobelprize/node/add/photoalbum |
      | mariecurie  | /nobelprize/node/add/photo |
      | mariecurie  | /nobelprize/node/add/event |
      | mariecurie  | /nobelprize/node/add/document |
      | mariecurie  | /nobelprize/node/add/discussion |

  @dev-wip
  Scenario Outline: As non member, access create content form, with purl prefix of draft private group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /nobelprize/node/add/photoalbum |
      | badhairday  | /nobelprize/node/add/photo |
      | badhairday  | /nobelprize/node/add/event |
      | badhairday  | /nobelprize/node/add/document |
      | badhairday  | /nobelprize/node/add/discussion |
