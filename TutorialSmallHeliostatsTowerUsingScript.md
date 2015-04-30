# Introduction #

This tutorial is going to be an introduction to tonatiuh script tool, which will allow users to create easier solar concentrating systems.


# Main functions #

Those are the functions to develop a system by scripting. They are explained following an alphabetic order:

```
ChangeSunPosition(double azimuth, double elevation) --> 
Sets the sun azimuth and sun elevation to those new values. The sun will be automatically  updated.

ChangeSunPosition(int year, int month, int day, double hours, double minutes, double seconds, double latitude, double longitude ) --> 
Sets the sun azimuth and sun elevation to the position the sun should be at the date and geographical position defined.

Copy()-->Copy the selected node.

Copy(QString nodeURL)-->Copy the nodeURL defined.

CreateGroupNode() --> Creates a separator node.

CreateAnalyzerNode() --> Creates an analyzer node.

CreateMaterial() --> Creates a material surface.

CreateShape(QString shapeType) --> Creates a new shape.

CreateSurfaceNode() --> Creates a TShapeKit node.

CreateTracker(QString trackerType) --> Creates a new tracker.

Cut() --> Cuts the selected node.

Cut(QString nodeURL) --> Cuts the node defined as nodeURL.

Delele() --> The node selected is deleted.

Delete( QString nodeURL) --> Deletes the node defined as nodeURL.

ExportAllPhotonMap(QString fileName) --> saves all PhotonMap in fileName.

ExportPhotonMap(QString fileName, QString nodeURL, bool globalCoord) -->
Saves the nodeURL photonMap in global or relative coordinates into the fileName file.

InsertFileComponent(QString fileName) --> insert a component previously saved in fileName.

New() --> Opens a new window.

Open(QString fileName) --> Opens the fileName file.

Paste(QString nodeURL, QString pasteType) --> Paste the node allocated on the clipboard as a child of nodeURL. pasteType is to indicate the type of paste
between Shared or Copied.

PasteCopy() --> Pastes the node allocated on the clipboard as a new child of the selected node.

PasteLink() --> Pastes the node allocated on the clipboard as a new child of the selected node.Instead a new node, this function creates a new pointer to the physical node.

Run() --> Runs tonatiuh system.

ResetAnalyzerValues() --> Resets analyzer values.

SaveAs(QString fileName)  --> Saves the current system into fileName.

SelectNode(QString nodeURL) --> Selects the nodeURL.

SetAimingPointAbsolute() --> AimingPoint set to Absolute value.

SetAimingPointRelative() --> AimingPoint set to Relative value.

SetIncreasePhotonMap(bool increase) --> Decides whether increase the photonMap or not.

SetNodeName(QString nodeName) --> Changes the selected node name to nodeName.

SetPhotonMapType(QString typeName)--> Selects the typeName photon map.

SetRandomDeviateType(QString typeName) --> Selects the typeName random seed.

SetRayCastingGrid(int widthDivisions, int heightDivisions) --> Sets the number of sun divisions.

SetRaysDrawingOptions(double raysFraction, bool drawPhotons) -->Checks between display or not the Photons and the percent of rays to draw after running the system.

SetRaysPerIteration(int rays) --> Sets the number of desired rays to launch the system.

SetSunshape( QString sunshapeType) -->  Selects the type of sun to simulate the system.

SetSunShapeParameter(QString parameter, QString value) -->Assigns the value to the parameter of the sun.

SetTransmissivity(QString transmissivityType) --> Set the transmissivityType transmissivity to the system.

SetTransmissivityParameter(QString parameter, QString value) --> Assigns the value to the parameter of the transmissivity.

SetValue(QString nodeURL,QString parameter, QString value) --> Set to nodeURL, the value to the parameter.


```


# How to use the functions #

Once the script editor window is opened, you can use a function only by typing tonatiuh and then, the name of the function to use. For example:

tonatiuh.New(); //Creates a new file

tonatiuh.CreateShape("Cone"); //Creates a cone.

Pressing the buttom Run will ejecute it.

# Script Example #

To explain more in detail the script funcionality we are going to develop <a href='http://code.google.com/p/tonatiuh/wiki/TutorialFluxConvergenceOnTowerSystem'> this tutorial </a>

## Modeling the tower ##

The tower is the element in which surface will be fixed the target frame. It will have 130 meters height.
To build it, click Automation-->Script Editor to open the script editor window and, please,type:

```

//Select the RootNode


tonatiuh.SelectNode("//SunNode/RootNode");

//Creates a new TSeparatorKit

tonatiuh.CreateGroupNode();

//Select it

tonatiuh.SelectNode("//SunNode/RootNode/TSeparatorKit1");

//Change the default name to Tower_Frame

tonatiuh.SetNodeName("Tower_Frame");

//Change in Tower_Frame the values of the "translation" parameter to "0 0 76.35"

tonatiuh.SetValue("//SunNode/RootNode/Tower_Frame","translation","0 0 76.35");

//Set Tower_Frame values of "rotation" parameter to "0 0 1 0"

tonatiuh.SetValue("//SunNode/RootNode/Tower_Frame","rotation"," 0 0 1 0");

//Create a SurfaceNode as a child of "Tower_Frame"

tonatiuh.CreateSurfaceNode();

//Select the last node created and rename it to "Tower_shapekit"
tonatiuh.SelectNode("//SunNode/RootNode/Tower_Frame/TShapeKit1");
tonatiuh.SetNodeName("Tower_shapeKit");

//Creates a cone shape as a child of Tower_shapeKit.

tonatiuh.CreateShape("Cone");
//Creates a variable with the route to avoid typing it  the whole time

var tower_shapeKitCone= "//SunNode/RootNode/Tower_Frame/Tower_shapeKit/Cone";

//Change some cone properties such as baseRadius, topRadius, height and activeSide

tonatiuh.SetValue(tower_shapeKitCone,"baseRadius","3");
tonatiuh.SetValue(tower_shapeKitCone,"topRadius","2");
tonatiuh.SetValue(tower_shapeKitCone,"height","130");
tonatiuh.SetValue(tower_shapeKitCone,"activeSide","OUTSIDE");

```

As soon as those lines were typed, please, click Run button and the tower will be created.
### Note: ###
**I recommend NOT to copy this code directly on the script window of Tonatiuh because it ommits the "intro" command. It would be better save it in a file with a .tnhs extension such as tower.tnhs and, then, open it through the script editor.**

## Modeling the receiver ##

Now, continue modeling, in that case, with the receiver. This shape will receive the whole rays reflected on the heliostats field. (The field will be created later). It will be a 10m x 10 m square.
So the following piece of code will create it:

```
//Create the target
//Select the RootNode

tonatiuh.SelectNode("//SunNode/RootNode");

//Creates a new TSepatatorKit node, select it and rename it to Target_Frame

tonatiuh.CreateGroupNode();
tonatiuh.SelectNode("//SunNode/RootNode/TSeparatorKit1");
tonatiuh.SetNodeName("Target_Frame");

//Create a variable to save the node tree path

var Target_FramePath="//SunNode/RootNode/Target_Frame"

tonatiuh.SetValue("//SunNode/RootNode/Target_Frame","translation","0 130 74.25");

tonatiuh.SetValue(Target_FramePath,"rotation"," -1 0 0 1.5707964 ");

//Creates a TShapeKit node
tonatiuh.CreateSurfaceNode();

//Select the TShapeKitNode and rename it to Target_shapeKit

tonatiuh.SelectNode(Target_FramePath.concat("/TShapeKit1"));
tonatiuh.SetNodeName("Target_shapeKit");

//Add a to Target_shapekit a flat_Rectangle and a "Specular_Standard_Material"

tonatiuh.CreateShape("Flat_Rectangle");
tonatiuh.CreateMaterial("Specular_Standard_Material");

var Target_shapekitpath= "//SunNode/RootNode/Target_Frame/Target_shapeKit";

//Set the parameter width,height and activeSide

tonatiuh.SetValue(Target_shapekitpath.concat("/Flat_Rectangle"),"width","10");

tonatiuh.SetValue(Target_shapekitpath.concat("/Flat_Rectangle"),"height","10");

tonatiuh.SetValue(Target_shapekitpath.concat("/Flat_Rectangle"),"activeSide","FRONT");

//Set some options to the material. 
//The most important option is to set the reflectiviy to 0 to avoid rays reflected from the target

tonatiuh.SetValue(Target_shapekitpath.concat("/Specular_Standard_Material"),"m_reflectivity","0");
tonatiuh.SetValue(Target_shapekitpath.concat("/Specular_Standard_Material"),"m_distribution","PILLBOX");
tonatiuh.SetValue(Target_shapekitpath.concat("/Specular_Standard_Material"),"m_ambientColor","0 0 0");
tonatiuh.SetValue(Target_shapekitpath.concat("/Specular_Standard_Material"),"m_diffuseColor","0 0 0");
tonatiuh.SetValue(Target_shapekitpath.concat("/Specular_Standard_Material"),"m_shininess","0.2");

```

## Modeling the heliostats field ##

Once the tower and the target are created, it is time to create the heliostats field. We want to create a 20 rows x 25 columns shape of heliostats. In this case, the centers of the facets of two adjacent heliostats located in a row, or column, is 5.5 meters.


```
//Create a variable with the path
var rootnode="//SunNode/RootNode";

//Select the RootNode and create a new TSeparatorKit node.

tonatiuh.SelectNode(rootnode);
tonatiuh.CreateGroupNode();

//Select it and rename to HeliostatField_Frame

tonatiuh.SelectNode(rootnode.concat("/TSeparatorKit1"));
tonatiuh.SetNodeName("HeliostatField_Frame");
var helFramePath=rootnode.concat("/HeliostatField_Frame");

//trans represents the z_position of the heliostasts
//this first one is in z=-52.3 and they  are separated 5.5 meters

var trans=-52.3;
//We are going to create 20 rows

for(i=1;i<=20;++i){

          //Create a new TSeparatorKitNode

          tonatiuh.SelectNode(helFramePath);
          tonatiuh.CreateGroupNode();
          tonatiuh.SelectNode(helFramePath.concat("/TSeparatorKit1"));

          //set the value of translaation to the heliostat

          tonatiuh.SetValue(helFramePath.concat("/TSeparatorKit1"),"translation","0 0".concat(" ",trans));

          //Change the node name to Row0i_Frame. i goes from 0 to 20
          //The first node will be called Row01_Frame and the last one Row020_Frame

          tonatiuh.SetNodeName("Row0".concat("",i).concat("_Frame"));

          
          //Select the node created create a group node as a child and rename it to Row

          var row=helFramePath.concat("/Row0".concat("",i).concat("_Frame"));
          tonatiuh.SelectNode(row);
          tonatiuh.CreateGroupNode();
          tonatiuh.SelectNode(row.concat("/TSeparatorKit1"));
          tonatiuh.SetNodeName("Row");

          //for each row, we have to create the tree to alocate 25 heliostats

          var NewRow=row.concat("/Row");

          //translation represents the x_position of the heliostasts
          //this first one is in x=-66 and they  are separated 5.5 meters

          var translationRow=-66;
          for(j=1;j<=25;++j){

                            //Create a new GroupNode and change the translation value
                            tonatiuh.SelectNode(NewRow);
                            tonatiuh.CreateGroupNode();
                            tonatiuh.SelectNode(NewRow.concat("/TSeparatorKit1"));
                            tonatiuh.SetValue(NewRow.concat("/TSeparatorKit1"),"translation","".concat("",translationRow).concat(" 0 0"));
                            
                            //Change the  translation parameter for the next iteration

                            translationRow=translationRow+5.5;
                            tonatiuh.SetNodeName("Heliostat".concat("",j).concat("_Frame"));
	                   var helRow=NewRow.concat("/Heliostat".concat("",j).concat("_Frame"));
                            
                            //Create a new groupNode and rename it to Heliostat

                            tonatiuh.SelectNode(helRow);
                            tonatiuh.CreateGroupNode();
                            tonatiuh.SelectNode(helRow.concat("/TSeparatorKit1"));
	                   tonatiuh.SetNodeName("Heliostat");
                            tonatiuh.SelectNode(helRow.concat("/Heliostat"));

                            //Create a tracker as a child of Heliostat and set the amimingPoint to "0 130 74.25"

                            tonatiuh.CreateTracker("Heliostat_tracker");
                            tonatiuh.SetValue(helRow.concat("/Heliostat/Heliostat_tracker"),"aimingPoint","0 130 74.25");
                           

                      }
                     
            //Change the translation parameter for the next iteration

            trans=trans+5.5;
         
}

```

## Inserting the shape and  material ##

In the previous step we have created the struct in which the heliostats will be located. Now, we are going to insert them using the Pastelink way. This technique consists of the creation of an heliostat and the creation of a pointer to it to save memory.

```
//Creating the first heliostat

var i=1;
var j=1;

//get the path to put the heliostat

var path="//SunNode/RootNode/HeliostatField_Frame/Row0".concat("",i).concat("_Frame/Row/Heliostat").concat("",j).concat("_Frame/Heliostat");
tonatiuh.SelectNode(path);

//Create a tShapeKitNode which will contain the shape and the material of the heliostat

tonatiuh.CreateSurfaceNode();
tonatiuh.SelectNode(path.concat("/TShapeKit1"));

//Create the shape. It's going to be a "Spherical_rectangle"

tonatiuh.CreateShape("Spherical_rectangle");

//Create the material. It's going to be a "Specular_Standard_Material"

tonatiuh.CreateMaterial("Specular_Standard_Material");

//Set the "Spherical_rectangle properties"

tonatiuh.SetValue(path.concat("/TShapeKit1/Spherical_rectangle"),"radius","300");
tonatiuh.SetValue(path.concat("/TShapeKit1/Spherical_rectangle"),"widthX","5");
tonatiuh.SetValue(path.concat("/TShapeKit1/Spherical_rectangle"),"widthZ","5");
tonatiuh.SetValue(path.concat("/TShapeKit1/Spherical_rectangle"),"activeSide","INSIDE");

//Set the material properties.

tonatiuh.SetValue(path.concat("/TShapeKit1/Specular_Standard_Material"),"m_reflectivity","1");
tonatiuh.SelectNode(path.concat("/TShapeKit1"));

//Copy the node just created

tonatiuh.Copy();
//we need to paste it inall the files and columns.

for(i=1;i<=20;i++){
for(j=1;j<=25;j++){
      //we eliminate the first case because the heliostat has been created

      if(i==1 && j==1){
      }
      else{
      //Search the path whre we have to paste the heliostat

        var path="//SunNode/RootNode/HeliostatField_Frame/Row0".concat("",i).concat("_Frame/Row/Heliostat").concat("",j).concat("_Frame/Heliostat");
        
        //Select the node and make pasteLink

        tonatiuh.SelectNode(path);
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

  * If we want to change the sun azimuth and zenith we have two ways to do it:

```
tonatiuh.ChangeSunPosition(123,25); //Set the azimuth to 123 and zenith to 25

tonatiuh.ChangeSunPosition(2010,12,11,10,0,0,35.5,-5.23); 
//this function calculates the azimuth and zenith in the place 
//which coordinates are (35.5,-5.23) and date is 11/12/2010 at 10:00:00AM.
```

  * There are two functions to export Tonatiuh data, or we export all photon map or only a certain part.
```
tonatiuh.ExportAllPhotonMap("exportAll.dat"); 
//export the photon in a file called exportAll.dat

tonatiuh.ExportAllPhotonMap("exportNode.dat","//SunNode/RootNode/Target_frame/Target_shapeKit",true); 
//export the photon map of the node Target_ShapeKit to the file exportNode.dat

```

Tonatiuh script is based on ECMAScript specification and has
default options implemented. To know more about them, you can find detailed information about by
following this link: http://developer.qt.nokia.com/doc/qt-4.7/ecmascript.html
or better this one: http://www.ecma-international.org/publications/files/ECMA-ST/Ecma-262.pdf

This is the end of the tutorial. If anybody has any doubts or experiences any problem, please report it here or in <a href='http://groups.google.com/group/tonatiuh-raytracer'>Tonatiuh discussion forum</a>.