# Introduction #

[GoogleTest](http://code.google.com/p/googletest/) is a framework based on the xUnit architecture. This framework is to write test for C++ code and valid for the most common platforms.
Installation

# Details #
To build and install goolge test library, first, we must install python and cmake in our development environment.

## CMake ##
To obtain CMake follow this [link](http://www.cmake.org/cmake/resources/software.html) to go to the CMake webpage. Once you reach de webpage, click on the link titled _"cmake-2.8.5-win32-x86.exe"_, which is the CMake binary installer for Windows. This will start the downloading of the CMake installer. When prompted, select the appropriate option to store the excutable file in your computer. Then, left-click twice on the installer and install CMake at the folder _"C:\sde\CMake"_.

## Python ##
Now, download python from the python [downloads](http://www.python.org/download/) web site. We need python 2.7 version, click _"Python 2.7 Windows installer"_. Store the excutable file in your computer. Then, left-click twice on the installer and install Python at the folder "C:\sde\Python-2.7".

## GoogleTest ##
Finally we have to download google test library sources. Downlaod them from the GoogleTest, clicking on ["gtest-1.6.0.zip"](http://code.google.com/p/googletest/downloads/detail?name=gtest-1.6.0.zip). Store the download file in your computer.

Once the sources file is on your PC, place it into the user directory under your MSYS folder and extract the archive. This will typically be _"C:\sde\MinGW\msys\1.0\home\username"_. Open an MSYS shell console and navigate to your MSYS user directory.

For build the library type:
```
export PATH=$PATH:/c/sde/CMake/bin:/c/sde/Python-2.7
cd gtest-version
mkdir mybuild
cd mybuild
cmake -G"MSYS Makefiles" ..
make
```

Now, to install builded libray type:
```
cp -r ../include/gtest /usr/local/include
cp lib*.a /usr/local/lib
```


[Windows Configuration](InstallingForWindows.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)