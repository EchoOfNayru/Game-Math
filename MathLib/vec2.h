#pragma once

union vec2 
{
	//access by array
	float v[2];

	//access by individual component
	struct { float x, y; };

	//access to vec2 by index
	float &operator[](unsigned idx);
	float operator[](unsigned idx) const;
};

// arithmatic operators

vec2 operator+(const vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 &lhs, const vec2 &rhs);
vec2 operator*(const vec2 &lhs, float rhs);
vec2 operator*(float lhs, const vec2 &rhs);
vec2 operator/(const vec2 &lhs, float rhs);

//compound assignment operators

vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
vec2 &operator-=(vec2 &lhs, const vec2 &rhs);
vec2 &operator*=(vec2 &lhs, float rhs);
vec2 &operator/=(vec2 &lhs, float rhs);

//logical operators

bool operator==(const vec2 &lhs, const vec2 &rhs);
bool operator!=(const vec2 &lhs, const vec2 &rhs);

// utility operators

float Magnitude(const vec2 & v);
vec2 Normal(const vec2 & v);
vec2 Normalize(vec2 & v);
float Dot(const vec2 & lhs, const vec2 & rhs);
float Distance(const vec2 & lhs, const vec2 & rhs);
vec2 Perpendicular(const vec2 & v);
vec2 Lerp(const vec2 &s, const vec2 &e, float a);
vec2 min(const vec2 &a, const vec2 &b);
vec2 max(const vec2 &a, const vec2 &b);