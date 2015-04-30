# Requirements #

  * SunStudio installed and updated.
  * Qt + QtWebkit compiled and installed.

# Details #

From the following link [http://ftp.coin3d.org/coin/src/all/simage-1.7.0.tar.gz](http://ftp.coin3d.org/coin/src/all/simage-1.7.0.tar.gz), download _"simage-1.7.0.tar.gz"_.

Extract the content of the downloaded tar.gz file into your _"Downloads"_ folder. This will create a new folder under _"Downloads"_ entitled: _"simage-1.7.0"_.

After that, download the patch file _"opensolaris\_simage-patch-configure.diff"_ from the following link [opensolaris\_simage-patch-configure.diff](http://tonatiuh.googlecode.com/files/opensolaris_simage-patch-configure.diff) and copy it to the just created _"simage-1.7.0"_ folder.

Once this is done, open a shell command with super user rights, navigate to the _"simage-1.7.0"_ folder and apply the patch by executing the following command:

```
patch -p0 < patch-configure.diff
```

_Note: the patch command that should be executed is the GNU patch, if in your system implementation that is not the default patch command, you should either make it the default, or replace the "patch" command for the correct command to invoke the GNU patch command in your system. In our case, that command was **"gpatch".**_

After the patch has been successfully applied, configure, make and install the simage library by executing the following commands in the shell as super user:

```
./configure --with-qt=/usr/local/Trolltech/Qt-4.6.2 --enable-qimage --enable-debug=no --enable-symbols=no CXXFLAGS='-library=stlport4'
make
pfexec make install
```

At the end of the installation process, the Simage library will be installed at _"/usr/local/lib"_. Now, you can proceed to the installation of [Coin3D](InstallingCoin3DForOpenSolaris.md).


[OpenSolaris Configuration](InstallingForOpenSolaris.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)