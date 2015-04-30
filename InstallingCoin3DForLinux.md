![http://tonatiuh.googlecode.com/svn/wiki/images/coin3d/coin3dLogo.png](http://tonatiuh.googlecode.com/svn/wiki/images/coin3d/coin3dLogo.png)

[Coin3D](http://www.coin3d.org/) is a high-level 3D graphics toolkit for developing cross-platform real-time 3D visualization and visual simulation software. This toolkit is implemented as a library. The Coin library is used within Tonatiuh to implement the programs 3D views of the concentrating system being simulated and to provide the architecture for the underlying 3D scene graph.

Here you will find instructions to install the Coin library in your computer and make this library available for the development of Tonatiuh.

# Details #


Download the latest realese of the Coin source package, currently Coin 3.1.3. To do it, click on the following [link](http://www.coin3d.org/lib/coin/releases/3.1.3) to go to the _"Coin 3.1.3"_ webpage of the Coin website. Once you reach the webpage, click on the link titled _"Get Coin 3.1.3 for all platforms"_ (see Figure 1). This will start the downloading of the Coin source package. When prompted if to open or to store the file in your computer, place it on your "downloads" directory, e.g., _/home/downloads_.

|<a href='http://picasaweb.google.com/lh/photo/-naD-qhTWm5Enmd6x7NC8ckjYPHGJOebwiJHbWK4XiY?feat=embedwebsite'><img src='http://lh6.ggpht.com/_tmEVMS15i5Y/TLAk0sBPMjI/AAAAAAAAAm0/yYLsUjdZ8Ag/s400/Coin_sourcecode.png' height='298' width='400' /></a>|
|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 1.** View of the "Coin 1.3.1" webpage.|

Open a shell console, navigate to your download directory, and extract the content of the installer file by typing:
```
tar -zxvf Coin-3.1.3.tar.gz
```

This will create a directory called _Coin-3.1.3_ in your download directory. Using the shell, navigate to just created Coin3.1.3 directory.

Type the following command to build the release version of the Coin3D library:
```
./configure
```

This will start the configuration process. Depending on your computer, this process may take some time to finish. When it does, install the Coin3D libraries by typing:
```
make 
make install
```

The installation process may take several hours.

At the end of the installation process, the libraries will be installed at /usr/local/lib. Now, you can proceed to the installation of [SoQt](InstallingSoQtForLinux.md).

[Linux Configuration](InstallingForLinux.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)