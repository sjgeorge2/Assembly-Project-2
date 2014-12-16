
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
	_displayScore << _score;
	_display = std::to_string(_score);
}






void Scoringengine::draw()
{
	gl::drawString("Score " + _display, _position, ColorA(1,0,0), Font("Arial",30));
	
}




	
