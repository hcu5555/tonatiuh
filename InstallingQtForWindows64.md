# Introduction #
![http://tonatiuh.googlecode.com/svn/wiki/images/qt/qtLogo.png](http://tonatiuh.googlecode.com/svn/wiki/images/qt/qtLogo.png)

Qt is cross-platform application framework for Graphics User Interface (GUI) development. This application framework is implemented as a set of related libraries. The Qt libraries are used within Tonatiuh to implement the program's GUI, the plug-in architecture, the parallel processing functionality, and the scripting capabilities, among other things.

Here you will find instructions to install the Qt libraries in your computer and make those libraries available for the development of Tonatiuh.

# Details #

To build and install Qt library, first, we must install perl, python. The OpenSSL and ICU libraries must be build before to be able compile Qt sources.

## Download Qt code ##
Download the latest libraries sources of the Qt . To do it, click on the following [link](http://download.qt-project.org/official_releases/qt/5.4/5.4.1/single/qt-everywhere-opensource-src-5.4.1.tar.gz).

Once the source code package is on your PC, extract the file to _"C:\sde"_ directory. Then, rename folder to "qt", so the code will be in _"C:\sde\qt"_.

## Perl ##
Qt recommends the Strawberry Perl version for MinGW 64-bit. Download the latest version from the following [link](http://strawberryperl.com/releases.html) and select the 64-bit ZIP version. Copy downloaded file to _"C:\sde"_ and extract the files to _"C:\sde\perl"_.

## Python ##

Download Python for 64-bit from the following [link](https://www.python.org/ftp/python/2.7.9/python-2.7.9.amd64.msi). Once the download process is finished intall Python into _"C:\sde\python"_.

## Ruby ##
The third language environment needed to build Qt is Ruby. Download the latest version from the following [link](http://rubyinstaller.org/downloads/) and select the 64-bit 7-zip version (currently ["Ruby 2.2.1 (x64)"](http://dl.bintray.com/oneclick/rubyinstaller/ruby-2.2.1-x64-mingw32.7z)). Copy downloaded file to _"C:\sde"_ and extract the files to _"C:\sde\ruby"_.

## Building OpenSSL ##
Next step for build Qt is build OpenSSL for MinGW 64-bit. Download sources latest stable edition (current version "openssl-1.0.1e.tar.gz" ) of OpenSSL from the OpenSSL website at [link](https://www.openssl.org/source/)  to "C:\sde\qt\qt5\_deps\openssl-1.0.1e.tar.gz.

Once the sources are downloaded go to this folder and extract files. For that, use msys console (run "C:\sde64\mingw64\msys\msys.bat" ):
```
tar -xzvf openssl-1.0.1e.tar.gz
cd openssl-1.0.1e
```

To start compiling and building OpenSSL execute following commands in the shell:
```
export PATH=/c/sde/mingw64/bin:$PATH 
unset MAKE_COMMAND_MAKEFLAGS  

CROSS_COMPILE="x86_64-w64-mingw32-" ./configure --prefix=/c/sde/qt/qt5_deps/openssl-1.0.1e/dist no-idea no-mdc2 no-rc5 shared mingw64  
```

Once configuration process has finished execute the commands below to buid the library and install it:
```
make depend && make && make install  
cp /c/sde/qt/qt5_deps/openssl-1.0.1e/dist/bin/*.dll /c/sde/qt/qtbase/bin
```

## Building ICU ##
The ICU library is also required to build Qt.  Download ICU sources("icu4c-52\_1-src.zip") from ["ICU website"](http://download.icu-project.org/files/icu4c/52.1/icu4c-52_1-src.zip) to "C:\sde\qt\qt5\_deps\".

In order to build and install the library open MSYS console ( run "C:\sde\mingw64\msys\msys.bat") and execute the following commands:
```
unset MAKE_COMMAND  
export PATH=/c/sde/mingw64/bin:$PATH 
cd /c/sde/qt/qt5_deps  
unzip icu4c-52_1-src.zip

cd icu/Source  
./runConfigureICU MinGW --prefix=/c/sde/qt/qt5_deps/icu/dist  
.make && make install
cp /c/sde/qt/qt5_deps/icu/dist/lib/icu*.dll  /c/sde/qt/qtbase/bin/
```

## Building Qt ##
Once OpenSLL and ICU libraries have been build successfully. The Qt build process can start.

In order to avoid configuration errors, before start with the configuration a new file named ".gitignore" must be created in Qt folder, _"C:\sde\qt"_ with the following content:
```
Makefile
.qmake.cache
.qmake.super
```

Copy this folder also in _"C:\sde\qt\qtbase"_. Now, the configuration process can be started. Open Windows command prompt (Cmd-shell) and type:
```
cd C:\sde\qt
set INCLUDE=C:\sde\qt\qt5_deps\icu\dist\include;C:\sde\qt\qt5_deps\openssl-1.0.1e\dist\include
set LIB=C:\sde\qt\qt5_deps\icu\dist\lib;C:\sde\qt\qt5_deps\openssl-1.0.1e\dist\lib
set QMAKESPEC=
set QTDIR=
set MAKE_COMMAND=
set PATH=%CD%\qtbase\bin;%CD%\gnuwin32\bin;C:\sde\mingw64\bin;C:\sde\strawberry\perl\bin;C:\sde\python;C:\sde\ruby\bin;C:\sde\qt\qt5_deps\icu\dist\lib;C:\sde\qt\qt5_deps\openssl-1.0.1e\dist\bin;C:\Program Files (x86)\Git\cmd;%SystemRoot%\System32
configure -debug-and-release -opensource -confirm-license -platform win32-g++ -developer-build -c++11 -icu -opengl desktop -openssl -plugin-sql-odbc -qt-style-windowsxp -qt-style-windowsvista -nomake examples -nomake tests
```
After qt configuration is finished, to build and install qt libraries typing:
```
mingw32-make
mingw32-make install
```

The build process may take several hours. Once the Qt libraries and development tools are installed, the next step is to install the Simage library. To do it, follow the instructions in the following wiki page: [Simage](InstallingSimageForWindows64.md)

[Windows 64 Bit Configuration](InstallingForWindows64.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)