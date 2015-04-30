# Introduction #

Simage is a library capable of loading, manipulating and saving images, creating and saving movies (AVI and mpeg), and loading audio. The simage library relies heavily on third party libraries to perform these tasks. The simage library is used within Tonatiuh to complement the Coin 3D library, since Coin uses simage to read textures.

Here you will find the instructions to install the simage library in your computer and make the library available for the development of Tonatiuh.


# Details #

Since the simage library binary installers for Windows, available at the Coin 3D website, are only valid for Visual C++ and we need to use the MinGW C++ compiler in order to be able to use the open source version of the Qt libraries, we need to build the simage library from the source code.

Download the latest realese of the Simage source package, currently simage-1.7.0. To do it, click on the following [link](https://bitbucket.org/Coin3D/coin/downloads) to go to the "simage 1.7.0" webpage of the Coin website. Once you reach the webpage, click on the link titled _"Get simage 1.7.0 for all platforms"_ (see Figure 1). This will start the downloading of the simage source package. When prompted if to open or to store the file in your computer, select the appropriate option to store the file in your computer.

|<a href='https://plus.google.com/photos/102955994792379493343/albums/5628006084143315025/6124214543977484210?pid=6124214543977484210&oid=102955994792379493343'><img src='https://lh3.googleusercontent.com/-ScxA8ZJbtao/VP2UriYPD7I/AAAAAAAAAb8/B_ZrywGSvbQ/w1196-h617-no/Simage_sourcecode.png' height='350' width='650' /></a>|
|:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 1.** View of the "simage 1.7.0" webpage.|

Once the simage source code package is on your PC, place it into the user directory under your MSYS folder. This will typically be _C:\sde\MinGW\msys\usr\home\username_.

Open an MSYS shell console. Navigate to your MSYS user directory and extract the archive by typing:
```
tar -zxvf simage-1.7.0.tar.gz
```

This will create a directory called _simage-1.7.0_ in your user directory. Using the MSYS shell navigate to the just created directory.

To build the library in release mode type:
```
export PATH=/c/sde/mingw64/bin:$PATH
./configure --disable-msvc --without-gdiplus --build=x86_64-w64-mingw32
```

This will start the configuration process. Depending on your computer, this process may take some time to finish. When it does, install the Simage library by typing:
```
mingw32-make 
mingw32-make install
```

The installation process may take several minutes. At the end of the installation process, the simage dynamic library _"libsimage-20.dll"_ and the file _"simage-config"_ will be installed at the folder _"C:\sde\MinGW\msys\local\bin"_ and the simage library files _"libsimage.dll.a"_ and _"libsimage.la"_ will be installed at the folder _"C:\sde\MinGW\msys\local\lib"_. In addition, the file _"simage.pc"_ will be installed at the folder _"C:\sde\MinGW\msys\local\lib\pkgconfig"_ and the necessary include files will be installed at the folder _"C:\sde\MinGW\msys\local\include"_.

Once the simage library is installed the next step is to install the Coin library. To do it, follow the instructions in the following wiki page: [Coin3D](InstallingCoin3DForWindows64.md)

[Windows 64 BitConfiguration](InstallingForWindows64.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)