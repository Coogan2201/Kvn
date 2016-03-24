#ifndef MOTORCLASS_H
#define MOTORCLASS_H
#include <Servo.h>
Servo Gripper;
Servo Wrist;
#include <Wire.h>

int stepPin;
int dirPin;

class motorClass
{
  public:
    void motorz2(byte motor, byte direction_, float distance)             //move the motors
    {
      if (motor == 'Y')
      {
        stepPin = YArm_STEP_PIN;
        dirPin = YArm_DIR_PIN;
        if (direction_ == '1')
        {
          digitalWrite(dirPin,HIGH);
        }
        if (direction_=='0')
        {
          digitalWrite(dirPin,LOW);
        }  
        for(int i =0;i<distance;i++)            //200 steps/revolution (NEMA 17), 1/16th step per pulse. 3200 pulses/revolution   ? How many revolutions per cm??
        {
          if(direction_=='0')
          {
  //          yPos++;
          }
          if(direction_=='1')
          {
//            yPos--;
          }
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(7500);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(7500);
          Serial.println(yPos);
        }
      }
      if (motor == 'J')
      {
        stepPin = Joint_STEP_PIN;
        dirPin = Joint_DIR_PIN;
        if (direction_ == '1')
        {
          digitalWrite(dirPin,HIGH);
        }
        if (direction_=='0')
        {
          digitalWrite(dirPin,LOW);
        }  
        for(int i =0;i<distance;i++)            //200 steps/revolution (NEMA 17), 1/16th step per pulse. 3200 pulses/revolution   ? How many revolutions per cm??
        {
          if(direction_=='0')
          {
    //        jPos++;
          }
          if(direction_=='1')
          {
  //          jPos--;
          }
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(2000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(2000);
          Serial.println(jPos);
        }
      }
            
      if (motor == 'B')
      {
        stepPin = Base_STEP_PIN;
        dirPin = Base_DIR_PIN;
        if (direction_ == '1')
        {
          digitalWrite(dirPin,HIGH);
        }
        if (direction_=='0')
        {
          digitalWrite(dirPin,LOW);
        }  
        for(int i =0;i<distance;i++)            //200 steps/revolution (NEMA 17), 1/16th step per pulse. 3200 pulses/revolution   ? How many revolutions per cm??
        {
          if(direction_=='0')
          {
 //           bPos++;
          }
          if(direction_=='1')
          {
   //         bPos--;
          }
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(2000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(2000);
          Serial.println(bPos);
        }
      }
      
      if (motor == 'Z')
      {
        stepPin = ZArm_STEP_PIN;
        dirPin = ZArm_DIR_PIN;
        if (direction_ == '0')
        {
          digitalWrite(dirPin,HIGH);
          for(int i =0;i<distance;i++)
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(3000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(4000);
           // zPos--;
            Serial.println(zPos);
          }
        }
        if (direction_ == '1')
        {
          digitalWrite(dirPin,LOW);
//          delay(50);
          for(int i =0;i<distance;i++)
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(3000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(4000);
         //   zPos++;
            Serial.println(zPos);
          }
        }
      }
    }

    void armHome()
    {
    yPinStatus = digitalRead(YArm_MIN_PIN);
     while(yPinStatus==1)
      {
        yPinStatus = digitalRead(YArm_MIN_PIN);
        motorz2('Y','1',1);
      }
      motorz2('Y','0',20);
      yPos = 0;
      zPos=0;
      bPos=0;
      jPos=0;
      delay(1000);
      }


      void resetPlate()
      {
        Gripper.write(90);
        motorz2('Y','1',500);
        motorz2('B','1',500);
        motorz2('Y','1',500);
        motorz2('J','0',2300);
//        armHome();
        incomingByte = '6';
      }

      void movePlate()
      {
      motorz2('Y','0',1000);                // bring the arm to the front
      motorz2('B','0',1500);                // .018 degrees per step (2222 for 40 degrees)      
      motorz2('Y','0',1280);
      motorz2('J','1',1400);
//      motorz2('Z','0',600);                 // arm down
//      Gripper.write(0);
//      motorz2('Z','1',600);
//    Wire.write('N');   //move needle plate to the proper position

//      motorz2('Y','1',600);
//      motorz2('J','1',200);
 
      incomingByte = '6';
    }

};
#endif
