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
//       _width = width;
//       _height = height;
//       _location is bottom right for lower and top right for upper boundaries
Boundary::Boundary(float height,float width, bool lowerUpper)
{
    if (lowerUpper) {
        _lowerUpper = lowerUpper;
        _width = width;
        _height = height;
        _location = ci::Vec2f(640.0+WIDTH, 480.0-height);
    }
    else
    {
        _lowerUpper = lowerUpper;
        _width = width;
        _height = height;
        _location = ci::Vec2f(640.0+WIDTH, 0.0);
    }
}

// update member function
// Pre: None
// Post: _location.x -= speed * dt
void Boundary::update(float dt, float speed)
{
    _location.x -= speed * dt;
}

// draw member function
// draws a green rectangle for either upper or lower border by _location variable
// Pre: None
// Post: rectangle is drawn to screen for either upper or lower border
void Boundary::draw()
{
    if (_lowerUpper) //lower
    {
        ci::Rectf rect(getLeftX(), getTopY(), getRightX()+10, getBottomY());
        ci::gl::color(0.0, 1.0, 0.0); //green
        ci::gl::drawSolidRect(rect);
    }
    else //upper
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
