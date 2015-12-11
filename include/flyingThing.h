#ifndef flyingThing_hpp
#define flyingThing_hpp

#include <stdio.h>
#include "point.h"
#include "uiDraw.h"



class flyingThing
{
public:
   
   Point center;
   
   bool live;
   flyingThing()
   {
      live = false;
   }

   Point getPoint() { return center;}
   void setPoint(Point p) {center = p;}
   
   virtual void draw() = 0;

};

#endif /* flyingThing_hpp */