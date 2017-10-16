#include "vec3.h"

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
