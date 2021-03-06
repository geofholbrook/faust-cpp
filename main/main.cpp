/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

#include "WM8978.h"
#include "WM8978.cpp"

#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE
#include "esp_log.h"

#include "udp_server.cpp"

#include "dsp.h"

extern "C" void app_main();

void app_main(void)
{
    udp_main();

    // Init audio codec
    WM8978 wm8978;
    wm8978.init();
    wm8978.addaCfg(1, 1);
    wm8978.inputCfg(1, 0, 0);
    wm8978.outputCfg(1, 0);
    wm8978.micGain(30);
    wm8978.auxGain(0);
    wm8978.lineinGain(0);

    // Set gain
    wm8978.spkVolSet(50); // [0-63]

    wm8978.hpVolSet(40, 40);
    wm8978.i2sCfg(2, 0);

    setup_leds();
    faust_start();

    // Waiting forever
    vTaskSuspend(nullptr);
}