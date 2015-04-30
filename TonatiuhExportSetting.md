# Phton Map Export Settings #

Tonatiuh generates a large amount of information when a simulation is executed. However, the user may not need all this information and consequently some of the information can be discarded. Tonatiuh, before start a simulation, asks what data the user want to save for the analysis.

<table>
<tr>
<td align='center'>
<a href='https://picasaweb.google.com/lh/photo/ePHGFGVq3Mb9qjJtIxV6XdMTjNZETYmyPJy0liipFm0?feat=embedwebsite'><img src='https://lh6.googleusercontent.com/-AdNRZ4lRVCs/UsWFLSdXtII/AAAAAAAAAXo/WCj8e_XUpxY/s400/ExportSettingsDialog.png' height='400' width='397' /></a>
</td>
</tr>
<tr>
<td align='center'>
<b>Figure 1.</b>Export Settings dialog.</td>
</tr>
</table>


# Parameters #

## Type of store ##

First the user must define the type of store for the photon map. Tonatiuh v2.0.1 has three ways to save simulation data.

  * _**QSL\_Database**_: The data is stored into a database in which the information is accessible using SQL statements. The user must define the directory where the database will be saved and the name for the database file. During the simulation this database will be created with three table:
    * Photons: this table saves all the information about photons. Information related to each photon depends on the parameters that the user wants to save.
    * Surfaces: Saves the identifiers associated to each surface in the system.
    * wphoton: saves the power per photon data.

  * _**Binary\_file**_: the photon map data will be saved into binary files. The parameters to define by the users are the directory to save the files, a base name for the files and the maximum photons number to save into each file. During the simulation two type of files are created: binary files and one ascii file with the exported parameters definition.

  * _**Not export**_: The data calculated in the simulation is not saved. This data is only used for the representation in the 3D view.

## Select photon to store ##

In this section the user can select which photons data want to store:
  * _**Export All Photon Map**_: Select this option to export the data of all the intersection calculated during the simulation.

  * _**Export surfaces**_: This option is used to define one or more surfaces. Only photons related to the intersection on these surfaces will be saved. Add to the list the surface node (the node which groups shape and material nodes) of the surfaces to export.

## Select photons information to store ##

The data that can be saved about each photon is the following:
  * _**Coordinates**_: the intersection point coordinates. This coordinates can be defined as:
    * _**Global Coordinates**_: Coordinates into the system of the scene.
    * _**Local Coordinates**_: Coordinates relative to the shape.
  * _**Surface Identifier**_: Identifier of the surface where the intersection has been given.
  * _**Surface Side**_: surface side identifier where the intersection has been given.
  * _**Photon Previous and Next identifiers**_: Identifier of the photon of the previous/next photon in the ray path.


[User's Guide](UsersGuide.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)