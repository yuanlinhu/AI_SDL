#include "Map.h"


Map::Map()
{
	m_x = 0;
	m_y = 0;

	m_w = 0;
	m_h = 0;
}

void Map::initMap()
{
	init(50, 50, 800, 800);
}

void Map::init(int x, int y, int w, int h)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
}

void Map::show(SDL_Surface* winSurface, SDL_Renderer *render)
{
	SDL_Rect rect;
	rect.x = m_x;
	rect.y = m_y;
	rect.w = m_w;				//物体大小
	rect.h = m_h;
	SDL_FillRect(winSurface, &rect, SDL_MapRGB(winSurface->format, 128, 128, 128));
}

void Map::update()
{

}

