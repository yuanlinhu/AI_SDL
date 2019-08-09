#pragma once
#include "SDL.h"

class Map
{
public:
	Map();

	void initMap();
	void init(int x, int y, int w, int h);
	void show(SDL_Surface* winSurface, SDL_Renderer *render);
	void update();
private:
	int m_x;
	int m_y;

	int m_w;
	int m_h;
};
