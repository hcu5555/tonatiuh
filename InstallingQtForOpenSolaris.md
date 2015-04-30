![http://tonatiuh.googlecode.com/svn/wiki/images/qt/qtLogo.png](http://tonatiuh.googlecode.com/svn/wiki/images/qt/qtLogo.png)

Qt is cross-platform application framework for GUI development.

# Requirements #

  * SunStudio installed and updated.
  * X11 development packages installed.
  * The address of the cc and CC compiler commands in the PATH.

# Details #

From the following link [ftp://ftp.qt.nokia.com/qt/source/qt-everywhere-opensource-src-4.6.2.tar.gz](ftp://ftp.qt.nokia.com/qt/source/qt-everywhere-opensource-src-4.6.2.tar.gz) download the Qt sources for Qt version 4.6.2.

**Note: It is important to ensure that the Qt source file downloaded is for Qt version 4.6.2. The outlined procedure has only been tested and is only guaranteed to work for that version.**

Extract the content of the downloaded tar.gz file into your _"Downloads"_ folder. This will create a new folder under _"Downloads"_ entitled: _"qt-everywhere-opensource-src-4.6.2"_.

From the following link [http://tonatiuh.googlecode.com/files/opensolaris-parches-qt-webkit.tar.bz2](http://tonatiuh.googlecode.com/files/opensolaris-parches-qt-webkit.tar.bz2) download the file containing the parches that need to be applied to the Qt source files, in order to compile the QtWebKit library for OpenSolaris.

Extract the content of the downloaded tar.bz file into your _"Downloads"_ folder. This will create a new folder under _"Downloads"_ entitled: _"opensolaris-parches-qt-webkit"_.

Copy all the files contained in that folder and paste them into the folder _"qt-everywhere-opensource-src-4.6.2"_. Then, open a command shell as super user, move to the _"qt-everywhere-opensource-src-4.6.2"_ folder, and execute the .sh file entitled _"parchearArchivos.sh"_ by entering:

```
./parchearArchivos.sh
```

The _"patch"_ command that the file _"parchearArchivos.sh"_ is supposed to execute is the GNU patch command. If the _"patch"_ command that executes by default in your OpenSolaris implementation is not the GNU patch command, you may get error or warning messages while executing _"parchearArchivos.sh"_. Should that be the case, you can either change your OpenSolaris implementation to ensure that the default _"patch"_ command is the GNU patch, or you can edit _"parchearArchivos.sh"_ to replace the invocations to _"patch"_ with invocations to _"gpatch"_

Once the patches are successfully applied, you may configure, make, and install by by typing the following shell commands:

```
./configure -platform solaris-cc-stlport -webkit -nomake demos -nomake examples
make
pfexec make install
pfexec crle -u -v -l /usr/local/Trolltech/Qt-4.6.2/lib
pfexec crle -u -v -l /usr/local/lib
```

Some of the previous commands (_"configure"_, and _"make"_) may take quite a long time to execute depending on the characteristics of the computing you are using.

At the end of the installation process, the Qt libraries will be installed at _"/usr/local/TrollTech/Qt-4.6.2/lib"_. Now, you can proceed to the installation of [Simage](InstallingSimageForOpenSolaris.md).


[OpenSolaris Configuration](InstallingForOpenSolaris.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)