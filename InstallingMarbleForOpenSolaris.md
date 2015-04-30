# Requirements #

  * SunStudio installed and updated.
  * Qt + QtWebkit compiled and installed.
  * CMake installed (can be done using OpenSolaris' Package Manager)

# Details #

From the following link [http://developer.kde.org/~tackat/marble/marble-0.8.0\_rev1005857.tar.gz](http://developer.kde.org/~tackat/marble/marble-0.8.0_rev1005857.tar.gz), download _"marble-0.8.0\_rev1005857.tar.gz"_.

Extract the content of the downloaded tar.gz file into your _"Downloads"_ folder. This will create a new folder under _"Downloads"_ entitled: _"marble"_.

After that, download the patch file _"opensolaris-marble-geopolygon.diff"_ from the following link [opensolaris-marble-geopolygon.diff](http://tonatiuh.googlecode.com/files/opensolaris-marble-geopolygon.diff) and copy it to the just created _"marble"_ folder.

Once this is done, open a shell command with super user rights, navigate to the _"marble"_ folder and apply the patch by executing the following command:

```
patch -p0 < opensolaris-marble-geopolygon.diff 
```

_Note: the patch command that should be executed is the GNU patch, if in your system implementation that is not the default patch command, you should either make it the default, or replace the "patch" command for the correct command to invoke the GNU patch command in your system. In our case, that command was **"gpatch".**_

After the patch has been successfully applied, execute the following shell command as super user:

```
export PATH=/usr/local/Trolltech/Qt-4.6.2/bin:$PATH
```

Now, invoke CMake to generate the appropriate make file by executing the following shell command as super user:

```
cmake -G"Unix Makefiles" -DQTONLY=ON ../marble
```

After the cmake command ends -which may take some time- you can make and install the Marble libraries by executing the following shell commands as super user:

```
make
mkdir /usr/local/include/marble
	
cp src/lib/*.h /usr/local/include/marble
cp src/lib/AbstractLayer/*.h /usr/local/include/marble
cp src/lib/geodata/*.h /usr/local/include/marble
cp src/lib/geodata/data/*.h /usr/local/include/marble
cp src/lib/geodata/handlers/dgml/*.h /usr/local/include/marble
cp src/lib/geodata/handlers/gpx/*.h /usr/local/include/marble
cp src/lib/geodata/handlers/kml/*.h /usr/local/include/marble
cp src/lib/geodata/parser/*.h /usr/local/include/marble
cp src/lib/geodata/scene/*.h /usr/local/include/marble
cp src/lib/gps/*.h /usr/local/include/marble
cp src/lib/Projections/*.h /usr/local/include/marble

cp src/lib/libmarblewidget.so* /usr/local/lib

mkdir -p /usr/local/bin/marble/plugins
	
cp src/plugins/network/qnam/libQNamNetworkPlugin.so  /usr/local/bin/marble/plugins
cp src/plugins/render/compass/libCompassFloatItem.so /usr/local/bin/marble/plugins
cp src/plugins/render/crosshairs/libCrosshairsPlugin.so /usr/local/bin/marble
cp src/plugins/render/geodata/libGeoRendererPlugin.so /usr/local/bin/marble
cp src/plugins/render/graticule/libGraticulePlugin.so /usr/local/bin/marble
cp src/plugins/render/mapscale/libMapScaleFloatItem.so /usr/local/bin/marble
cp src/plugins/render/navigation/libNavigationFloatItem.so /usr/local/bin/marble
cp src/plugins/render/overviewmap/libOverviewMap.so /usr/local/bin/marble
cp src/plugins/render/photo/libPhoto.so /usr/local/bin/marble
cp src/plugins/render/stars/libStarsPlugin.so /usr/local/bin/marble
cp src/plugins/render/wikipedia/libWikipedia.so /usr/local/bin/marble
```

At the end of the installation process, the Marble libraries will be installed at _"/usr/local/lib"_. Now, you can proceed to the installation of [Berkeley DB](InstallingBerkeleyDBForOpenSolaris.md).


[OpenSolaris Configuration](InstallingForOpenSolaris.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)