int wellFinder(String wellSize, int Xdist1, int Ydist1)
{
  for(int i=0;i<=220;i++)     //220 represents working area of Kvn
  {
    if(wellSize=="6")
    {
      if (Xdist1 == i)
      {
        well1x = i+24.76;
        well2x = well1x + 39.12;
        well3x = well2x + 39.12;
      }
      if(Ydist1 == i)
      {
        well1y = i+23.16;
        well2y = well1y+39.12;
      }
      wellZHeight = 2.54; //mm
      wellVolume = 16.8; //ml
    }
  
    if(wellSize=="12")
    {
      if (Xdist1 == i)
      {
        well1x = i+24.94;
        well2x = well1x + 26.01;
        well3x = well2x + 26.01;
        well4x = well2x + 26.01;
      }
      if(Ydist1 == i)
      {
        well1y = i+16.79;
        well2y = well1y+26.01;
        well3y = well1y+26.01;
      }
      wellZHeight = 2.16; //mm
      wellVolume = 6.9; //ml
      }

    if(wellSize=="24")
    {
      if (Xdist1 == i)
      {
        well1x = i+17.52;
        well2x = well1x + 19.3;
        well3x = well2x + 19.3;
        well4x = well2x + 19.3;
        well5x = well2x + 19.3;
        well6x = well2x + 19.3;
      }
      if(Ydist1 == i)
      {
        well1y = i+13.84;
        well2y = well1y+19.3;
        well3y = well1y+19.3;
        well4y = well1y+19.3;
      }
      wellZHeight = 2.87; //mm
      wellVolume = 1.9; //ml
    }
    if(wellSize=="48")
    {
      if (Xdist1 == i)
      {
        well1x = i+18.16;
        well2x = well1x + 13.08;
        well3x = well2x + 13.08;
        well4x = well2x + 13.08;
        well5x = well2x + 13.08;
        well6x = well2x + 13.08;
        well7x = well2x + 13.08;
        well8x = well2x + 13.08;
      }
      if(Ydist1 == i)
      {
        well1y = i+10.08;
        well2y = well1y+13.08;
        well3y = well1y+13.08;
        well4y = well1y+13.08;
        well5y = well1y+13.08;
        well6y = well1y+13.08;
      }
      wellZHeight = 2.87; //mm
      wellVolume = 0.95; //ml
    }
 }

return well1x;
}