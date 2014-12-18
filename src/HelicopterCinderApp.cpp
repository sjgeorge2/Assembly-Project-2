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
	This is our version of the classic "Helicopter" game
 
    Controls
    Spacebar/Mouse button/Up Arrow - press to go up, let go to go down
    Return - Reset Game
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
#include "../include/scoringEngine.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class HelicopterCinderApp : public AppNative
{
	Pipecontroller  _obstacle;
	BoundaryController _BoundaryController;
	heliController _Helicopter;
    Scoringengine _scoringEngine;

public:
    void prepareSettings(Settings *settings);
	void setup();
	void mouseDown( MouseEvent event );
    void mouseUp( MouseEvent event );
    void keyDown( KeyEvent event);
    void keyUp( KeyEvent event);
	void update();
	void draw();
	void drawpipe();
	void render();
	int size;
    bool upDown;
    int incrementSize;
    float dt;
    float olddt;
    bool hit;
    float someVariable;
    float startY, endY, YchangeRate;
    int gameState;
    float width, speed;
    int maxBoundaryHeight;
};

void HelicopterCinderApp::prepareSettings( Settings *settings )
{
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
    olddt = getElapsedSeconds();
    dt = 0;
    someVariable = 0;
    startY = endY = 10;
    YchangeRate = 100;
    gameState = 0;
    width = 20.0;
    speed = 120.0;
    maxBoundaryHeight = 100;
}

void HelicopterCinderApp::mouseDown( MouseEvent event )
{
//  when the left mouse is clicked we change direction
    if (event.isLeft())
    {
        gameState = 1;
		_Helicopter.setisfalling(false);
		_Helicopter.changeDirection();
	}
}

void HelicopterCinderApp::mouseUp( MouseEvent event )
{
    if (gameState == 1)
    {
        _Helicopter.setisfalling(true);
        _Helicopter.changeDirection();
    }
    
}

void HelicopterCinderApp::keyDown( KeyEvent event )
{
    //Return Key reset game
    if( event.getCode() == KeyEvent::KEY_RETURN)
    {
        gameState = 0;
        hit = false;
        width = 20.0;
        speed = 120.0;
        maxBoundaryHeight = 100;
        _scoringEngine.reset();
		_Helicopter.reset();
        _BoundaryController.reset();
        _obstacle.reset();
        
    }
    //Space bar/Up arrow - Helicopter goes up
    if (event.getCode() == KeyEvent::KEY_SPACE || event.getCode() == KeyEvent::KEY_UP)
    {
        gameState = 1;
        _Helicopter.setisfalling(false);
        _Helicopter.changeDirection();
    }
}
//When Spacebar is not pressed, helicopter goes down
void HelicopterCinderApp::keyUp( KeyEvent event ) {
    if (gameState == 1)
    {
        _Helicopter.setisfalling(true);
        _Helicopter.changeDirection();
    }
}

void HelicopterCinderApp::update()
{
    //to calculate dt
    float currentTime = getElapsedSeconds();
    dt = currentTime - olddt;
    olddt = currentTime;
    someVariable += 240 *dt;
    
    // beginning state - before click
    if (gameState == 0) {
		_Helicopter.updatePosition(dt);
    }
    // Level running state
    else if (gameState == 1)
    {
        //if not collided

        if(!hit)
        {
            // The following code is to make the boundaries more random
            // with help from Mike Moss
            while (someVariable >= Boundary::WIDTH)
            {
                _BoundaryController.addBoundary(startY, width, maxBoundaryHeight);
                
                someVariable -= 20;
                YchangeRate -=20;
                if (startY <= endY - 10) {
                    startY += incrementSize;
                }
                else if (startY >= endY + 10)
                {
                    startY -= incrementSize;
                }
            }
            
            int changeInSlope=rand()% (maxBoundaryHeight/2); //creates
            if ( YchangeRate <= 0)
            {
                YchangeRate = 320;
                startY = endY;
                speed += 5;
                width += 0.5;
                do {
                endY = rand()% maxBoundaryHeight;
                }while (abs(endY-startY)<changeInSlope); //
                
            }
            hit = _BoundaryController.update(_Helicopter, dt, speed);
        }
        // if not collided
        if(!hit)
        {
            // call this function every so frames to check if it's time to create another obstacle //
            if(app::getElapsedFrames()%200 == 0)
            {
                _obstacle.addPipe(640.0);
                maxBoundaryHeight++;
            }
            hit = _obstacle.update(_Helicopter, dt, speed);
            
            _Helicopter.updatePosition(dt);
            
            _scoringEngine.update();
        }
	}
}

void HelicopterCinderApp::draw()
{
    gl::clear(); //clear screen
	_BoundaryController.draw();
	_obstacle.draw();
	_Helicopter.draw();
    _scoringEngine.draw();
	if(hit)
	_scoringEngine.gameover();
}



CINDER_APP_NATIVE( HelicopterCinderApp, RendererGl )
