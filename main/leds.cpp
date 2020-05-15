#include "FastLED.h"

#define NUM_LEDS 19
#define DATA_PIN 22
#define BRIGHTNESS 50
#define LED_TYPE WS2811
#define COLOR_ORDER RGB

CRGB leds[NUM_LEDS];

void clear_leds()
{
    for (int i = 0; i < 8; i++)
    {
        leds[i] = CRGB::Black;
    }

    FastLED.delay(10);
};

void setup_leds()
{
    FastLED.addLeds<LED_TYPE, DATA_PIN>(leds, NUM_LEDS);
    // FastLED.setMaxPowerInVoltsAndMilliamps(5, 2000);
    FastLED.setBrightness(BRIGHTNESS);
    clear_leds();

    // while (1)
    // {
    //     fadeToBlackBy(&(leds[0]), 19, 1);
    //     FastLED.delay(10);
    // }
};

void set_led(uint8_t led_number, uint8_t red, uint8_t green, uint8_t blue)
{
    leds[led_number] = CRGB(red, green, blue);
    FastLED.delay(10);
};

void set_all_leds(uint8_t red, uint8_t green, uint8_t blue)
{
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i].setRGB(red, green, blue);
    }

    FastLED.delay(10);
};