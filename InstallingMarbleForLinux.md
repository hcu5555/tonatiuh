# Marble - Desktop Globe #

Marble is a Virtual Globe and World Atlas that you can use to learn more about Earth: You can pan and zoom around and you can look up places and roads. A mouse click on a place label will provide the respective Wikipedia article.

# Details #
To compile marble you need CMake -a cross-platform make. It can be download from http://www.cmake.org/cmake/resources/software.html. Download the latest binary version for Linux. You need a version newer than 2.4.

Now, you need to download the latest stable version of the Marble source code. To do it, go here:
http://edu.kde.org/marble/download.php

After dowloadin the marble source code, please uncomres it to a folder called _marble_ and, using the shell, navigate to the marble directory just created in your computer and type:
```
cmake -G"Unix Makefiles" -DQTONLY=ON ../marble
```

To build the library type:
```
make
```

Copy marble include files to the folder "/usr/local/include/marble".
```
mkdir -p /usr/local/include/marble
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

Copy main library files to the appropriate "/usr/local" folders.
```
cp src/lib/libmarblewidget.so* /usr/local/lib
```

Copy mable plugins to the folder "/usr/local/bin/marble".
```
mkdir -p /usr/local/bin/marble 
cp -u src/plugins/network/qnam/libQNamNetworkPlugin.so /usr/local/bin/marble
cp -u src/plugins/render/compass/libCompassFloatItem.so /usr/local/bin/marble 
cp -u src/plugins/render/crosshairs/libCrosshairsPlugin.so /usr/local/bin/marble
cp -u src/plugins/render/graticule/libGraticulePlugin.so /usr/local/bin/marble
cp -u src/plugins/render/mapscale/libMapScaleFloatItem.so /usr/local/bin/marble
cp -u src/plugins/render/navigation/libNavigationFloatItem.so /usr/local/bin/marble
cp -u src/plugins/render/overviewmap/libOverviewMap.so /usr/local/bin/marble
cp -u src/plugins/render/photo/libPhoto.so /usr/local/bin/marble
cp -u src/plugins/render/positionmarker/libPositionMarker.so /usr/local/bin/marble
cp -u src/plugins/render/progress/libProgressFloatItem.so /usr/local/bin/marble
cp -u src/plugins/render/routing/libRoutingPlugin.so /usr/local/bin/marble
cp -u src/plugins/render/positionmarker/libPositionMarker.so /usr/local/bin/marble
cp -u src/plugins/render/stars/libStarsPlugin.so /usr/local/bin/marble
cp -u src/plugins/render/weather/libWeather.so /usr/local/bin/marble 
cp -u src/plugins/render/wikipedia/libWikipedia.so /usr/local/bin/marble
```

Once the Marble library is installed the next step is to install the Marble library. To do it, follow the instructions in the following wiki page: [Installing SQLite for Linux](InstallingSQLiteForLinux.md).

[Linux Configuration](InstallingForLinux.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)