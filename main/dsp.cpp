
#include "FaustProgram.h"
#include "FaustProgram.cpp"

Sawtooth *DSP;

void faust_start() {
    // Allocate and start Faust DSP
    DSP = new Sawtooth(44100, 32);
    DSP->start();
}

void faust_setParamValue(const std::string& path, float value) {
    DSP->setParamValue(path, value);
}




    
