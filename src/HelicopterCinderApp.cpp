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
#include "scoringEngine.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class HelicopterCinderApp : public AppNative {

	
	Pipecontroller  _obstacle;
	BoundaryController _BoundaryController;
	heliController _Helicopter;
    Scoringengine _scoringEngine;

  public:
    void prepareSettings(Settings *settings);
	void setup();
	void mouseDown( MouseEvent event );
    void mouseUp( MouseEvent event );
	void update();
	void draw();
	void drawpipe();
	
	int size;
    bool upDown;
    int incrementSize;
	
    bool hit;
};

void HelicopterCinderApp::prepareSettings( Settings *settings ){
    settings->setWindowSize( 640, 480 );
    settings->setFrameRate( 60.0f );
}

	//Default Screen is 640x480
void HelicopterCinderApp::setup()
{
	size = 0;
    upDown = true;
    incrementSize = 5;
    hit = false;
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

void HelicopterCinderApp::mouseUp( MouseEvent event )
{
    _Helicopter.setisfalling(true);
    _Helicopter.changeDirection();
}



void HelicopterCinderApp::update()
{
    if(!hit)
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
        hit = _BoundaryController.update(_Helicopter);
    }
    if(!hit)
    {
        // call this function every so frames to check if it's time to create another obstacle //
        if(getElapsedFrames()%200 == 0)
        {
            _obstacle.addPipe(640.0);
        }
        hit = _obstacle.update(_Helicopter);

        // change the position of the helicopter every other frame -- 30 times in a second //
        //if (app::getElapsedFrames()%2 == 1)
        _Helicopter.updatePosition();
        
       _scoringEngine.update();
    }

	
}

void HelicopterCinderApp::draw()
{
    gl::clear();
	_BoundaryController.draw();
	_obstacle.draw();
	_Helicopter.draw();
    _scoringEngine.draw();
}



CINDER_APP_NATIVE( HelicopterCinderApp, RendererGl )
