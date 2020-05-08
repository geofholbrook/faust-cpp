#!/bin/bash

set -e

read_var() {
    VAR=$(grep $1 $2 | xargs)
    IFS="=" read -ra VAR <<< "$VAR"
    echo ${VAR[1]}
}

ESP_IDF_PATH=$(read_var ESP_IDF_PATH .env)
parent_dir=$(dirname $(pwd))

FILE=$1
BASENAME=$(basename "$FILE")
MODULENAME="${BASENAME%.dsp}"

faust2esp32 $FILE

# unzip generated file
unzip "${MODULENAME}.zip"

# copy and rename generated .h file
cp ./${MODULENAME}/FaustDSP/include/${MODULENAME}.h ./main/FaustProgram.h

# copy and rename generated .cpp file but replace include statement with correct .h file, 
sed "s/${MODULENAME}.h/FaustProgram.h/g" ./${MODULENAME}/FaustDSP/${MODULENAME}.cpp > ./main/FaustProgram.cpp

# add with the EXT_RAM_ATTR attribute where necessary
sed -i "" "s/ftbl0mydspSIG0\[65536\]/ftbl0mydspSIG0\[65536\] EXT_RAM_ATTR/g" ./main/FaustProgram.cpp

# remove zip and unzipped directory
rm "${MODULENAME}.zip"
rm -rf ./${MODULENAME}

# replace reference to faust instrument in template and create main.cpp
# sed "s/%ModuleName%/${MODULENAME}/g" ./main/main-template.cpp > ./main/main.cpp

sed "s/%ModuleName%/${MODULENAME}/g" ./main/dsp-template.txt > ./main/dsp.cpp

# make esp-idf tools available in shell, compile, and flash
source ${ESP_IDF_PATH}/export.sh
idf.py build 
idf.py -p $(read_var PORT .env) flash