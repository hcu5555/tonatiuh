# CppUnit #

CppUnit is the C++ port of the famous JUnit framework for unit testing. Test output is in XML or text format for automatic testing and GUI based for supervised tests.


First, download source files from [CppUnit Project Site](http://sourceforge.net/projects/cppunit/). Place into your home directory, typically be _c:\msys\usr\home\username_. Open a MSYS console and navigate to your directory. Extract archive file typing:
```
 tar -xzvf cppunit-1.12.1.tar.gz
```

Now, configure and install:
```
 cd cppunit-1.12.1
./configure
make 
make install
```

## QxRunner ##

[QxRunner](http://qxrunner.systest.ch/qxrunner/) is a library to develop C++ GUI applications to execute user selected items from a list.

The QxRunner for CppUnit (QxCppUnit) library provides a GUI frontend for CppUnit test execution, shortly called the QxTestRunner.

Download library source files from [QxRunner Project Site](http://qxrunner.systest.ch/common/download.htm). The current version is qxrunner 0.9.2.Extract files tiping the following command in a shell:
```
 tar -xzvf qxrunner.0.9.2.tar.gz
```

First, create qxrunner library.
```
 cd qxrunner/src/qxrunner
```

Open qxrunner.pro file with text editor and replace content with:
```
 TEMPLATE = lib

CONFIG += debug_and_release

RESOURCES   += resources/qxrunner.qrc
DEPENDPATH  += ../../include/qxrunner
INCLUDEPATH += . $$DEPENDPATH

DEFINES += QXRUNNER_DLL_BUILD

HEADERS = \
        aboutdialog.h \
        appsettings.h \
        columnsdialog.h \
        proxymodelcommon.h \
        qxrunner_global.h \
        resultsmodel.h \
        resultsproxymodel.h \
        resultsviewcontroller.h \
        runner.h \
        runneritem.h \
        runnermodel.h \
        runnermodelthread.h \
        runnerproxymodel.h \
        runnerviewcontroller.h \
        runnerwindow.h \
        runnerwindowclient.h \
        settingsdialog.h \
        statuswidget.h \
        stoppingdialog.h \
        utils.h \
        viewcontrollercommon.h
        
SOURCES = \
        aboutdialog.cpp \
        appsettings.cpp \
        columnsdialog.cpp \
        proxymodelcommon.cpp \
        qxrunner_global.cpp \
        resultsmodel.cpp \
        resultsproxymodel.cpp \
        resultsviewcontroller.cpp \
        runner.cpp \
        runneritem.cpp \
        runnermodel.cpp \
        runnermodelthread.cpp \
        runnerproxymodel.cpp \
        runnerviewcontroller.cpp \
        runnerwindow.cpp \
        runnerwindowclient.cpp \
        settingsdialog.cpp \
        statuswidget.cpp \
        stoppingdialog.cpp \
        utils.cpp \
        viewcontrollercommon.cpp

INTERFACES = \
        aboutdialog.ui \
        columnsdialog.ui \
        runnerwindow.ui \
        settingsdialog.ui \
        statuswidget.ui \
        stoppingdialog.ui

DESTDIR = ../../lib
TARGET = qxrunner
contains( TEMPLATE, lib ){
    CONFIG( debug, debug|release){
         TARGET=$$member(TARGET,0)d
    }
}
```

Now, type in the shell and execute the following commands:
```
qmake qxrunner.pro
make all
```

The qxrunner lib is created. Follow creating qxcppunit lib:
```
cd ../qxcppunit
```

Set CPPUNIT environment varible with
```
export CPPUNIT=/usr/local
```

Then, edit qxcppunit.pro file replacing the content with:
```
TEMPLATE = lib

CONFIG += debug_and_release

DEFINES += QXCPPUNIT_DLL_BUILD
DEFINES += QXRUNNER_DLL
DEFINES += CPPUNIT_DLL


DEPENDPATH  += $$(HOME)/qxrunner/include/qxcppunit
INCLUDEPATH += . $$DEPENDPATH ../../include $$(CPPUNIT)/include/

LIBS += -L"../../lib" -lqxrunner -L$$(CPPUNIT)/lib -lcppunit



HEADERS = \
        cppunititem.h \
        cppunitmodel.h \
        qxcppunit_global.h \
        testrunner.h

SOURCES = \
        cppunititem.cpp \
        cppunitmodel.cpp \
        testrunner.cpp

RESOURCES   += resources/qxcppunit.qrc

DESTDIR = ../../lib
TARGET = qxcppunit
contains( TEMPLATE, lib ){
    CONFIG( debug, debug|release){
         TARGET=$$member(TARGET,0)d
    }

}
```

Save changes before close editor. Type on the shell:
```
qmake qxcppunit.pro
make
```

After finish copy necesary files to /usr/local using the commands:
```
cd ../..
cp -r include/* /usr/local/include
cp lib/*.dll /usr/local/bin
cp lib/*.a /usr/local/lib
```

[WindowsConfiguration](InstallingForWindows.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)