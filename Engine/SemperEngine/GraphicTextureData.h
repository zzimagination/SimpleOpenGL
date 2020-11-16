#pragma once
#ifndef __GRAPHICTEXTUREDATA__
#define __GRAPHICTEXTUREDATA__

#include <map>
#include <memory>
#include "GraphicData.h"
#include "TextureData.h"

namespace SemperEngine
{
	namespace Core
	{
		class GraphicTextureData : public GraphicData
		{
		public:

			unsigned int glid;

		private:

			TextureData* _source = nullptr;

		public:

			GraphicTextureData();

			GraphicTextureData(int id);

			virtual ~GraphicTextureData() override;

			void SetSource(TextureData* source);

			TextureData* GetSource();

			virtual void Complete() override;

		};
	}
}
#endif // !__GRAPHICTEXTUREDATA__
