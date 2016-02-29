#ifndef MOTORCLASS_H
#define MOTORCLASS_H
#include "Pumps.h"
Pumps PumpSystem;

int stepPin;
int dirPin;
String firstXWell;
String firstYWell;
String nextWell;
int wellRowInt;
int wellCols;

class motorClass
{
  public:
    void motorz(String motor, String direction_, String distance)
    {
      delay(50);
      if (motor == "X")
      {
        stepPin = X_STEP_PIN;
        dirPin = X_DIR_PIN;
        if (direction_ == "HIGH")
        {
          digitalWrite(dirPin,HIGH);
        }
        if (direction_=="LOW")
        {
        digitalWrite(dirPin,LOW);
        }  
        delay(50);
        for(int i =0;i<distance.toInt();i++)            //200 steps/revolution (NEMA 17), 1/16th step per pulse. 3200 pulses/revolution   ? How many revolutions per cm??
        {
          if(direction_=="LOW")
          {
            xPos++;
          }
          if(direction_=="HIGH")
          {
            xPos--;
          }
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(700);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(700);
        }
      }
      
      if (motor == "Y")
      {
        stepPin = Y_STEP_PIN;
        dirPin = Y_DIR_PIN;
        if (direction_ == "HIGH")
        {
          digitalWrite(dirPin,HIGH);
        }
        if (direction_=="LOW")
        {
          digitalWrite(dirPin,LOW);
        }  
        delay(50);
        for(int i =0;i<distance.toInt();i++)            //200 steps/revolution (NEMA 17), 1/16th step per pulse. 3200 pulses/revolution   ? How many revolutions per cm??
        {
          if(direction_=="LOW")
          {
            yPos++;
          }
          if(direction_=="HIGH")
          {
            yPos--;
          }
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(700);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(700);
        }
      }
  
      if (motor == "Z")
      {
        stepPin = Z1_STEP_PIN;
        dirPin = Z1_DIR_PIN;
        
        if (direction_ == "LOW")
        {
          digitalWrite(dirPin,HIGH);
          delay(50);
          for(int i =0;i<distance.toInt();i++)
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(85);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(85);
            zPos--;
          }
        }
        if (direction_ == "HIGH")
        {
          digitalWrite(dirPin,LOW);
          delay(50);
          for(int i =0;i<distance.toInt();i++)
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(85);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(85);
            zPos++;
          }
        }
      }
    }

    void homeAxis()
    {
      xPos = 0;
      yPos = 0;
      zPos=0;
      stepPin = X_STEP_PIN;
      dirPin = X_DIR_PIN;
      digitalWrite(dirPin,HIGH);
      while(xPinStatus==1)
      {
        xPinStatus = digitalRead(X_MIN_PIN);
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(700);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(700);
      }

      digitalWrite(dirPin,LOW);
      for(int i=0;i<=350;i++)            //Tune 150 to get to the ultrasonic sensor
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(700);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(700);
      }
     
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

      digitalWrite(dirPin,LOW);
      for(int i=0;i<=350;i++)
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(800);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(800);
      }

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
      digitalWrite(dirPin,LOW);
      while(zPos<95000)
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(85);
        digitalWrite(stepPin, LOW);         //Set to a Z height so it can move around the working area
        delayMicroseconds(85);
        zPos++;
      }
    }
    void goToWells(int wellSize)
    {

      if(wellSize == 6)
      {
        firstXWell = "4180";
        firstYWell="10400";
        nextWell = "3200";
        wellRowInt = 1;
        wellCols = 3;
      }
      if(wellSize == 24)
      {
        firstXWell = "3380";
        firstYWell="11200";
        nextWell = "1544";
        wellRowInt = 2;
        wellCols = 6;
      }
      if(wellSize==96)
      {
        firstXWell = "3500";
        firstYWell="11250";
        nextWell = "720";
        wellRowInt = 4;
        wellCols = 12;
      }
      motorz("X","LOW",firstXWell);
      motorz("Y","LOW",firstYWell);
      motorz("Z","LOW","800");
      delay(100);
      PumpSystem.Pump(6, EthanolPump);
      motorz("Z","HIGH","800");
      for(int n = 1; n<=wellRowInt;n++)
      {
        for(int m = 1; m<wellCols;m++)
        { 
          motorz("X","LOW",nextWell);
          motorz("Z","LOW","800");
          delay(100);
          PumpSystem.Pump(6, EthanolPump);
          motorz("Z","HIGH","800");
        }
        motorz("Y","HIGH",nextWell);
        motorz("Z","LOW","800");
      delay(100);
      PumpSystem.Pump(6, EthanolPump);
      motorz("Z","HIGH","800");
        for(int m = 1; m<wellCols;m++)
        {
          motorz("X","HIGH",nextWell);
          motorz("Z","LOW","800");
      delay(100);
      PumpSystem.Pump(6, EthanolPump);
      motorz("Z","HIGH","800");
        } 
//        motorz("Y","HIGH",nextWell);
      }
    homeAxis(); 
  }
};
#endif
