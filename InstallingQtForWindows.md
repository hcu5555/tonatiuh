# Introduction #
![http://tonatiuh.googlecode.com/svn/wiki/images/qt/qtLogo.png](http://tonatiuh.googlecode.com/svn/wiki/images/qt/qtLogo.png)

Qt is cross-platform application framework for Graphics User Interface (GUI) development. This application framework is implemented as a set of related libraries. The Qt libraries are used within Tonatiuh to implement the program's GUI, the plug-in architecture, the parallel processing functionality, and the scripting capabilities, among other things.

Here you will find instructions to install the Qt libraries in your computer and make those libraries available for the development of Tonatiuh.

# Details #

Download the installer of the Qt 4 for Windows. Some of the libraries that use Qt doesn't compile with last Qt libraries version. To do it, click on the following [link](http://qt.nokia.com/downloads). Once you reach the webpage, go to the link titled _"Qt version for Windows 32-bit"_ (see Figure 1). This will start the downloading of the Qt SDK for Windows installer. When prompted if to open or to store the file in your computer, select the appropriate option to store the file in your computer.

|<a href='https://picasaweb.google.com/lh/photo/uEbVQOZgTZMd1-1MV3nctNMTjNZETYmyPJy0liipFm0?feat=embedwebsite'><img src='https://lh5.googleusercontent.com/-3fBnGHec22s/UqAobqDKtAI/AAAAAAAAAU4/Mae8Q_tJkps/s400/QT4Download.png' height='280' width='400' /></a>|
|:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 1.** View of the "Qt Download" webpage.|

Once the Qt installer is in your PC, left-click twice upon it to execute it.

During the execution of the installer do the following:
  * Check the _"I accept the terms of the License Agreement"_ and click the _"Next_ button.
|<a href='https://picasaweb.google.com/lh/photo/JR3T3LCaNcpARqiennK_JtMTjNZETYmyPJy0liipFm0?feat=embedwebsite'><img src='https://lh3.googleusercontent.com/-zhjsFR3hfpM/UqApv4AHJNI/AAAAAAAAAVE/Kk-3ismYvNo/s400/QT4License.png' height='311' width='400' /></a>|
|:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|  **Figure2.** License Agreement dialog.|

  * Enter _"C:\sde\Qt"_ as the destination folder.
  * Enter _"C:\sde\MinGW"_ as the MinGW installation folder and click the _"Install"_ button.


By instructing the Qt SDK for Windows installer to create the directory _"C:\sde\Qt"_ and to use it as the installation location, we are assuming that you will follow our suggestion of installing all the tools and libraries related to the Tonatiuh development environment under the same root folder, which we are defining as "C:\sde\". This has the advantage that once the Tonatiuh development environment is succesfully create in a computer, it can be replicated into other computers just by copying into these computers the root folder of the Tonatiuh development environment with all its subfolders and content.

Once the Qt libraries and development tools (including Qt creator) are installed, the next step is to install the Simage library. To do it, follow the instructions in the following wiki page: [Simage](InstallingSimageForWindows.md)

[Windows Configuration](InstallingForWindows.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)