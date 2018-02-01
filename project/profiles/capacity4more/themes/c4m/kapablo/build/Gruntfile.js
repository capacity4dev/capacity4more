/**
 * @file
 * Gruntfile defining and running theming tasks.
 */

module.exports = function (grunt) {
  grunt.initConfig({
      pkg: grunt.file.readJSON('package.json'),

      /**
       * Set project object.
       *
       * Variables:
       * <%= project.src %> : The root path of the project.
       */
      project: {
          src: 'src',
          dst: '..'
        },

      bootstrapDir: './node_modules/bootstrap-sass',

      // Compile SASS, including bootstrap-sass.
      sass: {
          dev: {
              options: {
                  style: 'expanded',
                  sourcemap: 'auto',
                  debug: true,
                  loadPath: '<%= bootstrapDir %>/assets/stylesheets'
                },
              files: [{
                  expand: true,
                  cwd: '<%= project.src %>/stylesheets',
                  src: ['*.scss'],
                  dest: '<%= project.dst %>/css',
                  ext: '.concat.css'
                }]
            },
          build: {
              options: {
                  style: 'compressed',
                  sourcemap: 'none',
                  debug: false,
                  loadPath: '<%= bootstrapDir %>/assets/stylesheets'
                },
              files: [{
                  expand: true,
                  cwd: '<%= project.src %>/stylesheets',
                  src: ['*.scss'],
                  dest: '<%= project.dst %>/css',
                  ext: '.concat.css'
                }]
            }
        },

      // Auto prefix CSS files with specified browser support.
      autoprefixer: {
          dev: {
              options: {
                  browsers: ['last 4 versions', 'ie 10'],
                  diff: true,
                  map: true
                },
              files: [{
                  expand: true,
                  cwd: '<%= project.dst %>/css',
                  src: ['*.concat.css'],
                  dest: '<%= project.dst %>/css',
                  ext: '.concat.css'
                }]
            },
          build: {
              options: {
                  browsers: ['last 4 versions', 'ie 10'],
                  diff: false,
                  map: false
                },
              files: [{
                  expand: true,
                  cwd: '<%= project.dst %>/css',
                  src: ['*.concat.css'],
                  dest: '<%= project.dst %>/css',
                  ext: '.concat.css'
                }]
            }
        },

      // ESLint Theme's JavaScript file.
      eslint: {
          src: ['<%= project.src %>/javascripts/kapablo.js']
        },

      // Concatenate JavaScript files.
      concat: {
          dev: {
              options: {
                  sourceMap: true
                },
              files: {
                  '<%= project.dst %>/js/bootstrap.concat.js': [
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/affix.js',
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/alert.js',
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/button.js',
                      // '<%= bootstrapDir %>/assets/javascripts/bootstrap/carousel.js'.
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/collapse.js',
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/dropdown.js',
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/modal.js',
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/tooltip.js',
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/popover.js',
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/scrollspy.js',
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/tab.js',
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/transition.js'
                  ],
                  '<%= project.dst %>/js/kapablo.concat.js': [
                      '<%= project.src %>/javascripts/kapablo.js',
                      '<%= project.src %>/javascripts/classie.js',
                      '<%= project.src %>/javascripts/sidebarEffects.js',
                      '<%= project.src %>/javascripts/cookie_config.js'
                  ]
                }
            },
          build: {
              options: {
                  sourceMap: false,
                  stripBanners: true
                },
              files: {
                  '<%= project.dst %>/js/bootstrap.concat.js': [
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/affix.js',
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/alert.js',
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/button.js',
                      // '<%= bootstrapDir %>/assets/javascripts/bootstrap/carousel.js'.
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/collapse.js',
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/dropdown.js',
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/modal.js',
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/tooltip.js',
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/popover.js',
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/scrollspy.js',
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/tab.js',
                      '<%= bootstrapDir %>/assets/javascripts/bootstrap/transition.js'
                  ],
                  '<%= project.dst %>/js/kapablo.concat.js': [
                      '<%= project.src %>/javascripts/kapablo.js',
                      '<%= project.src %>/javascripts/classie.js',
                      '<%= project.src %>/javascripts/sidebarEffects.js',
                      '<%= project.src %>/javascripts/cookie_config.js'
                  ]
                }
            }
        },

      // Uglify JavaScript files.
      uglify: {
          build: {
              options: {
                  report: 'min'
                },
              files: [{
                  expand: true,
                  cwd: '<%= project.dst %>/js',
                  src: ['*.concat.js'],
                  dest: '<%= project.dst %>/js',
                  ext: '.concat.js'
                }]
            }
        },

      // Minify images.
      imagemin: {
          build: {
              options: {
                  optimizationLevel: 3,
                  svgoPlugins: [{removeViewBox: false}],
                  progressive: true,
                  interlaced: true
                },
              files: [{
                  expand: true,
                  cwd: '<%= project.src %>/images',
                  src: ['**/*.{png,jpg,gif,svg}'],
                  dest: '<%= project.dst %>/images',
                }]
            }
        },

      // Remove destination files.
      clean: {
          options: {
              force: true
            },
          dst: [
              "<%= project.dst %>/css",
              "<%= project.dst %>/js",
              "<%= project.dst %>/images"
          ],
        },

      // Automate some tasks during development (if files change).
      watch: {
          style: {
              files: [
                  '<%= project.src %>/stylesheets/**/*.scss'
              ],
              tasks: ['sass:dev', 'autoprefixer:dev'],
              options: {
                  livereload: true
                }
            },

          scripts: {
              files: [
                  '<%= project.src %>/javascripts/**/*.js'
              ],
              tasks: ['eslint', 'concat', 'uglify'],
              options: {
                  livereload: true
                }
            },

          images: {
              files: [
                  '<%= project.src %>/images/**/*.{png,jpg,gif}'
              ],
              tasks: ['imagemin'],
              options: {
                  livereload: true
                }
            }
        }
    });

  grunt.loadNpmTasks('grunt-autoprefixer');
  grunt.loadNpmTasks('grunt-contrib-clean');
  grunt.loadNpmTasks('grunt-contrib-concat');
  grunt.loadNpmTasks('grunt-contrib-imagemin');
  grunt.loadNpmTasks('grunt-contrib-sass');
  grunt.loadNpmTasks('grunt-contrib-uglify');
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-eslint');

  grunt.registerTask('dev', [
        'clean',

        'imagemin',

        'sass:dev',
        'autoprefixer:dev',

        'eslint',
        'concat:dev'
    ]);

  grunt.registerTask('build', [
        'clean',

        'imagemin',

        'sass:build',
        'autoprefixer:build',

        'eslint',
        'concat:build',
        'uglify'
    ]);

  grunt.registerTask('default', [
        'build'
    ]);

  grunt.registerTask('dev-watch', [
        'dev',
        'watch'
    ]);
}
