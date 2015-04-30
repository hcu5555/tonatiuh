# Introduction #
In the simulation of a solar concentration system behaviour there are some factor that are not related with the system design and can alterate simulation results.

Tonatiuh has implemented different models for the sun and the transmissivity to analyze this effects. To define the sun and the transmissivity use the "Environment" menu.

## Sun ##
A system performace is different for a different moments. Furthemore, it is difficult to have a model of the sun. For this reason, differents sunshapes can be used to define the sun for the simulations.

Tonatiuh needs to define the following paramenters for the sun:
  * Sunshape. The available sunshapes are:
    * Buie sunshape
    * Pillbox sunhape
  * Position: The sun position in azimuth and elevation coodinates. The user can deffine this angles or use a calculator to compute this angles.
  * Scene first stage nodes. In order to accelerate the computations, the user can define the nodes that are not first stage nodes. With first stage nodes Tonatiuh will compute a valid area. The rays generated in the ray tracer will have as origin a point in this area and the first intersection will be with an fist stage node.

## Transmissivity ##
The transmissivity is other factor that can change the system result. In the literature there are different models to determine show this to phenomenon affects in solar concentration systems.

Tonatiuh has the following models implemented:
  * "Default Transmissivity"
  * "Ballestrin Transmissivity"
  * "Mirval Transmissivity"
  * "Sengupta-NREL Transmissivity"
  * "VantHull Transmissivity"
  * "VittitoeBiggs Transmissivity"


[User's Guide](UsersGuide.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)