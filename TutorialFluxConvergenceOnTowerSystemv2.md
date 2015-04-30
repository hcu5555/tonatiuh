# Introduction #

  * The main aim of this tutorial is explain how to analyze the tonatiuh output data to stimate the flux distribution on the target. Basically, we want to know when Tonatiuh converges. The convergence is how many rays we have to display with tonatiuh to get a stable FluxMax and relative FluxMax error. This tutorial has been updated to the Tonatiuh lastest version. The release 2.0.0 is the latest update of Tonatiuh. If you have an older version, please, upload it either by clicking on on Help-->Check for updates in Tonatiuh or by visiting <a href='http://code.google.com/p/tonatiuh/downloads/list'> tonatiuh downloads site </a>.

# Characteristics of the system #

The system we want to simulate consists of:

  * A tower.
  * One heliostat.
  * A flat plane as a receiver.

|<a href='https://picasaweb.google.com/lh/photo/yJNpX9SSCXLkuMfaAfsCTQ?full-exif=true?'><img src='https://lh4.googleusercontent.com/-mYxx1L76YPk/To2JSGxekaI/AAAAAAAAA9Y/9hq7wwYNVco/s510/EsquemaTutorialFlux.png' width='300' /></a>|
|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 1.** Tower system layout.|

# General aspects of the system #

The system we are going to simulate is made up of a flat square of 20 x 20 meters located on the top of a cylindric tower of 150 meters heigth.
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
rotation           -1 0 0 1.5707964
scaleFactor        1 1 1 
scaleOrientation   0 0 1 0 
center             0 0 0 
```

  * Select the new node and add a new TSeparatorKit as a child. Rename it to "TargetRotationNode" and change the parameters to:
```
translation        0 0 0
rotation           0 1 0  3.1415927
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
  * Select "TargetSurface" node and add a "Specular\_Standar\_Material" as a child.

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

  * Select the last node created and add a "Heliostat\_tracker" tracker. In the transform options,change the aimingPoint to:
```
aimingPoint   0 100 0
```
> The main property of this element is to make the heliostat change the position  while the sun is moving. Doing that, we can project more rays from the sun to the target.
  * Select the "HeliostatTracker" node, add a TShapeKit node and call it "HeliostatSurface".
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
  * First, click on "Sun Light" --> "Define SunLight".
    * In this case, choose a Pillbox\_SunShape.
    * Go to "Sun Area" tab, click at "Tower" node in the left side box and select it as first stage not valid node.
    * Click "OK".
  * Finally,we want to set the sun is Sevilla at 11 A.M. Click on "SunLigth" -->"Sun position Calculator". As we are assumming the simulation is done in summer, the local hour in Sevilla is two more hours than UTC system which is the standard used in Tonatiuh. So we have to set the time at 9.00 UTC. To see the coodinates of Sevilla, press the "Select" button inside the box called "Position Coordinates". Once Sevilla is found, right click and select "Set Home Location". Press "Ok" to change the coordinates. Click "Apply" into calculator dialog before closing this dialog.
If we have done all steps successfully, we are about to run the system.


## Running the system ##

The main purpose of Tonatiuh is to get information about how rays can reach the target. We can simulate the rays in two ways:
  * The easiest one consists of pressing the run button in the icon bar. You only obtain one photon map for each interaction. To export the photon map press Ray Trace, export photonMap. You can define the options to run Tonatiuh in that way by clicking on Ray trace --> Ray trace Options. Here, you can set the number of rays per interaction, you can choose between two types of random generators or set the number of divisions you want to divide the sun. Althougth you will get better results, the computation and the time will be higher. Otherwise, the improvement on the results will be better depending on the field we were using.


  * The other, is using the script editor.Please, select Automation -->script editor. This will display a new window. A basic script can be like this:
```
//load a file
tonatiuh_filename( "HeliostatSunSevilla.tnh" ); 

/*Define ray tracing options*/
//Number of rays to trace into each iteration
tonatiuh.SetRaysPerIteration( 2000000  );
//Sun divisions.  
tonatiuh.SetRayCastingGrid( 300,300 );
//type of random 
tonatiuh.SetRandomDeviateType("Mersenne Twister");
//Draw options
tonatiuh.SetRaysDrawingOptions( 0, false );
//Buffer size
tonatiuh.SetPhotonMapBufferSize( 5000000 );

//number of interactions 
for( var i = 0; i < 250; ++i ){  

	/*Define export parameters*/
	//The simulation will be saved into a binary file 
	tonatiuh.SetExportPhotonMapType("Binary_file");
	//The coordinates will be saved into target local coordinates
	tonatiuh.SetExportCoordinates( true, false );
	//The intersection surface will not saved because only target photons will be saved.
	tonatiuh. SetExportIntesectionSurface( false );
	//The surface side will also be saved
	tonatiuh.SetExportIntesectionSurfaceSide( true );
	//Previous and next data in not needed
	tonatiuh.SetExportPreviousNextPhotonID( false );
	//Target surface photons will be saved.
	var targetSurface = "//SunNode/RootNode/Tower/Target/TargetRotaionNode/TargetSurface";
	tonatiuh.AddExportSurfaceURL( targetSurface );
	//Define the directory to binary files, the files names and the size in photons for the files.
	var exportDir = "XXXX";
	tonatiuh.SetExportTypeParameterValue( "ExportDirectory",  exportDir );
	var fileNames = "TargetData";
	var iteration = i.toString();
	tonatiuh.SetExportTypeParameterValue( "ExportFile",  fileNames.concat( iteration )  );
	tonatiuh.SetExportTypeParameterValue( "FileSize",  "-1" );

	//Increments the photon map for tunned iterations.
	tonatiuh.SetIncreasePhotonMap( false );

        tonatiuh.Run();
}
```

> In this case, we want to get 5000000 of rays in the target. The previous script creates 250 files of 2000000 of rays to reach the desided number of photons in the target. We have to do that because of the memory limitations to get that amount of data doing one interaction.

|<a href='https://picasaweb.google.com/lh/photo/QHVJLKrPP5ewfcbLBsu5zQ?full-exif=true'><img src='https://lh3.googleusercontent.com/-S_x8vA4PYPU/To2qlbmM92I/AAAAAAAAA9w/76sPARv1i4Y/s800/FluxTutorialModel.png' height='240' width='400' /></a>|
|:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 3.** Tonatiuh's GUI after modeling system.|

# Tonatiuh post-processing #

Tonatiuh doesn't provide a photon map results analizer so it's necessary to use an external aplication such as Mathematica and R. The output photon map is saved in a .dat extension in a seven-tuple for each photon.

## Data post-processing with Mathematica ##
We use mathematica to know when photon maps converge. When we compare the convergence two by two, we get the relative error. If this error reaches a value lower than 0.5% in at least 5 cases, we will admit the result.

### How to create a post-proccess script using Mathematica ###

The following steps explain how we can make a script in Mathematica to read photons properly. In this case the taget was a flat square plane:
  * First, create a Mathematica notebook and save it in the same directory where simulation data is saved.
  * Then set the current working directory the directory where the notebook is saved.
```
SetDirectory[NotebookDirectory[]]
```
  * Next commands are to define target dimentsions, define flate plane width and heigth and compute its area:
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
  * After the definion of the target dimension and target division, the divisions area can be computed.
```
elementWidth = absorberWidth/widthDivisions (*meters*);
elementLength = absorberLength/lengthDivisions (*meters*);
elementArea = elementWidth*elementLength (*meters square*);
```
Now, we are going to define some functions to read files data:
  * The following function reads the names of the parameters in the parameters file:
```
ReadParameters[filename_] := 
 Module[{parametersFileData, parametersStartIndex, parametersEndIndex,
    parameters},
  parametersFileData = ReadList[filename, String]; 
  parametersStartIndex = 
   Flatten[Position[parametersFileData, "START PARAMETERS"]][[1]]; 
  parametersEndIndex = 
   Flatten[Position[parametersFileData, "END PARAMETERS"]][[1]];
  If[(parametersEndIndex - parametersStartIndex) > 1, 
   parameters = 
    Take[parametersFileData, {parametersStartIndex + 1, 
      parametersEndIndex - 1}],
   parameters = {};
   ];
  parameters]
```
  * The function to read the list of surfaces and its identifiers is the following:
```
ReadSurfaces[filename_] := 
 Module[{parametersFileData, surfacesStartIndex, surfacesEndIndex, 
   surfaces},  parametersFileData = ReadList[filename, String];
  surfacesStartIndex = 
   Flatten[Position[parametersFileData, "START SURFACES"]][[1]];
  surfacesEndIndex = 
   Flatten[Position[parametersFileData, "END SURFACES"]][[1]];
  If[(surfacesStartIndex - surfacesEndIndex) > 1, 
   surfaces = 
    Take[parametersFileData, {surfacesStartIndex + 1, 
      surfacesEndIndex - 1}],
   surfaces = {};
   ];
    surfaces]
```
  * Now, we are going to define a function to read the parameters names, surfaces list and the power per photon from the parameters file:
```
ReadTonatiuhParametersFile[filename_] := 
  Module[{parametersFileData, parameters, nParameters, surfaces, 
   data, powerPerPhoton,
       photonsList},
  parametersFileData = ReadList[filename, String];
    parameters = ReadParameters[filename];
    nParameters = Length[parameters];
    surfaces = Sort[ReadSurfaces[filename], #1[[1]] < #2[[1]] &];
    powerPerPhoton = ToExpression[ Last[parametersFileData]];
    {parameters, surfaces, powerPerPhoton}
    ]
```
  * Then, we define the fuction to read the photons data from binary files:
```
ReadTonatiuhResults[filename_] :=   
  BinaryReadList[ filename, "Real64", ByteOrdering -> +1];
```

After defining the needed functions we are going to start reading the files:
  * Find the binary files and compute the number of iterations runned:
```
binaryDataFiles = FileNames["TargetData*.dat"];
nIterations = Length[parametersFile];
```
  * The number of saved parameters per photon and the power per photon is the same for all the iterations. For this reason, we are going to read only once:
```
parametersFile = FileNames["TargetData*_parameters.txt"][[1]];
parameters = ReadTonatiuhParametersFile[parametersFile]
nParametersPerPhoton = Length[parameters[[1]]];
```
  * At this moment, we know what parameters are saved for each photon and the position of the need parameters. In this example there are five parameters for each photon and the 'x' and 'z' coordinates are in the second and forth position. To take this information only we define a new function:
```
transform01[{id_, x_, y_, z_, side_}] := {x, z}
```
  * Using this function and the function to read binary files, we are to create a new function that creates a grid and count the photons in each cell:
```
BinsMatrix[filename_] := Module[{photonList, xzList, photonCounts},
  photonList = 
   Partition[ReadTonatiuhResults[filename], nParametersPerPhoton];
  xzList = Map[transform01, photonList];
  photonCounts = 
   BinCounts[
    xzList, {-absorberWidth/2, absorberWidth/2, 
     elementWidth}, {-absorberLength/2, absorberLength/2, 
     elementLength}];
  photonCounts]
```
  * The next step is create the grid for each binary file:
```
bins = Map[BinsMatrix[#] &, binaryDataFiles];
bins = Table[
   BinsMatrix[binaryDataFiles[[i]]], {i, 1, Length[binaryDataFiles]}];
```
> To make it easier, in case you have lots of photon map files, you can do a parallel simulation. Instead of the last step, we have to use the following ones:
```
 LaunchKernels[2]
 DistributeDefinitions["Global`"]
 bins = ParallelMap[BinsMatrix[#] &, binaryDataFiles] ;
 CloseKernels[];
```
**Note:This only will work if the computer has more than one core. If it not your case, you will not be able to use this step.**

The following steps are to compute the power target for every iteration and the relative error:
  * Compute the power per photon for each iteration. In our simulation, we have started with new photon map and, therefore, the power per photon is the same in all the files. So we can calculate the power per photon as we show bellow:
```
powerPerPhoton = 
  Table[parameters[[3]]/i, {i, 1, Length[binaryDataFiles]}];
```
  * Now we are going join the photons grid. For each iteration, the grid will contain the photons of its file and the photons of the previous iterations files:
```
iterationPhotonCounts = 
  Table[Total[bins[[1 ;; i]]], {i, 1, Length[bins]}];
```
  * The target total power per iteration can be computed as following:
```
targetPower = 
 Table[ powerPerPhoton[[i]]*
   Total[Total[iterationPhotonCounts[[i]]]], {i, 1, 
   Length[powerPerPhoton]}](*W*)
```
  * To see if the results are good or not,we have to get the relative error:
```
errorFluxMax = 
 Table[100*(targetPower[[i]] - targetPower[[i - 1]])/
    targetPower[[i ]], {i, 2, Length[targetPower]}]
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
| **Figure 4.** Relative error graphical output.The red vertical line 

&lt;BR&gt;

 determines the last element which has a relative error >|0.5%| |

Another interesting result might be how the flux is going. To know that.
  * First we are going to compute the flux in the target for every iteration:
```
fluxConversionFactor = 
  Table[(powerPerPhoton[[i]]/1000)/elementArea, {i, 1, 
    Length [powerPerPhoton]}](*kW/(m^2-photon)*);
incidentFluxMatrix = 
  Table[iterationPhotonCounts[[i]]*fluxConversionFactor[[i]], {i, 1, 
    Length[iterationPhotonCounts]}] (*kW/m^2*);
```
  * The maximum flux is computes as follows:
```
fluxMax = 
  Table[Max[incidentFluxMatrix[[i]]], {i, 1, 
    Length[incidentFluxMatrix]}];
```
  * o plot the maximum flux at the target we can use:
```
 flux = ListPlot[fluxMax, Joined -> True, 
  LabelStyle -> Directive["Helvetica", 14], 
  AxesLabel -> {"Rays", 
    "Maximum flux(kW/\!\(\*SuperscriptBox[\(m\), \(2\)]\))"}, 
  PlotRange -> {All, {0, 2}}, ImageSize -> {1000, 600}]
```

|<a href='https://picasaweb.google.com/lh/photo/uGqpzkO7CY2ihd4kWs0k4Q?full-exif=true?'><img src='https://lh6.googleusercontent.com/-yJF0v4fzogg/Tsp64ge5API/AAAAAAAABAw/Y0rU0Ga_Esc/s912/TargetMaximumFlux.png' height='140' width='600' /></a>|
|:----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 5.** Graphical representationof the Maximum Flux.|

  * Finally, we use the last iteration flux to represent graphically the flux at the target:
```
finalIncidentFluxMatrix = Last[incidentFluxMatrix];

(*create a graphic with the flux distribution on the target*)
zmin = 0.0;
zmax = Max[finalIncidentFluxMatrix];
tonatiuh3D = 
 ListPlot3D[finalIncidentFluxMatrix, PlotRange -> All, 
  DataRange -> {{-absorberLength/2, 
     absorberLength/2}, {-absorberWidth/2, absorberWidth/2}}, 
  ColorFunctionScaling -> False, 
  ColorFunction -> 
   Function[{x, y, z}, 
    ColorData[
      "VisibleSpectrum"][(z - zmin)*(750 - 380)/(zmax - zmin) + 380]],
   ViewPoint -> {1.3, -2.4, 2}, PlotLabel -> "TONATIUH", 
  ImageSize -> {400, 400}]
```
|<a href='https://picasaweb.google.com/lh/photo/wCUuCooUVM0oE2-7q2h6VA?full-exif=true?'><img src='https://lh4.googleusercontent.com/-HacP8YPkuSI/Tsp5yNUhr7I/AAAAAAAABAk/3anJI0Br_mQ/s500/100Simulation_bins3D.jpg' height='240' width='450' /></a>|
|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Figure 6.** Example of a flux distribution on the target.|

This is a basic tonatiuh data proccessing. You can look into Mathematica to get other results. If there are any problem or something is wrong either in this tutorial or in Tonatiuh, please, type your discussion at the <a href='http://code.google.com/p/tonatiuh/issues/list'> issues tab </a> or better adding it to <a href='http://groups.google.com/group/tonatiuh-raytracer'>Tonatiuh users group forum. </a>

[Tutorials](Tutorials.md) | | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)