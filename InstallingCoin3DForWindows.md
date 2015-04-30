![http://tonatiuh.googlecode.com/svn/wiki/images/coin3d/coin3dLogo.png](http://tonatiuh.googlecode.com/svn/wiki/images/coin3d/coin3dLogo.png)

# Introduction #

Coin is a high-level 3D graphics toolkit for developing cross-platform real-time 3D visualization and visual simulation software. This toolkit is implemented as a library. The Coin library is used within Tonatiuh to implement the programs 3D views of the concentrating system being simulated and to provide the architecture for the underlying 3D scene graph.

Here you will find instructions to install the Coin library in your computer and make this library available for the development of Tonatiuh.

# Details #

Since the Coin library binary installers for Windows, available at the Coin 3D website, are only valid for Visual C++ and we need to use the MinGW C++ compiler in order to be able to use the open source version of the Qt libraries, we need to build the Coin library from the source code.

Download the latest realese of the Coin source package, currently Coin 3.1.3. To do it, click on the following [link](https://bitbucket.org/Coin3D/coin/downloads) to go to the _"Coin 3.1.3"_ webpage of the Coin website. Once you reach the webpage, click on the link titled _"Get Coin 3.1.3 for all platforms"_ (see Figure 1). This will start the downloading of the Coin source package. When prompted if to open or to store the file in your computer, select the appropriate option to store the file in your computer.

|<a href='https://picasaweb.google.com/lh/photo/JbWXb6encigkEK0GwW8J-dMTjNZETYmyPJy0liipFm0?feat=embedwebsite'><img src='https://lh5.googleusercontent.com/-qynyUWCzbqI/Up7qXwFvYMI/AAAAAAAAAS4/os-MG_0dOUU/s400/Coin-3.1.3_download.png' height='333' width='400' /></a>|
|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 1.** View of the "Coin 1.3.1" webpage.|

Once the coin source code package is on your PC, place it into the user directory under your MSYS folder. This will typically be _C:\sde\MinGW\msys\1.0\home\username_.

Open an MSYS shell console. Navigate to your MSYS user directory and extract the archive by typing:
```
tar -zxvf Coin-3.1.3.tar.gz
```

This will create a directory called _Coin-3.1.3_ in your user directory. Using the MSYS shell navigate to just created Coin-3.1.0 directory.

To build the library in release mode type:
```
export QTDIR=/c:/sde/Qt/version/mingw
export COINDIR=/usr/local
export INCLUDE=/usr/local/include:/c:/sde/MinGW/include
./configure --disable-msvc --enable-debug=no --enable-symbols=no
```

This will start the configuration process. Depending on your computer, this process may take some time to finish. When it does, a set of messages indicating the Coin configuration settings will be displayed at MSYS shell (see Figure 2).

|<a href='http://picasaweb.google.com/lh/photo/WYeLOhf48chNSykrpIxVWMkjYPHGJOebwiJHbWK4XiY?feat=embedwebsite'><img src='http://lh3.ggpht.com/_tmEVMS15i5Y/TLB670Ev2zI/AAAAAAAAAnE/J0_F_CRcPiw/s400/Coin_config_final_screen.png' height='323' width='400' /></a>|
|:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 2.** MSYS shell messages shown when the configuration process ends.|

To compile the code without errors, it is necessary to do some changes in the code:
  * File _"src/base/dict.h"_, line 31: comment the code.
```
//#include <cstdlib>
```
  * File _"src/fonts/freetype:cpp"_: comment line 121
```
//#include <math.h>
```
  * File _"src/fonts/glyph.h"_, line 40: Add
```
#include <cstdlib>
```



Now, you can install the Coin3D library by typing:
```
make 
make install
```

The installation process may take some time. At the end of the installation process, the Coin dynamic library _"libCoin-60.dll"_ and the file _"coin-config"_ will be installed at the folder _"C:\sde\MinGW\msys\1.0\local\bin"_ and the Coin library files "libCoin.dll.a" and "libCoin.la" will be installed at the folder _"C:\sde\MinGW\msys\1.0\local\lib"_. In addition, the file _"Coin.pc"_ will be installed at the folder _"C:\sde\MinGW\msys\1.0\local\lib\pkgconfig"_ and the necessary include files will be installed at the folders _"C:\sde\MinGW\msys\1.0\local\include"_ and _"C:\sde\MinGW\msys\1.0\local\include\Inventor"_.

Once the Coin library is installed, the next step in setting up the Tonatiuh development environment is to install the SoQt library. To do it, follow the instructions in the following wiki page: [Installing SoQt](InstallingSoQt.md)

[Windows Configuration](InstallingForWindows.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)