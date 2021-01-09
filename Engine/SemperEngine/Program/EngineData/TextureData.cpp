#include "TextureData.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		TextureData::TextureData()
		{
		}

		TextureData::~TextureData()
		{
		}

		TextureData* TextureData::Copy()
		{
			auto copy = new TextureData();
			copy->width = this->width;
			copy->height = this->height;
			copy->pixels.Resize(pixels.Size());
			copy->pixels.Copy(pixels.DataPtr());
			return copy;
		}
	}
}