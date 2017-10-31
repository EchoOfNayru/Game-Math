#include "sfwdraw.h"
#include "vec2.h"
#include "mathutils.h"
#include "Transform.h"
#include "vec3.h"
#include "Rgidbody.h"

int main() 
{
	sfw::initContext();

	Transform transform;
	Rigidbody rigidbody;

	transform.position = vec2{ 400,300 };

	while (sfw::stepContext()) 
	{
		float dt = sfw::getDeltaTime();

		//rigidbody.force = { 0,-25 };
		if (sfw::getKey('W'))rigidbody.force += transform.getGlobalTransform()[1].xy * 100;
		if (sfw::getKey('A'))rigidbody.torque += 360;
		if (sfw::getKey('D'))rigidbody.torque -= 360;

		if (sfw::getKey(' ')) 
		{
			rigidbody.force += -1 * rigidbody.velocity * 20;
			rigidbody.torque += -rigidbody.angularVelocity * 20;
		}

		rigidbody.integrate(transform, dt);
		DrawMatrix(transform.getGlobalTransform(), 40);
	}

	sfw::termContext();
}