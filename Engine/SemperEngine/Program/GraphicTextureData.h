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

			unsigned int glID = -1;

			GraphicTextureResource source;

		public:

			GraphicTextureData();

			virtual ~GraphicTextureData() override;

			void SetGLTexture(unsigned int glId);

		};
	}
}
#endif // !__GRAPHICTEXTUREDATA__
