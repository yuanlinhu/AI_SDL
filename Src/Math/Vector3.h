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


	void zero()
	{
		x = y = z = 0.0f;
	}

	Vector3 operator - () const
	{
		return Vector3(-x, -y, -z);
	}

	Vector3 operator + (const Vector3& a) const
	{
		return Vector3(x + a.x, y + a.y, z + a.z);
	}

	Vector3 operator - (const Vector3& a) const
	{
		return Vector3(x - a.x, y - a.y, z - a.z);
	}

	Vector3 operator * (float a) const
	{
		return Vector3(a*x, a*y, a*z);
	}

	Vector3 operator / (float a) const
	{
		float oneOverA = 1.0f / a;
		return Vector3(oneOverA*x, oneOverA*y, oneOverA*z);
	}


	Vector3& operator += (const Vector3& a)
	{
		x += a.x;
		y += a.y;
		z += a.z;
		return *this;
	}

	Vector3& operator -= (const Vector3& a)
	{
		x -= a.x;
		y -= a.y;
		z -= a.z;
		return *this;
	}

	Vector3& operator *= (float a)
	{
		x *= a;
		y *= a;
		z *= a;
		return *this;
	}

	Vector3& operator /= (float a)
	{
		float oneOverA = 1.0f / a;
		x *= oneOverA;
		y *= oneOverA;
		z *= oneOverA;
		return *this;
	}

	//向量标准化
	void normalize()
	{
		float magSq = x*x + y*y + z*z;
		if (magSq > 0.0f)
		{
			float oneOverMag = 1.0f / sqrt(magSq);
			x *= oneOverMag;
			y *= oneOverMag;
			z *= oneOverMag;
		}
	}


	//向量点乘
	float operator *(const Vector3& a) const
	{
		return x * a.x + y * a.y + z * a.z;
	}

};



//////////////////////////////////////////////////////////////////////////
//非成员函数
//////////////////////////////////////////////////////////////////////////

//求向量模
float vectorMag(const Vector3& a)
{
	return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

//计算叉乘
inline Vector3 crossProduct(const Vector3& a, const Vector3& b)
{
	return Vector3(
		a.y*b.z - a.z*b.y,
		a.x*b.z - a.z*b.x,
		a.x*b.y - a.y*b.x);
}


inline Vector3 operator *(float k, const Vector3& a)
{
	return Vector3(k*a.x, k*a.y, k*a.z);
}

inline float distance(const Vector3& a, const Vector3& b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;

	return sqrt(dx*dx + dy*dy + dz*dz);
}

extern const Vector3 kZeroVector;










#endif //_VECTOR_3_H_
