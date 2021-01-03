#include "GraphicTextureData.h"

namespace SemperEngine {

	namespace Core
	{
		GraphicTextureData::GraphicTextureData()
		{
			glid = 0;
			_source = nullptr;
		}

		GraphicTextureData::GraphicTextureData(int id)
		{
			glid = id;
			_source = nullptr;
		}

		GraphicTextureData::~GraphicTextureData()
		{
		}
		void GraphicTextureData::SetSource(TextureData* source)
		{
			this->_source = source;
			isPrimitived = true;
		}
		TextureData* GraphicTextureData::GetSource()
		{
			return _source;
		}
		void GraphicTextureData::Complete()
		{
			this->_source = nullptr;
			isPrimitived = false;
		}
	}
}