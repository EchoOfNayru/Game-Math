#include "vec2.h"

#include <cmath>
#include <cfloat>

//arithmatic operators

vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	return { lhs.x + rhs.x, lhs.y + rhs.y};
}

vec2 operator-(const vec2 & lhs, const vec2 & rhs)
{
	return { lhs.x - rhs.x, lhs.y - rhs.y};
}

vec2 operator*(const vec2 & lhs, int rhs)
{
	vec2 value;
	value.x = lhs.x * rhs;
	value.y = lhs.y * rhs;
	return value;
}

vec2 operator*(int lhs, const vec2 & rhs)
{
	vec2 value;
	value.x = rhs.x * lhs;
	value.y = rhs.y * lhs;
	return value;
}

vec2 operator/(const vec2 & lhs, int rhs)
{
	vec2 value;
	value.x = lhs.x / rhs;
	value, y = lhs.y / rhs;
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

vec2 & operator*=(vec2 & lhs, int rhs)
{
	lhs = lhs * rhs;
	return lhs;
}

vec2 & operator/=(vec2 & lhs, int rhs)
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

float Magnitude(vec2 & lhs, vec2 & rhs)
{
	return 0.0f;
}
