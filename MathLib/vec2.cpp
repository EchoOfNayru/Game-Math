#include "vec2.h"
#include "mathutils.h"

#include <cmath>
#include <cfloat>


//access by index

float & vec2::operator[](unsigned idx)
{
	return v[idx];
}

float vec2::operator[](unsigned idx) const
{
	return v[idx];
}

//arithmatic operators

vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	return { lhs.x + rhs.x, lhs.y + rhs.y};
}

vec2 operator-(const vec2 & lhs, const vec2 & rhs)
{
	return { lhs.x - rhs.x, lhs.y - rhs.y};
}

vec2 operator*(const vec2 & lhs, float rhs)
{
	vec2 value;
	value.x = lhs.x * rhs;
	value.y = lhs.y * rhs;
	return value;
}

vec2 operator*(float lhs, const vec2 & rhs)
{
	vec2 value;
	value.x = rhs.x * lhs;
	value.y = rhs.y * lhs;
	return value;
}

vec2 operator/(const vec2 & lhs, float rhs)
{
	vec2 value;
	value.x = lhs.x / rhs;
	value.y = lhs.y / rhs;
	return value;
}

//compound assignment operators

vec2 & operator+=(vec2 & lhs, const vec2 & rhs)
{
	lhs = lhs + rhs;
	return lhs;
}

vec2 & operator-=(vec2 & lhs, const vec2 & rhs)
{
	lhs = lhs - rhs;
	return lhs;
}

vec2 & operator*=(vec2 & lhs, float rhs)
{
	lhs = lhs * rhs;
	return lhs;
}

vec2 & operator/=(vec2 & lhs, float rhs)
{
	lhs = lhs / rhs;
	return lhs;
}

//logical operators

bool operator==(const vec2 & lhs, const vec2 & rhs)
{
	const int qty = (sizeof(lhs.v) / sizeof(lhs.v[0]));
	for (int i = 0; i < qty; i++) 
	{
		if (std::abs(lhs.v[i] - rhs.v[i]) < FLT_EPSILON) 
		{
			return false;
		}
	}
	return true;
}

bool operator!=(const vec2 & lhs, const vec2 & rhs)
{
	const int qty = (sizeof(lhs.v) / sizeof(lhs.v[0]));
	for (int i = 0; i < qty; i++)
	{
		if (std::abs(lhs.v[i] - rhs.v[i]) < FLT_EPSILON)
		{
			return true;
		}
	}
	return false;
}

//subscript operator


//ultility functions

float Magnitude(const vec2 & v)
{
	float num1 = v.x * v.x;
	float num2 = v.y * v.y;
	float num3 = num1 + num2;
	num3 = sqrtf(num3);
	return num3;
}

vec2 Normal(const vec2 & v) 
{
	vec2 temp;
	float mag = abs(Magnitude(v));
	temp.x = v.x / mag;
	temp.y = v.y / mag;
	return temp;
}

vec2 Normalize(vec2 & v) 
{
	float mag = abs(Magnitude(v));
	v.x /= mag;
	v.y /= mag;
	return v;
}

float Dot(const vec2 & lhs,const vec2 & rhs) 
{
	float num1 = lhs.x * rhs.x;
	float num2 = lhs.y * rhs.y;
	float num3 = num1 + num2;
	return num3;
}

float Distance(const vec2 & lhs,const vec2 & rhs) 
{
	return Magnitude(lhs - rhs);
}

vec2 Perpendicular(const vec2 & v) 
{
	return vec2{ v.y, -v.x };
}

vec2 Lerp(const vec2 &s, const vec2 &e, float a) 
{
	return s + a* (e - s);
}

vec2 min(const vec2 &a, const vec2 &b)
{
	vec2 temp;
	temp.x = min(a.x, b.x);
	temp.y = min(a.y, b.y);

	return temp;
}

vec2 max(const vec2 &a, const vec2 &b)
{
	vec2 temp;
	temp.x = max(a.x, b.x);
	temp.y = max(a.y, b.y);

	return temp;
}


vec2 project(const vec2 & v, const vec2 & axis)
{
	return Dot(v, axis) * axis;
}

vec2 reflect(const vec2 & v, const vec2 & axis)
{
	return 2 * project(v, axis) - v;
}