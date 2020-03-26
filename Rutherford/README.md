# Interaction of alpha, beta, and gamma particles with matter

|*Alpha* |*Beta* | *Gamma* |
| ---   | ---  | ---   |
| Transportation | Transportation | Transoportation|
| Ionization | Ionization | Ionization|
|            | Bremmstrahlung | Compton Scattering |
|            |                | Pair-Production |
|            |                | Photo-electric effect|


+ [Transportation](https://en.wikipedia.org/wiki/Transport_phenomena): This is the process in which a particle moves in a medium without loss of energy. 
+ [Ionization](https://en.wikipedia.org/wiki/Ionization): The process by which an atom or a molecule acquires a negative or positive charge by gaining or losing electron is called ionization.
  + eIon:
  + ionIon:
+ [Bremmstrahlung](https://en.wikipedia.org/wiki/Bremsstrahlung): Electromagnetic radiation emmitted by a charged particle when it accelerates or decelerate when passing through the field of a nucleus is called Bremsstrahlung.
+ Compton Scattering: The scattering of atomic electrons by the photon is called compton scattering.
+ [Pair-Production](https://en.wikipedia.org/wiki/Pair_production): The creation of a subatomic particle and its antipartice from a neutral boson is refer as the pair-production.
+ [Photo-electric effect](https://en.wikipedia.org/wiki/Photoelectric_effect): The emission of electrons when the photon of energy greater than threshold energy of a metal falls on the surface of it is called photoelectric effect.
## In AIR

### Different Physics Process that involved when alpha particle passes through the air are:

+ Transportation
+ Ionization
  + eIon
  + ionIon 


### Different Physics Process that involved when beta particle passes through the air are:
+ Transportation
+ Ionization
  + eIon



### Different Physics Process that involved when gamma particle passes through the air are:
+ Transportation
+ Compton Scattering
+ Ionization
# Example of a macro file:

```sh
# print macro commands on screen
/control/verbose 1
# geometry must be specified before /run/initialize
/geometry/source detector.tg
# initialize geometry and physics
/run/initialize

# change particle and its energy here
/gps/particle gamma
/gps/energy 2.6 MeV
/gps/ang/type iso

# visualize geometry and events for debugging
/vis/open HepRepFile
/vis/drawVolume
/vis/scene/add/trajectories
/vis/scene/endOfEventAction accumulate 10

# turn on detailed information about tracking
/tracking/verbose 2
# dump a few events on screen for debugging
/run/beamOn 10

# turn off screen printing for fast simulation
/vis/disable
/tracking/verbose 0
# turn on data recording
/analysis/setFileName output
# turn on progress report
/run/verbose 2
/run/printProgress 1000
# start simulation
/run/beamOn 50000
```


