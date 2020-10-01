#include "Vector2.h"

namespace SemperEngine {

	float Vector2::Dot(Vector2 a, Vector2 b)
	{
		return (a.x*b.x + a.y*b.y);
	}
	Vector2::Vector2()
	{
		x = 0; y = 0;
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
}