#ifndef BULLET_H
#define BULLET_H

#include "velocity.h"
#include "rifle.h"

class Bullet
{
public:
   Bullet();
   const bool isDead() const { return location.isDead(); };
   void fire(Rifle & rifle);
   Velocity getLocaiton()
   {
      return location;
   }
   void update();
   void draw();
   
private:
   bool living;
   Velocity location;

};

#endif
