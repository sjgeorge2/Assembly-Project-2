#include "pipes.h"

class Pipecontroller
{
	 Pipes _currentPipe;
	 Pipes _previousPipe;

	bool _draw; 

	static int _iterations;
	static int _framesSinceLast;


public:
	Pipecontroller();
	void update();
	void draw();
};

