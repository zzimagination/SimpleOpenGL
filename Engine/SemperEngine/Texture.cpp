#include "Texture.h"
#include <fstream>
#include <iostream>
#include "TextureDataCenter.h"

namespace SemperEngine {

	using namespace Core;

	Texture::Texture()
	{
		auto data = new TextureData();
		_package = TextureDataCenter::InputData(data);
		_package.Use();
	}

	Texture::Texture(TexturePackage package)
	{
		_package = package;
		_package.Use();
	}

	Texture::~Texture()
	{
		_package.Dispose();
	}

	TexturePackage Texture::Package()
	{
		return _package;
	}
}