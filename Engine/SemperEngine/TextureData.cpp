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
			auto buffer = new vector<unsigned char>(*(this->data.get()));
			auto copyData = shared_ptr<vector<unsigned char>>(buffer);
			copy->data = copyData;
			copy->width = this->width;
			copy->height = this->height;
			return copy;
		}
		unsigned char* TextureData::SourceData()
		{
			if (data.get() != nullptr)
			{
				return data->data();
			}
			return nullptr;
		}
	}
}