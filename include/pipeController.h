#include "pipes.h"
#include "cinder/Timer.h" // Cinder's ibuilt timer 
#include <list>

class Pipecontroller
{
	 

	bool _draw; 

	static int _iterations;

	std::list <Pipes> _obstacles; 
 
public:
	Pipecontroller();
	void update();
	void draw();
	void addPipe(float); 
};

