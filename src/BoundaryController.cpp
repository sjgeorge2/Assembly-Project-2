//
//  BoundaryController.cpp
//  Helicopter
//
//  Created by Lonny Strunk on 12/1/14.
//
//

#include "BoundaryController.h"


BoundaryController::BoundaryController()
{
    
}

void BoundaryController::update()
{
    for( std::list<Boundary>::iterator p = _lowerBoundary.begin(); p != _lowerBoundary.end(); ++p)
    {
        if(p->_location.x <= -(p->WIDTH))
        {
           // _lowerBoundary.erase(p); //std::out_of_bounds on windows 
        }
        p->update();
    }
    for( std::list<Boundary>::iterator q = _upperBoundary.begin(); q != _upperBoundary.end(); ++q)
    {
        if(q->_location.x <= -(q->WIDTH))
        {
           //_upperBoundary.erase(q); //std::out_of_bounds on windows  
        }
        q->update();
    }
}

void BoundaryController::draw()
{
    for( std::list<Boundary>::iterator p = _lowerBoundary.begin(); p != _lowerBoundary.end(); ++p)
    {
        p->draw();
    }
    for( std::list<Boundary>::iterator q = _upperBoundary.begin(); q != _upperBoundary.end(); ++q)
    {
        q->draw();
    }
}

void BoundaryController::addBoundary(float size)
{
    _lowerBoundary.push_back(Boundary(size, true));
    _upperBoundary.push_back(Boundary(100-size, false));
}
