#include "vec3.h"
#include "mathutils.h"

#include<cmath>
#include<cfloat>

float & vec3::operator[](unsigned idx)
{
	return v[idx];
}

float vec3::operator[](unsigned idx) const
{
	return v[idx];
}

// arithmatic ops

vec3 operator+(const vec3 & lhs, const vec3 & rhs)
{
	vec3 result;

	for (int i = 0; i < 3; i++) 
	{
		result.v[i] = lhs.v[i] + rhs.v[i];
	}

	return result;
}

vec3 operator-(const vec3 &lhs, const vec3 &rhs) 
{
	vec3 result;

	for (int i = 0; i < 3; i++)
	{
		result.v[i] = lhs.v[i] - rhs.v[i];
	}

	return result;
}

vec3 operator*(const vec3 &lhs, float rhs) 
{
	vec3 result;

	for (int i = 0; i < 3; i++)
	{
		result.v[i] = lhs.v[i] * rhs;
	}

	return result;
}

vec3 operator*(float lhs, const vec3 &rhs) 
{
	vec3 result;

	for (int i = 0; i < 3; i++)
	{
		result.v[i] = lhs * rhs.v[i];
	}

	return result;
}

vec3 operator/(const vec3 &lhs, float rhs) 
{
	vec3 result;

	for (int i = 0; i < 3; i++)
	{
		result.v[i] = lhs.v[i] / rhs;
	}

	return result;
}

//compound assignment ops

vec3 operator+=(vec3 & lhs, const vec3 & rhs)
{
	lhs = lhs + rhs;
	return lhs;
}

vec3 operator-=(vec3 & lhs, const vec3 & rhs)
{
	lhs = lhs - rhs;
	return lhs;
}

vec3 operator*=(vec3 & lhs, float rhs)
{
	lhs = lhs * rhs;
	return lhs;
}

vec3 operator/=(vec3 & lhs, float rhs)
{
	lhs = lhs / rhs;
	return lhs;
}

//logical ops

bool operator==(const vec3 & lhs, const vec3 & rhs)
{
	if (abs(lhs.x - rhs.x) < FLT_EPSILON &&
		abs(lhs.y - rhs.y) < FLT_EPSILON &&
		abs(lhs.z - rhs.z) < FLT_EPSILON) 
	{
		return false;
	}
	return true;
}

bool operator!=(const vec3 & lhs, const vec3 & rhs)
{
	if (abs(lhs.x - rhs.x) > FLT_EPSILON &&
		abs(lhs.y - rhs.y) > FLT_EPSILON &&
		abs(lhs.z - rhs.z) > FLT_EPSILON)
	{
		return false;
	}
	return true;
}

//utility functions

float Magnitude(const vec3 &v)
{
	return sqrtf(Square(v.x) + Square(v.y) + Square(v.z));
}

vec3 Normal(const vec3 &v)
{
	vec3 result;
	float mag = abs(Magnitude(v));
	result.x = v.x / mag;
	result.y = v.y / mag;
	result.z = v.z / mag;
	return result;
}

vec3 Normalize(vec3 &v)
{
	float mag = abs(Magnitude(v));
	v.x /= mag;
	v.y /= mag;
	v.z /= mag;
	return v;
}

float Dot(const vec3 &lhs, const vec3 &rhs)
{
	return ((lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.x * rhs.x));
}

float Distance(const vec3 &lhs, const vec3 &rhs)
{
	return Magnitude(lhs - rhs);
}

vec3 Min(const vec3 &lhs, const vec3 &rhs)
{
	vec3 result;
	result.x = lhs.x > rhs.x ? lhs.x : rhs.x;
	result.y = lhs.y > rhs.y ? lhs.y : rhs.y;
	result.z = lhs.z > rhs.z ? lhs.z : rhs.z;
	return result;
}

vec3 Max(const vec3 &lhs, const vec3 &rhs)
{
	vec3 result;
	result.x = max(lhs.x, rhs.x);
	result.y = max(lhs.y, rhs.y);
	result.z = max(lhs.z, rhs.z);
	return result;
}

vec3 Clamp(const vec3 & v, const vec3 & min, const vec3 & max)
{
	vec3 result;
	if (v.x > max.x || v.x < min.x) 
	{
		if (v.x > max.x) 
		{
			result.x = max.x;
		}
		else 
		{
			result.x = min.x;
		}
	}
	else 
	{
		result.x = v.x;
	}

	if (v.y > max.y || v.y < min.y)
	{
		if (v.y > max.y)
		{
			result.y = max.y;
		}
		else
		{
			result.y = min.y;
		}
	}
	else
	{
		result.y = v.y;
	}

	if (v.z > max.z || v.z < min.z)
	{
		if (v.z > max.z)
		{
			result.z = max.z;
		}
		else
		{
			result.z = min.z;
		}
	}
	else
	{
		result.z = v.z;
	}
	return result;
}
