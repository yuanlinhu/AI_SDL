
#include "Math.hpp"

bool Math::isInCircle(int x, int y, int circleX, int circleY, int radius)
{
	int deltaX = abs(circleX - x);
	int deltaY = abs(circleY - y);
	if (radius * radius >= (deltaX * deltaX + deltaY * deltaY))
	{
		return true;
	}

	return false;
}

bool Math::isInUmbrella(int x, int y, int circleX, int circleY, int radius)
{
	Vector2<int> _position;
	//Math::ToSceneSpace
	//Vector2f
	//float 	Distance(const Vector2f &a, const Vector2f &b)
	//SDL_Point
	//vector2
	//vector2
	int deltaX = abs(circleX - x);
	int deltaY = abs(circleY - y);
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
