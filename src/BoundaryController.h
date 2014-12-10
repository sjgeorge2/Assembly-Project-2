//
//  BoundaryController.h
//  Helicopter
//
/*
	Arsh Chauhan, Samuel George, Lonny Strunk
	University Of Alaska Fairbanks
	CS-301 Fall 2014 Project 2
	Dr. Orion Sky Lawlor
 */

#ifndef Helicopter_BoundaryController_h
#define Helicopter_BoundaryController_h

#include "Boundary.h"
#include <list>
#include "heliController.h"

// BoundaryController class
// controls the upper and lower boundaries. updates and draws all boundaries, adds boundaries.
class BoundaryController
{
public:
    BoundaryController();
    bool update(heliController & heli);
    void draw();
    void addBoundary(float size);
    
    std::list <Boundary> _lowerBoundary;
    std::list <Boundary> _upperBoundary;
};

#endif
