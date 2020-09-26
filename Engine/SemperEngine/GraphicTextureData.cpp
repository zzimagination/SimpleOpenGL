#include "GraphicTextureData.h"
#include "RenderObject.h"
#include<glad/glad.h>


namespace SemperEngine {

	GraphicTextureData::GraphicTextureData(Texture * gameData, unsigned int id)
	{
		this->gameData = gameData;
		this->textureId = id;
	}

	GraphicTextureData::~GraphicTextureData()
	{
	}

}