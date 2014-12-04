
#ifndef PIPES_H
#define PIPES_H

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/Rand.h"   // For random number generator 
#include "cinder/Timer.h" // For timer functions 

//This class draws and controls the obstacles through which the helicopter has to move


using namespace ci;
using namespace ci::app;
using namespace std;

class Pipes
{
	/*// Cooirdinates for upper left hand corner of rectangle 
	float _leftX;
	float _leftY;

	//Coordinates for Lower Right Hand Corner of rectangle
	float _rightX;
	float _rightY;*/

	 Rectf _currentPipe; // The current Pipe 
	 ci::Vec2f _position; // vector represeting upper left corner 

	 
	 static int _count; //counter since last pipe drawn
	 static float _WIDTH; 
	 static float _HEIGHT; 
	 
/*	Author: Arsh Chauhan (achauhan@alaska.edu)
	University of Alaska. Fairbanks 
	Created for CS301 Project 2
	Last Update: 12/03/2014
*/

/* Released in the Public Domain*/

/* This class defines the properties of the obstacles */
	


public:
	Pipes(float);
	void draw();
	void update();
	
	int getcount();
	int incrementcount();
	void setleftX(int);
	float getrightX();
	float getWIDTH();


/* To Do: Move the Pipes at some velocity.
		  Leave Space between pipes
*/
};


#endif 



