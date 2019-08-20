#ifndef Math_HPP
#define Math_HPP

#include "Macros.hpp"

class Math
{
public:
	static bool isInCircle(int x, int y, int circleX, int circleY, int radius);

	static bool isInUmbrella(int x, int y, int circleX, int circleY, int radius);
	static int  getRand(int minVal, int maxVal);
};

#endif	//Math_HPP