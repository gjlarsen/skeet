#ifndef VECTOR_H
#define VECTOR_H

#include "point.h"
#include <iostream>

/*****************************************************
 * Direction and speed for a given Point
 *****************************************************/
class Velocity : public Point
{
private:
   float dx;
   float dy;
   
public:
   const float getDx() const { return dx; }
   const float getDy() const { return dy; }
   const float getMag() const;
   const float getAngle() const;
   void setDx(float dx);
   void setDy(float dy);
   void advance();
   Velocity(float x = 0, float y = 0, float dx = 0, float dy = 0);
   Velocity(Velocity & vectorOrig);
   ~Velocity();
};

#endif /* velocity */
