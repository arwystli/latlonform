module.exports = function(grunt) {

  grunt.loadNpmTasks('grunt-contrib-uglify');
  grunt.loadNpmTasks('grunt-contrib-concat');
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-contrib-cssmin');
  grunt.loadNpmTasks('grunt-contrib-less');

  grunt.initConfig({
    pkg: grunt.file.readJSON('package.json'),
    concat: {
      dist: {
        src: ['js/jquery.latlonfield.js', 'js/main.js', 'js/jquery.formalize.js'],
        dest: 'js/all.js'
      }
    },
    uglify: {
      build: {
        src: 'js/all.js',
        dest: 'js/all.min.js'
      }
    },
    less: {
      development: {
        options: {
          //compress: true,
          //yuicompress: true,
          optimization: 2
        },
        files: {
          'css/main.css': ['css/style.less','css/layout.less']
        }
      }
    },
    cssmin: {
      target: {
        src: ["css/formalize.css", "css/main.css"],
        dest: "css/main.min.css"
      }
    },
    watch: {
      scripts: {
        files: ['js/jquery.latlonfield.js', 'js/main.js'],
        tasks: ['concat', 'uglify']
      },
      styles: {
        files: ['css/*.less'],
        tasks: ['less', 'cssmin']
      }
    }
  });

  grunt.registerTask('default', ['concat', 'uglify', 'less', 'cssmin', 'watch'] );

};
