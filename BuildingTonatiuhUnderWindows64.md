# Introduction #

Whether you want to collaborate in the development of Tonatiuh, you want to develop your own Tonatiuh plug-ins, or you just want to use the latest version of the program without between formal official program releases, you need to access the Tonatiuh Subversion repository and be able to build the Tonatiuh program from the source code.

Here you will find the instructions to configure Eclipse to both access the Tonatiuh Suversion repository and building the program and its official plug-ins from the source code.

# Details #

## Obtaining a local copy of Tonatiuh ##

To build Tonatiuh using the C++ Eclipse IDE, the first thing you need to do is to download the Tonatiuh source code from the Subversion repository at Googlecode. To do this, execute Eclipse, click on the "Window" option in the menu bar, then click on "Open Perspective" and select "SVN Repository Exploring" as the perspective to open.

Once the "SVN Repository Exploring" is open under Eclipse, right click on the middle of the left panel titled "SVN Repositories". A pop-up menu will be displayed showing only one option titled "New". Left-click on it, and select the option titled "Repository Location..." (see Figure 1).

|<a href='http://picasaweb.google.com/lh/photo/H1lCIvbGrnNQHWmCugkozQ?feat=embedwebsite'><img src='http://lh6.ggpht.com/_tmEVMS15i5Y/TL4UHatS9bI/AAAAAAAAAsE/FyG6OV0vHwU/s400/Eclipse_SVN_RepositoryExploring01.png' height='265' width='400' /></a>|
|:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 1.** Eclipse _"SVN Repository Exploring"_ perspective.|

This will display a pop-up dialog, with several tabs. Under the _"General"_ tab, in the dialog's URL field enter _"http://tonatiuh.googlecode.com/svn/trunk"_, then in the _"Label"_ section check either the option _"Use repository URL as label"_ or the option _"Use a custom label"_. If you select the second option, you need to provide the custom label you want to use to designate Tonatiuh's SVN repository at Googlecode.

If you are a member of the Tonatiuh software development team, enter your username and password, in the _"Authetication"_ section of the _"General"_ tab of the pop-up dialog.  If you are not a member of the team, leave this section blank to make an anonimous download of the Tonatiuh code.

Finally, check the option _"Validate Repository Location on finish"_, and click on the "Finish" button. After doing this, you will see the tree of the Tonatiuh Subversion code repository at Google code. To download the Tonatiuh code, including the code of the official Tonatiuh plug-ins, please, expand the _"trunk"_ subtree and right-click on the _"TonatiuhProject"_ folder. By doing this, you will trigger the display of a pop-up menu. On that menu, select the _"Check Out"_ option (see Figure 2). This will start the process of downloading the Tonatiuh code into your computer.

|<a href='http://picasaweb.google.com/lh/photo/viXYu7KmO8IYr18qgPF8Jw?feat=embedwebsite'><img src='http://lh5.ggpht.com/_tmEVMS15i5Y/TL9UN6uWhII/AAAAAAAAAsY/qFeF_mmGMsY/s400/Eclipse_SVN_CodeCheckout.png' height='264' width='400' /></a>|
|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 2.** Eclipse _"SVN Repository Exploring"_ perspective pop-up menu.|

## Configuring Eclipse to build Tonatiuh ##

### Set up Tonatiuh as a C++ project ###
Once the process of checking out the Tonatiuh code finishes, please, open the C/C++ Eclipse Perspective. To do it, left-click on the _"Window_ option of the Eclipse main menu bar, select _"Open Perspective"_, then select _"Other..."_ and then select "C/C++ (default)"_and click on the "OK" button._

Within the C/C++ perspective, locate the _"Project Explorer"_ pane and right-click on the _"TonatiuhProject"_ folder. In the pop-up menu that will be displayed, click on _"New"_ and then on _"Convert to a C/C++ Project"_. This will display the _"Convert to a C/C++ project"_ dialog (see Figure 3).


In the _"Candidates for conversion"_ section of the dialog, verify that the folder _"TonatiuhProject"_ is checked. In the _"Convert to C or C++"_ section verify that the _"C++ Project"_ option is selected. In the _"Project options"_ section verify that the _"Specify project type"_ option is cheked, that the selected _"Project type:"_ is _"Makefile project"_, and that the selected _"Toolchains"_ is _"Other Tool Chains"_. After all of the above is done, click on the _"Finish"_ button.

### Define environment variables ###

Once Tonatiuh is set up as a C++ project within Eclipse, you need to defining several environment variables which are needed by qmake to properly process the many Tonatiuh qt project files (_`*`.pro_) which are necessary to build Tonatiuh.

On the C/C++ Eclipse perspective, right-click on the _"TonatiuhProject"_ folder to display the pop-up menu. Go to the bottom of the menu and click on _"Properties"_. This will display the _"Properties for TonatiuhProject"_ dialog. There, on the tree-view at the left, click on the _"C/C++ Build"_ Item to expand it, and then click on the _"Environment"_ sub-item. This will display the _"Environment"_ form-view to the right of the tree-view of the _"Properties for TonatiuhProject"_ dialog.

To create the new environment variable TDE\_ROOT, first, click on the _"Add..."_ button of the _"Environment"_ form-view to display the _"New variable"_ pop-up dialog, then on this dialog check the _"Add to all configurations"_ option, enter the following information:

```
Name: TDE_ROOT
Value: C:\sde\mingw64\msys
```

And click the "OK" button.

To create the new environment variable TONATIUH\_ROOT follow a similar procedure. However, in this case, in the _"New variable"_ pop-up dialog enter the following information:

```
Name: TONATIUH_ROOT
Value: C:\sde\workspace\TonatiuhProject
```

It's also necessary to define the environment variable PATH with this information:

```
Name: PATH
Value: C:\sde\mingw64\bin;C:\sde\qt\qtbase\bin
```
And click the "OK" button.

At the end of the process the "Properties for TonatiuhProject" pop-up dialog, should look like Figure 4.

|<a href='http://picasaweb.google.com/lh/photo/0SVavIM49WiZV73jIm_Giw?feat=embedwebsite'><img src='http://lh6.ggpht.com/_tmEVMS15i5Y/TMC9NZ1grUI/AAAAAAAAAs0/piELeKya_78/s400/Eclipse_PropertiesDialog.png' height='220' width='400' /></a>|
|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 4.** _Eclipse C/C++ Environment variables pop-up dialog._|

After defining the two environment variables of Tonatiuh needed by qmake, go the tree-like window of the _"Properties for TonatiuhProject"_ dialog and under the _"C/C++ Build"_ item click on the _"Settings" sub-item to display the_"Settings"_form-like view.
There, select the_"Binary parser"_tab, and within the_"Binary parser:"_section make sure that only the option_"PE Windows Parser"_is checked. Then, click on the_"OK"_button to close the_"Properties for TonatiuhProject"_dialog._

### Create Make Targets ###

#### qmake ####
On the Make Target tab, right click on the folder titled "TonatiuhProject"_. Then, on the pop-up menu select_"New..."_. Finally, on the pop-up dialog titled_"Create Make Target"_fill the differend fields as follows:_

```
Target name: qmake
Make target: TonatiuhProject.pro
Build command: qmake
```

To fill the _"Make target"_ field you need uncheck the _"Same as the target name"_ option. Likewise, to fill the _"Build command"_ field uncheck the _"Use builder settings"_ option. Before clicking on the _"OK"_ button to close the dialog, please, verify that the _"Run all project builders"_ option is checked.

#### all ####
Repeat the previous procedure until the dialog _"Create Make Target"_ is displayed. Then, fill the differend fields as follows:

```
Target name: all
Make target: all
Build command: C:\sde\mingw64\bin\mingw32-make.exe
```

To fill the _"Make target"_ field just verify that the _"Same as the target name"_ option is checked. To fill the _"Build command"_ field uncheck the _"Use builder settings"_ option. Before clicking on the _"OK"_ button to close the dialog, please, verify that the _"Stop on first build error"_ and _"Run all project builders"_ options are both checked.

#### distclean ####
Repeat the previous procedure until the dialog _"Create Make Target"_ is displayed. Then, fill the differend fields as follows:

```
Target name: distclean
Make target: distclean
Build command: C:\sde\mingw64\bin\mingw32-make.exe
```

To fill the _"Make target"_ field just verify that the _"Same as the target name"_ option is checked. To fill the _"Build command"_ field uncheck the _"Use builder settings"_ option. Before clicking on the _"OK"_ button to close the dialog, please, verify that the _"Stop on first build error"_ and _"Run all project builders"_ options are both checked.
and select Add Make Target.

## Building Tonatiuh and its plug-ins ##

To build Tonatiuh and all the official plug-ins you need first to double-click on the _"qmake"_ target you just created in the _"Make Target"_ tab of the _"C/C++"_ Eclipse perspective. This will trigger the creation by qmake of all the Makefiles needed to build Tonatiuh. If you look at the _"Console"_ tab of the _"C/C++"_ Eclipse perspective you will see the following messages:

```
**** Build of configuration Default for project TonatiuhProject ****

qmake TonatiuhProject.pro
```

Once qmake finishes creating the project Makefiles, double-click on the _"all"_ target in the _"Make Target"_ tab of the _"C/C++"_ Eclipse perspective. This will trigger the building of Tonatiuh and its plug-ins. The process will take a while to execute. If you look at the _"Console"_ of the _"C/C++"_ Eclipse perspective you will see the display of compiler and linking instructions related to compilation and linking of the set of source code files of Tonatiuh and its plug-ins.


[Windows 64 bit Configuration](InstallingForWindows64.md) | [Developer's Guide](http://code.google.com/p/tonatiuh/wiki/DevelopersGuide) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)