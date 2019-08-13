#ifndef Trigger_HPP
#define Trigger_HPP

#include "Macros.hpp"
#include "Timer.hpp"

class Game;

class Trigger
{
public:
	Trigger();
	void init(TriggerType type, int x, int y);

	void update(Game* game);

	void render(SDL_Renderer* render);

	bool canErase();

	void setMaxIndex(int index)
	{
		m_maxIndex = index;
	}

	void setTimer(int milliSec)
	{
		m_Timer.setTimer(milliSec);
	}

	bool isExpire()
	{
		return m_Timer.isExpire();
	}

	void startTimer()
	{
		m_Timer.start();
	}

private:
	TriggerType		m_Type;
	Point2D			m_birthPos;
	Timer			m_Timer;
	int				m_curIndex = 0;
	int				m_maxIndex = 0;

	int				m_Radius;
};

#endif	//Trigger_HPP