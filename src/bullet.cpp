#include <cmath>
#include "bullet.h"
#include "uiDraw.h"

#define SPEED 10
#define deg2rad(value) ((M_PI / 180) * (value))

/*******************************************************
 * construct the bullet
 *******************************************************/
Bullet::Bullet()
{
   //is the bullet out of bounds
   location.setCheck(true);
}

/*************************************************************
 *  This function will print the bullet to the screen at its position
 *************************************************************/
void Bullet::draw()
{
   
   //put on a new bullet
   drawDot(Point(location.getX(),location.getY()));
   
}

/************************************************************
 * Move the bullet if its not dead
 ************************************************************/
void Bullet::update()
{
   //ADVANCE THE BULLET
   location.advance();
}


/*********************************************************
 *  This function will fire a bullet from the rifle
 **********************************************************/
void Bullet::fire(Rifle & rifle)
{

   //Puts bullet at rifle
   location.setX(300);
   location.setY(-300);
   
   //Fires at the angle of the rifle
   location.setDx(-cos(deg2rad((float)rifle.getAngle())) * SPEED);
   location.setDy( sin(deg2rad((float)rifle.getAngle())) * SPEED);
   location.setDead(true);   //This will mean the the bullet is "not loaded"
   
   drawDot(location);
}





