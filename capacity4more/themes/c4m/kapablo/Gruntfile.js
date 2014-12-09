module.exports = function (grunt) {
    grunt.initConfig({
        pkg: grunt.file.readJSON('package.json'),

        // SCSS
        compass: {
            build: {
                options: {
                    outputStyle: 'expanded',
                    debugInfo: true,
                    environment: 'development'
                }
            }
        },

//        sass: {
//            dist: {
//                files: {
//                    'css/style.css': 'sass/style.scss'
//                },
//                options: {
//                    style: 'compressed', // Can be nested, compact, compressed, expanded.
//                    sourcemap: 'none'
//                }
//            }
//        },

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

        watch: {
//            css: {
//                files: '**/*.scss',
//                tasks: ['sass']
//            },
            compass: {
                files: ['sass/*.scss', 'sass/**/*.scss'],
                tasks: ['compass'],
                options: {
                    livereload: true
                }
            },

            svgmin: {
                files: ['images/svg/**/*.svg'],
                tasks: ['svgmin', 'grunticon'],
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

//    grunt.loadNpmTasks('grunt-contrib-sass');
    grunt.loadNpmTasks('grunt-contrib-watch');
    grunt.loadNpmTasks('grunt-contrib-concat');
    grunt.loadNpmTasks('grunt-contrib-uglify');
    grunt.loadNpmTasks('grunt-svgmin');
    grunt.loadNpmTasks('grunt-grunticon');
    grunt.loadNpmTasks('grunt-contrib-compass');


    grunt.registerTask('build', [
        'concat',
        'uglify',
        'svgmin',
        'grunticon',
        'compass'
//        'sass'
    ]);

    grunt.registerTask('default', [
        'build',
        'watch'
    ]);
}
