//
//  BoundaryController.h
//  Helicopter
//
//  Created by Lonny Strunk on 12/1/14.
//
//

#ifndef Helicopter_BoundaryController_h
#define Helicopter_BoundaryController_h

#include "Boundary.h"
#include <list>

class BoundaryController
{
public:
    BoundaryController();
    void update();
    void draw();
    void addBoundary(float size);
    
    std::list <Boundary> _lowerBoundary;
    std::list <Boundary> _upperBoundary;
};

#endif
