#ifndef __GRAPHIC_RECORD__
#define __GRAPHIC_RECORD__

#include <vector>
#include "GraphicData.h"

namespace SemperEngine
{
	namespace Core
	{
		class GraphicRecord
		{
		public:

			enum class Attach
			{
				None,

				Depth,

				Stencil,

				DepthStencil
			};

		public:

			int width = 0;

			int height = 0;

			Attach attach = Attach::None;

			int msaa = 0;

		public:

			unsigned int glFrameBuffer = -1;

			unsigned int glRenderBuffer = -1;

			std::vector<GraphicTextureData> textures;

		public:

			bool MSAAEnable();

		};
	}
}
#endif // !__GRAPHIC_RECORD__
