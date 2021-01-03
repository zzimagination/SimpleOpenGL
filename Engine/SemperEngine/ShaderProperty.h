#ifndef __SHADER_PROPERTY__
#define __SHADER_PROPERTY__

#include <map>
#include <vector>
#include <string>
#include "Mathz.h"

namespace SemperEngine
{
	namespace Core
	{
		constexpr const char* MODEL_MATRIX = "_model";
		constexpr const char* VIEW_MATRIX = "_view";
		constexpr const char* PROJECTION_MARIX = "_projection";
		constexpr const char* MAINCOLOR = "_color";

		class ShaderProperty
		{
		public:

			std::string name = "Unlit";

			std::map<std::string, float> floatProperty;

			std::map<std::string, Float2> vector2Property;

			std::map<std::string, Float3> vector3Property;

			std::map<std::string, Float4> vector4Property;

			std::map<std::string, Matrix4x4> matrix4x4Property;

		public:

			ShaderProperty() {
			};

			~ShaderProperty() {
			};

			void Add(std::string name, float value)
			{
				floatProperty[name] = value;
			}

			void Add(std::string name, Float2 value)
			{
				vector2Property[name] = value;
			}

			void Add(std::string name, Float3 value)
			{
				vector3Property[name] = value;
			}

			void Add(std::string name, Float4 value)
			{
				vector4Property[name] = value;
			}

			void Add(std::string name, Matrix4x4 value)
			{
				matrix4x4Property[name] = value;
			}

			void Clear()
			{
				floatProperty.clear();
				vector2Property.clear();
				vector3Property.clear();
				vector4Property.clear();
				matrix4x4Property.clear();
				name = "Unlit";
			}
		};
	}
}
#endif // !SHADER_PROPERTY

