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
#include "../include/pipes.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class HelicopterCinderApp : public AppNative {

	Pipes obstacle;

  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void drawpipe();
};


//Function to draw the pipes (obstacles) 
void drawpipe()
{
	//upper left, lower right corner 
	
	int left_x = Rand::randFloat(0,640);
	int left_y = 0.0f;//Pipe starts at the bottom
	int right_x=left_x+10.0f; // 10 pixels wide 
	int right_y=left_y+Rand::randFloat(10,-390);// height between 10pixels to half screen 
	Rectf pipe(left_x,left_y,right_x,right_y);
	gl::drawSolidRect(pipe); 
}

	
	
	//Default Screen is 640x780
void HelicopterCinderApp::setup()
{
	
	


}

void HelicopterCinderApp::mouseDown( MouseEvent event )
{
}

void HelicopterCinderApp::update()
{
}

void HelicopterCinderApp::draw()
{
	obstacle.draw();
}



CINDER_APP_NATIVE( HelicopterCinderApp, RendererGl )
