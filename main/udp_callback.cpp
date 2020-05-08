#include "esp_log.h"
#include "dsp.h"

void udp_callback(char rx_buffer[128])
{
    ESP_LOGI("udp", "received message: %s", rx_buffer);

    faust_setParamValue("freq", 50);
}