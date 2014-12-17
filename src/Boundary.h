//
//  Boundary.h
//  Helicopter
//
/*
	Arsh Chauhan, Samuel George, Lonny Strunk
	University Of Alaska Fairbanks
	CS-301 Fall 2014 Project 2
	Dr. Orion Sky Lawlor
 */

#ifndef __Helicopter__Boundary__
#define __Helicopter__Boundary__

#include "cinder/Vector.h"
#include "cinder/gl/gl.h"
#include "cinder/Rect.h"
#include "cinder/app/Window.h"

// Boundary class
// holds information for individual blocks of the border upper and lower for
// the BoundaryController class
class Boundary
{
public:
    Boundary(float size, bool lowerUpper);
    void update(float dt);
    void draw();
    bool _lowerUpper;
    float _width;
    float _height;
    ci::Vec2f _location;
    
    float getLeftX();
    float getRightX();
    float getTopY();
    float getBottomY();
    
   static const int WIDTH = 20.0;
};

#endif /* defined(__Helicopter__Boundary__) */
