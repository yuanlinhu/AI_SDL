
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

bool Math::isFarThanDistance(Point2D& orgin, Point2D& target, int distance)
{
	int deltaX = abs(orgin.x - target.x);
	int deltaY = abs(orgin.y - target.y);
	if ((deltaX * deltaX + deltaY * deltaY) >= distance * distance)
	{
		return true;
	}

	return false;
}

bool Math::isInCircleSector(Point2D& orgin, Point2D& dir, int degree, int radius, Point2D& target)
{
	//Ê×ÏÈÅĞ¶Ï¾àÀë
	if (true == isFarThanDistance(orgin, target, radius))
	{
		//¾àÀë¹ıÔ¶
		return false;
	}

	//int temp1 = atan2(100, 100);
	//int temp2 = atan2(100, -100);
	//int temp3 = atan2(-100, 100);
	//int temp4 = atan2(-100, -100);

	//int temp11 = asin(100 / 100);
	//int temp21 = asin(100 / -100);
	//int temp31 = asin(-100 / 100);
	//int temp41 = asin(-100 / -100);


	//float temp10 = (180.0 / 3.14f) * atan2(100, 100);
	//float temp12 = (180.0 / 3.14f) * atan2(100, -100);
	//float temp13 = (180.0 / 3.14f) * atan2(-100, 100);
	//float temp14 = (180.0 / 3.14f) * atan2(-100, -100);

	int delta_Y = (orgin.y - dir.y);
	int delta_X = (orgin.x - dir.x);

	int orgDegree = (180.0 / 3.14f) * atan2(delta_Y, delta_X);
	if (orgDegree < 0)
	{
		orgDegree += 360;
	}
	int orgDegreeMin = orgDegree - degree;
	int orgDegreeMax = orgDegree + degree;


	int delta_Y_1 = (orgin.y - target.y);
	int delta_X_1 = (orgin.x - target.x);

	if (target.x < 100)
	{
		int kk = 0;
	}

	int tarDegree = (180.0 / 3.14f) * atan2(delta_Y_1, delta_X_1);
	if (tarDegree < 0)
	{
		tarDegree += 360;
	}

	if (tarDegree >= orgDegreeMin && tarDegree <= orgDegreeMax)
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
