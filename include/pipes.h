/*	Author: Arsh Chauhan (achauhan@alaska.edu)
	University of Alaska. Fairbanks 
	Created for CS301 Project 2
	Last Update: 12/03/2014
*/

/* Released in the Public Domain*/

/* This class defines the properties of the obstacles */
	


#ifndef PIPES_H
#define PIPES_H

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/Rand.h"   // For random number generator 
#include "cinder/Timer.h" // For timer functions 

/* Cinder Namepsaces */
using namespace ci;
using namespace ci::app;



class Pipes
{
	 Rectf _currentPipe; // The current Pipe 
	 ci::Vec2f _position; // vector represeting upper left corner 

	 /*Pipecontroller implements a std::list of Pipes*/
	 static float _WIDTH; 
	 static float _HEIGHT; 

public:
	Pipes(float);
	void draw();
	void update(float dt);
	
	void setleftX(int);
	
    float getLeftX();
    float getRightX();
    float getTopY();
    float getBottomY();
    
	float getWIDTH();

};


#endif 



