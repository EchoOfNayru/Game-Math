#include "mat3.h"

vec3 & mat3::operator[](size_t idx)
{
	return c[idx];
}

const vec3 & mat3::operator[](size_t idx) const
{
	return c[idx];
}

mat3 mat3::identity()
{
	return mat3();
}

mat3 operator+(const mat3 & lhs, const mat3 & rhs)
{
	return mat3();
}

mat3 operator-(const mat3 & lhs, const mat3 & rhs)
{
	return mat3();
}

mat3 operator*(const mat3 & lhs, const mat3 & rhs)
{
	return mat3();
}

mat3 operator*(const mat3 & lhs, const vec3 & rhs)
{
	return mat3();
}

mat3 transpose(const mat3 & A)
{
	mat3 result;

	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++)
		{
			result.mm[i][j] = A.mm[j][i];
		}
	}

	return result;
}


float determinant(const mat3 & A)
{
	return 0.0f;
}

mat3 inverse(const mat3 & A)
{
	return mat3();
}
