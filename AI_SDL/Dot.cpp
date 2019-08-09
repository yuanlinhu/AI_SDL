#include "Dot.h"
#include <SDL.h>


const int DOT_WIDTH = 10;
const int DOT_HEIGHT = 10;

Dot::Dot()
{
	//初始化坐标
	x = 0;
	y = 0;

	//初始化速率
	xVel = 0;
	yVel = 0;
}

void Dot::handle_input(SDL_Event& event)
{
	//当一个键被按下
	if (event.type == SDL_KEYDOWN)
	{
		//调整速度
		switch (event.key.keysym.sym)
		{
		case SDLK_UP: yVel -= DOT_HEIGHT / 2; break;
		case SDLK_DOWN: yVel += DOT_HEIGHT / 2; break;
		case SDLK_LEFT: xVel -= DOT_WIDTH / 2; break;
		case SDLK_RIGHT: xVel += DOT_WIDTH / 2; break;
		}
	}
	//当一个键盘按键被松开
	else if (event.type == SDL_KEYUP)
	{
		//调整速度
		switch (event.key.keysym.sym)
		{
		case SDLK_UP: yVel += DOT_HEIGHT / 2; break;
		case SDLK_DOWN: yVel -= DOT_HEIGHT / 2; break;
		case SDLK_LEFT: xVel += DOT_WIDTH / 2; break;
		case SDLK_RIGHT: xVel -= DOT_WIDTH / 2; break;
		}
	}
}

void Dot::move()
{
	//将圆点左右移动
	x += xVel;

	//当圆点往左右任意一侧走得太远时
	if ((x < 0) || (x + DOT_WIDTH > SCREEN_WIDTH))
	{
		//把它拽回来
		x -= xVel;
	}

	//将圆点上下移动
	y += yVel;

	//当圆点往上下任意一侧走得太远时
	if ((y < 0) || (y + DOT_HEIGHT > SCREEN_HEIGHT))
	{
		//拽回来
		y -= yVel;
	}
}

void Dot::show()
{
	//显示圆点
	apply_surface(x, y, dot, screen);
}