
#include "scoringEngine.h"


int Scoringengine::_score = 0;

Scoringengine::Scoringengine()
{
	_timeSinceStart.start();
	_width = 50;
	_height = 20;
	
	

}

void Scoringengine::update()
{
	if(int(_timeSinceStart.getSeconds())%10 == 0) // getSeconds returns a double typecast into int to compare 
	{
		++_score;
	}
	
	
}

void Scoringengine::render()
{
	 _display = "Total Score" + toString(_score);

	_scoreBox.alignment(TextBox::RIGHT).font( _scoreFont).size(_width,_height).text(_display);

	_scoreTexture = gl::Texture(_scoreBox.render()); // render the score box 

}

void Scoringengine::setup()
{
	#if defined( CINDER_COCOA )
	_scoreFont = Font( "Cochin-Italic", 12 );
#else
	_scoreFont = Font( "Times New Roman", 12 );
	
#endif	
	_scoreBox.size(_width,_height);
	
	render();
	
}


void Scoringengine::draw()
{
	if(_scoreTexture)
	{
		gl::draw(_scoreTexture);
	}
}




	
