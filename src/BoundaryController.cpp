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
#include <iostream>
// update member function
// updates all boundaries and deletes boundaries from list that are off screen
// Pre: None
// Post: every boundary is updated or deleted
bool BoundaryController::update(heliController & heli, float dt, float speed)
{
    bool hit = false;
    
    // for all in lowerBoundary, update
    for( std::list<Boundary>::iterator p = _lowerBoundary.begin(); p != _lowerBoundary.end(); ++p)
    {
        //collision detection for lower boundary
        if( (heli.getBottomY() > p->getTopY()) &&
           (((heli.getLeftX() > p->getLeftX()) && (heli.getLeftX() < p->getRightX())) ||
            ((heli.getRightX() > p->getLeftX()) && (heli.getRightX() < p->getRightX()))))
        {
            hit = true;
        }

        if(p->_location.x <= -(p->WIDTH)) //if boundary is off screen
        {
            p = _lowerBoundary.erase(p);
        }
        if (p != _lowerBoundary.end())
        {
            p->update(dt, speed);
        }
    }
    // for all in upperBoundary, update
    for( std::list<Boundary>::iterator q = _upperBoundary.begin(); q != _upperBoundary.end(); ++q)
    {
        //collision detection for upper boundary
        if( (heli.getTopY() < q->getBottomY()) &&
           (((heli.getLeftX() > q->getLeftX()) && (heli.getLeftX() < q->getRightX())) ||
            ((heli.getRightX() > q->getLeftX()) && (heli.getRightX() < q->getRightX()))))
        {
            hit = true;
        }
        if(q->_location.x <= -(q->WIDTH)) //if boundary is off screen
        {
            q = _upperBoundary.erase(q);
        }
        if(q != _upperBoundary.end())
        {
            q->update(dt, speed);
        }
    }
    return hit;
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
void BoundaryController::addBoundary(float height, float width, int maxBoundaryHeight)
{
    Boundary lower(height, width, true);
    Boundary upper(maxBoundaryHeight-height, width, false);
    
    lower._location.x=((int)lower._location.x)/Boundary::WIDTH*Boundary::WIDTH;
    upper._location.x=((int)upper._location.x)/Boundary::WIDTH*Boundary::WIDTH;
    
    _lowerBoundary.push_back(lower); //true for lower boundary constructor
    _upperBoundary.push_back(upper);// false for upper boundary constructor
}

//when game resets, clear all boundary blocks
void BoundaryController::reset()
{
    _lowerBoundary.clear();
    _upperBoundary.clear();
}
