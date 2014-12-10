#ifndef SCORINGENGINE_H
#define SCORINGENGINE_H


#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/TextureFont.h"
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
	std::string _display;

	TextBox _scoreBox;
	Font _scoreFont;
	gl::Texture _scoreTexture;
	int _width; // width of score display box
	int _height; // height of score display box 
public:
	
	
	Scoringengine();
	void update();
	void draw();
	void updateScore();
	void setup();
	void render();
};

#endif 