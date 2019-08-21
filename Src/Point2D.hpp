#ifndef POINT_2D_HPP
#define POINT_2D_HPP


class Point2D
{
public:
	Point2D();
	Point2D(int mX, int mY)
	{
		x = mX;
		y = mY;
	}
	
	bool operator==(const Point2D &ps) const
	{

		if (this->x == ps.x && this->y == ps.y)
			return true;
		return false;
	}

public:
	int x;
	int y;
};

#endif	//POINT_2D_HPP