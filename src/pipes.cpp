
#include "pipes.h"

Pipes::Pipes()
{
	_count=0;
}


//Draw the Pipe 
//FixMe: Pipes are going all the way to the bottom (right_y<=780)
void Pipes::draw()
{
	
	_leftX = Rand::randFloat(0,640);
	_rightX = _leftX+40; //20 pixels wide  
	_leftY = Rand::randFloat(100.0f,680.0f); //Leave 100px distance from top and bottom to prevent overlap with Lonny's surface
	_rightY=_rightX+50;  // height between 10-50 pixels
	_currentPipe.set(_leftX,_leftY,_rightX,_rightY);
	gl::drawSolidRect(_currentPipe); 
}

// This should move the pipes at some velocity 
void Pipes::update()
{
	_count=_count+1; 

}

// Return _count. Makes it accessible to the outside world 
int Pipes::getcount()
{
	return _count;
}