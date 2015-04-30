## Installing Subversion ##

Open Eclipse. In the main menu select _"Help"_ and then _"Install New Software"_. This will display a pop-up menu titled _"Install"_. In the field _"Work with"_ select _"--All Available Sites--"_. This selection will triger a search that will take some time to finish. Please, wait until the search ends.

At the end of the search, the dialog's tree view will be populated with many lists and items. Expand the _"Collaboration"_ list, select only the item _"Subversive SVN Team Provider"_, and click on the "Next" button (see Figure 1).

|<a href='http://picasaweb.google.com/lh/photo/3BLcQH5sqlrFjj2bty17Zg?feat=embedwebsite'><img src='http://lh3.ggpht.com/_tmEVMS15i5Y/TLOfrNXrcCI/AAAAAAAAArQ/WIPx5Cs68c8/s400/Eclipse_available_software.png' height='299' width='400' /></a>|
|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 1.** View of the Eclipse IDE and the _"Install\Available Software"_ dialog.|

In the next Install dialog's screen titled _"Install Details"_ click again on the _"Next"_ button. Then, in the screen titled _"Review Licenses"_ check the option _"I accept the terms of the license agreement"_ and click on the _"Finish"_ button.

Once the software installation process ends, you will be prompted to restart Eclipse. Click on the _"Restart Now"_ button, to do it. At the restart of Eclipse you will be presented a new _"Welcome"_ view(see Figure 2).

|<a href='http://picasaweb.google.com/lh/photo/J5PDC2iXqVXdFSYrliYJvQ?feat=embedwebsite'><img src='http://lh3.ggpht.com/_tmEVMS15i5Y/TLOmYN8b5bI/AAAAAAAAArc/lz2At3ywp38/s400/Eclipse_welcome_overview.png' height='266' width='400' /></a>|
|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 2.** Eclipse's _"Welcome"_ view after installing the SVN plug-in.|

Now, go to the Windows menu and select _"Open Perspective"_, and then _"SVN Repository Exploring"_. The first time you select this perspective, a pop-up dialog will be displayed entitled _"Install Connectors"_. Within the dialog you will be informed that in order for the SVN plug-in and the Eclipse perspective _"SVN Repository Exploring"_ to work, you need to install one of the SVN connector listed on the dialog (see Figure 3).

|<a href='http://picasaweb.google.com/lh/photo/fw2cK0HZ88Y1EQSL_D9zZA?feat=embedwebsite'><img src='http://lh3.ggpht.com/_tmEVMS15i5Y/TLOuJyX0CgI/AAAAAAAAArs/LhHIVthMIGo/s400/Marble_svn_connectors.png' height='288' width='400' /></a>|
|:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 3.** Eclipse's Subversive SVN Connectors selection dialog.|

Select the SVN Connector titled _"SVN Kit version"_ and follow the instructions of the subsequent dialogs, clicking on their _"Next"_ button, and accepting the licence agreements you are presented, until the installation process starts.

During the installation of the connector and related software you will get a _"Security Warning"_ from Eclipse, stating that _"you are installing software that contains unsigned content"_ and asking you if you want to continue with the installation. Say yes, by clicking on the security warning dialog's _"OK"_ button.

At the end of the software installation process you will be asked to restart Eclipse, please, do so by clicking on the _"Restart Now"_ button.

Once this is done, any time you will upload a file to a Subversion repository, the corresponding mime-type will automatically be set for that file.

Now, if you are a member of Tonatiuh's software development team, please, go to the wikipage [Upload\_to\_Repository](Upload_to_Repository.md) for instructions on how to check out Tonatiuh's source files, how to update your local copy of the Tonatiuh, and how to commit code changes to Tonatiuh's SVN repository at Googlecode.

If you are not a member of Tonatiuh's software developement team, but you are, however, interested in downloading a copy of the most current version of the Tonatiuh's source code, please, go to the wikipage [Anonymous\_Download](Anonymous_Download.md) for instructions on how to carry out an anounymous download of the Tonatiuh code.


[Windows Configuration](http://code.google.com/p/tonatiuh/wiki/InstallingForWindows) | [Windows 64 bit Configuration](http://code.google.com/p/tonatiuh/wiki/InstallingForWindows64) |
[Linux Configuration](InstallingForLinux.md) |
[Mac Configuration](InstallingForMac.md) |
[Wiki Home](http://code.google.com/p/tonatiuh/w/list)