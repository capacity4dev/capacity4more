module.exports = function (grunt) {
  var mozjpeg = require('imagemin-mozjpeg');


  grunt.initConfig({
      pkg: grunt.file.readJSON('package.json'),

      /**
       * Set project object
       *
       * Variables:
       * <%= project.src %> : The root path of the project.
       */
      project: {
        src: 'src',
        dst: '../'
      },

      // SCSS
      compass: {
        dev: {
          options: {
            config: 'config.rb',
            outputStyle: 'expanded',
            debugInfo: true,
            environment: 'development',
            sassDir: '<%= project.src %>/sass',
            cssDir: '<%= project.dst %>/css'
          }
        },
        prod: {
          options: {
            config: 'config.rb',
            outputStyle: 'compressed',
            debugInfo: false,
            environment: 'production',
            sassDir: '<%= project.src %>/sass',
            cssDir: '<%= project.dst %>/css'
          }
        }
      },

      // SVG Minification
      svgmin: {
        multiple: {
          files: [
            {
              expand: true,
              cwd: '<%= project.src %>/images/svg/',
              src: ['**/*.svg'],
              dest: '<%= project.dst %>/images/svgmin'
            }
          ]
        }
      },

      // SVG Fallback
      grunticon: {
        icons: {
          files: [
            {
              expand: true,
              cwd: '<%= project.src %>/images/svgmin/icons',
              src: ['**/*.svg'],
              dest: '<%= project.dst %>/images/icons'
            }
          ]
        }
      },

      imagemin: {
        dynamic: {
          options: {
            optimizationLevel: 5,
            svgoPlugins: [{removeViewBox: true}],
            use: [mozjpeg()]
          },
          files: [{
            expand: true,
            src: ['<%= project.dst %>/images/**/*.{png,jpg,gif,jpeg}']
          }]
        }
      },


      // JS
      uglify: {
        options: {
          report: 'min'
        },
        app: {
          files: {
            '<%= project.dst %>/js/kapablo.min.js': [
              '<%= project.src %>/js/app/kapablo.js'
            ]
          }
        },
        bootstrap: {
          files: {
            '<%= project.dst %>/js/bootstrap.min.js': [
              '<%= project.src %>/js/bootstrap/transition.js',
              '<%= project.src %>/js/bootstrap/alert.js',
              '<%= project.src %>/js/bootstrap/button.js',
              '<%= project.src %>/js/bootstrap/carousel.js',
              '<%= project.src %>/js/bootstrap/collapse.js',
              '<%= project.src %>/js/bootstrap/dropdown.js',
              '<%= project.src %>/js/bootstrap/modal.js',
              '<%= project.src %>/js/bootstrap/tooltip.js',
              '<%= project.src %>/js/bootstrap/popover.js',
              '<%= project.src %>/js/bootstrap/scrollspy.js',
              '<%= project.src %>/js/bootstrap/tab.js',
              '<%= project.src %>/js/bootstrap/affix.js']
          }
        }

//            ie7: {
//                src: ['<%= project.src %>/js/app/ie7.js'],
//                dest: '<%= project.src %>/js/<%= pkg.name %>.ie7.min.js'
//            }
      },

      // Detect duplicate CSS rules.
      //csscss: {
      //  options: {
      //    colorize: true,
      //    verbose: true,
      //    outputJson: false,
      //    minMatch: 5,
      //    compass: true,
      //    require: 'config.rb'
      //  },
      //  dist: {
      //    src: '<%= project.dst %>/css/mail.css',
      //    src: '<%= project.dst %>/css/style.css'
      //  }
      //},

      // All the annoying CSS stuff we don't want to do in 1 tool.
      pleeease: {
        custom: {
          options: {
            "browsers": ["ie 8"],
            autoprefixer: {'browsers': ['last 4 versions', 'ios 6']},
            filters: {'oldIE': true},
            minifier: false,
            pseudoElements: true,
            opacity: true,
            mqpacker: true,
            calc: true,
            colors: true
          },
          files: {
            '<%= project.dst %>/css/mail.css': '<%= project.dst %>/css/mail.css',
            '<%= project.dst %>/css/style.css': '<%= project.dst %>/css/style.css'
          }
        }
      },

      // Automate some tasks during development (if files change).
      watch: {
        svg: {
          files: ['<%= project.src %>/images/svg/**/*.svg'],
          tasks: ['svgmin', 'grunticon', 'compass:dev', 'pleeease'],
          options: {
            livereload: true
          }
        },

        style: {
          files: [
            '<%= project.src %>/sass/*.scss',
            '<%= project.src %>/sass/**/*.scss'
          ],
          tasks: ['compass:dev', 'pleeease'],
          options: {
            livereload: true
          }
        },

        scripts: {
          files: ['<%= project.src %>js/app/*.js'],
          tasks: ['uglify:app'],
          options: {
            livereload: true
          }
        }
      }
    }
  )
  ;

  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-contrib-concat');
  grunt.loadNpmTasks('grunt-contrib-uglify');
  grunt.loadNpmTasks('grunt-svgmin');
  grunt.loadNpmTasks('grunt-grunticon');
  grunt.loadNpmTasks('grunt-contrib-compass');
  grunt.loadNpmTasks('grunt-pleeease');
  grunt.loadNpmTasks('grunt-contrib-imagemin');

  grunt.registerTask('dev', [
    'svgmin',
    'grunticon',
    'imagemin',
    'uglify',
    'compass:dev',
    'pleeease',
    'watch'
  ]);

  grunt.registerTask('build', [
    'svgmin',
    'grunticon',
    'imagemin',
    'uglify',
    'compass:prod',
    //'pleeease'
  ]);

  grunt.registerTask('default', [
    'dev'
  ]);
};
