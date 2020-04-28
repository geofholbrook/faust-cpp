# Flash a Faust DSP program to ESP32
... in our case, on the TTGO TAudio board

Based on [these instructions](
https://faust.grame.fr/doc/tutorials/#using-the-esp32-c-development-environment).

This repo consists of a script, `flash.sh`, and a template, rendering most of those steps unnecessary. 

# usage

You can develop, test and download your .dsp file using the [online Faust editor](https://faust.grame.fr/editor/).

in the terminal, make sure you are navigated to the root of this repo.
make sure the board is connected for flashing.
run 
```
sh ./flash.sh <path-to-DSP-file>
```

(It probably makes sense to put your .dsp files in the faust-code folder, then it becomes sh ./flash.sh ./faust-code/CoolFaustDoohickey.dsp, for instance)

this will leave a working main.cpp file and updated dependencies in the /main directory. to flash again without building, run 
```
sh ./reflash.sh
```

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