read_var() {
    VAR=$(grep $1 $2 | xargs)
    IFS="=" read -ra VAR <<< "$VAR"
    echo ${VAR[1]}
}

ESP_IDF_PATH=$(read_var ESP_IDF_PATH .env)

source ${ESP_IDF_PATH}/export.sh

if [ "$1" == "flash" ]
then
    idf.py -p $(read_var PORT .env) flash monitor
else
    idf.py $1
fi
