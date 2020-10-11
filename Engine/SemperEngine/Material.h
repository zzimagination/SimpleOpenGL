#ifndef __MATERIAL__
#define __MATERIAL__

#include <vector>
#include <map>
#include <string>
#include "Mathz.h"
#include "ShaderProperty.h"

namespace SemperEngine
{
	class Material
	{
	public:

		std::string shader;

		ShaderProperty shaderProperty;

	public:

		Material();

		Material(std::string shader);

		void AddShaderProperty(std::string name, float value);

		void AddShaderProperty(std::string name, Vector2 value);

		void AddShaderProperty(std::string name, Vector3 value);

		void AddShaderProperty(std::string name, Vector4 value);

		void AddShaderProperty(std::string name, Matrix4x4 value);

		void AddShaderProperty(std::string name, Color value);

	};
}
#endif // !MATERIAL
