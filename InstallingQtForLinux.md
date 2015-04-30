![http://tonatiuh.googlecode.com/svn/wiki/images/qt/qtLogo.png](http://tonatiuh.googlecode.com/svn/wiki/images/qt/qtLogo.png)

Qt is cross-platform application framework for Graphics User Interface (GUI) development. This application framework is implemented as a set of related libraries. The Qt libraries are used within Tonatiuh to implement the program's GUI, the plug-in architecture, the parallel processing functionality, and the scripting capabilities, among other things.

Here you will find instructions to install the Qt libraries in your computer and make those libraries available for the development of Tonatiuh.

# Details #

In the Tonatiuh development, the las Qt version, Qt-4.7, is used. If this version is not available from the SO software management tool, configure it following the these steps.

To install the Qt SDK in your computer download the latest release of the installer file, _Qt\_SDK\_Lin32\_online\_v1\_1\_4\_en.run_ , from the http://qt.nokia.com/products/ website by clicking [here](http://qt.nokia.com/downloads/sdk-linux-x11-32bit-cpp). Place it on your "downloads" directory, e.g., _/home/downloads_.

Open a shell console, navigate to the downloads directory and run it by typing:
```
chmod u+x Qt_SDK_Lin32_online_v1_1_4_en.run
sudo ./Qt_SDK_Lin32_online_v1_1_4_en.run
```

This will open an installation wizard.During the execution of the installer do the following:
  * Check the _"I accept the terms of the License Agreement"_ and click the _"Next_ button.
  * Enter _"/usr/local/Trolltech/Qt-4.7"_ as the destination folder
  * Select the following components to install:
    * _"Qt Creator"_
    * _"Qt Development Libraries"_

After the Qt libraries are installed, you must add the appropriate information to your $PATH. To do that, edit the .bashrc file with your favorite editor to include the following at the end of the file:
```
QTDIR=/usr/local/Trolltech/Qt-4.7/qt
export QTDIR

PATH=$QTDIR/bin:$PATH
export PATH

```

Once the Qt libraries and development tools (including Qt creator) are installed, the next step is to install the [Simage](InstallingSimageForLinux.md) library.


[Linux Configuration](InstallingForLinux.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)