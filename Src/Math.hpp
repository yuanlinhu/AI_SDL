#ifndef Math_HPP
#define Math_HPP

#include "Macros.hpp"

class Math
{
public:
	static bool isInCircle(int x, int y, int circleX, int circleY, int radius);
	static bool isFarThanDistance(Vector2D& orgin, Vector2D& target, int distance);
	//�ж�target���Ƿ��� ��orginΪ��㣬dirΪ���� �뾶Ϊradius,�Ƕ�Ϊdegree��������
	static bool isInCircleSector(Vector2D& orgin, Vector2D& dir, int degree, int radius, Vector2D& target);
	static int  getRand(int minVal, int maxVal);
};

#endif	//Math_HPP