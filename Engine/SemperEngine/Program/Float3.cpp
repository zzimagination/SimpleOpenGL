#include "Float3.h"
#include "Mathz.h"

namespace SemperEngine {

	const Float3 Float3::right = Float3(1, 0, 0);

	const Float3 Float3::up = Float3(0, 1, 0);

	const Float3 Float3::forward = Float3(0, 0, 1);

	Float3 Float3::Cross(const Float3& a, const Float3& b)
	{
		return Float3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
	}

	float Float3::Dot(const Float3& a, const Float3& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	Float3::Float3()
	{
		x = 0; y = 0; z = 0;
	}

	Float3::Float3(const float& x, const float& y, const float& z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Float3::Float3(const Float2& value)
	{
		this->x = value.x;
		this->y = value.y;
		this->z = 0;
	}

	Float3 Float3::Normalize()
	{
		auto r = Math::Max(x, y);
		r = Math::Max(r, z);
		return Float3(x / r, y / r, z / r);
	}

	float Float3::Length()
	{
		float l1 = x * x + y * y + z * z;
		float l2 = Math::Sqrt(l1);
		return l2;
	}

	Float3 Float3::operator-()
	{
		return Float3(-x, -y, -z);
	}

	Float3 Float3::operator+(const Float3& b)
	{
		float x = this->x + b.x;
		float y = this->y + b.y;
		float z = this->z + b.z;
		return Float3(x, y, z);
	}

	Float3 Float3::operator-(const Float3& b)
	{
		float x = this->x - b.x;
		float y = this->y - b.y;
		float z = this->z - b.z;
		return Float3(x, y, z);
	}
	Float3 Float3::operator*(const float& right)
	{
		return Float3(this->x * right, this->y * right, this->z * right);
	}

	Float3 Float3::operator/(const float& right)
	{
		return Float3(this->x / right, this->y / right, this->z / right);
	}

	Float3 operator*(const float& left, const Float3& right)
	{
		return Float3(right.x * left, right.y * left, right.z * left);
	}
}