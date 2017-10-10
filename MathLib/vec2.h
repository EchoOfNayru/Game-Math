#pragma once

union vec2 
{
	//access by array
	float v[2];

	//access by individual component
	struct { float x, y; };
};

// arithmatic operators

vec2 operator+(const vec2 &lhs, const vec2 &rhs);

vec2 operator-(const vec2 &lhs, const vec2 &rhs);

vec2 operator*(const vec2 &lhs, int rhs);

vec2 operator*(int lhs, const vec2 &rhs);

vec2 operator/(const vec2 &lhs, int rhs);

//compound assignment operators

vec2 &operator+=(vec2 &lhs, const vec2 &rhs);

vec2 &operator-=(vec2 &lhs, const vec2 &rhs);

vec2 &operator*=(vec2 &lhs, int rhs);

vec2 &operator/=(vec2 &lhs, int rhs);

//logical operators

bool operator==(const vec2 &lhs, const vec2 &rhs);

bool operator!=(const vec2 &lhs, const vec2 &rhs);