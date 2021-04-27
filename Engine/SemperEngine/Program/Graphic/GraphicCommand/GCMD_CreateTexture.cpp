#include "GCMD_CreateTexture.h"

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

		void GCMD_CreateTexture::Execute()
		{
			auto tmp = GraphicResouceAPI::AddTextureData(textureData);
			textureData->SetGLTexture(tmp.glID);
		}
	}
}