#include "main.h"


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