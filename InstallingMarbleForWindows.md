# Introduction #

Marble is a Virtual Globe and World Atlas. As a library, it is used within Tonatiuh to provide the geographical positioning functionalities needed, among other things, to facilitate the user the task of specifying the location on Earh of the solar concentrating systems she or he wants to analyze.

Here you will find instructions to install the Marble library in your computer and make this library available for the development of Tonatiuh.

# Details #

## CMake ##
To compile Marble you need CMake -a cross-platform make. To obtain it follow this [link](http://www.cmake.org/cmake/resources/software.html) to go to the CMake webpage. Once you reach de webpage, click on the link titled _"cmake-2.8.12.1-win32-x86.exe"_, which is the CMake binary installer for Windows (see Figure 1). This will start the downloading of the CMake installer. When prompted, select the appropriate option to store the excutable file in your computer. Then, left-click twice on the installer and install CMake at the folder _"C:\sde\CMake"_.

|<a href='https://picasaweb.google.com/lh/photo/iTHC8hGDk8Nj-ypClgbkFNMTjNZETYmyPJy0liipFm0?feat=embedwebsite'><img src='https://lh5.googleusercontent.com/-eSKy-5rJv-w/UqAll_6x0WI/AAAAAAAAAUs/eeLavPXob04/s400/CMakeDownload.png' height='287' width='400' /></a>|
|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 1.** View of the "CMake" webpage.|


## Git ##

To download the marble source code, you need to install _Git_ control version software. You can download it for windows from the following [link](http://git-scm.com/downloads). After the download process is finished install it.

## Marble ##
Now, you need to download the latest stable version of the [Marble](http://marble.kde.org/install.php) source code. Click the following
[link](https://projects.kde.org/projects/kde/kdeedu/marble/repository) to go to the repository. But to start the download process execute Git and select _"Clone Existing Repository"_. In the dialog define:
  * Source Location: _"git://anongit.kde.org/marble"_
  * Target Directory: _"C:/sde/MinGW/msys/1.0/home/username"_

Click _"Clone"_ to start the code download process. Before start with the compilation, it is necessary to do some changes in the code to avoid some compilation errors:
  * File _"src/CMakeLists.txt"_: Go to the line 57 and delete
```
# FIXME: The original QT4_ADD_RESOURCES should be extended to support this filetype too
#
# QT4_ADD_RESOURCE2(outfiles inputfile ... )
# TODO  perhaps consider adding support for compression and root options to rcc

if (MINGW)
MACRO (QT4_ADD_RESOURCES2 outfiles )

FOREACH (it ${ARGN})
  GET_FILENAME_COMPONENT(outfilename ${it} NAME_WE)
  GET_FILENAME_COMPONENT(infile ${it} ABSOLUTE)
  GET_FILENAME_COMPONENT(rc_path ${infile} PATH)
  SET(outfile ${CMAKE_CURRENT_BINARY_DIR}/${outfilename}_res.o)
  #  parse file for dependencies
  FILE(READ "${infile}" _RC_FILE_CONTENTS)
  STRING(REGEX MATCHALL "<file>[^<]*" _RC_FILES "${_RC_FILE_CONTENTS}")
  SET(_RC_DEPENDS)
  FOREACH(_RC_FILE ${_RC_FILES})
    STRING(REGEX REPLACE "^<file>" "" _RC_FILE "${_RC_FILE}")
    SET(_RC_DEPENDS ${_RC_DEPENDS} "${rc_path}/${_RC_FILE}")
  ENDFOREACH(_RC_FILE)
  ADD_CUSTOM_COMMAND(OUTPUT ${outfile}
    COMMAND windres
    ARGS -i ${infile} -o ${outfile} --include-dir=${CMAKE_CURRENT_SOURCE_DIR}
    MAIN_DEPENDENCY ${infile}
    DEPENDS ${_RC_DEPENDS})
  SET(${outfiles} ${${outfiles}} ${outfile})
ENDFOREACH (it)

ENDMACRO (QT4_ADD_RESOURCES2)
ENDIF(MINGW)
```
  * File _"src/apps/marble-qt/CMakeLists.txt"_: go to the line 5 and delete
```
if(MSVC)
  set(marble_SRCS ${marble_SRCS} marble.rc)
endif(MSVC)

if(MINGW)
   QT4_ADD_RESOURCES2(marble_SRCS marble.rc)
endif(MINGW)
```
  * File _"src/apps/marble-ui/CMakeLists.txt"_: go to line 4 and delete
```
if(MSVC)
  set(marble_SRCS ${marble_SRCS} marble.qrc)
endif(MSVC)

if(MINGW)
   QT4_ADD_RESOURCES2(marble_SRCS marble.qrc)
endif(MINGW)
```


After doing these changes in the marble source code, using the MSYS shell navigate to the marble directory just created in your computer and type:
```
export QTDIR=/c/sde/Qt/Desktop/Qt/version/mingw
export PATH=$QTDIR/bin:$PATH:/c/sde/CMake/bin
```

The command to create Makefiles on release mode is:
```
$ cmake -G"MSYS Makefiles" -DQTONLY=ON -DCMAKE_INSTALL_PREFIX=. -DPACKAGE_ROOT_PREFIX=. -DCMAKE_BUILD_TYPE=Release ../marble
```

Then,
```
make
make install
```

Copy Marble include files to the folder "/local/include/marble".
```
$ cp -r include/marble /usr/local/include
```
Copy executable files to the folder "/local/local/bin".
```
cp src/marble.exe /usr/local/bin
cp src/tilecreator/tilecreator.exe /usr/local/bin
cp src/lib/geodatatest.exe /usr/local/bin
```
Copy main library files to the appropriate "/usr/local" folders.
```
cp src/lib/marble/libmarblewidget.dll /usr/local/bin
cp src/lib/marble/libmarblewidget.dll.a /usr/local/lib
```
Copy Marble plugins to the folder "/usr/local/bin/marble".
```
mkdir -p /usr/local/bin/marble
cp src/plugins/network/qnam/libQNamNetworkPlugin.dll /usr/local/bin/marble
cp src/plugins/render/compass/libCompassFloatItem.dll /usr/local/bin/marble 
cp src/plugins/render/crosshairs/libCrosshairsPlugin.dll /usr/local/bin/marble
cp src/plugins/render/graticule/libGraticulePlugin.dll /usr/local/bin/marble
cp src/plugins/render/mapscale/libMapScaleFloatItem.dll /usr/local/bin/marble
cp src/plugins/render/navigation/libNavigationFloatItem.dll /usr/local/bin/marble
cp src/plugins/render/overviewmap/libOverviewMap.dll /usr/local/bin/marble
cp src/plugins/render/photo/libPhoto.dll /usr/local/bin/marble
cp src/plugins/render/progress/libProgressFloatItem.dll /usr/local/bin/marble
cp src/plugins/render/stars/libStarsPlugin.dll /usr/local/bin/marble
cp src/plugins/render/weather/libWeather.dll /usr/local/bin/marble 
cp src/plugins/render/wikipedia/libWikipedia.dll /usr/local/bin/marble
```
At the end of the process, the Marble dynamic library _"libmarblewidget.dll"_ and the programs _"marble.exe"_ and _"tilecreator.exe"_ will be installed at the folder _"C:\sde\MinGW\msys\1.0\local\bin"_. The plugins _"ibCompassFloatItem.dll"_, _"libCrosshairsPlugin.dll"_, _"libGeoRendererPlugin.dll"_, _"libMapScaleFloatItem.dll"_, _"libNavigationFloatItem.dll"_, _"libOverviewMap.dll"_, and _"libStarsPlugin.dll"_ will be installed at the folder _"C:\sde\MinGW\msys\1.0\local\bin\marble"_ and the Marble library file "libmarblewidget.dll.a" will be installed at the folder _"C:\sde\MinGW\msys\1.0\local\lib"_. In addition, the necessary include files will be installed at the folder _"C:\sde\MinGW\msys\1.0\local\include\marble"_.

Once the Marble library is installed the next step is to install the SQLite. To do it, follow the instructions in the following wiki page: [Installing SQLite](InstallingQSLiteForWindows.md)

[Windows Configuration](InstallingForWindows.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)