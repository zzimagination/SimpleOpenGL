#include "GraphicTextureData.h"

namespace SemperEngine {

	namespace Core
	{
		GraphicTextureData::GraphicTextureData()
		{
		}

		GraphicTextureData::~GraphicTextureData()
		{
		}
		void GraphicTextureData::SetGLTexture(unsigned int glID)
		{
			this->glID = glID;
			Complete();
		}
	}
}