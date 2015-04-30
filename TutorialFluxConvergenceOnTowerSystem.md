# Introduction #

The main aim of this tutorial is explain how to analyze the tonatiuh output data to stimate the flux distribution on the target. Basically, we want to know when Tonatiuh converges. The convergence is how many rays we have to display with tonatiuh to get a stable FluxMax and relative FluxMax error. This tutorial has been updated to the Tonatiuh lastest version. The release 1.2.6 is the latest update of Tonatiuh. If you have an older version, please, upload it either by clicking on on Help-->Check for updates in Tonatiuh or by visiting <a href='http://code.google.com/p/tonatiuh/downloads/list'> tonatiuh downloads site </a>.

# Characteristics of the system #

The system we want to simulate consists of:

  * A tower.
  * One heliostat.
  * A flat plane as a receiver.

|<a href='https://picasaweb.google.com/lh/photo/yJNpX9SSCXLkuMfaAfsCTQ?full-exif=true?'><img src='https://lh4.googleusercontent.com/-mYxx1L76YPk/To2JSGxekaI/AAAAAAAAA9Y/9hq7wwYNVco/s510/EsquemaTutorialFlux.png' width='300' /></a>|
|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 1.** Tower system layout.|

# General aspects of the system #

The system we are going to simulate is made up of a flat square of 15 x 15 meters located on the top of a cylindric tower of 150 meters heigth.
400 meters away of the tower, we are going to create a flat square with a surface of 60 m<sup>2</sup> . This flate rectangle, called Heliostat, is going to with an inclination of 45º compared to the North.
We are asumming that the solar concentrating system is placed in Sevilla, Spain at 11.00 A.M.

# Modeling the system #

## Modeling the tower and the target ##
  * Once tonatiuh is opened, we have to select the rootNode and, then, add a TSeparator as a childen. The TSeparatorKit node is the blue circular button allocated on the icon bar.
  * When the node is created,double click and rename it to "Tower". With this new node selected, create a new TSeparatorKit as a node child and rename it to "Base". Set the Transform parameters to this:
```
translation        0 120 8
rotation           1 0 0 1.5707964
scaleFactor        1 0.5 1 
scaleOrientation   0 0 1 0 
center             0 0 0 
```

  * If we select the "Base" node, we can add one shape on it. Only if we create first a TShapeKit node (the red circle icon next to the blue one), we will be able to insert a shape.
  * With the TShape node, previously created, selected, we can add a shape. In this case, we are using a cylinder shape called Cylinder. We can find it in the menu Insert --> Shape.
  * Once the Cylinder is created, select it and change their values to those ones:
```
radious        15
length         120
phiMax         6.2831855
activeSide     OUTSIDE
```
  * Now, it is time to create the target. Select the node "Tower" and create a new TSeparator. Rename it to "Target". Change it transform values to:
```
translation        0 100 0
rotation           0 1 0 1.5707964
scaleFactor        1 1 1 
scaleOrientation   0 0 1 0 
center             0 0 0 
```

  * Select the new node and add a new TSeparatorKit as a child. Rename it to "target" and change the parameters to:
```
translation        0 0 0
rotation           0 0 -1 1.5707964
scaleFactor        1 1 1 
scaleOrientation   0 0 1 0 
center             0 0 0 
```
  * Add a new TShapeKit as a child of the last node created, called "TargetSurface". Now add a new shape as a child. In this example, the shape must be a "Flat\_Rectangle". If we have created it properly, it should be visible on the 3D scene viewer.
  * Set those parameters on the "Flat\_Rectangle" options:
```
width        20
heigth       20
activeSide   FRONT
```
  * Select the last TShapeKit created and add a "Specular\_Standar\_Material" as a child.

|<a href='https://picasaweb.google.com/lh/photo/uiDtAvD00LfqhEY273bOOw?full-exif=true'><img src='https://lh4.googleusercontent.com/-BLQv-KY_p6U/To2CkTqlXDI/AAAAAAAAA9E/Y8K0OQvIQ8s/s640/TowerImage2.png' height='240' width='400' /></a>|
|:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 2.** Tonatiuh's GUI after modeling the target and the tower.|

## Modeling the heliostat ##

By this moment, the tower of the system has been created. Now we need to create the heliostat. According to the initial conditions, the heliostat must be situated 400 meters away the tower with an inclination of 45º to the North. To create it, follow those steps:
  * Select the RootNode and create TSeparator node by clicking on the "Group Node" icon. Rename it to "Heliostat". We want the heliostat with an inclination of 45º and 400 metres away the tower. To fix the heliostat on the correct point we need to know the values for x and z. For x we have to calculate cos(45º) x 400. For z we have to calculate sen(45º) x 400. Now, we have to set them on the "!Heliostat" transform parameters in that way:
```
translation    282.85 0 -282.85
```

  * Select "Heliostat" and add a new TSeparatorKit. Rename it to "HeliostatTrackerNode".

  * Select the last node created and add a "!Heliostat\_tracker" traker type. In the transform options,change the aimingPoint to:
```
aimingPoint   0 100 0
```
> The main property of this element is to make the heliostat change the position  while the sun is moving. Doing that, we can project more rays from the sun to the target.
  * Select the "HeliostatSurface" node and add a TShapeKit node.
  * Now, add a "Flat\_Rectangle" shape and a "Specular\_Standar\_Material" as a child on the previous TShapeKit.
  * Select the "Standar\_Specular\_Material" and change the m\_reflectivity to 1.
  * We want a square flat which surface of with a surface of 60 m<sup>2</sup>. So we have to set it values to:
```
width         7.7399998
heigth        7.7399998
activeSide    FRONT
```

## Defining the sun ##

Now we have to define the sun. Without it, we will not be able to simulate the system. Only following two steps the sun will be created correctly:
  * First, click on "Sun Light" --> "Define SunLight". In this case, choose a Pillbox\_SunShape and click "OK".
  * Finally,we want to set the sun is Sevilla at 11 A.M. Click on "SunLigth" -->"Sun position Calculator". As we are assumming the simulation is done in summer, the local hour in Sevilla is two more hours than UTC system which is the standard used in Tonatiuh. So we have to set the time at 9.00 UTC. To see the coodinates of Sevilla, press the "Select" button inside the box called "Position Coordinates".Once Sevilla is found, right click and select "Set Home Location". Press "Ok" to change the coordinates. Click "Apply" into calculator dialog before closing this dialog.

If we have done all steps successfully, we are about to run the system.




## Running the system ##

The main purpose of Tonatiuh is to get information about how rays can reach the target. We can simulate the rays in two ways:
  * The easiest one consists of pressing the run button in the icon bar. You only obtain one photon map for each interaction. To export the photon map press Ray Trace, export photonMap. You can define the options to run Tonatiuh in that way by clicking on Ray trace --> Ray trace Options. Here, you can set the number of rays per interaction, you can choose between two types of random generators or set the number of divisions you want to divide the sun. Althougth you will get better results, the computation and the time will be higher. Otherwise, the improvement on the results will be better depending on the field we were using.


  * The other, is using the script editor.Please, select Automation -->script editor. This will display a new window. A basic script can be like this:
```
 {{{ 
 //load a file 
 tonatiuh_filename( "HeliostatSunSevilla.tnh" );  
 //number of rays to simulate 
 tonatiuh_numrays( 2000000  );  
 //Sun divisions.  
 tonatiuh_numdivisions(300,300); 
  
 //type of phton map 
 tonatiuh_photon_map("PhotonMapDefault");  
 //type of random 
 tonatiuh_random_generator("Mersenne Twister");  
 //patch of the target 
 var concentratorSurface = "//RootNode/Tower/Target/Target/Target";  
 //output folder/name of file to export. create the folder previously 
 var concentratorFileName = "folder/filename";  
  
 //number of interactions 
 for( var i = 1; i <= 250; ++i ){  
         tonatiuh_trace(); //simulate the system 
         var s = i.toString(); 
 //export the photon map data 
         tonatiuh_export(  concentratorFileName.concat( "_", s, ".dat" ),  concentratorSurface, false ); 
 } 
 }}} 
```

> In this case, we want to get 5000000 of rays in the target. The previous script creates 250 files of 2000000 of rays to reach the desided number of photons in the target. We have to do that because of the memory limitations to get that amount of data doing one interaction.

|<a href='https://picasaweb.google.com/lh/photo/QHVJLKrPP5ewfcbLBsu5zQ?full-exif=true'><img src='https://lh3.googleusercontent.com/-S_x8vA4PYPU/To2qlbmM92I/AAAAAAAAA9w/76sPARv1i4Y/s800/FluxTutorialModel.png' height='240' width='400' /></a>|
|:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 3.** Tonatiuh's GUI after modeling system.|

# Tonatiuh post-processing #

Tonatiuh doesn't provide a photon map results analizer so it's necessary to use an external aplication such as Mathematica and R. The output photon map is saved in a .dat extension in a seven-tuple for each photon.

## Data post-processing with Mathematica ##
We use mathematica to know when photon maps converge. When we compare the convergence two by two, we get the relative error. If this error reaches a value lower than 0.5% in at least 5 cases, we will admit the result.

> ### How to create a post-proccess script using Mathematica ###

> The following steps explain how we can make a script in Mathematica to read photons properly. In this case the taget was a flat square plane:
  * First, set the way Mathematica has to read the data and how to transform the coordinate to the target we are using currently. In this case we only need x and z to create a flat plane.
```
ReadTonatiuhResults[filename_] :=  BinaryReadList[ filename, "Real64", ByteOrdering -> +1];
transform01[{x_, y_, z_}] := { x , z }
```
  * Select the width and the heigth of the flat plane and calculate the area:
```
absorberLength = 20
absorberWidth = 20
absorberArea = absorberLength*absorberWidth
```
  * Define the number of cells in which the target is divided up. The more number you put, the more number of rays need simulating to reach the goal.
```
widthDivisions = 50;
lengthDivisions = 50;
```
  * We have to set the workspace of mathematica in the directory we have the data. First create the Notebook in this directory and set the directory with:
```
SetDirectory[NotebookDirectory[]]
```
  * Search the folders (DirectoryQ) in the current directory  where we have the .dat files.
```
directoryList = Select[FileNames["Folder_Name"], DirectoryQ]
```
  * Get all the .dat files allocates in the directory "directoryList{{i}}"; i is folder of the directoryList we are going to use) found in the previous step.
```
fileList = FileNames[directoryList[[1]] <> "*.dat", directoryList]
```
  * Once we have got all the files, we have to get their photons.
```
binsFilesList = Map[FluxMatrix, fileList];
```
This instruction applies the FluxMatrix function in all files of the directory.
FluxMatrix convert the .dat file to a .txt file. The .txt file has as many columns and files as the number of lengthDivisions and widthDivisions we have set and they have the number of rays in the target per cell.
```
FluxMatrix[fileName_] := 
 Module[{data, powerPerPhoton, photonsData2D, totalPhotons, totalPowerAtAbsorberTube, 
ElementWidth, ElementLength, photonCounts,
elementArea, fluxConversionFactor, incidentFluxMatrix, 
minimumFlux, maximumFlux, zmin, zmax, contourLevels, tonatiuhContour},

  data = ReadTonatiuhResults[fileName];
  (*read file data*)
  powerPerPhoton = data[[1]] ;
  data = Drop[data, 1];
  (*read the seven-tuplas photon info*)(*[[5]]-->
  0 read back rays;[[5]]-->read front rays;none-->read all rays*)
  data = Select[
     Partition[data, 7], #[[5]] == 1 &] /. {id_, x_, y_, z_, side_, 
      next_, prev_} -> {x, y, z};
  (*get the area*)
  data = Map[transform01, data];
  (*number of photons*)
  totalPhotons = Length[data];

  (*average power per photon*)
  totalPowerAtAbsorberTube = (totalPhotons*powerPerPhoton)/1000 (*kW*);
  (*cell width*)
  ElementWidth = absorberWidth/widthDivisions (*meters*);
  (*cell length*)
  ElementLength = absorberLength/lengthDivisions (*meters*);
  (*put the photon in the corresponding cell*)
  photonCounts = 
   BinCounts[
    data, {-absorberWidth/2, absorberWidth/2, 
     ElementWidth}, {-absorberLength/2, absorberLength/2, 
     ElementLength}];

  (*create and export*bins.txt files with the rays*)
  Export[StringJoin[DirectoryName[fileName], FileBaseName[fileName], 
    "bins.txt"], photonCounts, "Table"]]
```

  * Now, we have to mix the element in the variable binsFileList to create a table with the simulation files. The first element of this new table only contains the first element of the table binsFileList;the second element contains the first and the second element of binsFilelist;the last element of this new table will contain all the files of the table binsFileList.
```
simulationsFiles = Table[{ binsFilesList[[1 ;; i]], i}, {i, 1, Lengt[binsFilesList]}] ;
```
> > Each element of simulationFiles is made with two elements. The first one is a table of files and the second one is the number of elements of the first element.

  * Using the funtion PositionFluxMatrix, we will create the simulation files with the elements of the table simulationFiles.
```
simulationsBinsFiles = Map[PositionFluxMatrix[#[[1]], #[[2]]] &, simulationsFiles] ;
```
In the function PositionFluxMatrix, which has two parametes(the first one is the list, and the second is the number of elements in the list),create a new file by adding the elements of the file list all together. So, finally, the first simulation file will be compounded with the first "bins.txt" files; the second with the first and the second file;the last simulation file will contain the addition of all the bins files.
```
PositionFluxMatrix[binsFileList_, number_] := Module[{bins},
  (Read all files of the list and we add all together in another to know the total of rays at this momment *)

 
  bins = Table[
    Partition[ReadList[binsFileList[[i]], Real], lengthDivisions], {i,
      Length[binsFileList]}];

  (*Export data in *bins.txt files*)
  Export["Simulation" <> ToString[number] <> "_bins.txt", Total[bins],
    "Table"]
  ]
```

To make it easier, in case you have lots of photon map files, you can do a parallel simulation. Instead of the last step, we have to use the following ones:
```
LaunchKernels[2]
DistributeDefinitions["Global`"]
simulationsBinsFiles = ParallelMap[PositionFluxMatrix[#[[1]], #[[2]]] &, simulationsFiles] ;
```
**Note:This only will work if the computer has more than one core. If it not your case, you will not be able to use this step.
  * For each simulation, calculate the power per photon. The power per photon is the same in all the files of this simulation because there are the same number of rays traced on each cells that the sun is divided. So we can calculate the power per photon as we show bellow:
```
fileList = FileNames[directoryList[[1]] <> "*_*.dat", directoryList];
powerPerPhoton = ReadTonatiuhResults[fileList[[1]]][[1]]
wPhotons = Table[powerPerphoton/i, {i, 1, Length[simulationsBinsFiles]}] // N ;
```
  * With those lines you can get a result and some graphics about how the flux distribution is going on:
```
results = Table[fluxAnalysis[{simulationsBinsFiles[[i]],wPhotons[[i]]}],{i, 1, Length[simulationsBinsFiles]}];
```**

The funtion fluxAnalysis returns, for each files, the photons, the power, the maximunmFlux and the minimum. It may be like this:
```
fluxAnalysis[{fileName_, powerPerPhoton_}] := 
 Module[{totalPhotons, totalPower, ElementWidth, 
   ElementLength, photonCounts, elementArea, 
   fluxConversionFactor, 
incidentFluxMatrix, minimumFlux, maximumFlux,
    zmin, zmax, contourLevels, tonatiuhContour, tonatiuh3D},


  totalPower = (totalPhotons * powerPerPhoton)/1000 (* kW *);
  ElementWidth = absorberWidth  /widthDivisions (* meters *);
  ElementLength = absorberLength/lengthDivisions (* meters *);
  photonCounts = Partition[ReadList[fileName, Real], lengthDivisions];
  totalPhotons = Total[Total[photonCounts]];
  elementArea = ElementWidth*ElementLength (* meters square *);
  fluxConversionFactor = (powerPerPhoton/1000)/elementArea (* kW/(m^2- photon) *);
  incidentFluxMatrix = photonCounts * fluxConversionFactor (* kW/m^2 *);
  minimumFlux = Min[incidentFluxMatrix];
  maximumFlux = Max[incidentFluxMatrix];
  contourLevels = Table[Exp[i], {i, 0, Log[maximumFlux], Log[maximumFlux]/20.0}];
  {zmin = 0, zmax = maximumFlux};

  (*create a graphic with the flux distribution on the target*)
tonatiuh3D = ListPlot3D[incidentFluxMatrix, PlotRange -> All, 
    DataRange -> { {-absorberLength/2, 
       absorberLength/2}, {-absorberWidth/2 , absorberWidth /2}}, 
    ColorFunctionScaling -> False, 
    ColorFunction -> 
     Function[{x, y, z}, 
      ColorData[
        "VisibleSpectrum"][(z - zmin)*(750 - 380)/(zmax - zmin) + 
        380]], ViewPoint -> {1.3, -2.4, 2}, PlotLabel -> "TONATIUH", 
    ImageSize -> {400, 400}];

  Export[StringJoin[FileBaseName[fileName], "3D.jpg"], tonatiuh3D];

  {fileName, totalPhotons, totalPower, minimumFlux, maximumFlux}]
```

  * If you want to represent graphically the results of the flux in the target,only this line is required:

```
fluxAnalysis[{simulationsBinsFiles[[-1]], powerPerPhoton/100}]
```
|<a href='https://picasaweb.google.com/lh/photo/wCUuCooUVM0oE2-7q2h6VA?full-exif=true?'><img src='https://lh4.googleusercontent.com/-HacP8YPkuSI/Tsp5yNUhr7I/AAAAAAAABAk/3anJI0Br_mQ/s500/100Simulation_bins3D.jpg' height='240' width='450' /></a>|
|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 4.** Example of a flux distribution on the target.|

  * To see if the results are good or not,we have to get the relative error:
```
 errorFluxMax = Table[100*(results[[i, 5]] - results[[i - 1, 5]])/results[[i 1, 5]], {i, 2, Length[results]}]
```
**The simulation will be a success if the relative error result is lower than 0.5 in, at least, 5 consecutive cases.**

  * We can plot and get a graphical file of the results of the relative error by typing:
```
rel = ListPlot[errorFluxMax, Joined -> True, 
  LabelStyle -> Directive["Helvetica", 14], 
  AxesLabel -> {"Rays", 
    "Relative difference between maximum flux estimates (% of \
previous estimate)"}, PlotRange -> {All, {-5, 5}}  , 
  ImageSize -> {1000, 600}]; 
Export["TargetMFlux_error.png", rel]
```

|<a href='https://picasaweb.google.com/lh/photo/NRTamUJ3Bli2n3ZNFrQVrw?full-exif=true?'><img src='https://lh4.googleusercontent.com/-kvECkvg7Xrg/Tsp64jlXCdI/AAAAAAAABA0/NTrN20idqZo/s912/TargetMFlux_error.png' height='140' width='600' /></a>|
|:----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 5.** Relative error graphical output.The red vertical line 

&lt;BR&gt;

 determines the last element which has a relative error >|0.5%| |

  * Another interesting result might be how the maximun flux is going. To know that, type:
```
fluxMax = 
  Table[{results[[i, 2]], results[[i, 5]]}, {i, 1, Length[results] }];

flux = ListPlot[fluxMax, Joined -> True, 
  LabelStyle -> Directive["Helvetica", 14], 
  AxesLabel -> {"Rays", 
    "Maximum flux(kW/\!\(\*SuperscriptBox[\(m\), \(2\)]\))"}, 
  PlotRange -> {All, {0, 2}} , ImageSize -> {1000, 600}]
Export["TargetMaximumFlux.png", flux] 
```

|<a href='https://picasaweb.google.com/lh/photo/uGqpzkO7CY2ihd4kWs0k4Q?full-exif=true?'><img src='https://lh6.googleusercontent.com/-yJF0v4fzogg/Tsp64ge5API/AAAAAAAABAw/Y0rU0Ga_Esc/s912/TargetMaximumFlux.png' height='140' width='600' /></a>|
|:----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 6.** Graphical representationof the Maximum Flux.|


This is a basic tonatiuh data proccessing. You can look into Mathematica to get other results. If there are any problem or something is wrong either in this tutorial or in Tonatiuh, please, type your discussion at the <a href='http://code.google.com/p/tonatiuh/issues/list'> issues tab </a> or better adding it to <a href='http://groups.google.com/group/tonatiuh-raytracer'>Tonatiuh users group forum. </a>

[Tutorials](Tutorials.md) | | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)