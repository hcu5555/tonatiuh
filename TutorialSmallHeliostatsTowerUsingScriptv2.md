# Introduction #

This tutorial is going to be an introduction to tonatiuh script tool, which will allow users to create easier solar concentrating systems.


# Main functions #

The list of functions available for the scripting is defined in the [Script functions page](TonatiuhScriptFunctionsv2.md).

# How to use the functions #

Once the script editor window is opened, you can use a function only by typing tonatiuh and then, the name of the function to use. For example:

```
tonatiuh.New(); //Creates a new file
tonatiuh.!CreateShape("Cone"); //Creates a cone.
```
Pressing the buttom Run will ejecute it.

# Script Example #

To explain more in detail the script funcionality we are going to develop <a href='http://code.google.com/p/tonatiuh/wiki/http://code.google.com/p/tonatiuh/wiki/TutorialSmallHeliostatsTower'> this tutorial </a> using above functions.

## Modeling the tower ##

The tower is the element in which surface will be fixed the target frame. It will have 130 meters height.
To build it, click Automation-->Script Editor to open the script editor window and, please,type:

```
//Star with an empty system 
tonatiuh.New(); 
 
//Select the RootNode  
tonatiuh.SelectNode("//SunNode/RootNode");  
  
//Creates a new TSeparatorKit  
tonatiuh.CreateGroupNode();  
  
//Select it  
tonatiuh.SelectNode("//SunNode/RootNode/TSeparatorKit1");  
  
//Change the default name to Tower 
tonatiuh.SetNodeName("Tower");  
tonatiuh.SelectNode( "//SunNode/RootNode/Tower" ); 
 
//Creates a new TSeparatorKit to Base node. 
tonatiuh.CreateGroupNode();  
tonatiuh.SelectNode( "//SunNode/RootNode/Tower/TSeparatorKit1" ); 
tonatiuh.SetNodeName( "Base" ); 
 
//Change in Tower the values of the "translation" parameter to "0 0 76.35"  
tonatiuh.SetValue("//SunNode/RootNode/Tower/Base","translation","0 0 76.35"); 
  
//Create a SurfaceNode as a child of "Base"  
tonatiuh.CreateSurfaceNode();  
 
//Select the last node created and rename it to "TowerBaseSurface" 
tonatiuh.SelectNode("//SunNode/RootNode/Tower/Base/TShapeKit1"); 
tonatiuh.SetNodeName("TowerBaseSurface"); 
 
//Creates a cone shape as a child of TowerBaseSurface. 
tonatiuh.CreateShape( "Cone" );
 
//Creates a variable with the route to avoid typing it  the whole time 
var baseSurfaceNode = "//SunNode/RootNode/Tower/Base/TowerBaseSurface/Cone"; 
 
//Change some cylinder properties 
tonatiuh.SetValue( baseSurfaceNode, "baseRadius", "3" ); 
tonatiuh.SetValue( baseSurfaceNode, "topRadius", "2" ); 
tonatiuh.SetValue( baseSurfaceNode, "height", "135");
```

As soon as those lines were typed, please, click Run button and the tower will be created.
### Note: ###
**I recommend NOT to copy this code directly on the script window of Tonatiuh because it ommits the "intro" command. It would be better save it in a file with a .tnhs extension such as tower.tnhs and, then, open it through the script editor.**

## Modeling the receiver ##

Now, continue modeling, in that case, with the receiver. This shape will receive the whole rays reflected on the heliostats field. (The field will be created later). It will be a 20m x 20 m square.
So the following piece of code will create it:

```
//Select Tower node to create the target
tonatiuh.SelectNode( "//SunNode/RootNode/Tower" ); 
tonatiuh.CreateGroupNode();  
tonatiuh.SelectNode( "//SunNode/RootNode/Tower/TSeparatorKit1" ); 
tonatiuh.SetNodeName( "Target" ); 
 
//Change in Target node "translation" parameter values to "0 130 74.25"  
tonatiuh.SetValue("//SunNode/RootNode/Tower/Target","translation","0 130 74.25");  
//Set Target values of "rotation" parameter to "-1 0 0 1.5707964 "  
tonatiuh.SetValue("//SunNode/RootNode/Tower/Target","rotation","-1 0 0 1.5707964 ");  

//Select Target node to create a rotation node
tonatiuh.SelectNode( "//SunNode/RootNode/Tower/Target" ); 
tonatiuh.CreateGroupNode();  
tonatiuh.SelectNode( "//SunNode/RootNode/Tower/Target/TSeparatorKit1" ); 
tonatiuh.SetNodeName( "TargetRotationNode" ); 
 
//Set "TargetRotationNode" values of "rotation" parameter to " 0 1 0  3.1415927"  
tonatiuh.SetValue("//SunNode/RootNode/Tower/Target/TargetRotationNode","rotation"," 0 1 0  3.1415927");  

//Now, create target surface node
tonatiuh.CreateSurfaceNode();  
//Select the last node created and rename it to "TargetSurface"
tonatiuh.SelectNode("//SunNode/RootNode/Tower/Target/TargetRotationNode/TShapeKit1"); 
tonatiuh.SetNodeName("TargetSurface"); 

//Add the shape and material to the surface
tonatiuh.CreateShape( "Flat_Rectangle"); 
tonatiuh.CreateMaterial( "Specular_Standard_Material" ); 

//Change target parameters values 
var targetShapeceNode = "//SunNode/RootNode/Tower/Target/TargetRotationNode/TargetSurface/Flat_Rectangle"; 
tonatiuh.SetValue( targetShapeceNode, "width", "10" ); 
tonatiuh.SetValue( targetShapeceNode, "height", "10");
```

## Modeling the heliostats field ##

Once the tower and the target are created, it is time to create the heliostats field. We want to create a 20 rows x 25 columns shape of heliostats. In this case, the centers of the facets of two adjacent heliostats located in a row, or column, is 5.5 meters.
All the heliostats has the same geometry and, therefore, we are going to use the same heliostat surface for all the heliostats. We are going to create only one and create a link to this heliostat for the rest.

```
//Creates a node for heliostat field

//Create a variable with the path
var rootnode="//SunNode/RootNode";
tonatiuh.SelectNode(rootnode);
tonatiuh.CreateGroupNode();

//Select it and rename to HeliostatField_Frame
tonatiuh.SelectNode(rootnode.concat("/TSeparatorKit1"));
tonatiuh.SetNodeName("HeliostatField");
var fieldPath = rootnode.concat("/HeliostatField");

//zCoord represents the z coordinate of the heliostat positions.
//The first heliostat row is at z=-52.3 and row are separated 5.5 meters.

var zCoord=-52.3;
var rGap = 5.5;

//We are going to create 20 rows
for( r=1; r<=20; ++r){
    //Create a group node for the row
    tonatiuh.SelectNode( fieldPath );
    tonatiuh.CreateGroupNode();
    tonatiuh.SelectNode( fieldPath.concat("/TSeparatorKit1") );
    var rowName = "Row".concat(r);
    tonatiuh.SetNodeName( rowName  );
    var rowPath = fieldPath.concat("/",rowName);

    //set the value of translation to the row
    var rowZ = zCoord + ( r-1 ) * rGap;
    tonatiuh.SetValue(  rowPath ,"translation","0 0".concat(" ",rowZ ) );

    //xCoord represents the x coordinate of the heliostat positions.
    //The first heliostat is at x=-66 and heliostats are separated 5.5 meters.
    var xCoord=-66;
    var hGap = 5.5;
 
    for( h=1;h<= 25; ++h){
        //Create a new GroupNode for the heliostat.
        tonatiuh.SelectNode( rowPath  );
        tonatiuh.CreateGroupNode();
        tonatiuh.SelectNode( rowPath.concat( "/TSeparatorKit1" ) );
        var heliostatName = "Heliostat".concat( h );
        var heliostatPath = rowPath.concat( "/", heliostatName );
        tonatiuh.SetNodeName( heliostatName );
		
        //set the value of translation to the helisotat
        var heliostatX = xCoord + ( h-1 ) * hGap ;
        tonatiuh.SetValue( heliostatPath , "translation", heliostatX.toString().concat(" 0 0" ) );

        //Create a new groupNode for the tracker and rename it
        tonatiuh.CreateGroupNode();
        tonatiuh.SelectNode( heliostatPath.concat( "/TSeparatorKit1" ) );
        tonatiuh.SetNodeName("HeliostatTrackerNode" );
		
        var heliostatTrackerPath = heliostatPath.concat( "/HeliostatTrackerNode" );
        tonatiuh.SelectNode( heliostatTrackerPath  );

        //Create a tracker as a child of Heliostat and set the amimingPoint to "0 130 74.25"
        tonatiuh.CreateTracker("Heliostat_tracker");
        tonatiuh.SetValue( heliostatTrackerPath.concat("/Heliostat_tracker"), "aimingPoint", "0 130 74.25" ); 

        //All the heliostatat has the same geometry. 
        //For this reason, we are going to create only one 
        //and copy it for all helisotats.
        if( r == 1 && h == 1){
            //Create a tShapeKitNode which will contain the shape and the material of the heliostat 
            tonatiuh.CreateSurfaceNode(); 
            tonatiuh.SelectNode( heliostatTrackerPath.concat( "/TShapeKit1") ); 
            tonatiuh.SetNodeName( "HeliostatSurface");
            var heliostatSurfacePath = heliostatTrackerPath.concat( "/HeliostatSurface" );

            //Create the shape. It's going to be a "Spherical_rectangle" 
            tonatiuh.CreateShape("Spherical_rectangle"); 
            tonatiuh.SetValue( heliostatSurfacePath.concat("/Spherical_rectangle"), "radius", "300" ); 
            tonatiuh.SetValue( heliostatSurfacePath.concat("/Spherical_rectangle"), "widthX", "5"); 
            tonatiuh.SetValue( heliostatSurfacePath.concat("/Spherical_rectangle"), "widthZ", "5"); 
            tonatiuh.SetValue( heliostatSurfacePath.concat("/Spherical_rectangle"), "activeSide","INSIDE"); 
			
            //Create the material. It's going to be a "Specular_Standard_Material" 
            tonatiuh.CreateMaterial("Specular_Standard_Material"); 

            //Set the material properties. 
            tonatiuh.SetValue( heliostatSurfacePath.concat( "/Specular_Standard_Material" ), "m_reflectivity", "1" ); 

            //Copy the node just created 
            tonatiuh.Copy(); 
        }
        else{
            tonatiuh.PasteLink(); 
        }	             
    }
}
```
Now we have the whole system created.

## Simulating the system ##

  * Now, we can use some functions to define the sun or the amount of rays desired to simulate the system and then use Run() to simulate it.

  * We decided that we want to simulate 1000000 rays. To do that, type:  tonatiuh.SetRaysPerIteration(1000000);

  * Now we need to define the sun. A default sun shape can be created one of the following lines:
```
 tonatiuh.SetSunshape("Buie_Sunshape");  //define a Buie_sunshape type
 tonatiuh.SetSunshape("Pillbox_Sunshape"); // define a Pillbox_sunshape type
```
> In the tutorial a Pillbox sunshape is used. So, we are goin to define the sunshape and its parameters:
```
tonatiuh.SetSunshape( "Pillbox_Sunshape" );
tonatiuh.SetSunshapeParameter( "irradiance", "920" );
tonatiuh.SetSunshapeParameter( "thetaMax", "0.00465" );
```
  * If we want to change the sun azimuth and zenith we have two ways to do it:
```
tonatiuh.ChangeSunPosition(123,25); //Set the azimuth to 123 and zenith to 25

tonatiuh.ChangeSunPosition(2010, 12, 11, 10, 0, 0, 35.5, -5.23 ); 
//this function calculates the azimuth and zenith in the place 
//which coordinates are (35.5,-5.23) and date is 11/12/2010 at 10:00:00AM.
```

> In the turorial the sun is positioned to azimuth 0º and elevation 90º:
```
 tonatiuh.ChangeSunPosition( 0, 90 );
```

  * Next, we are going to use some of the functions to configure a simulation. This simulation traces 2000000 rays and saves target data to binary file.
```
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
var exportDir = "XXX"; 
tonatiuh.SetExportTypeParameterValue( "ExportDirectory",  exportDir ); 
var fileNames = "TargetData"; 
var iteration = i.toString(); 
tonatiuh.SetExportTypeParameterValue( "ExportFile",  fileNames.concat( iteration )  ); 
tonatiuh.SetExportTypeParameterValue( "FileSize",  "-1" ); 
 
//Increments the photon map for tunned iterations. 
tonatiuh.SetIncreasePhotonMap( false ); 
 
tonatiuh.Run(); 
```

After run this script the tower system will be created and simulated for defined sun position. As result of the simulation the target photons data will be saved into binary files.

Tonatiuh script is based on ECMAScript specification and has
default options implemented. To know more about them, you can find detailed information about by
following this link: http://developer.qt.nokia.com/doc/qt-4.7/ecmascript.html
or better this one: http://www.ecma-international.org/publications/files/ECMA-ST/Ecma-262.pdf

This is the end of the tutorial. If anybody has any doubts or experiences any problem, please report it here or in <a href='http://groups.google.com/group/tonatiuh-raytracer'>Tonatiuh discussion forum</a>.

[Tutorials](Tutorials.md) | | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)