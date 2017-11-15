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

bool doCollision(player &pooper, wall b)
{
	Collision hit = intersect_AABB(pooper.c.getGlobalBox(pooper.t), b.c.getGlobalBox(b.t));

	if (hit.penetrationDepth > 0)
	{
		static_resolution(pooper.t.position, pooper.rb.velocity, hit, 0.5f);
		return true;
	}

	return false;
}

bool doCollision(player &pooper, checkpoint &b)
{
	Collision hit = intersect_AABB(pooper.c.getGlobalBox(pooper.t), b.c.getGlobalBox(b.t));

	if (hit.penetrationDepth > 0)
	{
		static_resolution(pooper.t.position, pooper.rb.velocity, hit, 0.5f);
		return true;
	}

	return false;
}

bool doCollision(player &pooper, grass b)
{
	Collision hit = intersect_AABB(pooper.c.getGlobalBox(pooper.t), b.c.getGlobalBox(b.t));

	if (hit.penetrationDepth > 0)
	{
		pooper.inGrass = true;
		return true;
	}
	return false;
}

bool doCollision(player &pooper, checkpointTrigger &b/*, checkpointTrigger past*/)
{
	Collision hit = intersect_AABB(pooper.c.getGlobalBox(pooper.t), b.c.getGlobalBox(b.t));

	if (hit.penetrationDepth > 0)
	{
		b.isTriggered = true;
		b.connection2.isTriggered = true;
		b.connection1.isTriggered = true;
		/*past.isTriggered = false;
		past.connection1.isTriggered = false;
		past.connection2.isTriggered = false;*/
		return true;
	}
	return false;
}

int main()
{
	sfw::initContext(1280, 720, "Shippy Does The Thing");

	//background
	background bg;
	bg.sprite = sfw::loadTextureMap("../res/racetrack.png");
	bg.t.dimension = vec2{ 1280,720 };
	bg.t.position = vec2{ 640,360 };
	
	//player
	player pooper;
	pooper.sprite = sfw::loadTextureMap("../res/up_arrow1600.png");
	pooper.t.dimension = vec2{ 15,15 };
	pooper.t.position = vec2{ 150,300 };
	pooper.c.box.extents = { .5,.5 };

	//wall
	wall obstacle;
	obstacle.sprite = sfw::loadTextureMap("../res/Zach3.png");
	obstacle.t.dimension = vec2{ 40,40 };
	obstacle.t.position = vec2{ 800,650 };
	obstacle.c.box.extents = { .5,.5 };

	//Grass
	//center
	grass g1;
	g1.t.dimension = vec2{ 475,100 };
	g1.t.position = vec2{ 670,380 };
	g1.c.box.extents = { 1,1 };
	grass g2;
	g2.t.dimension = vec2{ 100,15 };
	g2.t.position = vec2{ 1030,485 };
	g2.c.box.extents = { 1,1 };
	grass g3;
	g3.t.dimension = vec2{ 250, 100 };
	g3.t.position = vec2{ 450,470 };
	g3.c.box.extents = { 1,1 };
	grass g4;
	g4.t.dimension = vec2{ 230, 100 };
	g4.t.position = vec2{ 840,270 };
	g4.c.box.extents = { 1,1 };
	//leftwall
	grass g5;
	g5.t.dimension = vec2{ 40,720 };
	g5.t.position = vec2{ 20,360 };
	g5.c.box.extents = { 1,1 };
	grass g6;
	g6.t.dimension = vec2{ 70,70 };
	g6.t.position = vec2{ 35,685 };
	g6.c.box.extents = { 1,1 };
	//topwall
	grass g7;
	g7.t.dimension = vec2{ 1280,25 };
	g7.t.position = vec2{ 640,705 };
	g7.c.box.extents = { 1,1 };
	grass g8;
	g8.t.dimension = vec2{ 75,100 };
	g8.t.position = vec2{ 890,670 };
	g8.c.box.extents = { 1,1 };
	grass g9;
	g9.t.dimension = vec2{ 200,70 };
	g9.t.position = vec2{ 1100,670 };
	g9.c.box.extents = { 1,1 };
	grass g10;
	g10.t.dimension = vec2{ 30,720 };
	g10.t.position = vec2{ 1270,360 };
	g10.c.box.extents = { 1,1 };
	grass g11;
	g11.t.dimension = vec2{ 1280,40 };
	g11.t.position = vec2{ 640, 10};
	g11.c.box.extents = { 1,1 };
	grass g12;
	g12.t.dimension = vec2{ 70,130 };
	g12.t.position = vec2{ 430, 50 };
	g12.c.box.extents = { 1,1 };
	grass g13;
	g13.t.dimension = vec2{ 60,130 };
	g13.t.position = vec2{ 260, 350 };
	g13.c.box.extents = { 1,1 };

	//checkpoints
	checkpoint cp11;
	cp11.t.dimension = vec2{ 10,10 };
	cp11.t.position = vec2{ 70,320 };
	cp11.c.box.extents = { 0.5,0.5 };
	cp11.sprite1 = sfw::loadTextureMap("../res/Lightpost1.png");
	cp11.sprite2 = sfw::loadTextureMap("../res/Lightpost2.png");
	cp11.isTriggered = false;
	checkpoint cp12;
	cp12.t.dimension = vec2{ 10,10 };
	cp12.t.position = vec2{ 200,320 };
	cp12.c.box.extents = { 0.5,0.5 };
	cp12.sprite1 = sfw::loadTextureMap("../res/Lightpost1.png");
	cp12.sprite2 = sfw::loadTextureMap("../res/Lightpost2.png");
	cp12.isTriggered = false;
	checkpointTrigger cp1;
	cp1.t.dimension = vec2{ 130,10 };
	cp1.t.position = vec2{ 135,320 };
	cp1.c.box.extents = { 0.5,0.5 };
	cp1.isTriggered = false;

	cp1.connection1 = cp11;
	cp1.connection2 = cp12;


	while (sfw::stepContext()) 
	{
		float dt = sfw::getDeltaTime();
		
		pooper.update();

		pooper.inGrass = false;

		//draw background
		bg.sprite.draw(bg.t);

		//draw player
		pooper.sprite.draw(pooper.t);
		drawAABB(pooper.c.getGlobalBox(pooper.t), MAGENTA);

		//draw wall
		obstacle.sprite.draw(obstacle.t);
		drawAABB(obstacle.c.getGlobalBox(obstacle.t), RED);

		//draw checkpoints
		cp1.connection1.Draw();
		drawAABB(cp11.c.getGlobalBox(cp11.t), YELLOW);
		cp1.connection2.Draw();
		drawAABB(cp12.c.getGlobalBox(cp12.t), YELLOW);
		drawAABB(cp1.c.getGlobalBox(cp1.t), YELLOW);

		//draw Grass AABB (development)
		//drawAABB(g1.c.getGlobalBox(g1.t), BLUE);
		//drawAABB(g2.c.getGlobalBox(g2.t), BLUE);
		//drawAABB(g3.c.getGlobalBox(g3.t), BLUE);
		//drawAABB(g4.c.getGlobalBox(g4.t), BLUE);
		//drawAABB(g5.c.getGlobalBox(g5.t), BLUE);
		//drawAABB(g6.c.getGlobalBox(g6.t), BLUE);
		//drawAABB(g7.c.getGlobalBox(g7.t), BLUE);
		//drawAABB(g8.c.getGlobalBox(g8.t), BLUE);
		//drawAABB(g9.c.getGlobalBox(g9.t), BLUE);
		//drawAABB(g10.c.getGlobalBox(g10.t), BLUE);
		//drawAABB(g11.c.getGlobalBox(g11.t), BLUE);
		//drawAABB(g12.c.getGlobalBox(g12.t), BLUE);
		//drawAABB(g13.c.getGlobalBox(g13.t), BLUE);


		//player movement
		pooper.controller.poll(pooper.rb, pooper.t);
		pooper.rb.integrate(pooper.t, dt);

		//screen edge collision
		if (pooper.t.position.x >= 1280 + 7.5)
		{
			pooper.t.position.x = 1280 - 1;
			pooper.rb.force.x += -1 * pooper.rb.velocity.x * 100;
		}
		else if (pooper.t.position.x <= 0 - 7.5)
		{
			pooper.t.position.x = 0 + 1;
			pooper.rb.force.x += -1 * pooper.rb.velocity.x * 100;
		}
		if (pooper.t.position.y <= 0 - 7.5) 
		{
			pooper.t.position.y = 0 + 1;
			pooper.rb.force.y += -1 * pooper.rb.velocity.y * 100;
		}
		else if (pooper.t.position.y >= 720 + 7.5) 
		{
			pooper.t.position.y = 720 - 1;
			pooper.rb.force.y += -1 * pooper.rb.velocity.y * 100;
		}

		//obstacle collision
		doCollision(pooper, obstacle);
		doCollision(pooper, g1);
		doCollision(pooper, g2);
		doCollision(pooper, g3);
		doCollision(pooper, g4);
		doCollision(pooper, g5);
		doCollision(pooper, g6);
		doCollision(pooper, g7);
		doCollision(pooper, g8);
		doCollision(pooper, g9);
		doCollision(pooper, g10);
		doCollision(pooper, g11);
		doCollision(pooper, g12);
		doCollision(pooper, g13);
		doCollision(pooper, cp11);
		doCollision(pooper, cp12);
		doCollision(pooper, cp1);
	}

	sfw::termContext();
}