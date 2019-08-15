

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

#include <vector>
#include <list>
#include <map>
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


class Font;
class Game;
class GameObjectMgr;
class GameObject;
class Timer;
class TriggerMgr;
class Trigger;
class GameMap;
class BlockMgr;
class Block;


//ÿ���֡��
const int FRAMES_PER_SECOND = 60;

extern SDL_Renderer* g_render;


//���ڴ�С
const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 800;

//��ͼ��С
const int MAP_WIDTH = 800;
const int MAP_HEIGHT = 600;

//�ϰ�����С��λ
const int BLOCK_WIDTH = 50;
const int BLOCK_HEIGHT = 50;



//ģ����ӳ�
//bool	m_needHighCPU = true;

//static SDL_Renderer* g_render = nullptr;

enum GameObjectType
{
	GOT_NULL = 0,

	GOT_PLAYER,
	GOT_ENEMY,

	GOT_MAX
};

enum TriggerType
{
	TRT_NULL = 0,

	TRT_AREA,
	TRT_COLLIDE,

	TRT_MAX
};


enum BlockType
{
	BLT_NULL = 0,

	BLT_ROCK,


	BLT_MAX
};

#endif //Macros_hpp