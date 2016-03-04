// Master: Arm Arduino

#include <Wire.h>
int incomingByte;

void setup() 
{
  Wire.begin();
  Serial.begin(9600);                                         // Initialize serial communication
}
void loop() 
{
  Wire.beginTransmission(9); // transmit to device #9
  while (Serial.available()>0) 
  {
    incomingByte = Serial.read();
  }
  switch(incomingByte)
  {
    case 'A':
    Wire.write('A');
    break;
    case 'B':
    Wire.write('B');
    break;    
    case 'C':
    Wire.write('C');
    break;
    case 'D':
    Wire.write('D');
    break;
    case 'E':
    Wire.write('E');
    break;
    case 'F':
    Wire.write('F');
    break;
    case 'G':
    Wire.write('G');
    break;
    case 'H':
    Wire.write('H');
    break;    
    case 'I':
    Wire.write('I');
    break;
    case 'J':
    Wire.write('J');
    break;
    case 'K':
    Wire.write('K');
    break;
    case 'L':
    Wire.write('L');
    break;
    case 'M':
    Wire.write('M');
    break;
    case 'N':
    Wire.write('N');
    break;    
    case 'O':
    Wire.write('O');
    break;
    case 'P':
    Wire.write('P');
    break;
    case 'Q':
    Wire.write('Q');
    break;
//    case 'F':
//    Wire.write('F');
//    break;
    }  
  Wire.endTransmission();    // stop transmitting
}
