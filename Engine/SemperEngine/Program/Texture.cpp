#include "Texture.h"
#include "ResourceObjectCenter.h"

namespace SemperEngine {

	using namespace std;
	using namespace Core;

	Texture::Texture(int width, int height)
	{
		_object = TextureObject::Create(width, height);
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
		_object->pixels = data;
		_object->Modify();
	}

	ArrayList<ColorByte> Texture::GetColors()
	{
		return _object->pixels;
	}
	void Texture::SetFilter(ResourceConfig::TextureFilter filter)
	{
		_object->filter = filter;
		_object->Modify();
	}
	ResourceConfig::TextureFilter Texture::GetFilter()
	{
		return _object->filter;
	}
}