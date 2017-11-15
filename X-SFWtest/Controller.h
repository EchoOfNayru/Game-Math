#pragma once

#include "RgidBody.h"
#include "Transform.h"
#include "sfwdraw.h"


class Controller 
{

public:
	void poll(Rigidbody &rb, const Transform &t) 
	{
		if (sfw::getKey('W'))rb.force += t.getGlobalTransform()[1].xy * 10;
		if (sfw::getKey('A'))rb.torque += 360;
		if (sfw::getKey('D'))rb.torque -= 360;

		if (sfw::getKey(' '))
		{
			rb.force += -1 * rb.velocity * 2;
			rb.torque += -rb.angularVelocity * 2;
		}
	}
};