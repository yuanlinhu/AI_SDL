#ifndef Math_HPP
#define Math_HPP

#include "Macros.hpp"

class Math
{
public:
	static bool isInCircle(int x, int y, int circleX, int circleY, int radius);
	static bool isFarThanDistance(Point2D& orgin, Point2D& target, int distance);
	//�ж�target���Ƿ��� ��orginΪ��㣬dirΪ���� �뾶Ϊradius,�Ƕ�Ϊdegree��������
	static bool isInCircleSector(Point2D& orgin, Point2D& dir, int degree, int radius, Point2D& target);
	static int  getRand(int minVal, int maxVal);
};

#endif	//Math_HPP