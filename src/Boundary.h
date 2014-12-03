//
//  Boundary.h
//  Helicopter
//
//  Created by Lonny Strunk on 12/1/14.
//
//

#ifndef __Helicopter__Boundary__
#define __Helicopter__Boundary__

#include "cinder/Vector.h"
#include "cinder/gl/gl.h"
#include "cinder/Rect.h"
#include "cinder/app/Window.h"

class Boundary
{
public:
    Boundary(float size, bool lowerUpper);
    void update();
    void draw();
    bool _lowerUpper;
    float _width;
    float _height;
    ci::Vec2f _location;
    
   static const int WIDTH = 20.0;
};

#endif /* defined(__Helicopter__Boundary__) */
