# Introduction #
SQLite is library that implements a self-contained, serverless, zero-configuration, transactional SQL database engine.

Here you will find instructions to install the !SQLite library in your computer and make this library available for the development of Tonatiuh.


# Details #

Before installing SQLite, please, verify that the MinGW and MSYS compilation and linking environment are already properly installed in your computer. If they are not, install them first by following the corresponding procedures to [Installing MinGW and MSYS](InstallingMinGWForWindows.md).

Download the latest release of the SQLite, currently SQLite 3071300. To do it, click on the following [link](http://www.sqlite.org/download.html) to go to the "SQLite"  download webpage. Once you reach the webpage, click on the link titled "sqlite-autoconf-_version_.tar.gz
" at the "Source Code" section. This will start the downloading of the source package. When prompted if to open or to store the file in your computer, select the appropriate option to store the file in your computer.

|<a href='https://picasaweb.google.com/lh/photo/EUE8J3N0mJ2oNgrSzrhA_-hPzBptKnN6WXkW8rDyw9U?feat=directlink'><img src='https://lh4.googleusercontent.com/-fmnewHcZOkY/UBEPur_I5TI/AAAAAAAAALM/NdkHdJlKKSc/s800/SQLiteDownloadWebpage.png' height='261' width='400' /></a>|
|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 1.** View of the "SQLite Download" webpage.|

Once the SQLite source code package is on your computer, place it into the user directory under your MSYS folder. This will typically be _"C:\sde\MinGW\msys\1.0\home\username"_.

Open an MSYS shell console. Navigate to your MSYS user directory and extract the archive by typing:
```
tar -zxvf sqlite-autoconf-version.tar.gz
```

This will create a directory called _sqlite-autoconf-version_ in your user directory. Using the MSYS shell navigate to the just created directory.

To build the library in release mode type:
```
./configure 
```
This will start the configuration process. Depending on your computer, this process may take some time to finish.


Now, you can install the SQLite library by typing:
```
make 
make install
```

The installation process may take some time. Once the SQLite library is installed the next step is to install the Eclipse Integrated Development Environment (IDE). To do it, follow the instructions in the following wiki page: [Installing and Configuring Eclipse](InstallingAndConfiguringEclipseForWindows.md)

[Windows Configuration](InstallingForWindows.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)