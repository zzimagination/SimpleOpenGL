#include "Texture.h"
#include "ResourceObjectCenter.h"
#include "ResourceDataCenter.h"

namespace SemperEngine {

	using namespace std;
	using namespace Core;

	Texture::Texture()
	{
		_object = TextureObject::Create();
		_object->Use();
	}

	Texture::Texture(TextureObject* obj)
	{
		_object = obj;
		_object->Use();
	}

	Texture::~Texture()
	{
		_object->Dispose();
	}

	Core::TextureObject* Texture::GetObject()
	{
		return _object;
	}

	Texture* Texture::Copy()
	{
		auto obj = _object->Copy();
		auto texture = new Texture(obj);
		return texture;
	}

	void Texture::SetColors(ArrayList<ColorByte> data)
	{
		_object->ColorBytes(data);
	}

	ArrayList<ColorByte> Texture::GetColors()
	{
		return _object->ColorBytes();
	}
}