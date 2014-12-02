#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "BoundaryController.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HelicopterApp : public AppNative {
  public:
    void prepareSettings(Settings *settings);
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    int size;
    bool upDown;
    int incrementSize;
    BoundaryController _BoundaryController;
};

void HelicopterApp::prepareSettings( Settings *settings ){
    //settings->setWindowSize( 800, 600 );
    settings->setFrameRate( 60.0f );
}


void HelicopterApp::setup()
{
    size = 0;
    upDown = true;
    incrementSize = 5;
}

void HelicopterApp::mouseDown( MouseEvent event )
{
}

void HelicopterApp::update()
{
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
}

void HelicopterApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    _BoundaryController.draw();
}

CINDER_APP_NATIVE( HelicopterApp, RendererGl )
