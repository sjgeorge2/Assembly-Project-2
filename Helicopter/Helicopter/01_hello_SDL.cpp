/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <iostream>



//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
	SDL_Window* window = NULL;
	
//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

//The Image we will load 
	SDL_Surface* background = NULL;

bool init()
{
	bool initialized = true;
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		initialized = false;
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( "Helicopter ", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			initialized = false;
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface( window );
		}
	}
	return initialized;
}


//FUnction to load the main window
bool loadMedia()
{
	bool loaded =  true;

	//Load the backgroud Image
	background = SDL_LoadBMP("Images/background.bmp");
	if( background == NULL) // Loading failes
	{
		std::cout<<"Failed to load background Image: "<<"Images/background.bmp";
		std::cout<<"Returned SDL Error: "<<SDL_GetError() <<std::endl;
		loaded = false;
	}
	return loaded;
}

// Close the Program gracefully 
void close()
{
	//Deallocate Surface
	SDL_FreeSurface(screenSurface);
	screenSurface = NULL;

	//Destroy Window
	SDL_DestroyWindow(window);
	window = NULL;

	//Quit the Program
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	if(!init())
	{
		std::cout<<"Failed to Initialize SDL"<<std::endl;
	}
	else
	{
		if(!loadMedia())
		{
			std::cout<<"Failed to Load Media"<<std::endl;
		}
		else{
			//Apply the Image
			SDL_BlitSurface(screenSurface, NULL, background ,NULL);
			//UPdate the surface
			SDL_UpdateWindowSurface(window);
			//5 second delay
			SDL_Delay( 5000 );
		}
	}
	close();
	

	return 0;
}


