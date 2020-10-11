#pragma once
#ifndef __COLOR_VARIABLE__
#define __COLOR_VARIABLE__

#include "Vector3.h"
#include "Vector4.h"

namespace SemperEngine
{
	class Color
	{
	public:

		static Color FromHEX32(long hex);
		static Color FromHEX24(long hex);

	private:

		Vector4 _data;

	public:

		Color();

		Color(Vector4 value);

		Color(Vector3 value);

		Color(float r, float g, float b, float a = 1);

		float R();

		float G();

		float B();

		float A();

		Color& operator=(const Vector4& right);

		Color& operator=(const Vector3& right);

		Color& operator=(const Color& right);
	};
}

#endif // !COLOR_VARIABLE
