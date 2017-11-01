#pragma once
#include "vec2.h"
#include "Transform.h"
#include "sfwdraw.h"

class Sprite 
{
public:
	int handle;
	vec2 dim;
	vec2 offset;

	Sprite(int a_handle =-1, int width=1, int height =1) :	handle(a_handle),
													dim{ (float)width, (float)height },
													offset{ 0,0 } 
	{
	
	}

	void draw(const Transform &t, const mat3 &cam = mat3::identity()) 
	{
		mat3 M = cam * t.getGlobalTransform() * translate(offset) * scale(dim);

		//M = translate(vec2{ 400,300 }) * scale(vec2{ 20,20 });
		
		sfw::drawTextureMatrix3(handle, 0, WHITE, M.m);
	}
};