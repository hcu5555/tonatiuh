# Introduction #
The Debug perspective on Eclipse lets you manage the debugging a program. You can control the execution of your program by setting breakpoints, suspending launched programs, stepping through your code, and examining the contents of variables.


## Creating a Debug Configuration ##

To create a run configuration:
  * Go to Run menu on Eclipse Window.
  * Select "Debug Configurations...".
  * Click New
  * Define a name to launch.
  * On "Main" tab select "Toantiuh" as a project and debug version of Tonatiuh binaries as C/C++ Application.
  * Go to "Environment" tab and add "PATH" variable with "C:\sde\msys\usr\qt\bin;C:\msys\usr\local\bin" value.
  * In "Debugger" tab select "MinGW gdb Debugger". Set the followings options to debugger:
  * GDB debugger: gdb
  * GDB command file: .gdbinit
  * GDB command set: Standard (Windows)
  * Protocol: mi

## Debug ##
  * In the C/C++ Projects view, select the project.
  * Click Run > Debug.

[Windows Configuration](InstallingForWindows.md) |
[Wiki Home](http://code.google.com/p/tonatiuh/w/list)