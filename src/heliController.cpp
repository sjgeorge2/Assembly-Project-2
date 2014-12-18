#include "heliController.h"

heliController::heliController()
{
	_position.x = 160;
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

/*Called every tume a mouse event happens
  reverses the y-accleration 
*/
void heliController::changeDirection()
{
	if (!_isFalling)
	{
		_acceleration = -700.0; // Screen coordinates start at top left corner, so this makes the helicopter fall down 
	}
	else
	{
		_acceleration = 800; //Helicopter goes up 
	}
}

// updates the position of the helicopter with every frame //
// currently _velocity is a placeholder variable for when we want a dynamic speed to immitate momentum //
void heliController::updatePosition(float dt)
{
    _velocity += _acceleration * dt; // Newtons laws of motion(v = vo*t)
	if (!_isFalling)	
	{
		_position.y = _position.y + _velocity * dt; //  move up (velocity*dt) pixels  every frame
	}
	else               
	{
		_position.y = _position.y + _velocity * dt; //  move down (velocity*dt) pixels  every frame
	}
	
}

/*
 Reset the game state when player requests a new game 
*/
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
	return _position.x; // Return the top left x-coordinate 
}

float heliController::getRightX()
{
	return _position.x + 50; // Return the bottom right x-coordinate
}

float heliController::getTopY()
{
	return _position.y; // Return the top left y-coordinate
}

float heliController::getBottomY()
{
	return _position.y + 50; // Return the bottom right x-coordinate
}

void heliController::setisfalling(bool isfalling)
{
	_isFalling = isfalling;
}
