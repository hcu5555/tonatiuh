# Introduction #

SoQt is a library that provides the glue between the Coin 3D libraries and the Qt 2D GUI and application framework libraries. The SoQt library is used within Tonatiuh mainly to implement different types of Coin 3D scene viewers inside traditional 2D Qt-generated windows.

Here you will find instructions to install the SoQt library in your computer and make this library available for the development of Tonatiuh.

# Details #

Before installing SoQt, please, verify that the Qt and Coin 3D libraries are already properly installed in your computer. If they are not, install them first by following the corresponding procedures to [installing Qt](InstallingQtForWindows64.md) and [installing Coin](InstallingCoin3DForWindows64.md).

Since the SoQt library binary installers for Windows, available at the Coin 3D website, are only valid for Visual C++ and the open source version of the Qt libraries can only be compiled under Windows with the MinGW C++ compiler, the SoQt library have to be built from the source code.

Download the latest release of the SoQt, currently SoQt 1.5.0. To do it, click on the following [link](https://bitbucket.org/Coin3D/coin/downloads) to go to the _"SoQt 1.5.0"_ webpage of the Coin website. Once you reach the webpage, click on the link titled _"Get SoQt 1.5.0 for all platforms"_ (see Figure 1). This will start the downloading of the SoQt source package. When prompted if to open or to store the file in your computer, select the appropriate option to store the file in your computer.

|<a href='https://picasaweb.google.com/lh/photo/WmgYWcr97W1E_UPjENiH6NMTjNZETYmyPJy0liipFm0?feat=embedwebsite'><img src='https://lh4.googleusercontent.com/-YTIaKcoNfmM/Up8VyXpTJzI/AAAAAAAAATg/uM2H28il2sQ/s400/SoQt_download.png' height='289' width='400' /></a>|
|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 1.** View of the "SoQt 1.5.0" webpage.|

Once the SoQt source code package is on your computer, place it into the user directory under your MSYS folder. This will typically be _"C:\sde\mingw64\msys\home\username"_.

Open an MSYS shell console. Navigate to your MSYS user directory and extract the archive by typing:
```
tar -zxvf SoQt-1.5.0.tar.gz
cd SoQt-1.5.0
```
This will create a directory called _SoQt-1.5.0_ in your user directory. Using the MSYS shell navigate to the just created SoQt-1.5.0. directory. To build the library in release mode type:
```
export QTDIR=/c/sde/qt/qtbase
export COINDIR=/usr/local
export INCLUDE=/usr/local/include:/c/sde/mingw64/include
export PATH=$QTDIR/bin:$PATH
export QMAKESPEC=$QTDIR/mkspecs/win32-g++
./configure --disable-msvc --enable-debug=no --enable-symbols=no --with-qt=/c/sde/qt/qtbase --build=x86_64-w64-mingw32 --enable-pkgconfig=no CPPFLAGS="-I/c/sde/qt/qtbase/include/QtCore -I/c/sde/qt/qtbase/include/QtGui -I/c/sde/qt/qtbase/include/QtWidgets -I/c/sde/qt/qtbase/include/QtOpenGL " LDFLAGS="-L/c/sde/qt/qtbase/lib" CONFIG_QTLIBS="-lQt5Core -lQt5Gui -lQt5Widgets -lQt5OpenGL"
```

This will start the configuration process. Depending on your computer, this process may take some time to finish. When it does, a set of messages indicating the SoQt configuration settings will be displayed at MSYS shell (see Figure 2).

|<a href='http://picasaweb.google.com/lh/photo/XDBDPsDIIWsoWNEyDv_nNckjYPHGJOebwiJHbWK4XiY?feat=embedwebsite'><img src='http://lh5.ggpht.com/_tmEVMS15i5Y/TLCjufdju0I/AAAAAAAAAno/YuZV_pqk2R8/s400/SoQt_config_final_screen.png' height='202' width='400' /></a>|
|:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 2.** MSYS shell messages shown when the configuration process ends.|

To solve some compilation errors, change the following:
  * File libtool (line 582):
```
   -$EGREP -e 'file format pe-i386(.*architecture: i386)?' >/dev/null ; then
   +$EGREP -e 'file format pe-x86-64' >/dev/null ; then
```
  * File src/Inventor/Qt/devices/6DOFEvents.cpp (lines 136, 137 ):
```
  -return TRUE;
  +return true;
```

  * File src/Inventor/Qt/widgets/QtNativePopMenu.cpp (line 46):
```
  -#include <QtGui/QMenu>
  +#include <QMenu>
```
  * File src/Inventor/Qt/SoQtGLWidget.cpp
    * (line 46)
```
    -#include <QtGui/QColormap>
    +#include <QColormap>
```
    * (line 871)
```
    -SbString w = obj->objectName().toAscii().constData();
    +SbString w = obj->objectName().toLatin1().constData();
```
  * File src/Inventor/Qt/SoQtComponent.cpp (lines 135, 182):
```
  -unsigned long 
  +unsigned long long
```

  * File src/Inventor/Qt/common/SoQtComponentCommon.cpp.in (lines 444, 451, 458, 479, 491):
```
  -long
  +long long
```

Now, you can install the SoQt library by typing:
```
make 
make install
```

The installation process may take some time. At the end of the installation process, the SoQt dynamic library _"libSoQt-20.dll"_ and the file _"soqt-config"_ will be installed at the folder _"C:\sde\MinGW\msys\local\bin"_ and the SoQt library files "libSoQt.dll.a" and "libSoQt.la" will be installed at the folder _"C:\sde\MinGW\msys\local\lib"_. In addition, the file _"SoQt.pc"_ will be installed at the folder _"C:\sde\MinGW\msys\local\lib\pkgconfig"_ and the necessary include files will be installed at the folders _"C:\sde\MinGW\msys\local\include"_ and _"C:\sde\MinGW\msys\local\include\Inventor"_.

Once the SoQt library is installed the next step is to install the SQLite library. To do it, follow the instructions in the following wiki page: [Installing SQLite](InstallingSQLiteForWindows64.md).

[Windows 64 BitConfiguration](InstallingForWindows64.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)