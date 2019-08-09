#pragma once


class MyPoint
{
public:
	MyPoint();
	
	bool operator==(const MyPoint &ps) const
	{

		if (this->x == ps.x && this->y == ps.y)
			return true;
		return false;
	}

public:
	int x;
	int y;
};

