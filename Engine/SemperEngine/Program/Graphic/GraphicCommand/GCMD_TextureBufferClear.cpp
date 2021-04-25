#include "GCMD_TextureBufferClear.h"
#include "../GraphicResource.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;

		GCMD_DeleteTexture::GCMD_DeleteTexture(GraphicTextureData* data, DeleteFunc func)
		{
			this->textureData = data;
			this->deleteFunc = func;
		}

		GCMD_DeleteTexture::~GCMD_DeleteTexture()
		{
		}

		void GCMD_DeleteTexture::Excute()
		{
			GraphicResouceAPI::ClearTextureData(textureData);
			if (deleteFunc == nullptr)
			{
				delete textureData;
			}
			else
			{
				deleteFunc(textureData);
			}
		}
	}
}