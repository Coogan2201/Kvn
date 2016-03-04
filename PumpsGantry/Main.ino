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
    pinMode(TrypsinPump,              OUTPUT);                  // Declare peristaltic pumps
    pinMode(MediaPump,                OUTPUT);
    pinMode(PBSPump,                  OUTPUT);
    
    Wire.begin(9);                                              // Initialize the I2C
    Wire.onReceive(receiveEvent); // register event

    Serial.begin(9600);                                         // Initialize serial communication
}
void receiveEvent(int bytes) 
{
  incomingByte = Wire.read();                                     // read one character from the I2C
}
void draw() 
{
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(15,15);
//  u8g.print(xPinStatus);
  u8g.print(mot);
  u8g.setPrintPos(15,35);                                       // Print out stuff to the LCD
//  u8g.print(returnState);
    u8g.print(dir);
  u8g.setPrintPos(15,55);
  u8g.print(dis);
//  u8g.print(mot);
}

void loop()
{
//    u8g.firstPage();  
//    do 
//    {
//      draw();                                                 //Initialize LCD
//    }
//    while( u8g.nextPage() );
//    delay(50);
    
  xPinStatus = digitalRead(X_MIN_PIN);
  yPinStatus = digitalRead(Y_MIN_PIN);                          // Read data from end stops
  zPinStatus = digitalRead(Z_MIN_PIN);

  switch(incomingByte)
  {
    case 'A':
    chrisClass.homeAxis();
    break;
    case 'B':
    chrisClass.goToWells(6);
    break;
    case 'C':
    chrisClass.changeMedia(6);
    break;
    case 'D':
    chrisClass.changeMedia(24);
    break;
    case 'E':
    chrisClass.changeMedia(96);
    break;
    case 'F':
    chrisClass.motorz("X","LOW","1");
    break;
    case 'G': 
    chrisClass.motorz("X","HIGH","1");
    break;
//    case 'H':
//    chrisClass.;
//    break;
//    case 'I':
//    chrisClass.;
//    break;
//    case 'J':
//    chrisClass.;
//    break;
//    case 'K':
//    chrisClass.;
//    break;
//    case 'L':
//    chrisClass.;
//    break;
//    case 'M':
//    chrisClass.;
//    break;
//    case 'N':
//    chrisClass.;
//    break;
//    case 'O':
//    chrisClass.;
//    break;
//    case 'P':
//    chrisClass.;
//    break;
//    case 'Q':
//    chrisClass.;
//    break;    
    }


  while (Serial.available()>0) 
  {
    mot  = Serial.readStringUntil(':');
    Serial.read();
    dir = Serial.readStringUntil(':');                            // Read data from serial port
    Serial.read();
    dis  = Serial.readStringUntil('\0');

        u8g.firstPage();  
    do 
    {
      draw();                                                 //Initialize LCD
    }
    while( u8g.nextPage() );
    delay(50);
    
    float a[2] = {dir.toFloat(),dis.toFloat()};
    
    if(mot=="rel")
    {
    chrisClass.relMover(6,a);
    }

    
    if(mot=="Y" || mot=="X" || mot=="EX1" || mot=="EX2" || mot == "Z")        // Move motors
    {
      chrisClass.motorz(mot,dir,dis);
    }
    if(mot=="home")        // Move motors
    {
      chrisClass.homeAxis();
    }
    }
}
