
#include "FaustProgram.h"
#include "FaustProgram.cpp"

Djembe *DSP;

void faust_start() {
    // Allocate and start Faust DSP
    DSP = new Djembe(44100, 32);
    DSP->start();
}

void faust_setParamValue(const std::string& path, float value) {
    DSP->setParamValue(path, value);
}




    
