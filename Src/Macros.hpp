

#ifndef Macros_hpp
#define Macros_hpp


#ifdef _WIN64
	#include "SDL.h"
	#include "SDL_image.h"
#elif _WIN32
#include "SDL.h"
#include "SDL_image.h"
#else
	#include "SDL2/SDL.h"
#endif


#include <stdio.h>
#include <map>
#include <vector>
#include <string>

using namespace std;

const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 800;

//Ã¿ÃëµÄÖ¡Êý
const int FRAMES_PER_SECOND = 20;

//static SDL_Renderer* g_render = nullptr;

#endif //Macros_hpp