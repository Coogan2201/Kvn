// Master: Arm Arduino

#include <Wire.h>
#include <Servo.h>
String mot;
String dis;
String dir;
String del;
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 0;
int wellDown=0;
void setup() {
  // Start the I2C Bus as Master
  Wire.begin();
  Serial.begin(9600);                                         // Initialize serial communication

}
void loop() {
  Wire.beginTransmission(9); // transmit to device #9
   while (Serial.available()>0) 
  {
    mot  = Serial.readStringUntil(':');
    Serial.read();
    dir = Serial.readStringUntil(':');                            // Read data from serial port
    Serial.read();
    dis  = Serial.readStringUntil('\0');
Serial.println(mot);
Serial.println(wellDown);
if(mot=="Well plates")                                                    // Find the wells in a plate
    {
      Wire.write(1);              // sends x 
    }
  }
  if(mot=="Well platess")
  {
    Wire.write(2);
  }

    Wire.endTransmission();    // stop transmitting

  
}
