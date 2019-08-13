

#ifndef Macros_hpp
#define Macros_hpp


#ifdef _WIN64

	#include "SDL.h"
	#include "SDL_image.h"
#include "SDL_ttf.h"

#elif _WIN32

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#else

	#include "SDL2/SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#endif


#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include <cmath>
#include <iomanip>


#include "Point2D.hpp"



using namespace std;

const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 800;

//每秒的帧数
const int FRAMES_PER_SECOND = 60;

//模拟高延迟
//bool	m_needHighCPU = true;

//static SDL_Renderer* g_render = nullptr;

enum GameObjectType
{
	GOT_NULL = 0,

	GOT_PLAYER,
	GOT_ENEMY,

	GOT_MAX
};

#endif //Macros_hpp