#ifndef __SHADER_PROPERTY__
#define __SHADER_PROPERTY__

#include <map>
#include <vector>
#include <string>
#include "Mathz.h"
#include "Texture.h"

namespace SemperEngine
{
	namespace Core
	{
		class ShaderProperty
		{
		public:

			std::map<std::string, float> floatProperty;

			std::map<std::string, Float2> vector2Property;

			std::map<std::string, Float3> vector3Property;

			std::map<std::string, Float4> vector4Property;

			std::map<std::string, Matrix4x4> matrix4x4Property;

			std::map<int, std::shared_ptr<Texture>> textureProperty;

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

			void Add(int id, std::shared_ptr<Texture> value)
			{
				textureProperty[id] = value;
			}
		};
	}
}
#endif // !SHADER_PROPERTY

