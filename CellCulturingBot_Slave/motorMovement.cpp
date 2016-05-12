
#include "motorMovement.h"
#include "Arduino.h"
#include "pumps.h"
pumps PumpSystem;

int stepPin;
int dirPin;
float yPos;
float xPos;
float zPos;
int pos;
int mydata;
int Well[96][2];
int startX;
int startY;
int wellDist;
int numCols;
int numRows;
int ethanolTime;
int pbsTime;
int trypsinTime;
int mediaTime;
int ethanolFullTime;
int pbsFullTime;
int trypsinFullTime;
int mediaFullTime;
int speed;



void motorMovement::move(char motor, char direction_, float distance)
{
	if (motor == 'X')
	{
		stepPin = X_STEP_PIN;
		dirPin = X_DIR_PIN;
		pos = xPos;
		speed = 70;
	}
	else if (motor == 'Y')
	{
		stepPin = Y_STEP_PIN;
		dirPin = Y_DIR_PIN;
		pos = yPos;
		speed = 70;
	}
	else if (motor == 'Z')
	{
		stepPin = Z_STEP_PIN;
		dirPin = Z_DIR_PIN;
		pos = zPos;
		speed = 25;
	}
	if (direction_ == '1')
	{
		digitalWrite(dirPin, HIGH);
	}
	else if (direction_ == '0')
	{
		digitalWrite(dirPin, LOW);
	}
	for (int i = 0; i<distance; i++)            //200 steps/revolution (NEMA 17), 1/16th step per pulse. 3200 pulses/revolution   ? How many revolutions per cm??
	{
		if (direction_ == '0')
		{
			pos++;
		}
		else if (direction_ == '1')
		{
			pos--;
		}
		digitalWrite(stepPin, HIGH);
		delayMicroseconds(speed);
		digitalWrite(stepPin, LOW);
		delayMicroseconds(speed);
	}
}

void motorMovement::homeAxes()
{
	int xPinStatus = 0;
	int yPinStatus = 0;
	int zPinStatus = 0;
	stepPin = X_STEP_PIN;
	dirPin = X_DIR_PIN;
	xPinStatus = digitalRead(X_MIN_PIN);
	yPinStatus = digitalRead(Y_MIN_PIN);
	zPinStatus = digitalRead(Z_MIN_PIN);

	digitalWrite(dirPin, HIGH);
	while (xPinStatus == 1)
	{
		xPinStatus = digitalRead(X_MIN_PIN);
		digitalWrite(X_ENABLE_PIN, LOW);
		digitalWrite(stepPin, HIGH);
		delayMicroseconds(70);
		digitalWrite(stepPin, LOW);
		delayMicroseconds(70);
		digitalWrite(X_ENABLE_PIN, HIGH);
	}
	move('X', '0', 250);

	stepPin = Y_STEP_PIN;
	dirPin = Y_DIR_PIN;
	digitalWrite(dirPin, HIGH);
	digitalWrite(Y_ENABLE_PIN, LOW);
	while (yPinStatus == 1)
	{
		yPinStatus = digitalRead(Y_MIN_PIN);
		digitalWrite(stepPin, HIGH);
		delayMicroseconds(70);
		digitalWrite(stepPin, LOW);
		delayMicroseconds(70);
	}
	digitalWrite(Y_ENABLE_PIN, HIGH);
	move('Y', '0', 350);

	stepPin = Z_STEP_PIN;
	dirPin = Z_DIR_PIN;
	digitalWrite(dirPin, HIGH);
	digitalWrite(Z_ENABLE_PIN, LOW);
	while (zPinStatus == 1)
	{
		zPinStatus = digitalRead(Z_MIN_PIN);
		digitalWrite(stepPin, HIGH);
		delayMicroseconds(25);
		digitalWrite(stepPin, LOW);
		delayMicroseconds(25);
	}
	digitalWrite(Z_ENABLE_PIN, HIGH);
	zPos = 0;
	while (zPos<88000)
	{
		move('Z', '1', 1);
	}
	xPos = 0;
	yPos = 0;
}

void motorMovement::changeMedia(int wellSize)                             //remove cells, sterilize, wash, add media
{
	if (wellSize == 6)
	{
		startX = 6800;
		startY = 9050;
		wellDist = 3200;
		numCols = 3;
		numRows = 2;
		ethanolTime = 5013;
		pbsTime = 6411;
		trypsinTime = 5501;
		mediaTime = 6818;
		ethanolFullTime = 1711;
		pbsFullTime = 2466;
		trypsinFullTime = 1928;
		mediaFullTime = 2384;
	}
	else if (wellSize == 24)
	{
		startX = 6250;
		startY = 9500;
		wellDist = 1544;
		numCols = 6;
		numRows = 4;
		ethanolTime = 5013;
		pbsTime = 5700;
		trypsinTime = 4500;
		mediaTime = 6000;
		ethanolFullTime = 1711;
		pbsFullTime = 1200;
		trypsinFullTime = 960;
		mediaFullTime = 1190;
	}

	for (int j = 0; j<numRows; j++)
	{
		for (int i = 0; i<numCols; i++)
		{
			Well[i + (numCols*j)][0] = startX + (i*wellDist);
			Well[i + (numCols*j)][1] = startY - j*wellDist;
		}
	}
	//Wash with Ethanol & PBS
	relMover(900, 850);
	PumpSystem.Pump(wellSize, EthanolPump, 120, ethanolTime);
	PumpSystem.Pump(wellSize, PBSPump, 120, pbsTime);

	//Aspirate media      
	for (int n = 0; n<wellSize; n++)
	{
		relMover(Well[n][0], Well[n][1]);
		while (zPos>13500)
		{
			move('Z', '0', 1);
		}

		PumpSystem.Pump(wellSize, WastePump, 255, 5000);
		while (zPos<88000)
		{
			move('Z', '1', 1);
		}
	}

	//PBS Wash     
	relMover(900, 850);
	PumpSystem.Pump(wellSize, PBSPump, 120, pbsTime);
	PumpSystem.Pump(wellSize, WastePump, 255, 5000);

	// Dispense Media
	relMover(Well[0][0], Well[0][1]);
	while (zPos>70000)
	{
		move('Z', '0', 1);
	}
	PumpSystem.Pump(wellSize, MediaPump, 120, mediaTime);
	while (zPos<88000)
	{
		move('Z', '1', 1);
	}
	for (int n = 0; n<wellSize - 1; n++)
	{
		relMover(Well[n + 1][0], Well[n + 1][1]);
		while (zPos>70000)
		{
			move('Z', '0', 1);
		}
		PumpSystem.Pump(wellSize, MediaPump, 120, mediaFullTime);
		while (zPos<88000)
		{
			move('Z', '1', 1);
		}
	}

	//Wash with Ethanol & PBS
	relMover(900, 850);
	PumpSystem.Pump(wellSize, EthanolPump, 120, ethanolTime);
	PumpSystem.Pump(wellSize, PBSPump, 120, pbsTime);
	PumpSystem.Pump(wellSize, WastePump, 255, 5000);
}


void motorMovement::cellPassage(int wellSize)
{
	if (wellSize == 6)
	{
		startX = 6800;
		startY = 9050;
		wellDist = 3200;
		numCols = 3;
		numRows = 2;
		ethanolTime = 5013;
		pbsTime = 6411;
		trypsinTime = 5501;
		mediaTime = 6818;
		ethanolFullTime = 1711;
		pbsFullTime = 2466;
		trypsinFullTime = 1928;
		mediaFullTime = 2384;
	}
	else if (wellSize == 24)
	{
		startX = 6250;
		startY = 9500;
		wellDist = 1544;
		numCols = 3;
		numRows = 4;
		ethanolTime = 5013;
		pbsTime = 5700;
		trypsinTime = 4500;
		mediaTime = 6000;
		ethanolFullTime = 1711;
		pbsFullTime = 1200;
		trypsinFullTime = 960;
		mediaFullTime = 1500;
	}

	for (int j = 0; j<numRows; j++)
	{
		for (int i = 0; i<numCols; i++)
		{
			Well[i + (numCols*j)][0] = startX + (i*wellDist);
			Well[i + (numCols*j)][1] = startY - j*wellDist;
		}
	}

	//Aspirate media      
	//      for(int n=0;n<12;n++)
	//      {
	//        relMover(Well[n][0],Well[n][1]);
	//        while(zPos>13500)
	//        {
	//          motorz2('Z','0',1);
	//        }      
	//        PumpSystem.Pump(wellSize, WastePump, 255, 5000);
	//        while(zPos<88000)
	//        {
	//          motorz2('Z','1',1);
	//        }
	//      }

	//PBS Wash
	//      relMover(Well[0][0],Well[0][1]);      
	//      PumpSystem.Pump(wellSize, PBSPump, 120, pbsTime);
	//      for(int n=0;n<12-1;n++)
	//      {
	//        relMover(Well[n+1][0],Well[n+1][1]);
	//        while(zPos>70000)
	//        {
	//          move('Z','0',1);
	//        }      
	//        PumpSystem.Pump(wellSize, PBSPump, 120, pbsFullTime);
	//        while(zPos<88000)
	//        {
	//          move('Z','1',1);
	//        }
	//      }

	//      //Aspirate PBS      
	//      for(int n=0;n<12;n++)
	//      {
	//        relMover(Well[n][0],Well[n][1]);
	//        while(zPos>13500)
	//        {
	//          move('Z','0',1);
	//        }      
	//        PumpSystem.Pump(wellSize, WastePump, 255, 5000);
	//        while(zPos<88000)
	//        {
	//          move('Z','1',1);
	//        }
	//      }

	//      //Deposit trypsin
	//      relMover(Well[0][0],Well[0][1]);      
	//      PumpSystem.Pump(wellSize, TrypsinPump, 120, trypsinTime); //increase this by double
	//      for(int n=0;n<12-1;n++)
	//      {
	//        relMover(Well[n+1][0],Well[n+1][1]);
	//        while(zPos>70000)
	//        {
	//          move('Z','0',1);
	//        }      
	//        PumpSystem.Pump(wellSize, TrypsinPump, 120, trypsinFullTime/2);
	//        while(zPos<88000)
	//        {
	//          move('Z','1',1);
	//        }
	//      }
	//      relMover(900,850);    //Kevin is done
	//      delay(60000);     //This is when the user removes the cells to put them in the incubator      
	//      
	//Deposit Media
	relMover(Well[0][0], Well[0][1]);
	PumpSystem.Pump(wellSize, MediaPump, 120, mediaTime);
	for (int n = 0; n<12 - 1; n++)
	{
		relMover(Well[n + 1][0], Well[n + 1][1]);
		while (zPos>70000)
		{
			move('Z', '0', 1);
		}
		PumpSystem.Pump(wellSize, MediaPump, 120, mediaFullTime / 2);
		while (zPos<88000)
		{
			move('Z', '1', 1);
		}
	}
	delay(60000);   //User replaces waste tube with collection tube

					//Aspirate Cells
	for (int n = 0; n<12; n++)
	{
		relMover(Well[n][0], Well[n][1]);
		while (zPos>13500)
		{
			move('Z', '0', 1);
		}
		PumpSystem.Pump(wellSize, WastePump, 255, 5000);
		while (zPos<88000)
		{
			move('Z', '1', 1);
		}
	}
	relMover(900, 850);    //Kevin is done

	delay(60000); //User adds a new well plate

				  //Deposit Media
	relMover(Well[0][0], Well[0][1]);
	PumpSystem.Pump(wellSize, MediaPump, 120, mediaTime);
	for (int n = 0; n<12 - 1; n++)
	{
		relMover(Well[n + 1][0], Well[n + 1][1]);
		while (zPos>70000)
		{
			move('Z', '0', 1);
		}
		PumpSystem.Pump(wellSize, MediaPump, 120, mediaFullTime);
		while (zPos<88000)
		{
			move('Z', '1', 1);
		}
	}
	relMover(900, 850);    //Kevin is done
}

void motorMovement::relMover(int newXPos, int newYPos)                   //move to individual plates
{
	int movePos[] = { (xPos - newXPos),yPos - newYPos };
	if (movePos[0]>0)
	{
		move('X', '1', movePos[0]);
	}
	else if (movePos[0]<0)
	{
		move('X', '0', abs(movePos[0]));
	}
	else if (movePos[1]>0)
	{
		move('Y', '1', movePos[1]);
	}
	else if (movePos[1]<0)
	{
		move('Y', '0', abs(movePos[1]));
	}
}