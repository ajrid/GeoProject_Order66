/*
 * NeoPixelTest.cpp
 *
 * Created: 6/8/2016 9:17:10 PM
 * Author : AJRID
 */ 

#include <Arduino.h>
#include <NeoPixel.h>
#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);
uint32_t Wheel(byte WheelPos);
void theaterChaseRainbow(uint8_t wait);
void theaterChase(uint32_t c, uint8_t wait);
void rainbowCycle(uint8_t wait);
void rainbow(uint8_t wait);
void colorWipe(uint32_t c, uint8_t wait);
int main(void)
{
init();
strip.begin();
strip.setBrightness(25);
strip.show();
    /* Replace with your application code */
    while (true) 
    {
	  colorWipe(strip.Color(255, 0, 0), 50); // Red
	  colorWipe(strip.Color(0, 255, 0), 50); // Green
	  colorWipe(strip.Color(0, 0, 255), 50); // Blue
	  theaterChase(strip.Color(127, 127, 127), 50); // White
	  theaterChase(strip.Color(127,   0,   0), 50); // Red
	  theaterChase(strip.Color(  0,   0, 127), 50); // Blue

	  rainbow(20);
	  rainbowCycle(20);
	  theaterChaseRainbow(50);
    }
	return 0;
}


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
	for(uint16_t i=0; i<strip.numPixels(); i++) {
		strip.setPixelColor(i, c);
		strip.show();
		delay(wait);
	}
}

void rainbow(uint8_t wait) {
	uint16_t i, j;

	for(j=0; j<256; j++) {
		for(i=0; i<strip.numPixels(); i++) {
			strip.setPixelColor(i, Wheel((i+j) & 255));
		}
		strip.show();
		delay(wait);
	}
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
	uint16_t i, j;

	for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
		for(i=0; i< strip.numPixels(); i++) {
			strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
		}
		strip.show();
		delay(wait);
	}
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
	for (int j=0; j<10; j++) {  //do 10 cycles of chasing
		for (int q=0; q < 3; q++) {
			for (int i=0; i < strip.numPixels(); i=i+3) {
				strip.setPixelColor(i+q, c);    //turn every third pixel on
			}
			strip.show();
			
			delay(wait);
			
			for (int i=0; i < strip.numPixels(); i=i+3) {
				strip.setPixelColor(i+q, 0);        //turn every third pixel off
			}
		}
	}
}


void theaterChaseRainbow(uint8_t wait) {
	for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
		for (int q=0; q < 3; q++) {
			for (int i=0; i < strip.numPixels(); i=i+3) {
				strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
			}
			strip.show();
			
			delay(wait);
			
			for (int i=0; i < strip.numPixels(); i=i+3) {
				strip.setPixelColor(i+q, 0);        //turn every third pixel off
			}
		}
	}
}

uint32_t Wheel(byte WheelPos) {
	WheelPos = 255 - WheelPos;
	if(WheelPos < 85) {
		return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
		} else if(WheelPos < 170) {
		WheelPos -= 85;
		return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
		} else {
		WheelPos -= 170;
		return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
	}
}