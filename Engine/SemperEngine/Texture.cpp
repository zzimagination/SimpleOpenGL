#include "Texture.h"
#include <fstream>
#include <iostream>
#include "GraphicCommandManager.h"

namespace SemperEngine {

	using namespace Core;

	Texture::Texture()
	{
		_package = TexturePackage(new TextureData());
		_package.Use(this);
		_package.GetResource()->Package(_package);
	}

	Texture::Texture(TexturePackage package)
	{
		_package = package;
		_package.Use(this);
	}

	Texture::~Texture()
	{
		_package.Dispose(this);
	}

	TexturePackage Texture::Package()
	{
		return _package;
	}
}