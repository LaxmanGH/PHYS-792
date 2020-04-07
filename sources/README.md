

An [outdated webpage](http://hurel.hanyang.ac.kr/Geant4/Geant4_GPS/reat.space.qinetiq.com/gps/examples/examples.html) shows most of the examples. In addition, it also shows resulted distribution plots, which are very helpful to understand the real effects of the [gps][] macro commands.

[Geant4][] also provide a much simpler particle source [particle gun]() which is less powerful, but covers some basic user cases.

[Geant4]: http://geant4.cern.ch
[gps]:http://geant4-userdoc.web.cern.ch/geant4-userdoc/UsersGuides/ForApplicationDeveloper/html/GettingStarted/generalParticleSource.html?highlight=general%20particle%20source
[primary particles]: {{site.g4doc}}/Fundamentals/eventGenerator.html

## GPS macros



### Source in a volume

```sh
/gps/pos/confine physics_volume_name
```

### Source on a surface

```sh
 # on a plane
 /gps/pos/type Plane
 # <shape> can be Circle, Annulus, Ellipse, Square, Rectangle
 /gps/pos/shape <shape>
 
 # on the surface of a volume
 /gps/pos/type Surface
 # <shape> can be Sphere, Ellipsoid, Cylinder, EllipticCylinder, Para
 /gps/pos/shape <shape>
```

## Common sources

### Am241

Am241 is a complicated source. It is an alpha, X-ray and gamma emitter at the same time. A mac file [Am241.mac] to demonstrate the definition of multiple particles from a source is included here.

### AmBe

The alpha partiles emitted from Am241 can be used to bonbust Be and generate neutrons up to about 12 MeV. The measured neutron energy spectrum can be found in the literature. A mac file [AmBe.mac]() is included here to demonstrate how to generate neutrons based on an energy spectrum.

### Ar39

Ar39 is a beta emitter. It is a common background for examples ulitize liquid argon as detecting material. Its measured beta spectrum is implemented in the mac file [Ar39.mac]().

### Co57

Co57 is a common low-energy calibration source. It emits a few x and gamma-rays as shown in [Co57.mac]().

### Fe55

Fe55 is an other commonly used low-energy calibration source. It emits a few x-rays around 6 keV as shown in [Fe55.mac]().

## Retrieve information of primary particles

[Co57HPGe.mac]() modifies some default settings of a Co57 source defined in [Co57.mac]() and shoots the emitted photons to a HPGe detector defined in [HPGe.tg](). The following commands show how to retrieve information of the primary particles in this simulation and use it to make event selections:

```cpp
// check primary particle energy distribution
root [] t->Draw("k[0]")
// show results in log scale
root [] gPad->SetLogy()
// show penetration depth (z) of 122 keV gamma rays (trk==1) in HPGe (vlm==1)
root [] t->Draw("z","k[0]>120 && k[0]<130 && trk==1 && vlm==1")
// show penetration depth of 14 keV gamma rays on the same plot
root [] t->Draw("z","k[0]<15 && trk==1 && vlm==1","same")
// show penetration depth of 692 keV gamma rays on the same plot
root [] t->Draw("z","k[0]>300 && trk==1 && vlm==1","same")
```

 ## Define optical properties of a material

~~~cpp
//:prop <material>
//  <wavelength-independent_property> <value>
:prop pureCsIat77K
  SCINTILLATIONYIELD 100./keV
  RESOLUTIONSCALE 2.
  FASTTIMECONSTANT 1.*ns
  SLOWTIMECONSTANT 1.*us
  YIELDRATIO 0.8

//:prop <material> photon_energies <int(array size)> <energy array>
//  <wavelength-dependent_property> <property values>
:prop pureCsIat77K
  photon_energies 2 2.034*eV, 3.025*eV, 4.136*eV
  RINDEX 1.34, 1.35, 1.36
  ABSLENGTH 1.0*meter, 1.1*meter, 1.2*meter
~~~

## Define optical properties of a surface

First of all, there is no need to define a *surface* for polished interfaces between two media. As long as the two media have an index of refraction stored in their respective G4MaterialPropertiesTable, \
the [G4OpBoundaryProcess][]::[PostStepDoIt][] will handle the refraction and reflection correctly.

One can use the following syntax to define a [G4LogicalBorderSurface][] in case that there is a real need to specify the optical properties of the interface:

~~~cpp
//:surf v12v2 v1:copyNo1 v2:copyNo2
:surf CsI2Teflon CsI:1 Teflon:1
  type dielectric_dielectric
  model unified
  finish ground
  sigma_alpha 0.1
  property photon_energies 2 2.5*eV 5.0*eV
    REFLECTIVITY 0.9 0.9
//property must be the last setting due to the current coding method
~~~

Note that physics volumes from the same logical volume created by the text geometry processor share the same name as their logical volume. Since [G4LogicalBorderSurface][] requires pointers to the two physical volumes beside, a unique copy number has to be attached to the volume name to uniquely identify the physics volume.

[GEARS]: http://physino.xyz/gears
[tg]: {{site.g4doc}}/Detector/Geometry/geomASCII.html
[Geant4]: http://geant4.cern.ch
[G4OpBoundaryProcess]: http://www-geant4.kek.jp/lxr/source//processes/optical/include/G4OpBoundaryProcess.hh
[PostStepDoIt]: http://www.apc.univ-paris7.fr/~franco/g4doxy4.10/html/class_g4_op_boundary_process.html#a70a65cc5127a05680a0c4679f8300871
[G4LogicalBorderSurface]: http://www-geant4.kek.jp/lxr/source/geometry/volumes/include/G4LogicalBorderSurface.hh
