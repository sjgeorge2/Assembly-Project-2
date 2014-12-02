
#include "pipes.h"


//Initiale Staic members 
Rectf Pipes::_currentPipe(0,0,0,0);  
Rectf Pipes::_previousPipe(0,0,0,0);
int Pipes::_count=0; 



Pipes::Pipes()
{
	_leftX=_leftY=_rightX=_rightY=0.0;
}


//Draw the Pipe 
//FixMe: Pipes are not constant height 
void Pipes::draw()
{
	
	gl::drawSolidRect(_currentPipe); 
}

void Pipes::setleftX(int leftX)
{
	_leftX = leftX;
}


// This should move the pipes at some velocity 
void Pipes::update()
{
		//_leftX = Rand::randFloat(0,640); // _leftX is now set by Pipescontroller 
		_rightX = _leftX+40; //40 pixels wide  
		_leftY = Rand::randFloat(100.0f,630.0f); //Leave 100px distance from top and bottom( bottom is screwed up)   to prevent overlap with Lonny's surface
		_rightY=_leftY+100.0;  // height 100 pixels
		_currentPipe.set(_leftX,_leftY,_rightX,_rightY);
		
}

// Return _count. Makes it accessible to the outside world 
int Pipes::getcount()
{
	return _count;
}

int Pipes::incrementcount()
{
	_count=_count+1;
	return _count;
}
