class Pumps
{
  public:
//    void Volume(int speedd, int duration)
//  {
//    int vol = f(speedd,duration);
//  }
  
  
  void Pump(int plate, int pumpz, int speedd, int duration)//  void Pump(int plate, int pumpz, int vol)
  {
    if(plate == 6)
    {
      analogWrite(pumpz,speedd);
      delay(duration);
      analogWrite(pumpz,0);
      delay(2000);
    }
    if(plate == 24)
    {
      analogWrite(pumpz,speedd/4);
      delay(duration/4);
      analogWrite(pumpz,0);
      delay(2000);
    }
    if(plate == 96)
    {
      analogWrite(pumpz,speedd/16);
      delay(duration/16);
      analogWrite(pumpz,0);
      delay(2000);
    }
  }

};
