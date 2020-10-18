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

		Core::ShaderProperty shaderProperty;

	public:

		Material();

		Material(std::string shader);

		void AddProperty(std::string name, float value);

		void AddProperty(std::string name, Vector2 value);

		void AddProperty(std::string name, Vector3 value);

		void AddProperty(std::string name, Vector4 value);

		void AddProperty(std::string name, Matrix4x4 value);

		void AddProperty(std::string name, Color value);

		void AddProperty(int id, Core::RsTextureRef value);
	};
}
#endif // !MATERIAL
