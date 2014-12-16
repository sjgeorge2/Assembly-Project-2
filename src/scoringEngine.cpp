
#include "scoringEngine.h"


int Scoringengine::_score = 0;

Scoringengine::Scoringengine()
{
	_position.set(2,0);
}

void Scoringengine::update()
{
	if(getElapsedFrames()%60 == 0) // +1 for every second played 
	{
		++_score;
	}
	_display = std::to_string(_score);
	_displayBinary = std::bitset<32>(_score).to_string();
}






void Scoringengine::draw()
{
	gl::enableAlphaBlending();
	
	gl::drawString("Score " + _display, _position, ColorA(1,0,0), Font("Arial",30));
	gl::drawString("Score in Binary " + _displayBinary, _position+Vec2f(0,25), ColorA(1,0,0), Font("Arial",20));
	
	
}




	
