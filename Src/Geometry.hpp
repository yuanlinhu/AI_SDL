#ifndef Geometry_HPP
#define Geometry_HPP

#include "Macros.hpp"

class Geometry
{
public:

	static void DrawCircle(SDL_Renderer *render, int radius, int mx, int my);
	static void DrawRect(SDL_Renderer *ren, int mx, int my, int x, int y);

	static bool isInCircle();
};

#endif	//Geometry_HPP