# Doxygen #

[Doxygen](http://www.stack.nl/~dimitri/doxygen/index.html) is a documentation generator for C++, C, Java, Objective-C, Python, IDL (versiones Corba y Microsoft), PHP, C#, and D. It is valid for Unix, Windows and Mac OS X.
Doxygen is the acronym of dox(document) gen(generator), source code documentation generator.


# Installation #

The doxygen sources and binaies are available on the doxygen download web page at http://www.stack.nl/~dimitri/doxygen/download.html#latestsrc. For Mac you can download doxygen binaries _Doxygen-version.dmg_ . Open downloaded file and copy _Doxygen.app_ to _Application_ folder.

# Eclipse configuration for Doxygen #

[Eclox](http://eclox.eu/) is a Doxygen plug-in for Eclipse. It integrates the code documentation process into Eclipse by providing a high-level graphical user interface over doxygen. To install de plugin:

  * Open Eclipse
  * Go to Help->Software Updates->Available Software.
  * Click _"Add Site..."_ button and write the following location: _http://download.gna.org/eclox/update_.
> > ![http://tonatiuh.googlecode.com/svn/wiki/images/eclipse/addSite.png](http://tonatiuh.googlecode.com/svn/wiki/images/eclipse/addSite.png)
  * Expand added site and select the files "Eclox" and "Eclox Hot" and push "Install...".
  * Accept all. The plugin should now be installed and restart eclipse.

Now, indicate to Eclipse to use installed doxigen version:
  * Go to Eclipse->Preferences.
  * Go to Doxygen and push "Add..." button.
  * Select in the file dialog the doxygen installation path: _/Applications/Doxygen/Contents/Resources_.
  * Acept and verificate that added version is selected. Apply changes before finish.

[Mac Configuration](InstallingForMac.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)