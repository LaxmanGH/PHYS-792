  
- [geant4/examples/extended/eventgenerator/exgps/macros]({{site.g4git}}/../examples/extended/eventgenerator/exgps/macros)

An [outdated webpage](http://hurel.hanyang.ac.kr/Geant4/Geant4_GPS/reat.space.qinetiq.com/gps/examples/examples.html) shows most of the examples. In addition, it also shows resulted distribution plots, which are very helpful to understand the real effects of the [gps][] macro commands.

[Geant4][] also provide a much simpler particle source ([particle gun]({{site.g4doc}}/Control/AllResources/Control/UIcommands/_gun_.html)), which is less powerful, but covers some basic user cases.

[Geant4]: http://geant4.cern.ch
[gps]:{{site.g4doc}}/GettingStarted/generalParticleSource.html
[primary particles]: {{site.g4doc}}/Fundamentals/eventGenerator.html

## GPS macros

An ASCII version of the manual of [gps][] macros is available [here]({{site.xyz}}/examples/sources/gps.txt).

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

Am241 is a complicated source. It is an alpha, X-ray and gamma emitter at the same time. A mac file is inclued [here]({{site.file}}/examples/sources/Am241.mac) to demonstrate the definition of multiple particles from a source.

### AmBe

The alpha partiles emitted from Am241 can be used to bonbust Be and generate neutrons up to about 12 MeV. The measured neutron energy spectrum can be found in the literature. A mac file is included [here]({{site.file}}/examples/sources/AmBe/AmBe.mac) to demonstrate how to generate neutrons based on an energy spectrum.

### Ar39

Ar39 is a beta emitter. It is a common background for examples ulitize liquid argon as detecting material. Its measured beta spectrum is implemented in [this mac file]({{site.file}}/examples/sources/Ar39.mac).

### Co57

Co57 is a common low-energy calibration source. It emits a few x and gamma-rays as shown in [this mac file]({{site.file}}/examples/sources/Co57.mac).

### Fe55

Fe55 is an other commonly used low-energy calibration source. It emits a few x-rays around 6 keV as shown in [this mac file]({{site.file}}/examples/sources/Fe55.mac).

## Retrieve information of primary particles

[Co57HPGe.mac]({{site.file}}/examples/sources/Co57HPGe.mac) modifies some default settings of a Co57 source defined in [Co57.mac]({{site.file}}/examples/sources/Co57.mac) and shoots the emitted photons to a HPGe detector defined in [HPGe.tg]({{site.file}}/examples/sources/HPGe.tg). The following commands show how to retrieve information of the primary particles in this simulation and use it to make event selections:

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

