#include "Texture.h"
#include "ResourceObjectCenter.h"
#include "ResourceDataCenter.h"

namespace SemperEngine {

	using namespace std;
	using namespace Core;

	Texture::Texture()
	{
		object = TextureObject::Create();
		object->Use();
	}

	Texture::Texture(TextureObject* obj)
	{
		object = obj;
		object->Use();
	}

	Texture::~Texture()
	{
		object->Dispose();
	}

	Texture* Texture::Copy()
	{
		auto obj = object->Copy();
		auto texture = new Texture(obj);
		return texture;
	}

	void Texture::SetColors(ArrayList<ColorByte> data)
	{
		object->ColorBytes(data);
	}

	ArrayList<ColorByte> Texture::GetColors()
	{
		return object->ColorBytes();
	}
}