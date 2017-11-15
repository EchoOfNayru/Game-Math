 #pragma once
#include "vec2.h"
#include "Transform.h"

class Rigidbody
{
public:
	vec2 velocity,
		acceleration,
		force,
		impulse;

	float mass,
		drag,
		angularVelocity,
		angularAcceleration,
		torque,
		angularDrag;

	Rigidbody() : velocity{ 0,0 },
		acceleration{ 0,0 },
		force{ 0,0 },
		impulse{ 0,0 },
		mass(1),
		drag(0.5f),
		angularVelocity(0),
		angularAcceleration(0),
		torque(0),
		angularDrag(.5f)
	{

	}



	void integrate(Transform &T, float dt)
	{
		acceleration = force / mass;
		velocity		+= acceleration * dt + impulse / mass;
		T.position		+= velocity * dt;
		impulse =  { 0,0 };
		force = (velocity * -1) * drag;

		angularAcceleration = torque / mass;
		angularVelocity += angularAcceleration *dt;
		T.angle += angularVelocity *dt;
		torque = -angularVelocity * angularDrag;
	}
};