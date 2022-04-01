
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

bool Math::isFarThanDistance(Vector2D& orgin, Vector2D& target, int distance)
{
	int deltaX = abs(orgin.x - target.x);
	int deltaY = abs(orgin.y - target.y);
	if ((deltaX * deltaX + deltaY * deltaY) >= distance * distance)
	{
		return true;
	}

	return false;
}

//���������� ����� �Ƕȷ�Χ�� ��Ҫ��������
void CalculateDegree(Vector2D& orgin, Vector2D& target, int& curDegree)
{
	int mulX = 1;
	int mulY = 1;
	int xiangxian = 1;
	if (orgin.y >= target.y)
	{
		//1��2 ����
		if (orgin.x >= target.x)
		{
			mulX = -1;
			mulY = 1;
			xiangxian = 2;
		}
		else
		{
			mulX = 1;
			mulY = 1;
			xiangxian = 1;
		}
	}
	else
	{
		//3��4 ����
		if (orgin.x >= target.x)
		{
			mulX = -1;
			mulY = -1;
			xiangxian = 3;
		}
		else
		{
			mulX = 1;
			mulY = -1;
			xiangxian = 4;
		}
	}


	//����Ƕ�

	int delta_X = abs(orgin.x - target.x) * mulX;
	int delta_Y = abs(orgin.y - target.y) * mulY;

	int orgDegree = (180.0 / 3.14f) * atan2(delta_Y, delta_X);
	curDegree = orgDegree;

	if (orgDegree < 0)
	{
		curDegree += 360;
	}

}

bool Math::isInCircleSector(Vector2D& orgin, Vector2D& dir, int degree, int radius, Vector2D& target)
{
	//�����жϾ���
	if (true == isFarThanDistance(orgin, target, radius))
	{
		//�����Զ
		return false;
	}


	int tarDegree = 0;
	CalculateDegree(orgin, target, tarDegree);

	int orgDegree = 0;
	CalculateDegree(orgin, dir, orgDegree);

	int orgDegreeMin = (orgDegree - degree) % 360;
	int orgDegreeMax = (orgDegree + degree) % 360;

	if (orgDegreeMin < 0)
	{
		orgDegreeMin += 360;
	}

	if (orgDegreeMax < 0)
	{
		orgDegreeMax += 360;
	}

	//cout << "orgDegree: " << orgDegree << ", tarDegree: " << tarDegree << endl;

	//cout << "orgDegreeMin: " << orgDegreeMin << ", orgDegreeMax: " << orgDegreeMax << endl;

	if (orgDegreeMin <= orgDegreeMax)
	{
		//������Χ
		if (tarDegree >= orgDegreeMin && tarDegree <= orgDegreeMax)
		{
			return true;
		}
	}
	else
	{
		//���˵�������
		if (tarDegree >= 0 && tarDegree <= orgDegreeMax)
		{
			//�ȼ��1~3���޵�
			return true;
		}

		//int _4thQuadStart = 360 + orgDegreeMin;
		if (tarDegree >= orgDegreeMin && tarDegree <= 360)
		{
			//���������
			return true;
		}
	}


	return false;


	//int delta_Y = (orgin.y - dir.y);
	//int delta_X = (orgin.x - dir.x);

	//int orgDegree = (180.0 / 3.14f) * atan2(delta_Y, delta_X);
	//if (orgDegree < 0)
	//{
	//	orgDegree += 360;
	//}
	//int orgDegreeMin = orgDegree - degree;
	//int orgDegreeMax = orgDegree + degree;

	//if (orgDegreeMin < 0)
	//{
	//	orgDegreeMin += 360;
	//}

	//if (orgDegreeMax < 0)
	//{
	//	orgDegreeMax += 360;
	//}

	//if (orgDegreeMin > orgDegreeMax)
	//{
	//	//����90�ȵ�ʱ����Ҫ���´���

	//	orgDegreeMin -= 180;
	//	//int tmp = orgDegreeMin;
	//	//orgDegreeMin = orgDegreeMax;
	//	//orgDegreeMax = tmp;

	//}

	//int delta_Y_1 = (orgin.y - target.y);
	//int delta_X_1 = (orgin.x - target.x);

	//if (target.x == 110 && target.y == 110)
	//{
	//	int kk = 0;
	//}

	//int tarDegree = (180.0 / 3.14f) * atan2(delta_Y_1, delta_X_1);
	//if (tarDegree < 0)
	//{
	//	tarDegree += 360;
	//}

	//if (tarDegree >= orgDegreeMin && tarDegree <= orgDegreeMax)
	//{
	//	return true;
	//}

	//return false;
}


int Math::getRand(int minVal, int maxVal)
{
	int delta = rand() / maxVal - minVal;
	return minVal + delta;
}
