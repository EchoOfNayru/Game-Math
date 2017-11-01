#include "sfwdraw.h"
#include "vec2.h"
#include "mathutils.h"
#include "Transform.h"
#include "vec3.h"
#include "Rgidbody.h"
#include "DrawShape.h"
#include "Collider.h"
#include "Player.h"
#include "Collision.h"

#include <cmath>
#include <string>
#include <cstring>
#include <cassert>

int main() 
{
	sfw::initContext();


	player pooper;

	pooper.sprite = sfw::loadTextureMap("../res/Zach3.png");
	pooper.t.dimension = vec2{ 48,48 };
	pooper.t.position = vec2{ 400,300 };
	pooper.collider.box.extents = { .5,.5 };

	while (sfw::stepContext()) 
	{
		float dt = sfw::getDeltaTime();
		
		pooper.controller.poll(pooper.rb, pooper.t);

		pooper.rb.integrate(pooper.t, dt);

		pooper.sprite.draw(pooper.t);

		drawAABB(pooper.collider.getGlobalBox(pooper.t), MAGENTA);
	}

	sfw::termContext();
}