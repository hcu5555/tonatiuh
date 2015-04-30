# Introduction #

[GoogleTest](http://code.google.com/p/googletest/) is a framework based on the xUnit architecture. This framework is to write test for C++ code and valid for the most common platforms.
Installation

# Details #
To build and install goolge test library, first, we must install python and cmake in our development environment.

## CMake ##
To obtain CMake follow this [link](http://www.cmake.org/cmake/resources/software.html) to go to the CMake webpage. Once you reach de webpage, download the latest binary version for Linux.

## Python ##
If you nedd to download python, ho to python [downloads](http://www.python.org/download/) web site. We need python 2.7 version.

## GoogleTest ##
Finally we have to download google test library sources. Downlaod them from the  [GoogleTest web site](http://code.google.com/p/googletest/), clicking on _"gtest-1.5.0.tar.gz"_. Store the download file in your computer.

Once the sources file is on your PC, open a shell console. Navigate to your download directory and extract the archive by typing:
```
tar -xzvf gtest-version.tar.gz
```

For build the library type:
```
cd gtest-version
mkdir mybuild
cd mybuild
cmake -G"Unix Makefiles" ..
make
```

Now, to install builded libray type:
```
cp -r ../include/gtest /usr/local/include
cp lib*.a /usr/local/lib
```

[Linux Configuration](InstallingForLinux.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)