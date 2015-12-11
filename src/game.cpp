//TODO: FINAL OPTIMIZATION
// 1. Location of the bird starting point and out of bounds
// 2. Clean the Code get rid of comments
// 3. Delete bullet when out of bounds
// 4. add points board

/****************************************
 * The game of Skeet
 ****************************************/
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "bird.h"
#include "rifle.h"
#include "bullet.h"
#include "string"
#include "sacredBird.h"
#include "standardBird.h"
#include "strongBird.h"
#include <vector>


#include <iostream>
#include <string>
using namespace std;
#define speedOfBullet 8
#define speedOfBird 5
#define angleOfBullet(value) ((M_PI / 180) * (value))
#define angleOfBird(value) ((M_PI / 180) * (value))
#include <cmath>
#define Delay 70

#include <vector>
#define THE_AMOUNT_OF_BULLETS 1115

/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
private:
   Point topLeft;
   Point bottomRight;
   
   //add any objects or variables that are required
   Bird* activeBird;
   Bird* sacredBird;
   Bird* strongBird;
   Bird* standardBird;

   
   Rifle rifle;
   //The bullet Vector
   vector <Bullet*> bullets;
   
public:
   // create the game
   Game(Point tl, Point br) : topLeft(tl), bottomRight(br)
   {
      this->sacredBird = new SacredBird();
      this->strongBird = new StrongBird();
      this->standardBird = new StandardBird();
      this->activeBird = this->standardBird;
   }
   
   // handle user input
   void handleInput(const Interface & ui);
   
   // advance the game
   void advance();
   
   // draw stuff
   void draw(const Interface & ui);
   
   void someOtherRandomFunction();
   
   Point pointOfBullet;
   Point pointOfGun;
   Point pointOfBird;
   Point pointOfScore;
   
   int birdAngleX;
   int birdAngleY;
   
   int randomBird;
   int currentBird;
   
   Game();
   ~Game() //Destructor
   {
      if (sacredBird != 0) {
         delete sacredBird;
      }
      
      if (strongBird != 0) {
         delete strongBird;
      }
      
      if (standardBird != 0) {
         delete standardBird;
      }
   };
   
   int birdWasHit;
   
   void setup();
   void advance(const Interface *pUI);
   void draw();
   
   Bird* getActiveBird()
   {
      return activeBird;
   }
   void setActiveBird(Bird* act)
   {
      activeBird = act;
   }
   Bird* getStrong()
   {
      return strongBird;
   }
   Bird* getSacred()
   {
      return sacredBird;
   }
   Bird* getStandard()
   {
      return standardBird;
   }
};


/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game::advance(const Interface *pUI)
{
   //Moves bird forward
    this->activeBird->restartBird();
   
   //make antother is outside
      if (this->activeBird->isOutside())
      {
         this->activeBird->restart();
      }

   //Moves rifle left or right
   if (pUI->isLeft() || pUI->isRight())
   {
      rifle.changeTheDirection(pUI->isLeft(),pUI->isRight());
   }
   
   //Shoot the bullet
   if (pUI->isSpace())
   {
      //pushback on the vector and add an additional bullet object
      Bullet* bullet = new Bullet();
      bullets.push_back(bullet);
      bullet->fire(rifle);
   }
   return;
}

/***************************************
 * GAME :: input
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game::draw()
{
   //Draw rifle
   rifle.drawTheRifle();
   
   int activeX = activeBird->pointOfCurrentBird.getX();
   int activeY = activeBird->pointOfCurrentBird.getY();
   
   //Actually Draw the bullet
   for (vector<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); it++ )
   {
      Bullet* b = *it;
      b->draw();
      b->update();
      //update the location
      int bulX = b->getLocaiton().getX();
      int bulY = b->getLocaiton().getY();

      if ((bulX <= (activeX + 10)) && (bulX >= (activeX - 10)))
      {
         if ((bulY <= (activeY + 10)) && (bulY >= (activeY - 10))) {
             activeBird->setOutside();
             activeBird->score();
         }
      }
   }
   //Draw bird
   this->activeBird->draw();
   
   
   pointOfScore.setX(-290);
   pointOfScore.setY(290);
   drawNumber(pointOfScore, activeBird->scoreNumHits);
  
}

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void *p)
{
   Game *pGame = (Game *)p;

  //if the bird is out of bounds then get a new bird
  // if current point of bird is out of bound then switch bird
   if (pGame->getActiveBird()->isOutside() == true) {
      int randomBird = random(1, 4);
      
      if (randomBird == 1)
      {
         pGame->setActiveBird(pGame->getSacred());
      }else if (randomBird == 2)
      {
          pGame->setActiveBird(pGame->getStrong());
      }else if (randomBird == 3)
      {
          pGame->setActiveBird(pGame->getStandard());
      }else{
           pGame->setActiveBird(pGame->getStandard());
      }
   }
   
   pGame->advance(pUI);
   pGame->handleInput(*pUI);
   pGame->draw();
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * the game and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char ** argv)
{
   Point topLeft(-300, 300);
   Point bottomRight(300, -300);
   
   Interface ui(argc, argv, "Skeet", topLeft, bottomRight);
   Game game(topLeft, bottomRight);
   ui.run(callBack, &game);
   
   return 0;
}

