#include "Vector2.h"
#include "Vector3.h"

Vector2::Vector2()
{
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2 Vector2::operator-()
{
	return Vector2(-x, -y);
}

Vector2 Vector2::operator+(const Vector2& b)
{
	float x = this->x + b.x;
	float y = this->y + b.y;
	return Vector2(x, y);
}

Vector2 Vector2::operator-(const Vector2& b)
{
	float x = this->x - b.x;
	float y = this->y - b.y;
	return Vector2(x, y);
}
