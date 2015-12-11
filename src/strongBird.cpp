#include <stdio.h>
#include "strongBird.h"


/***************************************************************************
 * Constructor
 ***************************************************************************/
StrongBird::StrongBird()
{
   //Reset position
   pointOfCurrentBird.setX(-300);//Left side
   
   pointOfCurrentBird.setY(random(-300, 300));   //Random
   
   //Set dx, dy
   pointOfCurrentBird.setDx(random(3.0, 6.0));
   if (pointOfCurrentBird.getY() > 0)         //Upper half of the screen
      pointOfCurrentBird.setDy(random(-4.0, 0.0));
   else                             //Lower half of the screen
      pointOfCurrentBird.setDy(random(0.0, 4.0));
}
/***************************************************************************
 * Destructor
 ***************************************************************************/
StrongBird::~StrongBird()
{
   
}

/***********************************************************************
 * Moves the bird by frame
 ***********************************************************************/
void StrongBird::restartBird()
{
   //YOU NEED TO GET THE POINT FROM THE pointOfCurrentBird Velocity
   if (pointOfCurrentBird.getX() == 0) //Default is zero; make a new bird!
   {
      restart();
   }
   //move it forward
   pointOfCurrentBird.advance();
   
}

/***************************************************************************
 * this will restart the bird back at the start on the left side
 ****************************************************************************/
void StrongBird::restart()
{
   //Reset position
   pointOfCurrentBird.setX(-300);                //Left side
   pointOfCurrentBird.setY(random(-300, 300));   //Random
   
   //Set dx, dy
   pointOfCurrentBird.setDx(random(3.0, 6.0));
   if (pointOfCurrentBird.getY() > 0)         //Upper half of the screen
      pointOfCurrentBird.setDy(random(-4.0, 0.0));
   else                             //Lower half of the screen
      pointOfCurrentBird.setDy(random(0.0, 4.0));
   
}

/***********************************************************************
 *
 ***********************************************************************/
bool StrongBird::isOutside()
{
   if (((pointOfCurrentBird.getX() > 300))) {
      return true;
   }
   if ((pointOfCurrentBird.getY() > 300)) {
      return true;
   }
   if ((pointOfCurrentBird.getY() < -300)) {
      return true;
   }
   
   //THIS WILL LET US KNOW WHEN THE POINT IS OUT OF BOUNDS CHANGE THE NAME OF THE POINT TO BETTER REFLECT WHAT IT IS DOING
   return false;
}

/***********************************************************************
 *
 ***********************************************************************/
void StrongBird::draw()
{
        drawToughBird(pointOfCurrentBird, 15, 4);
}


/***************************************************************************
 * setOutside
 ***************************************************************************/
void StrongBird::setOutside()
{
   
   pointOfCurrentBird.setX(500);
   
}

/***************************************************************************
 * handle the score
 ***************************************************************************/
void StrongBird::score()
{
   
   scoreNumHits++;
}