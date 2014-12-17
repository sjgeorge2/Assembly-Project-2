#ifndef HELICONTROLLER_H
#define HELICONTROLLER_H

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
// This is the Helicoptor class that handles movement and draws for the helicopter

using namespace ci;
using namespace ci::app;
using namespace std;


class heliController
{
private:
	Rectf _Helicopter;
	ci::Vec2f _position;
	bool _isFalling;
    float _velocity;
    float _acceleration;


public:
	heliController();
	void updatePosition(float dt);
	void draw();
	void changeDirection();
	int velocity( heliController & other);
	float getRightX();
	float getLeftX();
	float getTopY();
	float getBottomY();
	void setisfalling(bool);

};


#endif
