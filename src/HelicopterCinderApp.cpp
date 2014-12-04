/*This code is released in the Public Domain
 on an as is basis and does not come with any guarantee 
*/ 

/*	
	Arsh Chauhan, Samuel George, Lonny Strunk
	University Of Alaska, Fairbanks 
	CS-301 Fall 2014 Project 2 
	Dr. Orion Sky Lawlor 
*/

/* This is our version of the classic "Helicopter" game with some inline assembly*/


//Cinder Include Files
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/Rand.h"

//Our Header Files 
//#include "../include/pipes.h"
#include "../include/pipeController.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HelicopterCinderApp : public AppNative {

	
	Pipecontroller  _obstacle;

  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void drawpipe();
};


	//Default Screen is 640x780
void HelicopterCinderApp::setup()
{
	
	


}

void HelicopterCinderApp::mouseDown( MouseEvent event )
{
}

void HelicopterCinderApp::update()
{
	if(getElapsedFrames()%30 == 0)
	{
		_obstacle.update();
	}
}

void HelicopterCinderApp::draw()
{
	
	_obstacle.draw();
	
}



CINDER_APP_NATIVE( HelicopterCinderApp, RendererGl )
