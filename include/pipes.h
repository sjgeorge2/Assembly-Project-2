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
	float _leftX;
	float _leftY;

	//Coordinates for Lower Right Hand Corner of rectangle
	float _rightX;
	float _rightY;

	 static Rectf _currentPipe; // The current Pipe 
	 static Rectf _previousPipe; //The previous Pipe 

	 
	 static int _count; //counter since last pipe drawn
	 
	

	


public:
	Pipes();
	void draw();
	void update();
	
	int getcount();
	int incrementcount();
	void setleftX(int);

/* To Do: Move the Pipes at some velocity.
		  Leave Space between pipes
*/
};







