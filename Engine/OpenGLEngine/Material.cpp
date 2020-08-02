#include "Material.h"
#include "ShaderManager.h"
#include "ShaderProperty.h"
#include "Texture.h"

Material::Material(string shader)
{
	this->shader = ShaderManager::GetShader(shader);
	this->name = shader;
}

Material::Material(ShaderProgram * shader) :shader(shader)
{
	this->name = shader->name;
}

void Material::SetFloat(float value, string name)
{
	floatProperty.Add(name, value);
}

void Material::SetVector2(Vector2 value, string name)
{
	vector2Property.Add(name, value);
}

void Material::SetVector3(Vector3 value, string name)
{
	vector3Property.Add(name, value);
}

void Material::SetVector4(Vector4 value, string name)
{
	vector4Property.Add(name, value);
}

void Material::SetMatrix(Matrix4x4 value, string name)
{
	matrixProperty.Add(name, value);
}

void Material::SetTexture(Texture* tex)
{
	for (int i = 0; i < textures.size(); i++)
	{
		if (textures[i] == tex)
		{
			return;
		}
	}
	textures.push_back(tex);
}

void Material::RemoveTexture(Texture *tex)
{
	for (int i = 0; i < textures.size(); i++)
	{
		if (textures[i] == tex)
		{
			textures.erase(textures.begin() + i);
			return;
		}
	}
	throw "don't have the texture";
}
