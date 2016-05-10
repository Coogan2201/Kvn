class Pumps
{
  public:

  void Pump(int plate, int pumpz, int speedd, int duration)//  void Pump(int plate, int pumpz, int vol)
  {
    if(plate == 6)
    {
      analogWrite(pumpz,speedd);
      delay(duration);
      analogWrite(pumpz,0);
//      delay(2000);
    }
    if(plate == 24)
    {
      analogWrite(pumpz,speedd);
      delay(duration);
      analogWrite(pumpz,0);

    }
    if(plate == 96)
    {
      analogWrite(pumpz,speedd);
      delay(duration);
      analogWrite(pumpz,0);
    }
  }

};
