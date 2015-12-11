/***********************************************************************
 * Header File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen, including
 *    the location and the bounds.
 ************************************************************************/


#ifndef POINT_H
#define POINT_H

#include <iostream>

/*********************************************
 * POINT
 * A single position.
 *********************************************/
class Point
{
public:
   // constructors
   Point()            : x(0.0), y(0.0), check(false), dead(false) {}
   Point(bool check)  : x(0.0), y(0.0), check(check), dead(false) {}
   Point(float x, float y);
   Point(const Point & point) { *this = point; }
   
   // getters
   float getXMin()    const { return xMin;           }
   float getXMax()    const { return xMax;           }
   float getYMin()    const { return yMin;           }
   float getYMax()    const { return yMax;           }
   float getX()       const { return x;              }
   float getY()       const { return y;              }
   bool  getCheck()   const { return check;          }
   bool  isDead()     const { return dead;           }
   
   
   // setters
   void setCheck(bool f)    { check = f;             }
   void setDead(bool d)     { dead  = d;             }
   void setX(float x);
   void setY(float y);
   void addX(float dx)      { setX(getX() + dx);     }
   void addY(float dy)      { setY(getY() + dy);     }
  
   //const Point & operator = (const Point & rhs);
   
private:
   bool  check;
   bool  dead;
   float x;           // horizontal position
   float y;           // vertical position
   
   float xMin; float xMax; float yMin; float yMax;
   
   
   
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Point & pt);
std::istream & operator >> (std::istream & in,        Point & pt);

#endif // POINT_H
