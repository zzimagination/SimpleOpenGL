#include "Float2.h"

namespace SemperEngine {

	float Float2::Dot(const Float2& a, const Float2& b)
	{
		return (a.x * b.x + a.y * b.y);
	}
	Float2::Float2()
	{
		x = 0; y = 0;
	}

	Float2::Float2(const float& x, const float& y)
	{
		this->x = x;
		this->y = y;
	}

	Float2 Float2::operator-()
	{
		return Float2(-x, -y);
	}

	Float2 Float2::operator+(const Float2& b)
	{
		float x = this->x + b.x;
		float y = this->y + b.y;
		return Float2(x, y);
	}

	Float2 Float2::operator-(const Float2& b)
	{
		float x = this->x - b.x;
		float y = this->y - b.y;
		return Float2(x, y);
	}

	Float2 Float2::operator*(const float& b)
	{
		return Float2(this->x * b, this->y * b);
	}

	Float2 Float2::operator/(const float& b)
	{
		return Float2(this->x / b, this->y / b);
	}

	Float2 operator*(const float& left, const Float2& right)
	{
		return Float2(right.x * left, right.y * left);
	}
}