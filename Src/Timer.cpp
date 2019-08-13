#include "Timer.hpp"



Timer::Timer()
{

}

void Timer::setTimer(int second)
{
	m_startTicks = SDL_GetTicks();
	m_expireTicks = m_startTicks + second * 1000;
}

void Timer::reset()
{
	m_startTicks = 0;
	m_endTicks = 0;
	m_expireTicks = 0;
}

void Timer::start()
{
	m_startTicks = SDL_GetTicks();
}

void Timer::end()
{
	m_endTicks = SDL_GetTicks();
}

bool Timer::isExpire()
{
	if (m_expireTicks <= 0)
	{
		return false;
	}
	int nowTicks = SDL_GetTicks();
	if (nowTicks >= m_expireTicks)
	{
		return true;
	}

	return false;
}
