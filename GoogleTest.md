# Introduction #

[GoogleTest](http://code.google.com/p/googletest/) is a framework based on the xUnit architecture. This framework is to write test for C++ code and valid for the most common platforms.
Installation

# Details #
To build and install goolge test library, first, we must install python and cmake in our development environment.

## CMake ##
To obtain CMake, cross-platform make, follow this [link](http://www.cmake.org/cmake/resources/software.html) to go to the CMake webpage. Once you reach de webpage, click on the last stable cmake version for unix platform, _"cmake-versión.tar.gz"_. This will start the downloading of the CMake sources. When prompted, select the appropriate option to store the excutable file in your computer. Then, open a shell and go to download directory. To configure and install cmake type:
```
tar xvf cmake-version.tar
./configure
make
make install
```

## GoogleTest ##
Finally we have to download google test library sources. Downlaod them from the GoogleTest, clicking on _"gtest-1.5.0.tar.gz"_. Store the download file in your computer.

Once the sources file is on your PC, open an shell console. Navigate to your download directory and extract the archive by typing:
```
tar -xzvf gtest-version.tar.gz
```

For build the library type:
```
cd gtest-version
mkdir mybuild
cd mybuild
cmake -G"UNIX Makefiles" ..
make
```

Now, to install builded libray type:
```
make install
```


[Mac Configuration](InstallingForMac.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)