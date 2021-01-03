#include "Float4.h"

namespace SemperEngine {

	Float4::Float4()
	{
		x = 0; y = 0; z = 0; w = 0;
	}

	Float4::Float4(const float& x, const float& y, const float& z, const float& w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Float4::Float4(const Float3& value)
	{
		this->x = value.x;
		this->y = value.y;
		this->z = value.z;
		this->w = 0;
	}

	Float4::Float4(const Float2& value)
	{
		this->x = value.x;
		this->y = value.y;
		this->z = 0;
		this->w = 0;
	}

	Float4 Float4::operator-()
	{
		return Float4(-x, -y, -z, -w);
	}

	Float4 Float4::operator+(const Float4& b)
	{
		float x = this->x + b.x;
		float y = this->y + b.y;
		float z = this->z + b.z;
		float w = this->w + b.w;
		return Float4(x, y, z, w);
	}

	Float4 Float4::operator-(const Float4& b)
	{
		float x = this->x - b.x;
		float y = this->y - b.y;
		float z = this->z - b.z;
		float w = this->w - b.w;
		return Float4(x, y, z, w);
	}

	float Float4::operator*(const Float4& b)
	{
		return this->x * b.x + this->y * b.y + this->z * b.z + this->w * b.w;
	}
}