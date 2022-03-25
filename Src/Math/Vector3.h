//
//  Game.hpp
//  AI_SDL_mac
//
//  Created by yuanlinhu on 2019/8/10.
//  Copyright © 2019 yuanlinhu. All rights reserved.
//

#ifndef _VECTOR_3_H_
#define _VECTOR_3_H_

#include "../Macros.hpp"



class Vector3
{
public:
	float x, y, z;

	Vector3() {}
	Vector3(const Vector3& a) : x(a.x), y(a.y), z(a.z) {}
	Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

	Vector3& operator=(const Vector3& a)
	{
		x = a.x;
		y = a.y;
		z = a.z;
		return *this;
	}

	bool operator == (const Vector3& a)
	{
		return x == a.x && y == a.y && z == a.z;
	}

	bool operator != (const Vector3& a)
	{
		return x != a.x || y != a.y || z != a.z;
	}



};







#endif //_VECTOR_3_H_
