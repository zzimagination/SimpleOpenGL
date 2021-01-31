#ifndef __MATERIAL__
#define __MATERIAL__

#include <vector>
#include <map>
#include <string>
#include "Common.h"
#include "Graphic.h"
#include "Texture.h"

namespace SemperEngine
{
	class Material
	{
	public:

		class MaterialTexture
		{
		public:

			int index;

			std::shared_ptr<Texture> texture;

		public:

			MaterialTexture(int i, std::shared_ptr<Texture> tex)
			{
				this->index = i;
				this->texture = tex;
			}
			~MaterialTexture()
			{}
		};

	public:

		Core::RenderOperation renderOperation;

		Core::ShaderProperty shaderProperty;

		std::vector<MaterialTexture> textures;

	public:

		Material();

		Material(std::string shader);

		void AddProperty(std::string name, float value);

		void AddProperty(std::string name, Float2 value);

		void AddProperty(std::string name, Float3 value);

		void AddProperty(std::string name, Float4 value);

		void AddProperty(std::string name, Matrix4x4 value);

		void AddProperty(std::string name, Color value);

		void AddProperty(int id, std::shared_ptr<Texture> value);
	};
}
#endif // !MATERIAL