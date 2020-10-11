#include "Material.h"

namespace SemperEngine {

	using namespace std;

	Material::Material(string shader)
	{
		this->shader = shader;
	}

	Material::Material() :Material("Unlit")
	{
		AddShaderProperty("_color", Vector4(1, 1, 1, 1));
	}

	void Material::AddShaderProperty(std::string name, float value)
	{
		shaderProperty.Add(name, value);
	}

	void Material::AddShaderProperty(std::string name, Vector2 value)
	{
		shaderProperty.Add(name, value);
	}

	void Material::AddShaderProperty(std::string name, Vector3 value)
	{
		shaderProperty.Add(name, value);
	}

	void Material::AddShaderProperty(std::string name, Vector4 value)
	{
		shaderProperty.Add(name, value);
	}

	void Material::AddShaderProperty(std::string name, Matrix4x4 value)
	{
		shaderProperty.Add(name, value);
	}
	void Material::AddShaderProperty(std::string name, Color value)
	{
		shaderProperty.Add(name, Vector4(value.R(), value.G(), value.B(), value.A()));
	}
}