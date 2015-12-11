#ifndef standardBird_hpp
#define standardBird_hpp

#include <stdio.h>
#include "flyingThing.h"
#include "bird.h"


class StandardBird : public Bird
{
public:
   
   StandardBird();
   virtual ~StandardBird();
   virtual void restartBird();
   virtual void restart();
   virtual bool isOutside();
   virtual void draw();
   virtual void setOutside();
   virtual void score();
};

#endif /* standardBird_hpp */
