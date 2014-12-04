/*	Author: Arsh Chauhan (achauhan@alaska.edu)
	University of Alaska. Fairbanks 
	Created for CS301 Project 2
	Last Update: 12/03/2014
*/

/* Released in the Public Domain*/

/* This file implements the animation for the obstacles  */


#include "pipeController.h"

int Pipecontroller::_iterations = 0; 

Pipecontroller::Pipecontroller(){}


/* This implementation will clear the screen every 30 frames and will require other objects to redraw themselves that often*/
void Pipecontroller::update()
{
	/* Screen width is 640, so 4 iterations produces 4 equidistant obstacles */
	if(_iterations<4)
	{
		addPipe(120+(160*_iterations));// _leftX for Pipe is 160-WIDTH+(160*_iterations))
		++_iterations;
	}
	else
	{
		_iterations = 0; // reset iterations for every 4 iterations
	}
	

	for(std::list<Pipes>::iterator p = _obstacles.begin(); p != _obstacles.end(); p++)
	{
		gl::clear(); // trying to get it to delete triangles using lists but getting weird position values 
		/* if rightX < 0, the obstacle has left the screen*/
		
		/*if(p->getrightX() == 0.0f)
		{
		 _obstacles.erase(p); // Delete the obstacle 
		} */
		
		p->update();
	}
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


