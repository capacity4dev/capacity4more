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

        sass: {
            dev: {
                options: {
                    style: 'expanded',
                    sourcemap: 'auto',
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
            dist: {
                options: {
                    style: 'compressed',
                    sourcemap: 'none',
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

    });

    grunt.loadNpmTasks('grunt-contrib-sass');
}