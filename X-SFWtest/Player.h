#pragma once

#include "RgidBody.h"
#include "Transform.h"
#include "Collider.h"
#include "Controller.h"
#include "Sprite.h"

class player
{
public:
	Transform t;
	Rigidbody rb;
	Collider c;
	Controller controller;
	Sprite sprite;

	bool inGrass;

	void update()
	{
		if (inGrass) rb.drag = 3;
		else rb.drag = 0.5f;
	}
};

class wall 
{
public:
	Transform t;
	Collider c;
	Sprite sprite;
};

class background 
{
public:
	Sprite sprite;
	Transform t;
};

class grass 
{
public:
	Transform t;
	Collider c;
};

class checkpoint 
{
public:
	Transform t;
	Collider c;
	Sprite sprite1;
	Sprite sprite2;
	bool isTriggered;

	void Draw() 
	{
		if (isTriggered) 
		{
			sprite2.draw(t);
		}
		else 
		{
			sprite1.draw(t);
		}
	}
};

class checkpointTrigger 
{
public:
	Transform t;
	Sprite sprite;
	Collider c;
	bool isTriggered;
	checkpoint connection1;
	checkpoint connection2;
};