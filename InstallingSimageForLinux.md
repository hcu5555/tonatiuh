# Simage #

Simage is a library capable of loading, manipulating and saving images, creating and saving movies (AVI and mpeg), and loading audio. The simage library relies heavily on third party libraries to perform these tasks. The simage library is used within Tonatiuh to complement the Coin 3D library, since Coin uses simage to read textures.

Here you will find the instructions to install the simage library in your computer and make the library available for the development of Tonatiuh.

# Details #

Download the latest realese of the Simage source package, currently simage-1.7.0. To do it, click on the following [link](http://www.coin3d.org/lib/plonesoftwarecenter_view) to go to the "simage 1.7.0" webpage of the Coin website. Once you reach the webpage, click on the link titled _"Get simage 1.7.0 for all platforms"_ (see Figure 1). This will start the downloading of the simage source package. When prompted if to open or to store the file in your computer, place it on your "downloads" directory, e.g., _/home/downloads_.

|<a href='http://picasaweb.google.com/lh/photo/OKxlezrM1MlVCjjDSjTCX8kjYPHGJOebwiJHbWK4XiY?feat=embedwebsite'><img src='http://lh3.ggpht.com/_tmEVMS15i5Y/TK-kOAPXjZI/AAAAAAAAAmQ/YfNdlO1VcvM/s400/Simage_sourcecode.png' height='297' width='400' /></a>|
|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 1.** View of the "simage 1.7.0" webpage.|

Open a shell console, navigate to your download directory, and extract the content of the installer file by typing:
```
tar -zxvf simage-1.7.0.tar.gz
```

This will create a directory called _simage-1.7.0_ in your download directory. Using the shell, navigate to the just created simage-1.7.0 directory.

Type the following command to build the release version of the simage library:
```
./configure --with-qt=/usr/local/Trolltech/Qt-4.7 --enable-debug=no --enable-symbols=no
```

This will start the configuration process. Depending on your computer, this process may take some time to finish. When it does, install the simage libraries by typing:
```
make 
make install
```

May be, you will need to type _sudo make install_ if you don't have enough privileges.


At the end of the installation process, the libraries will be installed at _/usr/local/lib_. Now, you can proceed to the installation of [Coin3D](InstallingCoin3DForLinux.md).


[Linux Configuration](InstallingForLinux.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)