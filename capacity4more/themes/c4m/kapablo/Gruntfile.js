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

      imagemin: {                          // Task
        dynamic: {                         // Another target
          options: {                       // Target options
            optimizationLevel: 12,
            svgoPlugins: [{ removeViewBox: false }],
            use: [mozjpeg()]
          },
          files: [{
            expand: true,                  // Enable dynamic expansion
            src: ['images/**/*.{png,jpg,gif}']   // Actual patterns to match
          }]
        }
      },



      // JS
      concat: {
        options: {
          stripBanners: true
        },
        app: {
          src: [
            'js/app/kapablo.js',
            'js/app/modernizr.js'
          ],
          dest: 'js/<%= pkg.name %>.concat.js'
        }
      },
      uglify: {
        options: {
          report: 'min'
        },
        app: {
          src: ['<%= concat.app.dest %>'],
          dest: 'js/<%= pkg.name %>.min.js'
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
          src: 'css/style.css'
        }
      },

      pleeease: {
        custom: {
          options: {
            "browsers": ["ie 8"],
            //autoprefixer: {'browsers': ['last 4 versions', 'ios 6']},
            filters: {'oldIE': true},
            minifier: false,
            pseudoElements: true,
            opacity: true,
            mqpacker: true,
            calc: true,
            colors: true
          },
          files: {
            'css/style.css': 'css/style.css'
          }
        }
      },

      // Automate some tasks during development (if files change).
      watch: {
        svgmin: {
          files: ['images/svg/**/*.svg'],
          tasks: ['svgmin', 'grunticon', 'compass'],
          options: {
            livereload: true
          }
        },

        compass: {
          files: ['sass/*.scss', 'sass/**/*.scss'],
          tasks: ['compass', 'pleeease'],
          options: {
            livereload: true
          }
        },

        scripts: {
          files: ['js/app/*.js'],
          tasks: ['concat:app', 'uglify:app'],
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
    'concat',
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
    'concat',
    'uglify',
    'compass:prod',
    'pleeease',
  ]);

  grunt.registerTask('default', [
    'build',
    'watch'
  ]);
}
