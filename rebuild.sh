#!/bin/bash
read_var() {
    VAR=$(grep $1 $2 | xargs)
    IFS="=" read -ra VAR <<< "$VAR"
    echo ${VAR[1]}
}

ESP_IDF_PATH=$(read_var ESP_IDF_PATH .env)

set -e

# make esp-idf tools available in shell, compile, and flash
source ${ESP_IDF_PATH}/export.sh
idf.py build