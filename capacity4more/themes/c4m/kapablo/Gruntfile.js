module.exports = function (grunt) {
  var mozjpeg = require('imagemin-mozjpeg');


  grunt.initConfig({
      pkg: grunt.file.readJSON('package.json'),

      // SCSS
      compass: {
        dev: {
          options: {
            config: 'config.rb',
            outputStyle: 'expanded',
            debugInfo: true,
            environment: 'development'
          }
        },
        prod: {
          options: {
            config: 'config.rb',
            outputStyle: 'compressed',
            debugInfo: false,
            environment: 'production'
          }
        }
      },

      // SVG Minification
      svgmin: {
        multiple: {
          files: [
            {
              expand: true,
              cwd: 'images/svg/',
              src: ['**/*.svg'],
              dest: 'images/svgmin'
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
              cwd: 'images/svgmin/icons',
              src: ['**/*.svg'],
              dest: 'images/icons'
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
            src: ['images/**/*.{png,jpg,gif,jpeg}']
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
            'js/kapablo.min.js': [
              'js/app/modernizr.js',
              'js/app/kapablo.js'
            ]
          }
        },
        bootstrap: {
          files: {
            'js/bootstrap.min.js': ['js/bootstrap/transition.js',
              'js/bootstrap/alert.js',
              'js/bootstrap/button.js',
              'js/bootstrap/carousel.js',
              'js/bootstrap/collapse.js',
              'js/bootstrap/dropdown.js',
              'js/bootstrap/modal.js',
              'js/bootstrap/tooltip.js',
              'js/bootstrap/popover.js',
              'js/bootstrap/scrollspy.js',
              'js/bootstrap/tab.js',
              'js/bootstrap/affix.js']
          }
        }

//            ie7: {
//                src: ['js/app/ie7.js'],
//                dest: 'js/<%= pkg.name %>.ie7.min.js'
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
          src: [
            'css/style.css',
            'css/mail.css'
          ]
        }
      },

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
            'css/style.css': 'css/style.css',
            'css/mail.css': 'css/mail.css',
          }
        }
      },

      // Automate some tasks during development (if files change).
      watch: {
        svg: {
          files: ['images/svg/**/*.svg'],
          tasks: ['svgmin', 'grunticon', 'compass:dev', 'pleeease'],
          options: {
            livereload: true
          }
        },

        style: {
          files: ['sass/*.scss', 'sass/**/*.scss'],
          tasks: ['compass:dev', 'pleeease'],
          options: {
            livereload: true
          }
        },

        scripts: {
          files: ['js/app/*.js'],
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
    //'csscss',
    'watch'
  ]);

  grunt.registerTask('build', [
    'svgmin',
    'grunticon',
    'imagemin',
    'uglify',
    'compass:prod',
    'pleeease',
  ]);

  grunt.registerTask('default', [
    'dev',
    'watch'
  ]);
}
