Search API Attachments

This module will extract the content out of attached files using the Tika
library or the build in Solr extractor and index it.
Search API attachments will index many file formats, including PDF's, MS Office,
MP3 (ID3 tags), JPEG Metadata, ...

The module was tested with Apache Solr, however it should work on all Search API
search servers.
Database Search gives errors on saving but should work
(Core Issue: http://drupal.org/node/1007830)

More information:
http://tika.apache.org/download.html

REQUIREMENTS
------------

Requires the ability to run java on your server and an installation of the
Apache Tika library if you don't want to use the Solr build in extractor.

PHP-iconv to index txt files.

MODULE INSTALLATION
-------------------
Copy search_api_attachments into your modules folder

Install the search_api_attachments module in your Drupal site

Go to the configuration: admin/config/search/search_api/attachments

Choose an extraction method and follow the instructions under the respective
heading below.


EXTRACTION CONFIGURATION (Tika)
-------------------------------
On Ubuntu 10.10

Install java
> sudo apt-get install openjdk-6-jdk

Download Apache Tika library: http://tika.apache.org/download.html
> wget http://mir2.ovh.net/ftp.apache.org/dist/tika/tika-app-1.4.jar

Enter the full path on your server where you downloaded the jar
e.g. /var/apache-tika/ and the name of the jar file e.g. tika-app-1.4.jar

EXTRACTION CONFIGURATION (Solr)
-------------------------------
This requires 1.0-RC5 or newer of the 'Search API Solr' module (namely for issue
#1986284) and the Solr config files that come with it.

If you're just using the 'example' application with the built-in Jetty server,
you can skip straight to editing your solrconfig.xml file. Libraries should
automatically be loaded.

Before continuing, download and extract the Solr package for your particular
release, if you don't have it already, e.g.
> wget http://apache.mirror.serversaustralia.com.au/lucene/solr/3.6.2/apache-solr-3.6.2.tgz
> tar xvzf apache-solr-3.6.2.tgz

In the below instructions, replace '$SOLR_HOME' with your Solr home directory.

From the Solr package, copy the 'dist/' and 'lib/' directories into your solr
home directory, e.g.:
> cp -R apache-solr-3.6.2/dist $SOLR_HOME/
> cp -R apache-solr-3.6.2/contrib/extraction/lib $SOLR_HOME/

Then edit the 'solrconfig.xml' file:
> nano $SOLR_HOME/conf/solrconfig.xml

And add the following line:
<lib dir="./dist/" regex="apache-solr-cell-\d.*\.jar" />

Then restart Tomcat/Jetty.

SUBMODULES
-------------------------------
search_api_attachments_field_collections: More details in contrib folder.

CACHING
-------
Extracting files content can take a long time and it may not be needed to do it
again each time a node gets reindexed.
search_api_attachments have a cahe bin where we store all the extracted files
contents: this is the cache_search_api_attachments table.
cache its are in the form of: 'cached_extraction_[fid]' where [fid] is the file
id.
When a file is deleted or updated, we drop its extracted stored cache.
Whend the sidewide cache is deleted (drush cc all per example) we drop all the
stored extracted files cache only if 'Preserve cached extractions across cache
 clears.' option is unchecked in the configuration form of the module.