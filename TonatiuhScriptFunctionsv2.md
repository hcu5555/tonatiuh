# Introduction #
Tonatiuh has de capability to design and run the simulations using the scripting. To use the scripting open the script editor in _Automation>Script Editor_.

# Main functions #

Those are the functions to develop a system by scripting. They are explained following an alphabetic order:

  * **AddExportSurfaceURL( QString nodeURL )** : Adds the surface with the URL _nodeURL_ to the export surfaces list. The _nodeURL_ is the tree nodes names starting form the root ("\\SunNode\ROOTNODENAME ", where ROOTNODENAME is the name of the root node in the scene ) to the surface node ( the node that contains the surface shape and material).

  * **ChangeSunPosition(double azimuth, double elevation)**: Sets the sun azimuth and sun elevation to those new values. The sun will be automatically  updated.

  * **ChangeSunPosition( int year, int month, int day, double hours, double minutes, double seconds, double latitude, double longitude )**: Changes the sun position to the position defined for a location ( latitude and _longitude_ in degrees) and for the time in UT.

  * **Copy()**: Copies the selected node to the clipboard.

  * **Copy( QString nodeURL )**: Copies the node defined by _nodeURL_ to the clipboard.

  * **CreateGroupNode()**: Creates a separator node as a child of current selected node.

  * **CreateAnalyzerNode()**: Creates an analyzer node as a child of current selected node.

  * **CreateMaterial( QString materialType )**: Creates material node of type _materialType_ as a child of current selected node.

  * _CreateShape( QString shapeType )_: Creates a new shape node of type _shapeType_ as a child of current selected node.

  * **CreateSurfaceNode()**: Creates a Surface node as a child of current selected node.

  * **CreateTracker( QString trackerType )**: Creates a new tracker of type _trackerType_ as child of the current selected node.

  * **Cut()**: Cuts the selected node and saves it at the clipboard.

  * **Cut( QString nodeURL )**: Cuts the node defined as _nodeURL_ and saves it at the clipboard.

  * **Delele()**: Deletes selected node.

  * **Delete( QString nodeURL )**: Deletes the node defined as _nodeURL_ and the childreon of this node form the scene.

  * **InsertFileComponent( QString componentFileName )**: Inserts as a child of the selected node the Tonatiuh component saved at the file _componentFileName_.

  * **New()**: Opens an empty Tonatiuh scene.

  * **Open( QString fileName )**: Opens the _fileName_ file.

  * **Paste( QString nodeURL, QString pasteType )**: Pastes the node allocated on the clipboard as a child of _nodeURL_. The second argument, _pasteType_, indicates the type of paste, _Shared_ or _Copied_.

  * **PasteCopy()**: Pastes the node allocated on the clipboard as a new child of the selected node.

  * **PasteLink()**: Pastes the node allocated on the clipboard as a child of the selected node. Instead a new node, this function creates a new pointer to the physical node.

  * **Run()**: Runs the ray tracer for the current scene.

  * **ResetAnalyzerValues()**: Resets analyzer values.

  * **SaveAs( QString fileName )**: Saves the current system into _fileName_.

  * **SelectNode( QString nodeURL )**: Selects the _nodeURL_.

  * **SetAimingPointAbsolute()**: Sets the _AimingPoint_ parameter value to _Absolute_ value.

  * **SetAimingPointRelative()**: Sets the _AimingPoint_ parameter value to _Relative_ value.

  * **SetExportAllPhotonMap()**: Sets to save all intersection photons.

  * **SetExportCoordinates( bool enabled, bool global )**: If _enabled_ is _false_ the photons coordintates will not be saved into simulations results. Otherwise, the coordinates will be saved into scene coordiantes if _global_ is true or in local coordinates relative to ntersection surface.

  * **SetExportIntesectionSurface( bool enabled )**: If _enabled_ is _true_ the intersection surface will be saved for all photons. Otherwise, this information will not be saved.

  * **SetExportIntesectionSurfaceSide( bool enabled )**: If _enabled_ is _true_ the side of the surface where ray has been intersected. Otherwise, this information will not be saved.

  * **SetExportPhotonMapType( QString exportModeType )**: Sets the export photon type to _exportModeType_. Currently the _"SQL\_Database"_, _"Binary\_file"_ and _"Not export"_ are available.

  * **SetExportPreviousNextPhotonID( bool enabled )**:  If _enabled_ is _true_ the photon previous and next photons ID will be saved. Otherwise, this information will not be saved.

  * **SetExportTypeParameterValue( QString parameterName, QString parameterValue )**: Sets to current selected export type parameter called _parameterName_ the value _parameterValue_.
    * For _"Binary\_file"_ the parameters are:
      * "ExportDirectory": the directory path to store binary files.
      * "ExportFile": the binary files root name.
      * "FileSize": the maximum photons that can be stored into a file. Use "-1" to save into a one file.
    * For _"QSL\_Database"_ the parameters are:
      * "ExportDirectory": the path of directory where the DB will be stored.
      * "DBFilename": The file name for the database.

  * **SetIncreasePhotonMap( bool increase )**: Decides whether increase the photonMap or not for consecutive ray tracer executions.

  * **SetNodeName( QString nodeName )**: Changes the selected node name to _nodeName_.

  * **SetPhotonMapBufferSize( unsigned int nPhotons )**: Sets to _nPhoton_ the maximum number of photons that the photon map can store.

  * **SetRandomDeviateType( QString typeName )**: Sets the type of random number generator to _typeName_. Current Tonatiuh version has available _"Mersenne Twister"_ and _"Rng Stream"_ generators.

  * **SetRayCastingGrid(int widthDivisions, int heightDivisions)**: Sets the number of sun divisions.

  * **SetRaysDrawingOptions( bool drawRays, bool drawPhotons )**: Sets to draw rays and photons after simulations.

  * **SetRaysPerIteration( unsigned int rays )**: Sets the number of rays to trace per each ray trace execution.

  * **SetSunshape( QString sunshapeType )**: Sets the sunshape type to _sunshapeType_ if it is valid type. Currently _"Buie\_Sunshape"_ and _"Pillbox\_Sunshape"_.

  * **SetRaysDrawingOptions( double raysFraction, bool drawPhotons)**: cks between display or not the Photons and the percent of rays to draw after running the system.

  * **SetSunShapeParameter( QString parameter, QString value )**: Assigns the _value_ to the sun parameter _parameter_.

  * **SetTransmissivity( QString transmissivityType )**: Sets the scene transmissivity to _transmissivityType_. The following types are available currently:
    * _"Default Transmissivity"_
    * _"Ballestrin Transmissivity"_
    * _"Mirval Transmissivity"_
    * _"Sengupta-NREL Transmissivity"_
    * _"VantHull Transmissivity"_
    * _"VittitoeBiggs Transmissivity"_

  * **SetTransmissivityParameter( QString parameter, QString value )**: Assings the value into _value_ to the _parameter_ into the current defined transmissivity.

  * **SetValue( QString nodeURL,QString parameter, QString value)**: Sets to parameter with the name _parameter_ of the node _nodeURL_, the value defined into _value_.

In the Tutorials section there is an example of how use this functions to create a tower system a simulate it. Go to [Smal heliostats Tower using script](TutorialSmallHeliostatsTowerUsingScriptv2.md).

[User Guide](UsersGuide.md)| [Wiki Home](http://code.google.com/p/tonatiuh/w/list)