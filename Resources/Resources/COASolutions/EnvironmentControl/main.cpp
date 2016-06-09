/*
* EnvironmentControl.cpp
*
* Created: 6/3/2016 9:13:29 PM
* Author : AJRID
*/

#include <Arduino.h>
#include <Servo.h>
void Tune(uint32_t& _lightlevel,uint32_t &_low,uint32_t &_high)
{
	if(_lightlevel<_low)
	{
		_low=_lightlevel;
	}
	if (_lightlevel>_high)
	{
		_high=_lightlevel;
	}
	//_lightlevel=map(_lightlevel,_high,_low,0,255);
	//_lightlevel=constrain(_lightlevel,0,255);
}


uint32_t SaveData(uint32_t *_data, uint32_t _light)
{
	static uint32_t check=0;
	_data[check]= _light;
	++check;
	
	uint32_t avg;
	for(uint32_t i=0;i<10;++i)
	{
	avg+=_data[i];
	}
	avg/=10;
	check=0;
	if(check==10)
	{
	check=0;
	}
	return avg;
	
}
float TempertureCelcius(float * _data, float _temp)
{
static unsigned int check=0;
_data[check]= _temp;
++check;

float avg;
for(unsigned int i=0;i<10;++i)
{
	avg+=_data[i];
}
avg/=10;
check=0;
if(check==10)
{
	check=0;
}
float degC=0.0;
degC=((avg*0.004882814)-0.5)*100.0;
return degC;
//float answer[2];
//answer[0]=degC;
//answer[1]=(degC*(9,0/5.0)+32.0);
//return answer;

}
float TempertureF(float * _data, float _temp,float cel)
{
	static unsigned int check=0;
	_data[check]= _temp;
	++check;

	float avg;
	for(unsigned int i=0;i<10;++i)
	{
		avg+=_data[i];
	}
	avg/=10;
	check=0;
	if(check==10)
	{
		check=0;
	}
	float degF=0.0;
	degF=(cel*(9,0/5.0)+32.0);
	return degF;
	//float answer[2];
	//answer[0]=degC;
	//answer[1]=(degC*(9,0/5.0)+32.0);
	//return answer;

}
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
	int buttonred =1;
	int ledred=6;
	int ledblue=5;
	int ledstate=HIGH;
	int temp_button=8;
	int temp=0;
	float tempdata;
	uint32_t lightlevelArray[10];
	float temperturearray[10];
	float degc;
	float degf;
	int buttonstate;
	int lastbuttonstate;
	uint32_t mappedLevel;
	uint32_t avg;
	
	uint32_t lightlevel, high=255, low= 0;
	pinMode(temp_button,INPUT_PULLUP);
	pinMode(ledred,OUTPUT);
	pinMode(ledblue,OUTPUT);
	digitalWrite(ledred,HIGH);
	digitalWrite(ledblue,LOW);
	Servo myservo;
	myservo.attach(9);
	uint32_t timer=millis();
	Serial.begin(115200);
	/* Replace with your application code */
	while (true)
	{
	lastbuttonstate=buttonstate;
	buttonstate=Debounce(temp_button);
	tempdata=analogRead(temp);
		if((timer+20)<millis())
		{
			timer=millis();
			lightlevel =analogRead(buttonred);
			
			Tune(lightlevel,low,high);

			if((high-low)<10)
			{
				analogWrite(ledblue,LOW);
				analogWrite(ledred,LOW);
				
			}
			else
			{
				 mappedLevel =map(lightlevel,low,high,0,255);
				 avg = (lightlevelArray,mappedLevel);
				myservo.write(avg);
				analogWrite(ledred,avg);
				analogWrite(ledblue,~avg);
			}
			degc=TempertureCelcius(temperturearray,tempdata);
		degf=TempertureF(temperturearray,tempdata,degc);
			if(high>low)
			{
				high--;
				low++;
			}
			
			
			
		}
		if(buttonstate==LOW&&lastbuttonstate==HIGH)
		{
		Serial.print("Light: avg(");
		Serial.print(avg);
		Serial.print(") min(");
		Serial.print(low);
		Serial.print(") max(");
		Serial.print(high);
		Serial.print(") map(");
		Serial.print(mappedLevel);
		Serial.print(") TEMP: degC(");
		Serial.print(degc);
		Serial.print(") degF(");
		Serial.print(degf);
		Serial.println(")");
		}
		
	}
}

