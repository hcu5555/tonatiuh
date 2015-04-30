# Requirements #

  * SunStudio installed and updated.
  * Qt + QtWebkit compiled and installed.
  * Simage compiled and installed.
  * Coin3D compiled and installed.
  * The address of the cc and CC compiler commands in the PATH.

# Details #

From the following link [http://ftp.coin3d.org/coin/src/all/SoQt-1.5.0.tar.gz](http://ftp.coin3d.org/coin/src/all/SoQt-1.5.0.tar.gz), download _"SoQt-1.5.0.tar.gz"_.

Extract the content of the downloaded tar.gz file into your _"Downloads"_ folder. This will create a new folder under _"Downloads"_ entitled: _"SoQt-1.5.0"_.

Open a shell command as super user. Navigate to the recently created _"SoQt-1.5.0"_ command and type the following shell commands as super user:

```
export COINDIR="/usr/local"
export INCLUDE="/usr/local/include:/usr/local/Trolltech/Qt-4.6.2/include"
export CXXFLAGS='-library=stlport4'
export LIBS='-lCrun -lm'
```

Once this is done, you are ready to configure, make, and install the SoQt library by typing the following shell commands as super user:

```
./configure --enable-debug=no --enable-symbols=no --with-coin=/usr/local --with-qt=/usr/local/Trolltech/Qt-4.6.2 
make
pfexec make install
```

At the end of the installation process, the SoQt library will be installed at _"/usr/local/lib"_. Now, you can proceed to the installation of [Marble](InstallingMarbleForOpenSolaris.md).


[OpenSolaris Configuration](InstallingForOpenSolaris.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)