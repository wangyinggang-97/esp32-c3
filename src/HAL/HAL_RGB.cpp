#include "main.h"


CRGB leds[LED_NUM];

Pixel rgb;
HAL::rgb_t  rgb1;

void HAL::RGB_init() {
    rgb.init();
    //rgb.setBrightness(0.1).setRGB(0, 0, 0, 255).setRGB(1, 0, 0, 255);
}

void Pixel::init(void)
{
	FastLED.addLeds<WS2812,RGB_PIN,GRB>(colorbuffers,LED_NUM);
	FastLED.setBrightness(200);
}

Pixel&Pixel::setRGB(int id,int r,int g, int b)
{
   colorbuffers[id]=CRGB(r,g,b);
   FastLED.show();
   return *this;
}

Pixel&Pixel::setBrightness(float duty)
{
	duty = constrain(duty,0,1);
	FastLED.setBrightness((uint8_t)255*duty);
	FastLED.show();
	return *this;
}

void HAL::RGBrandom(int id) {
   if(id==1)
   {
       leds[0] = CRGB::Red;
       FastLED.show();
   }
   if(id==0)
   {
       leds[0] = CRGB::Black;
       FastLED.show();
   }

}

void HAL::RGB_Update() {

}