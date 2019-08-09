#include "Entity.h"


#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


Entity::Entity()
{
	m_speed = 1;

	m_round.x = 200;
	m_round.y = 200;
}

void Entity::set_target_pos(int x, int y)
{
	m_target_pos.x = x;
	m_target_pos.y = y;
}

void Entity::set_random_target_pos()
{
	m_target_pos.x = m_birth.x + rand() % m_round.x;
	m_target_pos.y = m_birth.y + rand() % m_round.y;
	
}

void Entity::set_birth_pos(int x, int y)
{
	m_birth.x = x;
	m_birth.y = y;

	m_cur_pos.x = m_birth.x;
	m_cur_pos.y = m_birth.y;

	m_target_pos.x = x;
	m_target_pos.y = y;
}


void Entity::set_random_birth_pos()
{
	set_birth_pos(500, 500);
}


void Entity::update()
{
	if (m_target_pos == m_cur_pos)
	{
		set_random_target_pos();
		return;
	}

	int x_mul = (m_target_pos.x > m_cur_pos.x) ? 1 : -1;
	int y_mul = (m_target_pos.y > m_cur_pos.y) ? 1 : -1;

	x_mul = (m_target_pos.x == m_cur_pos.x) ? 0 : x_mul;
	y_mul = (m_target_pos.y == m_cur_pos.y) ? 0 : y_mul;
	
	m_cur_pos.x += (x_mul * m_speed);
	m_cur_pos.y += (y_mul * m_speed);

}


void Entity::show(SDL_Surface* winSurface)
{
	//画范围
	{
		SDL_Rect rect_round;
		rect_round.x = m_birth.x;
		rect_round.y = m_birth.y;
		rect_round.w = m_round.x;
		rect_round.h = m_round.y;
		SDL_FillRect(winSurface, &rect_round, SDL_MapRGB(winSurface->format, 50, 200, 200));
	}

	//画当前位置
	{
		SDL_Rect rect;
		rect.x = m_cur_pos.x;
		rect.y = m_cur_pos.y;
		rect.w = 10;				//物体大小
		rect.h = 10;
		SDL_FillRect(winSurface, &rect, SDL_MapRGB(winSurface->format, 0, 90, 120));
	}
	

	//画目标
	{
		SDL_Rect rect;
		rect.x = m_target_pos.x;
		rect.y = m_target_pos.y;
		rect.w = 15;		
		rect.h = 15;
		SDL_FillRect(winSurface, &rect, SDL_MapRGB(winSurface->format, 0, 0, 120));
	}


	
	
}


