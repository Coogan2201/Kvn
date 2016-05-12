// 
// 
// 

#include "pumps.h"
#include "Arduino.h"

void pumps::Pump(int plate, int pumpz, int speedd, int duration)
	{
		if (plate == 6)
		{
			analogWrite(pumpz, speedd);
			delay(duration);
			analogWrite(pumpz, 0);
		}
		if (plate == 24)
		{
			analogWrite(pumpz, speedd);
			delay(duration);
			analogWrite(pumpz, 0);

		}
		if (plate == 96)
		{
			analogWrite(pumpz, speedd);
			delay(duration);
			analogWrite(pumpz, 0);
		}
	}