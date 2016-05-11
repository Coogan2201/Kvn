
#include "motorMovement.h"
#include <Servo.h>

Servo Gripper;
Servo Wrist;

int stepPin;
int dirPin;

motorMovement::motorMovement()
{
	//
}
void motorMovement::move(char motor, char direction_, float distance)             //move the motors
	{
		if (motor == 'Y')
		{
			stepPin = YArm_STEP_PIN;
			dirPin = YArm_DIR_PIN;
			pos = yPos;
			speed = 15000;
		}
		if (motor == 'J')
		{
			stepPin = Joint_STEP_PIN;
			dirPin = Joint_DIR_PIN;
			pos = jPos;
			speed = 700;
		}
		if (motor == 'B')
		{
			stepPin = Base_STEP_PIN;
			dirPin = Base_DIR_PIN;
			pos = bPos;
			speed = 700;
		}
		if (motor == 'Z')
		{
			stepPin = ZArm_STEP_PIN;
			dirPin = ZArm_DIR_PIN;
			pos = zPos;
			speed = 2800;
		}
		if (direction_ == '1')
		{
			digitalWrite(dirPin, HIGH);
		}
		if (direction_ == '0')
		{
			digitalWrite(dirPin, LOW);
		}
		for (int i = 0; i<distance; i++)            //200 steps/revolution (NEMA 17), 1/16th step per pulse. 3200 pulses/revolution   ? How many revolutions per cm??
			{
				if (direction_ == '0')
				{
					pos++;
				}
				if (direction_ == '1')
				{
					pos--;
				}
				digitalWrite(stepPin, HIGH);
				delayMicroseconds(speed);
				digitalWrite(stepPin, LOW);
				delayMicroseconds(speed);
			}
	}

void motorMovement::motorarmHome()
	{
		yPinStatus = digitalRead(YArm_MIN_PIN);                          // Read data from end stops
		jPinStatus = digitalRead(JArm_MIN_PIN);
		bPinStatus = digitalRead(BArm_MIN_PIN);
		zPinStatus = digitalRead(ZArm_MIN_PIN);
		motorz2('B', '1', 900);
		motorz2('J', '1', 200);
		while (zPinStatus == 0)
		{
			zPinStatus = digitalRead(ZArm_MIN_PIN);
			motorz2('Z', '1', 1);
		}
		motorz2('Z', '0', 500);
		while (yPinStatus == 1)
		{
			yPinStatus = digitalRead(YArm_MIN_PIN);
			motorz2('Y', '1', 1);
		}
		motorz2('Y', '0', 680);
		while (digitalRead(BArm_MIN_PIN) == 1)
		{
			bPinStatus = digitalRead(BArm_MIN_PIN);
			motorz2('B', '1', 10);
		}
		while (jPinStatus == 1)
		{
			jPinStatus = digitalRead(JArm_MIN_PIN);
			motorz2('J', '0', 10);
		}
		motorz2('J', '1', 100);
		motorz2('B', '0', 100);
		yPos = 0;
		bPos = 0;
		jPos = 0;
		zPos = 0;
	}

	void movePlate()
	{
		Gripper.write(180);
		Wrist.write(90);                            //release onto the plate
		motorz2('B', '0', 1150);
		motorz2('J', '1', 1500);
		motorz2('Y', '0', 750);
		Wrist.write(0);
	}

	void movePlate2()
	{
		motorz2('Z', '0', 12300);
		Gripper.write(0);
		motorz2('Z', '1', 6800);
		Wrist.write(90);
	}
	void movePlate3()
	{
		motorz2('B', '0', 600);
		motorz2('J', '0', 830);
		motorz2('Y', '1', 760);
		motorz2('Z', '0', 750);
		Gripper.write(90);
		motorz2('Z', '1', 2000);
		incomingByte = '6';
	}
};
#endif
