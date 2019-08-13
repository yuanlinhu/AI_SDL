#ifndef Timer_HPP
#define Timer_HPP

#include "Macros.hpp"

class Timer
{
public:
	Timer();
	
	void setTimer(int second);
	void start();
	void end();
	void reset();

	bool isExpire();
	

public:
	int m_startTicks = 0;
	int m_endTicks = 0;
	int m_expireTicks = 0;

};

#endif	//Timer_HPP