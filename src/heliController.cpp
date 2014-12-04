#include "heliController.h"

heliController::heliController()
{
	_position.x = 320;
	_position.y = 156;
	_isFalling = true;
	_velocity = 100; // pixels per second?
}

void heliController::draw()
{
	_Helicopter.set(_position.x, _position.y, _position.x + 50, _position.y + 50);
	gl::drawSolidRect(_Helicopter);
}

void heliController::changeDirection()
{
	if (!_isFalling)
	{
		_velocity = -100;
		_isFalling = false;
	}
	else
	{
		_velocity = 100;
	}
}

void heliController::updatePosition()
{
	if (!_isFalling)	// move up 2 pixels with every frame while mouse is pressed, 60 frames; 120px/s//
	{
		_position.y = _position.y + 1;
	}
	else               // move down 2 pixels with every frame while mouse is not pressed, 60 frames //
	{
		_position.y = _position.y - 1;
	}
}

// not sure if adding this, need to figure out how to properly replace draw() images
int heliController::velocity(heliController & other)
{
	// uses old velocity with algorithm here to determine a new velocity //
	// imitate inertia and momentum //
	return 100;
}

int heliController::getLeftX()
{
	return _position.x;
}

int heliController::getRightX()
{
	return _position.x + 50;
}

int heliController::getTopY()
{
	return _position.y + 50;
}

int heliController::getBottomY()
{
	return _position.y - 50;
}
