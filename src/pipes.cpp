
#include "pipes.h"

Pipes::Pipes()
{
	/*left_x = Rand::randFloat(0,640);
	left_y = 0.0f; //Pipe starts at the bottom
	right_x=left_x+10.0f; // 10 pixels wide 
	right_y=left_y+Rand::randFloat(10,-390); // height between 10pixels to half screen 
	*/
}


//Draw the Pipe 
void Pipes::draw()
{
	
	left_x = Rand::randFloat(0,640);
	left_y = 780.0f; //Pipe starts at the bottom
	right_x=left_x+10.0f; // 10 pixels wide 
	right_y=left_y+Rand::randFloat(10,-390); // height between 10pixels to half screen 
	Rectf currentPipe(left_x,left_y,right_x,right_y);
	gl::drawSolidRect(currentPipe); 
}

// This should move the pipes at some velocity 
void Pipes::update()
{
}
