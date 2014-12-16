/*	Author: Arsh Chauhan (achauhan@alaska.edu)
	University of Alaska. Fairbanks 
	Created for CS301 Project 2
	Last Update: 12/03/2014
*/

/* Released in the Public Domain*/

/* This file implements the animation for the obstacles  */


#include "pipeController.h"

int Pipecontroller::_iterations = 0; 

Pipecontroller::Pipecontroller()
{
    srand (static_cast <unsigned> (time(0)));
}


/* This implementation will clear the screen every 30 frames and will require other objects to redraw themselves that often*/
bool Pipecontroller::update(heliController & heli)
{
    for(std::list<Pipes>::iterator p = _obstacles.begin(); p != _obstacles.end(); p++)
    {
        //top-right heli point collision
        if ( ((heli.getTopY() > p->getTopY())  && (heli.getTopY() < p->getBottomY())) &&
            ((heli.getRightX() > p->getLeftX()) && (heli.getRightX() < p->getRightX())))
        {
            return true;
        }
        //top-left heli point collision
        else if ( ((heli.getTopY() > p->getTopY())  && (heli.getTopY() < p->getBottomY())) &&
                 ((heli.getLeftX() > p->getLeftX()) && (heli.getLeftX() < p->getRightX())))
        {
            return true;
        }
        //bottom-right heli point collision
        else if (((heli.getBottomY() > p->getTopY())  && (heli.getBottomY() < p->getBottomY())) &&
                 ((heli.getRightX() > p->getLeftX()) && (heli.getRightX() < p->getRightX())))
        {
            return true;
        }
        //bottom-left heli point collision
        else if (((heli.getBottomY() > p->getTopY())  && (heli.getBottomY() < p->getBottomY())) &&
                 ((heli.getLeftX() > p->getLeftX()) && (heli.getLeftX() < p->getRightX())))
        {
            return true;
        }
        
		if(p->getRightX() == 0.0f)
		{
		p = _obstacles.erase(p); // Delete the obstacle
		}
		p->update();
	}
    return false;
}

// Draw an obstacle 
void Pipecontroller::draw()
{	
	for(std::list<Pipes>::iterator p = _obstacles.begin(); p != _obstacles.end(); p++)
	{
		p->draw();
	}
}

//Add a new obstacle 
void Pipecontroller::addPipe(float leftX)
{
	_obstacles.push_back(Pipes(leftX));
}


