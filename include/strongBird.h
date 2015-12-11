#ifndef strongBird_hpp
#define strongBird_hpp

#include <stdio.h>
#include "bird.h"
#include "uiDraw.h"

class StrongBird : public Bird
{
  // virtual void advance();
public:
   StrongBird();
   virtual ~StrongBird();
   virtual void restartBird();
   virtual void restart();
   virtual bool isOutside();
   virtual void setOutside();
   
   virtual void draw();
   virtual void score();

};

#endif /* strongBird_hpp */
