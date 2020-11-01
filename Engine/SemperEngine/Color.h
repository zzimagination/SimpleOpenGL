#pragma once
#ifndef __COLOR_VARIABLE__
#define __COLOR_VARIABLE__

#include "Float3.h"
#include "Float4.h"

namespace SemperEngine
{
	class Color
	{
	public:

		static Color FromHEX32(const long& hex);
		static Color FromHEX24(const long& hex);

	private:

		Float4 _data;

	public:

		Color();

		Color(Float4 value);

		Color(Float3 value);

		Color(const float& r, const float& g, const float& b, const float& a = 1);

		float R();

		float G();

		float B();

		float A();

		Color& operator=(const Float4& right);

		Color& operator=(const Float3& right);

		Color& operator=(const Color& right);
	};
}

#endif // !COLOR_VARIABLE
