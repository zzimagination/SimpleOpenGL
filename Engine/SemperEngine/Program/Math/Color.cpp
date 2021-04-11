#include "Color.h"

namespace SemperEngine
{
	Color Color::FromHEX32(const long& hex)
	{
		auto r = (unsigned char)((hex & 0xff000000) >> 24);
		auto g = (unsigned char)((hex & 0x00ff0000) >> 16);
		auto b = (unsigned char)((hex & 0x0000ff00) >> 8);
		auto a = (unsigned char)((hex & 0x000000FF));
		return Color32(r, g, b, a);
	}

	Color Color::FromHEX24(const long& hex)
	{
		auto r = (unsigned char)((hex & 0xff0000) >> 16);
		auto g = (unsigned char)((hex & 0x00ff00) >> 8);
		auto b = (unsigned char)((hex & 0x0000ff));
		return Color32(r, g, b, 255);
	}

	Color Color::ColorFloat(const float& r, const float& g, const float& b, const float& a)
	{
		return Color(Float4(r, g, b, a));
	}

	Color Color::Color32(const ColorByte& r, const ColorByte& g, const ColorByte& b, const ColorByte& a)
	{
		Color c;
		c._r = r;
		c._g = g;
		c._b = b;
		c._a = a;
		return c;
	}

	Color Color::Black()
	{
		return Color::Color32(0,0,0);
	}

	Color Color::White()
	{
		return Color::Color32();
	}

	Color::Color()
	{
		_r = 255;
		_g = 255;
		_b = 255;
		_a = 255;
	}

	Color::Color(const Float4& value)
	{
		_r = (unsigned char)(value.x * 255);
		_g = (unsigned char)(value.y * 255);
		_b = (unsigned char)(value.z * 255);
		_a = (unsigned char)(value.w * 255);
	}

	Color::Color(const Float3& value)
	{
		_r = (unsigned char)(value.x * 255);
		_g = (unsigned char)(value.y * 255);
		_b = (unsigned char)(value.z * 255);
		_a = 255;
	}

	float Color::R()
	{
		return _r / 255.0f;
	}

	ColorByte Color::R32()
	{
		return _r;
	}
	void Color::SetR(const float& value)
	{
		_r = (unsigned char)(value * 255);
	}

	void Color::SetR32(const ColorByte& value)
	{
		_r = value;
	}

	float Color::G()
	{
		return _g / 255.0f;
	}

	ColorByte Color::G32()
	{
		return _g;
	}

	void Color::SetG(const float& value)
	{
		_g = (unsigned char)(value * 255);
	}

	void Color::SetG32(const ColorByte& value)
	{
		_g = value;
	}

	float Color::B()
	{
		return _b / 255.0f;
	}

	ColorByte Color::B32()
	{
		return _b;
	}

	void Color::SetB(const float& value)
	{
		_b = (unsigned char)(value * 255);
	}

	void Color::SetB32(const ColorByte& value)
	{
		_b = value;
	}

	float Color::A()
	{
		return _a / 255.0f;
	}

	ColorByte Color::A32()
	{
		return _a;
	}

	void Color::SetA(const float& value)
	{
		_a = (unsigned char)(value * 255);
	}

	void Color::SetA32(const ColorByte& value)
	{
		_a = value;
	}

	Float4 Color::ToFloat4()
	{
		Float4 f;
		f.x = R();
		f.y = G();
		f.z = B();
		f.w = A();
		return f;
	}

	Color& Color::operator=(const Float4& right)
	{
		_r = (unsigned char)(right.x * 255);
		_g = (unsigned char)(right.y * 255);
		_b = (unsigned char)(right.z * 255);
		_a = (unsigned char)(right.w * 255);
		return *this;
	}

	Color& Color::operator=(const Float3& right)
	{
		_r = (unsigned char)(right.x * 255);
		_g = (unsigned char)(right.y * 255);
		_b = (unsigned char)(right.z * 255);
		_a = 1;
		return *this;
	}

	Color& Color::operator=(const Color& right)
	{
		_r = right._r;
		_g = right._g;
		_b = right._b;
		_a = right._a;
		return *this;
	}

	bool Color::operator==(const Color& right)
	{
		bool result = _r == right._r && _g == right._g && _b == right._b && _a == right._a;
		return result;
	}
}