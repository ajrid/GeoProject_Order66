/*
 * Blinky.cpp
 *
 * Created: 6/1/2016 7:21:11 PM
 * Author : AJRID
 */ 

#include <Arduino.h>

bool Debounce(int _pin )
{
	for(int i=0;i<1000;++i)
	{
	if(digitalRead(_pin)==HIGH)
	{
	return false;
	}
	
	}
	return true;
}

int main(void)
{
init();
int buttonred =13;
int ledred=7;
int buttonGREEN =12;
int ledGREEN=6;
int buttonBLUE =11;
int ledBLUE=5;
int LEDTRI_RED =8;
int LEDTRI_GREEN =9;
int LEDTRI_BLUE =10;

int ledstate=HIGH;

int ledstateblue =HIGH;
int ledststategreen=HIGH;
int buttonstateRED;
int lastButtonStateRED;

int buttonstateGREEN;
int lastButtonStateGREEN;

int buttonstateBLUE;
int lastButtonStateBLUE;
long lastDebouncetime=0;
long debouncedelay=50;
pinMode(buttonred, INPUT);
pinMode(ledred,OUTPUT);
pinMode(buttonGREEN, INPUT);
pinMode(ledGREEN,OUTPUT);
pinMode(buttonBLUE, INPUT);
pinMode(ledBLUE,OUTPUT);
pinMode(LEDTRI_RED,OUTPUT);
pinMode(LEDTRI_GREEN,OUTPUT);
pinMode(LEDTRI_BLUE,OUTPUT);

digitalWrite(ledred,ledstate);
digitalWrite(ledGREEN,ledstate);
digitalWrite(ledBLUE,ledstate);

digitalWrite(LEDTRI_RED,ledstate);
digitalWrite(LEDTRI_GREEN,ledstate);
digitalWrite(LEDTRI_BLUE,ledstate);
//digitalWrite(ledred,HIGH);
    /* Replace with your application code */
    while (true) 
    {
	
		lastButtonStateRED=buttonstateRED;
		buttonstateRED=Debounce(buttonred);

		lastButtonStateGREEN=buttonstateGREEN;
		buttonstateGREEN=Debounce(buttonGREEN);
		
		lastButtonStateBLUE=buttonstateBLUE;
		buttonstateBLUE=Debounce(buttonBLUE);

		if(buttonstateRED==LOW && lastButtonStateRED ==HIGH)
		{
		ledstate=!ledstate;
		digitalWrite(ledred,ledstate);
		digitalWrite(LEDTRI_RED,ledstate);

		}
		if(buttonstateGREEN==LOW && lastButtonStateGREEN ==HIGH)
		{
			ledststategreen=!ledststategreen;
			digitalWrite(ledGREEN,ledststategreen);
			digitalWrite(LEDTRI_GREEN,ledststategreen);
			
		}
		if(buttonstateBLUE==LOW && lastButtonStateBLUE ==HIGH)
		{
			ledstateblue=!ledstateblue;
			digitalWrite(ledBLUE,ledstateblue);
			digitalWrite(LEDTRI_BLUE,ledstateblue);
		
		}
	
    }
}

