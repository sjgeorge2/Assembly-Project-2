//
//  Boundary.cpp
//  Helicopter
//
//  Created by Lonny Strunk on 12/1/14.
//
//

#include "Boundary.h"

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

void Boundary::update()
{
    _location.x -= (int)(WIDTH/10.0);
}

void Boundary::draw()
{
    if (_lowerUpper) {
        ci::Rectf rect(_location.x, _location.y, _location.x+ _width, _location.y+_height);
        ci::gl::color(0.0, 1.0, 0.0); //green
        ci::gl::drawSolidRect(rect);
    }
    else
    {
        ci::Rectf rect(_location.x, _location.y, _location.x+ _width, _location.y+_height);
        ci::gl::color(0.0, 1.0, 0.0); //green
        ci::gl::drawSolidRect(rect);
    }
}
