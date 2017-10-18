#include "sfwdraw.h"
#include "vec2.h"
#include "mathutils.h"
#include "Transform.h"
#include "vec3.h"

int main() 
{
	sfw::initContext();

	Transform myTransform;
	myTransform.position = vec2{ 350,400 };
	myTransform.dimension = vec2{ 1,1 };
	myTransform.angle = 0;

	/*Transform myBaby;
	myBaby.position = vec2{ 10,10 };
	myBaby.dimension = { 1,1 };
	myBaby.angle = 0;
	myBaby.e_parent = &myTransform;*/

	while (sfw::stepContext()) 
	{
		float t = sfw::getTime();

		//myTransform.angle += 17 * t;

		DrawMatrix(myTransform.getGlobalTransform(), 30);
		//DrawMatrix(myBaby.getGlobalTransform(), 30);
	}

	sfw::termContext();
}