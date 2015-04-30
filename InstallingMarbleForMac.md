# Marble - Desktop Globe #

## Introduction ##
Marble is a Virtual Globe and World Atlas that you can use to learn more about Earth: You can pan and zoom around and you can look up places and roads. A mouse click on a place label will provide the respective Wikipedia article.

## Details ##
To compile marble you need CMake, a cross-platform make. You can obtain it from http://www.cmake.org/cmake/resources/software.html. Download the last version of cmake for unix, you need a version newer than 2.4. Install CMake at _/usr/local_ by:
```
tar xvf cmake-version.tar
./configure
make
make install
```

Now, you need to download the latest stable version of the Marble source code. To do it, you need to use a subversion or svn client to access the appropriate Marble's svn repository and check out the appropriate marble folder, with all of its content, including all files and subdirectories.

If you have installed in your computer a command-line svn client, the command you should execute in your shell to get the marble folder with all its content is:
```
svn co svn://anonsvn.kde.org/home/kde/branches/KDE/4.5/kdeedu/marble
```

Now, download the source files from http://edu.kde.org/marble/download.php link. Place it into downloads under your home folder. This will typically be  /home/username/downloads. Open a shell console and navigate to downloads directory. Extract the archive by typing:

```
tar xvf marble-version.tar.gz
```

This will create a directory called _marble-version_ in your user directory. Using the shell navigate to just created marble-version directory and type:
```
export QTDIR=/usr/local/Trolltech/Qt-4.7.0
export PATH=$PATH:$QTDIR/bin:/usr/local/bin
```

The command to create Makefiles on release mode is:
```
cmake -G"Unix Makefiles" -Wno-dev -DQTONLY=ON ../marble
```

Then,
```
make
```


Copy marble include files to the folder "/local/include/marble".
```
mkdir /usr/local/include/marble
cp src/lib/*.h /usr/local/include/marble 
cp src/lib/blendings/*.h /usr/local/include/marble 
cp src/lib/geodata/*.h /usr/local/include/marble 
cp src/lib/geodata/data/*.h /usr/local/include/marble 
cp src/lib/geodata/graphicsitem/*.h /usr/local/include/marble 
cp src/lib/geodata/handlers/dgml/*.h /usr/local/include/marble 
cp src/lib/geodata/handlers/gpx/*.h /usr/local/include/marble 
cp src/lib/geodata/handlers/kml/*.h /usr/local/include/marble 
cp src/lib/geodata/handlers/osm-namefinder/*.h /usr/local/include/marble 
cp src/lib/geodata/parser/*.h /usr/local/include/marble 
cp src/lib/geodata/scene/*.h /usr/local/include/marble
cp src/lib/geodata/writer/*.h /usr/local/include/marble  
cp src/lib/geodata/writers/kml/*.h /usr/local/include/marble 
cp src/lib/graphicsview/*.h /usr/local/include/marble
cp src/lib/graphicsview/screengraphicsitem/*.h /usr/local/include/marble  
cp src/lib/Projections/*.h /usr/local/include/marble
cp src/lib/routing/*.h /usr/local/include/marble
cp src/lib/routing/instructions/*.h /usr/local/include/marble 
```

Copy executable files to the folder "/local/include/bin".
```
cp -r src/marble.app /usr/local/bin
cp src/tilecreator/tilecreator /usr/local/bin
cp src/lib/geodatatest /usr/local/bin
```

Copy main library files to the appropriate "/usr/local" folders.
```
cp src/lib/libmarblewidget*.dylib /usr/local/lib
```

Copy mable plugins to the folder "/usr/local/bin/marble".
```
mkdir /usr/local/bin/marble 
cp src/plugins/network/qnam/libQNamNetworkPlugin.so /usr/local/bin/marble
cp src/plugins/render/compass/libCompassFloatItem.so /usr/local/bin/marble 
cp src/plugins/render/crosshairs/libCrosshairsPlugin.so /usr/local/bin/marble
cp src/plugins/render/graticule/libGraticulePlugin.so /usr/local/bin/marble
cp src/plugins/render/mapscale/libMapScaleFloatItem.so /usr/local/bin/marble
cp src/plugins/render/navigation/libNavigationFloatItem.so /usr/local/bin/marble
cp src/plugins/render/overviewmap/libOverviewMap.so /usr/local/bin/marble
cp src/plugins/render/photo/libPhoto.so /usr/local/bin/marble
cp src/plugins/render/positionmarker/libPositionMarker.so /usr/local/bin/marble
cp src/plugins/render/progress/libProgressFloatItem.so /usr/local/bin/marble
cp src/plugins/render/routing/libRoutingPlugin.so /usr/local/bin/marble
cp src/plugins/render/positionmarker/libPositionMarker.so /usr/local/bin/marble
cp src/plugins/render/stars/libStarsPlugin.so /usr/local/bin/marble
cp src/plugins/render/weather/libWeather.so /usr/local/bin/marble 
cp src/plugins/render/wikipedia/libWikipedia.so /usr/local/bin/marble
```

Once the Marble library is installed the next step is to install the Marble library. To do it, follow the instructions in the following wiki page: [Installing Berkeley DB for Mac](InstallingBerkeleyDBForMac.md).

[Mac Configuration](InstallingForMac.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)