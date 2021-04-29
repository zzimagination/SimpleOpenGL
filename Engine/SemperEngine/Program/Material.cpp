#include "Material.h"

namespace Semper {

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

	void Material::SetDepth(Depth mode)
	{
		_object->depth = (int)mode;
	}

	void Material::SetBlend(bool enable, Source source, Destination destination)
	{
		_object->blend = enable;
		_object->source = (int)source;
		_object->destination = (int)destination;
	}

	void Material::SetCull(Cull mode)
	{
		_object->cull = (int)mode;
	}

	void Material::AddProperty(std::string name, float value)
	{
		_object->floatProperties[name] = value;
	}

	void Material::AddProperty(std::string name, Float2 value)
	{
		_object->float2Properties[name] = value;
	}

	void Material::AddProperty(std::string name, Float3 value)
	{
		_object->float3Properties[name] = value;
	}

	void Material::AddProperty(std::string name, Float4 value)
	{
		_object->float4Properties[name] = value;
	}

	void Material::AddProperty(std::string name, Matrix4x4 value)
	{
		_object->matrix4x4Properties[name] = value;
	}

	void Material::AddProperty(std::string name, Color value)
	{
		AddProperty(name, value.ToFloat4());
	}

	void Material::AddProperty(std::string name, std::shared_ptr<Texture> value)
	{
		auto i = _object->textureProperties.find(name);
		if (i == _object->textureProperties.end())
		{
			_object->textureProperties.insert(std::pair<std::string, std::shared_ptr<Texture>>(name, value));
			_object->textureList.Add(name);
			return;
		}
		i->second = value;
		_object->textureList.Remove(name);
		_object->textureList.Add(name);
	}

	void Material::AddProperty(std::string name, std::shared_ptr<Texture> value, int order)
	{
		auto i = _object->textureProperties.find(name);
		if (i == _object->textureProperties.end())
		{
			_object->textureProperties.insert(std::pair<std::string, std::shared_ptr<Texture>>(name, value));
			_object->textureList.Add(name, order);
			return;
		}
		i->second = value;
		_object->textureList.Remove(name);
		_object->textureList.Add(name, order);
	}

	ResourceObject* Material::GetObject()
	{
		return _object;
	}
}