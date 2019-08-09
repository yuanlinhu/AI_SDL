#include "Dot.h"
#include <SDL.h>


const int DOT_WIDTH = 10;
const int DOT_HEIGHT = 10;

Dot::Dot()
{
	//��ʼ������
	x = 0;
	y = 0;

	//��ʼ������
	xVel = 0;
	yVel = 0;
}

void Dot::handle_input(SDL_Event& event)
{
	//��һ����������
	if (event.type == SDL_KEYDOWN)
	{
		//�����ٶ�
		switch (event.key.keysym.sym)
		{
		case SDLK_UP: yVel -= DOT_HEIGHT / 2; break;
		case SDLK_DOWN: yVel += DOT_HEIGHT / 2; break;
		case SDLK_LEFT: xVel -= DOT_WIDTH / 2; break;
		case SDLK_RIGHT: xVel += DOT_WIDTH / 2; break;
		}
	}
	//��һ�����̰������ɿ�
	else if (event.type == SDL_KEYUP)
	{
		//�����ٶ�
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
	//��Բ�������ƶ�
	x += xVel;

	//��Բ������������һ���ߵ�̫Զʱ
	if ((x < 0) || (x + DOT_WIDTH > SCREEN_WIDTH))
	{
		//����ק����
		x -= xVel;
	}

	//��Բ�������ƶ�
	y += yVel;

	//��Բ������������һ���ߵ�̫Զʱ
	if ((y < 0) || (y + DOT_HEIGHT > SCREEN_HEIGHT))
	{
		//ק����
		y -= yVel;
	}
}

void Dot::show()
{
	//��ʾԲ��
	apply_surface(x, y, dot, screen);
}