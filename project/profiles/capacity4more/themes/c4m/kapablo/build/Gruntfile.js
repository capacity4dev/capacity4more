module.exports = function (grunt) {
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
                    ext: '.css'
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
                    ext: '.css'
                }]
            }
        },

        autoprefixer: {
            dev: {
                options: {
                    browsers: ['last 2 versions', 'ie 9'],
                    diff: true,
                    map: true
                },
                files: [{
                    expand: true,
                    cwd: '<%= project.dst %>/css',
                    src: ['*.css'],
                    dest: '<%= project.dst %>/css',
                    ext: '.css'
                }]
            },
            build: {
                options: {
                    browsers: ['last 2 versions', 'ie 6'],
                    diff: false,
                    map: false
                },
                files: [{
                    expand: true,
                    cwd: '<%= project.dst %>/css',
                    src: ['*.css'],
                    dest: '<%= project.dst %>/css',
                    ext: '.css'
                }]
            }

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
                    '<%= project.src %>/stylesheets/*.scss',
                    '<%= project.src %>/stylesheets/**/*.scss'
                ],
                tasks: ['sass:dev', 'autoprefixer:dev'],
                options: {
                    livereload: true
                }
            }
        }

    });

    grunt.loadNpmTasks('grunt-contrib-clean');
    grunt.loadNpmTasks('grunt-contrib-sass');
    grunt.loadNpmTasks('grunt-contrib-watch');
    grunt.loadNpmTasks('grunt-autoprefixer');

    grunt.registerTask('dev', [
        'clean',
        'sass:dev',
        'autoprefixer:dev',
        'watch'
    ]);

    grunt.registerTask('build', [
        'clean',
        'sass:build',
        'autoprefixer:build'
    ]);

    grunt.registerTask('default', [
        'build'
    ]);
}