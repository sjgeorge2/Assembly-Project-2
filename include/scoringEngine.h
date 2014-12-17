#ifndef SCORINGENGINE_H
#define SCORINGENGINE_H

#include<bitset>

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/TextureFont.h"
#include "cinder/Timer.h" 
#include "cinder/Utilities.h"

using namespace ci;
using namespace ci::app;

class Scoringengine
{
	Vec2f _position; //Score display starts at this location 
	static int _score;
    static int _highScore;
	std::string _display;
	std::string _displayBinary;// Display the string in Binary
    std::string _displayHighScore;
	
public:
	
	
	Scoringengine();
	void update();
	void draw();
    void reset();
	
};

#endif 