#pragma once
#ifndef __GRAPHICTEXTUREDATA__
#define __GRAPHICTEXTUREDATA__

#include <map>
#include <memory>
#include "GraphicData.h"
#include "Graphic.h"

namespace SemperEngine
{
	namespace Core
	{
		class GraphicTextureData : public GraphicData
		{
		public:

			unsigned int glid = 0;

			GraphicTextureResource source;

		public:

			GraphicTextureData();

			GraphicTextureData(int id);

			virtual ~GraphicTextureData() override;

		};
	}
}
#endif // !__GRAPHICTEXTUREDATA__
