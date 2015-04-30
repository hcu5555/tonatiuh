# Introduction #

[SoQt](http://doc.coin3d.org/SoQt/) is a library that provides the glue between Systems in Motion's Coin high-level 3D visualization library and Trolltech's Qt 2D user interface library. This pages provides instruction regarding how to install SoQt in your computer under Linux.

Before installing SoQt, please, verify that Qt and Coin 3D are already installed and functioning on your PC. If they are not, install them first by following the corresponding installation procedures InstallingQtForLinux and [InstallingCoin3DForLinux](InstallingCoin3DForLinux.md).

# Details #
Download the latest release of the SoQt, currently SoQt 1.5.0. To do it, click on the following [link](http://www.coin3d.org/lib/soqt/releases/1.5.0) to go to the _"SoQt 1.5.0"_ webpage of the Coin website. Once you reach the webpage, click on the link titled _"Get SoQt 1.5.0 for all platforms"_ (see Figure 1). This will start the downloading of the SoQt source package. When prompted if to open or to store the file in your computer, place it on your "downloads" directory, e.g., /home/downloads. .

|<a href='http://picasaweb.google.com/lh/photo/3r_TwpwkMdF2hc8h-_Ggq8kjYPHGJOebwiJHbWK4XiY?feat=embedwebsite'><img src='http://lh4.ggpht.com/_tmEVMS15i5Y/TLCToThqs9I/AAAAAAAAAnY/yWkESmsWGPQ/s400/SoQt_sourcecode.png' height='261' width='400' /></a>|
|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 1.** View of the "SoQt 1.5.0" webpage.|

Open a shell console, navigate to downlaod directory and extract the archive by typing:
```
tar -zxvf SoQt-1.5.0.tar.gz
```
This will create a directory called _SoQt-1.5.0_ in your user directory. Using the shell navigate to the just created SoQt-1.5.0. directory and type:
```
export COINDIR="/usr/local"
export INCLUDE="/usr/local/include:/usr/local/Trolltech/Qt-4.7/qt/include"
```

Type configure command for release build:
```
./configure --enable-debug=no --enable-symbols=no --with-coin=/usr/local --with-qt=/usr/local/Trolltech/Qt-4.7/qt
```

This will start the configuration process. This process should finish succesfully with the following message:
```
SoQt configuration settings:
  Open Inventor brand:  Coin
  Static Materials:     Yes
  Installation Prefix:  /usr/local

Now, run 'make install' to build and install SoQt.
```

Then, to install the SoQt libraries type:
```
make
make install
```

Once the SoQt library is installed the next step is to install the Marble library. To do it, follow the instructions in the following wiki page: [Installing Marble for Linux](InstallingMarbleForLinux.md).

[Linux Configuration](InstallingForLinux.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)