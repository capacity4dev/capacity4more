<?php

/**
 * @file
 * c4m_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ('current_search' == $module && 'current_search' == $api) {
    return array('version' => 1);
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function c4m_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function c4m_search_default_search_api_index() {
  $items = array();
  $items['c4m_search_comments'] = entity_import('search_api_index', '{
    "name" : "Search Comments",
    "machine_name" : "c4m_search_comments",
    "description" : "Search index for all comments.",
    "server" : "c4m_solr",
    "item_type" : "comment",
    "options" : {
      "datasource" : { "bundles" : [
          "comment_node_article",
          "comment_node_banner",
          "comment_node_book",
          "comment_node_discussion",
          "comment_node_document",
          "comment_node_event",
          "comment_node_featured",
          "comment_node_feed",
          "comment_node_group",
          "comment_node_inthe_picture",
          "comment_node_news",
          "comment_node_organisation",
          "comment_node_page_element",
          "comment_node_photo",
          "comment_node_photoalbum",
          "comment_node_project",
          "comment_node_share",
          "comment_node_topic",
          "comment_node_wiki_page"
        ]
      },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "author:uid" : { "type" : "integer" },
        "cid" : { "type" : "integer" },
        "comment_body:format" : { "type" : "string" },
        "comment_body:value" : { "type" : "text" },
        "created" : { "type" : "date" },
        "node:c4m_vocab_topic" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:title" : { "type" : "text" },
        "node:type" : { "type" : "string" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "search_api_viewed" : { "type" : "text" },
        "status" : { "type" : "boolean" },
        "subject" : { "type" : "text" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_comment_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_attachments_alter_settings" : {
          "status" : 0,
          "weight" : "0",
          "settings" : {
            "excluded_extensions" : "aif art avi bmp gif ico mov oga ogv png psd ra ram rgb flv",
            "number_indexed" : "0",
            "max_file_size" : "0",
            "excluded_private" : 1
          }
        },
        "search_api_alter_add_hierarchy" : { "status" : 1, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 1, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "status" : true, "author:uid" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : [],
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : { "status" : 1, "weight" : "15", "settings" : { "fields" : [] } },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "entity_type" : "search_api_index",
    "rdf_mapping" : []
  }');
  $items['c4m_search_nodes'] = entity_import('search_api_index', '{
    "name" : "Search Nodes",
    "machine_name" : "c4m_search_nodes",
    "description" : "Search index for all nodes.",
    "server" : "c4m_solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "article" : "article",
              "discussion" : "discussion",
              "document" : "document",
              "event" : "event",
              "feed" : "feed",
              "group" : "group",
              "news" : "news",
              "photo" : "photo",
              "photoalbum" : "photoalbum",
              "project" : "project",
              "wiki_page" : "wiki_page"
            }
          }
        },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_attachments_alter_settings" : {
          "status" : 1,
          "weight" : "0",
          "settings" : {
            "excluded_extensions" : "aif art avi bmp gif ico mov oga ogv png psd ra ram rgb flv",
            "number_indexed" : "0",
            "max_file_size" : "0",
            "excluded_private" : 1
          }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "c4m_vocab_geo:parents_all" : "c4m_vocab_geo:parents_all",
              "og_vocabulary:parents_all" : "og_vocabulary:parents_all"
            }
          }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "c4m_organised_by" : true,
              "c4m_cris_contract_number" : true,
              "c4m_cris_decision_number" : true,
              "c4m_partner" : true,
              "c4m_source_of_funding" : true,
              "body:value" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "c4m_organised_by" : true,
              "c4m_cris_contract_number" : true,
              "c4m_cris_decision_number" : true,
              "c4m_partner" : true,
              "c4m_source_of_funding" : true,
              "body:value" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 1,
          "weight" : "15",
          "settings" : { "fields" : {
              "title" : true,
              "c4m_organised_by" : true,
              "c4m_cris_contract_number" : true,
              "c4m_cris_decision_number" : true,
              "c4m_partner" : true,
              "c4m_source_of_funding" : true,
              "body:value" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "c4m_organised_by" : true,
              "c4m_cris_contract_number" : true,
              "c4m_cris_decision_number" : true,
              "c4m_partner" : true,
              "c4m_source_of_funding" : true,
              "body:value" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "c4m_organised_by" : true,
              "c4m_cris_contract_number" : true,
              "c4m_cris_decision_number" : true,
              "c4m_partner" : true,
              "c4m_source_of_funding" : true,
              "body:value" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      },
      "fields" : {
        "attachments_c4m_document" : { "type" : "text" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "c4m_body:value" : { "type" : "text", "boost" : "3.0" },
        "c4m_cris_contract_number" : { "type" : "list\\u003Ctext\\u003E" },
        "c4m_cris_decision_number" : { "type" : "list\\u003Ctext\\u003E" },
        "c4m_datetime_end:duration" : { "type" : "duration" },
        "c4m_datetime_end:value" : { "type" : "date" },
        "c4m_datetime_end:value2" : { "type" : "date" },
        "c4m_discussion_type" : { "type" : "string" },
        "c4m_document_add_to_library" : { "type" : "boolean" },
        "c4m_document_agenda" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "c4m_document_presentation" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "c4m_event_type" : { "type" : "string" },
        "c4m_is_template" : { "type" : "boolean" },
        "c4m_og_group_access_type" : { "type" : "string" },
        "c4m_og_group_type" : { "type" : "string" },
        "c4m_og_status" : { "type" : "string" },
        "c4m_organised_by" : { "type" : "text" },
        "c4m_photo_is_part_of_photo_album" : { "type" : "boolean" },
        "c4m_project_stage" : { "type" : "string" },
        "c4m_project_type" : { "type" : "string" },
        "c4m_related_topic" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "c4m_related_user" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "user" },
        "c4m_source_entity" : { "type" : "integer", "entity_type" : "node" },
        "c4m_source_of_funding" : { "type" : "list\\u003Ctext\\u003E" },
        "c4m_vocab_date" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "c4m_vocab_document_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "c4m_vocab_geo" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "c4m_vocab_language" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "c4m_vocab_theme" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "c4m_vocab_topic" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "c4m_vocab_topic:name" : { "type" : "list\\u003Ctext\\u003E", "boost" : "13.0" },
        "changed" : { "type" : "date" },
        "comment_count" : { "type" : "integer" },
        "created" : { "type" : "date" },
        "flag_c4m_og_content_recommend_count" : { "type" : "integer" },
        "group_group" : { "type" : "boolean" },
        "is_new" : { "type" : "boolean" },
        "nid" : { "type" : "integer" },
        "og_group_ref" : { "type" : "integer", "entity_type" : "node" },
        "og_vocabulary" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "promote" : { "type" : "boolean" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "type" : { "type" : "string" },
        "views" : { "type" : "integer" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "entity_type" : "search_api_index",
    "rdf_mapping" : []
  }');
  $items['c4m_search_users'] = entity_import('search_api_index', '{
    "name" : "Search Users",
    "machine_name" : "c4m_search_users",
    "description" : null,
    "server" : "c4m_solr",
    "item_type" : "user",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "c4m_body:value" : { "type" : "text" },
        "c4m_country" : { "type" : "string" },
        "c4m_first_name" : { "type" : "string" },
        "c4m_is_deleted" : { "type" : "boolean" },
        "c4m_is_spammer" : { "type" : "boolean" },
        "c4m_job_title" : { "type" : "text" },
        "c4m_last_name" : { "type" : "string" },
        "c4m_og_membership_type" : { "type" : "list\\u003Cstring\\u003E" },
        "c4m_organisation" : { "type" : "string" },
        "c4m_organisation_type" : { "type" : "string" },
        "c4m_user_contributions" : { "type" : "integer" },
        "c4m_vocab_geo" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "c4m_vocab_topic" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "c4m_vocab_topic_expertise" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "created" : { "type" : "date" },
        "mail" : { "type" : "text" },
        "name" : { "type" : "text" },
        "og_membership__1" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "og_membership" },
        "search_api_aggregation_1" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "uid" : { "type" : "integer" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_role_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "roles" : [] }
        },
        "search_api_alter_user_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_attachments_alter_settings" : {
          "status" : 0,
          "weight" : "0",
          "settings" : {
            "excluded_extensions" : "aif art avi bmp gif ico mov oga ogv png psd ra ram rgb flv",
            "number_indexed" : "0",
            "max_file_size" : "0",
            "excluded_private" : 1
          }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "c4m_user_fullname",
                "type" : "fulltext",
                "fields" : [ "c4m_first_name", "c4m_last_name" ],
                "description" : "A Fulltext aggregation of the following fields: First Name, Last Name."
              }
            }
          }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "name" : true,
              "mail" : true,
              "c4m_vocab_geo" : true,
              "c4m_vocab_topic" : true,
              "c4m_vocab_topic_expertise" : true,
              "c4m_country" : true,
              "c4m_first_name" : true,
              "c4m_last_name" : true,
              "c4m_organisation" : true,
              "c4m_organisation_type" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "name" : true,
              "mail" : true,
              "c4m_organisation_type" : true,
              "c4m_first_name" : true,
              "c4m_job_title" : true,
              "c4m_last_name" : true,
              "c4m_organisation" : true,
              "c4m_body:value" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 1,
          "weight" : "15",
          "settings" : { "fields" : {
              "name" : true,
              "mail" : true,
              "c4m_organisation_type" : true,
              "c4m_first_name" : true,
              "c4m_job_title" : true,
              "c4m_last_name" : true,
              "c4m_organisation" : true,
              "c4m_body:value" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "name" : true, "mail" : true, "c4m_organisation" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "name" : true,
              "mail" : true,
              "c4m_first_name" : true,
              "c4m_last_name" : true,
              "c4m_organisation" : true,
              "c4m_organisation_type" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "entity_type" : "search_api_index",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_sort().
 */
function c4m_search_default_search_api_sort() {
  $items = array();
  $items['c4m_search_comments__created'] = entity_import('search_api_sort', '{
    "index_id" : "c4m_search_comments",
    "field" : "created",
    "name" : "Date created",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "c4m_search_comments__created",
    "default_sort" : "1",
    "default_sort_no_terms" : "1",
    "default_order" : "desc",
    "options" : { "field_name" : "Date created" },
    "entity_type" : "search_api_sort",
    "rdf_mapping" : []
  }');
  $items['c4m_search_nodes__c4m_datetime_end:value'] = entity_import('search_api_sort', '{
    "index_id" : "c4m_search_nodes",
    "field" : "c4m_datetime_end:value",
    "name" : "Start Date",
    "enabled" : "1",
    "weight" : "-100",
    "identifier" : "c4m_search_nodes__c4m_datetime_end:value",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "asc",
    "options" : { "field_name" : "Date \\u00bb Start date" },
    "entity_type" : "search_api_sort",
    "rdf_mapping" : []
  }');
  $items['c4m_search_nodes__comment_count'] = entity_import('search_api_sort', '{
    "index_id" : "c4m_search_nodes",
    "field" : "comment_count",
    "name" : "Comment count",
    "enabled" : "1",
    "weight" : "-99",
    "identifier" : "c4m_search_nodes__comment_count",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "Comment count" },
    "entity_type" : "search_api_sort",
    "rdf_mapping" : []
  }');
  $items['c4m_search_nodes__created'] = entity_import('search_api_sort', '{
    "index_id" : "c4m_search_nodes",
    "field" : "created",
    "name" : "Date created",
    "enabled" : "1",
    "weight" : "-98",
    "identifier" : "c4m_search_nodes__created",
    "default_sort" : "0",
    "default_sort_no_terms" : "1",
    "default_order" : "desc",
    "options" : { "field_name" : "Date created" },
    "entity_type" : "search_api_sort",
    "rdf_mapping" : []
  }');
  $items['c4m_search_nodes__flag_c4m_og_content_recommend_count'] = entity_import('search_api_sort', '{
    "index_id" : "c4m_search_nodes",
    "field" : "flag_c4m_og_content_recommend_count",
    "name" : "Recommendations",
    "enabled" : "1",
    "weight" : "-95",
    "identifier" : "c4m_search_nodes__flag_c4m_og_content_recommend_count",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "The flag count of type c4m_og_content_recommend for an inthe_picture entity" },
    "entity_type" : "search_api_sort",
    "rdf_mapping" : []
  }');
  $items['c4m_search_nodes__search_api_relevance'] = entity_import('search_api_sort', '{
    "index_id" : "c4m_search_nodes",
    "field" : "search_api_relevance",
    "name" : "Relevance",
    "enabled" : "1",
    "weight" : "-97",
    "identifier" : "c4m_search_nodes__search_api_relevance",
    "default_sort" : "1",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "search_api_relevance" },
    "entity_type" : "search_api_sort",
    "rdf_mapping" : []
  }');
  $items['c4m_search_nodes__views'] = entity_import('search_api_sort', '{
    "index_id" : "c4m_search_nodes",
    "field" : "views",
    "name" : "Number of views",
    "enabled" : "1",
    "weight" : "-96",
    "identifier" : "c4m_search_nodes__views",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "Number of views" },
    "entity_type" : "search_api_sort",
    "rdf_mapping" : []
  }');
  $items['c4m_search_users__c4m_first_name'] = entity_import('search_api_sort', '{
    "index_id" : "c4m_search_users",
    "field" : "c4m_first_name",
    "name" : "First Name",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "c4m_search_users__c4m_first_name",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "asc",
    "options" : { "field_name" : "First Name" },
    "entity_type" : "search_api_sort",
    "rdf_mapping" : []
  }');
  $items['c4m_search_users__c4m_last_name'] = entity_import('search_api_sort', '{
    "index_id" : "c4m_search_users",
    "field" : "c4m_last_name",
    "name" : "Last Name",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "c4m_search_users__c4m_last_name",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "asc",
    "options" : { "field_name" : "Last Name" },
    "entity_type" : "search_api_sort",
    "rdf_mapping" : []
  }');
  $items['c4m_search_users__c4m_user_contributions'] = entity_import('search_api_sort', '{
    "index_id" : "c4m_search_users",
    "field" : "c4m_user_contributions",
    "name" : "Number of activity",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "c4m_search_users__c4m_user_contributions",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "Total number of contributions of the user (posts + comments)" },
    "entity_type" : "search_api_sort",
    "rdf_mapping" : []
  }');
  $items['c4m_search_users__created'] = entity_import('search_api_sort', '{
    "index_id" : "c4m_search_users",
    "field" : "created",
    "name" : "Date of registration",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "c4m_search_users__created",
    "default_sort" : "1",
    "default_sort_no_terms" : "1",
    "default_order" : "desc",
    "options" : { "field_name" : "Created" },
    "entity_type" : "search_api_sort",
    "rdf_mapping" : []
  }');
  return $items;
}
