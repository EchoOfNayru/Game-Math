#include "Shapes.h"
#include <cmath>

circle operator*(const mat3 & M, const circle & C)
{
	circle ret = C;

	ret.position = (M * vec3{ C.position.x, C.position.y, 1.f }).xy;

	vec2 scale;
	scale.x = Magnitude(M[0].xy);
	scale.y = Magnitude(M[1].xy);

	ret.radius *= fmaxf(scale.x, scale.y);

	return ret;
}

AABB operator*(const mat3 & M, const AABB & B)
{
	return AABB();
}
