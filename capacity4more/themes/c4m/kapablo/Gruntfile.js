module.exports = function (grunt) {
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
                src: ['sass/style.scss']
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
                tasks: ['compass'],
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
    });

    grunt.loadNpmTasks('grunt-contrib-watch');
    grunt.loadNpmTasks('grunt-contrib-concat');
    grunt.loadNpmTasks('grunt-contrib-uglify');
    grunt.loadNpmTasks('grunt-svgmin');
    grunt.loadNpmTasks('grunt-grunticon');
    grunt.loadNpmTasks('grunt-contrib-compass');
    grunt.loadNpmTasks('grunt-csscss');


    grunt.registerTask('dev', [
        'svgmin',
        'grunticon',
        'csscss',
        'concat',
        'uglify',
        'compass:dev',
        'watch'
    ]);

    grunt.registerTask('build', [
        'svgmin',
        'grunticon',
        'concat',
        'uglify',
        'compass:prod'
    ]);

    grunt.registerTask('default', [
        'build',
        'watch'
    ]);
}
