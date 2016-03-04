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
    int motorz(String motor, String direction_, String distance)
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

    void motorz2(byte motor, byte direction_, float distance)
    {
      delay(50);
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
        delay(50);
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
        delay(50);
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
          delay(50);
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
          delay(50);
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
    }


    int homeAxis()
    {
      xPos = 0;
      yPos = 0;
      zPos=0;
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
    
    int goToWells(int wellSize)
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
      PumpSystem.Pump(6, EthanolPump, 120, 5000);
      motorz("Z","HIGH","800");
      for(int n = 1; n<=wellRowInt;n++)
      {
        for(int m = 1; m<wellCols;m++)
        { 
          motorz("X","LOW",nextWell);
          motorz("Z","LOW","800");
          delay(100);
          PumpSystem.Pump(6, EthanolPump, 120, 5000);
          motorz("Z","HIGH","800");
        }
        motorz("Y","HIGH",nextWell);
        motorz("Z","LOW","800");
      delay(100);
      PumpSystem.Pump(6, EthanolPump, 120, 5000);
      motorz("Z","HIGH","800");
        for(int m = 1; m<wellCols;m++)
        {
          motorz("X","HIGH",nextWell);
          motorz("Z","LOW","800");
      delay(100);
      PumpSystem.Pump(6, EthanolPump, 120, 5000);
      motorz("Z","HIGH","800");
        } 
      }
    homeAxis(); 
    return 1;
  }
  
    
    
    int changeMedia(int wellSize)
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

        //Aspirate media
      
      motorz("X","LOW",firstXWell);                              
      motorz("Y","LOW",firstYWell);
      motorz("Z","LOW","800");
      delay(100);
      PumpSystem.Pump(wellSize, WastePump, 120, 5000);         //chagen Pump function to incorporate duration and speed control
      motorz("Z","HIGH","800");
      for(int n = 1; n<=wellRowInt;n++)
      {
        for(int m = 1; m<wellCols;m++)
        { 
          motorz("X","LOW",nextWell);
          motorz("Z","LOW","800");
          delay(100);
          PumpSystem.Pump(wellSize, WastePump, 120, 5000);
          motorz("Z","HIGH","800");
        }
        motorz("Y","HIGH",nextWell);
        motorz("Z","LOW","800");
      delay(100);
      PumpSystem.Pump(wellSize, WastePump, 120, 5000);
      motorz("Z","HIGH","800");
        for(int m = 1; m<wellCols;m++)
        {
          motorz("X","HIGH",nextWell);
          motorz("Z","LOW","800");
      delay(100);
      PumpSystem.Pump(wellSize, WastePump, 120, 5000);
      motorz("Z","HIGH","800");
        } 
      }
          homeAxis(); 

      //Ethanol Wash
      
      motorz("X","LOW","8000");
      motorz("Y","LOW","1500");           // Make this spot the waste reservoir
      motorz("Z","LOW","800");
      delay(100);
      PumpSystem.Pump(wellSize, EthanolPump, 120, 5000);    //purge the line
      motorz("Z","HIGH","800");
      homeAxis();

    //PBS Wash

      motorz("X","LOW",firstXWell);
      motorz("Y","LOW",firstYWell);
      motorz("Z","LOW","800");
      delay(100);
      PumpSystem.Pump(wellSize, PBSPump, 120, 5000);
      motorz("Z","HIGH","800");
      for(int n = 1; n<=wellRowInt;n++)
      {
        for(int m = 1; m<wellCols;m++)
        { 
          motorz("X","LOW",nextWell);
          motorz("Z","LOW","800");
          delay(100);
          PumpSystem.Pump(wellSize, PBSPump, 120, 5000);
          motorz("Z","HIGH","800");
        }
        motorz("Y","HIGH",nextWell);
        motorz("Z","LOW","800");
      delay(100);
      PumpSystem.Pump(wellSize, PBSPump, 120, 5000);
      motorz("Z","HIGH","800");
        for(int m = 1; m<wellCols;m++)
        {
          motorz("X","HIGH",nextWell);
          motorz("Z","LOW","800");
      delay(100);
      PumpSystem.Pump(wellSize, PBSPump, 120, 5000);
      motorz("Z","HIGH","800");
        } 
      }
    homeAxis();

    //Aspirate PBS
    
      motorz("X","LOW",firstXWell);                              
      motorz("Y","LOW",firstYWell);
      motorz("Z","LOW","800");
      delay(100);
      PumpSystem.Pump(wellSize, WastePump, 120, 5000);         //chagen Pump function to incorporate duration and speed control
      motorz("Z","HIGH","800");
      for(int n = 1; n<=wellRowInt;n++)
      {
        for(int m = 1; m<wellCols;m++)
        { 
          motorz("X","LOW",nextWell);
          motorz("Z","LOW","800");
          delay(100);
          PumpSystem.Pump(wellSize, WastePump, 120, 5000);
          motorz("Z","HIGH","800");
        }
        motorz("Y","HIGH",nextWell);
        motorz("Z","LOW","800");
      delay(100);
      PumpSystem.Pump(wellSize, WastePump, 120, 5000);
      motorz("Z","HIGH","800");
        for(int m = 1; m<wellCols;m++)
        {
          motorz("X","HIGH",nextWell);
          motorz("Z","LOW","800");
      delay(100);
      PumpSystem.Pump(wellSize, WastePump, 120, 5000);
      motorz("Z","HIGH","800");
        } 
      }
      homeAxis(); 

      // Dispense Media                                       //Didn't finish this step
      motorz("X","LOW",firstXWell);                              
      motorz("Y","LOW",firstYWell);
      motorz("Z","LOW","800");
      delay(100);
      PumpSystem.Pump(wellSize, MediaPump, 120, 5000);         //chagen Pump function to incorporate duration and speed control
      motorz("Z","HIGH","800");
      for(int n = 1; n<=wellRowInt;n++)
      {
        for(int m = 1; m<wellCols;m++)
        { 
          motorz("X","LOW",nextWell);
          motorz("Z","LOW","800");
          delay(100);
          PumpSystem.Pump(wellSize, MediaPump, 120, 5000);
          motorz("Z","HIGH","800");
        }
        motorz("Y","HIGH",nextWell);
        motorz("Z","LOW","800");
      delay(100);
      PumpSystem.Pump(wellSize, MediaPump, 120, 5000);
      motorz("Z","HIGH","800");
        for(int m = 1; m<wellCols;m++)
        {
          motorz("X","HIGH",nextWell);
          motorz("Z","LOW","800");
      delay(100);
      PumpSystem.Pump(wellSize, MediaPump, 120, 5000);
      motorz("Z","HIGH","800");
        } 
      }
      homeAxis();
      return 1; 
  } 

  void relMover(int wellSize, float newPos[])
  {
    xPos = 4180;
    yPos = 10400;           //comment out!!! 
      if(wellSize == 6)
      {
      float Well1[2] = {4180,10400};
      float Well2[2] = {7380,10400};
      float Well3[2] = {10580,10400};
      float Well4[2] = {10580,7200};      
      float Well5[2] = {7380,7200};      
      float Well6[2] = {4180,7200};
      }

       int movePos[2] = {(xPos-newPos[0]),yPos-newPos[1]};
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
