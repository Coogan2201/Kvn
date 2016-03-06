#ifndef MOTORCLASS_H
#define MOTORCLASS_H
#include "Pumps.h"
#include "U8glib.h"

Pumps PumpSystem;
U8GLIB_ST7920_128X64_1X u8g(23,17,16);                        // Declare LCD pins

int stepPin;
int dirPin;
int Well[96][2];
int startX;
int startY;
int wellDist;
int numCols;
int numRows;

class motorClass
{
  public:
  void draw() 
{
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(15,15);
  u8g.print(zPos);
  u8g.setPrintPos(15,35);                                       // Print out stuff to the LCD
    u8g.print(xPos);
  u8g.setPrintPos(15,55);
  u8g.print(yPos);
}
    void motorz2(byte motor, byte direction_, float distance)             //move the motors
    {
//      delay(50);
      if (motor == 'X')
      {
        stepPin = X_STEP_PIN;
        dirPin = X_DIR_PIN;
        if (direction_ == '1')
        {
          digitalWrite(dirPin,HIGH);
        }
        if (direction_=='0')
        {
        digitalWrite(dirPin,LOW);
        }
//        delay(50);
        for(int i =0;i<distance;i++)            //200 steps/revolution (NEMA 17), 1/16th step per pulse. 3200 pulses/revolution   ? How many revolutions per cm??
        {
          if(direction_=='0')
          {
            xPos++;
          }
          if(direction_=='1')
          {
            xPos--;
          }
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(700);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(700);
        }
      }      
      if (motor == 'Y')
      {
        stepPin = Y_STEP_PIN;
        dirPin = Y_DIR_PIN;
        if (direction_ == '1')
        {
          digitalWrite(dirPin,HIGH);
        }
        if (direction_=='0')
        {
          digitalWrite(dirPin,LOW);
        }  
//        delay(50);
        for(int i =0;i<distance;i++)            //200 steps/revolution (NEMA 17), 1/16th step per pulse. 3200 pulses/revolution   ? How many revolutions per cm??
        {
          if(direction_=='0')
          {
            yPos++;
          }
          if(direction_=='1')
          {
            yPos--;
          }
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(700);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(700);
        }
      }
      if (motor == 'Z')
      {
        stepPin = Z1_STEP_PIN;
        dirPin = Z1_DIR_PIN;
        
        if (direction_ == '0')
        {
          digitalWrite(dirPin,HIGH);
//          delay(50);
          for(int i =0;i<distance;i++)
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(85);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(85);
            zPos--;
          }
        }
        if (direction_ == '1')
        {
          digitalWrite(dirPin,LOW);
//          delay(50);
          for(int i =0;i<distance;i++)
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(85);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(85);
            zPos++;
          }
        }
      }
//      u8g.firstPage();  
//    do 
//    {
//      draw();                                                 //Initialize LCD
//    }
//    while( u8g.nextPage() );
//    delay(50);      
    }

    int homeAxis()                                    //bring the motors to the end stops
    {
      stepPin = X_STEP_PIN;
      dirPin = X_DIR_PIN;
      xPinStatus = digitalRead(X_MIN_PIN);
      yPinStatus = digitalRead(Y_MIN_PIN);
      zPinStatus = digitalRead(Z_MIN_PIN);

      digitalWrite(dirPin,HIGH);
      while(xPinStatus==1)
      {
        xPinStatus = digitalRead(X_MIN_PIN);
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(700);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(700);
      }
      motorz2('X','0',350);
      
      stepPin = Y_STEP_PIN;
      dirPin = Y_DIR_PIN;
      digitalWrite(dirPin,HIGH);
      while(yPinStatus==1)
      {
        yPinStatus = digitalRead(Y_MIN_PIN);
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(700);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(700);
      }
      motorz2('Y','0',350);

      stepPin = Z1_STEP_PIN;
      dirPin = Z1_DIR_PIN;
      digitalWrite(dirPin,HIGH);
      while(zPinStatus==1)
      {
        zPinStatus = digitalRead(Z_MIN_PIN);
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(85);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(85);
      }
      zPos = 0;
      while(zPos<80000)
      {
        motorz2('Z','1',1);
      }
      xPos = 0;
      yPos = 0;
  //    zPos=30000;         //fix later
    }
    
    int changeMedia(int wellSize)                             //remove cells, sterilize, wash, add media
    {
      if(wellSize == 6)
      {
        startX = 4180;
        startY = 10400;
        wellDist = 3200;
        numCols = 3;
        numRows = 2;
      }
    if(wellSize == 24)
      {
        startX = 3380;
        startY=11200;
        wellDist = 1544;
        numCols = 6;
        numRows = 4;
      }
      if(wellSize==96)
      {
        startX = 3500;
        startY=11250;
        wellDist = 720;
        numCols = 12;
        numRows = 8;
      }
  
    for(int j = 0; j<numRows;j++)
    {
      for(int i = 0; i<numCols; i++)
      {
        Well[i+(numCols*j)][0] = startX+(i*wellDist);
        Well[i+(numCols*j)][1] = startY - j*wellDist;
        
//        Serial.println(Well[i+(numCols*j)][0]);
//        Serial.println(Well[i+(numCols*j)][1]);
//        Serial.println("n");    
      }
    }
        
      //Aspirate media      
      for(int n=0;n<wellSize;n++)
      {
      relMover(Well[n][0],Well[n][1]);
      motorz2('Z','0',800);
      delay(100);
      PumpSystem.Pump(wellSize, WastePump, 120, 5000);         //change Pump function to incorporate duration and speed control
      motorz2('Z','1',800);
      }

      
      //Ethanol Wash     
      relMover(12000,1500);    // replace with wasteStation[0],wasteStation[1]
      motorz2('Z','0',800);
      delay(100);
      PumpSystem.Pump(wellSize, EthanolPump, 120, 5000);    //Steralize the tubes
      PumpSystem.Pump(wellSize,WastePump,120,5000);         //suck up all the ethanol
      motorz2('Z','1',800);
 
    //PBS Wash
      for(int n=0;n<6;n++)
      {
      relMover(Well[n][0],Well[n][1]);      
      motorz2('Z','0',800);
      delay(100);
      PumpSystem.Pump(wellSize, PBSPump, 120, 5000);
      motorz2('Z','1',800);
      PumpSystem.Pump(wellSize,WastePump,120,500);            //Try this just to prevent leaking everywhere

      }
      
    //Aspirate PBS
      for(int n=0;n<6;n++)
      {
      relMover(Well[n][0],Well[n][1]);      
      motorz2('Z','0',800);
      delay(100);
      PumpSystem.Pump(wellSize, WastePump, 120, 5000);         //chagen Pump function to incorporate duration and speed control
      motorz2('Z','1',800);
      }      
      
      // Dispense Media                                       //Didn't finish this step
      for(int n=0;n<6;n++)
      {
      relMover(Well[n][0],Well[n][1]);      
      motorz2('Z','0',800);
      delay(100);
      PumpSystem.Pump(wellSize, MediaPump, 120, 5000);         //chagen Pump function to incorporate duration and speed control
      motorz2('Z','1',800);
      } 
    }

  void relMover(int newXPos, int newYPos)                   //move to individual plates
  {
      int movePos[] = {(xPos-newXPos),yPos-newYPos};
      if (movePos[0]>0)
      {
      motorz2('X', '1', movePos[0]);
      }
      if (movePos[0]<0)
      {
      motorz2('X', '0', abs(movePos[0]));
      }
      if (movePos[1]>0)
      {
      motorz2('Y', '1', movePos[1]);
      }
      if (movePos[1]<0)
      {
      motorz2('Y', '0', abs(movePos[1]));
      }
      }
};
#endif
