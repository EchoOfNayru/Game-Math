#include <iostream>
#include <math.h>

int Square(int x) 
{
	int y = x * x;
	return y;
}



































































































































































































































































































































int Double(int x) 
{
	int y = x * 2;
	return y;
}

int Cubed(int x) 
{
	int y = x * x * x;
	return y;
}

float DegreesToRadians(float x) 
{
	float y = x * (3.14 / 180);
	return y;
}

float RadiansToDegrees(float x) 
{
	float y = x * 180 / 3.14;
	return y;
}

float QFpos(float a, float b, float c) 
{
	float pos = (-b + sqrt(Square(b) - (4 * a*c))) / (2 * a);
	return pos;
}

float QFneg(float a, float b, float c) 
{
	float neg = (-b - sqrt(Square(b) - (4 * a*c))) / (2 * a);
	return neg;
}

void QuadraticFormula(float a, float b, float c) 
{
	std::cout << QFpos(a, b, c) << std::endl;
	std::cout << (a, b, c) << std::endl;
}

float BasicQuadratic(int x) 
{
	float y = Square(x) + (2 * x) - 7;
	return y;
}

int main() 
{
	QuadraticFormula(3, 7, 9);
	while (true) 
	{
		
	}
}