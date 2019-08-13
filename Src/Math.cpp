
#include "Math.hpp"

bool Math::isInCircle(int x, int y, int circleX, int circleY, int radius)
{
	int deltaX = circleX - x;
	int deltaY = circleY - y;
	if (radius * radius >= (deltaX * deltaX + deltaY * deltaY))
	{
		return true;
	}

	return false;
}

int Math::getRand(int minVal, int maxVal)
{
	int delta = rand() / maxVal - minVal;
	return minVal + delta;
}
