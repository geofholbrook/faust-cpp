#!/bin/bash

set -e

# make esp-idf tools available in shell, compile, and flash
source ${ESP_IDF_PATH}/export.sh
idf.py -p $(read_var PORT .env) flash