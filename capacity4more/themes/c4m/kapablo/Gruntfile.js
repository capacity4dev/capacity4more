module.exports = function (grunt) {
    grunt.initConfig({
        pkg: grunt.file.readJSON('package.json'),
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
    grunt.loadNpmTasks('grunt-contrib-sass');
    grunt.loadNpmTasks('grunt-contrib-watch');

    grunt.registerTask('build', [
        'sass'
    ]);

    grunt.registerTask('default', [
        'sass',
        'watch'
    ]);
}
