#include "Vector2.h"
#include "Vector3.h"

Vector3 Vector3::left = Vector3(1, 0, 0);
Vector3 Vector3::up = Vector3(0, 1, 0);
Vector3 Vector3::forward = Vector3(0, 0, 1);

Vector3::Vector3()
{
}

Vector3::Vector3(const Vector3 & a)
{
	this->x = a.x;
	this->y = a.y;
	this->z = a.z;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3 Vector3::operator-()
{
	return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator+(const Vector3& b)
{
	float x = this->x + b.x;
	float y = this->y + b.y;
	float z = this->z + b.z;
	return Vector3(x, y, z);
}

Vector3 Vector3::operator-(const Vector3& b)
{
	float x = this->x - b.x;
	float y = this->y - b.y;
	float z = this->z - b.z;
	return Vector3(x, y, z);
}
