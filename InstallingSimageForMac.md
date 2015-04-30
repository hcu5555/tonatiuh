# Introduction #

Simage is a library capable of loading, manipulating and saving images, creating and saving movies (AVI and mpeg), and loading audio. The simage library relies heavily on third party libraries to perform these tasks. The simage library is used within Tonatiuh to complement the Coin 3D library, since Coin uses simage to read textures.

Here you will find the instructions to install the simage library in your computer and make the library available for the development of Tonatiuh.

# Details #

Download the latest realese of simage, currently [simage-1.7.0](http://www.coin3d.org/lib/simage/releases/1.7.0), from the [Coin3D](http://www.coin3d.org/) website at http://www.coin3d.org/lib/plonesoftwarecenter_view. Place it into the desktop.

Open a shell console and navigate to desktop and extract the archive by typing:
```
tar -xvf simage-1.7.0.tar.gz
```

This will create a directory called _simage-1.7.0_ in your user directory. Using the shell navigate to just created simage-1.7.0 directory. Create release libraries by typing:
```
./configure --enable-debug=no --with-qt=/usr/local/Trolltech/Qt-4.7.0
```

This will start the configuration process. Depending on your computer, this process may take some time to finish. When it does, install the simage libraries by typing:
```
make 
make install
```

At the end of the installation process, the libraries hab been installed at /usr/local directory. Now, [Coin3D](InstallingCoin3DForMac.md) installation can be started.


[Mac Configuration](InstallingForMac.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)