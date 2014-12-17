#include "heliController.h"

heliController::heliController()
{
	_position.x = 320;
	_position.y = 156;
	_isFalling = true;
    _velocity = 0.0;
    _acceleration = 0.0;
}

void heliController::draw()
{
	_Helicopter.set(_position.x, _position.y, _position.x + 50, _position.y + 50);
	gl::color(0.0f,0.0f,1.0f); // Blue to difeerentiate helicopter from obstacles 
	gl::drawSolidRect(_Helicopter);
}

void heliController::changeDirection()
{
	if (!_isFalling)
	{
		_acceleration = -700.0;
	}
	else
	{
		_acceleration = 800;
	}
}

// updates the position of the helicopter with every frame //
// currently _velocity is a placeholder variable for when we want a dynamic speed to immitate momentum //
void heliController::updatePosition(float dt)
{
    _velocity += _acceleration * dt;
	if (!_isFalling)	// move up 2 pixels with every frame while mouse is pressed, 60 frames; 120px/s//
	{
		_position.y = _position.y + _velocity * dt;
	}
	else               // move down 2 pixels with every frame while mouse is not pressed, 60 frames //
	{
		_position.y = _position.y + _velocity * dt;
	}
	
}

// not sure if adding this, need to figure out how to properly replace draw() images
int heliController::velocity(heliController & other)
{
	// uses old velocity with algorithm here to determine a new velocity //
	// imitate inertia and momentum //
	return 1;
}

void heliController::reset()
{
    _position.x = 320;
    _position.y = 156;
    _isFalling = true;
    _velocity = 0.0;
    _acceleration = 0.0;
}

float heliController::getLeftX()
{
	return _position.x;
}

float heliController::getRightX()
{
	return _position.x + 50;
}

float heliController::getTopY()
{
	return _position.y;
}

float heliController::getBottomY()
{
	return _position.y + 50;
}

void heliController::setisfalling(bool isfalling)
{
	_isFalling = isfalling;
}
