# Introduction #
![http://tonatiuh.googlecode.com/svn/wiki/images/qt/qtLogo.png](http://tonatiuh.googlecode.com/svn/wiki/images/qt/qtLogo.png)

Qt is cross-platform application framework for Graphics User Interface (GUI) development. This application framework is implemented as a set of related libraries. The Qt libraries are used within Tonatiuh to implement the program's GUI, the plug-in architecture, the parallel processing functionality, and the scripting capabilities, among other things.

Here you will find instructions to install the Qt libraries in your computer and make those libraries available for the development of Tonatiuh.

# Details #
The available Qt binary package for Mac, is not valid for the Tonatiuh development environment. To configure Qt should download and build Qt from sources.

Download the latest Qt libraries sources. To do it, click on the following [link](http://qt.nokia.com/downloads) to go to the "Downloads" webpage of the Qt website. Once you reach the webpage, click on the link titled _"Qt libraries 4.7.0 for Mac"_. Click on _"Source code available on this link:
http://get.qt.nokia.com/qt/source/qt-everywhere-opensource-src-4.7.0.tar.gz
"_. This will start the downloading of the Qt source code. Select the appropriate option to store the file in your computer.

Once the download ha finished, open a shell and go to download directory and extract files:
```
tar -xvf qt-everywhere-opensource-src-4.7.0.tar
```

After extraction, a new directory, qt-everywhere-opensource-src-4.7.0, will be created. Go to the directory and type:
```
./configure -opensource -debug-and-release -universal -no-framework 
```
You will be asked to accept the license agreement. Accept it typing yes.

After qt configuration is finished, to install qt libraries typing:
```
make
make install
```

Now, Qt libraries are installed, we must specify where Qt is installed. Type:

```
$ vi ~/.profile 
```

Type "e" to be able to write in the file. We should add the following text:
```
PATH=/usr/local/Trolltech/Qt-4.7.0/bin:$PATH 
export PATH 
QTDIR=/usr/local/Trolltech/Qt-4.7.0 
export QTDIR 
```

Save chages with:
```
ESC
:wq
```

To continue with the resources intallation to Tonatiuh development, start with [Simage](InstallingSimageForMac.md) installation.

[Mac Configuration](InstallingForMac.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)