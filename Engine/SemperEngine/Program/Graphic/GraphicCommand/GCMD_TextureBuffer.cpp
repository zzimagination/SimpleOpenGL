#include "GCMD_TextureBuffer.h"
#include "../GraphicResource.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;

		GCMD_CreateTexture::GCMD_CreateTexture(GraphicTextureData* data)
		{
			this->textureData = data;
		}

		GCMD_CreateTexture::~GCMD_CreateTexture()
		{
		}

		void GCMD_CreateTexture::Excute()
		{
			auto tmp = GraphicResouceAPI::AddTextureData(textureData);
			textureData->SetGLTexture(tmp.glID);
		}
	}
}