#include "Material.h"

namespace SemperEngine {

	using namespace std;

	Material::Material(string shader)
	{
		this->shader = shader;
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
		shaderProperty.Add(name, Float4(value.R(), value.G(), value.B(), value.A()));
	}

	void Material::AddProperty(int id, std::shared_ptr<Texture> value)
	{
		shaderProperty.Add(id, value);
	}
}