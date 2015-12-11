#ifndef sacredBird_hpp
#define sacredBird_hpp

#include <stdio.h>
#include "bird.h"
#include "uiDraw.h"

class SacredBird : public Bird
{
public:
   
   SacredBird();
   virtual ~SacredBird();
   virtual void restartBird();
   virtual void restart();
   virtual bool isOutside();
   virtual void setOutside();
   
   virtual void draw();
   virtual void score();

};

#endif /* sacredBird_hpp */
