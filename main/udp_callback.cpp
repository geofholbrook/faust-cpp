#include "esp_log.h"
#include "dsp.h"
#include <string.h>
#include <stdlib.h>

void udp_callback(char rx_buffer[128])
{
    ESP_LOGI("udp", "received message: %s", rx_buffer);

	char delim[] = " ";

    char *param;
    char *value_str = "0"; // avoids [-Werror=maybe-uninitialized]

	param = strtok(rx_buffer, delim);
    
    if (param != NULL)
    {
		 value_str = strtok(NULL, delim);
    }
    
    float value = atof(value_str);
    strcpy(param, param+1);  // removes leading slash
    
	faust_setParamValue(param, value);
}