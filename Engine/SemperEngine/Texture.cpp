#include "Texture.h"
#include "ResourceObjectCenter.h"


namespace SemperEngine {

	using namespace std;
	using namespace Core;

	Texture::Texture()
	{
		object = ResourceObjectCenter::CreateTexture();
	}

	Texture::~Texture()
	{
		ResourceObjectCenter::DeleteTexture(object);
	}
	Texture* Texture::Copy()
	{
		auto obj = ResourceObjectCenter::CopyTexture(object);
		auto texture = new Texture();
		ResourceObjectCenter::DeleteTexture(texture->object);
		texture->object = obj;
		return texture;
	}
	void Texture::ColorBuffer(std::shared_ptr<unsigned char> buffer)
	{

	}
	std::shared_ptr<unsigned char> Texture::ColorBuffer()
	{
		return std::shared_ptr<unsigned char>();
	}
}