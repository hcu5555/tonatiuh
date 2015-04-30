mary Procedure to install Coin3D for Mac

# Coin3D #

Coin 3D is a high-level 3D graphics toolkit for developing cross-platform real-time 3D visualization and visual simulation software. Install Qt before start with the installation.

# Details #

Download the latest realese of Coin3D, currently [Coin3D-3.1.3](http://www.coin3d.org/lib/coin/releases/3.1.3), from the [Coin3D](http://www.coin3d.org/) website at http://www.coin3d.org/lib/plonesoftwarecenter_view. Place it into the desktop.

Open a shell console and navigate to desktop and extract the archive by typing:
```
tar xvf Coin-3.1.3.tar
```

This will create a directory called _Coin-3.1.3_ in your user directory. Using the shell navigate to just created directory. First create release libraries by typing:
```
./configure --enable-debug=no --without-framework
```

This will start the configuration process. Depending on your computer, this process may take some time to finish. To solve an error in the compilation open SoVertexArrayIndexer.cpp at Coin-3.1.3/src/misc
and replace
```
const int32_t * src = this->indexarray.getArrayPtr();
```
by
```
const int32_t * src = (const int32_t *) this->indexarray.getArrayPtr();
```
When it does, install the coin libraries by typing:
```
make 
make install
```

At the end of the installation process, the libraries hab been installed at /usr/local directory. Now, [SoQt](InstallingSoQtForMac.md) installation can be started.


[Mac Configuration](InstallingForMac.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)