#pragma once
#ifndef __COLOR_VARIABLE__
#define __COLOR_VARIABLE__

#include "Float3.h"
#include "Float4.h"

namespace Semper
{
	typedef unsigned char ColorByte;

	class Color
	{
	public:

		static Color FromHEX32(const long& hex);

		static Color FromHEX24(const long& hex);

		static Color ColorFloat(const float& r = 1, const float& g = 1, const float& b = 1, const float& a = 1);

		static Color Color32(const ColorByte& r = 255, const ColorByte& g = 255, const ColorByte& b = 255, const ColorByte& a = 255);

		static Color Black();

		static Color White();

	private:

		ColorByte _r;

		ColorByte _g;

		ColorByte _b;

		ColorByte _a;

	public:

		Color();

		Color(const Float4& value);

		Color(const Float3& value);

		float R();

		ColorByte R32();

		void SetR(const float& value);

		void SetR32(const ColorByte& value);

		float G();

		ColorByte G32();

		void SetG(const float& value);

		void SetG32(const ColorByte& value);

		float B();

		ColorByte B32();

		void SetB(const float& value);

		void SetB32(const ColorByte& value);

		float A();

		ColorByte A32();

		void SetA(const float& value);

		void SetA32(const ColorByte& value);

		Float4 ToFloat4();

		Color& operator=(const Float4& right);

		Color& operator=(const Float3& right);

		Color& operator=(const Color& right);

		bool operator == (const Color& right);
	};
}

#endif // !COLOR_VARIABLE
