module.exports = function (grunt) {
    grunt.initConfig({
        pkg: grunt.file.readJSON('package.json'),
        less: {
            dist: {
                options: {
                    cleancss: true,
                    compress: true,
                    ieCompat: true,
                    sourceMap: false
                },
                files: {
                    "css/bootstrap.css": "less/style.less"
                }
            }
        },
        sass: {
            dist: {
                files: {
                    'css/style.css': 'sass/style.scss'
                },
                options: {
                    style: 'compressed', // Can be nested, compact, compressed, expanded.
                    sourcemap: 'none'
                }
            }
        },
        watch: {
            css: {
                files: '**/*.scss',
                tasks: ['sass']
            }
        }
    });
    grunt.loadNpmTasks('grunt-contrib-less');
    grunt.loadNpmTasks('grunt-contrib-sass');
    grunt.loadNpmTasks('grunt-contrib-watch');

    grunt.registerTask('build', [
        'less',
        'sass'
    ]);

    grunt.registerTask('default', [
        'less',
        'sass',
        'watch'
    ]);
}