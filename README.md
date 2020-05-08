# Flash a Faust DSP program to ESP32, control parameters via UDP
... in our case, on the TTGO TAudio board

Based on [these instructions](
https://faust.grame.fr/doc/tutorials/#using-the-esp32-c-development-environment).

This repo consists of a script, `flash.sh`, and a template, rendering most of those steps unnecessary. 

# usage

You can develop, test and download your .dsp file using the [online Faust editor](https://faust.grame.fr/editor/).

in the terminal, make sure you are navigated to the root of this repo.

1. (you have to do this only once, or again if someone else has done it and pushed to the repo ... to be fixed!)
```
sh ./esp-idf.sh menuconfig
```
navigate to 'Example Connection Configuration' and enter your wifi credentials.

2. Make sure the board is connected for flashing, then:
```
sh ./flash.sh <path-to-DSP-file>
```

(It probably makes sense to put your .dsp files in the faust-code folder, then it becomes sh ./flash.sh ./faust-code/CoolFaustDoohickey.dsp, for instance)

this will create the dsp.cpp, FaustProgram.cpp, and FaustProgram.h files in the /main directory, build, and flash. Individual actions are also available with esp-idf.sh script:
```
sh ./esp-idf.sh [ menuconfig | build | flash | monitor ]
```

note: `monitor` restarts the board. To exit the monitor use `Ctrl-]`

# UDP control

Parameters controllable by UDP can be set up in the faust code such as in this example:
```
periodms = nentry("period",1000,50,2000,10);
freq = nentry("freq",100, 20, 10000, 1);
strikePosition = nentry("strikePosition", .5, 0, 1, 0.01);
strikeSharpness = nentry("strikeSharpness", .5, 0, 1, 0.01);
gain = nentry("gain", 1, 0, 5, 0.1);
```
only the first two araguments to nentry have any effect in this context, although the have to be there. You can then change arguments over UDP (use 255.255.255.255, or monitor the output to get the specific IP) with a string such as "/freq 440"

# requirements

There are two requirements for the `flash.sh` script to work.
1. you have to have faust2esp32 compiled executable from the terminal
2. you have to have ESP32 development environment installed

## requirement 1: faust2esp32

**You have to compile the master-dev branch of Faust.**

The tutorials say that it is included in the distribution, but as of today (april 25 2020) it seems to only be included in the master-dev branch. So
using instructions taken from [here](https://github.com/grame-cncm/faust/wiki/BuildingSimple) :

```
git clone https://github.com/grame-cncm/faust.git
cd faust
git submodule update --init
```

(commit I used: 56072051920bb4ec482661670bbc8037af12dbe3)

NB: you have to have cmake installed. I have Homebrew (https://brew.sh/), so I used `brew install cmake`.

Then:
```
make
sudo make install
```

NOTE: if you get this error:
`Could NOT find PkgConfig (missing: PKG_CONFIG_EXECUTABLE)`
then you have to run `brew install pkg-config` first! (or sudo apt-get install pkg-config on Linux, i guess. On the Mac just get homebrew.)

the goal here is to have `faust2esp32` available as an executable in the terminal. I think that `sudo make install` puts the faust executables in someplace like /usr/local/bin

## requirement 2: install ESP-IDF

follow the steps [here](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html), up to and including step 3:  (as it says in the esp32 instructions in the Faust tutorial)

side note: if you have any problems running `install.sh` (for example, we ran into something like [this issue](https://github.com/espressif/esp-idf/issues/4744)), you will want to make sure you have an up-to-date version of esp-idf. With `git describe --tags` we get `4.2-dev-1206-g741960d5c`. If it appears to be older than that you should update it. Maybe by erasing the local repo and installing from scratch?