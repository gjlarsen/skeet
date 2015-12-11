#include "rifle.h"
#include "uiDraw.h"
#include "point.h"
#define HEIGHT_OF_RIFLE 79
#define WIDTH_OF_RIFLE 15

/*************************************************
 * This is the defaut constructor for rifle
 *************************************************/
Rifle::Rifle()
{
   angleOfBarrel = 45;
   
   changeTheDirection(0, 0);
}


/****************************************************
 * This funtion will put the rifle on the screen
 ****************************************************/
void Rifle::drawTheRifle()
{
   //This will be a point for the rifle
   Point pt = Point();
   
   pt.setX(300);
   pt.setY(-300);
   //This is going to draw the rectangle
   drawRect(pt, WIDTH_OF_RIFLE, HEIGHT_OF_RIFLE, 90 - this->angleOfBarrel);
 
   return;
}

/**************************************************
 * This funtion will move the rifle
 ***************************************************/
void Rifle::changeTheDirection(int leftMove, int rightMove)
{
   if (leftMove)
      angleOfBarrel -= leftMove;
   if (rightMove)
      angleOfBarrel += rightMove;
   if (angleOfBarrel < 0)
      angleOfBarrel = 0;
   if (angleOfBarrel > 90)
      angleOfBarrel = 90;
   
}


