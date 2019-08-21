#ifndef Math_HPP
#define Math_HPP

#include "Macros.hpp"

class Math
{
public:
	static bool isInCircle(int x, int y, int circleX, int circleY, int radius);
	static bool isFarThanDistance(Point2D& orgin, Point2D& target, int distance);
	//判断target点是否在 已orgin为起点，dir为方向， 半径为radius,角度为degree的扇形中
	static bool isInCircleSector(Point2D& orgin, Point2D& dir, int degree, int radius, Point2D& target);
	static int  getRand(int minVal, int maxVal);
};

#endif	//Math_HPP