#include "Texture.h"
#include <fstream>
#include <iostream>
#include "GraphicCommandManager.h"

namespace SemperEngine {

	Texture::Texture()
	{
		width = 0;

		height = 0;

		data = nullptr;
	}

	Texture::~Texture()
	{
	}
}