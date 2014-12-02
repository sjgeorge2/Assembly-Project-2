/* This implementation will clear the screen every 4 seconds and will require other objects to redraw themselves that often*/



#include "pipeController.h"


int Pipecontroller::_iterations = 0; 
int Pipecontroller::_framesSinceLast = 0;

Pipecontroller::Pipecontroller()
{
}


/* In theor, this update funtion should draw 4 equidistant triangles 
   But currently it draws them randomly but i seem to like it better
*/

void Pipecontroller::update()
{
	_framesSinceLast++;
	_draw = false;
	if(_framesSinceLast%30 ==0)
	{if(_iterations<4)
		{
		_draw = true; 
  		_currentPipe.setleftX(160+(160*_iterations)); //One pipe every +160 pixels in the poitive x ( 4 pipes per screen) 
		++_iterations;
		_currentPipe.update();
		}
	else
	{
		_iterations = 0; // reset _ieterations to 0
		
		//Screen clears every 2 seconds 
		gl::clear(); // clear the screen 
	}
	}



}


void Pipecontroller::draw()
{
	if(_draw)
	{
		_currentPipe.draw();
	}
}


