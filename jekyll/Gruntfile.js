// Generated on 2014-06-30 using generator-jekyllrb 1.2.1
'use strict';

// Directory reference:
//   css: css
//   compass: _scss
//   javascript: js
//   images: images
//   fonts: fonts

module.exports = function (grunt) {
  // Show elapsed time after tasks run
  require('time-grunt')(grunt);
  // Load all Grunt tasks
  require('load-grunt-tasks')(grunt);

  grunt.initConfig({
    // Configurable paths
    yeoman: {
      app: 'app',
      dist: 'dist'
    },
    watch: {
      compass: {
        files: ['<%= yeoman.app %>/_scss/**/*.{scss,sass}'],
        tasks: ['compass:server', 'autoprefixer:server']
      },
      autoprefixer: {
        files: ['<%= yeoman.app %>/css/**/*.css'],
        tasks: ['copy:stageCss', 'autoprefixer:server']
      },
      jekyll: {
        files: [
          '<%= yeoman.app %>/**/*.{html,yml,md,mkd,markdown}',
          '!<%= yeoman.app %>/_bower_components/**/*'
        ],
        tasks: ['jekyll:server']
      },
      livereload: {
        options: {
          livereload: '<%= connect.options.livereload %>'
        },
        files: [
          '.jekyll/**/*.html',
          '.tmp/css/**/*.css',
          '{.tmp,<%= yeoman.app %>}/<%= js %>/**/*.js',
          '<%= yeoman.app %>/images/**/*.{gif,jpg,jpeg,png,svg,webp}'
        ]
      }
    },
    connect: {
      options: {
        port: 9000,
        livereload: 35729,
        // change this to '0.0.0.0' to access the server from outside
        hostname: 'localhost'
      },
      livereload: {
        options: {
          open: true,
          base: [
            '.tmp',
            '.jekyll',
            '<%= yeoman.app %>'
          ]
        }
      },
      dist: {
        options: {
          open: true,
          base: [
            '<%= yeoman.dist %>'
          ]
        }
      },
      test: {
        options: {
          base: [
            '.tmp',
            '.jekyll',
            'test',
            '<%= yeoman.app %>'
          ]
        }
      }
    },
    clean: {
      dist: {
        files: [{
          dot: true,
          src: [
            '<%= yeoman.dist %>/*',
            // Running Jekyll also cleans the target directory.  Exclude any
            // non-standard `keep_files` here (e.g., the generated files
            // directory from Jekyll Picture Tag).
            '!<%= yeoman.dist %>/.git*'
          ]
        }]
      },
      server: [
        '.tmp',
        '.jekyll'
      ]
    },
    compass: {
      options: {
        // If you're using global Sass gems, require them here.
        // require: ['singularity', 'jacket'],
        bundleExec: true,
        sassDir: '<%= yeoman.app %>/_scss',
        cssDir: '.tmp/css',
        imagesDir: '<%= yeoman.app %>/images',
        javascriptsDir: '<%= yeoman.app %>/js',
        relativeAssets: false,
        httpImagesPath: '/images',
        httpGeneratedImagesPath: '/images/generated',
        outputStyle: 'expanded',
        raw: 'extensions_dir = "<%= yeoman.app %>/_bower_components"\n',
        // Allow using @import in the sass files.
        importPath: '<%= yeoman.app %>/_bower_components'
      },
      dist: {
        options: {
          generatedImagesDir: '<%= yeoman.dist %>/images/generated'
        }
      },
      server: {
        options: {
          debugInfo: true,
          generatedImagesDir: '.tmp/images/generated'
        }
      }
    },
    autoprefixer: {
      options: {
        browsers: ['last 2 versions']
      },
      dist: {
        files: [{
          expand: true,
          cwd: '<%= yeoman.dist %>/css',
          src: '**/*.css',
          dest: '<%= yeoman.dist %>/css'
        }]
      },
      server: {
        files: [{
          expand: true,
          cwd: '.tmp/css',
          src: '**/*.css',
          dest: '.tmp/css'
        }]
      }
    },
    jekyll: {
      options: {
        bundleExec: true,
        config: '_config.yml,_config.build.yml',
        src: '<%= yeoman.app %>'
      },
      dist: {
        options: {
          dest: '<%= yeoman.dist %>',
        }
      },
      server: {
        options: {
          config: '_config.yml',
          dest: '.jekyll'
        }
      },
      check: {
        options: {
          doctor: true
        }
      }
    },
    useminPrepare: {
      options: {
        dest: '<%= yeoman.dist %>'
      },
      html: '<%= yeoman.dist %>/index.html'
    },
    usemin: {
      options: {
        assetsDirs: '<%= yeoman.dist %>',
      },
      html: ['<%= yeoman.dist %>/**/*.html'],
      css: ['<%= yeoman.dist %>/css/**/*.css']
    },
    htmlmin: {
      dist: {
        options: {
          collapseWhitespace: true,
          collapseBooleanAttributes: true,
          removeAttributeQuotes: true,
          removeRedundantAttributes: true
        },
        files: [{
          expand: true,
          cwd: '<%= yeoman.dist %>',
          src: '**/*.html',
          dest: '<%= yeoman.dist %>'
        }]
      }
    },
    // Usemin adds files to concat
    concat: {},
    // Usemin adds files to uglify
    uglify: {},
    // Usemin adds files to cssmin
    cssmin: {
      dist: {
        options: {
          check: 'gzip'
        }
      }
    },
    imagemin: {
      dist: {
        options: {
          progressive: true
        },
        files: [{
          expand: true,
          cwd: '<%= yeoman.dist %>',
          src: '**/*.{jpg,jpeg,png}',
          dest: '<%= yeoman.dist %>'
        }]
      }
    },
    svgmin: {
      dist: {
        files: [{
          expand: true,
          cwd: '<%= yeoman.dist %>',
          src: '**/*.svg',
          dest: '<%= yeoman.dist %>'
        }]
      }
    },
    copy: {
      dist: {
        files: [{
          expand: true,
          dot: true,
          cwd: '<%= yeoman.app %>',
          src: [
            // Jekyll processes and moves HTML and text files.
            // Usemin moves CSS and javascript inside of Usemin blocks.
            // Copy moves asset files and directories.
            'images/**/*',
            'fonts/**/*',
            // Like Jekyll, exclude files & folders prefixed with an underscore.
            '!**/_*{,/**}'
            // Explicitly add any files your site needs for distribution here.
            //'_bower_components/jquery/jquery.js',
            //'favicon.ico',
            //'apple-touch*.png'
          ],
          dest: '<%= yeoman.dist %>'
        }]
      },
      // Copy CSS into .tmp directory for Autoprefixer processing
      stageCss: {
        files: [{
          expand: true,
          dot: true,
          cwd: '<%= yeoman.app %>/css',
          src: '**/*.css',
          dest: '.tmp/css'
        }]
      }
    },
    filerev: {
      options: {
        length: 4
      },
      dist: {
        files: [{
          src: [
            '<%= yeoman.dist %>/js/**/*.js',
            '<%= yeoman.dist %>/css/**/*.css',
            '<%= yeoman.dist %>/images/**/*.{gif,jpg,jpeg,png,svg,webp}',
            '<%= yeoman.dist %>/fonts/**/*.{eot*,otf,svg,ttf,woff}'
          ]
        }]
      }
    },
    buildcontrol: {
      dist: {
        options: {
          remote: 'git@github.com:capacity4dev/capacity4more.git',
          branch: 'gh-pages',
          commit: true,
          push: true
        }
      }
    },
    jshint: {
      options: {
        jshintrc: '.jshintrc',
        reporter: require('jshint-stylish')
      },
      all: [
        'Gruntfile.js',
        '<%= yeoman.app %>/js/**/*.js',
        'test/spec/**/*.js'
      ]
    },
    csslint: {
      options: {
        csslintrc: '.csslintrc'
      },
      check: {
        src: [
          '<%= yeoman.app %>/css/**/*.css',
          '<%= yeoman.app %>/_scss/**/*.scss'
        ]
      }
    },
    concurrent: {
      server: [
        'compass:server',
        'copy:stageCss',
        'jekyll:server'
      ],
      dist: [
        'compass:dist',
        'copy:dist'
      ]
    }
  });

  // Define Tasks
  grunt.registerTask('serve', function (target) {
    if (target === 'dist') {
      return grunt.task.run(['build', 'connect:dist:keepalive']);
    }

    grunt.task.run([
      'clean:server',
      'concurrent:server',
      'autoprefixer:server',
      'connect:livereload',
      'watch'
    ]);
  });

  grunt.registerTask('server', function () {
    grunt.log.warn('The `server` task has been deprecated. Use `grunt serve` to start a server.');
    grunt.task.run(['serve']);
  });

  // No real tests yet. Add your own.
  grunt.registerTask('test', [
  //   'clean:server',
  //   'concurrent:test',
  //   'connect:test'
  ]);

  grunt.registerTask('check', [
    'clean:server',
    'jekyll:check',
    'compass:server'
    // 'jshint:all',
    // 'csslint:check'
  ]);

  grunt.registerTask('build', [
    'clean',
    // Jekyll cleans files from the target directory, so must run first
    'jekyll:dist',
    'concurrent:dist',
    'useminPrepare',
    'concat',
    'autoprefixer:dist',
    'cssmin',
    'uglify',
    'imagemin',
    'svgmin',
    // 'filerev',
    'usemin',
    'htmlmin'
    ]);

  grunt.registerTask('deploy', [
    'check',
    'test',
    'build',
    'buildcontrol'
    ]);

  grunt.registerTask('default', [
    'check',
    'test',
    'build'
  ]);
};
