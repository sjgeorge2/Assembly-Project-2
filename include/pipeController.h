/*	Author: Arsh Chauhan (achauhan@alaska.edu)
	University of Alaska. Fairbanks 
	Created for CS301 Project 2
	Last Update: 12/03/2014
*/

/* Released in the Public Domain*/

/* This class handles the animation for the obstacles  */
	



#ifndef PIPECONTROLLER_H
#define PIPECONTROLLER_H



#include "pipes.h"
#include "heliController.h"

#include <list>

class Pipecontroller
{
	static int _iterations;
	std::list <Pipes> _obstacles; 
 
public:
	Pipecontroller();
	bool update(heliController & heli, float dt, float speed);
	void draw();
	void addPipe(float);
    void reset();
};

#endif