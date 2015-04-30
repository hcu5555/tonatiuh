# Introduction #

Simage is a library capable of loading, manipulating and saving images, creating and saving movies (AVI and mpeg), and loading audio. The simage library relies heavily on third party libraries to perform these tasks. The simage library is used within Tonatiuh to complement the Coin 3D library, since Coin uses simage to read textures.

Here you will find the instructions to install the simage library in your computer and make the library available for the development of Tonatiuh.


# Details #

Since the simage library binary installers for Windows, available at the Coin 3D website, are only valid for Visual C++ and we need to use the MinGW C++ compiler in order to be able to use the open source version of the Qt libraries, we need to build the simage library from the source code.

Download the latest realese of the Simage source package, currently simage-1.7.0. To do it, click on the following [link](https://bitbucket.org/Coin3D/coin/downloads) to go to the "Downloads" webpage of the Coin3D website. Once you reach the webpage, click on the link entitled _"simage-1.7.0.tar.gz"_ (see Figure 1). This will start the downloading of the simage source package. When prompted if to open or to store the file in your computer, select the appropriate option to store the file in your computer.

|<a href='https://plus.google.com/photos/100251272352990958135/albums/5362380659945338161/5892949347792701474?banner=pwa&pid=5892949347792701474&oid=100251272352990958135feat=embedwebsite'><img src='https://lh3.googleusercontent.com/-VJR4ua_06sg/Ucf2NaqNyCI/AAAAAAAAD2E/TjonggbaCuU/w856-h685-no/Simage_Download.PNG' height='297' width='400' /></a>|
|:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 1.** View of the "simage 1.7.0" webpage.|

Once the simage source code package is on your PC, place it into the user directory under your MSYS folder. This will typically be _C:\sde\MinGW\msys\1.0\home\username_.

Open an MSYS shell console. Navigate to your MSYS user directory and extract the archive by typing:
```
tar -zxvf simage-1.7.0.tar.gz
```

This will create a directory called _simage-1.7.0_ in your user directory. Using the MSYS shell navigate to the just created directory.

To build the library in release mode type:
```
./configure --disable-msvc --without-gdiplus --with-qt=/c:/sde/Qt/Desktop/Qt/version/mingw --enable-debug=no --enable-symbols=no
```

This will start the configuration process. Depending on your computer, this process may take some time to finish. When it does, install the Simage library by typing:
```
make 
make install
```

The installation process may take several minutes. At the end of the installation process, the simage dynamic library _"libsimage-20.dll"_ and the file _"simage-config"_ will be installed at the folder _"C:\sde\MinGW\msys\1.0\local\bin"_ and the simage library files _"libsimage.dll.a"_ and _"libsimage.la"_ will be installed at the folder _"C:\sde\MinGW\msys\1.0\local\lib"_. In addition, the file _"simage.pc"_ will be installed at the folder _"C:\sde\MinGW\msys\1.0\local\lib\pkgconfig"_ and the necessary include files will be installed at the folder _"C:\sde\MinGW\msys\1.0\local\include"_.

Once the simage library is installed the next step is to install the Coin library. To do it, follow the instructions in the following wiki page: [Coin3D](InstallingCoin3DForWindows.md)

[Windows Configuration](InstallingForWindows.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)