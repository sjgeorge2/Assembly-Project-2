/*This code is released in the Public Domain
 on an as is basis and does not come with any guarantee 
*/ 

/*	
	Arsh Chauhan, Samuel George, Lonny Strunk
	University Of Alaska, Fairbanks 
	CS-301 Fall 2014 Project 2 
	Dr. Orion Sky Lawlor 
*/

/* 
	This is our version of the classic "Helicopter" game with some inline assembly


*/


//Cinder Include Files
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/Rand.h"

//Our Header Files 
#include "../include/pipes.h"
#include "pipeController.h"
#include "BoundaryController.h"
#include "heliController.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class HelicopterCinderApp : public AppNative {

	
	Pipecontroller  _obstacle;
	BoundaryController _BoundaryController;
	heliController _Helicopter;
	

  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void drawpipe();
	int size;
    bool upDown;
    int incrementSize;
	
    
};


	//Default Screen is 640x780
void HelicopterCinderApp::setup()
{
	size = 0;
    upDown = true;
    incrementSize = 5;
}

void HelicopterCinderApp::mouseDown( MouseEvent event )
{
//  when the left mouse is clicked we change direction
	if (event.isLeft())
	{
		_Helicopter.setisfalling(false);
		_Helicopter.changeDirection(); 
	}					
}

void HelicopterCinderApp::update()
{
// call this function every so frames to continue drawing the borders //
	if (app::getElapsedFrames()%10 == 9)
    {
        _BoundaryController.addBoundary(size);
        if (size == incrementSize * 15)
            upDown = false;
        if (size == 0)
            upDown = true;
        if(upDown)
            size+= incrementSize;
        else
            size-= incrementSize;
    }
	_BoundaryController.update();
	
// call this function every so frames to check if it's time to create another obstacle //
	if(getElapsedFrames()%30 == 0)
	{
		_obstacle.update();
	}

// check if left mouse is still down, if not, change direction 	
	if (!event.isLeftDown())
	{
		_Helicopter.setisfalling(true);
		_Helicopter.changeDirection();
	}
// change the position of the helicopter every other frame -- 30 times in a second //
	if (app::getElapsedFrames()%2 == 1) 
	_Helicopter.updatePosition();
}

void HelicopterCinderApp::draw()
{
	
	_BoundaryController.draw();
	_obstacle.draw();
	_Helicopter.draw();
	
}



CINDER_APP_NATIVE( HelicopterCinderApp, RendererGl )
