#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/Rand.h"   // For random number generator 
#include "cinder/Timer.h" // For timer functions 

//This class draws and controls the obstacles through which the helicopter has to move


using namespace ci;
using namespace ci::app;
using namespace std;

class Pipes
{
	// Cooirdinates for upper left hand corner of rectangle 
	float left_x;
	float left_y;

	//Coordinates for Lower Right Hand Corner of rectangle
	float right_x;
	float right_y;

	 
	Timer previous_pipe; //TIme since last pipe 
	

	


public:
	Pipes();
	void draw();
	void update();

/* To Do: Move the Pipes at some velocity.
		  Leave Space between pipes
*/
};






