Feature: Group Status
  Test group status field

  @api
  Scenario: Check requested group as admin
    Given I am logged in as user "mariecurie"
    When  I start editing group "Requested group"
    Then  the "#edit-c4m-og-status-und" element should not contain "archived"
    And   the "#edit-c4m-og-status-und" element should not contain "published"

  @api
  Scenario: Check requested group as group owner
    Given I am logged in as user "alfrednobel"
    When  I start editing group "Requested group"
    Then  the "#edit-c4m-og-status-und" element should not contain "rejected"
    And   the "#edit-c4m-og-status-und" element should not contain "draft"
    And   the "#edit-c4m-og-status-und" element should not contain "published"
    And   the "#edit-c4m-og-status-und" element should not contain "archived"

  @api
  Scenario: Check rejected group group as admin
    Given I am logged in as user "mariecurie"
    When  I start editing group "Rejected group"
    Then  the "#edit-c4m-og-status-und" element should not contain "requested"
    And   the "#edit-c4m-og-status-und" element should not contain "draft"
    And   the "#edit-c4m-og-status-und" element should not contain "published"
    And   the "#edit-c4m-og-status-und" element should not contain "archived"

  @api
  Scenario: Check rejected group group as group owner
    Given I am logged in as user "alfrednobel"
    When  I start editing group "Rejected group"
    Then  I should not see an "#edit-c4m-og-status-und" element

  @api
  Scenario: Check draft group as admin
    Given I am logged in as user "mariecurie"
    When  I start editing group "Draft group"
    Then  the "#edit-c4m-og-status-und" element should not contain "archived"
    And   the "#edit-c4m-og-status-und" element should not contain "rejected"
    And   the "#edit-c4m-og-status-und" element should not contain "requested"

  @api
  Scenario: Check draft group as group owner
    Given I am logged in as user "alfrednobel"
    When  I start editing group "Draft group"
    Then  the "#edit-c4m-og-status-und" element should not contain "rejected"
    And   the "#edit-c4m-og-status-und" element should not contain "requested"
    And   the "#edit-c4m-og-status-und" element should not contain "archived"

  @api
  Scenario: Check published group as admin
    Given I am logged in as user "mariecurie"
    When  I start editing group "Published group"
    Then  the "#edit-c4m-og-status-und" element should not contain "rejected"
    And   the "#edit-c4m-og-status-und" element should not contain "requested"

  @api
  Scenario: Check published group as group owner
    Given I am logged in as user "alfrednobel"
    When  I start editing group "Published group"
    Then  the "#edit-c4m-og-status-und" element should not contain "rejected"
    And   the "#edit-c4m-og-status-und" element should not contain "requested"
    And   the "#edit-c4m-og-status-und" element should not contain "draft"

  @api
  Scenario: Check archived group as admin
    Given I am logged in as user "mariecurie"
    When  I start editing group "Archived group"
    Then  the "#edit-c4m-og-status-und" element should not contain "rejected"
    And   the "#edit-c4m-og-status-und" element should not contain "requested"
    And   the "#edit-c4m-og-status-und" element should not contain "draft"

  @api
  Scenario: Check archived group as group owner
    Given I am logged in as user "alfrednobel"
    When  I start editing group "Archived group"
    Then  I should not see an "#edit-c4m-og-status-und" element

  @api
  Scenario: Check deleted group as admin
    Given I am logged in as user "mariecurie"
    When  I start editing group "Deleted group"
    Then  the "#edit-c4m-og-status-und" element should not contain "rejected"
    And   the "#edit-c4m-og-status-und" element should not contain "requested"

  @api
  Scenario: Check deleted group as group owner
    Given I am logged in as user "alfrednobel"
    When  I start editing group "Deleted group"
    Then  I should not see an "#edit-c4m-og-status-und" element
