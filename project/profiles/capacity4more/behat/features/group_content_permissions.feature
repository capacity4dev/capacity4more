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
    Given I am logged in as user "<user>"
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
    Given I am logged in as user "mariecurie"
    When  I change access of group "Pending group" to "Public"
    Then  I am an anonymous user
    And   I go to "pending"
    And   I should see "Please log in"

  @api
  Scenario Outline: As site admin, access create content form, with purl prefix of pending public group.
    Given I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should have access to the page

    Examples:
      | user        | path                 |
      | mariecurie  |  /pending/node/add/photoalbum |
      | mariecurie  |  /pending/node/add/photo |
      | mariecurie  |  /pending/node/add/event |
      | mariecurie  |  /pending/node/add/document |
      | mariecurie  |  /pending/node/add/discussion |

  @api
  Scenario Outline: As non member, member, group admin and group owner, access create content form, with purl prefix of pending public group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /pending/node/add/photoalbum |
      | isaacnewton | /pending/node/add/photoalbum |
      | turing      | /pending/node/add/photoalbum |
      | alfrednobel | /pending/node/add/photoalbum |
      | badhairday  | /pending/node/add/photo |
      | isaacnewton | /pending/node/add/photo |
      | turing      | /pending/node/add/photo |
      | alfrednobel | /pending/node/add/photo |
      | badhairday  | /pending/node/add/event |
      | isaacnewton | /pending/node/add/event |
      | turing      | /pending/node/add/event |
      | alfrednobel | /pending/node/add/event |
      | badhairday  | /pending/node/add/document |
      | isaacnewton | /pending/node/add/document |
      | turing      | /pending/node/add/document |
      | alfrednobel | /pending/node/add/document |
      | badhairday  | /pending/node/add/discussion |
      | isaacnewton | /pending/node/add/discussion |
      | turing      | /pending/node/add/discussion |
      | alfrednobel | /pending/node/add/discussion |

  @api
  Scenario: Set "Pending group" group state to 'Restricted'. Anonymous user asked to log in.
    Given I am logged in as user "mariecurie"
    When  I change access of group "Pending group" to "Restricted"
    Then  I am an anonymous user
    And   I go to "pending"
    And   I should see "Please log in"

  @api
  Scenario Outline: As site admin, access create content form, with purl prefix of pending restricted group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should have access to the page

    Examples:
      | user        | path                 |
      | mariecurie  | /pending/node/add/photoalbum |
      | mariecurie  | /pending/node/add/photo |
      | mariecurie  | /pending/node/add/event |
      | mariecurie  | /pending/node/add/document |
      | mariecurie  | /pending/node/add/discussion |

  @api
  Scenario Outline: As non member, member, group admin and group owner, access create content form, with purl prefix of pending restricted group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /pending/node/add/photoalbum |
      | isaacnewton | /pending/node/add/photoalbum |
      | turing      | /pending/node/add/photoalbum |
      | alfrednobel | /pending/node/add/photoalbum |
      | badhairday  | /pending/node/add/photo |
      | isaacnewton | /pending/node/add/photo |
      | turing      | /pending/node/add/photo |
      | alfrednobel | /pending/node/add/photo |
      | badhairday  | /pending/node/add/event |
      | isaacnewton | /pending/node/add/event |
      | turing      | /pending/node/add/event |
      | alfrednobel | /pending/node/add/event |
      | badhairday  | /pending/node/add/document |
      | isaacnewton | /pending/node/add/document |
      | turing      | /pending/node/add/document |
      | alfrednobel | /pending/node/add/document |
      | badhairday  | /pending/node/add/discussion |
      | isaacnewton | /pending/node/add/discussion |
      | turing      | /pending/node/add/discussion |
      | alfrednobel | /pending/node/add/discussion |

  @api
  Scenario: Set "Pending group" group state to 'Private'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When   I change access of group "Pending group" to "Private"
    Then   I am an anonymous user
    And    I go to "pending"
    And    I should see "Please log in"

  @api
  Scenario Outline: As site admin, access create content form, with purl prefix of pending private group.
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

  @api
  Scenario Outline: As non member, member, group admin and group owner, access create content form, with purl prefix of pending private group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /pending/node/add/photoalbum |
      | isaacnewton | /pending/node/add/photoalbum |
      | turing      | /pending/node/add/photoalbum |
      | alfrednobel | /pending/node/add/photoalbum |
      | badhairday  | /pending/node/add/photo |
      | isaacnewton | /pending/node/add/photo |
      | turing      | /pending/node/add/photo |
      | alfrednobel | /pending/node/add/photo |
      | badhairday  | /pending/node/add/event |
      | isaacnewton | /pending/node/add/event |
      | turing      | /pending/node/add/event |
      | alfrednobel | /pending/node/add/event |
      | badhairday  | /pending/node/add/document |
      | isaacnewton | /pending/node/add/document |
      | turing      | /pending/node/add/document |
      | alfrednobel | /pending/node/add/document |
      | badhairday  | /pending/node/add/discussion |
      | isaacnewton | /pending/node/add/discussion |
      | turing      | /pending/node/add/discussion |
      | alfrednobel | /pending/node/add/discussion |

  @api
  Scenario: Restore "Pending group" group state to 'Public'.
    Given  I am logged in as user "mariecurie"
    When   I change access of group "Pending group" to "Public"
    And   I am an anonymous user

  @api
  Scenario: Set "Draft group" group state to 'Public'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When   I change access of group "Draft group" to "Public"
    Then   I am an anonymous user
    And    I go to "draft"
    And    I should see "Please log in"

  @api
  Scenario Outline: As member, group admin, group owner and site admin, access create content form, with purl prefix of draft public group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should have access to the page

    Examples:
      | user        | path                 |
      | isaacnewton | /draft/node/add/photoalbum |
      | isaacnewton | /draft/node/add/photo |
      | isaacnewton | /draft/node/add/event |
      | isaacnewton | /draft/node/add/document |
      | isaacnewton | /draft/node/add/discussion |
      | turing      | /draft/node/add/photoalbum |
      | turing      | /draft/node/add/photo |
      | turing      | /draft/node/add/event |
      | turing      | /draft/node/add/document |
      | turing      | /draft/node/add/discussion |
      | alfrednobel  | /draft/node/add/photoalbum |
      | alfrednobel  | /draft/node/add/photo |
      | alfrednobel  | /draft/node/add/event |
      | alfrednobel  | /draft/node/add/document |
      | alfrednobel  | /draft/node/add/discussion |
      | mariecurie  | /draft/node/add/photoalbum |
      | mariecurie  | /draft/node/add/photo |
      | mariecurie  | /draft/node/add/event |
      | mariecurie  | /draft/node/add/document |
      | mariecurie  | /draft/node/add/discussion |

  @api
  Scenario Outline: As non member, access create content form, with purl prefix of draft public group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /draft/node/add/photoalbum |
      | badhairday  | /draft/node/add/photo |
      | badhairday  | /draft/node/add/event |
      | badhairday  | /draft/node/add/document |
      | badhairday  | /draft/node/add/discussion |

  @api
  Scenario: Set "Draft group" group state to 'Restricted'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When   I change access of group "Draft group" to "Restricted"
    Then   I am an anonymous user
    And    I go to "draft"
    And    I should see "Please log in"

  @api
  Scenario Outline:  As member, group admin, group owner and site admin, access create content form, with purl prefix of draft restricted group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should have access to the page

    Examples:
      | user        | path                 |
      | isaacnewton | /draft/node/add/photoalbum |
      | isaacnewton | /draft/node/add/photo |
      | isaacnewton | /draft/node/add/event |
      | isaacnewton | /draft/node/add/document |
      | isaacnewton | /draft/node/add/discussion |
      | turing      | /draft/node/add/photoalbum |
      | turing      | /draft/node/add/photo |
      | turing      | /draft/node/add/event |
      | turing      | /draft/node/add/document |
      | turing      | /draft/node/add/discussion |
      | alfrednobel  | /draft/node/add/photoalbum |
      | alfrednobel  | /draft/node/add/photo |
      | alfrednobel  | /draft/node/add/event |
      | alfrednobel  | /draft/node/add/document |
      | alfrednobel  | /draft/node/add/discussion |
      | mariecurie  | /draft/node/add/photoalbum |
      | mariecurie  | /draft/node/add/photo |
      | mariecurie  | /draft/node/add/event |
      | mariecurie  | /draft/node/add/document |
      | mariecurie  | /draft/node/add/discussion |

  @api
  Scenario Outline: As non member, access create content form, with purl prefix of draft restricted group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /draft/node/add/photoalbum |
      | badhairday  | /draft/node/add/photo |
      | badhairday  | /draft/node/add/event |
      | badhairday  | /draft/node/add/document |
      | badhairday  | /draft/node/add/discussion |

  @api
  Scenario: Set "Draft group" group state to 'Private'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When   I change access of group "Draft group" to "Private"
    Then   I am an anonymous user
    And    I go to "draft"
    And    I should see "Please log in"

  @api
  Scenario Outline: As member, group admin, group owner and site admin, access create content form, with purl prefix of draft private group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should have access to the page

    Examples:
      | user        | path                 |
      | isaacnewton | /draft/node/add/photoalbum |
      | isaacnewton | /draft/node/add/photo |
      | isaacnewton | /draft/node/add/event |
      | isaacnewton | /draft/node/add/document |
      | isaacnewton | /draft/node/add/discussion |
      | turing      | /draft/node/add/photoalbum |
      | turing      | /draft/node/add/photo |
      | turing      | /draft/node/add/event |
      | turing      | /draft/node/add/document |
      | turing      | /draft/node/add/discussion |
      | alfrednobel  | /draft/node/add/photoalbum |
      | alfrednobel  | /draft/node/add/photo |
      | alfrednobel  | /draft/node/add/event |
      | alfrednobel  | /draft/node/add/document |
      | alfrednobel  | /draft/node/add/discussion |
      | mariecurie  | /draft/node/add/photoalbum |
      | mariecurie  | /draft/node/add/photo |
      | mariecurie  | /draft/node/add/event |
      | mariecurie  | /draft/node/add/document |
      | mariecurie  | /draft/node/add/discussion |

  @api
  Scenario Outline: As non member, access create content form, with purl prefix of draft private group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /draft/node/add/photoalbum |
      | badhairday  | /draft/node/add/photo |
      | badhairday  | /draft/node/add/event |
      | badhairday  | /draft/node/add/document |
      | badhairday  | /draft/node/add/discussion |

  @api
  Scenario: Restore "Draft group" group state to 'Public'.
    Given  I am logged in as user "mariecurie"
    When   I change access of group "Draft group" to "Public"
    And   I am an anonymous user

  @api
  Scenario: Set "Published group" group state to 'Public'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When   I change access of group "Published group" to "Public"
    Then   I am an anonymous user
    And    I go to "published"
    And    I should see "Please log in"

  @api
  Scenario Outline: As member, group admin, group owner and site admin, access create content form, with purl prefix of published public group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should have access to the page

    Examples:
      | user        | path                 |
      | isaacnewton | /published/node/add/photoalbum |
      | isaacnewton | /published/node/add/photo |
      | isaacnewton | /published/node/add/event |
      | isaacnewton | /published/node/add/document |
      | isaacnewton | /published/node/add/discussion |
      | turing      | /published/node/add/photoalbum |
      | turing      | /published/node/add/photo |
      | turing      | /published/node/add/event |
      | turing      | /published/node/add/document |
      | turing      | /published/node/add/discussion |
      | alfrednobel  | /published/node/add/photoalbum |
      | alfrednobel  | /published/node/add/photo |
      | alfrednobel  | /published/node/add/event |
      | alfrednobel  | /published/node/add/document |
      | alfrednobel  | /published/node/add/discussion |
      | mariecurie  | /published/node/add/photoalbum |
      | mariecurie  | /published/node/add/photo |
      | mariecurie  | /published/node/add/event |
      | mariecurie  | /published/node/add/document |
      | mariecurie  | /published/node/add/discussion |

  @api
  Scenario Outline: As non member, access create content form, with purl prefix of published public group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /published/node/add/photoalbum |
      | badhairday  | /published/node/add/photo |
      | badhairday  | /published/node/add/event |
      | badhairday  | /published/node/add/document |
      | badhairday  | /published/node/add/discussion |

  @api
  Scenario: Set "Published group" group state to 'Restricted'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When   I change access of group "Published group" to "Restricted"
    Then   I am an anonymous user
    And    I go to "published"
    And    I should see "Please log in"

  @api
  Scenario Outline:  As member, group admin, group owner and site admin, access create content form, with purl prefix of published restricted group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should have access to the page

    Examples:
      | user        | path                 |
      | isaacnewton | /published/node/add/photoalbum |
      | isaacnewton | /published/node/add/photo |
      | isaacnewton | /published/node/add/event |
      | isaacnewton | /published/node/add/document |
      | isaacnewton | /published/node/add/discussion |
      | turing      | /published/node/add/photoalbum |
      | turing      | /published/node/add/photo |
      | turing      | /published/node/add/event |
      | turing      | /published/node/add/document |
      | turing      | /published/node/add/discussion |
      | alfrednobel  | /published/node/add/photoalbum |
      | alfrednobel  | /published/node/add/photo |
      | alfrednobel  | /published/node/add/event |
      | alfrednobel  | /published/node/add/document |
      | alfrednobel  | /published/node/add/discussion |
      | mariecurie  | /published/node/add/photoalbum |
      | mariecurie  | /published/node/add/photo |
      | mariecurie  | /published/node/add/event |
      | mariecurie  | /published/node/add/document |
      | mariecurie  | /published/node/add/discussion |

  @api
  Scenario Outline: As non member, access create content form, with purl prefix of published restricted group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /published/node/add/photoalbum |
      | badhairday  | /published/node/add/photo |
      | badhairday  | /published/node/add/event |
      | badhairday  | /published/node/add/document |
      | badhairday  | /published/node/add/discussion |

  @api
  Scenario: Set "Published group" group state to 'Private'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When   I change access of group "Published group" to "Private"
    Then   I am an anonymous user
    And    I go to "published"
    And    I should see "Please log in"

  @api
  Scenario Outline: As member, group admin, group owner and site admin, access create content form, with purl prefix of published private group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should have access to the page

    Examples:
      | user        | path                 |
      | isaacnewton | /published/node/add/photoalbum |
      | isaacnewton | /published/node/add/photo |
      | isaacnewton | /published/node/add/event |
      | isaacnewton | /published/node/add/document |
      | isaacnewton | /published/node/add/discussion |
      | turing      | /published/node/add/photoalbum |
      | turing      | /published/node/add/photo |
      | turing      | /published/node/add/event |
      | turing      | /published/node/add/document |
      | turing      | /published/node/add/discussion |
      | alfrednobel  | /published/node/add/photoalbum |
      | alfrednobel  | /published/node/add/photo |
      | alfrednobel  | /published/node/add/event |
      | alfrednobel  | /published/node/add/document |
      | alfrednobel  | /published/node/add/discussion |
      | mariecurie  | /published/node/add/photoalbum |
      | mariecurie  | /published/node/add/photo |
      | mariecurie  | /published/node/add/event |
      | mariecurie  | /published/node/add/document |
      | mariecurie  | /published/node/add/discussion |

  @api
  Scenario Outline: As non member, access create content form, with purl prefix of published private group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /published/node/add/photoalbum |
      | badhairday  | /published/node/add/photo |
      | badhairday  | /published/node/add/event |
      | badhairday  | /published/node/add/document |
      | badhairday  | /published/node/add/discussion |


  @api
  Scenario: Restore "Published group" group state to 'Public'.
    Given  I am logged in as user "mariecurie"
    When   I change access of group "Published group" to "Public"
    And   I am an anonymous user

  @api
  Scenario: Set "Archived group" group state to 'Public'. Anonymous user asked to log in.
    Given I am logged in as user "mariecurie"
    When  I change access of group "Archived group" to "Public"
    Then  I am an anonymous user
    And   I go to "archived"
    And   I should see "Please log in"

  @api
  Scenario Outline: As site admin, access create content form, with purl prefix of archived public group.
    Given I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should have access to the page

    Examples:
      | user        | path                 |
      | mariecurie  |  /archived/node/add/photoalbum |
      | mariecurie  |  /archived/node/add/photo |
      | mariecurie  |  /archived/node/add/event |
      | mariecurie  |  /archived/node/add/document |
      | mariecurie  |  /archived/node/add/discussion |

  @api
  Scenario Outline: As non member, member, group admin and group owner, access create content form, with purl prefix of archived public group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /archived/node/add/photoalbum |
      | isaacnewton | /archived/node/add/photoalbum |
      | turing      | /archived/node/add/photoalbum |
      | alfrednobel | /archived/node/add/photoalbum |
      | badhairday  | /archived/node/add/photo |
      | isaacnewton | /archived/node/add/photo |
      | turing      | /archived/node/add/photo |
      | alfrednobel | /archived/node/add/photo |
      | badhairday  | /archived/node/add/event |
      | isaacnewton | /archived/node/add/event |
      | turing      | /archived/node/add/event |
      | alfrednobel | /archived/node/add/event |
      | badhairday  | /archived/node/add/document |
      | isaacnewton | /archived/node/add/document |
      | turing      | /archived/node/add/document |
      | alfrednobel | /archived/node/add/document |
      | badhairday  | /archived/node/add/discussion |
      | isaacnewton | /archived/node/add/discussion |
      | turing      | /archived/node/add/discussion |
      | alfrednobel | /archived/node/add/discussion |

  @api
  Scenario: Set "Archived group" group state to 'Restricted'. Anonymous user asked to log in.
    Given I am logged in as user "mariecurie"
    When  I change access of group "Archived group" to "Restricted"
    Then  I am an anonymous user
    And   I go to "archived"
    And   I should see "Please log in"

  @api
  Scenario Outline: As site admin, access create content form, with purl prefix of archived restricted group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should have access to the page

    Examples:
      | user        | path                 |
      | mariecurie  | /archived/node/add/photoalbum |
      | mariecurie  | /archived/node/add/photo |
      | mariecurie  | /archived/node/add/event |
      | mariecurie  | /archived/node/add/document |
      | mariecurie  | /archived/node/add/discussion |

  @api
  Scenario Outline: As non member, member, group admin and group owner, access create content form, with purl prefix of archived restricted group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /archived/node/add/photoalbum |
      | isaacnewton | /archived/node/add/photoalbum |
      | turing      | /archived/node/add/photoalbum |
      | alfrednobel | /archived/node/add/photoalbum |
      | badhairday  | /archived/node/add/photo |
      | isaacnewton | /archived/node/add/photo |
      | turing      | /archived/node/add/photo |
      | alfrednobel | /archived/node/add/photo |
      | badhairday  | /archived/node/add/event |
      | isaacnewton | /archived/node/add/event |
      | turing      | /archived/node/add/event |
      | alfrednobel | /archived/node/add/event |
      | badhairday  | /archived/node/add/document |
      | isaacnewton | /archived/node/add/document |
      | turing      | /archived/node/add/document |
      | alfrednobel | /archived/node/add/document |
      | badhairday  | /archived/node/add/discussion |
      | isaacnewton | /archived/node/add/discussion |
      | turing      | /archived/node/add/discussion |
      | alfrednobel | /archived/node/add/discussion |

  @api
  Scenario: Set "Archived group" group state to 'Private'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When   I change access of group "Archived group" to "Private"
    Then   I am an anonymous user
    And    I go to "archived"
    And    I should see "Please log in"

  @api
  Scenario Outline: As site admin, access create content form, with purl prefix of archived private group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should have access to the page

    Examples:
      | user        | path                 |
      | mariecurie  | /archived/node/add/photoalbum |
      | mariecurie  | /archived/node/add/photo |
      | mariecurie  | /archived/node/add/event |
      | mariecurie  | /archived/node/add/document |
      | mariecurie  | /archived/node/add/discussion |

  @api
  Scenario Outline: As non member, member, group admin and group owner, access create content form, with purl prefix of archived private group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /archived/node/add/photoalbum |
      | isaacnewton | /archived/node/add/photoalbum |
      | turing      | /archived/node/add/photoalbum |
      | alfrednobel | /archived/node/add/photoalbum |
      | badhairday  | /archived/node/add/photo |
      | isaacnewton | /archived/node/add/photo |
      | turing      | /archived/node/add/photo |
      | alfrednobel | /archived/node/add/photo |
      | badhairday  | /archived/node/add/event |
      | isaacnewton | /archived/node/add/event |
      | turing      | /archived/node/add/event |
      | alfrednobel | /archived/node/add/event |
      | badhairday  | /archived/node/add/document |
      | isaacnewton | /archived/node/add/document |
      | turing      | /archived/node/add/document |
      | alfrednobel | /archived/node/add/document |
      | badhairday  | /archived/node/add/discussion |
      | isaacnewton | /archived/node/add/discussion |
      | turing      | /archived/node/add/discussion |
      | alfrednobel | /archived/node/add/discussion |

  @api
  Scenario: Restore "Archived group" group state to 'Public'.
    Given  I am logged in as user "mariecurie"
    When   I change access of group "Archived group" to "Public"
    And    I am an anonymous user

  @api
  Scenario: Set "Deleted group" group state to 'Public'. Anonymous user asked to log in.
    Given I am logged in as user "mariecurie"
    When  I change access of group "Deleted group" to "Public"
    Then  I am an anonymous user
    And   I go to "deleted"
    And   I should see "Please log in"

  @api
  Scenario Outline: As site admin, access create content form, with purl prefix of deleted public group.
    Given I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should have access to the page

    Examples:
      | user        | path                 |
      | mariecurie  |  /deleted/node/add/photoalbum |
      | mariecurie  |  /deleted/node/add/photo |
      | mariecurie  |  /deleted/node/add/event |
      | mariecurie  |  /deleted/node/add/document |
      | mariecurie  |  /deleted/node/add/discussion |

  @api
  Scenario Outline: As non member, member, group admin and group owner, access create content form, with purl prefix of deleted public group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /deleted/node/add/photoalbum |
      | isaacnewton | /deleted/node/add/photoalbum |
      | turing      | /deleted/node/add/photoalbum |
      | alfrednobel | /deleted/node/add/photoalbum |
      | badhairday  | /deleted/node/add/photo |
      | isaacnewton | /deleted/node/add/photo |
      | turing      | /deleted/node/add/photo |
      | alfrednobel | /deleted/node/add/photo |
      | badhairday  | /deleted/node/add/event |
      | isaacnewton | /deleted/node/add/event |
      | turing      | /deleted/node/add/event |
      | alfrednobel | /deleted/node/add/event |
      | badhairday  | /deleted/node/add/document |
      | isaacnewton | /deleted/node/add/document |
      | turing      | /deleted/node/add/document |
      | alfrednobel | /deleted/node/add/document |
      | badhairday  | /deleted/node/add/discussion |
      | isaacnewton | /deleted/node/add/discussion |
      | turing      | /deleted/node/add/discussion |
      | alfrednobel | /deleted/node/add/discussion |

  @api
  Scenario: Set "Deleted group" group state to 'Restricted'. Anonymous user asked to log in.
    Given I am logged in as user "mariecurie"
    When  I change access of group "Deleted group" to "Restricted"
    Then  I am an anonymous user
    And   I go to "deleted"
    And   I should see "Please log in"

  @api
  Scenario Outline: As site admin, access create content form, with purl prefix of deleted restricted group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should have access to the page

    Examples:
      | user        | path                 |
      | mariecurie  | /deleted/node/add/photoalbum |
      | mariecurie  | /deleted/node/add/photo |
      | mariecurie  | /deleted/node/add/event |
      | mariecurie  | /deleted/node/add/document |
      | mariecurie  | /deleted/node/add/discussion |

  @api
  Scenario Outline: As non member, member, group admin and group owner, access create content form, with purl prefix of deleted restricted group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /deleted/node/add/photoalbum |
      | isaacnewton | /deleted/node/add/photoalbum |
      | turing      | /deleted/node/add/photoalbum |
      | alfrednobel | /deleted/node/add/photoalbum |
      | badhairday  | /deleted/node/add/photo |
      | isaacnewton | /deleted/node/add/photo |
      | turing      | /deleted/node/add/photo |
      | alfrednobel | /deleted/node/add/photo |
      | badhairday  | /deleted/node/add/event |
      | isaacnewton | /deleted/node/add/event |
      | turing      | /deleted/node/add/event |
      | alfrednobel | /deleted/node/add/event |
      | badhairday  | /deleted/node/add/document |
      | isaacnewton | /deleted/node/add/document |
      | turing      | /deleted/node/add/document |
      | alfrednobel | /deleted/node/add/document |
      | badhairday  | /deleted/node/add/discussion |
      | isaacnewton | /deleted/node/add/discussion |
      | turing      | /deleted/node/add/discussion |
      | alfrednobel | /deleted/node/add/discussion |

  @api
  Scenario: Set "Deleted group" group state to 'Private'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When   I change access of group "Deleted group" to "Private"
    Then   I am an anonymous user
    And    I go to "deleted"
    And    I should see "Please log in"

  @api
  Scenario Outline: As site admin, access create content form, with purl prefix of deleted private group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should have access to the page

    Examples:
      | user        | path                 |
      | mariecurie  | /deleted/node/add/photoalbum |
      | mariecurie  | /deleted/node/add/photo |
      | mariecurie  | /deleted/node/add/event |
      | mariecurie  | /deleted/node/add/document |
      | mariecurie  | /deleted/node/add/discussion |

  @api
  Scenario Outline: As non member, member, group admin and group owner, access create content form, with purl prefix of deleted private group.
    Given  I am logged in as user "<user>"
    When   I go to "<path>"
    Then   I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /deleted/node/add/photoalbum |
      | isaacnewton | /deleted/node/add/photoalbum |
      | turing      | /deleted/node/add/photoalbum |
      | alfrednobel | /deleted/node/add/photoalbum |
      | badhairday  | /deleted/node/add/photo |
      | isaacnewton | /deleted/node/add/photo |
      | turing      | /deleted/node/add/photo |
      | alfrednobel | /deleted/node/add/photo |
      | badhairday  | /deleted/node/add/event |
      | isaacnewton | /deleted/node/add/event |
      | turing      | /deleted/node/add/event |
      | alfrednobel | /deleted/node/add/event |
      | badhairday  | /deleted/node/add/document |
      | isaacnewton | /deleted/node/add/document |
      | turing      | /deleted/node/add/document |
      | alfrednobel | /deleted/node/add/document |
      | badhairday  | /deleted/node/add/discussion |
      | isaacnewton | /deleted/node/add/discussion |
      | turing      | /deleted/node/add/discussion |
      | alfrednobel | /deleted/node/add/discussion |

  @api
  Scenario: Restore "Deleted group" group state to 'Public'.
    Given  I am logged in as user "mariecurie"
    When   I change access of group "Deleted group" to "Public"
    And    I am an anonymous user
