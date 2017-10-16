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
bool operator!=(const vec3 &lhs, const vec3 &rhs);

// utility functions

float Magnitude(const vec3 &v);
vec3 Normal(const vec3 &v);
vec3 Normalize(vec3 &v);
float Dot(const vec3 &lhs, const vec3 &rhs);
float Distance(const vec3 &lhs, const vec3 &rhs);
vec3 Min(const vec3 &lhs, const vec3 &rhs);
vec3 Max(const vec3 &lhs, const vec3 &rhs);
vec3 Clamp(const vec3 &v, const vec3 &min, const vec3 &max);