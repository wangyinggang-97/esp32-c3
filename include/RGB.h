#ifndef  _RGB_H
#define  _RGB_H

#include "main.h"

#define RGB_PIN 8
#define LED_NUM 2

class Pixel
{
	private:
		/* data */
		CRGB colorbuffers[LED_NUM];
	public:
	void init();
	Pixel&setRGB(int id,int r,int g, int b);
	Pixel&setBrightness(float duty);
};


#endif