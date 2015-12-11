
#include "bird.h"
#include "uiDraw.h"

/***********************************************************************
 * Start the bird at a given point
 ***********************************************************************/
Bird::Bird()
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

/***********************************************************************
 * Moves the bird every frame
 ***********************************************************************/
void Bird::restartBird()
{
   //YOU NEED TO GET THE POINT FROM THE pointOfCurrentBird Velocity
   if (pointOfCurrentBird.getX() == 0) //Default is zero; make a new bird!
   {
      restart();
   }
   //move it forward
   pointOfCurrentBird.advance();
   
}

/*************************************************************************
 * This will Print the bird to the screen at its position
 *************************************************************************/
void Bird::draw()
{
   //Do some Initialization here NOT SURE IF I DID THIS RIGHT
   int x = pointOfCurrentBird.getX();
   int y = pointOfCurrentBird.getY();

}

/***************************************************************************
* this will restart the bird back at the start on the left side
 ****************************************************************************/
void Bird::restart()
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

/***************************************************************************
 * This will check to see if the bird is outside of the screen
 ***************************************************************************/
bool Bird::isOutside()
{

   return false;
}

/***************************************************************************
 * Destructor
 ***************************************************************************/
Bird::~Bird()
{
   
}

/***************************************************************************
 * setOutside
 ***************************************************************************/
void Bird::setOutside()
{
   
   pointOfCurrentBird.setX(500);
   
}

/***************************************************************************
 * handle the score
 ***************************************************************************/
void Bird::score()
{
   scoreNumHits = 0;
   scoreNumHits++;
}
