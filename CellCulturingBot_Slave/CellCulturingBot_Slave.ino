// Slave: Liquid Arduino

#include "pumps.h"
#include "motorMovement.h"
#include "Wire.h"
#include "U8glib.h"

char incomingByte;
int xPinStatus;
int yPinStatus;
int zPinStatus;

motorMovement gantrySystem;                                     // create instance of motorClass
pumps pumpSystem;												// Create instance of pumps
U8GLIB_ST7920_128X64_1X u8g(23, 17, 16);						// Declare LCD pins

void setup()
{
	pinMode(X_DIR_PIN, OUTPUT);
	pinMode(Y_DIR_PIN, OUTPUT);
	pinMode(Z_DIR_PIN, OUTPUT);

	pinMode(X_STEP_PIN, OUTPUT);
	pinMode(Y_STEP_PIN, OUTPUT);
	pinMode(Z_STEP_PIN, OUTPUT);

	pinMode(X_ENABLE_PIN, OUTPUT);
	pinMode(Y_ENABLE_PIN, OUTPUT);
	pinMode(Z_ENABLE_PIN, OUTPUT);

	digitalWrite(X_ENABLE_PIN, HIGH);
	digitalWrite(Y_ENABLE_PIN, HIGH);
	digitalWrite(Z_ENABLE_PIN, HIGH);

	pinMode(X_MIN_PIN, INPUT);
	pinMode(Y_MIN_PIN, INPUT);									// Declare end stops
	pinMode(Z_MIN_PIN, INPUT);

	pinMode(EthanolPump, OUTPUT);
	pinMode(WastePump, OUTPUT);
	pinMode(TrypsinPump, OUTPUT);								// Declare peristaltic pumps
	pinMode(MediaPump, OUTPUT);
	pinMode(PBSPump, OUTPUT);

	//Wire.begin(9);                                              // Initialize the I2C (communicate between the two arduinos)
	//Wire.onReceive(receiveEvent);                               // register event
    Serial.begin(9600);                                         // Initialize serial communication
}

//void receiveEvent(int bytes)
//{
//	incomingByte = Wire.read();                                   // read one character from the I2C}
//}

void draw()
{
	u8g.setFont(u8g_font_profont11);
	u8g.setPrintPos(10, 10);                                      // Print out stuff to the LCD
}

void loop()
{

	  while (Serial.available() > 0)
	  {
	    incomingByte = Serial.read();
	    Serial.print(incomingByte);
	  }
	xPinStatus = digitalRead(X_MIN_PIN);
	yPinStatus = digitalRead(Y_MIN_PIN);                          // Read data from end stops
	zPinStatus = digitalRead(Z_MIN_PIN);

	switch (incomingByte)
	{
	case 'A':
		gantrySystem.homeAxes();
		break;
	case 'B':
		gantrySystem.homeAxes();
		gantrySystem.changeMedia(6);
		gantrySystem.homeAxes();
		incomingByte = 'O';
		break;
	case 'C':
		gantrySystem.homeAxes();
		gantrySystem.changeMedia(24);
		gantrySystem.homeAxes();
		incomingByte = 'O';
		break;
	case 'D':
		gantrySystem.homeAxes();
		gantrySystem.cellPassage(24);
		gantrySystem.homeAxes();
		incomingByte = 'O';
		break;
	case 'E':
		gantrySystem.move('X', '0', 50);
		break;
	case 'F':
		gantrySystem.move('X', '1', 50);
		break;
	case 'G':
		gantrySystem.move('Y', '1', 50);
		break;
	case 'H':
		gantrySystem.move('Y', '0', 50);
		break;
	case 'I':
		gantrySystem.move('Z', '1', 100);
		break;
	case 'J':
		gantrySystem.move('Z', '0', 100);
		break;
	case 'K':
		gantrySystem.homeAxes();
		gantrySystem.cellPassage(24);
		gantrySystem.homeAxes();
		incomingByte = 'O';
	case 'N':                         //Bring plate to the front of the system
		gantrySystem.move('Y', '0', 13000);
		break;
	case 'M':                         //Bring plate to the front of the system
		gantrySystem.move('Y', '1', 13000);
		break;

	case '1':
		pumpSystem.Pump(6, WastePump, 120, 1000);
		break;

	case '2':
		//    pumpSystem.Pump(6,TrypsinPump, 150, 1928);          //%2ml
		//    pumpSystem.Pump(6,TrypsinPump, 150, 5501);            //%2ml from empty
		pumpSystem.Pump(6, TrypsinPump, 150, 4300);           //%1ml from empty
															  //    pumpSystem.Pump(6,TrypsinPump, 150, 1000);            //%1ml from full
		break;

	case '3':
		//    pumpSystem.Pump(6,MediaPump, 150, 2384);            //%2ml from full
		//    pumpSystem.Pump(6,MediaPump, 150, 6818);              //%2ml from empty
		pumpSystem.Pump(6, MediaPump, 150, 6000);           //%1ml from empty
															//    pumpSystem.Pump(6,MediaPump, 150, 1200);            //%1ml from full
		break;

	case '4':
		//    pumpSystem.Pump(6,PBSPump, 150, 2466);              //%2ml
		//    pumpSystem.Pump(6,PBSPump, 150, 6411);                //%2ml from empty
		pumpSystem.Pump(6, PBSPump, 150, 5500);               //%1ml from empty
															  //    pumpSystem.Pump(6,PBSPump, 150, 1200);                //%1ml from full
		break;

	case '5':
		//    pumpSystem.Pump(6,EthanolPump, 150, 1711);          //%2ml
		//    pumpSystem.Pump(6,EthanolPump, 150, 5013);            //%2ml from empty
		pumpSystem.Pump(6, EthanolPump, 150, 4300);           //%1ml from empty
															  //    pumpSystem.Pump(6,EthanolPump, 150, 900);            //%1ml from full
		break;

	case '8':
		Serial.println(xPinStatus);
		Serial.println(yPinStatus);
		Serial.println(zPinStatus);
	}
}