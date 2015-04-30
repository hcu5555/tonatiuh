# Introduction #

To be able to develop Tonatiuh under Windows XP, Windows Vista or Windows 7, you need to install the MSYS shell environment, the MinGW C++ compiler, and a series of libraries. The installation of the MSYS shell environment and the MinGW C++ compiler is the first step in this process.

Here you will find instructions to carry out this first and important step towards setting up of a programming environment that will allow you to contribute to the development of Tonatiuh and / or to create your own plug-ins for Tonatiuh.

# Details #

Download the latest version of the MinGW installer. To do it, click on the following [link](http://sourceforge.net/projects/mingw/) to go to the webpage of the MinGW project website at SourceForge. Once you reach the webpage, click on the large green button labeled "Download" (see Figure 1). This will start the downloading of the MinGW installer. When prompted if to open or to store the file in your computer, select the appropriate option to store file on your computer.


|<a href='https://picasaweb.google.com/lh/photo/7fQEZquqdmkb04TyqtIJB-hPzBptKnN6WXkW8rDyw9U?feat=directlink'><img src='https://lh6.googleusercontent.com/-SIFnx5V_H18/ThqyVa4CjAI/AAAAAAAAAJY/aGEpPaFSQ98/s400/MinGWForWindows.png' /></a>|
|:----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 1.** View of the "Files" webpage of the MinGW website in SourceForge.|

Once the MinGW installer is in your PC, left-click twice upon it to execute it.

During the execution of the installer do the following:
  * Click _"Install"_ to start with the installation.
|<a href='https://picasaweb.google.com/lh/photo/P46lc0dg0VXFkkmH0JQrJdMTjNZETYmyPJy0liipFm0?feat=embedwebsite'><img src='https://lh5.googleusercontent.com/-Tm_4TtGkiiA/Up7U5bj9rwI/AAAAAAAAAQE/Sh0uv7TPv8k/s400/MinGWInstall1.png' height='309' width='400' /></a>|
|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 2.** MinGW Installer opening dialog.|

  * Enter _"C:\sde\MinGW"_ as the destination location and click _"Conitnue"_.
|<a href='https://picasaweb.google.com/lh/photo/bB68hnRDyufMWUCdClGR0dMTjNZETYmyPJy0liipFm0?feat=embedwebsite'><img src='https://lh6.googleusercontent.com/-mCROtodDlVI/Up7WU3NkVGI/AAAAAAAAAQg/XcjIKzu79NA/s400/MinGWInstall2.png' height='309' width='400' /></a>|
|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 3.** Preferences dialog.|

  * Select the following components to install:
    * _"A Basic MinGW Installation"_
    * _"The GNU C++ Compiler"_,
    * _"A Basic MSYS Installation"_
|<a href='https://picasaweb.google.com/lh/photo/QlT0ac2be5bYlgEK_ZjHpdMTjNZETYmyPJy0liipFm0?feat=embedwebsite'><img src='https://lh5.googleusercontent.com/-F9UZ0Su8xWc/Up7WV7Q3mTI/AAAAAAAAAQs/14ndwsbCnqo/s400/MinGWInstall4.png' height='236' width='400' /></a>|
|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 4.** MinGW Installation Manager dialog.|

After the installation is completed, open a MSYS shell console at _"C:\sde\MinGW\msys\1.0\msys.bat"_ and type:
```
sh /postinstall/pi.sh
```
  * Type _"y"_ to continue with the installation.
  * Type _"y"_ to say that MinGW is installed.
  * Enter _"c:/sde/MinGW"_ as the MinGW installation location.

By instructing the MSYS and MinGW installer to create the directory _"C:\sde\MinGW"_ and to use it as the installation location, we are assuming that you will follow our suggestion of installing all the tools and libraries related to the Tonatiuh development environment under the same root folder, which we are defining as "C:\sde\". This has the advantage that once the Tonatiuh development environment is succesfully create in a computer, it can be replicated into other computers just by copying into these computers the root folder of the Tonatiuh development environment with all its subfolders and content.

Once MinGW is installed, the next step is to install the Qt libraries. To do it, follow the instruction in the following wike page: [InstallingQtForWindows](InstallingQtForWindows.md).

[Windows Configuration](InstallingForWindows.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)