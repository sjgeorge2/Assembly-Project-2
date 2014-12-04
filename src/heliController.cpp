#include "heliController.h"

heliController::heliController()
{
	_position.x = 320;
	_position.y = 156;
	_isFalling = true;
	_velocity = 1; // pixels per second?
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
		_velocity = -1;
	}
	else
	{
		_velocity = 1;
		_isFalling = true;
	}
}

// updates the position of the helicopter with every frame //
// currently _velocity is a placeholder variable for when we want a dynamic speed to immitate momentum //
void heliController::updatePosition()
{
	if (!_isFalling)	// move up 2 pixels with every frame while mouse is pressed, 60 frames; 120px/s//
	{
		_position.y = _position.y + _velocity;
	}
	else               // move down 2 pixels with every frame while mouse is not pressed, 60 frames //
	{
		_position.y = _position.y + _velocity;
	}
}

// not sure if adding this, need to figure out how to properly replace draw() images
int heliController::velocity(heliController & other)
{
	// uses old velocity with algorithm here to determine a new velocity //
	// imitate inertia and momentum //
	return 1;
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
