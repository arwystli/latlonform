latlonform
Author Bob Hutchinson <hutch@arwystli.net>

This simple project provides a form for collecting decimal latitude and longitude.
The form prevents the user from entering anything other than number, dot and minus characters and it normalizes the output.
The project also uses npm and grunt to concatenate and minify javascript and compile less files to css and minify css

To make use of this project you can install it by unpacking it into a folder. You may want to edit the .htaccess file to get things working.
If you want to use grunt you will need to have that installed globally, the cd into the project and type "npm install",
this will install the modules mentioned in package.json
Alternately you can just pilfer the project for useful bits such as the javascript files that manage the form.

Formalize has been included, see http://formalize.io. Marvellous stuff IMHO.
