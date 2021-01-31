#include "Material.h"

namespace SemperEngine {

	using namespace std;

	Material::Material(string shader)
	{
		shaderProperty.name = shader;
	}

	Material::Material() :Material("Unlit")
	{
		AddProperty("_color", Float4(1, 1, 1, 1));
	}

	void Material::AddProperty(std::string name, float value)
	{
		shaderProperty.Add(name, value);
	}

	void Material::AddProperty(std::string name, Float2 value)
	{
		shaderProperty.Add(name, value);
	}

	void Material::AddProperty(std::string name, Float3 value)
	{
		shaderProperty.Add(name, value);
	}

	void Material::AddProperty(std::string name, Float4 value)
	{
		shaderProperty.Add(name, value);
	}

	void Material::AddProperty(std::string name, Matrix4x4 value)
	{
		shaderProperty.Add(name, value);
	}
	
	void Material::AddProperty(std::string name, Color value)
	{
		auto f = Float4(value.R(), value.G(), value.B(), value.A());
		shaderProperty.Add(name, f);
	}

	void Material::AddProperty(int id, std::shared_ptr<Texture> value)
	{
		MaterialTexture tex(id, value);
		for (int i = 0; i < textures.size(); i++)
		{
			if (textures[i].index == tex.index)
			{
				textures[i] = tex;
				return;
			}
		}
		textures.push_back(tex);
	}
}