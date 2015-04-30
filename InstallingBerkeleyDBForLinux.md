## Introduction ##

Oracle Berkeley DB is the industry-leading open source, embeddable database engine that provides developers with fast, reliable, local persistence with zero administration. This library is used in Tonatiuh to implement photon maps plug-ins which can store an arbitrary number of photons.

Here you will find instructions to install the Berkeley DB library in your computer and make this library available for the development of Tonatiuh.

**Note:** Check if you can download the last Berkeley DB library file from your Software Management tool.

## Details ##

Use this [link](http://www.oracle.com/technology/software/products/berkeley-db/index.html) to go to the Berkeley DB webpage of the Orable website. Once you reach the webpage, select the link to download the latest stable source code version of the Berkeley DB in your computer. Currently, this version is 5.1.19 (see Figure 1).

|<table><tr><td><a href='http://picasaweb.google.com/manuel.jesus.blanco/TonatiuhWikiFigures?authkey=Gv1sRgCN2umpjNtK24Kg&feat=embedwebsite#5526847072163475010'><img src='http://lh3.ggpht.com/_tmEVMS15i5Y/TLNOITA2LkI/AAAAAAAAAoY/b-lQwR5Dl3M/s400/BerkeleyDB_download.png' /></a></td></tr><tr><td></td></tr></table>|
|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 1.** View of the _"Berkeley DB"_ webpage.|

Open a shell, navigate to download directory and extract downloaded files typing:

```
tar -xzvf db-version.tar.gz
```

Change to the build directory with:
```
cd db-version/build_unix
```

To configure the Berkeley DB type the following command:
```
../dist/configure --enable-cxx --prefix=/usr/local
```

To build and install the library use the commands:
```
make
make install
```

## Building an application ##
To build an application with Berkeley DB library add the library headers path to include
variable as:
```
INCLUDEPATH += 		$$(TDE_ROOT)/local/include 

```

Also, add the library to LIBS variable:
```
LIBS += -L$$(TDE_ROOT)/local/lib -ldb_cxx
```

Once the Berkeley DB library is installed the next step is to install the Eclipse Integrated Development Environment (IDE). To do it, follow the instructions in the following wiki page: [Installing and Configuring Eclipse](InstallingAndConfiguringEclipseForLinux.md)


[Linux Configuration](InstallingForLinux.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)