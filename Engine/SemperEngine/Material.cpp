#include "Material.h"
#include "GraphicShaderManager.h"
#include "Texture.h"

namespace SemperEngine {

	using namespace std;

	Material::Material(string shader)
	{
		this->shader = ShaderManager::GetShader(shader);
		this->name = shader;
		SetVector4(Vector4(1, 1, 1, 1), "_color");
	}

	void Material::SetMainColor(Vector4 color)
	{
		
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
		matrix4x4Property.Add(name, value);
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
}