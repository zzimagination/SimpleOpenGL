#include "GraphicResource.h"


namespace SemperEngine {

	namespace Core
	{
		GraphicTextureData::GraphicTextureData()
		{
			glid = 0;
		}

		GraphicTextureData::GraphicTextureData(int id)
		{
			glid = id;
		}

		GraphicTextureData::~GraphicTextureData()
		{
		}
	}
}