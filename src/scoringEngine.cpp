
#include "scoringEngine.h"


int Scoringengine::_score = 0;
int Scoringengine::_highScore = 0;

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
    _displayHighScore = std::to_string(_highScore);
}


void Scoringengine::draw()
{
	gl::enableAlphaBlending();
	
	gl::drawString("Score " + _display, _position, ColorA(1,0,0), Font("Arial",30));
	gl::drawString("Score in Binary " + _displayBinary, _position+Vec2f(0,25), ColorA(1,0,0), Font("Arial",20));
    gl::drawString("High Score " + _displayHighScore, Vec2f(0,465), ColorA(1,0,0), Font("Arial",20));
}


void Scoringengine::reset()
{
    if (_highScore < _score) {
        _highScore = _score;
    }
    _score = 0;
}

void Scoringengine::gameover()
{
	gl::drawStringCentered("Game Over", Vec2f(320,240),ColorA (1,0,0),Font("Arial", 40));
	gl::drawStringCentered("Press Enter Start New Game", Vec2f(320,300),ColorA (1,0,0),Font("Arial", 40));
}
