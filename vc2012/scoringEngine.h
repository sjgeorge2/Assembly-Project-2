#ifndef SCORINGENGINE_H
#define SCORINGENGINE_H


#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/Timer.h" 
#include "cinder/Text.h"
#include "cinder/Font.h"
#include "cinder/Utilities.h"

using namespace ci;
using namespace ci::app;

class Scoringengine
{
	Timer _timeSinceStart;
	static int _score;
	
	Font _scoreFont;
	TextBox _scoreBox;
	gl::Texture _scoreTexture;
	int _width; // width of score display box
	int _height; // height of score display box 
public:
	

	Scoringengine();
	void update();
	void draw();
	void updateScore();
};

#endif 