# Introduction #

To be able to develop Tonatiuh under Windows 64 Bit, you need to install he MSYS shell environment, the MinGW 64 C++ compiler, and a series of libraries. The installation of the MSYS shell environment and the MinGW 64 C++ compiler is the first step in this process.

Here you will find instructions to carry out this first and important step towards setting up of a programming environment that will allow you to contribute to the development of Tonatiuh and / or to create your own plug-ins for Tonatiuh.

# Details #

## Installing the Mingw ##

Download the latest version of the MinGW for 64 bits. To do it, click on the following [link](http://sourceforge.net/projects/mingwbuilds/files/host-windows/releases/4.8.1/32-bit/threads-posix/dwarf/x32-4.8.1-release-posix-dwarf-rev5.7z/download). This is the recommended package for Qt compilation. When prompted if to open or to store the file in your computer, select the appropriate option to store file on your computer.


Once the MinGW is in your PC, right-click upon it to extract its content. Move or copy the "MinGW" folder into the folder "C:\sde\".

## Installing the MSYS ##
Now, to download MSYS Environment go to the following [link](http://sourceforge.net/projects/mingwbuilds/files/external-binary-packages/msys+7za+wget+svn+git+mercurial+cvs-rev11.7z/download) to download the version recommended by Qt. After the download is finished, extract it to  "C:\sde\mingw64".

By instructing the MSYS and MinGW installer to create the directory _"C:\sde\mingw64"_ and to use it as the installation location, we are assuming that you will follow our suggestion of installing all the tools and libraries related to the Tonatiuh development environment under the same root folder, which we are defining as "C:\sde\". This has the advantage that once the Tonatiuh development environment is succesfully create in a computer, it can be replicated into other computers just by copying into these computers the root folder of the Tonatiuh development environment with all its subfolders and content.

Once MinGW is installed, the next step is to install the Qt libraries. To do it, follow the instruction in the following wike page: [Installing Qt](InstallingQtForWindows64.md).

[Windows 64 Bit Configuration](InstallingForWindows64.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)