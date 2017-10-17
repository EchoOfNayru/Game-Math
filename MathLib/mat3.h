#pragma once

#include "vec3.h"

union mat3 
{
	float m[9];
	float mm[3][3];
	vec3 c[3];

	vec3 &operator[](size_t idx); //column accessor
	const vec3 &operator[](size_t idx) const; 

	static mat3 identity(); //creates and returns an identity matrix.
};

mat3 operator+(const mat3 &lhs, const mat3 &rhs);
mat3 operator-(const mat3 &lhs, const mat3 &rhs);

mat3 operator*(const mat3 &lhs, const mat3 &rhs);
mat3 operator*(const mat3 &lhs, const vec3 &rhs);

mat3 transpose(const mat3 &A);

float determinant(const mat3 &A);
mat3 inverse(const mat3 &A);