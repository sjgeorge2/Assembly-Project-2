//
//  BoundaryController.cpp
//  Helicopter
//
/*
	Arsh Chauhan, Samuel George, Lonny Strunk
	University Of Alaska Fairbanks
	CS-301 Fall 2014 Project 2
	Dr. Orion Sky Lawlor
 */

#include "BoundaryController.h"

// Default Constructor
BoundaryController::BoundaryController()
{
    
}

// update member function
// updates all boundaries and deletes boundaries from list that are off screen
// Pre: None
// Post: every boundary is updated or deleted
bool BoundaryController::update(heliController & heli)
{
    // for all in lowerBoundary, update
    for( std::list<Boundary>::iterator p = _lowerBoundary.begin(); p != _lowerBoundary.end(); ++p)
    {
        if( (heli.getBottomY() > p->getTopY()) &&
           (((heli.getLeftX() > p->getLeftX()) && (heli.getLeftX() < p->getRightX())) ||
            ((heli.getRightX() > p->getLeftX()) && (heli.getRightX() < p->getRightX()))))
        {
            return true;
        }

        if(p->_location.x <= -(p->WIDTH))
        {
           p = _lowerBoundary.erase(p); //std::out_of_bounds on windows
        }
        p->update();
            }
    // for all in upperBoundary, update
    for( std::list<Boundary>::iterator q = _upperBoundary.begin(); q != _upperBoundary.end(); ++q)
    {
        if( (heli.getTopY() < q->getBottomY()) &&
           (((heli.getLeftX() > q->getLeftX()) && (heli.getLeftX() < q->getRightX())) ||
            ((heli.getRightX() > q->getLeftX()) && (heli.getRightX() < q->getRightX()))))
        {
            return true;
        }
        if(q->_location.x <= -(q->WIDTH))
        {
           q = _upperBoundary.erase(q); //std::out_of_bounds on windows
        }
        q->update();
    }
    return false;
}

// draw member function
// draws all boundaries
// Pre: None
// Post: all boundaries are drawn
void BoundaryController::draw()
{
    // for all in lowerBoundary, draw
    for( std::list<Boundary>::iterator p = _lowerBoundary.begin(); p != _lowerBoundary.end(); ++p)
    {
        p->draw();
    }
    // for all in uppperBoundary, draw
    for( std::list<Boundary>::iterator q = _upperBoundary.begin(); q != _upperBoundary.end(); ++q)
    {
        q->draw();
    }
}

// addBoundary member function
// adds a lower and upper boundary to their respective lists
// Pre: size >= 0.0
// Post: lowerBoundary of given size is added
//       upperBoundary of 100-size is added
void BoundaryController::addBoundary(float size)
{
    _lowerBoundary.push_back(Boundary(size, true)); //true for lower boundary constructor
    _upperBoundary.push_back(Boundary(100-size, false));// false for upper boundary constructor
}
