#include "velocity.h"



/*********************************************
 
 *********************************************/

Velocity::Velocity(float x, float y, float dx, float dy)
{
   //Position
   setX(x);
   setY(y);
   
   //Velocity
   setDx(dx);
   setDy(dy);
}

/*******************************************

 *******************************************/
Velocity::Velocity(Velocity & vectorOrig)
{
   //Copy position
   setX(vectorOrig.getX());
   setY(vectorOrig.getY());
   
   //Copy velocity
//  setDx(vectorOrig.getDx());
//  setDy(vectorOrig.getDy());
   setDx(vectorOrig.dx);
   setDy(vectorOrig.dy);

}

/***********************************************

 ***********************************************/
Velocity::~Velocity()
{
}

/************************************************

 ************************************************/
void Velocity::setDx(float dx)
{
   this->dx = dx;
   return;
}

/*************************************************

 *************************************************/
void Velocity::setDy(float dy)
{
   this->dy = dy;
   return;
}

/***************************************************

 ***************************************************/
void Velocity::advance()
{
   addX(dx);
   addY(dy);
   
   return;
}
