/*	Author: Arsh Chauhan (achauhan@alaska.edu)
	University of Alaska. Fairbanks 
	Created for CS301 Project 2
	Last Update: 12/03/2014
*/

/* Released in the Public Domain*/

/* This class defines the properties of the obstacles */
#include "pipes.h"


//Initialize Static members 
//Rectf Pipes::_currentPipe(0,0,0,0);  
float Pipes::_WIDTH = 40 ;
float Pipes::_HEIGHT =100;
int Pipes::_count=0; 



Pipes::Pipes(float leftX)
{
	_position.x = leftX;
	_position.y = Rand::randFloat(0.0f,780.0f);
	//_currentPipe.set(_position.x,_position.y,_position.x+_WIDTH,_position.y+_HEIGHT);
		
}


// This should move the pipes at some velocity 
void Pipes::update()
{
	_position.x = _position.x-_WIDTH; // Move rectangle by _WIDTH 
	
	/*_rightX = _leftX+_WIDTH; //Upper Left corner x-coordinate 
	_leftY = Rand::randFloat(0.0f,780.0f);
	_rightY=_leftY+_HEIGHT;  //Lower Right corner y-coordinate		
	_currentPipe.set(_leftX,_leftY,_rightX,_rightY);*/
}

//Draw the Pipe 
//FixMe: Pipes are not constant height 
void Pipes::draw()
{
	_currentPipe.set(_position.x,_position.y,_position.x+_WIDTH,_position.y+_HEIGHT);
	gl::color(0.0,1.0,0.0);
	gl::drawSolidRect(_currentPipe); 
}


// Return _count. Makes it accessible to the outside world 
int Pipes::getcount()
{
	return _count;
}


float Pipes::getrightX()
{
	return (_position.x+_WIDTH);
}


float Pipes::getWIDTH()
{
	return _WIDTH;
}

void Pipes::setleftX(int leftX)
{
	_position.x = leftX;
}


int Pipes::incrementcount()
{
	_count=_count+1;
	return _count;
}

