module.exports = function (grunt) {
  var mozjpeg = require('imagemin-mozjpeg');


  grunt.initConfig({
      pkg: grunt.file.readJSON('package.json'),

      /**
       * Set project object
       *
       * Variables:
       * <%= project.root %> : The root path of the project.
       */
      project: {
        root: '../../../capacity4more/themes/c4m/kapablo'
      },

      // SCSS
      compass: {
        dev: {
          options: {
            config: 'config.rb',
            outputStyle: 'expanded',
            debugInfo: true,
            environment: 'development',
            sassDir: '<%= project.root %>/sass',
            cssDir: '<%= project.root %>/css'
          }
        },
        prod: {
          options: {
            config: 'config.rb',
            outputStyle: 'compressed',
            debugInfo: false,
            environment: 'production',
            sassDir: '<%= project.root %>/sass',
            cssDir: '<%= project.root %>/css'
          }
        }
      },

      // SVG Minification
      svgmin: {
        multiple: {
          files: [
            {
              expand: true,
              cwd: '<%= project.root %>/images/svg/',
              src: ['**/*.svg'],
              dest: '<%= project.root %>/images/svgmin'
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
              cwd: '<%= project.root %>/images/svgmin/icons',
              src: ['**/*.svg'],
              dest: '<%= project.root %>/images/icons'
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
            src: ['<%= project.root %>/images/**/*.{png,jpg,gif,jpeg}']
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
            '<%= project.root %>/js/kapablo.min.js': [
              '<%= project.root %>/js/app/kapablo.js'
            ]
          }
        },
        bootstrap: {
          files: {
            '<%= project.root %>/js/bootstrap.min.js': [
              '<%= project.root %>/js/bootstrap/transition.js',
              '<%= project.root %>/js/bootstrap/alert.js',
              '<%= project.root %>/js/bootstrap/button.js',
              '<%= project.root %>/js/bootstrap/carousel.js',
              '<%= project.root %>/js/bootstrap/collapse.js',
              '<%= project.root %>/js/bootstrap/dropdown.js',
              '<%= project.root %>/js/bootstrap/modal.js',
              '<%= project.root %>/js/bootstrap/tooltip.js',
              '<%= project.root %>/js/bootstrap/popover.js',
              '<%= project.root %>/js/bootstrap/scrollspy.js',
              '<%= project.root %>/js/bootstrap/tab.js',
              '<%= project.root %>/js/bootstrap/affix.js']
          }
        }

//            ie7: {
//                src: ['<%= project.root %>/js/app/ie7.js'],
//                dest: '<%= project.root %>/js/<%= pkg.name %>.ie7.min.js'
//            }
      },

      // Detect duplicate CSS rules.
      csscss: {
        options: {
          colorize: true,
          verbose: true,
          outputJson: false,
          minMatch: 5,
          compass: true,
          require: 'config.rb'
        },
        dist: {
          src: '<%= project.root %>/css/mail.css',
          src: '<%= project.root %>/css/style.css'
        }
      },

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
            '<%= project.root %>/css/mail.css': '<%= project.root %>/css/mail.css',
            '<%= project.root %>/css/style.css': '<%= project.root %>/css/style.css'
          }
        }
      },

      // Automate some tasks during development (if files change).
      watch: {
        svg: {
          files: ['<%= project.root %>/images/svg/**/*.svg'],
          tasks: ['svgmin', 'grunticon', 'compass:dev', 'pleeease'],
          options: {
            livereload: true
          }
        },

        style: {
          files: [
            '<%= project.root %>/sass/*.scss',
            '<%= project.root %>/sass/**/*.scss'
          ],
          tasks: ['compass:dev', 'pleeease'],
          options: {
            livereload: true
          }
        },

        scripts: {
          files: ['<%= project.root %>js/app/*.js'],
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
  grunt.loadNpmTasks('grunt-csscss');
  grunt.loadNpmTasks('grunt-pleeease');
  grunt.loadNpmTasks('grunt-contrib-imagemin');

  grunt.registerTask('dev', [
    'svgmin',
    'grunticon',
    'imagemin',
    'uglify',
    'compass:dev',
    'pleeease',
    'csscss',
    'watch'
  ]);

  grunt.registerTask('build', [
    'svgmin',
    'grunticon',
    'imagemin',
    'uglify',
    'compass:prod',
    'pleeease'
  ]);

  grunt.registerTask('default', [
    'dev'
  ]);
};
