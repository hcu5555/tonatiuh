# Requirements #

  * SunStudio installed and updated.
  * Qt + QtWebkit compiled and installed.
  * Simage compiled and installed.
  * The address of the cc and CC compiler commands in the PATH.

# Details #

From the following link [http://ftp.coin3d.org/coin/src/all/Coin-3.1.3.tar.gz](http://ftp.coin3d.org/coin/src/all/Coin-3.1.3.tar.gz), download _"Coin-3.1.3.tar.gz"_.

Extract the content of the downloaded tar.gz file into your _"Downloads"_ folder. This will create a new folder under _"Downloads"_ entitled: _"Coin-3.1.3"_.

From the following link [http://tonatiuh.googlecode.com/files/opensolaris-parches-Coin3d.tar.bz2](http://tonatiuh.googlecode.com/files/opensolaris-parches-Coin3d.tar.bz2) download the file containing the parches that need to be applied to the Coin3D source files, in order to compile the !Coin3D libraries for OpenSolaris.

Extract the content of the downloaded tar.bz2 file into your _"Downloads"_ folder. This will create a new folder under _"Downloads"_ entitled: _"opensolaris-parches-Coin3d"_.

Copy all the files contained in that folder and paste them into the folder _"Coin-3.1.3"_. Then, open a command shell as super user, move to the _"Coin-3.1.3"_ folder, and execute the .sh file entitled _"parchearArchivos.sh"_ by entering:

```
./parchearArchivos.sh
```

The _"patch"_ command that the file _"parchearArchivos.sh"_ is supposed to execute is the GNU patch command. If the _"patch"_ command that executes by default in your OpenSolaris implementation is not the GNU patch command, you may get error or warning messages while executing _"parchearArchivos.sh"_. Should that be the case, you can either change your OpenSolaris implementation to ensure that the default _"patch"_ command is the GNU patch, or you can edit _"parchearArchivos.sh"_ to replace the invocations to _"patch"_ with invocations to _"gpatch"_

Once the patches are successfully applied, you may configure, make, and install by by typing the following shell commands as super user:

```
./configure CXXFLAGS='-library=stlport4' LIBS='-lCrun -lm'
make
pfexec make install
```

At the end of the installation process, the Coin3D libraries will be installed at _"/usr/local/lib"_. Now, you can proceed to the installation of [SoQt](InstallingSoQtForOpenSolaris.md).


[OpenSolaris Configuration](InstallingForOpenSolaris.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)