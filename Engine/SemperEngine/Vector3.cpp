#include "Vector3.h"
#include "Mathz.h"

namespace SemperEngine {

	Vector3 Vector3::left = Vector3(1, 0, 0);

	Vector3 Vector3::up = Vector3(0, 1, 0);

	Vector3 Vector3::forward = Vector3(0, 0, 1);

	Vector3 Vector3::Cross(Vector3 a, Vector3 b)
	{
		return Vector3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
	}
	float Vector3::Dot(Vector3 a, Vector3 b)
	{
		return a.x*b.x + a.y*b.y + a.z*b.z;
	}

	Vector3::Vector3()
	{
		x = 0; y = 0; z = 0;
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

	Vector3 Vector3::Normalize()
	{
		auto r = Math::Max(x, y);
		r = Math::Max(r, z);
		return Vector3(x / r, y / r, z / r);
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
}