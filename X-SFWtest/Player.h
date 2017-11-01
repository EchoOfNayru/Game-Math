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
	Collider collider;
	Controller controller;
	Sprite sprite;
};

class Wall 
{
	Transform t;
	Collider collider;
	Sprite sprite;
};