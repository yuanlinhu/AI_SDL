#ifndef Math_HPP
#define Math_HPP

#include "Macros.hpp"

class Math
{
public:
	static bool isInCircle(int x, int y, int circleX, int circleY, int radius);
	static bool isFarThanDistance(Vector2D& orgin, Vector2D& target, int distance);
	//判断target点是否在 已orgin为起点，dir为方向， 半径为radius,角度为degree的扇形中
	static bool isInCircleSector(Vector2D& orgin, Vector2D& dir, int degree, int radius, Vector2D& target);
	static int  getRand(int minVal, int maxVal);
};

#endif	//Math_HPP