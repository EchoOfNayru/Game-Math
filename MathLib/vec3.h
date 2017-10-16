#pragma once
#include "vec2.h"

union vec3 
{
	//access by array
	float v[3];

	//access by individual compnent
	struct {float x, y, z};

	//access to vec3 by index
	float &operator[](unsigned idx);
	float operator[](unsigned idx) const;

	//access as vec2
	vec2 xy;
};

//arithmatic operators

vec3 operator+(const vec3 &lhs, const vec3 &rhs);
vec3 operator-(const vec3 &lhs, const vec3 &rhs);
vec3 operator*(const vec3 &lhs, float rhs);
vec3 operator*(float lhs, const vec3 &rhs);
vec3 operator/(const vec3 &lhs, float rhs);

//compound assignment operators

vec3 operator+=(vec3 &lhs, const vec3 &rhs);
vec3 operator-=(vec3 &lhs, const vec3 &rhs);
vec3 operator*=(vec3 &lhs, float rhs);
vec3 operator/=(vec3 &lhs, float rhs);

// logical ops

bool operator==(const vec3 &lhs, const vec3 &rhs);