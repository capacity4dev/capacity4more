/**
 * Gulp Build script.
 *
 * Documentation : @link http://gulpjs.com/.
 */

'use strict';

/* global require */

var del = require('del');
var gulp = require('gulp');
var autoprefixer = require('gulp-autoprefixer');
var cache = require('gulp-cache');
var concat = require('gulp-concat');
var eslint = require('gulp-eslint');
var gulpif = require('gulp-if');
var imagemin = require('gulp-imagemin');
var plumber = require('gulp-plumber');
var rename = require('gulp-rename');
var sass = require('gulp-sass');
var sourcemaps = require('gulp-sourcemaps');
var strip = require('gulp-strip-comments');
var uglify = require('gulp-uglify');
var pump = require('pump');
var sequence = require('run-sequence');

var config = {
  sass : {
    errLogToConsole: false,
    outputStyle: 'compressed',
    includePaths: [
      'node_modules/bootstrap-sass/assets/stylesheets'
    ]
  },
  autoprefixer : {
    browsers: ['last 4 versions', 'ie 10']
  },
  dist: '..',
  sourceMaps: false,
  stripBanners: true,
  uglify: true,
  bootstrapDir: './node_modules/bootstrap-sass'
};

/**
 * Task to update the settings for development.
 */
gulp.task('dev-options', function () {
  config.sourceMaps = true;
  config.stripBanners = false;
  config.uglify = false;
  config.sass.errLogToConsole = true;
  config.sass.outputStyle = 'expanded';
  config.autoprefixer.diff = true;
  config.autoprefixer.map = true;
});

/**
 * Cleanup task.
 */
gulp.task('clean', function() {
  return del([
    config.dist + '/css',
    config.dist + '/js',
    config.dist + '/images'
  ], { force: true });
});

/**
 * Task to minimize the images.
 */
gulp.task('imagemin', function() {
  gulp.src('src/images/**/*.{png,jpg,gif,svg}')
    .pipe(cache(
      imagemin({
        optimizationLevel: 3,
        svgoPlugins: [{removeViewBox: false}],
        progressive: true,
        interlaced: true
      })
    ))
    .pipe(gulp.dest(config.dist + '/images'));
});

/**
 * Task to parse sass files and generate minimized CSS files.
 */
gulp.task('sass', function() {
  gulp.src('src/stylesheets/kapablo.scss')
    .pipe(plumber({
      errorHandler: function (error) {
        console.log(error.message);
        this.emit('end');
      }}))
    .pipe(gulpif(config.sourceMaps, sourcemaps.init()))
    .pipe(sass(config.sass))
    .pipe(autoprefixer(config.autoprefixer))
    .pipe(rename({ extname : ".concat.css" }))
    .pipe(gulpif(config.sourceMaps, sourcemaps.write('.')))
    .pipe(gulp.dest(config.dist + '/css'));
});

/**
 * Task to parse sass files and generate minimized CSS files.
 */
gulp.task('eslint', function() {
  return gulp.src('src/javascripts/kapablo.js')
    .pipe(eslint())
    .pipe(eslint.format())
    .pipe(eslint.failAfterError());
});

/**
 * Task to concatenate the scripts.
 */
gulp.task('concat', ['eslint'], function() {
  var files = {
    "bootstrap.concat.js": [
      config.bootstrapDir + '/assets/javascripts/bootstrap/affix.js',
      config.bootstrapDir + '/assets/javascripts/bootstrap/alert.js',
      config.bootstrapDir + '/assets/javascripts/bootstrap/button.js',
      config.bootstrapDir + '/assets/javascripts/bootstrap/collapse.js',
      config.bootstrapDir + '/assets/javascripts/bootstrap/dropdown.js',
      config.bootstrapDir + '/assets/javascripts/bootstrap/modal.js',
      config.bootstrapDir + '/assets/javascripts/bootstrap/tooltip.js',
      config.bootstrapDir + '/assets/javascripts/bootstrap/popover.js',
      config.bootstrapDir + '/assets/javascripts/bootstrap/scrollspy.js',
      config.bootstrapDir + '/assets/javascripts/bootstrap/tab.js',
      config.bootstrapDir + '/assets/javascripts/bootstrap/transition.js'
    ],
    "kapablo.concat.js": [
      'src/javascripts/kapablo.js',
      'src/javascripts/classie.js',
      'src/javascripts/sidebarEffects.js'
    ]
  };
  for (var file in files) {
    // @see https://eslint.org/docs/rules/guard-for-in
    if (Object.prototype.hasOwnProperty.call(files, file)) {
      gulp.src(files[file])
        .pipe(plumber({
          errorHandler: function (error) {
            console.log(error.message);
            this.emit('end');
          }}))
        .pipe(gulpif(config.stripBanners, strip({ safe : true })))
        .pipe(gulpif(config.sourceMaps, sourcemaps.init()))
        .pipe(concat(file))
        .pipe(gulpif(config.uglify, uglify()))
        .pipe(gulpif(config.sourceMaps, sourcemaps.write('.')))
        .pipe(gulp.dest(config.dist + '/js/'));
    }
  }
});

/**
 * Task to uglify the scripts.
 */
gulp.task('uglify', ['concat'], function(cb) {
  pump(
    [
      gulp.src([config.dist + '/js/*.concat.js']),
      plumber({
        errorHandler: function (error) {
          console.log(error.message);
          this.emit('end');
        }}),
      gulpif(config.uglify, uglify()),
      gulp.dest(config.dist + '/js/')
    ],
    cb
  );
});

/**
 * Watch.
 */
gulp.task('dev-watch', function() {
  gulp.watch('src/images/**/*.{png,jpg,gif}', ['imagemin']);
  gulp.watch('src/stylesheets/**/*.scss', ['styles']);
  gulp.watch('src/javascripts/**/*.js', ['scripts']);
});

// Aliases.
gulp.task('images', ['imagemin']);
gulp.task('styles', ['sass']);
gulp.task('scripts', ['eslint', 'concat']);

// Main task.
gulp.task('default', ['build']);
gulp.task('build', function() {
  sequence('clean', ['images', 'styles', 'scripts']);
});

// Dev task.
gulp.task('dev', function() {
  sequence('dev-options', 'build');
});
gulp.task('watch', function() {
  sequence('dev', 'dev-watch');
});
