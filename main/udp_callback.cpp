#include "esp_log.h"
#include "dsp.h"
#include "leds.h"
#include <string.h>
#include <stdlib.h>

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}


void other_parser(char rx_buffer[128])
{   
    vector<string> words = split(rx_buffer, ' ');
    vector<string> osc_address = split(words[0], '/');
    
    osc_address = vector<string>(osc_address.begin() + 1, osc_address.end());

    for (auto word : words) {
        int n = word.length();
        char char_arr[n + 1];
        strcpy(char_arr, word.c_str());

        ESP_LOGI("udp", "word: %s", char_arr);
    }

    for (auto sub : osc_address ) {
            int n = sub.length();
            char char_arr[n + 1];
            strcpy(char_arr, sub.c_str());

        ESP_LOGI("udp", "addr: %s", char_arr);
    }

    if (osc_address[0] == "led") {
        uint8_t led_number = stoi(words[1]);
        uint8_t red = stoi(words[2]);
        uint8_t green = stoi(words[3]);
        uint8_t blue = stoi(words[4]);

        set_led(led_number, red, green, blue);
    
    } else {
        faust_setParamValue(osc_address[0], stof(words[1]));
    }
}




void udp_callback(char rx_buffer[128])
{
    other_parser(rx_buffer);

    // ESP_LOGI("udp", "received message: %s", rx_buffer);

	// char delim[] = " ";

    // char *param;
    // char *value_str = "0";

	// param = strtok(rx_buffer, delim);
    
    // if (param != NULL)
    // {
	// 	 value_str = strtok(NULL, delim);
    // }
    
    // float value = atof(value_str);
    // strcpy(param, param+1);  // removes leading slash

    // faust_setParamValue(param, value);
}