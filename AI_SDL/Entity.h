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
	MyPoint m_birth;					//������
	MyPoint m_cur_pos;				//��ǰλ��
	MyPoint m_target_pos;				//Ŀ���
	MyPoint m_round;				//��Χ
	float m_speed;

};