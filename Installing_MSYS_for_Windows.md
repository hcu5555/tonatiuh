# Introduction #

MSYS is a collection of GNU utilities to build applications and programs which depend on UNIX. Before the installation of MSYS, [MinGW](InstallingMinGWForWindows.md) must be intalled in _C:\sde\MinGW_.

# Details #

Download the latest stable version of the MSYS installer (version MSYS-1.0.11). To do it, click on the following [link](http://sourceforge.net/projects/mingw/files/MSYS%20Base%20System) to go to the MSYS Base System section of the MinGW website.

Once you are there, expand the Current Release\_MSYS-1.0.11 section of the page, and click on the link to the executable file: 'MSYS-1.0.11.exe' as shown in Figure 1.

|![http://lh5.ggpht.com/_tmEVMS15i5Y/Snid5ss27LI/AAAAAAAAATA/X3tDvPWItbQ/s800/MSYS_installation01.jpg](http://lh5.ggpht.com/_tmEVMS15i5Y/Snid5ss27LI/AAAAAAAAATA/X3tDvPWItbQ/s800/MSYS_installation01.jpg)|
|:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 1. Link to download the MSYS installer as located in the MSYS Base System section of the MinGW website.**|

A window will popup asking you if you want to execute the file or store it in your computer. Store it in your PC and, after that, execute it.

During the execution of the installer:
  * In the License Agreement Dialog click the "Yes" button to accept the terms of the License Agreement.
  * In the Select Destination Directory Dialog type "C:\sde\msys\usr" as the installation folder.
  * In the first post-install window, to the question "Do you wish to continue with the post install?" type: "y". To the question "Do you have MinGW installed? type "y". To the question "Where is your MinGW installation? type "c:/sde/MinGW".
  * In the last installation program dialog click on the "Finish" button.
Once MSYS is installed the next step is to install the Qt libraries. To do it, follow the instructions in the following wiki page: [InstallingQtForWindows](InstallingQtForWindows.md)

[Windows Configuration](InstallingForWindows.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)