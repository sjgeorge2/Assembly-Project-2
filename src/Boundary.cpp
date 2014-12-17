//
//  Boundary.cpp
//  Helicopter
//
/*
	Arsh Chauhan, Samuel George, Lonny Strunk
	University Of Alaska Fairbanks
	CS-301 Fall 2014 Project 2
	Dr. Orion Sky Lawlor
 */

#include "Boundary.h"

// 2-variable Boundary constructor
// creates a boundary of given size, with a bool to indicate if it is upper or lower boundary
// Pre: size >= 0.0
// Post: _lowerUpper = lowerUpper;
//       _width = WIDTH;
//       _height = size;
//       _location is bottom right for lower and top right for upper boundaries
Boundary::Boundary(float size, bool lowerUpper)
{
    if (lowerUpper) {
        _lowerUpper = lowerUpper;
        _width = WIDTH;
        _height = size;
        _location = ci::Vec2f(640.0+WIDTH, 480.0-size);
    }
    else
    {
        _lowerUpper = lowerUpper;
        _width = WIDTH;
        _height = size;
        _location = ci::Vec2f(640.0+WIDTH, 0.0);
    }
}

// update member function
// every frame, the location of the block moves to the left by the width/10
// Pre: None
// Post: _location.x -= (int)(WIDTH/10.0)
void Boundary::update(float dt)
{
    _location.x -= 120 * dt;
}

// draw member function
// draws a green rectangle for either upper or lower border by _location variable
// Pre: None
// Post: rectangle is drawn to screen for either upper or lower border
void Boundary::draw()
{
    if (_lowerUpper) {
        ci::Rectf rect(getLeftX(), getTopY(), getRightX()+10, getBottomY());
        ci::gl::color(0.0, 1.0, 0.0); //green
        ci::gl::drawSolidRect(rect);
    }
    else
    {
        ci::Rectf rect(getLeftX(), getTopY(), getRightX()+10, getBottomY());
        ci::gl::color(0.0, 1.0, 0.0); //green
        ci::gl::drawSolidRect(rect);
    }
}

float Boundary::getLeftX()
{
    return _location.x;
}
float Boundary::getRightX()
{
    return _location.x + _width;
}
float Boundary::getTopY()
{
    return _location.y;
}
float Boundary::getBottomY()
{
    return _location.y + _height;
}
