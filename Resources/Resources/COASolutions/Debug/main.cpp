/*
 * Debug.cpp
 *
 * Created: 6/3/2016 5:30:33 PM
 * Author : AJRID
 */ 

#include <Arduino.h>


int main(void)
{
init();
uint32_t val = 123456;
Serial.begin(115200);
    /* Replace with your application code */
    while (true) 
    {
	Serial.print("hello");
	Serial.print("")
    }
}

