#include "Material.h"

namespace SemperEngine {

	using namespace std;
	using namespace Core;

	Material::Material(string shader)
	{
		_object = MaterialObject::Create(shader);
		_object->Use();
	}

	Material::~Material()
	{
		_object->Dispose();
	}

	void Material::Blend(bool enable, Graphic::BlendFunc src, Graphic::BlendFunc dest)
	{
		_object->renderOperation.blend = enable;
		_object->renderOperation.source = src;
		_object->renderOperation.destination = dest;
	}

	void Material::CullFace(bool enable, Graphic::CullFace face)
	{
		_object->renderOperation.cull = enable;
		_object->renderOperation.cullFace = face;
	}

	void Material::Depth(bool enable, Graphic::DepthFunc func)
	{
		_object->renderOperation.depth = enable;
		_object->renderOperation.depthFunc = func;
	}

	vector<shared_ptr<Texture>> Material::GetTextures()
	{
		return _object->textures;
	}

	Material::Material() :Material("Color")
	{
		AddProperty("_color", Float4(1, 1, 1, 1));
	}

	void Material::AddProperty(std::string name, float value)
	{
		_object->shaderProperty.Add(name, value);
	}

	void Material::AddProperty(std::string name, Float2 value)
	{
		_object->shaderProperty.Add(name, value);
	}

	void Material::AddProperty(std::string name, Float3 value)
	{
		_object->shaderProperty.Add(name, value);
	}

	void Material::AddProperty(std::string name, Float4 value)
	{
		_object->shaderProperty.Add(name, value);
	}

	void Material::AddProperty(std::string name, Matrix4x4 value)
	{
		_object->shaderProperty.Add(name, value);
	}

	void Material::AddProperty(std::string name, Color value)
	{
		_object->shaderProperty.Add(name, value);
	}

	void Material::AddProperty(int id, std::shared_ptr<Texture> value)
	{
		if (_object->textures.size() > id)
		{
			_object->textures[id] = value;
		}
		else
		{
			_object->textures.push_back(value);
		}
	}
	ResourceObject* Material::GetObject()
	{
		return _object;
	}
}