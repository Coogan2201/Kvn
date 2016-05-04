// Master: Arm Arduino

#include "pins.h"
#include "motorClass.h"
#include "U8glib.h"
U8GLIB_ST7920_128X64_1X u8g(23,17,16);                        // Declare LCD pins
motorClass gantrySystem;                                      // create instance of motorClass

void draw() 
{
  u8g.setFont(u8g_font_profont11);
  u8g.setPrintPos(10,10);                                       // Print out stuff to the LCD
    u8g.print(zPos);
  u8g.setPrintPos(10,30);                                       // Print out stuff to the LCD
    u8g.print(bPos);
  u8g.setPrintPos(10,50);                                       // Print out stuff to the LCD
    u8g.print(jPos);
  u8g.setPrintPos(50,10);                                       // Print out stuff to the LCD
    u8g.print(bPinStatus);    
 }
void setup() 
{
    pinMode(YArm_DIR_PIN,                 OUTPUT);
    pinMode(YArm_STEP_PIN,                OUTPUT);
    pinMode(YArm_ENABLE_PIN,              OUTPUT);   
    digitalWrite(YArm_ENABLE_PIN,         LOW);
 
    pinMode(Joint_DIR_PIN,                OUTPUT);
    pinMode(Joint_STEP_PIN,               OUTPUT);
    pinMode(Joint_ENABLE_PIN,             OUTPUT);
    digitalWrite(Joint_ENABLE_PIN,        LOW);
    
    pinMode(Base_DIR_PIN,                 OUTPUT);
    pinMode(Base_STEP_PIN,                OUTPUT);
    pinMode(Base_ENABLE_PIN,              OUTPUT);
    digitalWrite(Base_ENABLE_PIN,         LOW);
    
    pinMode(ZArm_DIR_PIN,                 OUTPUT);
    pinMode(ZArm_STEP_PIN,                OUTPUT);
    pinMode(ZArm_ENABLE_PIN,              OUTPUT);
    digitalWrite(ZArm_ENABLE_PIN,         LOW);

    pinMode(YArm_MIN_PIN, INPUT);
    pinMode(ZArm_MIN_PIN, INPUT_PULLUP);    
    pinMode(BArm_MIN_PIN, INPUT);
    pinMode(JArm_MIN_PIN, INPUT);
    
    Gripper.attach(11);
    Wrist.attach(6);
    Serial.begin(19200);   
    
    Wire.begin();
}

void loop() 
{
  Wire.beginTransmission(9); // transmit to device #9
  yPinStatus = digitalRead(YArm_MIN_PIN);                          // Read data from end stops
  zPinStatus = digitalRead(ZArm_MIN_PIN);
  bPinStatus = digitalRead(BArm_MIN_PIN);
  jPinStatus = digitalRead(JArm_MIN_PIN);  

if (Serial.available()>0) 
  {
    incomingByte = Serial.read();
    Serial.print(incomingByte);
  }
  switch(incomingByte)
  {
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    case 'A':             // Home Axes
    Wire.write('A');
    break;
    case 'B':             // Home, change media in 6 well plate, Home
    Wire.write('B');
    break;    
    case 'C':             // change media 24
    Wire.write('C');
    break;
    case 'D':             // change media 96
    Wire.write('D');
    break;
    case 'E':             // X, left
    Wire.write('E');
    break;
    case 'F':             // X, right
    Wire.write('F');
    break;
    case 'G':             // Y, backward
    Wire.write('G');
    break;
    case 'H':             // Y, forward         
    Wire.write('H');
    break;    
    case 'I':             // Z, up
    Wire.write('I');
    break;
    case 'J':             // Z, down
    Wire.write('J');
    break;   
    case 'K':             // Z, down
    Wire.write('K');
    break;
    case 'N':             // plate to front
    Wire.write('N');
    break;
    case 'M':             // plate to back
    Wire.write('M');
    break;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    case 'L':
    gantrySystem.movePlate2();
    break;
    case 'P':
    gantrySystem.movePlate3();
    break;
    case 'V':                                //Home the arm plate
    gantrySystem.armHome();
    break;
    case 'W':
    gantrySystem.movePlate();
    break;
    case 'X':
    gantrySystem.motorz2('B','0',50);            //CCW
    break;
    case 'Y':
    gantrySystem.motorz2('B','1',50);            //clockwise
    break;
    case 'x':
    gantrySystem.motorz2('J','0',50);            //clockwise
    break;
    case 'y':
    gantrySystem.motorz2('J','1',50);            //CCW
    break;
    case 'a':
    Wrist.write(90);                            //release onto the plate
    break;    
    case 'b':
    Wrist.write(0);                             //clamp the plate
    break;
    case 'c':
    gantrySystem.motorz2('Y','1',20);            // Y back 
    break;
    case 'd':
    gantrySystem.motorz2('Y','0',20);            // Y front
    break;
    case 'e':
    gantrySystem.motorz2('Z','1',50);            // Z up
    break;
    case 'f':
    gantrySystem.motorz2('Z','0',50);            // Z down
    break;
    case 'g':
    Gripper.write(180);                            //clamp onto the plate
    break;    
    case 'h':
    Gripper.write(0);                             //release the plate
    break;    

    case '1':
    Wire.write('1');
    break;
    case '2':
    Wire.write('2');
    break;
    case '3':
    Wire.write('3');
    break;
    case '4':
    Wire.write('4');
    break;
    case '5':
    Wire.write('5');
    break;
    case '8':
    Serial.println(jPos);
    
//    u8g.firstPage();  
//      do 
//      {
//        draw();                                                 //Initialize LCD
//      }
//      while( u8g.nextPage() );
//      delay(50);
//    break;
    }  

  Wire.endTransmission();    // stop transmitting
}
