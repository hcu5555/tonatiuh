# Introduction #

Marble is a Virtual Globe and World Atlas. As a library, it is used within Tonatiuh to provide the geographical positioning functionalities needed, among other things, to facilitate the user the task of specifying the location on Earh of the solar concentrating systems she or he wants to analyze.

Here you will find instructions to install the Marble library in your computer and make this library available for the development of Tonatiuh.

# Details #

To compile Marble you need CMake -a cross-platform make. To obtain it follow this [link](http://www.cmake.org/cmake/resources/software.html) to go to the CMake webpage. Once you reach de webpage, click on the link titled _"cmake-2.8.5-win32-x86.exe"_, which is the CMake binary installer for Windows (see Figure 1). This will start the downloading of the CMake installer. When prompted, select the appropriate option to store the excutable file in your computer. Then, left-click twice on the installer and install CMake at the folder _"C:\sde\CMake"_.

|<a href='http://picasaweb.google.com/lh/photo/5Iue-oDOBsZN6zeEpmRBQMkjYPHGJOebwiJHbWK4XiY?feat=embedwebsite'><img src='http://lh5.ggpht.com/_tmEVMS15i5Y/TLDLa3oJp1I/AAAAAAAAAn4/mZPF8osxLas/s400/CMake_installer.png' height='338' width='400' /></a>|
|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 1.** View of the "CMake" webpage.|

Now, you need to download the latest stable version of the Marble source code. To do it, you need a git client and use one of these commands:
```
git clone -b KDE/4.6 git://anongit.kde.org/marble
```
or
```
git clone -b marble-1.1 git://anongit.kde.org/marble
```

Before start with the compilation, it is necessary to do some changes in the code to avoid some compilation errors:
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


After doing these changes intoe marble source code, using the MSYS shell navigate to the marble directory just created in your computer and type:
```
export QTDIR=/c/sde/qt-version
export PATH=$QTDIR/bin:$PATH:/c/sde/CMake/bin
```

The command to create Makefiles on release mode is:
```
cmake -G"MSYS Makefiles" -Wno-dev -DQTONLY=ON -DCMAKE_INSTALL_PREFIX=/usr/local -DCMAKE_BUILD_TYPE=Release ../marble
```

Then,
```
make
make install
```


Copy to lib folder:
```
cp src/lib/marble/libmarblewidget.dll.a /usr/local/lib
```

Move Marble library and executable to bin folder.
```
cd /usr/local
mv *.dll bin
mv *.exe bin
```

At the end of the process, the Marble dynamic library _"libmarblewidget.dll"_ and the programs _"marble.exe"_ and _"tilecreator.exe"_ will be installed at the folder _"C:\sde\MinGW\msys\local\bin"_. The plugins _"ibCompassFloatItem.dll"_, _"libCrosshairsPlugin.dll"_, _"libGeoRendererPlugin.dll"_, _"libMapScaleFloatItem.dll"_, _"libNavigationFloatItem.dll"_, _"libOverviewMap.dll"_, and _"libStarsPlugin.dll"_ will be installed at the folder _"C:\sde\MinGW\msys\local\bin\marble"_ and the Marble library file "libmarblewidget.dll.a" will be installed at the folder _"C:\sde\MinGW\msys\local\lib"_. In addition, the necessary include files will be installed at the folder _"C:\sde\MinGW\msys\local\include\marble"_.

Once the Marble library is installed the next step is to install the Eclipse Integrated Development Environment (IDE). To do it, follow the instructions in the following wiki page: [Installing SQLite](InstallingSQLiteForWindows64.md)


[Windows 64 Bit Configuration](InstallingForWindows64.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)