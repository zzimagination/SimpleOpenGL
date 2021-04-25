#include "GraphicTextureData.h"

namespace Semper {

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