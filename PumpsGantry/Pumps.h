class Pumps
{
  public:
  void Pump(int plate, int pumpz)//, int delayy)
  {
    if(plate == 6)
    {
      analogWrite(pumpz,120);
      delay(5000);
      analogWrite(pumpz,0);
      delay(1000);
    }
  }
};
