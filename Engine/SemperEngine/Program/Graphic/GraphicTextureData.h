#ifndef __GRAPHICTEXTUREDATA__
#define __GRAPHICTEXTUREDATA__

#include <map>
#include <memory>
#include "GraphicData.h"

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

			void SetGLTexture(unsigned int glID);

		};
	}
}
#endif // !__GRAPHICTEXTUREDATA__
