#pragma once

#include "MyPoint.h"
#include "SDL.h"

class Entity
{
public:
	Entity();
	void set_target_pos(int x, int y);
	void set_birth_pos(int x, int y);
	void set_random_birth_pos();
	void set_random_target_pos();
	void update();
	void show(SDL_Surface* winSurface);
public:
	MyPoint m_birth;					//出生点
	MyPoint m_cur_pos;				//当前位置
	MyPoint m_target_pos;				//目标点
	MyPoint m_round;				//范围
	float m_speed;

};