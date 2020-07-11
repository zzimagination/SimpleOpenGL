#include "Vector2.h"
#include "Vector3.h"

Vector3::Vector3()
{
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(Vector2 v)
{
	this->x = v.x;
	this->y = v.y;
}

Vector3 Vector3::operator-()
{
	return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator+(const Vector3 b)
{
	float x = this->x + b.x;
	float y = this->y + b.y;
	float z = this->z + b.z;
	return Vector3(x, y, z);
}

Vector3 Vector3::operator-(const Vector3 b)
{
	float x = this->x - b.x;
	float y = this->y - b.y;
	float z = this->z - b.z;
	return Vector3(x, y, z);
}

Vector3::operator Vector2()
{
	return Vector2(x, y);
}
