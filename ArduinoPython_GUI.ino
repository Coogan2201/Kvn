// Slave: Liquid Arduino

#include <Wire.h>
#include "pins.h"
#include "U8glib.h"
#include "motorClass.h"
motorClass chrisClass;

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
//    pinMode(TrypsinPump,              OUTPUT);                  // Declare peristaltic pumps
//    pinMode(MediaPump,                OUTPUT);
//    pinMode(PbsPump,                  OUTPUT);
    
    Wire.begin(9);                                              // Initialize the I2C
    Wire.onReceive(receiveEvent); // register event

    Serial.begin(9600);                                         // Initialize serial communication
}

void receiveEvent(int bytes) 
{
  wellDown = Wire.read();                                     // read one character from the I2C
}
void draw() 
{
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(15,15);
  u8g.print(wellDown);
  u8g.setPrintPos(15,35);                                       // Print out stuff to the LCD
  u8g.print(yPos);
  u8g.setPrintPos(15,55);
  u8g.print(zPos);
}

void loop()
{
  xPinStatus = digitalRead(X_MIN_PIN);
  yPinStatus = digitalRead(Y_MIN_PIN);                          // Read data from end stops
  zPinStatus = digitalRead(Z_MIN_PIN);
Serial.println(wellDown);
    if(wellDown == 2)                                                    // Find the wells in a plate
    {
      chrisClass.goToWells(6); 
    }
    u8g.firstPage();  
    do 
    {
      draw();                                                 //Initialize LCD
    } 
    while( u8g.nextPage() );
    delay(50);


  while (Serial.available()>0) 
  {
    mot  = Serial.readStringUntil(':');
    Serial.read();
    dir = Serial.readStringUntil(':');                            // Read data from serial port
    Serial.read();
    dis  = Serial.readStringUntil('\0');
    
    
    if(mot=="Y" || mot=="X" || mot=="EX1" || mot=="EX2" || mot == "Z")        // Move motors
    {
      chrisClass.motorz(mot,dir,dis);
    }
    
    if(mot == "Home Axes")                                                    // Home the axes
    {
      chrisClass.homeAxis();
    }
    
    if(mot=="Well plates")                                                    // Find the wells in a plate
    {
      chrisClass.goToWells(6); 
    }

  } 
}
