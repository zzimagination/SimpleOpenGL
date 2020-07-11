#include "Vector4.h"
#include "Vector3.h"

Vector4::Vector4()
{
}

Vector4::Vector4(float x, float y, float z, float w = 1)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4 Vector4::operator-()
{
	return Vector4(-x, -y, -z, -w);
}

Vector4 Vector4::operator+(const Vector4& b)
{
	float x = this->x + b.x;
	float y = this->y + b.y;
	float z = this->z + b.z;
	float w = this->w + b.w;
	return Vector4(x, y, z, w);
}

Vector4 Vector4::operator-(const Vector4& b)
{
	float x = this->x - b.x;
	float y = this->y - b.y;
	float z = this->z - b.z;
	float w = this->w - b.w;
	return Vector4(x, y, z, w);
}

Vector4::operator Vector3()
{
	return Vector3(x, y, z);
}
