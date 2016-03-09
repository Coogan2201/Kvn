// Slave: Liquid Arduino

#include <Wire.h>
#include "pins.h"
#include "U8glib.h"
#include "motorClass.h"
motorClass gantrySystem;                                      // create instance of motorClass
Pumps pumpSystem;
U8GLIB_ST7920_128X64_1X u8g(23,17,16);                        // Declare LCD pins

void setup() 
{
    pinMode(X_DIR_PIN,                OUTPUT);
    pinMode(X_STEP_PIN,               OUTPUT);
    pinMode(Y_DIR_PIN,                OUTPUT);
    pinMode(Y_STEP_PIN,               OUTPUT);
    pinMode(Z1_DIR_PIN,               OUTPUT);
    pinMode(Z1_STEP_PIN,              OUTPUT);
    pinMode(EX1_DIR_PIN,              OUTPUT);
    pinMode(EX1_STEP_PIN,             OUTPUT);    
    pinMode(EX2_DIR_PIN,              OUTPUT);                // Declare and enable motors
    pinMode(EX2_STEP_PIN,             OUTPUT);
    pinMode(X_ENABLE_PIN,             OUTPUT);    
    pinMode(Y_ENABLE_PIN,             OUTPUT);
    pinMode(Z1_ENABLE_PIN,            OUTPUT);
    pinMode(EX1_ENABLE_PIN,           OUTPUT);    
    pinMode(EX2_ENABLE_PIN,           OUTPUT);
    digitalWrite(X_ENABLE_PIN,        LOW);
    digitalWrite(Y_ENABLE_PIN,        LOW);
    digitalWrite(Z1_ENABLE_PIN,       LOW);
    digitalWrite(EX1_ENABLE_PIN,      LOW);
    digitalWrite(EX2_ENABLE_PIN,      LOW);
    pinMode(X_MIN_PIN,                INPUT);
    pinMode(Y_MIN_PIN,                INPUT);                   // Declare end stops
    pinMode(Z_MIN_PIN,                INPUT);
    pinMode(EthanolPump,              OUTPUT);
    pinMode(WastePump,                OUTPUT);
    pinMode(TrypsinPump,              OUTPUT);                  // Declare peristaltic pumps
    pinMode(MediaPump,                OUTPUT);
    pinMode(PBSPump,                  OUTPUT);
    Wire.begin(9);                                              // Initialize the I2C (communicate between the two arduinos)
    Wire.onReceive(receiveEvent);                               // register event
    Serial.begin(9600);                                         // Initialize serial communication
}
void receiveEvent(int bytes) 
{
//  incomingByte = Wire.readStringUntil(':');                                   // read one character from the I2C
//  incomingByte = Wire.read();                                   // read one character from the I2C}
}
void draw() 
{
  u8g.setFont(u8g_font_profont11);
  u8g.setPrintPos(15,35);                                       // Print out stuff to the LCD
  u8g.print("Changing Media in a 6 Well Plate");
}
void loop()
{
xPinStatus = digitalRead(X_MIN_PIN);
yPinStatus = digitalRead(Y_MIN_PIN);                          // Read data from end stops
zPinStatus = digitalRead(Z_MIN_PIN);


while (Serial.available()>0) 
{
//  incomingByte  = Serial.readStringUntil(':');
  incomingByte  = Serial.read();
}
//    if(incomingByte=="home")        // Move motors
//    {
//      u8g.firstPage();  
//    do 
//    {
//      draw();                                                 //Initialize LCD
//    }
//    while( u8g.nextPage() );
//    delay(50);
//      gantrySystem.homeAxis();
//    }
//    if(incomingByte=="HomeAxes")
//    {
//      gantrySystem.motorz2('X','0',1000);
//    }
//if(incomingByte=="HomeAxes")
//{
//  gantrySystem.motorz2('X','0',1000);
//  
//}


  switch(incomingByte)
  {
    case 'A':
    gantrySystem.homeAxis();
    break;
    case 'B':
    gantrySystem.changeMedia(6);
    break;
    case 'C':
    gantrySystem.changeMedia(24);
    break;
    case 'D':
    gantrySystem.changeMedia(96);
    break;
    case 'F':
    gantrySystem.motorz2('X','0',1);
    break;
    case 'G': 
    gantrySystem.motorz2('X','0',0);
    break;
    case 'H':
    gantrySystem.motorz2('X','1',1);
    break;
    case 'I':
    gantrySystem.motorz2('X','1',0);
    break;
    case 'J':
    gantrySystem.motorz2('Y','1',1);
    break;
    case 'K':
    gantrySystem.motorz2('Y','1',0);
    break;
    case 'L':
    gantrySystem.motorz2('Y','0',1);
    break;
    case 'M':
    gantrySystem.motorz2('Y','0',0);
    break;
    case 'N':
    gantrySystem.motorz2('Z','1',1);
    break;
    case 'O':
    gantrySystem.motorz2('Z','1',0);
    break;
    case 'P':
    gantrySystem.motorz2('Z','0',1);
    break;
    case 'Q':
    gantrySystem.motorz2('Z','0',0);
    break;    
    case 'R':
    pumpSystem.Pump(6,EthanolPump, 180, 5000);
    break;
    case 'S':
    pumpSystem.Pump(6,WastePump, 180, 5000);
    break;
    case 'T':
    pumpSystem.Pump(6,EthanolPump, 0, 5000);
    break;
    case 'U':
    pumpSystem.Pump(6,WastePump, 0, 5000);
    break;
    }
}
