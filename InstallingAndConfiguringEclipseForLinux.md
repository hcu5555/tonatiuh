# Introduction #
![http://tonatiuh.googlecode.com/svn/wiki/images/eclipse/eclipseIcon.png](http://tonatiuh.googlecode.com/svn/wiki/images/eclipse/eclipseIcon.png)

Eclipse is an open source community whose projects are focus on building an extensible development platform, runtimes and application frameworks for building, deploying and managing software across the entire software lifecycle.

Here you will find instructions to install the Eclipse Integrated Development Environment for C/C++ Developers and to configure it for the development of Tonatiuh.

# Details #

## Installing the Eclipse IDE for C/C++ Developers ##
Download the latest version of the_"Eclipse IDE for C/C++ Developers"_ from the Eclipse website. To do it, click on the following [link](http://www.eclipse.org/downloads/) to go to the "Downloads" webpage of the Eclipse website. Once you reach the webpage, click on the appropriate version (Linux 32 Bit or Linux 64 Bit) of the link titled _"Eclipse IDE for C/C++ Developers". Then follow the instructions to select a mirror site from where to download the compressed package file. When prompted, select the appropriate option to store the file in your computer. Currently, the latest version of the compressed package file is titled_"eclipse-cpp-helios-SR1-linux-gtk.zip"_._

Once the IDE for C/C++ Developers compressed package file is in your computer, right-click upon it to extract its content. This will create a top level folder titled _eclipse_.Move or copy the _"eclipse"_ folder into the folder _"/home/username/"_

## Configuring the Eclipse IDE for C/C++ Developers for developing Qt applications ##

On the Eclipse main menu select _"Window"_ and within it _"Preferences"_. This will triger a pop-up dialog titled _Preferences"_, which can be used to adjust different Eclipse options. In the left tree-like view of the preferences dialog select "General\Editors\File Associations" (see Figure 1). In the dialog's _"File Associations"_ right view, within the _"File types"_ window, add the new types:
  * .ui
  * .ts

And within the _"Associated editors"_ window, associate this file types with the following programs, respectively:
  * /usr/local/Trolltech/Qt-4.7.0/bin/designer
  * /usr/local/Trolltech/Qt-4.7.0//bin/linguist

|<a href='http://picasaweb.google.com/lh/photo/qsb4_Ia8dQQ4MpdeF904fA?feat=embedwebsite'><img src='http://lh4.ggpht.com/_tmEVMS15i5Y/TLONfbgLfYI/AAAAAAAAAq4/1Yxl6FBiHU8/s400/Eclipse_file_associations.png' height='299' width='400' /></a>|
|:------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 1.** View of the Eclipse IDE and the _"Preferences\File Associations"_ dialog.|


To install svn to download and update Tonatiuh follow the corresponding installation procedures [Installing\_Subversive](Installing_Subversive.md).

[Linux Configuration](InstallingForLinux.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)