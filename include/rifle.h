#ifndef RIFLE_H
#define RIFLE_H

#include "point.h"

class Rifle
{
private:
   int angleOfBarrel;
   
public:
   
   void changeTheDirection(int left, int right);
   void drawTheRifle();
   const int getAngle() const { return angleOfBarrel; };
   //This is the Constructor
   Rifle();
};

#endif
