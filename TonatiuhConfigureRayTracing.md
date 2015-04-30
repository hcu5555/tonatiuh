# Configuring the ray tracer #
The ray tracing is the technique that Tonatiuh uses to simulate analyze de solar concentration systems. The rays are generated in a light source, the sun for Tonatiuh, and then these rays intersection with system surfaces are calculated.

Before execute the ray tracer, some parameters can be configured in the following dialog, available from the menu _"Ray Trace">"Ray Trace Options ..."_:


<table>
<tr>
<td align='center'>
<a href='https://picasaweb.google.com/lh/photo/6JLKm9S_ArOZjnCzynrZydMTjNZETYmyPJy0liipFm0?feat=embedwebsite'><img src='https://lh5.googleusercontent.com/-0qEqJwmbWx8/UsV3L0HIR0I/AAAAAAAAAVg/a0xV_WaTie0/s800/RayTracingOptions.png' height='544' width='358' /></a>
</td>
</tr>
<tr>
<td align='center'>
<b>Figure 1.</b>Ray Tracer Options dialog.</td>
</tr>
</table>


## Settings ##
The first parameters to configure are related with the ray generation:
  * _**Number of rays**_: The number of rays to simulate.
  * _**Random Generator**_: Random number generator algorithm.
  * _**With divisions** and **Height divisions**_: A grid is defined in the sun plane for generate rays for the cells of this grid that are enabled (a cell is enabled if a ray with origin in the cell can intersect with a surface). The divisions define de number of cells for each dimension for the grid.


## Draw ##
The draw option are the parameters that define how de simulation results will be showed in the 3D view.
  * _**Show rays**_: Check this option to show the path of the simulated rays.
  * _**Show photons**_: A photon is the data associated with an ray intersection with a scene surface. Check this option to show the photons intersection positions.

In the simulation can be selected to create only photons of one surfaces intersections. If this functionality is used, the draw options are not used and after the simulation the rays and the photons will not be drawn.

## PhotonMap ##
The photon map is the structure that stores the photons in memory. This structure can be configured as following:

  * Buffer size: maximum number of photons to store in the photon map.
  * Construction: This option defines if in consecutive simulations  must start with an empty structure (_**New Photon Map**_) or continue adding (_**Increase photon map**_) photons to the photon map created in the previous simulation.


[User's Guide](UsersGuide.md) | [Wiki Home](http://code.google.com/p/tonatiuh/w/list)