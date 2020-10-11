#ifndef __SHADER_PROPERTY__
#define __SHADER_PROPERTY__

#include <map>
#include <vector>
#include <string>
#include "Mathz.h"

namespace SemperEngine {

	constexpr const char* MODEL_MATRIX = "_model";
	constexpr const char* VIEW_MATRIX = "_view";
	constexpr const char* PROJECTION_MARIX = "_projection";
	constexpr const char* MAINCOLOR = "_color";

	typedef std::map<std::string, float> FProperty;
	typedef std::map<std::string, Vector2> Vec2Property;
	typedef std::map<std::string, Vector3> Vec3Property;
	typedef std::map<std::string, Vector4> Vec4Property;
	typedef std::map<std::string, Matrix4x4> Mat4Property;

	class ShaderProperty
	{
	public:

		static int i;

	public:

		FProperty floatProperty;

		Vec2Property vector2Property;

		Vec3Property vector3Property;

		Vec4Property vector4Property;

		Mat4Property matrix4x4Property;

	public:

		ShaderProperty() { 
		};

		~ShaderProperty() {
		};

		void Add(std::string name, float value)
		{
			floatProperty[name] = value;
		}

		void Add(std::string name, Vector2 value)
		{
			vector2Property[name] = value;
		}

		void Add(std::string name, Vector3 value)
		{
			vector3Property[name] = value;
		}

		void Add(std::string name, Vector4 value)
		{
			vector4Property[name] = value;
		}

		void Add(std::string name, Matrix4x4 value)
		{
			matrix4x4Property[name] = value;
		}

	};
}
#endif // !SHADER_PROPERTY

