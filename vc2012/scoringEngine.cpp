
#include "scoringEngine.h"


int Scoringengine::_score = 0;

Scoringengine::Scoringengine()
{
	_timeSinceStart.start();
	_scoreFont = Font("Times New Roman", 12);
	_width = 100;
	_height = 20;
	
	_scoreBox.size(_width,_height);

}

void Scoringengine::update()
{
    if(int(app::getElapsedFrames())%30 == 0) // getSeconds returns a double typecast into int to compare
	{
		_score += 1;
	}
	
	std::string display = "Total Score " + toString(_score);

	_scoreBox.alignment(TextBox::RIGHT).font(_scoreFont).size(_width,_height).text(display);

	_scoreTexture = gl::Texture(_scoreBox.render()); // render the score box 

}

void Scoringengine::draw()
{
	if(_scoreTexture)
	{
        gl::color(1.0, 0.0, 0.0);
		gl::draw(_scoreTexture);
	}
}




	
