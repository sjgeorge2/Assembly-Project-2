/*	Author: Arsh Chauhan (achauhan@alaska.edu)
	University of Alaska. Fairbanks 
	Created for CS301 Project 2
	Last Update: 12/03/2014
*/

/* Released in the Public Domain*/

/* This file implements the properties of the obstacles */

#include "pipes.h"
#include <cstdlib>
using std::rand;
#include <ctime>
using std::time;


//Initialize Static members 

float Pipes::_WIDTH = 40 ; // Set fixed Width for the obstacles
float Pipes::_HEIGHT =100; // Set fixed Height for the obstacles 




Pipes::Pipes(float leftX)
{
    float randNum=rand()%480;
    
	_position.x = leftX; // top left x-coordinate is passed by pipeController's addPipe
    _position.y = randNum;
}


// This should move the pipes at some velocity 
void Pipes::update(float dt)
{
	_position.x-= 120 * dt; // Move rectangle by _WIDTH
}

//Draw the Pipe 
void Pipes::draw()
{
	_currentPipe.set(getLeftX(), getTopY(), getRightX(), getBottomY());
	gl::color(0.0,1.0,0.0); // Green 
	gl::drawSolidRect(_currentPipe); 
}

// returns the right top corner's x-coordinate
float Pipes::getRightX()
{
	return (_position.x+_WIDTH);
}
float Pipes::getLeftX()
{
    return (_position.x);
}
float Pipes::getTopY()
{
    return (_position.y);
}
float Pipes::getBottomY()
{
    return (_position.y+_HEIGHT);
}


float Pipes::getWIDTH()
{
	return _WIDTH;
}

//Sets the top-left corner's x-coordinate 
void Pipes::setleftX(int leftX)
{
	_position.x = leftX;
}




