#ifndef BIRD_H
#define BIRD_H
#include "point.h"
#include "velocity.h"

#define BIRD_SIZE 10


class Bird
{
public:
   
   int scoreNumHits;
   
   Velocity pointOfCurrentBird;

   Bird(); //Constructor
   virtual ~Bird();
   virtual void restartBird();
   virtual void draw();
   virtual void restart();
   virtual bool isOutside();
   virtual void setOutside();
   virtual void score();
   
};

#endif