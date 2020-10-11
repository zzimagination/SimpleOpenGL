#include "Color.h"

namespace SemperEngine
{
	Color Color::FromHEX32(long hex)
	{
		auto r = (hex & 0xff000000) >> 24;
		auto g = (hex & 0x00ff0000) >> 16;
		auto b = (hex & 0x0000ff00) >> 8;
		auto a = (hex & 0x000000FF);
		return Color(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
	}
	Color Color::FromHEX24(long hex)
	{
		auto r = (hex & 0xff0000) >> 16;
		auto g = (hex & 0x00ff00) >> 8;
		auto b = (hex & 0x0000ff);
		return Color(r / 255.0f, g / 255.0f, b / 255.0f, 1);
	}
	Color::Color()
	{
		_data = Vector4(1, 1, 1, 1);
	}
	Color::Color(Vector4 value)
	{
		_data = value;
	}
	Color::Color(Vector3 value)
	{
		_data = Vector4(value.x, value.y, value.z, 1);
	}
	Color::Color(float r, float g, float b, float a)
	{
		_data = Vector4(r, g, b, a);
	}
	float Color::R()
	{
		return _data.x;
	}
	float Color::G()
	{
		return _data.y;
	}
	float Color::B()
	{
		return _data.z;
	}
	float Color::A()
	{
		return _data.w;
	}
	Color& Color::operator=(const Vector4& right)
	{
		this->_data = right;
		return *this;
	}
	Color& Color::operator=(const Vector3& right)
	{
		this->_data = Vector4(right.x, right.y, right.z, 1);
		return *this;
	}
	Color& Color::operator=(const Color& right)
	{
		this->_data = right._data;
		return *this;// TODO: 在此处插入 return 语句
	}
}